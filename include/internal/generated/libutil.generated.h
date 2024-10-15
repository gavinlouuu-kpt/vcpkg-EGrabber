/* Copyright Euresys 2021*/

#ifndef EURESYS_LIBUTIL_GENERATED_HEADER_FILE
#define EURESYS_LIBUTIL_GENERATED_HEADER_FILE

#include "../cEGrabberErrorList.h"
#include "../box.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

static inline void checkStatus(const EGrabberDll &dll, int status) {
    if (status == 0) {
        return;
    }
    // The type of the error returned by the EGrabber library is identified from the code
    // of the last thread-local error in the library. Once identified, an exception is
    // reconstructed from that last thread-local error.
    cEGrabber::CEGRABBER_ERROR code;
    checkStatusCritical(dll.euInternal_lastError_getCode(&code));
    switch (code) {
        case ce::CEGRABBER_GENAPI_ERROR:
        {
            Box<genapi_error, ce::Eur_genapi_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_genapi_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_CTI_LOADING_ERROR:
        {
            Box<cti_loading_error, ce::Eur_cti_loading_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_cti_loading_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_MISSING_GENTL_SYMBOL:
        {
            Box<missing_gentl_symbol, ce::Eur_missing_gentl_symbol> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_missing_gentl_symbol(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_UNEXPECTED_DATA_TYPE:
        {
            Box<unexpected_data_type, ce::Eur_unexpected_data_type> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_unexpected_data_type(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_UNEXPECTED_DATA_SIZE:
        {
            Box<unexpected_data_size, ce::Eur_unexpected_data_size> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_unexpected_data_size(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_CLIENT_ERROR:
        {
            Box<client_error, ce::Eur_client_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_client_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_GENTL_ERROR:
        {
            Box<gentl_error, ce::Eur_gentl_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_gentl_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_THREAD_ERROR:
        {
            Box<thread_error, ce::Eur_thread_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_thread_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_INTERNAL_ERROR:
        {
            Box<internal_error, ce::Eur_internal_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_internal_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_NOT_ALLOWED:
        {
            Box<not_allowed, ce::Eur_not_allowed> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAEur_not_allowed(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_STD_RUNTIME_ERROR:
        {
            Box<std::runtime_error, ce::std_runtime_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAstd_runtime_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_STD_LOGIC_ERROR:
        {
            Box<std::logic_error, ce::std_logic_error> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAstd_logic_error(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        case ce::CEGRABBER_STD_EXCEPTION:
        {
            Box<std::exception, ce::std_exception> errorBox(dll);
            checkStatusCritical(dll.euInternal_lastError_getAstd_exception(errorBox.getBoxAddr()));
            throw errorBox.unbox();
        }
        default:
            throw egrabber_library_error(-1, "unknown cEGrabber error code " + intToString(code));
    }
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#define EGRABBER_CALLBACK_CATCH \
    catch (const genapi_error &e) { \
        Internal::Box<genapi_error, ce::Eur_genapi_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_genapi_error(errorBox.getBox())); \
    } \
    catch (const cti_loading_error &e) { \
        Internal::Box<cti_loading_error, ce::Eur_cti_loading_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_cti_loading_error(errorBox.getBox())); \
    } \
    catch (const missing_gentl_symbol &e) { \
        Internal::Box<missing_gentl_symbol, ce::Eur_missing_gentl_symbol> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_missing_gentl_symbol(errorBox.getBox())); \
    } \
    catch (const unexpected_data_type &e) { \
        Internal::Box<unexpected_data_type, ce::Eur_unexpected_data_type> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_unexpected_data_type(errorBox.getBox())); \
    } \
    catch (const unexpected_data_size &e) { \
        Internal::Box<unexpected_data_size, ce::Eur_unexpected_data_size> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_unexpected_data_size(errorBox.getBox())); \
    } \
    catch (const client_error &e) { \
        Internal::Box<client_error, ce::Eur_client_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_client_error(errorBox.getBox())); \
    } \
    catch (const gentl_error &e) { \
        Internal::Box<gentl_error, ce::Eur_gentl_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_gentl_error(errorBox.getBox())); \
    } \
    catch (const thread_error &e) { \
        Internal::Box<thread_error, ce::Eur_thread_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_thread_error(errorBox.getBox())); \
    } \
    catch (const internal_error &e) { \
        Internal::Box<internal_error, ce::Eur_internal_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_internal_error(errorBox.getBox())); \
    } \
    catch (const not_allowed &e) { \
        Internal::Box<not_allowed, ce::Eur_not_allowed> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFEur_not_allowed(errorBox.getBox())); \
    } \
    catch (const std::runtime_error &e) { \
        Internal::Box<std::runtime_error, ce::std_runtime_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFstd_runtime_error(errorBox.getBox())); \
    } \
    catch (const std::logic_error &e) { \
        Internal::Box<std::logic_error, ce::std_logic_error> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFstd_logic_error(errorBox.getBox())); \
    } \
    catch (const std::exception &e) { \
        Internal::Box<std::exception, ce::std_exception> errorBox(grabber->getGenTL().egrabberDll, e); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFstd_exception(errorBox.getBox())); \
    } \
    catch (...) { \
        Internal::Box<std::runtime_error, ce::std_runtime_error> errorBox(grabber->getGenTL().egrabberDll, std::runtime_error("Unknown error from a callback")); \
        checkStatusCriticalCallback(grabber->gentl.egrabberDll, grabber->gentl.egrabberDll.euInternal_lastCallbackError_setFstd_runtime_error(errorBox.getBox())); \
    }

#endif // EURESYS_LIBUTIL_GENERATED_HEADER_FILE
