/* Copyright Euresys 2020 */

#ifndef ERECORDERLIBRARY_H
#define ERECORDERLIBRARY_H

#include "ERecorder.h"
#include "internal/dynamicLibrary.h"
#include "internal/defaultPath.h"

#include <string>
#include <vector>
#include <sstream>

#ifndef ERECORDERLIBRARY_WITH_PROGRESS_REPORT
#if __cplusplus >= 201103L
#define ERECORDERLIBRARY_WITH_PROGRESS_REPORT 1
#else
#define ERECORDERLIBRARY_WITH_PROGRESS_REPORT 0
#endif
#endif

#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
#include <atomic>
#endif

/** @file
    Main EGrabber Recorder header file for the Recorder Library
 **/

namespace Euresys {
namespace EGrabberRecorder {

/** @defgroup EGrabberRecorder (C++ API)
    Euresys EGrabber Recorder C++ classes that load the library and
    expose a higher level API
    @{
 **/

/// A Recorder error (@ref RECORDER_STATUS)
class RecorderError: public std::runtime_error {
public:
    RECORDER_STATUS status;
    explicit RecorderError(RECORDER_STATUS status, const std::string &description);
    static void check(RECORDER_STATUS status);
};

/// Unknown error (@ref RECORDER_STATUS_UNKNOWN_ERROR)
class UnknownError: public RecorderError {
public:
    UnknownError();
};

/// Unknown parameter error (@ref RECORDER_STATUS_UNKNOWN_PARAMETER)
class UnknownParameter: public RecorderError {
public:
    UnknownParameter();
};

/// Invalid parameter type error (@ref RECORDER_STATUS_INVALID_PARAMETER_TYPE)
class InvalidParameterType: public RecorderError {
public:
    InvalidParameterType();
};

/// Invalid parameter value error (@ref RECORDER_STATUS_INVALID_PARAMETER_VALUE)
class InvalidParameterValue: public RecorderError {
public:
    InvalidParameterValue();
};

/// Buffer too small error (@ref RECORDER_STATUS_BUFFER_TOO_SMALL)
class BufferTooSmall: public RecorderError {
public:
    BufferTooSmall();
};

/// Parameter read-only error (@ref RECORDER_STATUS_PARAMETER_IS_READ_ONLY)
class ParameterIsReadOnly: public RecorderError {
public:
    ParameterIsReadOnly();
};

/// System error @ref RECORDER_STATUS_SYSTEM_ERROR
class SystemError: public RecorderError {
public:
    SystemError();
};

/// Invalid storage path error (@ref RECORDER_STATUS_INVALID_CONTAINER_PATH)
class InvalidContainerPath: public RecorderError {
public:
    InvalidContainerPath();
};

/// Data file full error (@ref RECORDER_STATUS_DATA_FILE_FULL)
class DataFileFull: public RecorderError {
public:
    DataFileFull();
};

/// Operation not allowed error (@ref RECORDER_STATUS_OPERATION_NOT_ALLOWED)
class OperationNotAllowed: public RecorderError {
public:
    OperationNotAllowed();
};

/// Index out of range error (@ref RECORDER_STATUS_INDEX_OUT_OF_RANGE)
class IndexOutOfRange: public RecorderError {
public:
    IndexOutOfRange();
};

/// Invalid index data error (@ref RECORDER_STATUS_INVALID_INDEX_DATA)
class InvalidIndexData: public RecorderError {
public:
    InvalidIndexData();
};

/// Invalid index size error (@ref RECORDER_STATUS_INVALID_INDEX_SIZE)
class InvalidIndexSize: public RecorderError {
public:
    InvalidIndexSize();
};

/// Unsupported database version error (@ref RECORDER_STATUS_UNSUPPORTED_DATABASE_VERSION)
class UnsupportedDatabaseVersion: public RecorderError {
public:
    UnsupportedDatabaseVersion();
};

/// Invalid index header error (@ref RECORDER_STATUS_INVALID_INDEX_HEADER)
class InvalidIndexHeader: public RecorderError {
public:
    InvalidIndexHeader();
};

/// Invalid length written error (@ref RECORDER_STATUS_INVALID_LENGTH_WRITTEN)
class InvalidLengthWritten: public RecorderError {
public:
    InvalidLengthWritten();
};

/// Not initialized error (@ref RECORDER_STATUS_NOT_INITIALIZED)
class NotInitialized: public RecorderError {
public:
    NotInitialized();
};

/// Invalid handle error (@ref RECORDER_STATUS_INVALID_HANDLE)
class InvalidHandle: public RecorderError {
public:
    InvalidHandle();
};

/// Resource in use error (@ref RECORDER_STATUS_RESOURCE_IN_USE)
class ResourceInUse: public RecorderError {
public:
    ResourceInUse();
};

/// End of data error (@ref RECORDER_STATUS_END_OF_DATA)
class EndOfData: public RecorderError {
public:
    EndOfData();
};

/// Invalid argument error (@ref RECORDER_STATUS_INVALID_ARGUMENT)
class InvalidArgument: public RecorderError {
public:
    InvalidArgument();
};

/// No container in path (@ref RECORDER_STATUS_NO_CONTAINER)
class NoContainer: public RecorderError {
public:
    NoContainer();
};

/// License Manager error (@ref RECORDER_STATUS_LICENSE_MANAGER_ERROR)
class LicenseManagerError: public RecorderError {
public:
    LicenseManagerError();
};

/// No license (@ref RECORDER_STATUS_NO_LICENSE)
class NoLicense: public RecorderError {
public:
    NoLicense();
};

/// Image conversion error (@ref RECORDER_STATUS_IMAGE_CONVERSION_ERROR)
class ImageConversionError: public RecorderError {
public:
    ImageConversionError();
};

/// Unsupported image format error (thrown by @ref Recorder::exportImages)
class UnsupportedImageFormatError : public RecorderError {
public:
    UnsupportedImageFormatError();
};

/// Operation aborted by the user (thrown by @ref Recorder::exportImages)
class Aborted : public RecorderError {
public:
    Aborted();
};

/// Invalid data size on reading
class InvalidDataSize : public RecorderError {
public:
    InvalidDataSize();
};

/// An invalid character was used in the chapter name
class InvalidChapterCharacter : public RecorderError {
public:
    InvalidChapterCharacter();
};

/// The chapter name conflicts with a reserved name
class ReservedChapterName : public RecorderError {
public:
    ReservedChapterName();
};

/// The chapter name is already used
class ChapterNameAlreadyUsed : public RecorderError {
public:
    ChapterNameAlreadyUsed();
};

/// The chapter name is too long
class ChapterNameTooLong : public RecorderError {
public:
    ChapterNameTooLong();
};

class RecorderLibrary;

/** A Recorder object that encapsulates a recorder handle (@ref RECORDER_HANDLE)
    and exposes higher level recorder functions; the destructor takes care of
    closing the recorder when the object goes out of scope
    @note the recorder is automatically created by RecorderLibrary::openRecorder
 **/
class Recorder {
public:
#if __cplusplus >= 201103L
    Recorder(const Recorder &) = delete;
    Recorder(Recorder &&);
    Recorder &operator=(const Recorder &) = delete;
    Recorder &operator=(Recorder &&);
#else
    Recorder(const Recorder &);
    Recorder &operator=(const Recorder &);
#endif
    /// create a Recorder object from a recorder handle (@ref RecorderLibrary::openRecorder)
    explicit Recorder(RecorderLibrary &recorderLibrary, RECORDER_HANDLE handle,
                      RECORDER_CLOSE_MODE closeMode);
    /// close a recorder using the mode defined when the recorder was created (@ref RecorderClose)
    virtual ~Recorder();
    /// check if the recorder handle is valid
    operator bool() const;
    /// close the recorder using the mode defined when the recorder was created (@ref RecorderClose)
    void close();
    /// close the recorder using the given close mode (@ref RecorderClose)
    void close(RECORDER_CLOSE_MODE closeMode);
    /// get a recorder parameter (@ref RecorderGetParameterString)
    std::string getParameterString(RECORDER_PARAMETER parameter);
    /// set a recorder parameter (@ref RecorderSetParameterString)
    void setParameterString(RECORDER_PARAMETER parameter, const std::string &value);
    /// get a recorder parameter (@ref RecorderGetParameterInteger)
    int64_t getParameterInteger(RECORDER_PARAMETER parameter);
    /// set a recorder parameter (@ref RecorderSetParameterInteger)
    void setParameterInteger(RECORDER_PARAMETER parameter, int64_t value);
    /// write to the container synchronously (@ref RecorderWrite)
    void write(const RECORDER_BUFFER_INFO *info, const void *buffer);
    // read data from the container into a user buffer (@ref RecorderRead)
    size_t read(RECORDER_BUFFER_INFO *info, void *buffer, size_t bufferSize);
    // read data from the container (@ref RecorderRead)
    std::vector<char> read(RECORDER_BUFFER_INFO *info = 0);
    // export images from the container (@ref RecorderExport)
    size_t exportImages(const std::string &path, size_t count, uint32_t exportPixelFormat = 0);
    // start a new chapter (@ref RecorderStartChapter)
    void startChapter(const std::string &name = "", const std::string &info = "");

#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    struct Progress {
        size_t index;
        size_t count;
        bool working;
    };
    Progress getProgress() const;
    void abort();
#endif

private:
    RecorderLibrary *recorderLibrary;
    RECORDER_HANDLE handle;
    RECORDER_CLOSE_MODE closeMode;
#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    static int progressCallback(void *context, RECORDER_PROGRESS_STATE state, size_t index, size_t count);
    std::atomic<Progress> currentProgress;
    std::atomic<bool> abortFlag;
#endif
};

/** A Recorder library object that loads and unloads the Recorder Library and
    exposes its low-level functions
 **/
class RecorderLibrary {
public:
    explicit RecorderLibrary(const std::string &path = getDefaultPath())
        : dynlib(path)
        , initLib(reinterpret_cast<FnRecorderInitLib>(dynlib.getSymbol("RecorderInitLib")))
        , closeLib(reinterpret_cast<FnRecorderCloseLib>(dynlib.getSymbol("RecorderCloseLib")))
        , open(reinterpret_cast<FnRecorderOpen>(dynlib.getSymbol("RecorderOpen")))
        , close(reinterpret_cast<FnRecorderClose>(dynlib.getSymbol("RecorderClose")))
        , setParameterString(reinterpret_cast<FnRecorderSetParameterString>(dynlib.getSymbol("RecorderSetParameterString")))
        , getParameterString(reinterpret_cast<FnRecorderGetParameterString>(dynlib.getSymbol("RecorderGetParameterString")))
        , setParameterInteger(reinterpret_cast<FnRecorderSetParameterInteger>(dynlib.getSymbol("RecorderSetParameterInteger")))
        , getParameterInteger(reinterpret_cast<FnRecorderGetParameterInteger>(dynlib.getSymbol("RecorderGetParameterInteger")))
        , read(reinterpret_cast<FnRecorderRead>(dynlib.getSymbol("RecorderRead")))
        , write(reinterpret_cast<FnRecorderWrite>(dynlib.getSymbol("RecorderWrite")))
        , exportImages(reinterpret_cast<FnRecorderExport>(dynlib.getSymbol("RecorderExport")))
        , startChapter(reinterpret_cast<FnRecorderStartChapter>(dynlib.getSymbol("RecorderStartChapter"))) {
        initLibrary();
    }
    virtual ~RecorderLibrary() {
        closeLib();
    }

    void initLibrary() {
        RecorderError::check(initLib());
    }

    void closeLibrary() {
        RecorderError::check(closeLib());
    }

    /// Open a recorder and return a @ref Recorder object that wraps the opened recorder handle
    Recorder openRecorder(const std::string &path, RECORDER_OPEN_MODE mode,
                          RECORDER_CLOSE_MODE closeMode = RECORDER_CLOSE_MODE_TRIM, uint32_t *fileVersion = 0) {
        RECORDER_HANDLE handle = 0;
        RecorderError::check(open(path.c_str(), mode, &handle, fileVersion));
        return Recorder(*this, handle, closeMode);
    }

    static std::string getDefaultPath() {
        std::string path(Internal::getDefaultLibraryPath());
        if (path.empty()) {
            throw std::runtime_error("No default recorder library path");
        }
        return path;
    }

private:
    Internal::DynamicLibrary dynlib;
    FnRecorderInitLib initLib;
    FnRecorderCloseLib closeLib;
public:
    FnRecorderOpen open;
    FnRecorderClose close;
    FnRecorderSetParameterString setParameterString;
    FnRecorderGetParameterString getParameterString;
    FnRecorderSetParameterInteger setParameterInteger;
    FnRecorderGetParameterInteger getParameterInteger;
    FnRecorderRead read;
    FnRecorderWrite write;
    FnRecorderExport exportImages;
    FnRecorderStartChapter startChapter;
};

/** @cond */

inline void RecorderError::check(RECORDER_STATUS status) {
    switch (status) {
        case RECORDER_STATUS_OK:
            break;
        case RECORDER_STATUS_UNKNOWN_ERROR:
            throw UnknownError();
        case RECORDER_STATUS_UNKNOWN_PARAMETER:
            throw UnknownParameter();
        case RECORDER_STATUS_INVALID_PARAMETER_TYPE:
            throw InvalidParameterType();
        case RECORDER_STATUS_INVALID_PARAMETER_VALUE:
            throw InvalidParameterValue();
        case RECORDER_STATUS_BUFFER_TOO_SMALL:
            throw BufferTooSmall();
        case RECORDER_STATUS_PARAMETER_IS_READ_ONLY:
            throw ParameterIsReadOnly();
        case RECORDER_STATUS_SYSTEM_ERROR:
            throw SystemError();
        case RECORDER_STATUS_INVALID_CONTAINER_PATH:
            throw InvalidContainerPath();
        case RECORDER_STATUS_DATA_FILE_FULL:
            throw DataFileFull();
        case RECORDER_STATUS_OPERATION_NOT_ALLOWED:
            throw OperationNotAllowed();
        case RECORDER_STATUS_INDEX_OUT_OF_RANGE:
            throw IndexOutOfRange();
        case RECORDER_STATUS_INVALID_INDEX_DATA:
            throw InvalidIndexData();
        case RECORDER_STATUS_INVALID_INDEX_SIZE:
            throw InvalidIndexSize();
        case RECORDER_STATUS_UNSUPPORTED_DATABASE_VERSION:
            throw UnsupportedDatabaseVersion();
        case RECORDER_STATUS_INVALID_INDEX_HEADER:
            throw InvalidIndexHeader();
        case RECORDER_STATUS_INVALID_LENGTH_WRITTEN:
            throw InvalidLengthWritten();
        case RECORDER_STATUS_NOT_INITIALIZED:
            throw NotInitialized();
        case RECORDER_STATUS_INVALID_HANDLE:
            throw InvalidHandle();
        case RECORDER_STATUS_RESOURCE_IN_USE:
            throw ResourceInUse();
        case RECORDER_STATUS_END_OF_DATA:
            throw EndOfData();
        case RECORDER_STATUS_INVALID_ARGUMENT:
            throw InvalidArgument();
        case RECORDER_STATUS_NO_CONTAINER:
            throw NoContainer();
        case RECORDER_STATUS_LICENSE_MANAGER_ERROR:
            throw LicenseManagerError();
        case RECORDER_STATUS_NO_LICENSE:
            throw NoLicense();
        case RECORDER_STATUS_IMAGE_CONVERSION_ERROR:
            throw ImageConversionError();
        case RECORDER_STATUS_UNSUPPORTED_IMAGE_FORMAT:
            throw UnsupportedImageFormatError();
        case RECORDER_STATUS_ABORTED:
            throw Aborted();
        case RECORDER_STATUS_INVALID_DATA_SIZE:
            throw InvalidDataSize();
        case RECORDER_STATUS_INVALID_CHAPTER_CHARACTER:
            throw InvalidChapterCharacter();
        case RECORDER_STATUS_RESERVED_CHAPTER_NAME:
            throw ReservedChapterName();
        case RECORDER_STATUS_CHAPTER_NAME_ALREADY_USED:
            throw ChapterNameAlreadyUsed();
        case RECORDER_STATUS_CHAPTER_NAME_TOO_LONG:
            throw ChapterNameTooLong();
        default: {
            std::stringstream ss;
            ss << "RecorderError(RECORDER_STATUS=" << status << ")";
            throw RecorderError(status, ss.str());
        }
    }
}

inline RecorderError::RecorderError(RECORDER_STATUS status, const std::string &description)
    : std::runtime_error(description)
    , status(status)
{}

#define EGRABBER_RECORDER_ERROR_CTOR(error, status) \
    inline error::error(): RecorderError(status, #error){}

EGRABBER_RECORDER_ERROR_CTOR(UnknownError,               RECORDER_STATUS_UNKNOWN_ERROR);
EGRABBER_RECORDER_ERROR_CTOR(UnknownParameter,           RECORDER_STATUS_UNKNOWN_PARAMETER);
EGRABBER_RECORDER_ERROR_CTOR(InvalidParameterType,       RECORDER_STATUS_INVALID_PARAMETER_TYPE);
EGRABBER_RECORDER_ERROR_CTOR(InvalidParameterValue,      RECORDER_STATUS_INVALID_PARAMETER_VALUE);
EGRABBER_RECORDER_ERROR_CTOR(BufferTooSmall,             RECORDER_STATUS_BUFFER_TOO_SMALL);
EGRABBER_RECORDER_ERROR_CTOR(ParameterIsReadOnly,        RECORDER_STATUS_PARAMETER_IS_READ_ONLY);
EGRABBER_RECORDER_ERROR_CTOR(SystemError,                RECORDER_STATUS_SYSTEM_ERROR);
EGRABBER_RECORDER_ERROR_CTOR(InvalidContainerPath,       RECORDER_STATUS_INVALID_CONTAINER_PATH);
EGRABBER_RECORDER_ERROR_CTOR(DataFileFull,               RECORDER_STATUS_DATA_FILE_FULL);
EGRABBER_RECORDER_ERROR_CTOR(OperationNotAllowed,        RECORDER_STATUS_OPERATION_NOT_ALLOWED);
EGRABBER_RECORDER_ERROR_CTOR(IndexOutOfRange,            RECORDER_STATUS_INDEX_OUT_OF_RANGE);
EGRABBER_RECORDER_ERROR_CTOR(InvalidIndexData,           RECORDER_STATUS_INVALID_INDEX_DATA);
EGRABBER_RECORDER_ERROR_CTOR(InvalidIndexSize,           RECORDER_STATUS_INVALID_INDEX_SIZE);
EGRABBER_RECORDER_ERROR_CTOR(UnsupportedDatabaseVersion, RECORDER_STATUS_UNSUPPORTED_DATABASE_VERSION);
EGRABBER_RECORDER_ERROR_CTOR(InvalidIndexHeader,         RECORDER_STATUS_INVALID_INDEX_HEADER);
EGRABBER_RECORDER_ERROR_CTOR(InvalidLengthWritten,       RECORDER_STATUS_INVALID_LENGTH_WRITTEN);
EGRABBER_RECORDER_ERROR_CTOR(NotInitialized,             RECORDER_STATUS_NOT_INITIALIZED);
EGRABBER_RECORDER_ERROR_CTOR(InvalidHandle,              RECORDER_STATUS_INVALID_HANDLE);
EGRABBER_RECORDER_ERROR_CTOR(ResourceInUse,              RECORDER_STATUS_RESOURCE_IN_USE);
EGRABBER_RECORDER_ERROR_CTOR(EndOfData,                  RECORDER_STATUS_END_OF_DATA);
EGRABBER_RECORDER_ERROR_CTOR(InvalidArgument,            RECORDER_STATUS_INVALID_ARGUMENT);
EGRABBER_RECORDER_ERROR_CTOR(NoContainer,                RECORDER_STATUS_NO_CONTAINER);
EGRABBER_RECORDER_ERROR_CTOR(LicenseManagerError,        RECORDER_STATUS_LICENSE_MANAGER_ERROR);
EGRABBER_RECORDER_ERROR_CTOR(NoLicense,                  RECORDER_STATUS_NO_LICENSE);
EGRABBER_RECORDER_ERROR_CTOR(ImageConversionError,       RECORDER_STATUS_IMAGE_CONVERSION_ERROR);
EGRABBER_RECORDER_ERROR_CTOR(UnsupportedImageFormatError, RECORDER_STATUS_UNSUPPORTED_IMAGE_FORMAT);
EGRABBER_RECORDER_ERROR_CTOR(Aborted,                    RECORDER_STATUS_ABORTED);
EGRABBER_RECORDER_ERROR_CTOR(InvalidDataSize,            RECORDER_STATUS_INVALID_DATA_SIZE);
EGRABBER_RECORDER_ERROR_CTOR(InvalidChapterCharacter,    RECORDER_STATUS_INVALID_CHAPTER_CHARACTER);
EGRABBER_RECORDER_ERROR_CTOR(ReservedChapterName,        RECORDER_STATUS_RESERVED_CHAPTER_NAME);
EGRABBER_RECORDER_ERROR_CTOR(ChapterNameAlreadyUsed,     RECORDER_STATUS_CHAPTER_NAME_ALREADY_USED);
EGRABBER_RECORDER_ERROR_CTOR(ChapterNameTooLong,         RECORDER_STATUS_CHAPTER_NAME_TOO_LONG);

#if __cplusplus >= 201103L
inline Recorder::Recorder(Recorder &&other)
    : recorderLibrary(other.recorderLibrary)
    , handle(other.handle)
    , closeMode(other.closeMode)
#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    , currentProgress(other.currentProgress.load())
    , abortFlag(other.abortFlag.load())
#endif
{
    other.handle = 0;
}

inline Recorder &Recorder::operator=(Recorder &&other) {
    if (&other == this) {
        return *this;
    }

    std::swap(recorderLibrary, other.recorderLibrary);
    std::swap(handle, other.handle);
    std::swap(closeMode, other.closeMode);

#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    currentProgress = other.currentProgress.load();
    abortFlag = other.abortFlag.load();
#endif

    return *this;
}
#endif

inline Recorder::Recorder(RecorderLibrary &recorderLibrary, RECORDER_HANDLE handle,
                          RECORDER_CLOSE_MODE closeMode)
    : recorderLibrary(&recorderLibrary)
    , handle(handle)
    , closeMode(closeMode)
#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    , currentProgress({0, 0, false})
    , abortFlag(false)
#endif
{}
inline Recorder::~Recorder() {
    try {
        close();
    } catch (...) {
    }
}
inline void Recorder::close() {
    close(closeMode);
}
inline void Recorder::close(RECORDER_CLOSE_MODE mode) {
    if (handle) {
        RecorderError::check(recorderLibrary->close(handle, mode));
        handle = 0;
    }
}
inline Recorder::operator bool() const {
    return handle != 0;
}
inline std::string Recorder::getParameterString(RECORDER_PARAMETER parameter) {
    std::vector<char> value(128);
    size_t size = value.size();
    RECORDER_STATUS status = recorderLibrary->getParameterString(handle, parameter, &value[0], &size);
    if (status == RECORDER_STATUS_BUFFER_TOO_SMALL) {
        RecorderError::check(recorderLibrary->getParameterString(handle, parameter, 0, &size));
        value.resize(size);
        status = recorderLibrary->getParameterString(handle, parameter, &value[0], &size);
    }
    RecorderError::check(status);
    return (size) ? std::string(&value[0]) : std::string();
}
inline void Recorder::setParameterString(RECORDER_PARAMETER parameter, const std::string &value) {
    RecorderError::check(recorderLibrary->setParameterString(handle, parameter, value.c_str()));
}
inline int64_t Recorder::getParameterInteger(RECORDER_PARAMETER parameter) {
    int64_t value = 0;
    RecorderError::check(recorderLibrary->getParameterInteger(handle, parameter, &value));
    return value;
}
inline void Recorder::setParameterInteger(RECORDER_PARAMETER parameter, int64_t value) {
    RecorderError::check(recorderLibrary->setParameterInteger(handle, parameter, value));
}
inline void Recorder::write(const RECORDER_BUFFER_INFO *info, const void *buffer) {
    RecorderError::check(recorderLibrary->write(handle, info, buffer, 0, 0, 0));
}
inline size_t Recorder::read(RECORDER_BUFFER_INFO *info, void *buffer, size_t bufferSize) {
    size_t size = bufferSize;
    RecorderError::check(recorderLibrary->read(handle, info, buffer, &size, 0));
    return size;
}
inline std::vector<char> Recorder::read(RECORDER_BUFFER_INFO *info) {
    size_t size = 0;
    RecorderError::check(recorderLibrary->read(handle, 0, 0, &size, 0));
    std::vector<char> data(size ? size : 1);
    RecorderError::check(recorderLibrary->read(handle, info, &data[0], &size, 0));
    data.resize(size);
    return data;
}
inline size_t Recorder::exportImages(const std::string &path, size_t count, uint32_t exportPixelFormat) {
#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
    RecorderError::check(recorderLibrary->exportImages(handle, path.c_str(), &count, exportPixelFormat, 0, &progressCallback, this));
#else
    RecorderError::check(recorderLibrary->exportImages(handle, path.c_str(), &count, exportPixelFormat, 0, 0, 0));
#endif
    return count;
}
inline void Recorder::startChapter(const std::string &name, const std::string &info) {
    RecorderError::check(recorderLibrary->startChapter(handle, name.c_str(), info.c_str()));
}


#if ERECORDERLIBRARY_WITH_PROGRESS_REPORT
inline int Recorder::progressCallback(void *context, RECORDER_PROGRESS_STATE state, size_t index, size_t count) {
    Recorder *recorder = reinterpret_cast<Recorder *>(context);
    if (recorder) {
        if (state == RECORDER_PROGRESS_STATE_STARTING) {
            recorder->currentProgress.store({0, 0, true});
            recorder->abortFlag.store(false);
        } else if (state == RECORDER_PROGRESS_STATE_ONGOING) {
            recorder->currentProgress.store({index, count, true});
            if (recorder->abortFlag.load()) {
                return -1;
            }
        } else if (state == RECORDER_PROGRESS_STATE_ENDING) {
            Progress finished(recorder->currentProgress.load());
            finished.working = false;
            recorder->currentProgress.store(finished);
        }
    }
    return 0;
}
inline Recorder::Progress Recorder::getProgress() const {
    return currentProgress.load();
}
inline void Recorder::abort() {
    abortFlag.store(true);
}
#endif

/** @endcond */

/** @} */

} // namespace EGrabberRecorder
} // namespace Euresys

#endif
