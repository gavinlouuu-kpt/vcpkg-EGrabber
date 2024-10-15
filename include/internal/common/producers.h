#ifndef EURESYS_PRODUCERS_HEADER_FILE
#define EURESYS_PRODUCERS_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

    enum ProducerType { COAXLINK_PRODUCER, GIGELINK_PRODUCER, GRABLINK_PRODUCER, PLAYLINK_PRODUCER, PATTL_PRODUCER};

    template<enum ProducerType> const char *getEuresysCtiEnvVariable();
    template<> inline const char *getEuresysCtiEnvVariable<COAXLINK_PRODUCER>() {
        return "EURESYS_COAXLINK_GENTL64_CTI";
    }
    template<> inline const char *getEuresysCtiEnvVariable<GIGELINK_PRODUCER>() {
        return "EURESYS_GIGELINK_GENTL64_CTI";
    }
    template<> inline const char *getEuresysCtiEnvVariable<GRABLINK_PRODUCER>() {
        return "EURESYS_GRABLINK_GENTL64_CTI";
    }
    template<> inline const char *getEuresysCtiEnvVariable<PLAYLINK_PRODUCER>() {
        return "EURESYS_PLAYLINK_GENTL64_CTI";
    }
    template<> inline const char *getEuresysCtiEnvVariable<PATTL_PRODUCER>() {
        return "EURESYS_PATTL_GENTL64_CTI";
    }

    template<enum ProducerType> const char *getProducerName();
    template<> inline const char *getProducerName<COAXLINK_PRODUCER>() {
        return "coaxlink.cti";
    }
    template<> inline const char *getProducerName<GIGELINK_PRODUCER>() {
        return "gigelink.cti";
    }
    template<> inline const char *getProducerName<GRABLINK_PRODUCER>() {
        return "grablink.cti";
    }
    template<> inline const char *getProducerName<PLAYLINK_PRODUCER>() {
        return "playlink.cti";
    }
    template<> inline const char *getProducerName<PATTL_PRODUCER>() {
        return "pattl.cti";
    }
} // end of Internal
} // end of EURESYS_NAMESPACE
#endif
