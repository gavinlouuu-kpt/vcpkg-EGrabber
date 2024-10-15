/* Copyright Euresys 2020 */

#ifndef EGRABBER_RECORDER_H
#define EGRABBER_RECORDER_H

/** @file
    Header file for Euresys Recorder Library
 **/

#if defined(_WIN32)

#if !defined(EGRABBER_RECORDER_API_DECL)
#define EGRABBER_RECORDER_API_DECL __declspec(dllimport)
#endif
#if defined(__i386__)
#define EGRABBER_RECORDER_API_CALLTYPE __stdcall
#else
#define EGRABBER_RECORDER_API_CALLTYPE
#endif

#elif defined (__GNUC__) && (__GNUC__ >= 4) && (defined (__linux__) || defined (__APPLE__))

#define EGRABBER_RECORDER_API_DECL __attribute__((visibility("default")))
#if defined (__i386__)
#define EGRABBER_RECORDER_API_CALLTYPE __attribute__((stdcall))
#else
#define EGRABBER_RECORDER_API_CALLTYPE
#endif

#else
#error Unknown platform
#endif

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
namespace Euresys {
namespace EGrabberRecorder {
#endif

enum RECORDER_STATUS_LIST {
    RECORDER_STATUS_OK                           = 0,   /**< The operation completed successfully */
    RECORDER_STATUS_NOT_INITIALIZED              = -1,  /**< The recorder library is not initialized */
    RECORDER_STATUS_UNKNOWN_ERROR                = -2,  /**< An unknown error has occurred */
    RECORDER_STATUS_UNKNOWN_PARAMETER            = -3,  /**< The recorder parameter is unknown */
    RECORDER_STATUS_INVALID_PARAMETER_TYPE       = -4,  /**< The recorder parameter type is invalid */
    RECORDER_STATUS_INVALID_PARAMETER_VALUE      = -5,  /**< The recorder parameter value is invalid */
    RECORDER_STATUS_BUFFER_TOO_SMALL             = -6,  /**< The destination buffer is too small */
    RECORDER_STATUS_PARAMETER_IS_READ_ONLY       = -7,  /**< The recorder parameter is read-only */
    RECORDER_STATUS_SYSTEM_ERROR                 = -8,  /**< A system error has occurred */
    RECORDER_STATUS_INVALID_CONTAINER_PATH       = -9,  /**< The specified container path is invalid */
    RECORDER_STATUS_DATA_FILE_FULL               = -11, /**< The container data file is full */
    RECORDER_STATUS_OPERATION_NOT_ALLOWED        = -12, /**< The operation is not allowed by the recorder open mode */
    RECORDER_STATUS_INDEX_OUT_OF_RANGE           = -13, /**< The RECORDER_PARAMETER_RECORD_INDEX value is out of range */
    RECORDER_STATUS_INVALID_INDEX_DATA           = -14, /**< The internal meta-data of the current record is invalid (partial read) */
    RECORDER_STATUS_INVALID_INDEX_SIZE           = -15, /**< The internal meta-data size of the container is invalid (partial read or invalid meta-data file size) */
    RECORDER_STATUS_UNSUPPORTED_DATABASE_VERSION = -16, /**< The given container is not supported by the recorder library */
    RECORDER_STATUS_INVALID_INDEX_HEADER         = -17, /**< The internal meta-data header of the container is invalid */
    RECORDER_STATUS_INVALID_LENGTH_WRITTEN       = -18, /**< Some data was not completely written to disk (partial write) */
    RECORDER_STATUS_INVALID_HANDLE               = -19, /**< The record handle is invalid */
    RECORDER_STATUS_RESOURCE_IN_USE              = -20, /**< The resource is already in use */
    RECORDER_STATUS_END_OF_DATA                  = -21, /**< There is no more record to read in the container */
    RECORDER_STATUS_NO_CONTAINER                 = -22, /**< The path does not contain a container and read only access is required */
    RECORDER_STATUS_INVALID_ARGUMENT             = -23, /**< A given argument is invalid */
    RECORDER_STATUS_LICENSE_MANAGER_ERROR        = -24, /**< An error occurred in the licenser manager, please contact Euresys support */
    RECORDER_STATUS_NO_LICENSE                   = -25, /**< There is no valid license for this library, please contact Euresys support */
    RECORDER_STATUS_IMAGE_CONVERSION_ERROR       = -26, /**< An image conversion error has occurred */
    RECORDER_STATUS_UNSUPPORTED_IMAGE_FORMAT     = -27, /**< The image format is not supported by the export file */
    RECORDER_STATUS_ABORTED                      = -28, /**< The current operation has been aborted by the user */
    RECORDER_STATUS_INVALID_DATA_SIZE            = -29, /**< A read operation returned an invalid size (partial read or invalid data file size) */
    RECORDER_STATUS_INVALID_CHAPTER_CHARACTER    = -30, /**< The chapter name has an invalid character */
    RECORDER_STATUS_RESERVED_CHAPTER_NAME        = -31, /**< The chapter name conflicts with a reserved name */
    RECORDER_STATUS_CHAPTER_NAME_ALREADY_USED    = -32, /**< The chapter name is already used */
    RECORDER_STATUS_CHAPTER_NAME_TOO_LONG        = -33, /**< The chapter name is too long */
};
typedef int RECORDER_STATUS; /**< @see RECORDER_STATUS_LIST */

typedef struct S_RECORDER_BUFFER_INFO {
    uint64_t size;         /**< buffer size (in bytes) */
    uint64_t pitch;        /**< buffer pitch in bytes (size of a line including padding) */
    uint64_t width;        /**< buffer width (number of pixels in a line) */
    uint64_t height;       /**< delivered height (e.g. GenTL::BUFFER_INFO_DELIVERED_IMAGEHEIGHT) */
    uint32_t pixelformat;  /**< buffer pixel format (GenICam PFNC 32-bit value) */
    uint32_t partCount;    /**< fixed maximum number of parts in the buffer */
    uint64_t timestamp;    /**< buffer timestamp, expressed in nanoseconds since the computer booted (e.g. GenTL::BUFFER_INFO_TIMESTAMP_NS) */
    uint64_t userdata;     /**< any buffer specific user data */
    uint64_t utc;          /**< UTC timestamp (if 0 when written, read will return buffer timestamp converted to UTC using the synchronized timestamps of the buffer chapter) */
    uint64_t chapterIndex; /**< chapter index; Chapter0 always exists for legacy recordings (set by the library) */
    uint64_t partSize;     /**< size of each buffer part (if 0 when written, read will return (size / partCount) */
    uint64_t reserved[13]; /**< reserved for future use, must be 0 */
} RECORDER_BUFFER_INFO;

typedef void *RECORDER_HANDLE;

enum RECORDER_PARAMETER_LIST {
    RECORDER_PARAMETER_VERSION                      = 0, /**< recorder library version */
    RECORDER_PARAMETER_CONTAINER_SIZE               = 1, /**< recorder container size */
    RECORDER_PARAMETER_RECORD_INDEX                 = 2, /**< current recorder index position */
    RECORDER_PARAMETER_RECORD_COUNT                 = 3, /**< number of records in the recorder container */
    RECORDER_PARAMETER_REMAINING_SPACE_ON_DEVICE    = 4, /**< space left on the same disk as the recorder container */
    RECORDER_PARAMETER_BUFFER_OPTIMAL_ALIGNMENT     = 5, /**< buffer alignment recommended for best write performance on recorder storage disk, changing the value should be done with extreme caution (set 0 for default value) */
    RECORDER_PARAMETER_DATABASE_VERSION             = 7, /**< format version of recorder container */
    RECORDER_PARAMETER_REMAINING_SPACE_IN_CONTAINER = 8, /**< space left in the recorder container */
    RECORDER_PARAMETER_CHAPTER_COUNT                = 10,/**< number of chapters in the container (read only) */
    RECORDER_PARAMETER_CHAPTER_INDEX                = 11,/**< chapter selector */
    RECORDER_PARAMETER_CHAPTER_RECORD_INDEX         = 12,/**< index of record in the current chapter */
    RECORDER_PARAMETER_CHAPTER_RECORD_COUNT         = 13,/**< number of records in the current chapter (read only) */
    RECORDER_PARAMETER_CHAPTER_UTC                  = 14,/**< chapter UTC time (UTC value of synchronized pair of timestamps for the current chapter, cf. RecorderStartChapter) (read only) */
    RECORDER_PARAMETER_CHAPTER_TIMESTAMP            = 15,/**< chapter timestamp (system value of synchronized pair of timestamps for the current chapter, cf. RecorderStartChapter) (read only) */
    RECORDER_PARAMETER_CHAPTER_NAME                 = 16,/**< chapter name */
    RECORDER_PARAMETER_CHAPTER_USER_INFO            = 17,/**< chapter user info */
    RECORDER_PARAMETER_BAYER_DECODING_METHOD        = 18,/**< decoding method to use when Bayer format is converted (default is RECORDER_BAYER_DECODING_METHOD_1, cf. RECORDER_BAYER_DECODING_METHOD) */
    RECORDER_PARAMETER_LICENSE_STATUS               = 19,/**< recorder library license status */
    RECORDER_PARAMETER_PARTIAL_IO_RETRY_LIMIT       = 20,/**< number of retries for partial I/O operations (read/write) before raising invalid data length errors (default is 1) */
    RECORDER_PARAMETER_DEVICE_TEMPERATURE           = 21,/**< current temperature of the device in mK (might require special permissions) (read only) */
};
typedef unsigned int RECORDER_PARAMETER; /**< @see RECORDER_PARAMETER_LIST */

enum RECORDER_OPEN_MODE_LIST {
    RECORDER_OPEN_MODE_WRITE  = 0, /**< open a new or an existing (to overwrite) recorder in write mode (record index set to 0) */
    RECORDER_OPEN_MODE_READ   = 1, /**< open an existing recorder in read mode (record index set to 0) */
    RECORDER_OPEN_MODE_APPEND = 2, /**< open an existing recorder in append mode (record index set to record count) */
};
typedef unsigned int RECORDER_OPEN_MODE; /**< @see RECORDER_OPEN_MODE_LIST */

enum RECORDER_CLOSE_MODE_LIST {
    RECORDER_CLOSE_MODE_TRIM                = 0,     /**< trim the recorder container size when closing the recorder */
    RECORDER_CLOSE_MODE_KEEP                = 1,     /**< keep the current recorder container size when closing the recorder */
    RECORDER_CLOSE_MODE_DONT_TRIM_CHAPTERS  = 0x100, /**< keep the trailing chapters even if they are empty (can be combined with trim or keep) */
};
typedef unsigned int RECORDER_CLOSE_MODE; /**< @see RECORDER_CLOSE_MODE_LIST */

enum RECORDER_PROGRESS_STATE_LIST {
    RECORDER_PROGRESS_STATE_STARTING = 0,   /**< An operation is starting, index and count are not set */
    RECORDER_PROGRESS_STATE_ONGOING  = 1,   /**< An operation is ongoing, index and count are set according to the current progress */
    RECORDER_PROGRESS_STATE_ENDING   = 2,   /**< An operation is ending (successfully or not), index and count are not set */
};
typedef unsigned int RECORDER_PROGRESS_STATE; /**< @see RECORDER_PROGRESS_STATE_LIST */
typedef int (*RECORDER_PROGRESS_CALLBACK)(void *context, RECORDER_PROGRESS_STATE state, size_t index, size_t count);

enum RECORDER_BAYER_DECODING_METHOD_LIST {
    RECORDER_BAYER_DECODING_METHOD_NONE = -1,   /**< Bayer decoding disabled, content is interpreted as Mono */
    RECORDER_BAYER_DECODING_METHOD_1 = 1,       /**< Bayer decoding method 1 (3x3 interpolation, a.k.a. legacy method) */
    RECORDER_BAYER_DECODING_METHOD_2 = 2,       /**< Bayer decoding method 2 (3x3 median-based interpolation, a.k.a. advanced method) */
    RECORDER_BAYER_DECODING_METHOD_3 = 3,       /**< Bayer decoding method 3 (5x5 gradient-based interpolation) */
    RECORDER_BAYER_DECODING_METHOD_5 = 5,       /**< Bayer decoding method 5 (2x2 average-based interpolation) */
};
typedef int64_t RECORDER_BAYER_DECODING_METHOD;

#define RECORDER_API EGRABBER_RECORDER_API_DECL RECORDER_STATUS EGRABBER_RECORDER_API_CALLTYPE

/** @defgroup ERecorder (C API)
    Euresys Recorder low-level C API
    @{
 **/

/** Open the Recorder library **/
RECORDER_API RecorderInitLib();
/** Close the Recorder library **/
RECORDER_API RecorderCloseLib();
/** Open a recorder object
    @param path         path to the recorder container to open
    @param mode         the operation mode of the recorder
    @param handle       out: the handle of the opened recorder in case of success
    @param fileVersion  out: the version of the recorder container format
                        (optional, fileVersion may be NULL)
 **/
RECORDER_API RecorderOpen(const char *path, RECORDER_OPEN_MODE mode, RECORDER_HANDLE *handle, uint32_t *fileVersion);
/** Close a recorder object
    @param handle   the handle of the recorder object to close
    @param mode     specifies how the recorder container is closed:
                    - if mode is RECORDER_CLOSE_MODE_TRIM: the recorder container
                      is reduced to the smallest size that fits the container contents
                    - if mode is RECORDER_CLOSE_MODE_KEEP: the recorder container
                      size is unchanged
                    - if the flag RECORDER_CLOSE_MODE_DONT_TRIM_CHAPTERS is added
                      to the mode, the trailing chapters will be kept even if they are empty;
                      by default, trailing empty chapters are removed
 **/
RECORDER_API RecorderClose(RECORDER_HANDLE handle, RECORDER_CLOSE_MODE mode);
/** Set a recorder object parameter string value
    @param handle       the handle of the recorder object
    @param parameter    the identifier of the parameter to set (see @ref RECORDER_PARAMETER)
    @param value        the new string value of the parameter
 **/
RECORDER_API RecorderSetParameterString(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, const char *value);
/** Get a recorder object parameter string value
    @param handle       the handle of the recorder object
    @param parameter    the identifier of the parameter to get (see @ref RECORDER_PARAMETER)
    @param value        optional output buffer for the parameter value:
                        - if value is NULL: the required size of the output
                          buffer is written to the output parameter size
                        - if value is not NULL: the string value is written to
                          the output buffer
    @param size         in/out: size of output buffer
 **/
RECORDER_API RecorderGetParameterString(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, char *value, size_t *size);
/** Set a recorder object parameter integer value
    @param handle       the handle of the recorder object
    @param parameter    the identifier of the parameter to set (see @ref RECORDER_PARAMETER)
    @param value        the new integer value of the parameter
 **/
RECORDER_API RecorderSetParameterInteger(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, int64_t value);
/** Get a recorder object parameter integer value
    @param handle       the handle of the recorder object
    @param parameter    the identifier of the parameter to get (see @ref RECORDER_PARAMETER)
    @param value        out: the current integer value of the parameter
 **/
RECORDER_API RecorderGetParameterInteger(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, int64_t *value);
/** Read the record at the current index position from a recorder container opened in read mode
    @param handle       the handle of the recorder object
    @param info         out: optional output buffer where record buffer info
                        will be written
    @param buffer       out: optional output buffer where record buffer data
                        will be written
    @param bufferSize   in/out: size of output buffer
    @param reserved     must be nullptr
    @note the function reads the buffer info and data of the record at the
          position defined by the parameter RECORDER_PARAMETER_RECORD_INDEX
          - when buffer is NULL: the recorder index is not changed
          - when buffer is not NULL: the recorder index is automatically set
            to the next record after a successful read
 **/
RECORDER_API RecorderRead(RECORDER_HANDLE handle, RECORDER_BUFFER_INFO *info, void *buffer, size_t *bufferSize, void *reserved);
/** Write buffer info and data to a recorder container opened in write or append mode
    @param handle           the handle of the recorder object
    @param info             the buffer info to write to the container
    @param buffer           the buffer data to write to the container
    @param reserved1        must be nullptr
    @param reserved2        must be nullptr
    @param reserved3        must be nullptr
    @note the buffer info and data are written to the container at the current
          index position (RECORDER_PARAMETER_RECORD_INDEX); the recorder index
          is automatically incremented by one after a write and the recorder
          count (RECORDER_PARAMETER_RECORD_COUNT) is also adapted accordingly
 **/
RECORDER_API RecorderWrite(RECORDER_HANDLE handle, const RECORDER_BUFFER_INFO *info, const void *buffer, void *reserved1, void *reserved2, void *reserved3);
/** Export a range of recorded images to files. The container must be opened in read mode
    @param handle            the handle of the recorder object
    @param path              the path template of the exported files
                             (see note for a description of the name decoration)
    @param count             on input: the number of records to export
                             on output: the number of records actually exported
    @param exportPixelFormat the pixel format of the exported file; or 0 to
                             disable image conversions and keep the original
                             pixel format
    @param reserved          must be 0
    @param progressCallback  optional progress callback; if progressCallback is different
                             from NULL, it is called before exporting each buffer;
                             the export continues as long as the callback returns 0;
                             if the callback returns a value different from 0,
                             RecorderExport will stop and return RECORDER_STATUS_ABORTED
    @param progressContext   progress context passed to progress callback
    @note export starts at the current index position (RECORDER_PARAMETER_RECORD_INDEX)
          in the container and goes on until "count" records have been exported or the
          end of the container is reached; the count parameter is updated accordingly;
          the RECORDER_PARAMETER_RECORD_INDEX is updated accordingly.
    @note file name decoration uses the `@` character as a place holder for the following:
          - `@i` for the index relative to the first record in the container
            (number of digits used is defined by the number of records in the container)
          - `@n` for the index relative to the current record written
            (number of digits used is defined by the count parameter)
          - `@p` for the part index relative to the record
            (number of digits used is defined by the buffer part count of the record)
          - `@t` for the timestamp value in RECORDER_BUFFER_INFO::timestamp of the exported record
          - `@c` for the chapter index
          - `@C` for the chapter name
          - `@@` for the literal `@`
          All other `@` patterns are invalid and a RECORDER_STATUS_INVALID_ARGUMENT is returned.
    @note the file format is derived from the file extension
          - .tiff or .tif for the TIFF file format
          - .mkv for the Matroska MKV file format (using the V_UNCOMPRESSED codec)
          If the path does not have an extension, a RECORDER_STATUS_INVALID_ARGUMENT is returned
    @note the allowed values for exportPixelFormat depend on the file type.
          - TIFF files support the following: Mono8, Mono16, RGB8, RGB16
          - MKV files support the following: Mono8, RGB8
    @note for TIFF files:
          - if count is greater than 1 and path does not contain any `@` pattern, we add `.@n` before
            the file extension
          - if a record contains more than 1 part and the path does not contain the `@p` pattern,
            we add `.@p` before the file extension
    @note for MKV files:
          - the export operation creates one MKV file per chapter; if the export operation spans
            several chapters, we add `@.n` automatically before the file extension
          - the image width, height and pixel format must be constant for the entire file.
            The first exported image is used to define these values. A subsequent image with a
            different format will be simply skipped and the returned count will not be updated.
          - timestamps increase monotonically; when a backward discontinuity is detected i.e. the
            relative time from the beginning of the file of the image to be written is less than the
            relative time of the latest image written, a new time reference is taken
    @note most of the times, a record contains one image (one buffer part) so the number of exported
          images matches the number of exported records; but, if a record contains more than 1 part,
          each part is exported as a separate image so the number of exported images will be greater
          than the output "count"
    @note Records containing Bayer formats are converted using the decoding method defined by the
          parameter RECORDER_PARAMETER_BAYER_DECODING_METHOD
**/
RECORDER_API RecorderExport(RECORDER_HANDLE handle, const char *path, size_t *count,
                            uint32_t exportPixelFormat, unsigned int reserved,
                            RECORDER_PROGRESS_CALLBACK progressCallback, void *progressContext);
/** Start a new chapter. The container must be in write mode.
    @param handle           the handle of the recorder object
    @param name             optional name of the new chapter (may be nullptr)
    @param info             an optional info string (may be nullptr)
    @note a chapter helps grouping recordings and provides a synchronization point between system and UTC timestamps
    @note a chapter is automatically created if needed on the first write after opening the container if
          this function has not been called. The name of the automatically created chapter is "Chapter<xx>"
          where "<xx>" is the index of the new chapter.
    @note it is allowed to call this method at any time to signal a time discontinuity or start a new group
          of recordings
    @note the newly created chapter becomes the current chapter and the RECORDER_CHAPTER_XXXX parameters
          are updated accordingly
    @note the chapter name must comply with the regular expression [A-Za-z_][-A-Za-z0-9_ ]*
    @note the chapter name length cannot exceed 255 characters
    @note the chapter name must be unique within the container
    @note the chapter name cannot be like a default chapter name (i.e. Chapter[0-9]+) unless it matches
          the default name it would get automatically
    @note when a chapter is created, a synchronized pair of system/UTC timestamps is captured and stored
          in the storage as RECORDER_PARAMETER_CHAPTER_TIMESTAMP and RECORDER_PARAMETER_CHAPTER_UTC;
          the system time timestamp is expressed in nanoseconds since the computer booted;
    @note when reading back from a container, the pair of synchronized timestamps of the corresponding chapter
          is used internally to compute the value of the (non-zero) utc field of a RECORDER_BUFFER_INFO record
          from the value of the (system) timestamp field
 **/
RECORDER_API RecorderStartChapter(RECORDER_HANDLE handle, const char *name, const char *info);

/** @cond */

/* typedefs for dynamic loading */
#define RECORDER_API_PTR(fn) typedef RECORDER_STATUS(EGRABBER_RECORDER_API_CALLTYPE *fn)

RECORDER_API_PTR(FnRecorderInitLib)();
RECORDER_API_PTR(FnRecorderCloseLib)();
RECORDER_API_PTR(FnRecorderOpen)(const char *path, RECORDER_OPEN_MODE mode, RECORDER_HANDLE *handle, uint32_t *fileVersion);
RECORDER_API_PTR(FnRecorderClose)(RECORDER_HANDLE handle, RECORDER_CLOSE_MODE mode);
RECORDER_API_PTR(FnRecorderSetParameterString)(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, const char *value);
RECORDER_API_PTR(FnRecorderGetParameterString)(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, char *value, size_t *size);
RECORDER_API_PTR(FnRecorderSetParameterInteger)(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, int64_t value);
RECORDER_API_PTR(FnRecorderGetParameterInteger)(RECORDER_HANDLE handle, RECORDER_PARAMETER parameter, int64_t *value);
RECORDER_API_PTR(FnRecorderRead)(RECORDER_HANDLE handle, RECORDER_BUFFER_INFO *info, void *buffer, size_t *bufferSize, void *reserved);
RECORDER_API_PTR(FnRecorderWrite)(RECORDER_HANDLE handle, const RECORDER_BUFFER_INFO *info, const void *buffer, void* reserved1, void* reserved2, void* reserved3);
RECORDER_API_PTR(FnRecorderExport)(RECORDER_HANDLE handle, const char *path, size_t *count,
                                   uint32_t exportPixelFormat, unsigned int reserved,
                                   RECORDER_PROGRESS_CALLBACK progressCallback, void *progressContext);
RECORDER_API_PTR(FnRecorderStartChapter)(RECORDER_HANDLE handle, const char *name, const char *info);

/** @endcond */

/** @} */

#ifdef __cplusplus
} // namespace EGrabberRecorder
} // namespace Euresys
} // extern "C"
#endif

#endif
