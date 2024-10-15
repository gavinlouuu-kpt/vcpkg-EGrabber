/* Copyright Euresys 2021 */

#ifndef EGENTL_TYPES_HEADER_FILE
#define EGENTL_TYPES_HEADER_FILE

/** @file
    Defines data types related to Euresys::EGenTL
 **/

namespace EURESYS_NAMESPACE {

// --------------------------------------------------------------------------
// EGenTL structures
// --------------------------------------------------------------------------

/** structure of useful buffer information
 */
struct BufferInfo {
    void * base;
    size_t size;
    size_t linePitch;
    size_t width;
    size_t deliveredHeight;
    std::string pixelFormat;
    unsigned int bitsPerPixel;
};

/** special type to query info command details without getting the data
 */
struct InfoCommandInfo {
    int dataType;
    size_t dataSize;
};

} // EURESYS_NAMESPACE

#endif
