#ifndef DYNAMICLIBRARY_H
#define DYNAMICLIBRARY_H

#include <stdexcept>
#include <string>

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__APPLE__)
#include <dlfcn.h>
#else
#include <Windows.h>
#endif

namespace Euresys {
namespace EGrabberRecorder {
namespace Internal {

class dynlib_loading_error: public std::runtime_error {
public:
    explicit dynlib_loading_error(const std::string &path)
        : std::runtime_error(std::string("Cannot load ") + path)
    {}
};

class missing_dynlib_symbol: public std::runtime_error {
public:
    explicit missing_dynlib_symbol(const std::string &path, const std::string &symbol)
        : std::runtime_error(std::string("Missing symbol ") + symbol + " in " + path)
    {}
};

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__APPLE__)
namespace {
typedef void *DYNLIB_HANDLE;
DYNLIB_HANDLE loadDynLib(const std::string &path) {
    void *h = dlopen(path.c_str(), RTLD_NOW);
    if (!h) {
        char *err = dlerror();
        if (!err) {
            throw dynlib_loading_error(path);
        } else {
            throw dynlib_loading_error(path + ", " + err);
        }
    }
    return h;
}
void unloadDynLib(DYNLIB_HANDLE h) {
    dlclose(h);
}
void *getDynLibSymbol(DYNLIB_HANDLE h, const std::string &symbol) {
    return dlsym(h, symbol.c_str());
}
}
#else
namespace {
typedef HMODULE DYNLIB_HANDLE;
DYNLIB_HANDLE loadDynLib(const std::string &path) {
    HMODULE h = LoadLibraryA(path.c_str());
    if (!h) {
        throw dynlib_loading_error(path);
    }
    return h;
}
void unloadDynLib(DYNLIB_HANDLE h) {
    FreeLibrary(h);
}
void *getDynLibSymbol(DYNLIB_HANDLE h, const std::string &symbol) {
    return reinterpret_cast<void *>(GetProcAddress(h, symbol.c_str()));
}
}
#endif

class DynamicLibrary {
public:
    DynamicLibrary(const std::string &path)
        : path(path)
        , dynlib(loadDynLib(path))
    {}
    ~DynamicLibrary() {
        try {
            unloadDynLib(dynlib);
        } catch (...) {
        }
    }
    void *getSymbol(const std::string &symbol) {
        void *s = getDynLibSymbol(dynlib, symbol);
        if (!s) {
            throw missing_dynlib_symbol(path, symbol);
        }
        return s;
    }
    const std::string &getPath() const {
        return path;
    }
private:
    std::string path;
    DYNLIB_HANDLE dynlib;
};

} // namespace Internal
} // namespace EGrabberRecorder
} // namespace Euresys

#endif
