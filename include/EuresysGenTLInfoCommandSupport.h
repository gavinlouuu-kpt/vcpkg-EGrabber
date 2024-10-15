/* Copyright Euresys 2023 */

#ifndef EURESYS_INFO_COMMAND_SUPPORT_HEADER_FILE
#define EURESYS_INFO_COMMAND_SUPPORT_HEADER_FILE

static inline bool8_t IsTlInfoCommandImplementedInCoaxlink(int32_t cmd) {
    switch(cmd) {
        /* TL_INFO commands implemented in Coaxlink */
        case TL_INFO_ID:
        case TL_INFO_VENDOR:
        case TL_INFO_MODEL:
        case TL_INFO_VERSION:
        case TL_INFO_TLTYPE:
        case TL_INFO_NAME:
        case TL_INFO_PATHNAME:
        case TL_INFO_DISPLAYNAME:
        case TL_INFO_CHAR_ENCODING:
        case TL_INFO_GENTL_VER_MAJOR:
        case TL_INFO_GENTL_VER_MINOR:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsInterfaceInfoCommandImplementedInCoaxlink(int32_t cmd) {
    switch(cmd) {
        /* INTERFACE_INFO commands implemented in Coaxlink */
        case INTERFACE_INFO_ID:
        case INTERFACE_INFO_DISPLAYNAME:
        case INTERFACE_INFO_TLTYPE:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsDeviceInfoCommandImplementedInCoaxlink(int32_t cmd) {
    switch(cmd) {
        /* DEVICE_INFO commands implemented in Coaxlink */
        case DEVICE_INFO_ID:
        case DEVICE_INFO_VENDOR:
        case DEVICE_INFO_MODEL:
        case DEVICE_INFO_TLTYPE:
        case DEVICE_INFO_DISPLAYNAME:
        case DEVICE_INFO_ACCESS_STATUS:
        case DEVICE_INFO_USER_DEFINED_NAME:
        case DEVICE_INFO_SERIAL_NUMBER:
        case DEVICE_INFO_VERSION:
        case DEVICE_INFO_TIMESTAMP_FREQUENCY:
        case DEVICE_INFO_CUSTOM_DEVICE_DESCRIPTION:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsStreamInfoCommandImplementedInCoaxlink(int32_t cmd) {
    switch(cmd) {
        /* STREAM_INFO commands implemented in Coaxlink */
        case STREAM_INFO_ID:
        case STREAM_INFO_NUM_DELIVERED:
        case STREAM_INFO_NUM_UNDERRUN:
        case STREAM_INFO_NUM_ANNOUNCED:
        case STREAM_INFO_NUM_QUEUED:
        case STREAM_INFO_NUM_AWAIT_DELIVERY:
        case STREAM_INFO_NUM_STARTED:
        case STREAM_INFO_PAYLOAD_SIZE:
        case STREAM_INFO_IS_GRABBING:
        case STREAM_INFO_DEFINES_PAYLOADSIZE:
        case STREAM_INFO_TLTYPE:
        case STREAM_INFO_NUM_CHUNKS_MAX:
        case STREAM_INFO_BUF_ANNOUNCE_MIN:
        case STREAM_INFO_BUF_ALIGNMENT:
        case STREAM_INFO_CUSTOM_STREAM_DESCRIPTION:
        case STREAM_INFO_CUSTOM_SHOULD_REANNOUNCE_BUFFERS:
        case STREAM_INFO_CUSTOM_SHOULD_REALLOC_BUFFERS:
            return 1;
        /* STREAM_INFO commands not implemented Coaxlink */
        case STREAM_INFO_FLOW_TABLE:
        case STREAM_INFO_GENDC_PREFETCH_DESCRIPTOR:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsBufferInfoCommandImplementedInCoaxlink(int32_t cmd) {
    switch(cmd) {
        /* BUFFER_INFO commands implemented in Coaxlink */
        case BUFFER_INFO_BASE:
        case BUFFER_INFO_SIZE:
        case BUFFER_INFO_USER_PTR:
        case BUFFER_INFO_TIMESTAMP:
        case BUFFER_INFO_NEW_DATA:
        case BUFFER_INFO_IS_QUEUED:
        case BUFFER_INFO_IS_ACQUIRING:
        case BUFFER_INFO_IS_INCOMPLETE:
        case BUFFER_INFO_TLTYPE:
        case BUFFER_INFO_SIZE_FILLED:
        case BUFFER_INFO_WIDTH:
        case BUFFER_INFO_HEIGHT:
        case BUFFER_INFO_XOFFSET:
        case BUFFER_INFO_YOFFSET:
        case BUFFER_INFO_XPADDING:
        case BUFFER_INFO_YPADDING:
        case BUFFER_INFO_FRAMEID:
        case BUFFER_INFO_IMAGEPRESENT:
        case BUFFER_INFO_IMAGEOFFSET:
        case BUFFER_INFO_PAYLOADTYPE:
        case BUFFER_INFO_PIXELFORMAT:
        case BUFFER_INFO_PIXELFORMAT_NAMESPACE:
        case BUFFER_INFO_DELIVERED_IMAGEHEIGHT:
        case BUFFER_INFO_PIXEL_ENDIANNESS:
        case BUFFER_INFO_DATA_SIZE:
        case BUFFER_INFO_TIMESTAMP_NS:
        case BUFFER_INFO_CONTAINS_CHUNKDATA:
        case BUFFER_INFO_CUSTOM_START_OF_SCAN:
        case BUFFER_INFO_CUSTOM_END_OF_SCAN:
        case BUFFER_INFO_CUSTOM_EVENT_TIMESTAMP:
        case BUFFER_INFO_CUSTOM_CXP_STREAMID:
        case BUFFER_INFO_CUSTOM_CXP_TAPG:
        case BUFFER_INFO_CUSTOM_CXP_FLAGS:
        case BUFFER_INFO_CUSTOM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_WIDTH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_HEIGHT:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_ARRANGEMENT:
        case BUFFER_INFO_CUSTOM_CUSTOM_LOGIC_STATUS:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_OFFSET:
        case BUFFER_INFO_CUSTOM_STREAM_BLOCK_HEIGHT:
        case BUFFER_INFO_CUSTOM_LLE_LINES_PER_IMAGE:
        case BUFFER_INFO_CUSTOM_ALIGNMENT:
        case BUFFER_INFO_CUSTOM_PART_SIZE:
        case BUFFER_INFO_CUSTOM_NUM_PARTS:
        case BUFFER_INFO_CUSTOM_NUM_DELIVERED_PARTS:
        case BUFFER_INFO_CUSTOM_PART_TIMESTAMPS:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_0:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_1:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_2:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_3:
        case BUFFER_INFO_CUSTOM_HAS_BUFFER_METADATA:
        case BUFFER_INFO_CUSTOM_HAS_LINE_METADATA:
        case BUFFER_INFO_CUSTOM_LINE_METADATA_BASE:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_0:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_1:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_2:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_3:
            return 1;
        /* BUFFER_INFO commands not implemented Coaxlink */
        case BUFFER_INFO_DELIVERED_CHUNKPAYLOADSIZE:
        case BUFFER_INFO_CHUNKLAYOUTID:
        case BUFFER_INFO_FILENAME:
        case BUFFER_INFO_DATA_LARGER_THAN_BUFFER:
        case BUFFER_INFO_IS_COMPOSITE:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsTlInfoCommandImplementedInGrablink(int32_t cmd) {
    switch(cmd) {
        /* TL_INFO commands implemented in Grablink */
        case TL_INFO_ID:
        case TL_INFO_VENDOR:
        case TL_INFO_MODEL:
        case TL_INFO_VERSION:
        case TL_INFO_TLTYPE:
        case TL_INFO_NAME:
        case TL_INFO_PATHNAME:
        case TL_INFO_DISPLAYNAME:
        case TL_INFO_CHAR_ENCODING:
        case TL_INFO_GENTL_VER_MAJOR:
        case TL_INFO_GENTL_VER_MINOR:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsInterfaceInfoCommandImplementedInGrablink(int32_t cmd) {
    switch(cmd) {
        /* INTERFACE_INFO commands implemented in Grablink */
        case INTERFACE_INFO_ID:
        case INTERFACE_INFO_DISPLAYNAME:
        case INTERFACE_INFO_TLTYPE:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsDeviceInfoCommandImplementedInGrablink(int32_t cmd) {
    switch(cmd) {
        /* DEVICE_INFO commands implemented in Grablink */
        case DEVICE_INFO_ID:
        case DEVICE_INFO_VENDOR:
        case DEVICE_INFO_MODEL:
        case DEVICE_INFO_TLTYPE:
        case DEVICE_INFO_DISPLAYNAME:
        case DEVICE_INFO_ACCESS_STATUS:
        case DEVICE_INFO_USER_DEFINED_NAME:
        case DEVICE_INFO_SERIAL_NUMBER:
        case DEVICE_INFO_VERSION:
        case DEVICE_INFO_TIMESTAMP_FREQUENCY:
        case DEVICE_INFO_CUSTOM_DEVICE_DESCRIPTION:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsStreamInfoCommandImplementedInGrablink(int32_t cmd) {
    switch(cmd) {
        /* STREAM_INFO commands implemented in Grablink */
        case STREAM_INFO_ID:
        case STREAM_INFO_NUM_DELIVERED:
        case STREAM_INFO_NUM_UNDERRUN:
        case STREAM_INFO_NUM_ANNOUNCED:
        case STREAM_INFO_NUM_QUEUED:
        case STREAM_INFO_NUM_AWAIT_DELIVERY:
        case STREAM_INFO_NUM_STARTED:
        case STREAM_INFO_PAYLOAD_SIZE:
        case STREAM_INFO_IS_GRABBING:
        case STREAM_INFO_DEFINES_PAYLOADSIZE:
        case STREAM_INFO_TLTYPE:
        case STREAM_INFO_NUM_CHUNKS_MAX:
        case STREAM_INFO_BUF_ANNOUNCE_MIN:
        case STREAM_INFO_BUF_ALIGNMENT:
        case STREAM_INFO_CUSTOM_STREAM_DESCRIPTION:
        case STREAM_INFO_CUSTOM_SHOULD_REANNOUNCE_BUFFERS:
        case STREAM_INFO_CUSTOM_SHOULD_REALLOC_BUFFERS:
            return 1;
        /* STREAM_INFO commands not implemented Grablink */
        case STREAM_INFO_FLOW_TABLE:
        case STREAM_INFO_GENDC_PREFETCH_DESCRIPTOR:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsBufferInfoCommandImplementedInGrablink(int32_t cmd) {
    switch(cmd) {
        /* BUFFER_INFO commands implemented in Grablink */
        case BUFFER_INFO_BASE:
        case BUFFER_INFO_SIZE:
        case BUFFER_INFO_USER_PTR:
        case BUFFER_INFO_TIMESTAMP:
        case BUFFER_INFO_NEW_DATA:
        case BUFFER_INFO_IS_QUEUED:
        case BUFFER_INFO_IS_ACQUIRING:
        case BUFFER_INFO_IS_INCOMPLETE:
        case BUFFER_INFO_TLTYPE:
        case BUFFER_INFO_SIZE_FILLED:
        case BUFFER_INFO_WIDTH:
        case BUFFER_INFO_HEIGHT:
        case BUFFER_INFO_XOFFSET:
        case BUFFER_INFO_YOFFSET:
        case BUFFER_INFO_XPADDING:
        case BUFFER_INFO_YPADDING:
        case BUFFER_INFO_FRAMEID:
        case BUFFER_INFO_IMAGEPRESENT:
        case BUFFER_INFO_IMAGEOFFSET:
        case BUFFER_INFO_PAYLOADTYPE:
        case BUFFER_INFO_PIXELFORMAT:
        case BUFFER_INFO_PIXELFORMAT_NAMESPACE:
        case BUFFER_INFO_DELIVERED_IMAGEHEIGHT:
        case BUFFER_INFO_PIXEL_ENDIANNESS:
        case BUFFER_INFO_DATA_SIZE:
        case BUFFER_INFO_TIMESTAMP_NS:
        case BUFFER_INFO_CONTAINS_CHUNKDATA:
        case BUFFER_INFO_CUSTOM_START_OF_SCAN:
        case BUFFER_INFO_CUSTOM_END_OF_SCAN:
        case BUFFER_INFO_CUSTOM_EVENT_TIMESTAMP:
        case BUFFER_INFO_CUSTOM_CXP_STREAMID:
        case BUFFER_INFO_CUSTOM_CXP_TAPG:
        case BUFFER_INFO_CUSTOM_CXP_FLAGS:
        case BUFFER_INFO_CUSTOM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_WIDTH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_HEIGHT:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_ARRANGEMENT:
        case BUFFER_INFO_CUSTOM_CUSTOM_LOGIC_STATUS:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_OFFSET:
        case BUFFER_INFO_CUSTOM_STREAM_BLOCK_HEIGHT:
        case BUFFER_INFO_CUSTOM_LLE_LINES_PER_IMAGE:
        case BUFFER_INFO_CUSTOM_ALIGNMENT:
        case BUFFER_INFO_CUSTOM_PART_SIZE:
        case BUFFER_INFO_CUSTOM_NUM_PARTS:
        case BUFFER_INFO_CUSTOM_NUM_DELIVERED_PARTS:
        case BUFFER_INFO_CUSTOM_PART_TIMESTAMPS:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_0:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_1:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_2:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_3:
        case BUFFER_INFO_CUSTOM_HAS_BUFFER_METADATA:
        case BUFFER_INFO_CUSTOM_HAS_LINE_METADATA:
        case BUFFER_INFO_CUSTOM_LINE_METADATA_BASE:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_0:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_1:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_2:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_3:
            return 1;
        /* BUFFER_INFO commands not implemented Grablink */
        case BUFFER_INFO_DELIVERED_CHUNKPAYLOADSIZE:
        case BUFFER_INFO_CHUNKLAYOUTID:
        case BUFFER_INFO_FILENAME:
        case BUFFER_INFO_DATA_LARGER_THAN_BUFFER:
        case BUFFER_INFO_IS_COMPOSITE:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsTlInfoCommandImplementedInGigelink(int32_t cmd) {
    switch(cmd) {
        /* TL_INFO commands implemented in Gigelink */
        case TL_INFO_ID:
        case TL_INFO_VENDOR:
        case TL_INFO_MODEL:
        case TL_INFO_VERSION:
        case TL_INFO_TLTYPE:
        case TL_INFO_NAME:
        case TL_INFO_PATHNAME:
        case TL_INFO_DISPLAYNAME:
        case TL_INFO_CHAR_ENCODING:
        case TL_INFO_GENTL_VER_MAJOR:
        case TL_INFO_GENTL_VER_MINOR:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsInterfaceInfoCommandImplementedInGigelink(int32_t cmd) {
    switch(cmd) {
        /* INTERFACE_INFO commands implemented in Gigelink */
        case INTERFACE_INFO_ID:
        case INTERFACE_INFO_DISPLAYNAME:
        case INTERFACE_INFO_TLTYPE:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsDeviceInfoCommandImplementedInGigelink(int32_t cmd) {
    switch(cmd) {
        /* DEVICE_INFO commands implemented in Gigelink */
        case DEVICE_INFO_ID:
        case DEVICE_INFO_VENDOR:
        case DEVICE_INFO_MODEL:
        case DEVICE_INFO_TLTYPE:
        case DEVICE_INFO_DISPLAYNAME:
        case DEVICE_INFO_ACCESS_STATUS:
        case DEVICE_INFO_USER_DEFINED_NAME:
        case DEVICE_INFO_SERIAL_NUMBER:
        case DEVICE_INFO_VERSION:
        case DEVICE_INFO_TIMESTAMP_FREQUENCY:
        case DEVICE_INFO_CUSTOM_DEVICE_DESCRIPTION:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsStreamInfoCommandImplementedInGigelink(int32_t cmd) {
    switch(cmd) {
        /* STREAM_INFO commands implemented in Gigelink */
        case STREAM_INFO_ID:
        case STREAM_INFO_NUM_DELIVERED:
        case STREAM_INFO_NUM_UNDERRUN:
        case STREAM_INFO_NUM_ANNOUNCED:
        case STREAM_INFO_NUM_QUEUED:
        case STREAM_INFO_NUM_AWAIT_DELIVERY:
        case STREAM_INFO_NUM_STARTED:
        case STREAM_INFO_PAYLOAD_SIZE:
        case STREAM_INFO_IS_GRABBING:
        case STREAM_INFO_DEFINES_PAYLOADSIZE:
        case STREAM_INFO_TLTYPE:
        case STREAM_INFO_NUM_CHUNKS_MAX:
        case STREAM_INFO_BUF_ANNOUNCE_MIN:
        case STREAM_INFO_BUF_ALIGNMENT:
        case STREAM_INFO_CUSTOM_STREAM_DESCRIPTION:
        case STREAM_INFO_CUSTOM_SHOULD_REANNOUNCE_BUFFERS:
        case STREAM_INFO_CUSTOM_SHOULD_REALLOC_BUFFERS:
            return 1;
        /* STREAM_INFO commands not implemented Gigelink */
        case STREAM_INFO_FLOW_TABLE:
        case STREAM_INFO_GENDC_PREFETCH_DESCRIPTOR:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsBufferInfoCommandImplementedInGigelink(int32_t cmd) {
    switch(cmd) {
        /* BUFFER_INFO commands implemented in Gigelink */
        case BUFFER_INFO_BASE:
        case BUFFER_INFO_SIZE:
        case BUFFER_INFO_USER_PTR:
        case BUFFER_INFO_TIMESTAMP:
        case BUFFER_INFO_NEW_DATA:
        case BUFFER_INFO_IS_QUEUED:
        case BUFFER_INFO_IS_ACQUIRING:
        case BUFFER_INFO_IS_INCOMPLETE:
        case BUFFER_INFO_TLTYPE:
        case BUFFER_INFO_SIZE_FILLED:
        case BUFFER_INFO_WIDTH:
        case BUFFER_INFO_HEIGHT:
        case BUFFER_INFO_XOFFSET:
        case BUFFER_INFO_YOFFSET:
        case BUFFER_INFO_XPADDING:
        case BUFFER_INFO_YPADDING:
        case BUFFER_INFO_FRAMEID:
        case BUFFER_INFO_IMAGEPRESENT:
        case BUFFER_INFO_IMAGEOFFSET:
        case BUFFER_INFO_PAYLOADTYPE:
        case BUFFER_INFO_PIXELFORMAT:
        case BUFFER_INFO_PIXELFORMAT_NAMESPACE:
        case BUFFER_INFO_DELIVERED_IMAGEHEIGHT:
        case BUFFER_INFO_PIXEL_ENDIANNESS:
        case BUFFER_INFO_DATA_SIZE:
        case BUFFER_INFO_TIMESTAMP_NS:
        case BUFFER_INFO_CONTAINS_CHUNKDATA:
        case BUFFER_INFO_CUSTOM_START_OF_SCAN:
        case BUFFER_INFO_CUSTOM_END_OF_SCAN:
        case BUFFER_INFO_CUSTOM_EVENT_TIMESTAMP:
        case BUFFER_INFO_CUSTOM_CXP_STREAMID:
        case BUFFER_INFO_CUSTOM_CXP_TAPG:
        case BUFFER_INFO_CUSTOM_CXP_FLAGS:
        case BUFFER_INFO_CUSTOM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_WIDTH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_HEIGHT:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_ARRANGEMENT:
        case BUFFER_INFO_CUSTOM_CUSTOM_LOGIC_STATUS:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_OFFSET:
        case BUFFER_INFO_CUSTOM_STREAM_BLOCK_HEIGHT:
        case BUFFER_INFO_CUSTOM_LLE_LINES_PER_IMAGE:
        case BUFFER_INFO_CUSTOM_ALIGNMENT:
        case BUFFER_INFO_CUSTOM_PART_SIZE:
        case BUFFER_INFO_CUSTOM_NUM_PARTS:
        case BUFFER_INFO_CUSTOM_NUM_DELIVERED_PARTS:
        case BUFFER_INFO_CUSTOM_PART_TIMESTAMPS:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_0:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_1:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_2:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_3:
        case BUFFER_INFO_CUSTOM_HAS_BUFFER_METADATA:
        case BUFFER_INFO_CUSTOM_HAS_LINE_METADATA:
        case BUFFER_INFO_CUSTOM_LINE_METADATA_BASE:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_0:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_1:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_2:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_3:
            return 1;
        /* BUFFER_INFO commands not implemented Gigelink */
        case BUFFER_INFO_DELIVERED_CHUNKPAYLOADSIZE:
        case BUFFER_INFO_CHUNKLAYOUTID:
        case BUFFER_INFO_FILENAME:
        case BUFFER_INFO_DATA_LARGER_THAN_BUFFER:
        case BUFFER_INFO_IS_COMPOSITE:
            return 0;
        default:
            return 0;
    }
}

static inline bool8_t IsTlInfoCommandImplementedInPlaylink(int32_t cmd) {
    switch(cmd) {
        /* TL_INFO commands implemented in Playlink */
        case TL_INFO_ID:
        case TL_INFO_VENDOR:
        case TL_INFO_MODEL:
        case TL_INFO_VERSION:
        case TL_INFO_TLTYPE:
        case TL_INFO_NAME:
        case TL_INFO_PATHNAME:
        case TL_INFO_DISPLAYNAME:
        case TL_INFO_CHAR_ENCODING:
        case TL_INFO_GENTL_VER_MAJOR:
        case TL_INFO_GENTL_VER_MINOR:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsInterfaceInfoCommandImplementedInPlaylink(int32_t cmd) {
    switch(cmd) {
        /* INTERFACE_INFO commands implemented in Playlink */
        case INTERFACE_INFO_ID:
        case INTERFACE_INFO_DISPLAYNAME:
        case INTERFACE_INFO_TLTYPE:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsDeviceInfoCommandImplementedInPlaylink(int32_t cmd) {
    switch(cmd) {
        /* DEVICE_INFO commands implemented in Playlink */
        case DEVICE_INFO_ID:
        case DEVICE_INFO_VENDOR:
        case DEVICE_INFO_MODEL:
        case DEVICE_INFO_TLTYPE:
        case DEVICE_INFO_DISPLAYNAME:
        case DEVICE_INFO_ACCESS_STATUS:
        case DEVICE_INFO_USER_DEFINED_NAME:
        case DEVICE_INFO_SERIAL_NUMBER:
        case DEVICE_INFO_VERSION:
        case DEVICE_INFO_TIMESTAMP_FREQUENCY:
        case DEVICE_INFO_CUSTOM_DEVICE_DESCRIPTION:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsStreamInfoCommandImplementedInPlaylink(int32_t cmd) {
    switch(cmd) {
        /* STREAM_INFO commands implemented in Playlink */
        case STREAM_INFO_ID:
        case STREAM_INFO_NUM_DELIVERED:
        case STREAM_INFO_NUM_UNDERRUN:
        case STREAM_INFO_NUM_ANNOUNCED:
        case STREAM_INFO_NUM_QUEUED:
        case STREAM_INFO_NUM_AWAIT_DELIVERY:
        case STREAM_INFO_NUM_STARTED:
        case STREAM_INFO_PAYLOAD_SIZE:
        case STREAM_INFO_IS_GRABBING:
        case STREAM_INFO_DEFINES_PAYLOADSIZE:
        case STREAM_INFO_TLTYPE:
        case STREAM_INFO_NUM_CHUNKS_MAX:
        case STREAM_INFO_BUF_ANNOUNCE_MIN:
        case STREAM_INFO_BUF_ALIGNMENT:
        case STREAM_INFO_FLOW_TABLE:
        case STREAM_INFO_GENDC_PREFETCH_DESCRIPTOR:
        case STREAM_INFO_CUSTOM_STREAM_DESCRIPTION:
        case STREAM_INFO_CUSTOM_SHOULD_REANNOUNCE_BUFFERS:
        case STREAM_INFO_CUSTOM_SHOULD_REALLOC_BUFFERS:
            return 1;
        default:
            return 0;
    }
}

static inline bool8_t IsBufferInfoCommandImplementedInPlaylink(int32_t cmd) {
    switch(cmd) {
        /* BUFFER_INFO commands implemented in Playlink */
        case BUFFER_INFO_BASE:
        case BUFFER_INFO_SIZE:
        case BUFFER_INFO_USER_PTR:
        case BUFFER_INFO_TIMESTAMP:
        case BUFFER_INFO_NEW_DATA:
        case BUFFER_INFO_IS_QUEUED:
        case BUFFER_INFO_IS_ACQUIRING:
        case BUFFER_INFO_IS_INCOMPLETE:
        case BUFFER_INFO_TLTYPE:
        case BUFFER_INFO_SIZE_FILLED:
        case BUFFER_INFO_WIDTH:
        case BUFFER_INFO_HEIGHT:
        case BUFFER_INFO_XOFFSET:
        case BUFFER_INFO_YOFFSET:
        case BUFFER_INFO_XPADDING:
        case BUFFER_INFO_YPADDING:
        case BUFFER_INFO_FRAMEID:
        case BUFFER_INFO_IMAGEPRESENT:
        case BUFFER_INFO_IMAGEOFFSET:
        case BUFFER_INFO_PAYLOADTYPE:
        case BUFFER_INFO_PIXELFORMAT:
        case BUFFER_INFO_PIXELFORMAT_NAMESPACE:
        case BUFFER_INFO_DELIVERED_IMAGEHEIGHT:
        case BUFFER_INFO_PIXEL_ENDIANNESS:
        case BUFFER_INFO_DATA_SIZE:
        case BUFFER_INFO_TIMESTAMP_NS:
        case BUFFER_INFO_CONTAINS_CHUNKDATA:
        case BUFFER_INFO_IS_COMPOSITE:
        case BUFFER_INFO_CUSTOM_START_OF_SCAN:
        case BUFFER_INFO_CUSTOM_END_OF_SCAN:
        case BUFFER_INFO_CUSTOM_EVENT_TIMESTAMP:
        case BUFFER_INFO_CUSTOM_CXP_STREAMID:
        case BUFFER_INFO_CUSTOM_CXP_TAPG:
        case BUFFER_INFO_CUSTOM_CXP_FLAGS:
        case BUFFER_INFO_CUSTOM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_WIDTH:
        case BUFFER_INFO_CUSTOM_STREAM_LINE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_HEIGHT:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_PITCH:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_ARRANGEMENT:
        case BUFFER_INFO_CUSTOM_CUSTOM_LOGIC_STATUS:
        case BUFFER_INFO_CUSTOM_STREAM_STRIPE_OFFSET:
        case BUFFER_INFO_CUSTOM_STREAM_BLOCK_HEIGHT:
        case BUFFER_INFO_CUSTOM_LLE_LINES_PER_IMAGE:
        case BUFFER_INFO_CUSTOM_ALIGNMENT:
        case BUFFER_INFO_CUSTOM_PART_SIZE:
        case BUFFER_INFO_CUSTOM_NUM_PARTS:
        case BUFFER_INFO_CUSTOM_NUM_DELIVERED_PARTS:
        case BUFFER_INFO_CUSTOM_PART_TIMESTAMPS:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_0:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_1:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_2:
        case BUFFER_INFO_CUSTOM_BUFFER_METADATA_3:
        case BUFFER_INFO_CUSTOM_HAS_BUFFER_METADATA:
        case BUFFER_INFO_CUSTOM_HAS_LINE_METADATA:
        case BUFFER_INFO_CUSTOM_LINE_METADATA_BASE:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_0:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_1:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_2:
        case BUFFER_INFO_CUSTOM_METADATA_CONTENT_3:
            return 1;
        /* BUFFER_INFO commands not implemented Playlink */
        case BUFFER_INFO_DELIVERED_CHUNKPAYLOADSIZE:
        case BUFFER_INFO_CHUNKLAYOUTID:
        case BUFFER_INFO_FILENAME:
        case BUFFER_INFO_DATA_LARGER_THAN_BUFFER:
            return 0;
        default:
            return 0;
    }
}

#endif /* EURESYS_INFO_COMMAND_SUPPORT_HEADER_FILE */
