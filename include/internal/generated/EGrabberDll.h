/* Copyright Euresys 2021*/

#ifndef EURESYS_EGRABBER_DLL_HEADER_FILE
#define EURESYS_EGRABBER_DLL_HEADER_FILE

#include "../EuresysDynamicLibrary.h"
#include "cEGrabber.generated.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

#define INIT_EGRABBER_FN(dll, fn) fn(reinterpret_cast<ce::P##fn>(dll.getSymbol(#fn)))
#define DECL_EGRABBER_FN(fn) ce::P##fn fn

class EGrabberDllBase {
    protected:
        EGrabberDllBase(const std::string &path)
        : dll(path)
        {}
        virtual ~EGrabberDllBase()
        {}
        DynamicLibrary dll;
};

class EGrabberDllClassEGenTL: virtual public EGrabberDllBase {
    protected:
        EGrabberDllClassEGenTL(const std::string &path)
        : EGrabberDllBase(path)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFccpb8)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_create)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFcpb8)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFcp)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFb8ccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_createFb8)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAsFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAi8FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAi16FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAi32FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAi64FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAu8FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAu16FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAu32FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAu64FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAdFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAfFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAu8pFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoASsFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAvptrFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoASvcFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoASv_std_stringFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAb8FTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoAcptrFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetInfoA_CINFOFTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcReadPortFPHu64Svc)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcReadPortStringFPHu64s)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcReadPortFPHu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcWritePortFPHu64Svc)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcReadPortDataFPHu64vps)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcWritePortDataFPHu64vps)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLFPH)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAsFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAi8FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAi16FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAi32FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAi64FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAu8FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAu16FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAu32FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAu64FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAdFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAfFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAu8pFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoASsFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAvptrFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoASvcFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoASv_std_stringFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAb8FPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoAcptrFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortInfoA_CINFOFPHPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcRegisterEventFEHET)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcUnregisterEventFEHET)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataFEHvpsu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventsGetDataFSv_EEGDEu64p)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAsFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAi8FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAi16FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAi32FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAi64FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAu8FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAu16FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAu32FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAu64FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAdFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAfFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAu8pFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoASsFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAvptrFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoASvcFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoASv_std_stringFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAb8FEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoAcptrFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetDataInfoA_CINFOFEHvpsEDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAsFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAi8FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAi16FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAi32FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAi64FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAu8FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAu16FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAu32FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAu64FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAdFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAfFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAu8pFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoASsFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAvptrFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoASvcFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoASv_std_stringFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAb8FEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoAcptrFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventGetInfoA_CINFOFEHEIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventFlushFEH)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventKillFEH)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlOpen)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlCloseFTH)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAsFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAi8FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAi16FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAi32FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAi64FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAu8FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAu16FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAu32FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAu64FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAdFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAfFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAu8pFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoASsFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAvptrFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoASvcFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoASv_std_stringFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAb8FTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoAcptrFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInfoA_CINFOFTHTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetNumInterfacesFTH)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceIDFTHu32)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAsFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAi8FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAi16FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAi32FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAi64FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAu8FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAu16FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAu32FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAu64FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAdFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAfFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAu8pFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoASsFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAvptrFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoASvcFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoASv_std_stringFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAb8FTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoAcptrFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlGetInterfaceInfoA_CINFOFTHccpTIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlOpenInterfaceFTHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlUpdateInterfaceListFTHu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_tlUpdateInterfaceListFTH)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifCloseFIH)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAsFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAi8FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAi16FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAi32FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAi64FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAu8FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAu16FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAu32FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAu64FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAdFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAfFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAu8pFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoASsFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAvptrFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoASvcFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoASv_std_stringFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAb8FIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoAcptrFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetInfoA_CINFOFIHIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetNumDevicesFIH)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceIDFIHu32)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifUpdateDeviceListFIHu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifUpdateDeviceListFIH)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAsFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAi8FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAi16FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAi32FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAi64FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAu8FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAu16FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAu32FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAu64FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAdFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAfFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAu8pFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoASsFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAvptrFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoASvcFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoASv_std_stringFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAb8FIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoAcptrFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetDeviceInfoA_CINFOFIHccpIIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifOpenDeviceFIHccpDAF)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifOpenDeviceFIHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetPortFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetNumDataStreamsFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetDataStreamIDFDHu32)
        , INIT_EGRABBER_FN(dll, euEGenTL_devOpenDataStreamFDHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_devCloseFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAsFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAi8FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAi16FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAi32FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAi64FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAu8FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAu16FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAu32FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAu64FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAdFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAfFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAu8pFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoASsFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAvptrFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoASvcFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoASv_std_stringFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAb8FDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoAcptrFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetInfoA_CINFOFDHDIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceBufferFDHvpsvp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceBufferFDHvps)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAllocAndAnnounceBufferFDHsvp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAllocAndAnnounceBufferFDHs)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceBusBufferFDHu64svp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceBusBufferFDHu64s)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceDeviceBufferFDHvpsMTvp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAnnounceDeviceBufferFDHvpsMT)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsAllocAndAnnounceBuffersFDHsSv_BH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsFlushQueueFDHAQT)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsStartAcquisitionFDHASFu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsStartAcquisitionFDHASF)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsStartAcquisitionFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsStopAcquisitionFDHASF)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsStopAcquisitionFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsCloseFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAsFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAi8FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAi16FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAi32FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAi64FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAu8FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAu16FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAu32FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAu64FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAdFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAfFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAu8pFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoASsFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAvptrFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoASvcFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoASv_std_stringFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAb8FDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoAcptrFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetInfoA_CINFOFDHSIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferIDFDHu32)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsRevokeBufferFDHBHvppvpp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsRevokeBufferFDHBHvpp)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsRevokeBufferFDHBH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsRevokeBuffersFDHSv_BH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsQueueBufferFDHBH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsQueueBuffersFDHSv_BH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAsFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAi8FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAi16FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAi32FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAi64FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAu8FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAu16FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAu32FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAu64FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAdFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAfFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAu8pFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoASsFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAvptrFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoASvcFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoASv_std_stringFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAb8FDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoAcptrFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoA_CINFOFDHBHBIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferInfoFDHBH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetNumBufferPartsFDHBH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAsFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAi8FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAi16FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAi32FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAi64FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAu8FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAu16FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAu32FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAu64FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAdFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAfFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAu8pFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoASsFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAvptrFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoASvcFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoASv_std_stringFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAb8FDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoAcptrFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetBufferPartInfoA_CINFOFDHBHu32BPIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetNumPortURLsFPH)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAsFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAi8FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAi16FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAi32FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAi64FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAu8FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAu16FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAu32FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAu64FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAdFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAfFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAu8pFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoASsFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAvptrFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoASvcFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoASv_std_stringFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAb8FPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoAcptrFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcGetPortURLInfoA_CINFOFPHu32UIC)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcReadPortStackedFPHSv_PRSE)
        , INIT_EGRABBER_FN(dll, euEGenTL_gcWritePortStackedFPHSv_PRSE)
        , INIT_EGRABBER_FN(dll, euEGenTL_ifGetParentFIH)
        , INIT_EGRABBER_FN(dll, euEGenTL_devGetParentFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_dsGetParentFDH)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoFccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoFucucccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoWaveUpFucuc)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoWaveDownFucuc)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoWaveResetFucuc)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoWaveValueFucucu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_mementoWaveNoValueFucuc)
        , INIT_EGRABBER_FN(dll, euEGenTL_getTimestampUs)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiSetStringFPHccpccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetStringFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetStringDataFPHccpSvc)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetStringListFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiSetIntegerFPHccpi64)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetIntegerFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetIntegerWithDefaultFPHccpi64)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiSetFloatFPHccpd)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetFloatFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetFloatWithDefaultFPHccpd)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiSetRegisterFPHccpvps)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiGetRegisterFPHccpvps)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiExecuteCommandFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiAttachEventFPHu64vps)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiInvalidateFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiRunScriptFPHccpGENAPI_UI_SCRIPT_CONTEXT_p)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiRunScriptFPHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiRunScriptFSv_PHccpGENAPI_UI_SCRIPT_CONTEXT_p)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiRunScriptFSv_PHccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_genapiInterruptScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetPixelFormatValueFccpui)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetPixelFormatFu64)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetBytesPerPixelFccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetBitsPerPixelFccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageConvertF_ICI_p_ICO_pImageConvertROI_p)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageConvertF_ICI_p_ICO_p)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageSaveToDiskF_ICI_pccpi64_ISTDP_p)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageSaveToDiskF_ICI_pccpi64)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageSaveToDiskF_ICI_pccp)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetFImageIdsp)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageGetFImageId)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageReleaseFImageId)
        , INIT_EGRABBER_FN(dll, euEGenTL_imagePrepareBuffersFss)
        , INIT_EGRABBER_FN(dll, euEGenTL_imageTrimBuffers)
        , INIT_EGRABBER_FN(dll, euEGenTL_isShared)
        , INIT_EGRABBER_FN(dll, euEGenTL_eventKillQuietFEH)
        , INIT_EGRABBER_FN(dll, euEGenTL_lockUpdates)
        , INIT_EGRABBER_FN(dll, euEGenTL_unlockUpdates)
        , INIT_EGRABBER_FN(dll, euEGenTL_destroy)
        {}
        virtual ~EGrabberDllClassEGenTL()
        {}

    public:
        DECL_EGRABBER_FN(euEGenTL_createFccpb8);
        DECL_EGRABBER_FN(euEGenTL_createFccp);
        DECL_EGRABBER_FN(euEGenTL_create);
        DECL_EGRABBER_FN(euEGenTL_createFcpb8);
        DECL_EGRABBER_FN(euEGenTL_createFcp);
        DECL_EGRABBER_FN(euEGenTL_createFb8ccp);
        DECL_EGRABBER_FN(euEGenTL_createFb8);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAsFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAi8FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAi16FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAi32FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAi64FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAu8FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAu16FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAu32FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAu64FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAdFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAfFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAu8pFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoASsFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAvptrFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoASvcFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoASv_std_stringFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAb8FTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoAcptrFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetInfoA_CINFOFTIC);
        DECL_EGRABBER_FN(euEGenTL_gcReadPortFPHu64Svc);
        DECL_EGRABBER_FN(euEGenTL_gcReadPortStringFPHu64s);
        DECL_EGRABBER_FN(euEGenTL_gcReadPortFPHu64);
        DECL_EGRABBER_FN(euEGenTL_gcWritePortFPHu64Svc);
        DECL_EGRABBER_FN(euEGenTL_gcReadPortDataFPHu64vps);
        DECL_EGRABBER_FN(euEGenTL_gcWritePortDataFPHu64vps);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLFPH);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAsFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAi8FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAi16FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAi32FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAi64FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAu8FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAu16FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAu32FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAu64FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAdFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAfFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAu8pFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoASsFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAvptrFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoASvcFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoASv_std_stringFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAb8FPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoAcptrFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortInfoA_CINFOFPHPIC);
        DECL_EGRABBER_FN(euEGenTL_gcRegisterEventFEHET);
        DECL_EGRABBER_FN(euEGenTL_gcUnregisterEventFEHET);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataFEHvpsu64);
        DECL_EGRABBER_FN(euEGenTL_eventsGetDataFSv_EEGDEu64p);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAsFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAi8FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAi16FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAi32FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAi64FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAu8FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAu16FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAu32FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAu64FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAdFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAfFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAu8pFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoASsFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAvptrFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoASvcFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoASv_std_stringFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAb8FEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoAcptrFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetDataInfoA_CINFOFEHvpsEDIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAsFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAi8FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAi16FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAi32FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAi64FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAu8FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAu16FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAu32FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAu64FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAdFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAfFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAu8pFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoASsFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAvptrFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoASvcFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoASv_std_stringFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAb8FEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoAcptrFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventGetInfoA_CINFOFEHEIC);
        DECL_EGRABBER_FN(euEGenTL_eventFlushFEH);
        DECL_EGRABBER_FN(euEGenTL_eventKillFEH);
        DECL_EGRABBER_FN(euEGenTL_tlOpen);
        DECL_EGRABBER_FN(euEGenTL_tlCloseFTH);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAsFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAi8FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAi16FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAi32FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAi64FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAu8FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAu16FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAu32FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAu64FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAdFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAfFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAu8pFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoASsFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAvptrFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoASvcFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoASv_std_stringFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAb8FTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoAcptrFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInfoA_CINFOFTHTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetNumInterfacesFTH);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceIDFTHu32);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAsFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAi8FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAi16FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAi32FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAi64FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAu8FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAu16FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAu32FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAu64FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAdFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAfFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAu8pFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoASsFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAvptrFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoASvcFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoASv_std_stringFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAb8FTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoAcptrFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlGetInterfaceInfoA_CINFOFTHccpTIC);
        DECL_EGRABBER_FN(euEGenTL_tlOpenInterfaceFTHccp);
        DECL_EGRABBER_FN(euEGenTL_tlUpdateInterfaceListFTHu64);
        DECL_EGRABBER_FN(euEGenTL_tlUpdateInterfaceListFTH);
        DECL_EGRABBER_FN(euEGenTL_ifCloseFIH);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAsFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAi8FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAi16FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAi32FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAi64FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAu8FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAu16FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAu32FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAu64FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAdFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAfFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAu8pFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoASsFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAvptrFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoASvcFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoASv_std_stringFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAb8FIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoAcptrFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetInfoA_CINFOFIHIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetNumDevicesFIH);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceIDFIHu32);
        DECL_EGRABBER_FN(euEGenTL_ifUpdateDeviceListFIHu64);
        DECL_EGRABBER_FN(euEGenTL_ifUpdateDeviceListFIH);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAsFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAi8FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAi16FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAi32FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAi64FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAu8FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAu16FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAu32FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAu64FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAdFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAfFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAu8pFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoASsFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAvptrFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoASvcFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoASv_std_stringFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAb8FIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoAcptrFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifGetDeviceInfoA_CINFOFIHccpIIC);
        DECL_EGRABBER_FN(euEGenTL_ifOpenDeviceFIHccpDAF);
        DECL_EGRABBER_FN(euEGenTL_ifOpenDeviceFIHccp);
        DECL_EGRABBER_FN(euEGenTL_devGetPortFDH);
        DECL_EGRABBER_FN(euEGenTL_devGetNumDataStreamsFDH);
        DECL_EGRABBER_FN(euEGenTL_devGetDataStreamIDFDHu32);
        DECL_EGRABBER_FN(euEGenTL_devOpenDataStreamFDHccp);
        DECL_EGRABBER_FN(euEGenTL_devCloseFDH);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAsFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAi8FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAi16FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAi32FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAi64FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAu8FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAu16FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAu32FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAu64FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAdFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAfFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAu8pFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoASsFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAvptrFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoASvcFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoASv_std_stringFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAb8FDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoAcptrFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_devGetInfoA_CINFOFDHDIC);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceBufferFDHvpsvp);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceBufferFDHvps);
        DECL_EGRABBER_FN(euEGenTL_dsAllocAndAnnounceBufferFDHsvp);
        DECL_EGRABBER_FN(euEGenTL_dsAllocAndAnnounceBufferFDHs);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceBusBufferFDHu64svp);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceBusBufferFDHu64s);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceDeviceBufferFDHvpsMTvp);
        DECL_EGRABBER_FN(euEGenTL_dsAnnounceDeviceBufferFDHvpsMT);
        DECL_EGRABBER_FN(euEGenTL_dsAllocAndAnnounceBuffersFDHsSv_BH);
        DECL_EGRABBER_FN(euEGenTL_dsFlushQueueFDHAQT);
        DECL_EGRABBER_FN(euEGenTL_dsStartAcquisitionFDHASFu64);
        DECL_EGRABBER_FN(euEGenTL_dsStartAcquisitionFDHASF);
        DECL_EGRABBER_FN(euEGenTL_dsStartAcquisitionFDH);
        DECL_EGRABBER_FN(euEGenTL_dsStopAcquisitionFDHASF);
        DECL_EGRABBER_FN(euEGenTL_dsStopAcquisitionFDH);
        DECL_EGRABBER_FN(euEGenTL_dsCloseFDH);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAsFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAi8FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAi16FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAi32FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAi64FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAu8FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAu16FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAu32FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAu64FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAdFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAfFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAu8pFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoASsFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAvptrFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoASvcFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoASv_std_stringFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAb8FDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoAcptrFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetInfoA_CINFOFDHSIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferIDFDHu32);
        DECL_EGRABBER_FN(euEGenTL_dsRevokeBufferFDHBHvppvpp);
        DECL_EGRABBER_FN(euEGenTL_dsRevokeBufferFDHBHvpp);
        DECL_EGRABBER_FN(euEGenTL_dsRevokeBufferFDHBH);
        DECL_EGRABBER_FN(euEGenTL_dsRevokeBuffersFDHSv_BH);
        DECL_EGRABBER_FN(euEGenTL_dsQueueBufferFDHBH);
        DECL_EGRABBER_FN(euEGenTL_dsQueueBuffersFDHSv_BH);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAsFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAi8FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAi16FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAi32FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAi64FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAu8FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAu16FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAu32FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAu64FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAdFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAfFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAu8pFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoASsFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAvptrFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoASvcFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoASv_std_stringFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAb8FDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoAcptrFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoA_CINFOFDHBHBIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferInfoFDHBH);
        DECL_EGRABBER_FN(euEGenTL_dsGetNumBufferPartsFDHBH);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAsFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAi8FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAi16FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAi32FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAi64FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAu8FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAu16FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAu32FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAu64FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAdFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAfFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAu8pFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoASsFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAvptrFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoASvcFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoASv_std_stringFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAb8FDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoAcptrFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_dsGetBufferPartInfoA_CINFOFDHBHu32BPIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetNumPortURLsFPH);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAsFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAi8FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAi16FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAi32FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAi64FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAu8FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAu16FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAu32FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAu64FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAdFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAfFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAu8pFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoASsFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAvptrFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoASvcFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoASv_std_stringFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAb8FPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoAcptrFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcGetPortURLInfoA_CINFOFPHu32UIC);
        DECL_EGRABBER_FN(euEGenTL_gcReadPortStackedFPHSv_PRSE);
        DECL_EGRABBER_FN(euEGenTL_gcWritePortStackedFPHSv_PRSE);
        DECL_EGRABBER_FN(euEGenTL_ifGetParentFIH);
        DECL_EGRABBER_FN(euEGenTL_devGetParentFDH);
        DECL_EGRABBER_FN(euEGenTL_dsGetParentFDH);
        DECL_EGRABBER_FN(euEGenTL_mementoFccp);
        DECL_EGRABBER_FN(euEGenTL_mementoFucucccp);
        DECL_EGRABBER_FN(euEGenTL_mementoWaveUpFucuc);
        DECL_EGRABBER_FN(euEGenTL_mementoWaveDownFucuc);
        DECL_EGRABBER_FN(euEGenTL_mementoWaveResetFucuc);
        DECL_EGRABBER_FN(euEGenTL_mementoWaveValueFucucu64);
        DECL_EGRABBER_FN(euEGenTL_mementoWaveNoValueFucuc);
        DECL_EGRABBER_FN(euEGenTL_getTimestampUs);
        DECL_EGRABBER_FN(euEGenTL_genapiSetStringFPHccpccp);
        DECL_EGRABBER_FN(euEGenTL_genapiGetStringFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiGetStringDataFPHccpSvc);
        DECL_EGRABBER_FN(euEGenTL_genapiGetStringListFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiSetIntegerFPHccpi64);
        DECL_EGRABBER_FN(euEGenTL_genapiGetIntegerFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiGetIntegerWithDefaultFPHccpi64);
        DECL_EGRABBER_FN(euEGenTL_genapiSetFloatFPHccpd);
        DECL_EGRABBER_FN(euEGenTL_genapiGetFloatFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiGetFloatWithDefaultFPHccpd);
        DECL_EGRABBER_FN(euEGenTL_genapiSetRegisterFPHccpvps);
        DECL_EGRABBER_FN(euEGenTL_genapiGetRegisterFPHccpvps);
        DECL_EGRABBER_FN(euEGenTL_genapiExecuteCommandFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiAttachEventFPHu64vps);
        DECL_EGRABBER_FN(euEGenTL_genapiInvalidateFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiRunScriptFPHccpGENAPI_UI_SCRIPT_CONTEXT_p);
        DECL_EGRABBER_FN(euEGenTL_genapiRunScriptFPHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiRunScriptFSv_PHccpGENAPI_UI_SCRIPT_CONTEXT_p);
        DECL_EGRABBER_FN(euEGenTL_genapiRunScriptFSv_PHccp);
        DECL_EGRABBER_FN(euEGenTL_genapiInterruptScriptFccp);
        DECL_EGRABBER_FN(euEGenTL_imageGetPixelFormatValueFccpui);
        DECL_EGRABBER_FN(euEGenTL_imageGetPixelFormatFu64);
        DECL_EGRABBER_FN(euEGenTL_imageGetBytesPerPixelFccp);
        DECL_EGRABBER_FN(euEGenTL_imageGetBitsPerPixelFccp);
        DECL_EGRABBER_FN(euEGenTL_imageConvertF_ICI_p_ICO_pImageConvertROI_p);
        DECL_EGRABBER_FN(euEGenTL_imageConvertF_ICI_p_ICO_p);
        DECL_EGRABBER_FN(euEGenTL_imageSaveToDiskF_ICI_pccpi64_ISTDP_p);
        DECL_EGRABBER_FN(euEGenTL_imageSaveToDiskF_ICI_pccpi64);
        DECL_EGRABBER_FN(euEGenTL_imageSaveToDiskF_ICI_pccp);
        DECL_EGRABBER_FN(euEGenTL_imageGetFImageIdsp);
        DECL_EGRABBER_FN(euEGenTL_imageGetFImageId);
        DECL_EGRABBER_FN(euEGenTL_imageReleaseFImageId);
        DECL_EGRABBER_FN(euEGenTL_imagePrepareBuffersFss);
        DECL_EGRABBER_FN(euEGenTL_imageTrimBuffers);
        DECL_EGRABBER_FN(euEGenTL_isShared);
        DECL_EGRABBER_FN(euEGenTL_eventKillQuietFEH);
        DECL_EGRABBER_FN(euEGenTL_lockUpdates);
        DECL_EGRABBER_FN(euEGenTL_unlockUpdates);
        DECL_EGRABBER_FN(euEGenTL_destroy);
};

class EGrabberDllClassEGrabberCOD: virtual public EGrabberDllBase {
    protected:
        EGrabberDllClassEGrabberCOD(const std::string &path)
        : EGrabberDllBase(path)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLiiiDAFb8)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLiiiDAF)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLiii)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLii)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLi)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTL)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEurEGInfoDAFb8)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEurEGInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEurEGInfo)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEurEGCameraInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEurEGCameraInfo)
        , INIT_EGRABBER_FN(dll, euEGCOD_reallocBuffersFss)
        , INIT_EGRABBER_FN(dll, euEGCOD_reallocBuffersFs)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_GenTLMemorys)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_GenTLMemory)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_UserMemory)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_UserMemoryArray)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_UserMemoryArrayb8)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_BusMemory)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceAndQueueFEur_NvidiaRdmaMemory)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushBuffersFAQT)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushBuffers)
        , INIT_EGRABBER_FN(dll, euEGCOD_resetBufferQueue)
        , INIT_EGRABBER_FN(dll, euEGCOD_resetBufferQueueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGCOD_queueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGCOD_revokeFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGCOD_shouldReannounceBuffers)
        , INIT_EGRABBER_FN(dll, euEGCOD_shouldReallocBuffers)
        , INIT_EGRABBER_FN(dll, euEGCOD_startFu64b8)
        , INIT_EGRABBER_FN(dll, euEGCOD_startFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_start)
        , INIT_EGRABBER_FN(dll, euEGCOD_stop)
        , INIT_EGRABBER_FN(dll, euEGCOD_getWidth)
        , INIT_EGRABBER_FN(dll, euEGCOD_getHeight)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPayloadSize)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPixelFormat)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAdOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAfOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8pOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAvptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASvcOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASv_std_stringOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAb8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAcptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoA_CINFOOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAdOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAfOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8pOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAvptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASvcOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASv_std_stringOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAb8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAcptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoA_CINFOOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAdODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAfODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8pODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAvptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASvcODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASv_std_stringODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAb8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAcptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoA_CINFOODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAi64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAdOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAfOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAu8pOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAvptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASvcOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoASv_std_stringOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAb8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoAcptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInfoA_CINFOOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAi8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAi16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAi32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAi64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAu8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAu16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAu32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAu64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAdFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAfFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAu8pFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoASsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAvptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoASvcFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoASv_std_stringFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAb8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoAcptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferInfoA_CINFOFsBIC)
        , INIT_EGRABBER_FN(dll, euEGCOD_getBufferDataFs)
        , INIT_EGRABBER_FN(dll, euEGCOD_isOpenOSystemModule)
        , INIT_EGRABBER_FN(dll, euEGCOD_isOpenOInterfaceModule)
        , INIT_EGRABBER_FN(dll, euEGCOD_isOpenODeviceModule)
        , INIT_EGRABBER_FN(dll, euEGCOD_isOpenOStreamModule)
        , INIT_EGRABBER_FN(dll, euEGCOD_isOpenORemoteModule)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortOSystemModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortOInterfaceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortODeviceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortOStreamModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortORemoteModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAdOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAfOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8pOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAvptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASvcOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASv_std_stringOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAb8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAcptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueA_CINFOOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAdOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAfOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8pOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAvptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASvcOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASv_std_stringOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAb8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAcptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueA_CINFOOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAdODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAfODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8pODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAvptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASvcODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASv_std_stringODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAb8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAcptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueA_CINFOODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAdOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAfOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8pOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAvptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASvcOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASv_std_stringOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAb8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAcptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueA_CINFOOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAi64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAdORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAfORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAu8pORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAvptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASvcORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueASv_std_stringORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAb8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueAcptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortValueA_CINFOORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWsOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi8OSystemModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi16OSystemModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi32OSystemModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi64OSystemModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu8OSystemModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu16OSystemModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu32OSystemModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu64OSystemModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWdOSystemModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWfOSystemModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWsOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi8OInterfaceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi16OInterfaceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi32OInterfaceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi64OInterfaceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu8OInterfaceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu16OInterfaceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu32OInterfaceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu64OInterfaceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWdOInterfaceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWfOInterfaceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWsODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi8ODeviceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi16ODeviceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi32ODeviceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi64ODeviceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu8ODeviceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu16ODeviceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu32ODeviceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu64ODeviceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWdODeviceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWfODeviceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWsOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi8OStreamModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi16OStreamModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi32OStreamModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi64OStreamModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu8OStreamModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu16OStreamModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu32OStreamModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu64OStreamModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWdOStreamModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWfOStreamModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWsORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi8ORemoteModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi16ORemoteModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi32ORemoteModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWi64ORemoteModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu8ORemoteModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu16ORemoteModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu32ORemoteModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWu64ORemoteModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWdORemoteModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcWritePortValueWfORemoteModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortStringOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortStringOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortStringODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortStringOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_gcReadPortStringORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_getIntegerOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getIntegerOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getIntegerODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getIntegerOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getIntegerORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getFloatOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getFloatOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getFloatODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getFloatOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getFloatORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringDataOSystemModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringDataOInterfaceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringDataODeviceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringDataOStreamModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringDataORemoteModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringListOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringListOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringListODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringListOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStringListORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIntegerOSystemModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIntegerOInterfaceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIntegerODeviceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIntegerOStreamModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIntegerORemoteModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGCOD_setFloatOSystemModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGCOD_setFloatOInterfaceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGCOD_setFloatODeviceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGCOD_setFloatOStreamModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGCOD_setFloatORemoteModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGCOD_setStringOSystemModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setStringOInterfaceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setStringODeviceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setStringOStreamModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setStringORemoteModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_executeOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_executeOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_executeODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_executeOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_executeORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_attachEventOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_attachEventOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_attachEventODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_attachEventOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_attachEventORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGCOD_invalidateOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_invalidateOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_invalidateODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_invalidateOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_invalidateORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_runScriptFccpvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_runScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_interruptScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_onScriptUiCallbackFccpvpSm_std_string_std_stringSs)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoFccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoFucucccp)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoWaveUpFucuc)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoWaveDownFucuc)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoWaveResetFucuc)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoWaveValueFucucu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_mementoWaveNoValueFucuc)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_enableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_disableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_flushEventWAll)
        , INIT_EGRABBER_FN(dll, euEGCOD_popFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_pop)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelPop)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWNewBufferDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWIoToolboxDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCicDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWDataStreamDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCxpInterfaceDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWDeviceErrorDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCxpDeviceDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWRemoteDeviceDataFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWAnyFu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventWAny)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventWAny)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWCicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountWAny)
        , INIT_EGRABBER_FN(dll, euEGCOD_onNewBufferEventFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onIoToolboxEventFEur_IoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onCicEventFEur_CicData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onDataStreamEventFEur_DataStreamData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onCxpInterfaceEventFEur_CxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onDeviceErrorEventFEur_DeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onCxpDeviceEventFEur_CxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_onRemoteDeviceEventFEur_RemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGCOD_getLastEventGrabberIndex)
        , INIT_EGRABBER_FN(dll, euEGCOD_shutdown)
        , INIT_EGRABBER_FN(dll, euEGCOD_pushFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGCOD_popEventFilterFsu64EurOOAi_p)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventFilterFsu64)
        , INIT_EGRABBER_FN(dll, euEGCOD_processEventFilterFs)
        , INIT_EGRABBER_FN(dll, euEGCOD_cancelEventFilterFs)
        , INIT_EGRABBER_FN(dll, euEGCOD_getPendingEventCountFilterFs)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceBusBufferFu64svp)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceBusBufferFu64s)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceNvidiaRdmaBufferFvpsvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_announceNvidiaRdmaBufferFvps)
        , INIT_EGRABBER_FN(dll, euEGCOD_getSystemPortFi)
        , INIT_EGRABBER_FN(dll, euEGCOD_getInterfacePortFi)
        , INIT_EGRABBER_FN(dll, euEGCOD_getDevicePortFi)
        , INIT_EGRABBER_FN(dll, euEGCOD_getStreamPortFi)
        , INIT_EGRABBER_FN(dll, euEGCOD_getRemotePortFi)
        , INIT_EGRABBER_FN(dll, euEGCOD_destroy)
        , INIT_EGRABBER_FN(dll, euEGCOD_setNewBufferEventCallbackF_NBECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setIoToolboxEventCallbackF_ITECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setCicEventCallbackF_CECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setDataStreamEventCallbackF_DSECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setCxpInterfaceEventCallbackF_CIECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setDeviceErrorEventCallbackF_DEECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setCxpDeviceEventCallbackF_CDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setRemoteDeviceEventCallbackF_RDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_setScriptUiCallbackFScriptUiCallbackvp)
        , INIT_EGRABBER_FN(dll, euEGCOD_createFEur_EGenTLTHIHDHDH)
        {}
        virtual ~EGrabberDllClassEGrabberCOD()
        {}

    public:
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLiiiDAFb8);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLiiiDAF);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLiii);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLii);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLi);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTL);
        DECL_EGRABBER_FN(euEGCOD_createFEurEGInfoDAFb8);
        DECL_EGRABBER_FN(euEGCOD_createFEurEGInfoDAF);
        DECL_EGRABBER_FN(euEGCOD_createFEurEGInfo);
        DECL_EGRABBER_FN(euEGCOD_createFEurEGCameraInfoDAF);
        DECL_EGRABBER_FN(euEGCOD_createFEurEGCameraInfo);
        DECL_EGRABBER_FN(euEGCOD_reallocBuffersFss);
        DECL_EGRABBER_FN(euEGCOD_reallocBuffersFs);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_GenTLMemorys);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_GenTLMemory);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_UserMemory);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_UserMemoryArray);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_UserMemoryArrayb8);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_BusMemory);
        DECL_EGRABBER_FN(euEGCOD_announceAndQueueFEur_NvidiaRdmaMemory);
        DECL_EGRABBER_FN(euEGCOD_flushBuffersFAQT);
        DECL_EGRABBER_FN(euEGCOD_flushBuffers);
        DECL_EGRABBER_FN(euEGCOD_resetBufferQueue);
        DECL_EGRABBER_FN(euEGCOD_resetBufferQueueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGCOD_queueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGCOD_revokeFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGCOD_shouldReannounceBuffers);
        DECL_EGRABBER_FN(euEGCOD_shouldReallocBuffers);
        DECL_EGRABBER_FN(euEGCOD_startFu64b8);
        DECL_EGRABBER_FN(euEGCOD_startFu64);
        DECL_EGRABBER_FN(euEGCOD_start);
        DECL_EGRABBER_FN(euEGCOD_stop);
        DECL_EGRABBER_FN(euEGCOD_getWidth);
        DECL_EGRABBER_FN(euEGCOD_getHeight);
        DECL_EGRABBER_FN(euEGCOD_getPayloadSize);
        DECL_EGRABBER_FN(euEGCOD_getPixelFormat);
        DECL_EGRABBER_FN(euEGCOD_getInfoAsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAdOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAfOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8pOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAvptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASvcOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASv_std_stringOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAb8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAcptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoA_CINFOOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAdOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAfOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8pOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAvptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASvcOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASv_std_stringOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAb8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAcptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoA_CINFOOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAdODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAfODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8pODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAvptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASvcODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASv_std_stringODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAb8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAcptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoA_CINFOODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAi64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAdOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAfOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAu8pOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAvptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASvcOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoASv_std_stringOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAb8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoAcptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getInfoA_CINFOOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAsFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAi8FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAi16FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAi32FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAi64FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAu8FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAu16FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAu32FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAu64FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAdFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAfFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAu8pFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoASsFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAvptrFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoASvcFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoASv_std_stringFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAb8FsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoAcptrFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferInfoA_CINFOFsBIC);
        DECL_EGRABBER_FN(euEGCOD_getBufferDataFs);
        DECL_EGRABBER_FN(euEGCOD_isOpenOSystemModule);
        DECL_EGRABBER_FN(euEGCOD_isOpenOInterfaceModule);
        DECL_EGRABBER_FN(euEGCOD_isOpenODeviceModule);
        DECL_EGRABBER_FN(euEGCOD_isOpenOStreamModule);
        DECL_EGRABBER_FN(euEGCOD_isOpenORemoteModule);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortOSystemModuleFu64Svc);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortOInterfaceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortODeviceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortOStreamModuleFu64Svc);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortORemoteModuleFu64Svc);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAdOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAfOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8pOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAvptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASvcOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASv_std_stringOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAb8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAcptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueA_CINFOOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAdOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAfOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8pOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAvptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASvcOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASv_std_stringOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAb8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAcptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueA_CINFOOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAdODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAfODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8pODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAvptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASvcODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASv_std_stringODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAb8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAcptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueA_CINFOODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAdOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAfOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8pOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAvptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASvcOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASv_std_stringOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAb8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAcptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueA_CINFOOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAi64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAdORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAfORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAu8pORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAvptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASvcORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueASv_std_stringORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAb8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueAcptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortValueA_CINFOORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWsOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi8OSystemModuleFu64i8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi16OSystemModuleFu64i16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi32OSystemModuleFu64i32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi64OSystemModuleFu64i64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu8OSystemModuleFu64u8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu16OSystemModuleFu64u16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu32OSystemModuleFu64u32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu64OSystemModuleFu64u64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWdOSystemModuleFu64d);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWfOSystemModuleFu64f);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWsOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi8OInterfaceModuleFu64i8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi16OInterfaceModuleFu64i16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi32OInterfaceModuleFu64i32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi64OInterfaceModuleFu64i64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu8OInterfaceModuleFu64u8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu16OInterfaceModuleFu64u16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu32OInterfaceModuleFu64u32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu64OInterfaceModuleFu64u64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWdOInterfaceModuleFu64d);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWfOInterfaceModuleFu64f);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWsODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi8ODeviceModuleFu64i8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi16ODeviceModuleFu64i16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi32ODeviceModuleFu64i32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi64ODeviceModuleFu64i64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu8ODeviceModuleFu64u8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu16ODeviceModuleFu64u16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu32ODeviceModuleFu64u32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu64ODeviceModuleFu64u64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWdODeviceModuleFu64d);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWfODeviceModuleFu64f);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWsOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi8OStreamModuleFu64i8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi16OStreamModuleFu64i16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi32OStreamModuleFu64i32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi64OStreamModuleFu64i64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu8OStreamModuleFu64u8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu16OStreamModuleFu64u16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu32OStreamModuleFu64u32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu64OStreamModuleFu64u64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWdOStreamModuleFu64d);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWfOStreamModuleFu64f);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWsORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi8ORemoteModuleFu64i8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi16ORemoteModuleFu64i16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi32ORemoteModuleFu64i32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWi64ORemoteModuleFu64i64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu8ORemoteModuleFu64u8);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu16ORemoteModuleFu64u16);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu32ORemoteModuleFu64u32);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWu64ORemoteModuleFu64u64);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWdORemoteModuleFu64d);
        DECL_EGRABBER_FN(euEGCOD_gcWritePortValueWfORemoteModuleFu64f);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortStringOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortStringOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortStringODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortStringOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_gcReadPortStringORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGCOD_getIntegerOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getIntegerOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getIntegerODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getIntegerOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getIntegerORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getFloatOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getFloatOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getFloatODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getFloatOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getFloatORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringDataOSystemModuleFccpSvc);
        DECL_EGRABBER_FN(euEGCOD_getStringDataOInterfaceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGCOD_getStringDataODeviceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGCOD_getStringDataOStreamModuleFccpSvc);
        DECL_EGRABBER_FN(euEGCOD_getStringDataORemoteModuleFccpSvc);
        DECL_EGRABBER_FN(euEGCOD_getStringListOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringListOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringListODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringListOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getStringListORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_getRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_getRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_getRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_getRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_getRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_setIntegerOSystemModuleFccpi64);
        DECL_EGRABBER_FN(euEGCOD_setIntegerOInterfaceModuleFccpi64);
        DECL_EGRABBER_FN(euEGCOD_setIntegerODeviceModuleFccpi64);
        DECL_EGRABBER_FN(euEGCOD_setIntegerOStreamModuleFccpi64);
        DECL_EGRABBER_FN(euEGCOD_setIntegerORemoteModuleFccpi64);
        DECL_EGRABBER_FN(euEGCOD_setFloatOSystemModuleFccpd);
        DECL_EGRABBER_FN(euEGCOD_setFloatOInterfaceModuleFccpd);
        DECL_EGRABBER_FN(euEGCOD_setFloatODeviceModuleFccpd);
        DECL_EGRABBER_FN(euEGCOD_setFloatOStreamModuleFccpd);
        DECL_EGRABBER_FN(euEGCOD_setFloatORemoteModuleFccpd);
        DECL_EGRABBER_FN(euEGCOD_setStringOSystemModuleFccpccp);
        DECL_EGRABBER_FN(euEGCOD_setStringOInterfaceModuleFccpccp);
        DECL_EGRABBER_FN(euEGCOD_setStringODeviceModuleFccpccp);
        DECL_EGRABBER_FN(euEGCOD_setStringOStreamModuleFccpccp);
        DECL_EGRABBER_FN(euEGCOD_setStringORemoteModuleFccpccp);
        DECL_EGRABBER_FN(euEGCOD_setRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_setRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_setRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_setRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_setRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGCOD_executeOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_executeOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_executeODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_executeOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_executeORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_attachEventOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_attachEventOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_attachEventODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_attachEventOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_attachEventORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGCOD_invalidateOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_invalidateOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_invalidateODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_invalidateOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_invalidateORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGCOD_runScriptFccpvp);
        DECL_EGRABBER_FN(euEGCOD_runScriptFccp);
        DECL_EGRABBER_FN(euEGCOD_interruptScriptFccp);
        DECL_EGRABBER_FN(euEGCOD_onScriptUiCallbackFccpvpSm_std_string_std_stringSs);
        DECL_EGRABBER_FN(euEGCOD_mementoFccp);
        DECL_EGRABBER_FN(euEGCOD_mementoFucucccp);
        DECL_EGRABBER_FN(euEGCOD_mementoWaveUpFucuc);
        DECL_EGRABBER_FN(euEGCOD_mementoWaveDownFucuc);
        DECL_EGRABBER_FN(euEGCOD_mementoWaveResetFucuc);
        DECL_EGRABBER_FN(euEGCOD_mementoWaveValueFucucu64);
        DECL_EGRABBER_FN(euEGCOD_mementoWaveNoValueFucuc);
        DECL_EGRABBER_FN(euEGCOD_enableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWCicData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_enableEventWAll);
        DECL_EGRABBER_FN(euEGCOD_disableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWCicData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_disableEventWAll);
        DECL_EGRABBER_FN(euEGCOD_flushEventWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWCicData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_flushEventWAll);
        DECL_EGRABBER_FN(euEGCOD_popFu64);
        DECL_EGRABBER_FN(euEGCOD_pop);
        DECL_EGRABBER_FN(euEGCOD_cancelPop);
        DECL_EGRABBER_FN(euEGCOD_processEventWNewBufferDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWIoToolboxDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWCicDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWDataStreamDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWCxpInterfaceDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWDeviceErrorDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWCxpDeviceDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWRemoteDeviceDataFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWAnyFu64);
        DECL_EGRABBER_FN(euEGCOD_processEventWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_processEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_processEventWCicData);
        DECL_EGRABBER_FN(euEGCOD_processEventWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_processEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_processEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_processEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_processEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_processEventWAny);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWCicData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_cancelEventWAny);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWNewBufferData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWIoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWCicData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWDataStreamData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWDeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWCxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountWAny);
        DECL_EGRABBER_FN(euEGCOD_onNewBufferEventFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGCOD_onIoToolboxEventFEur_IoToolboxData);
        DECL_EGRABBER_FN(euEGCOD_onCicEventFEur_CicData);
        DECL_EGRABBER_FN(euEGCOD_onDataStreamEventFEur_DataStreamData);
        DECL_EGRABBER_FN(euEGCOD_onCxpInterfaceEventFEur_CxpInterfaceData);
        DECL_EGRABBER_FN(euEGCOD_onDeviceErrorEventFEur_DeviceErrorData);
        DECL_EGRABBER_FN(euEGCOD_onCxpDeviceEventFEur_CxpDeviceData);
        DECL_EGRABBER_FN(euEGCOD_onRemoteDeviceEventFEur_RemoteDeviceData);
        DECL_EGRABBER_FN(euEGCOD_getLastEventGrabberIndex);
        DECL_EGRABBER_FN(euEGCOD_shutdown);
        DECL_EGRABBER_FN(euEGCOD_pushFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGCOD_popEventFilterFsu64EurOOAi_p);
        DECL_EGRABBER_FN(euEGCOD_processEventFilterFsu64);
        DECL_EGRABBER_FN(euEGCOD_processEventFilterFs);
        DECL_EGRABBER_FN(euEGCOD_cancelEventFilterFs);
        DECL_EGRABBER_FN(euEGCOD_getPendingEventCountFilterFs);
        DECL_EGRABBER_FN(euEGCOD_announceBusBufferFu64svp);
        DECL_EGRABBER_FN(euEGCOD_announceBusBufferFu64s);
        DECL_EGRABBER_FN(euEGCOD_announceNvidiaRdmaBufferFvpsvp);
        DECL_EGRABBER_FN(euEGCOD_announceNvidiaRdmaBufferFvps);
        DECL_EGRABBER_FN(euEGCOD_getSystemPortFi);
        DECL_EGRABBER_FN(euEGCOD_getInterfacePortFi);
        DECL_EGRABBER_FN(euEGCOD_getDevicePortFi);
        DECL_EGRABBER_FN(euEGCOD_getStreamPortFi);
        DECL_EGRABBER_FN(euEGCOD_getRemotePortFi);
        DECL_EGRABBER_FN(euEGCOD_destroy);
        DECL_EGRABBER_FN(euEGCOD_setNewBufferEventCallbackF_NBECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setIoToolboxEventCallbackF_ITECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setCicEventCallbackF_CECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setDataStreamEventCallbackF_DSECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setCxpInterfaceEventCallbackF_CIECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setDeviceErrorEventCallbackF_DEECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setCxpDeviceEventCallbackF_CDECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setRemoteDeviceEventCallbackF_RDECallbackvp);
        DECL_EGRABBER_FN(euEGCOD_setScriptUiCallbackFScriptUiCallbackvp);
        DECL_EGRABBER_FN(euEGCOD_createFEur_EGenTLTHIHDHDH);
};

class EGrabberDllClassEGrabberST: virtual public EGrabberDllBase {
    protected:
        EGrabberDllClassEGrabberST(const std::string &path)
        : EGrabberDllBase(path)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLiiiDAFb8)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLiiiDAF)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLiii)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLii)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLi)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTL)
        , INIT_EGRABBER_FN(dll, euEGST_createFEurEGInfoDAFb8)
        , INIT_EGRABBER_FN(dll, euEGST_createFEurEGInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGST_createFEurEGInfo)
        , INIT_EGRABBER_FN(dll, euEGST_createFEurEGCameraInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGST_createFEurEGCameraInfo)
        , INIT_EGRABBER_FN(dll, euEGST_reallocBuffersFss)
        , INIT_EGRABBER_FN(dll, euEGST_reallocBuffersFs)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_GenTLMemorys)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_GenTLMemory)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_UserMemory)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_UserMemoryArray)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_UserMemoryArrayb8)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_BusMemory)
        , INIT_EGRABBER_FN(dll, euEGST_announceAndQueueFEur_NvidiaRdmaMemory)
        , INIT_EGRABBER_FN(dll, euEGST_flushBuffersFAQT)
        , INIT_EGRABBER_FN(dll, euEGST_flushBuffers)
        , INIT_EGRABBER_FN(dll, euEGST_resetBufferQueue)
        , INIT_EGRABBER_FN(dll, euEGST_resetBufferQueueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGST_queueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGST_revokeFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGST_shouldReannounceBuffers)
        , INIT_EGRABBER_FN(dll, euEGST_shouldReallocBuffers)
        , INIT_EGRABBER_FN(dll, euEGST_startFu64b8)
        , INIT_EGRABBER_FN(dll, euEGST_startFu64)
        , INIT_EGRABBER_FN(dll, euEGST_start)
        , INIT_EGRABBER_FN(dll, euEGST_stop)
        , INIT_EGRABBER_FN(dll, euEGST_getWidth)
        , INIT_EGRABBER_FN(dll, euEGST_getHeight)
        , INIT_EGRABBER_FN(dll, euEGST_getPayloadSize)
        , INIT_EGRABBER_FN(dll, euEGST_getPixelFormat)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAdOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAfOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8pOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAvptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASvcOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASv_std_stringOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAb8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAcptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoA_CINFOOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAdOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAfOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8pOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAvptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASvcOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASv_std_stringOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAb8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAcptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoA_CINFOOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAdODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAfODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8pODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAvptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASvcODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASv_std_stringODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAb8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAcptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoA_CINFOODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAi64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAdOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAfOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAu8pOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAvptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASvcOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoASv_std_stringOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAb8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoAcptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getInfoA_CINFOOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAi8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAi16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAi32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAi64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAu8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAu16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAu32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAu64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAdFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAfFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAu8pFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoASsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAvptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoASvcFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoASv_std_stringFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAb8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoAcptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferInfoA_CINFOFsBIC)
        , INIT_EGRABBER_FN(dll, euEGST_getBufferDataFs)
        , INIT_EGRABBER_FN(dll, euEGST_isOpenOSystemModule)
        , INIT_EGRABBER_FN(dll, euEGST_isOpenOInterfaceModule)
        , INIT_EGRABBER_FN(dll, euEGST_isOpenODeviceModule)
        , INIT_EGRABBER_FN(dll, euEGST_isOpenOStreamModule)
        , INIT_EGRABBER_FN(dll, euEGST_isOpenORemoteModule)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortOSystemModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortOInterfaceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortODeviceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortOStreamModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortORemoteModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAdOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAfOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8pOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAvptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASvcOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASv_std_stringOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAb8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAcptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueA_CINFOOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAdOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAfOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8pOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAvptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASvcOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASv_std_stringOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAb8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAcptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueA_CINFOOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAdODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAfODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8pODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAvptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASvcODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASv_std_stringODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAb8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAcptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueA_CINFOODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAdOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAfOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8pOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAvptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASvcOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASv_std_stringOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAb8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAcptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueA_CINFOOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAi64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAdORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAfORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAu8pORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAvptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASvcORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueASv_std_stringORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAb8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueAcptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortValueA_CINFOORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWsOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi8OSystemModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi16OSystemModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi32OSystemModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi64OSystemModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu8OSystemModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu16OSystemModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu32OSystemModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu64OSystemModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWdOSystemModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWfOSystemModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWsOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi8OInterfaceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi16OInterfaceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi32OInterfaceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi64OInterfaceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu8OInterfaceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu16OInterfaceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu32OInterfaceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu64OInterfaceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWdOInterfaceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWfOInterfaceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWsODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi8ODeviceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi16ODeviceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi32ODeviceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi64ODeviceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu8ODeviceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu16ODeviceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu32ODeviceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu64ODeviceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWdODeviceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWfODeviceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWsOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi8OStreamModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi16OStreamModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi32OStreamModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi64OStreamModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu8OStreamModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu16OStreamModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu32OStreamModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu64OStreamModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWdOStreamModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWfOStreamModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWsORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi8ORemoteModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi16ORemoteModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi32ORemoteModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWi64ORemoteModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu8ORemoteModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu16ORemoteModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu32ORemoteModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWu64ORemoteModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWdORemoteModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGST_gcWritePortValueWfORemoteModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortStringOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortStringOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortStringODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortStringOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_gcReadPortStringORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_getIntegerOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getIntegerOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getIntegerODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getIntegerOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getIntegerORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getFloatOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getFloatOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getFloatODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getFloatOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getFloatORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringDataOSystemModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGST_getStringDataOInterfaceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGST_getStringDataODeviceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGST_getStringDataOStreamModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGST_getStringDataORemoteModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGST_getStringListOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringListOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringListODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringListOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getStringListORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_getRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_getRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_getRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_getRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_getRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_setIntegerOSystemModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGST_setIntegerOInterfaceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGST_setIntegerODeviceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGST_setIntegerOStreamModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGST_setIntegerORemoteModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGST_setFloatOSystemModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGST_setFloatOInterfaceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGST_setFloatODeviceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGST_setFloatOStreamModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGST_setFloatORemoteModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGST_setStringOSystemModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGST_setStringOInterfaceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGST_setStringODeviceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGST_setStringOStreamModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGST_setStringORemoteModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGST_setRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_setRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_setRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_setRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_setRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGST_executeOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_executeOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_executeODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_executeOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_executeORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_attachEventOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_attachEventOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_attachEventODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_attachEventOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_attachEventORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGST_invalidateOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_invalidateOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_invalidateODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_invalidateOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_invalidateORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGST_runScriptFccpvp)
        , INIT_EGRABBER_FN(dll, euEGST_runScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGST_interruptScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGST_onScriptUiCallbackFccpvpSm_std_string_std_stringSs)
        , INIT_EGRABBER_FN(dll, euEGST_mementoFccp)
        , INIT_EGRABBER_FN(dll, euEGST_mementoFucucccp)
        , INIT_EGRABBER_FN(dll, euEGST_mementoWaveUpFucuc)
        , INIT_EGRABBER_FN(dll, euEGST_mementoWaveDownFucuc)
        , INIT_EGRABBER_FN(dll, euEGST_mementoWaveResetFucuc)
        , INIT_EGRABBER_FN(dll, euEGST_mementoWaveValueFucucu64)
        , INIT_EGRABBER_FN(dll, euEGST_mementoWaveNoValueFucuc)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_enableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_disableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_flushEventWAll)
        , INIT_EGRABBER_FN(dll, euEGST_onNewBufferEventFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGST_onIoToolboxEventFEur_IoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGST_onCicEventFEur_CicData)
        , INIT_EGRABBER_FN(dll, euEGST_onDataStreamEventFEur_DataStreamData)
        , INIT_EGRABBER_FN(dll, euEGST_onCxpInterfaceEventFEur_CxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGST_onDeviceErrorEventFEur_DeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGST_onCxpDeviceEventFEur_CxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_onRemoteDeviceEventFEur_RemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGST_getLastEventGrabberIndex)
        , INIT_EGRABBER_FN(dll, euEGST_shutdown)
        , INIT_EGRABBER_FN(dll, euEGST_pushFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGST_announceBusBufferFu64svp)
        , INIT_EGRABBER_FN(dll, euEGST_announceBusBufferFu64s)
        , INIT_EGRABBER_FN(dll, euEGST_announceNvidiaRdmaBufferFvpsvp)
        , INIT_EGRABBER_FN(dll, euEGST_announceNvidiaRdmaBufferFvps)
        , INIT_EGRABBER_FN(dll, euEGST_getSystemPortFi)
        , INIT_EGRABBER_FN(dll, euEGST_getInterfacePortFi)
        , INIT_EGRABBER_FN(dll, euEGST_getDevicePortFi)
        , INIT_EGRABBER_FN(dll, euEGST_getStreamPortFi)
        , INIT_EGRABBER_FN(dll, euEGST_getRemotePortFi)
        , INIT_EGRABBER_FN(dll, euEGST_destroy)
        , INIT_EGRABBER_FN(dll, euEGST_setNewBufferEventCallbackF_NBECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setIoToolboxEventCallbackF_ITECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setCicEventCallbackF_CECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setDataStreamEventCallbackF_DSECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setCxpInterfaceEventCallbackF_CIECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setDeviceErrorEventCallbackF_DEECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setCxpDeviceEventCallbackF_CDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setRemoteDeviceEventCallbackF_RDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setScriptUiCallbackFScriptUiCallbackvp)
        , INIT_EGRABBER_FN(dll, euEGST_setThreadStartCallbackF_TStartCvp)
        , INIT_EGRABBER_FN(dll, euEGST_setThreadStopCallbackF_TStopCvp)
        , INIT_EGRABBER_FN(dll, euEGST_createFEur_EGenTLTHIHDHDH)
        {}
        virtual ~EGrabberDllClassEGrabberST()
        {}

    public:
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLiiiDAFb8);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLiiiDAF);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLiii);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLii);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLi);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTL);
        DECL_EGRABBER_FN(euEGST_createFEurEGInfoDAFb8);
        DECL_EGRABBER_FN(euEGST_createFEurEGInfoDAF);
        DECL_EGRABBER_FN(euEGST_createFEurEGInfo);
        DECL_EGRABBER_FN(euEGST_createFEurEGCameraInfoDAF);
        DECL_EGRABBER_FN(euEGST_createFEurEGCameraInfo);
        DECL_EGRABBER_FN(euEGST_reallocBuffersFss);
        DECL_EGRABBER_FN(euEGST_reallocBuffersFs);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_GenTLMemorys);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_GenTLMemory);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_UserMemory);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_UserMemoryArray);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_UserMemoryArrayb8);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_BusMemory);
        DECL_EGRABBER_FN(euEGST_announceAndQueueFEur_NvidiaRdmaMemory);
        DECL_EGRABBER_FN(euEGST_flushBuffersFAQT);
        DECL_EGRABBER_FN(euEGST_flushBuffers);
        DECL_EGRABBER_FN(euEGST_resetBufferQueue);
        DECL_EGRABBER_FN(euEGST_resetBufferQueueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGST_queueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGST_revokeFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGST_shouldReannounceBuffers);
        DECL_EGRABBER_FN(euEGST_shouldReallocBuffers);
        DECL_EGRABBER_FN(euEGST_startFu64b8);
        DECL_EGRABBER_FN(euEGST_startFu64);
        DECL_EGRABBER_FN(euEGST_start);
        DECL_EGRABBER_FN(euEGST_stop);
        DECL_EGRABBER_FN(euEGST_getWidth);
        DECL_EGRABBER_FN(euEGST_getHeight);
        DECL_EGRABBER_FN(euEGST_getPayloadSize);
        DECL_EGRABBER_FN(euEGST_getPixelFormat);
        DECL_EGRABBER_FN(euEGST_getInfoAsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAdOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAfOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8pOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAvptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASvcOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASv_std_stringOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAb8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAcptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoA_CINFOOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAdOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAfOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8pOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAvptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASvcOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASv_std_stringOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAb8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAcptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoA_CINFOOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAdODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAfODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8pODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAvptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASvcODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASv_std_stringODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAb8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAcptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoA_CINFOODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAi64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAdOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAfOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAu8pOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAvptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASvcOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoASv_std_stringOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAb8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoAcptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getInfoA_CINFOOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAsFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAi8FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAi16FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAi32FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAi64FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAu8FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAu16FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAu32FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAu64FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAdFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAfFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAu8pFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoASsFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAvptrFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoASvcFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoASv_std_stringFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAb8FsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoAcptrFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferInfoA_CINFOFsBIC);
        DECL_EGRABBER_FN(euEGST_getBufferDataFs);
        DECL_EGRABBER_FN(euEGST_isOpenOSystemModule);
        DECL_EGRABBER_FN(euEGST_isOpenOInterfaceModule);
        DECL_EGRABBER_FN(euEGST_isOpenODeviceModule);
        DECL_EGRABBER_FN(euEGST_isOpenOStreamModule);
        DECL_EGRABBER_FN(euEGST_isOpenORemoteModule);
        DECL_EGRABBER_FN(euEGST_gcReadPortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcReadPortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcReadPortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcReadPortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcReadPortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcWritePortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcWritePortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcWritePortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcWritePortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcWritePortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_gcReadPortOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortOSystemModuleFu64Svc);
        DECL_EGRABBER_FN(euEGST_gcWritePortOInterfaceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGST_gcWritePortODeviceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGST_gcWritePortOStreamModuleFu64Svc);
        DECL_EGRABBER_FN(euEGST_gcWritePortORemoteModuleFu64Svc);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAdOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAfOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8pOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAvptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASvcOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASv_std_stringOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAb8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAcptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueA_CINFOOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAdOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAfOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8pOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAvptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASvcOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASv_std_stringOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAb8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAcptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueA_CINFOOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAdODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAfODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8pODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAvptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASvcODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASv_std_stringODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAb8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAcptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueA_CINFOODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAdOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAfOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8pOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAvptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASvcOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASv_std_stringOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAb8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAcptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueA_CINFOOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAi64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAdORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAfORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAu8pORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAvptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASvcORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueASv_std_stringORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAb8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueAcptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcReadPortValueA_CINFOORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWsOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi8OSystemModuleFu64i8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi16OSystemModuleFu64i16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi32OSystemModuleFu64i32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi64OSystemModuleFu64i64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu8OSystemModuleFu64u8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu16OSystemModuleFu64u16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu32OSystemModuleFu64u32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu64OSystemModuleFu64u64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWdOSystemModuleFu64d);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWfOSystemModuleFu64f);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWsOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi8OInterfaceModuleFu64i8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi16OInterfaceModuleFu64i16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi32OInterfaceModuleFu64i32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi64OInterfaceModuleFu64i64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu8OInterfaceModuleFu64u8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu16OInterfaceModuleFu64u16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu32OInterfaceModuleFu64u32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu64OInterfaceModuleFu64u64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWdOInterfaceModuleFu64d);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWfOInterfaceModuleFu64f);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWsODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi8ODeviceModuleFu64i8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi16ODeviceModuleFu64i16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi32ODeviceModuleFu64i32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi64ODeviceModuleFu64i64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu8ODeviceModuleFu64u8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu16ODeviceModuleFu64u16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu32ODeviceModuleFu64u32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu64ODeviceModuleFu64u64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWdODeviceModuleFu64d);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWfODeviceModuleFu64f);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWsOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi8OStreamModuleFu64i8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi16OStreamModuleFu64i16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi32OStreamModuleFu64i32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi64OStreamModuleFu64i64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu8OStreamModuleFu64u8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu16OStreamModuleFu64u16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu32OStreamModuleFu64u32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu64OStreamModuleFu64u64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWdOStreamModuleFu64d);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWfOStreamModuleFu64f);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWsORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi8ORemoteModuleFu64i8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi16ORemoteModuleFu64i16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi32ORemoteModuleFu64i32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWi64ORemoteModuleFu64i64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu8ORemoteModuleFu64u8);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu16ORemoteModuleFu64u16);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu32ORemoteModuleFu64u32);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWu64ORemoteModuleFu64u64);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWdORemoteModuleFu64d);
        DECL_EGRABBER_FN(euEGST_gcWritePortValueWfORemoteModuleFu64f);
        DECL_EGRABBER_FN(euEGST_gcReadPortStringOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortStringOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortStringODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortStringOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGST_gcReadPortStringORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGST_getIntegerOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_getIntegerOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getIntegerODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getIntegerOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_getIntegerORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_getFloatOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_getFloatOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getFloatODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getFloatOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_getFloatORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringDataOSystemModuleFccpSvc);
        DECL_EGRABBER_FN(euEGST_getStringDataOInterfaceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGST_getStringDataODeviceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGST_getStringDataOStreamModuleFccpSvc);
        DECL_EGRABBER_FN(euEGST_getStringDataORemoteModuleFccpSvc);
        DECL_EGRABBER_FN(euEGST_getStringListOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringListOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringListODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringListOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_getStringListORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_getRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_getRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_getRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_getRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_getRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_setIntegerOSystemModuleFccpi64);
        DECL_EGRABBER_FN(euEGST_setIntegerOInterfaceModuleFccpi64);
        DECL_EGRABBER_FN(euEGST_setIntegerODeviceModuleFccpi64);
        DECL_EGRABBER_FN(euEGST_setIntegerOStreamModuleFccpi64);
        DECL_EGRABBER_FN(euEGST_setIntegerORemoteModuleFccpi64);
        DECL_EGRABBER_FN(euEGST_setFloatOSystemModuleFccpd);
        DECL_EGRABBER_FN(euEGST_setFloatOInterfaceModuleFccpd);
        DECL_EGRABBER_FN(euEGST_setFloatODeviceModuleFccpd);
        DECL_EGRABBER_FN(euEGST_setFloatOStreamModuleFccpd);
        DECL_EGRABBER_FN(euEGST_setFloatORemoteModuleFccpd);
        DECL_EGRABBER_FN(euEGST_setStringOSystemModuleFccpccp);
        DECL_EGRABBER_FN(euEGST_setStringOInterfaceModuleFccpccp);
        DECL_EGRABBER_FN(euEGST_setStringODeviceModuleFccpccp);
        DECL_EGRABBER_FN(euEGST_setStringOStreamModuleFccpccp);
        DECL_EGRABBER_FN(euEGST_setStringORemoteModuleFccpccp);
        DECL_EGRABBER_FN(euEGST_setRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_setRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_setRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_setRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_setRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGST_executeOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_executeOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_executeODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_executeOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_executeORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_attachEventOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_attachEventOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_attachEventODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_attachEventOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_attachEventORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGST_invalidateOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGST_invalidateOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGST_invalidateODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGST_invalidateOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGST_invalidateORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGST_runScriptFccpvp);
        DECL_EGRABBER_FN(euEGST_runScriptFccp);
        DECL_EGRABBER_FN(euEGST_interruptScriptFccp);
        DECL_EGRABBER_FN(euEGST_onScriptUiCallbackFccpvpSm_std_string_std_stringSs);
        DECL_EGRABBER_FN(euEGST_mementoFccp);
        DECL_EGRABBER_FN(euEGST_mementoFucucccp);
        DECL_EGRABBER_FN(euEGST_mementoWaveUpFucuc);
        DECL_EGRABBER_FN(euEGST_mementoWaveDownFucuc);
        DECL_EGRABBER_FN(euEGST_mementoWaveResetFucuc);
        DECL_EGRABBER_FN(euEGST_mementoWaveValueFucucu64);
        DECL_EGRABBER_FN(euEGST_mementoWaveNoValueFucuc);
        DECL_EGRABBER_FN(euEGST_enableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGST_enableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGST_enableEventWCicData);
        DECL_EGRABBER_FN(euEGST_enableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGST_enableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGST_enableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGST_enableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGST_enableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGST_enableEventWAll);
        DECL_EGRABBER_FN(euEGST_disableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGST_disableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGST_disableEventWCicData);
        DECL_EGRABBER_FN(euEGST_disableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGST_disableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGST_disableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGST_disableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGST_disableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGST_disableEventWAll);
        DECL_EGRABBER_FN(euEGST_flushEventWNewBufferData);
        DECL_EGRABBER_FN(euEGST_flushEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGST_flushEventWCicData);
        DECL_EGRABBER_FN(euEGST_flushEventWDataStreamData);
        DECL_EGRABBER_FN(euEGST_flushEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGST_flushEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGST_flushEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGST_flushEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGST_flushEventWAll);
        DECL_EGRABBER_FN(euEGST_onNewBufferEventFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGST_onIoToolboxEventFEur_IoToolboxData);
        DECL_EGRABBER_FN(euEGST_onCicEventFEur_CicData);
        DECL_EGRABBER_FN(euEGST_onDataStreamEventFEur_DataStreamData);
        DECL_EGRABBER_FN(euEGST_onCxpInterfaceEventFEur_CxpInterfaceData);
        DECL_EGRABBER_FN(euEGST_onDeviceErrorEventFEur_DeviceErrorData);
        DECL_EGRABBER_FN(euEGST_onCxpDeviceEventFEur_CxpDeviceData);
        DECL_EGRABBER_FN(euEGST_onRemoteDeviceEventFEur_RemoteDeviceData);
        DECL_EGRABBER_FN(euEGST_getLastEventGrabberIndex);
        DECL_EGRABBER_FN(euEGST_shutdown);
        DECL_EGRABBER_FN(euEGST_pushFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGST_announceBusBufferFu64svp);
        DECL_EGRABBER_FN(euEGST_announceBusBufferFu64s);
        DECL_EGRABBER_FN(euEGST_announceNvidiaRdmaBufferFvpsvp);
        DECL_EGRABBER_FN(euEGST_announceNvidiaRdmaBufferFvps);
        DECL_EGRABBER_FN(euEGST_getSystemPortFi);
        DECL_EGRABBER_FN(euEGST_getInterfacePortFi);
        DECL_EGRABBER_FN(euEGST_getDevicePortFi);
        DECL_EGRABBER_FN(euEGST_getStreamPortFi);
        DECL_EGRABBER_FN(euEGST_getRemotePortFi);
        DECL_EGRABBER_FN(euEGST_destroy);
        DECL_EGRABBER_FN(euEGST_setNewBufferEventCallbackF_NBECallbackvp);
        DECL_EGRABBER_FN(euEGST_setIoToolboxEventCallbackF_ITECallbackvp);
        DECL_EGRABBER_FN(euEGST_setCicEventCallbackF_CECallbackvp);
        DECL_EGRABBER_FN(euEGST_setDataStreamEventCallbackF_DSECallbackvp);
        DECL_EGRABBER_FN(euEGST_setCxpInterfaceEventCallbackF_CIECallbackvp);
        DECL_EGRABBER_FN(euEGST_setDeviceErrorEventCallbackF_DEECallbackvp);
        DECL_EGRABBER_FN(euEGST_setCxpDeviceEventCallbackF_CDECallbackvp);
        DECL_EGRABBER_FN(euEGST_setRemoteDeviceEventCallbackF_RDECallbackvp);
        DECL_EGRABBER_FN(euEGST_setScriptUiCallbackFScriptUiCallbackvp);
        DECL_EGRABBER_FN(euEGST_setThreadStartCallbackF_TStartCvp);
        DECL_EGRABBER_FN(euEGST_setThreadStopCallbackF_TStopCvp);
        DECL_EGRABBER_FN(euEGST_createFEur_EGenTLTHIHDHDH);
};

class EGrabberDllClassEGrabberMT: virtual public EGrabberDllBase {
    protected:
        EGrabberDllClassEGrabberMT(const std::string &path)
        : EGrabberDllBase(path)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLiiiDAFb8)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLiiiDAF)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLiii)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLii)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLi)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTL)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEurEGInfoDAFb8)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEurEGInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEurEGInfo)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEurEGCameraInfoDAF)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEurEGCameraInfo)
        , INIT_EGRABBER_FN(dll, euEGMT_reallocBuffersFss)
        , INIT_EGRABBER_FN(dll, euEGMT_reallocBuffersFs)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_GenTLMemorys)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_GenTLMemory)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_UserMemory)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_UserMemoryArray)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_UserMemoryArrayb8)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_BusMemory)
        , INIT_EGRABBER_FN(dll, euEGMT_announceAndQueueFEur_NvidiaRdmaMemory)
        , INIT_EGRABBER_FN(dll, euEGMT_flushBuffersFAQT)
        , INIT_EGRABBER_FN(dll, euEGMT_flushBuffers)
        , INIT_EGRABBER_FN(dll, euEGMT_resetBufferQueue)
        , INIT_EGRABBER_FN(dll, euEGMT_resetBufferQueueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGMT_queueFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGMT_revokeFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euEGMT_shouldReannounceBuffers)
        , INIT_EGRABBER_FN(dll, euEGMT_shouldReallocBuffers)
        , INIT_EGRABBER_FN(dll, euEGMT_startFu64b8)
        , INIT_EGRABBER_FN(dll, euEGMT_startFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_start)
        , INIT_EGRABBER_FN(dll, euEGMT_stop)
        , INIT_EGRABBER_FN(dll, euEGMT_getWidth)
        , INIT_EGRABBER_FN(dll, euEGMT_getHeight)
        , INIT_EGRABBER_FN(dll, euEGMT_getPayloadSize)
        , INIT_EGRABBER_FN(dll, euEGMT_getPixelFormat)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu16OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu32OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu64OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAdOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAfOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8pOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASsOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAvptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASvcOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASv_std_stringOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAb8OSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAcptrOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoA_CINFOOSystemModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu16OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu32OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu64OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAdOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAfOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8pOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASsOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAvptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASvcOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASv_std_stringOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAb8OInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAcptrOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoA_CINFOOInterfaceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu16ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu32ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu64ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAdODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAfODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8pODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASsODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAvptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASvcODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASv_std_stringODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAb8ODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAcptrODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoA_CINFOODeviceModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAi64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu16OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu32OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu64OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAdOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAfOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAu8pOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASsOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAvptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASvcOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoASv_std_stringOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAb8OStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoAcptrOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getInfoA_CINFOOStreamModuleFi32)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAi8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAi16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAi32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAi64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAu8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAu16FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAu32FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAu64FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAdFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAfFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAu8pFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoASsFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAvptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoASvcFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoASv_std_stringFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAb8FsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoAcptrFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferInfoA_CINFOFsBIC)
        , INIT_EGRABBER_FN(dll, euEGMT_getBufferDataFs)
        , INIT_EGRABBER_FN(dll, euEGMT_isOpenOSystemModule)
        , INIT_EGRABBER_FN(dll, euEGMT_isOpenOInterfaceModule)
        , INIT_EGRABBER_FN(dll, euEGMT_isOpenODeviceModule)
        , INIT_EGRABBER_FN(dll, euEGMT_isOpenOStreamModule)
        , INIT_EGRABBER_FN(dll, euEGMT_isOpenORemoteModule)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortDataOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortDataOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortDataODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortDataOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortDataORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortOSystemModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortOInterfaceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortODeviceModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortOStreamModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortORemoteModuleFu64Svc)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu16OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu32OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu64OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAdOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAfOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8pOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASsOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAvptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASvcOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASv_std_stringOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAb8OSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAcptrOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueA_CINFOOSystemModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu16OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu32OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu64OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAdOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAfOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8pOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASsOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAvptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASvcOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASv_std_stringOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAb8OInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAcptrOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueA_CINFOOInterfaceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu16ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu32ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu64ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAdODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAfODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8pODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASsODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAvptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASvcODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASv_std_stringODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAb8ODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAcptrODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueA_CINFOODeviceModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu16OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu32OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu64OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAdOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAfOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8pOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASsOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAvptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASvcOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASv_std_stringOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAb8OStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAcptrOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueA_CINFOOStreamModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAi64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu16ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu32ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu64ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAdORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAfORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAu8pORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASsORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAvptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASvcORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueASv_std_stringORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAb8ORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueAcptrORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortValueA_CINFOORemoteModuleFu64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWsOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi8OSystemModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi16OSystemModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi32OSystemModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi64OSystemModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu8OSystemModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu16OSystemModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu32OSystemModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu64OSystemModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWdOSystemModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWfOSystemModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWsOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi8OInterfaceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi16OInterfaceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi32OInterfaceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi64OInterfaceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu8OInterfaceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu16OInterfaceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu32OInterfaceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu64OInterfaceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWdOInterfaceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWfOInterfaceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWsODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi8ODeviceModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi16ODeviceModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi32ODeviceModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi64ODeviceModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu8ODeviceModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu16ODeviceModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu32ODeviceModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu64ODeviceModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWdODeviceModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWfODeviceModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWsOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi8OStreamModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi16OStreamModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi32OStreamModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi64OStreamModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu8OStreamModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu16OStreamModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu32OStreamModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu64OStreamModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWdOStreamModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWfOStreamModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWsORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi8ORemoteModuleFu64i8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi16ORemoteModuleFu64i16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi32ORemoteModuleFu64i32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWi64ORemoteModuleFu64i64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu8ORemoteModuleFu64u8)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu16ORemoteModuleFu64u16)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu32ORemoteModuleFu64u32)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWu64ORemoteModuleFu64u64)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWdORemoteModuleFu64d)
        , INIT_EGRABBER_FN(dll, euEGMT_gcWritePortValueWfORemoteModuleFu64f)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortStringOSystemModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortStringOInterfaceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortStringODeviceModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortStringOStreamModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_gcReadPortStringORemoteModuleFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_getIntegerOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getIntegerOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getIntegerODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getIntegerOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getIntegerORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getFloatOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getFloatOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getFloatODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getFloatOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getFloatORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringDataOSystemModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringDataOInterfaceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringDataODeviceModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringDataOStreamModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringDataORemoteModuleFccpSvc)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringListOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringListOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringListODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringListOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getStringListORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_getRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_getRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_getRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_getRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_getRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_setIntegerOSystemModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGMT_setIntegerOInterfaceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGMT_setIntegerODeviceModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGMT_setIntegerOStreamModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGMT_setIntegerORemoteModuleFccpi64)
        , INIT_EGRABBER_FN(dll, euEGMT_setFloatOSystemModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGMT_setFloatOInterfaceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGMT_setFloatODeviceModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGMT_setFloatOStreamModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGMT_setFloatORemoteModuleFccpd)
        , INIT_EGRABBER_FN(dll, euEGMT_setStringOSystemModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGMT_setStringOInterfaceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGMT_setStringODeviceModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGMT_setStringOStreamModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGMT_setStringORemoteModuleFccpccp)
        , INIT_EGRABBER_FN(dll, euEGMT_setRegisterOSystemModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_setRegisterOInterfaceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_setRegisterODeviceModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_setRegisterOStreamModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_setRegisterORemoteModuleFccpvps)
        , INIT_EGRABBER_FN(dll, euEGMT_executeOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_executeOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_executeODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_executeOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_executeORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_attachEventOSystemModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_attachEventOInterfaceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_attachEventODeviceModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_attachEventOStreamModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_attachEventORemoteModuleFu64vps)
        , INIT_EGRABBER_FN(dll, euEGMT_invalidateOSystemModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_invalidateOInterfaceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_invalidateODeviceModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_invalidateOStreamModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_invalidateORemoteModuleFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_runScriptFccpvp)
        , INIT_EGRABBER_FN(dll, euEGMT_runScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_interruptScriptFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_onScriptUiCallbackFccpvpSm_std_string_std_stringSs)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoFccp)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoFucucccp)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoWaveUpFucuc)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoWaveDownFucuc)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoWaveResetFucuc)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoWaveValueFucucu64)
        , INIT_EGRABBER_FN(dll, euEGMT_mementoWaveNoValueFucuc)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_enableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_disableEventWAll)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWNewBufferData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWIoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWCicData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWDataStreamData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWDeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWCxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWRemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_flushEventWAll)
        , INIT_EGRABBER_FN(dll, euEGMT_onNewBufferEventFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGMT_onIoToolboxEventFEur_IoToolboxData)
        , INIT_EGRABBER_FN(dll, euEGMT_onCicEventFEur_CicData)
        , INIT_EGRABBER_FN(dll, euEGMT_onDataStreamEventFEur_DataStreamData)
        , INIT_EGRABBER_FN(dll, euEGMT_onCxpInterfaceEventFEur_CxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euEGMT_onDeviceErrorEventFEur_DeviceErrorData)
        , INIT_EGRABBER_FN(dll, euEGMT_onCxpDeviceEventFEur_CxpDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_onRemoteDeviceEventFEur_RemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEGMT_getLastEventGrabberIndex)
        , INIT_EGRABBER_FN(dll, euEGMT_shutdown)
        , INIT_EGRABBER_FN(dll, euEGMT_pushFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euEGMT_announceBusBufferFu64svp)
        , INIT_EGRABBER_FN(dll, euEGMT_announceBusBufferFu64s)
        , INIT_EGRABBER_FN(dll, euEGMT_announceNvidiaRdmaBufferFvpsvp)
        , INIT_EGRABBER_FN(dll, euEGMT_announceNvidiaRdmaBufferFvps)
        , INIT_EGRABBER_FN(dll, euEGMT_getSystemPortFi)
        , INIT_EGRABBER_FN(dll, euEGMT_getInterfacePortFi)
        , INIT_EGRABBER_FN(dll, euEGMT_getDevicePortFi)
        , INIT_EGRABBER_FN(dll, euEGMT_getStreamPortFi)
        , INIT_EGRABBER_FN(dll, euEGMT_getRemotePortFi)
        , INIT_EGRABBER_FN(dll, euEGMT_destroy)
        , INIT_EGRABBER_FN(dll, euEGMT_setNewBufferEventCallbackF_NBECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setIoToolboxEventCallbackF_ITECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setCicEventCallbackF_CECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setDataStreamEventCallbackF_DSECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setCxpInterfaceEventCallbackF_CIECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setDeviceErrorEventCallbackF_DEECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setCxpDeviceEventCallbackF_CDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setRemoteDeviceEventCallbackF_RDECallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setScriptUiCallbackFScriptUiCallbackvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setThreadStartCallbackF_TStartCvp)
        , INIT_EGRABBER_FN(dll, euEGMT_setThreadStopCallbackF_TStopCvp)
        , INIT_EGRABBER_FN(dll, euEGMT_createFEur_EGenTLTHIHDHDH)
        {}
        virtual ~EGrabberDllClassEGrabberMT()
        {}

    public:
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLiiiDAFb8);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLiiiDAF);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLiii);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLii);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLi);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTL);
        DECL_EGRABBER_FN(euEGMT_createFEurEGInfoDAFb8);
        DECL_EGRABBER_FN(euEGMT_createFEurEGInfoDAF);
        DECL_EGRABBER_FN(euEGMT_createFEurEGInfo);
        DECL_EGRABBER_FN(euEGMT_createFEurEGCameraInfoDAF);
        DECL_EGRABBER_FN(euEGMT_createFEurEGCameraInfo);
        DECL_EGRABBER_FN(euEGMT_reallocBuffersFss);
        DECL_EGRABBER_FN(euEGMT_reallocBuffersFs);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_GenTLMemorys);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_GenTLMemory);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_UserMemory);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_UserMemoryArray);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_UserMemoryArrayb8);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_BusMemory);
        DECL_EGRABBER_FN(euEGMT_announceAndQueueFEur_NvidiaRdmaMemory);
        DECL_EGRABBER_FN(euEGMT_flushBuffersFAQT);
        DECL_EGRABBER_FN(euEGMT_flushBuffers);
        DECL_EGRABBER_FN(euEGMT_resetBufferQueue);
        DECL_EGRABBER_FN(euEGMT_resetBufferQueueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGMT_queueFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGMT_revokeFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euEGMT_shouldReannounceBuffers);
        DECL_EGRABBER_FN(euEGMT_shouldReallocBuffers);
        DECL_EGRABBER_FN(euEGMT_startFu64b8);
        DECL_EGRABBER_FN(euEGMT_startFu64);
        DECL_EGRABBER_FN(euEGMT_start);
        DECL_EGRABBER_FN(euEGMT_stop);
        DECL_EGRABBER_FN(euEGMT_getWidth);
        DECL_EGRABBER_FN(euEGMT_getHeight);
        DECL_EGRABBER_FN(euEGMT_getPayloadSize);
        DECL_EGRABBER_FN(euEGMT_getPixelFormat);
        DECL_EGRABBER_FN(euEGMT_getInfoAsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu16OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu32OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu64OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAdOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAfOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8pOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASsOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAvptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASvcOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASv_std_stringOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAb8OSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAcptrOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoA_CINFOOSystemModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu16OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu32OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu64OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAdOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAfOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8pOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASsOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAvptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASvcOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASv_std_stringOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAb8OInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAcptrOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoA_CINFOOInterfaceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu16ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu32ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu64ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAdODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAfODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8pODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASsODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAvptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASvcODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASv_std_stringODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAb8ODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAcptrODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoA_CINFOODeviceModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAi64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu16OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu32OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu64OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAdOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAfOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAu8pOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASsOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAvptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASvcOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoASv_std_stringOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAb8OStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoAcptrOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getInfoA_CINFOOStreamModuleFi32);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAsFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAi8FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAi16FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAi32FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAi64FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAu8FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAu16FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAu32FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAu64FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAdFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAfFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAu8pFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoASsFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAvptrFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoASvcFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoASv_std_stringFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAb8FsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoAcptrFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferInfoA_CINFOFsBIC);
        DECL_EGRABBER_FN(euEGMT_getBufferDataFs);
        DECL_EGRABBER_FN(euEGMT_isOpenOSystemModule);
        DECL_EGRABBER_FN(euEGMT_isOpenOInterfaceModule);
        DECL_EGRABBER_FN(euEGMT_isOpenODeviceModule);
        DECL_EGRABBER_FN(euEGMT_isOpenOStreamModule);
        DECL_EGRABBER_FN(euEGMT_isOpenORemoteModule);
        DECL_EGRABBER_FN(euEGMT_gcReadPortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcReadPortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcReadPortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcReadPortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcReadPortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcWritePortDataOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcWritePortDataOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcWritePortDataODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcWritePortDataOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcWritePortDataORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_gcReadPortOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortOSystemModuleFu64Svc);
        DECL_EGRABBER_FN(euEGMT_gcWritePortOInterfaceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGMT_gcWritePortODeviceModuleFu64Svc);
        DECL_EGRABBER_FN(euEGMT_gcWritePortOStreamModuleFu64Svc);
        DECL_EGRABBER_FN(euEGMT_gcWritePortORemoteModuleFu64Svc);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu16OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu32OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu64OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAdOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAfOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8pOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASsOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAvptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASvcOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASv_std_stringOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAb8OSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAcptrOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueA_CINFOOSystemModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu16OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu32OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu64OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAdOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAfOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8pOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASsOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAvptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASvcOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASv_std_stringOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAb8OInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAcptrOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueA_CINFOOInterfaceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu16ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu32ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu64ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAdODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAfODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8pODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASsODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAvptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASvcODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASv_std_stringODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAb8ODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAcptrODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueA_CINFOODeviceModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu16OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu32OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu64OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAdOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAfOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8pOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASsOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAvptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASvcOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASv_std_stringOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAb8OStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAcptrOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueA_CINFOOStreamModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAi64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu16ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu32ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu64ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAdORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAfORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAu8pORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASsORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAvptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASvcORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueASv_std_stringORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAb8ORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueAcptrORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcReadPortValueA_CINFOORemoteModuleFu64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWsOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi8OSystemModuleFu64i8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi16OSystemModuleFu64i16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi32OSystemModuleFu64i32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi64OSystemModuleFu64i64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu8OSystemModuleFu64u8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu16OSystemModuleFu64u16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu32OSystemModuleFu64u32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu64OSystemModuleFu64u64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWdOSystemModuleFu64d);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWfOSystemModuleFu64f);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWsOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi8OInterfaceModuleFu64i8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi16OInterfaceModuleFu64i16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi32OInterfaceModuleFu64i32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi64OInterfaceModuleFu64i64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu8OInterfaceModuleFu64u8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu16OInterfaceModuleFu64u16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu32OInterfaceModuleFu64u32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu64OInterfaceModuleFu64u64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWdOInterfaceModuleFu64d);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWfOInterfaceModuleFu64f);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWsODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi8ODeviceModuleFu64i8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi16ODeviceModuleFu64i16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi32ODeviceModuleFu64i32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi64ODeviceModuleFu64i64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu8ODeviceModuleFu64u8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu16ODeviceModuleFu64u16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu32ODeviceModuleFu64u32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu64ODeviceModuleFu64u64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWdODeviceModuleFu64d);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWfODeviceModuleFu64f);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWsOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi8OStreamModuleFu64i8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi16OStreamModuleFu64i16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi32OStreamModuleFu64i32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi64OStreamModuleFu64i64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu8OStreamModuleFu64u8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu16OStreamModuleFu64u16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu32OStreamModuleFu64u32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu64OStreamModuleFu64u64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWdOStreamModuleFu64d);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWfOStreamModuleFu64f);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWsORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi8ORemoteModuleFu64i8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi16ORemoteModuleFu64i16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi32ORemoteModuleFu64i32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWi64ORemoteModuleFu64i64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu8ORemoteModuleFu64u8);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu16ORemoteModuleFu64u16);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu32ORemoteModuleFu64u32);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWu64ORemoteModuleFu64u64);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWdORemoteModuleFu64d);
        DECL_EGRABBER_FN(euEGMT_gcWritePortValueWfORemoteModuleFu64f);
        DECL_EGRABBER_FN(euEGMT_gcReadPortStringOSystemModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortStringOInterfaceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortStringODeviceModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortStringOStreamModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_gcReadPortStringORemoteModuleFu64s);
        DECL_EGRABBER_FN(euEGMT_getIntegerOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getIntegerOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getIntegerODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getIntegerOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getIntegerORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getFloatOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getFloatOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getFloatODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getFloatOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getFloatORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringDataOSystemModuleFccpSvc);
        DECL_EGRABBER_FN(euEGMT_getStringDataOInterfaceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGMT_getStringDataODeviceModuleFccpSvc);
        DECL_EGRABBER_FN(euEGMT_getStringDataOStreamModuleFccpSvc);
        DECL_EGRABBER_FN(euEGMT_getStringDataORemoteModuleFccpSvc);
        DECL_EGRABBER_FN(euEGMT_getStringListOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringListOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringListODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringListOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getStringListORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_getRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_getRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_getRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_getRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_getRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_setIntegerOSystemModuleFccpi64);
        DECL_EGRABBER_FN(euEGMT_setIntegerOInterfaceModuleFccpi64);
        DECL_EGRABBER_FN(euEGMT_setIntegerODeviceModuleFccpi64);
        DECL_EGRABBER_FN(euEGMT_setIntegerOStreamModuleFccpi64);
        DECL_EGRABBER_FN(euEGMT_setIntegerORemoteModuleFccpi64);
        DECL_EGRABBER_FN(euEGMT_setFloatOSystemModuleFccpd);
        DECL_EGRABBER_FN(euEGMT_setFloatOInterfaceModuleFccpd);
        DECL_EGRABBER_FN(euEGMT_setFloatODeviceModuleFccpd);
        DECL_EGRABBER_FN(euEGMT_setFloatOStreamModuleFccpd);
        DECL_EGRABBER_FN(euEGMT_setFloatORemoteModuleFccpd);
        DECL_EGRABBER_FN(euEGMT_setStringOSystemModuleFccpccp);
        DECL_EGRABBER_FN(euEGMT_setStringOInterfaceModuleFccpccp);
        DECL_EGRABBER_FN(euEGMT_setStringODeviceModuleFccpccp);
        DECL_EGRABBER_FN(euEGMT_setStringOStreamModuleFccpccp);
        DECL_EGRABBER_FN(euEGMT_setStringORemoteModuleFccpccp);
        DECL_EGRABBER_FN(euEGMT_setRegisterOSystemModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_setRegisterOInterfaceModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_setRegisterODeviceModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_setRegisterOStreamModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_setRegisterORemoteModuleFccpvps);
        DECL_EGRABBER_FN(euEGMT_executeOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_executeOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_executeODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_executeOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_executeORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_attachEventOSystemModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_attachEventOInterfaceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_attachEventODeviceModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_attachEventOStreamModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_attachEventORemoteModuleFu64vps);
        DECL_EGRABBER_FN(euEGMT_invalidateOSystemModuleFccp);
        DECL_EGRABBER_FN(euEGMT_invalidateOInterfaceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_invalidateODeviceModuleFccp);
        DECL_EGRABBER_FN(euEGMT_invalidateOStreamModuleFccp);
        DECL_EGRABBER_FN(euEGMT_invalidateORemoteModuleFccp);
        DECL_EGRABBER_FN(euEGMT_runScriptFccpvp);
        DECL_EGRABBER_FN(euEGMT_runScriptFccp);
        DECL_EGRABBER_FN(euEGMT_interruptScriptFccp);
        DECL_EGRABBER_FN(euEGMT_onScriptUiCallbackFccpvpSm_std_string_std_stringSs);
        DECL_EGRABBER_FN(euEGMT_mementoFccp);
        DECL_EGRABBER_FN(euEGMT_mementoFucucccp);
        DECL_EGRABBER_FN(euEGMT_mementoWaveUpFucuc);
        DECL_EGRABBER_FN(euEGMT_mementoWaveDownFucuc);
        DECL_EGRABBER_FN(euEGMT_mementoWaveResetFucuc);
        DECL_EGRABBER_FN(euEGMT_mementoWaveValueFucucu64);
        DECL_EGRABBER_FN(euEGMT_mementoWaveNoValueFucuc);
        DECL_EGRABBER_FN(euEGMT_enableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGMT_enableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGMT_enableEventWCicData);
        DECL_EGRABBER_FN(euEGMT_enableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGMT_enableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGMT_enableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGMT_enableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGMT_enableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGMT_enableEventWAll);
        DECL_EGRABBER_FN(euEGMT_disableEventWNewBufferData);
        DECL_EGRABBER_FN(euEGMT_disableEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGMT_disableEventWCicData);
        DECL_EGRABBER_FN(euEGMT_disableEventWDataStreamData);
        DECL_EGRABBER_FN(euEGMT_disableEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGMT_disableEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGMT_disableEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGMT_disableEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGMT_disableEventWAll);
        DECL_EGRABBER_FN(euEGMT_flushEventWNewBufferData);
        DECL_EGRABBER_FN(euEGMT_flushEventWIoToolboxData);
        DECL_EGRABBER_FN(euEGMT_flushEventWCicData);
        DECL_EGRABBER_FN(euEGMT_flushEventWDataStreamData);
        DECL_EGRABBER_FN(euEGMT_flushEventWCxpInterfaceData);
        DECL_EGRABBER_FN(euEGMT_flushEventWDeviceErrorData);
        DECL_EGRABBER_FN(euEGMT_flushEventWCxpDeviceData);
        DECL_EGRABBER_FN(euEGMT_flushEventWRemoteDeviceData);
        DECL_EGRABBER_FN(euEGMT_flushEventWAll);
        DECL_EGRABBER_FN(euEGMT_onNewBufferEventFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGMT_onIoToolboxEventFEur_IoToolboxData);
        DECL_EGRABBER_FN(euEGMT_onCicEventFEur_CicData);
        DECL_EGRABBER_FN(euEGMT_onDataStreamEventFEur_DataStreamData);
        DECL_EGRABBER_FN(euEGMT_onCxpInterfaceEventFEur_CxpInterfaceData);
        DECL_EGRABBER_FN(euEGMT_onDeviceErrorEventFEur_DeviceErrorData);
        DECL_EGRABBER_FN(euEGMT_onCxpDeviceEventFEur_CxpDeviceData);
        DECL_EGRABBER_FN(euEGMT_onRemoteDeviceEventFEur_RemoteDeviceData);
        DECL_EGRABBER_FN(euEGMT_getLastEventGrabberIndex);
        DECL_EGRABBER_FN(euEGMT_shutdown);
        DECL_EGRABBER_FN(euEGMT_pushFEur_NewBufferData);
        DECL_EGRABBER_FN(euEGMT_announceBusBufferFu64svp);
        DECL_EGRABBER_FN(euEGMT_announceBusBufferFu64s);
        DECL_EGRABBER_FN(euEGMT_announceNvidiaRdmaBufferFvpsvp);
        DECL_EGRABBER_FN(euEGMT_announceNvidiaRdmaBufferFvps);
        DECL_EGRABBER_FN(euEGMT_getSystemPortFi);
        DECL_EGRABBER_FN(euEGMT_getInterfacePortFi);
        DECL_EGRABBER_FN(euEGMT_getDevicePortFi);
        DECL_EGRABBER_FN(euEGMT_getStreamPortFi);
        DECL_EGRABBER_FN(euEGMT_getRemotePortFi);
        DECL_EGRABBER_FN(euEGMT_destroy);
        DECL_EGRABBER_FN(euEGMT_setNewBufferEventCallbackF_NBECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setIoToolboxEventCallbackF_ITECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setCicEventCallbackF_CECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setDataStreamEventCallbackF_DSECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setCxpInterfaceEventCallbackF_CIECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setDeviceErrorEventCallbackF_DEECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setCxpDeviceEventCallbackF_CDECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setRemoteDeviceEventCallbackF_RDECallbackvp);
        DECL_EGRABBER_FN(euEGMT_setScriptUiCallbackFScriptUiCallbackvp);
        DECL_EGRABBER_FN(euEGMT_setThreadStartCallbackF_TStartCvp);
        DECL_EGRABBER_FN(euEGMT_setThreadStopCallbackF_TStopCvp);
        DECL_EGRABBER_FN(euEGMT_createFEur_EGenTLTHIHDHDH);
};

class EGrabberDllMisc: virtual public EGrabberDllBase {
    protected:
        EGrabberDllMisc(const std::string &path)
        : EGrabberDllBase(path)
        , INIT_EGRABBER_FN(dll, euEurCINFO_get_dataType)
        , INIT_EGRABBER_FN(dll, euEurCINFO_get_dataSize)
        , INIT_EGRABBER_FN(dll, euEurCINFO_destroy)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurCINFOFcInfoCommandInfo_p)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_create)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_destroy)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_create)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_destroy)
        , INIT_EGRABBER_FN(dll, euGenTLMemory_createFsvp)
        , INIT_EGRABBER_FN(dll, euGenTLMemory_createFs)
        , INIT_EGRABBER_FN(dll, euGenTLMemory_create)
        , INIT_EGRABBER_FN(dll, euGenTLMemory_destroy)
        , INIT_EGRABBER_FN(dll, euUserMemory_createFvpsvp)
        , INIT_EGRABBER_FN(dll, euUserMemory_createFvps)
        , INIT_EGRABBER_FN(dll, euUserMemory_destroy)
        , INIT_EGRABBER_FN(dll, euBusMemory_createFu64svp)
        , INIT_EGRABBER_FN(dll, euBusMemory_createFu64s)
        , INIT_EGRABBER_FN(dll, euBusMemory_destroy)
        , INIT_EGRABBER_FN(dll, euNvidiaRdmaMemory_createFvpsvp)
        , INIT_EGRABBER_FN(dll, euNvidiaRdmaMemory_createFvps)
        , INIT_EGRABBER_FN(dll, euNvidiaRdmaMemory_destroy)
        , INIT_EGRABBER_FN(dll, euUserMemoryArray_createFEur_UserMemorys)
        , INIT_EGRABBER_FN(dll, euUserMemoryArray_destroy)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_createFssb8)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_createFss)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_createFs)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_create)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_createFEur_BufferIndexRange)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_indexAtFs)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_size)
        , INIT_EGRABBER_FN(dll, euBufferIndexRange_destroy)
        , INIT_EGRABBER_FN(dll, euNewBufferData_create)
        , INIT_EGRABBER_FN(dll, euNewBufferData_destroy)
        , INIT_EGRABBER_FN(dll, euIoToolboxData_create)
        , INIT_EGRABBER_FN(dll, euIoToolboxData_destroy)
        , INIT_EGRABBER_FN(dll, euCicData_create)
        , INIT_EGRABBER_FN(dll, euCicData_destroy)
        , INIT_EGRABBER_FN(dll, euDataStreamData_create)
        , INIT_EGRABBER_FN(dll, euDataStreamData_destroy)
        , INIT_EGRABBER_FN(dll, euCxpInterfaceData_create)
        , INIT_EGRABBER_FN(dll, euCxpInterfaceData_destroy)
        , INIT_EGRABBER_FN(dll, euDeviceErrorData_create)
        , INIT_EGRABBER_FN(dll, euDeviceErrorData_destroy)
        , INIT_EGRABBER_FN(dll, euCxpDeviceData_create)
        , INIT_EGRABBER_FN(dll, euCxpDeviceData_destroy)
        , INIT_EGRABBER_FN(dll, euRemoteDeviceData_create)
        , INIT_EGRABBER_FN(dll, euRemoteDeviceData_destroy)
        , INIT_EGRABBER_FN(dll, euCoaxlink)
        , INIT_EGRABBER_FN(dll, euGrablink)
        , INIT_EGRABBER_FN(dll, euGigelink)
        , INIT_EGRABBER_FN(dll, euPlaylink)
        , INIT_EGRABBER_FN(dll, euquery_attributes)
        , INIT_EGRABBER_FN(dll, euquery_featuresFb8)
        , INIT_EGRABBER_FN(dll, euquery_features)
        , INIT_EGRABBER_FN(dll, euquery_featuresOfFccpb8)
        , INIT_EGRABBER_FN(dll, euquery_featuresOfFccp)
        , INIT_EGRABBER_FN(dll, euquery_categoriesFb8)
        , INIT_EGRABBER_FN(dll, euquery_categories)
        , INIT_EGRABBER_FN(dll, euquery_categoriesOfFccpb8)
        , INIT_EGRABBER_FN(dll, euquery_categoriesOfFccp)
        , INIT_EGRABBER_FN(dll, euquery_enumEntriesFccpb8)
        , INIT_EGRABBER_FN(dll, euquery_enumEntriesFccp)
        , INIT_EGRABBER_FN(dll, euquery_availableFccp)
        , INIT_EGRABBER_FN(dll, euquery_readableFccp)
        , INIT_EGRABBER_FN(dll, euquery_writeableFccp)
        , INIT_EGRABBER_FN(dll, euquery_implementedFccp)
        , INIT_EGRABBER_FN(dll, euquery_commandFccp)
        , INIT_EGRABBER_FN(dll, euquery_doneFccp)
        , INIT_EGRABBER_FN(dll, euquery_interfacesFccp)
        , INIT_EGRABBER_FN(dll, euquery_sourceFccp)
        , INIT_EGRABBER_FN(dll, euquery_xml)
        , INIT_EGRABBER_FN(dll, euquery_infoFccpccp)
        , INIT_EGRABBER_FN(dll, euquery_declared)
        , INIT_EGRABBER_FN(dll, euaction_declareInteger)
        , INIT_EGRABBER_FN(dll, euaction_declareFloat)
        , INIT_EGRABBER_FN(dll, euaction_declareString)
        , INIT_EGRABBER_FN(dll, euaction_undeclare)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_createFEur_EGenTL)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_discoverFb8)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_discover)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_egrabberCount)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_egrabbersFi)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_cameraCount)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_camerasFii)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_camerasFi)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_camerasFccpi)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_camerasFccp)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_interfaceCount)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_interfaceInfoFi)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_deviceCountFi)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_deviceInfoFii)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_streamCountFii)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_streamInfoFiii)
        , INIT_EGRABBER_FN(dll, euEurEGDiscovery_destroy)
        , INIT_EGRABBER_FN(dll, eugetEventDescriptionFEDNC)
        , INIT_EGRABBER_FN(dll, euBuffer_createFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euBuffer_pushFEurEGBase)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAsFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAi8FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAi16FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAi32FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAi64FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAu8FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAu16FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAu32FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAu64FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAdFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAfFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAu8pFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoASsFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAvptrFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoASvcFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoASv_std_stringFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAb8FEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoAcptrFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoA_CINFOFEurEGBaseBIC)
        , INIT_EGRABBER_FN(dll, euBuffer_getUserPointer)
        , INIT_EGRABBER_FN(dll, euBuffer_saveToDiskFEurEGBaseccpi64_ISTDP_p)
        , INIT_EGRABBER_FN(dll, euBuffer_saveToDiskFEurEGBaseccpi64)
        , INIT_EGRABBER_FN(dll, euBuffer_saveToDiskFEurEGBaseccp)
        , INIT_EGRABBER_FN(dll, euBuffer_getInfoFEurEGBase)
        , INIT_EGRABBER_FN(dll, euBuffer_destroy)
        , INIT_EGRABBER_FN(dll, eucti_loading_error_createFccp)
        , INIT_EGRABBER_FN(dll, eucti_loading_error_destroy)
        , INIT_EGRABBER_FN(dll, eumissing_gentl_symbol_createFccpccp)
        , INIT_EGRABBER_FN(dll, eumissing_gentl_symbol_destroy)
        , INIT_EGRABBER_FN(dll, euunexpected_data_type_createFID)
        , INIT_EGRABBER_FN(dll, euunexpected_data_type_destroy)
        , INIT_EGRABBER_FN(dll, euunexpected_data_size_createFss)
        , INIT_EGRABBER_FN(dll, euunexpected_data_size_destroy)
        , INIT_EGRABBER_FN(dll, euclient_error_createFccp)
        , INIT_EGRABBER_FN(dll, euclient_error_destroy)
        , INIT_EGRABBER_FN(dll, eugentl_error_createFGE)
        , INIT_EGRABBER_FN(dll, eugentl_error_createFGEccp)
        , INIT_EGRABBER_FN(dll, eugentl_error_destroy)
        , INIT_EGRABBER_FN(dll, eugenapi_error_createFGEC)
        , INIT_EGRABBER_FN(dll, eugenapi_error_parameter_count)
        , INIT_EGRABBER_FN(dll, eugenapi_error_parameter_typeFs)
        , INIT_EGRABBER_FN(dll, eugenapi_error_string_parameterFs)
        , INIT_EGRABBER_FN(dll, eugenapi_error_integer_parameterFs)
        , INIT_EGRABBER_FN(dll, eugenapi_error_float_parameterFs)
        , INIT_EGRABBER_FN(dll, eugenapi_error_add_string_parameterFcp)
        , INIT_EGRABBER_FN(dll, eugenapi_error_add_integer_parameterFi64)
        , INIT_EGRABBER_FN(dll, eugenapi_error_add_float_parameterFd)
        , INIT_EGRABBER_FN(dll, eugenapi_error_destroy)
        , INIT_EGRABBER_FN(dll, euthread_error_createFccp)
        , INIT_EGRABBER_FN(dll, euthread_error_destroy)
        , INIT_EGRABBER_FN(dll, euinternal_error_create)
        , INIT_EGRABBER_FN(dll, euinternal_error_destroy)
        , INIT_EGRABBER_FN(dll, eunot_allowed_create)
        , INIT_EGRABBER_FN(dll, eunot_allowed_destroy)
        , INIT_EGRABBER_FN(dll, euEurOOA_create)
        , INIT_EGRABBER_FN(dll, euEurOOA_destroy)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_1)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_2)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_3)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_4)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_5)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_6)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_7)
        , INIT_EGRABBER_FN(dll, euEurOOA_at_position_8)
        , INIT_EGRABBER_FN(dll, eugetEventFilterONewBufferData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterOIoToolboxData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterOCicData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterODataStreamData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterOCxpInterfaceData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterODeviceErrorData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterOCxpDeviceData)
        , INIT_EGRABBER_FN(dll, eugetEventFilterORemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_interfaceIndex)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceIndex)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_streamIndex)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_interfaceID)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceID)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_streamID)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceVendorName)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceModelName)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceDescription)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_streamDescription)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceUserID)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceSerialNumber)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_deviceLicenseStatus)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_tlType)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_firmwareStatus)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_fanStatus)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_licenseStatus)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_isRemoteAvailable)
        , INIT_EGRABBER_FN(dll, euEurEGInfo_get_isDeviceReadOnly)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_grabber_count)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_grabber_atFs)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_grabbers_push_backFEurEGInfo)
        , INIT_EGRABBER_FN(dll, euEurEGCameraInfo_get_script)
        , INIT_EGRABBER_FN(dll, euECameraBufferPush_CallbackOnDemandFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAi8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAi16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAi32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAi64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAu8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAu16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAu32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAu64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAdFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAfFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAu8pFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandASsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAvptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandASvcFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandASv_std_stringFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAb8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandAcptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandA_CINFOFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackOnDemandFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euECameraBufferPush_CallbackSingleThreadFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAi8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAi16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAi32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAi64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAu8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAu16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAu32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAu64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAdFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAfFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAu8pFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadASsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAvptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadASvcFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadASv_std_stringFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAb8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadAcptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadA_CINFOFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackSingleThreadFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euECameraBufferPush_CallbackMultiThreadFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAi8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAi16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAi32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAi64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAu8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAu16FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAu32FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAu64FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAdFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAfFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAu8pFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadASsFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAvptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadASvcFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadASv_std_stringFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAb8FEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadAcptrFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadA_CINFOFEur_NewBufferDataBIC)
        , INIT_EGRABBER_FN(dll, euECameraBufferGetInfo_CallbackMultiThreadFEur_NewBufferData)
        , INIT_EGRABBER_FN(dll, euaction_GenApiActionyBuilder_destroy)
        , INIT_EGRABBER_FN(dll, euaction_GenApiActionBuilder_destroy)
        , INIT_EGRABBER_FN(dll, euaction_GenApiActionBuilder_string)
        , INIT_EGRABBER_FN(dll, euquery_GenApiQueryBuilder_destroy)
        , INIT_EGRABBER_FN(dll, euquery_GenApiQueryBuilder_string)
        , INIT_EGRABBER_FN(dll, euquery_GenApiQueryBuilder_globFccp)
        , INIT_EGRABBER_FN(dll, euquery_GenApiQueryBuilder_regexFccp)
        , INIT_EGRABBER_FN(dll, eugetEuresysCtiPath)
        , INIT_EGRABBER_FN(dll, euBufferInfo_destroy)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_BufferInfoFcBufferInfo_p)
        , INIT_EGRABBER_FN(dll, eustd_string_create)
        , INIT_EGRABBER_FN(dll, eustd_string_destroy)
        , INIT_EGRABBER_FN(dll, eustd_const_string_create)
        , INIT_EGRABBER_FN(dll, eustd_const_string_destroy)
        , INIT_EGRABBER_FN(dll, eustd_string_c_str)
        , INIT_EGRABBER_FN(dll, eustd_string_assignFccp)
        , INIT_EGRABBER_FN(dll, euto_box_std_stringFccps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_stringFccppsp)
        , INIT_EGRABBER_FN(dll, eustd_string_assign_operatorFSs)
        , INIT_EGRABBER_FN(dll, eustd_vector_char_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_char_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_char_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_char_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_char_push_backFc)
        , INIT_EGRABBER_FN(dll, euto_box_std_vector_charFccps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_vector_charFccppsp)
        , INIT_EGRABBER_FN(dll, eustd_vector_std_string_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_std_string_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_std_string_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_std_string_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_EEGDE_push_backFEEGDE)
        , INIT_EGRABBER_FN(dll, euto_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ppsp)
        , INIT_EGRABBER_FN(dll, eustd_vector_BUFFER_HANDLE_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_BUFFER_HANDLE_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_BUFFER_HANDLE_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_BUFFER_HANDLE_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_BH_push_backFBH)
        , INIT_EGRABBER_FN(dll, euto_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ppsp)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_REGISTER_STACK_ENTRY_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_REGISTER_STACK_ENTRY_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_REGISTER_STACK_ENTRY_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_REGISTER_STACK_ENTRY_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_PRSE_push_backFPRSE)
        , INIT_EGRABBER_FN(dll, euto_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ppsp)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_HANDLE_create)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_HANDLE_size)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_HANDLE_destroy)
        , INIT_EGRABBER_FN(dll, eustd_vector_PORT_HANDLE_atFs)
        , INIT_EGRABBER_FN(dll, eustd_vector_PH_push_backFPH)
        , INIT_EGRABBER_FN(dll, euto_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ps)
        , INIT_EGRABBER_FN(dll, eufrom_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ppsp)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_create)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_destroy)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_size)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_atFSm_std_string_std_stringSs)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_atFSs)
        , INIT_EGRABBER_FN(dll, eustd_map_std_string_std_string_atFsSs_pSs_p)
        , INIT_EGRABBER_FN(dll, eustd_runtime_error_createFccp)
        , INIT_EGRABBER_FN(dll, eustd_runtime_error_destroy)
        , INIT_EGRABBER_FN(dll, eustd_runtime_error_what)
        , INIT_EGRABBER_FN(dll, eustd_logic_error_createFccp)
        , INIT_EGRABBER_FN(dll, eustd_logic_error_destroy)
        , INIT_EGRABBER_FN(dll, eustd_logic_error_what)
        , INIT_EGRABBER_FN(dll, eustd_exception_createFccp)
        , INIT_EGRABBER_FN(dll, eustd_exception_destroy)
        , INIT_EGRABBER_FN(dll, eustd_exception_what)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_BufferIndexRangeFspspb8_p)
        , INIT_EGRABBER_FN(dll, euNewBufferDataANewBufferData)
        , INIT_EGRABBER_FN(dll, euIoToolboxDataAIoToolboxData)
        , INIT_EGRABBER_FN(dll, euCicDataACicData)
        , INIT_EGRABBER_FN(dll, euDataStreamDataADataStreamData)
        , INIT_EGRABBER_FN(dll, euCxpInterfaceDataACxpInterfaceData)
        , INIT_EGRABBER_FN(dll, euDeviceErrorDataADeviceErrorData)
        , INIT_EGRABBER_FN(dll, euCxpDeviceDataACxpDeviceData)
        , INIT_EGRABBER_FN(dll, euRemoteDeviceDataARemoteDeviceData)
        , INIT_EGRABBER_FN(dll, euto_box_Eur_NewBufferDataFcst_NewBufferData_s_p)
        , INIT_EGRABBER_FN(dll, euto_box_EurEGInfoFcEGrabberInfo)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurEGInfoFcEGrabberInfo_p)
        , INIT_EGRABBER_FN(dll, euto_box_EurEGInfoFcEGrabberInfoExt1_p)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurEGInfoFcEGrabberInfoExt1_p)
        , INIT_EGRABBER_FN(dll, euto_box_EurEGInfoFcEGrabberInfoExt2_p)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurEGInfoFcEGrabberInfoExt2_p)
        , INIT_EGRABBER_FN(dll, euto_box_EurEGInfoFcEGrabberInfoExt3_p)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurEGInfoFcEGrabberInfoExt3_p)
        , INIT_EGRABBER_FN(dll, euto_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p)
        , INIT_EGRABBER_FN(dll, eufrom_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_genapi_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_genapi_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_cti_loading_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_cti_loading_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_missing_gentl_symbol)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_missing_gentl_symbol)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_unexpected_data_type)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_unexpected_data_type)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_unexpected_data_size)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_unexpected_data_size)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_client_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_client_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_gentl_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_gentl_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_thread_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_thread_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_internal_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_internal_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAEur_not_allowed)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFEur_not_allowed)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAstd_runtime_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFstd_runtime_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAstd_logic_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFstd_logic_error)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getAstd_exception)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setFstd_exception)
        , INIT_EGRABBER_FN(dll, euInternal_lastError_getCode)
        , INIT_EGRABBER_FN(dll, euInternal_lastCallbackError_setCallbackCriticalError)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_cti_loading_error_path)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_missing_gentl_symbol_path)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_missing_gentl_symbol_symbol)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_unexpected_data_type)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_unexpected_data_sizeFspsp)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_gentl_error_gc_err)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_gentl_error_description)
        , INIT_EGRABBER_FN(dll, eufrom_box_Eur_genapi_error)
        , INIT_EGRABBER_FN(dll, eugenapi_error_string_parameterASsFs)
        , INIT_EGRABBER_FN(dll, eucheckAllBoxedTypeCount)
        {}
        virtual ~EGrabberDllMisc()
        {}

    public:
        DECL_EGRABBER_FN(euEurCINFO_get_dataType);
        DECL_EGRABBER_FN(euEurCINFO_get_dataSize);
        DECL_EGRABBER_FN(euEurCINFO_destroy);
        DECL_EGRABBER_FN(eufrom_box_EurCINFOFcInfoCommandInfo_p);
        DECL_EGRABBER_FN(euEurEGInfo_create);
        DECL_EGRABBER_FN(euEurEGInfo_destroy);
        DECL_EGRABBER_FN(euEurEGCameraInfo_create);
        DECL_EGRABBER_FN(euEurEGCameraInfo_destroy);
        DECL_EGRABBER_FN(euGenTLMemory_createFsvp);
        DECL_EGRABBER_FN(euGenTLMemory_createFs);
        DECL_EGRABBER_FN(euGenTLMemory_create);
        DECL_EGRABBER_FN(euGenTLMemory_destroy);
        DECL_EGRABBER_FN(euUserMemory_createFvpsvp);
        DECL_EGRABBER_FN(euUserMemory_createFvps);
        DECL_EGRABBER_FN(euUserMemory_destroy);
        DECL_EGRABBER_FN(euBusMemory_createFu64svp);
        DECL_EGRABBER_FN(euBusMemory_createFu64s);
        DECL_EGRABBER_FN(euBusMemory_destroy);
        DECL_EGRABBER_FN(euNvidiaRdmaMemory_createFvpsvp);
        DECL_EGRABBER_FN(euNvidiaRdmaMemory_createFvps);
        DECL_EGRABBER_FN(euNvidiaRdmaMemory_destroy);
        DECL_EGRABBER_FN(euUserMemoryArray_createFEur_UserMemorys);
        DECL_EGRABBER_FN(euUserMemoryArray_destroy);
        DECL_EGRABBER_FN(euBufferIndexRange_createFssb8);
        DECL_EGRABBER_FN(euBufferIndexRange_createFss);
        DECL_EGRABBER_FN(euBufferIndexRange_createFs);
        DECL_EGRABBER_FN(euBufferIndexRange_create);
        DECL_EGRABBER_FN(euBufferIndexRange_createFEur_BufferIndexRange);
        DECL_EGRABBER_FN(euBufferIndexRange_indexAtFs);
        DECL_EGRABBER_FN(euBufferIndexRange_size);
        DECL_EGRABBER_FN(euBufferIndexRange_destroy);
        DECL_EGRABBER_FN(euNewBufferData_create);
        DECL_EGRABBER_FN(euNewBufferData_destroy);
        DECL_EGRABBER_FN(euIoToolboxData_create);
        DECL_EGRABBER_FN(euIoToolboxData_destroy);
        DECL_EGRABBER_FN(euCicData_create);
        DECL_EGRABBER_FN(euCicData_destroy);
        DECL_EGRABBER_FN(euDataStreamData_create);
        DECL_EGRABBER_FN(euDataStreamData_destroy);
        DECL_EGRABBER_FN(euCxpInterfaceData_create);
        DECL_EGRABBER_FN(euCxpInterfaceData_destroy);
        DECL_EGRABBER_FN(euDeviceErrorData_create);
        DECL_EGRABBER_FN(euDeviceErrorData_destroy);
        DECL_EGRABBER_FN(euCxpDeviceData_create);
        DECL_EGRABBER_FN(euCxpDeviceData_destroy);
        DECL_EGRABBER_FN(euRemoteDeviceData_create);
        DECL_EGRABBER_FN(euRemoteDeviceData_destroy);
        DECL_EGRABBER_FN(euCoaxlink);
        DECL_EGRABBER_FN(euGrablink);
        DECL_EGRABBER_FN(euGigelink);
        DECL_EGRABBER_FN(euPlaylink);
        DECL_EGRABBER_FN(euquery_attributes);
        DECL_EGRABBER_FN(euquery_featuresFb8);
        DECL_EGRABBER_FN(euquery_features);
        DECL_EGRABBER_FN(euquery_featuresOfFccpb8);
        DECL_EGRABBER_FN(euquery_featuresOfFccp);
        DECL_EGRABBER_FN(euquery_categoriesFb8);
        DECL_EGRABBER_FN(euquery_categories);
        DECL_EGRABBER_FN(euquery_categoriesOfFccpb8);
        DECL_EGRABBER_FN(euquery_categoriesOfFccp);
        DECL_EGRABBER_FN(euquery_enumEntriesFccpb8);
        DECL_EGRABBER_FN(euquery_enumEntriesFccp);
        DECL_EGRABBER_FN(euquery_availableFccp);
        DECL_EGRABBER_FN(euquery_readableFccp);
        DECL_EGRABBER_FN(euquery_writeableFccp);
        DECL_EGRABBER_FN(euquery_implementedFccp);
        DECL_EGRABBER_FN(euquery_commandFccp);
        DECL_EGRABBER_FN(euquery_doneFccp);
        DECL_EGRABBER_FN(euquery_interfacesFccp);
        DECL_EGRABBER_FN(euquery_sourceFccp);
        DECL_EGRABBER_FN(euquery_xml);
        DECL_EGRABBER_FN(euquery_infoFccpccp);
        DECL_EGRABBER_FN(euquery_declared);
        DECL_EGRABBER_FN(euaction_declareInteger);
        DECL_EGRABBER_FN(euaction_declareFloat);
        DECL_EGRABBER_FN(euaction_declareString);
        DECL_EGRABBER_FN(euaction_undeclare);
        DECL_EGRABBER_FN(euEurEGDiscovery_createFEur_EGenTL);
        DECL_EGRABBER_FN(euEurEGDiscovery_discoverFb8);
        DECL_EGRABBER_FN(euEurEGDiscovery_discover);
        DECL_EGRABBER_FN(euEurEGDiscovery_egrabberCount);
        DECL_EGRABBER_FN(euEurEGDiscovery_egrabbersFi);
        DECL_EGRABBER_FN(euEurEGDiscovery_cameraCount);
        DECL_EGRABBER_FN(euEurEGDiscovery_camerasFii);
        DECL_EGRABBER_FN(euEurEGDiscovery_camerasFi);
        DECL_EGRABBER_FN(euEurEGDiscovery_camerasFccpi);
        DECL_EGRABBER_FN(euEurEGDiscovery_camerasFccp);
        DECL_EGRABBER_FN(euEurEGDiscovery_interfaceCount);
        DECL_EGRABBER_FN(euEurEGDiscovery_interfaceInfoFi);
        DECL_EGRABBER_FN(euEurEGDiscovery_deviceCountFi);
        DECL_EGRABBER_FN(euEurEGDiscovery_deviceInfoFii);
        DECL_EGRABBER_FN(euEurEGDiscovery_streamCountFii);
        DECL_EGRABBER_FN(euEurEGDiscovery_streamInfoFiii);
        DECL_EGRABBER_FN(euEurEGDiscovery_destroy);
        DECL_EGRABBER_FN(eugetEventDescriptionFEDNC);
        DECL_EGRABBER_FN(euBuffer_createFEur_NewBufferData);
        DECL_EGRABBER_FN(euBuffer_pushFEurEGBase);
        DECL_EGRABBER_FN(euBuffer_getInfoAsFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAi8FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAi16FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAi32FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAi64FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAu8FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAu16FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAu32FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAu64FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAdFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAfFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAu8pFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoASsFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAvptrFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoASvcFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoASv_std_stringFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAb8FEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoAcptrFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getInfoA_CINFOFEurEGBaseBIC);
        DECL_EGRABBER_FN(euBuffer_getUserPointer);
        DECL_EGRABBER_FN(euBuffer_saveToDiskFEurEGBaseccpi64_ISTDP_p);
        DECL_EGRABBER_FN(euBuffer_saveToDiskFEurEGBaseccpi64);
        DECL_EGRABBER_FN(euBuffer_saveToDiskFEurEGBaseccp);
        DECL_EGRABBER_FN(euBuffer_getInfoFEurEGBase);
        DECL_EGRABBER_FN(euBuffer_destroy);
        DECL_EGRABBER_FN(eucti_loading_error_createFccp);
        DECL_EGRABBER_FN(eucti_loading_error_destroy);
        DECL_EGRABBER_FN(eumissing_gentl_symbol_createFccpccp);
        DECL_EGRABBER_FN(eumissing_gentl_symbol_destroy);
        DECL_EGRABBER_FN(euunexpected_data_type_createFID);
        DECL_EGRABBER_FN(euunexpected_data_type_destroy);
        DECL_EGRABBER_FN(euunexpected_data_size_createFss);
        DECL_EGRABBER_FN(euunexpected_data_size_destroy);
        DECL_EGRABBER_FN(euclient_error_createFccp);
        DECL_EGRABBER_FN(euclient_error_destroy);
        DECL_EGRABBER_FN(eugentl_error_createFGE);
        DECL_EGRABBER_FN(eugentl_error_createFGEccp);
        DECL_EGRABBER_FN(eugentl_error_destroy);
        DECL_EGRABBER_FN(eugenapi_error_createFGEC);
        DECL_EGRABBER_FN(eugenapi_error_parameter_count);
        DECL_EGRABBER_FN(eugenapi_error_parameter_typeFs);
        DECL_EGRABBER_FN(eugenapi_error_string_parameterFs);
        DECL_EGRABBER_FN(eugenapi_error_integer_parameterFs);
        DECL_EGRABBER_FN(eugenapi_error_float_parameterFs);
        DECL_EGRABBER_FN(eugenapi_error_add_string_parameterFcp);
        DECL_EGRABBER_FN(eugenapi_error_add_integer_parameterFi64);
        DECL_EGRABBER_FN(eugenapi_error_add_float_parameterFd);
        DECL_EGRABBER_FN(eugenapi_error_destroy);
        DECL_EGRABBER_FN(euthread_error_createFccp);
        DECL_EGRABBER_FN(euthread_error_destroy);
        DECL_EGRABBER_FN(euinternal_error_create);
        DECL_EGRABBER_FN(euinternal_error_destroy);
        DECL_EGRABBER_FN(eunot_allowed_create);
        DECL_EGRABBER_FN(eunot_allowed_destroy);
        DECL_EGRABBER_FN(euEurOOA_create);
        DECL_EGRABBER_FN(euEurOOA_destroy);
        DECL_EGRABBER_FN(euEurOOA_at_position_1);
        DECL_EGRABBER_FN(euEurOOA_at_position_2);
        DECL_EGRABBER_FN(euEurOOA_at_position_3);
        DECL_EGRABBER_FN(euEurOOA_at_position_4);
        DECL_EGRABBER_FN(euEurOOA_at_position_5);
        DECL_EGRABBER_FN(euEurOOA_at_position_6);
        DECL_EGRABBER_FN(euEurOOA_at_position_7);
        DECL_EGRABBER_FN(euEurOOA_at_position_8);
        DECL_EGRABBER_FN(eugetEventFilterONewBufferData);
        DECL_EGRABBER_FN(eugetEventFilterOIoToolboxData);
        DECL_EGRABBER_FN(eugetEventFilterOCicData);
        DECL_EGRABBER_FN(eugetEventFilterODataStreamData);
        DECL_EGRABBER_FN(eugetEventFilterOCxpInterfaceData);
        DECL_EGRABBER_FN(eugetEventFilterODeviceErrorData);
        DECL_EGRABBER_FN(eugetEventFilterOCxpDeviceData);
        DECL_EGRABBER_FN(eugetEventFilterORemoteDeviceData);
        DECL_EGRABBER_FN(euEurEGInfo_get_interfaceIndex);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceIndex);
        DECL_EGRABBER_FN(euEurEGInfo_get_streamIndex);
        DECL_EGRABBER_FN(euEurEGInfo_get_interfaceID);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceID);
        DECL_EGRABBER_FN(euEurEGInfo_get_streamID);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceVendorName);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceModelName);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceDescription);
        DECL_EGRABBER_FN(euEurEGInfo_get_streamDescription);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceUserID);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceSerialNumber);
        DECL_EGRABBER_FN(euEurEGInfo_get_deviceLicenseStatus);
        DECL_EGRABBER_FN(euEurEGInfo_get_tlType);
        DECL_EGRABBER_FN(euEurEGInfo_get_firmwareStatus);
        DECL_EGRABBER_FN(euEurEGInfo_get_fanStatus);
        DECL_EGRABBER_FN(euEurEGInfo_get_licenseStatus);
        DECL_EGRABBER_FN(euEurEGInfo_get_isRemoteAvailable);
        DECL_EGRABBER_FN(euEurEGInfo_get_isDeviceReadOnly);
        DECL_EGRABBER_FN(euEurEGCameraInfo_grabber_count);
        DECL_EGRABBER_FN(euEurEGCameraInfo_grabber_atFs);
        DECL_EGRABBER_FN(euEurEGCameraInfo_grabbers_push_backFEurEGInfo);
        DECL_EGRABBER_FN(euEurEGCameraInfo_get_script);
        DECL_EGRABBER_FN(euECameraBufferPush_CallbackOnDemandFEur_NewBufferData);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAi8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAi16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAi32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAi64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAu8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAu16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAu32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAu64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAdFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAfFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAu8pFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandASsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAvptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandASvcFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandASv_std_stringFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAb8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandAcptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandA_CINFOFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackOnDemandFEur_NewBufferData);
        DECL_EGRABBER_FN(euECameraBufferPush_CallbackSingleThreadFEur_NewBufferData);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAi8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAi16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAi32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAi64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAu8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAu16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAu32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAu64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAdFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAfFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAu8pFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadASsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAvptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadASvcFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadASv_std_stringFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAb8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadAcptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadA_CINFOFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackSingleThreadFEur_NewBufferData);
        DECL_EGRABBER_FN(euECameraBufferPush_CallbackMultiThreadFEur_NewBufferData);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAi8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAi16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAi32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAi64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAu8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAu16FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAu32FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAu64FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAdFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAfFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAu8pFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadASsFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAvptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadASvcFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadASv_std_stringFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAb8FEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadAcptrFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadA_CINFOFEur_NewBufferDataBIC);
        DECL_EGRABBER_FN(euECameraBufferGetInfo_CallbackMultiThreadFEur_NewBufferData);
        DECL_EGRABBER_FN(euaction_GenApiActionyBuilder_destroy);
        DECL_EGRABBER_FN(euaction_GenApiActionBuilder_destroy);
        DECL_EGRABBER_FN(euaction_GenApiActionBuilder_string);
        DECL_EGRABBER_FN(euquery_GenApiQueryBuilder_destroy);
        DECL_EGRABBER_FN(euquery_GenApiQueryBuilder_string);
        DECL_EGRABBER_FN(euquery_GenApiQueryBuilder_globFccp);
        DECL_EGRABBER_FN(euquery_GenApiQueryBuilder_regexFccp);
        DECL_EGRABBER_FN(eugetEuresysCtiPath);
        DECL_EGRABBER_FN(euBufferInfo_destroy);
        DECL_EGRABBER_FN(eufrom_box_Eur_BufferInfoFcBufferInfo_p);
        DECL_EGRABBER_FN(eustd_string_create);
        DECL_EGRABBER_FN(eustd_string_destroy);
        DECL_EGRABBER_FN(eustd_const_string_create);
        DECL_EGRABBER_FN(eustd_const_string_destroy);
        DECL_EGRABBER_FN(eustd_string_c_str);
        DECL_EGRABBER_FN(eustd_string_assignFccp);
        DECL_EGRABBER_FN(euto_box_std_stringFccps);
        DECL_EGRABBER_FN(eufrom_box_std_stringFccppsp);
        DECL_EGRABBER_FN(eustd_string_assign_operatorFSs);
        DECL_EGRABBER_FN(eustd_vector_char_create);
        DECL_EGRABBER_FN(eustd_vector_char_size);
        DECL_EGRABBER_FN(eustd_vector_char_destroy);
        DECL_EGRABBER_FN(eustd_vector_char_atFs);
        DECL_EGRABBER_FN(eustd_vector_char_push_backFc);
        DECL_EGRABBER_FN(euto_box_std_vector_charFccps);
        DECL_EGRABBER_FN(eufrom_box_std_vector_charFccppsp);
        DECL_EGRABBER_FN(eustd_vector_std_string_create);
        DECL_EGRABBER_FN(eustd_vector_std_string_size);
        DECL_EGRABBER_FN(eustd_vector_std_string_destroy);
        DECL_EGRABBER_FN(eustd_vector_std_string_atFs);
        DECL_EGRABBER_FN(eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_create);
        DECL_EGRABBER_FN(eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_size);
        DECL_EGRABBER_FN(eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_destroy);
        DECL_EGRABBER_FN(eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_atFs);
        DECL_EGRABBER_FN(eustd_vector_EEGDE_push_backFEEGDE);
        DECL_EGRABBER_FN(euto_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ps);
        DECL_EGRABBER_FN(eufrom_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ppsp);
        DECL_EGRABBER_FN(eustd_vector_BUFFER_HANDLE_create);
        DECL_EGRABBER_FN(eustd_vector_BUFFER_HANDLE_size);
        DECL_EGRABBER_FN(eustd_vector_BUFFER_HANDLE_destroy);
        DECL_EGRABBER_FN(eustd_vector_BUFFER_HANDLE_atFs);
        DECL_EGRABBER_FN(eustd_vector_BH_push_backFBH);
        DECL_EGRABBER_FN(euto_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ps);
        DECL_EGRABBER_FN(eufrom_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ppsp);
        DECL_EGRABBER_FN(eustd_vector_PORT_REGISTER_STACK_ENTRY_create);
        DECL_EGRABBER_FN(eustd_vector_PORT_REGISTER_STACK_ENTRY_size);
        DECL_EGRABBER_FN(eustd_vector_PORT_REGISTER_STACK_ENTRY_destroy);
        DECL_EGRABBER_FN(eustd_vector_PORT_REGISTER_STACK_ENTRY_atFs);
        DECL_EGRABBER_FN(eustd_vector_PRSE_push_backFPRSE);
        DECL_EGRABBER_FN(euto_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ps);
        DECL_EGRABBER_FN(eufrom_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ppsp);
        DECL_EGRABBER_FN(eustd_vector_PORT_HANDLE_create);
        DECL_EGRABBER_FN(eustd_vector_PORT_HANDLE_size);
        DECL_EGRABBER_FN(eustd_vector_PORT_HANDLE_destroy);
        DECL_EGRABBER_FN(eustd_vector_PORT_HANDLE_atFs);
        DECL_EGRABBER_FN(eustd_vector_PH_push_backFPH);
        DECL_EGRABBER_FN(euto_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ps);
        DECL_EGRABBER_FN(eufrom_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ppsp);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_create);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_destroy);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_size);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_atFSm_std_string_std_stringSs);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_atFSs);
        DECL_EGRABBER_FN(eustd_map_std_string_std_string_atFsSs_pSs_p);
        DECL_EGRABBER_FN(eustd_runtime_error_createFccp);
        DECL_EGRABBER_FN(eustd_runtime_error_destroy);
        DECL_EGRABBER_FN(eustd_runtime_error_what);
        DECL_EGRABBER_FN(eustd_logic_error_createFccp);
        DECL_EGRABBER_FN(eustd_logic_error_destroy);
        DECL_EGRABBER_FN(eustd_logic_error_what);
        DECL_EGRABBER_FN(eustd_exception_createFccp);
        DECL_EGRABBER_FN(eustd_exception_destroy);
        DECL_EGRABBER_FN(eustd_exception_what);
        DECL_EGRABBER_FN(eufrom_box_Eur_BufferIndexRangeFspspb8_p);
        DECL_EGRABBER_FN(euNewBufferDataANewBufferData);
        DECL_EGRABBER_FN(euIoToolboxDataAIoToolboxData);
        DECL_EGRABBER_FN(euCicDataACicData);
        DECL_EGRABBER_FN(euDataStreamDataADataStreamData);
        DECL_EGRABBER_FN(euCxpInterfaceDataACxpInterfaceData);
        DECL_EGRABBER_FN(euDeviceErrorDataADeviceErrorData);
        DECL_EGRABBER_FN(euCxpDeviceDataACxpDeviceData);
        DECL_EGRABBER_FN(euRemoteDeviceDataARemoteDeviceData);
        DECL_EGRABBER_FN(euto_box_Eur_NewBufferDataFcst_NewBufferData_s_p);
        DECL_EGRABBER_FN(euto_box_EurEGInfoFcEGrabberInfo);
        DECL_EGRABBER_FN(eufrom_box_EurEGInfoFcEGrabberInfo_p);
        DECL_EGRABBER_FN(euto_box_EurEGInfoFcEGrabberInfoExt1_p);
        DECL_EGRABBER_FN(eufrom_box_EurEGInfoFcEGrabberInfoExt1_p);
        DECL_EGRABBER_FN(euto_box_EurEGInfoFcEGrabberInfoExt2_p);
        DECL_EGRABBER_FN(eufrom_box_EurEGInfoFcEGrabberInfoExt2_p);
        DECL_EGRABBER_FN(euto_box_EurEGInfoFcEGrabberInfoExt3_p);
        DECL_EGRABBER_FN(eufrom_box_EurEGInfoFcEGrabberInfoExt3_p);
        DECL_EGRABBER_FN(euto_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p);
        DECL_EGRABBER_FN(eufrom_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_genapi_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_genapi_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_cti_loading_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_cti_loading_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_missing_gentl_symbol);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_missing_gentl_symbol);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_unexpected_data_type);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_unexpected_data_type);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_unexpected_data_size);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_unexpected_data_size);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_client_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_client_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_gentl_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_gentl_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_thread_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_thread_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_internal_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_internal_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAEur_not_allowed);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFEur_not_allowed);
        DECL_EGRABBER_FN(euInternal_lastError_getAstd_runtime_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFstd_runtime_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAstd_logic_error);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFstd_logic_error);
        DECL_EGRABBER_FN(euInternal_lastError_getAstd_exception);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setFstd_exception);
        DECL_EGRABBER_FN(euInternal_lastError_getCode);
        DECL_EGRABBER_FN(euInternal_lastCallbackError_setCallbackCriticalError);
        DECL_EGRABBER_FN(eufrom_box_Eur_cti_loading_error_path);
        DECL_EGRABBER_FN(eufrom_box_Eur_missing_gentl_symbol_path);
        DECL_EGRABBER_FN(eufrom_box_Eur_missing_gentl_symbol_symbol);
        DECL_EGRABBER_FN(eufrom_box_Eur_unexpected_data_type);
        DECL_EGRABBER_FN(eufrom_box_Eur_unexpected_data_sizeFspsp);
        DECL_EGRABBER_FN(eufrom_box_Eur_gentl_error_gc_err);
        DECL_EGRABBER_FN(eufrom_box_Eur_gentl_error_description);
        DECL_EGRABBER_FN(eufrom_box_Eur_genapi_error);
        DECL_EGRABBER_FN(eugenapi_error_string_parameterASsFs);
        DECL_EGRABBER_FN(eucheckAllBoxedTypeCount);
};

class EGrabberDll: public EGrabberDllClassEGenTL, public EGrabberDllClassEGrabberCOD, public EGrabberDllClassEGrabberST, public EGrabberDllClassEGrabberMT, public EGrabberDllMisc {
    public:
        EGrabberDll(const std::string &path)
        : EGrabberDllBase(path)
        , EGrabberDllClassEGenTL(path)
        , EGrabberDllClassEGrabberCOD(path)
        , EGrabberDllClassEGrabberST(path)
        , EGrabberDllClassEGrabberMT(path)
        , EGrabberDllMisc(path)
        {}
        virtual ~EGrabberDll()
        {}
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_EGRABBER_DLL_HEADER_FILE
