/*****************************Copyright (c)***********************************
 *          Shenzhen Raythink Technology Co., Ltd.
 *
 *
 *-------------------------------File Info-------------------------------------
 * File Name:               diag_ap.c
 * Last modified Date:      2021-9-7 10:00
 * Last Version:            V1.0.0
 * Description:
 *
 * ----------------------------------------------------------------------------
 * Created By:               Leng
 * Created date:             2021-9-7 10:00
 * Version:                  V1.0.0
 * Descriptions:
 *
 * ----------------------------------------------------------------------------
 * Modified By:
 * Modified date:
 * Version:
 * Description:
 *
******************************************************************************/


/*
**********************************************************************************************************
					INCLUDES
**********************************************************************************************************
*/
#include "diag_ap.h"
#include "Mw_CANIL.h"
#include "ecual_flexspi.h"
#include "service_prog.h"
#include "ecual_timer.h"
#include "Security_Access_Algorithm.h"

/*
**********************************************************************************************************
					MACROS
**********************************************************************************************************
*/
#define D_UNLOCKKEY       						(0x0uL)
#define D_UNLOCKSEED      						(0x0uL)
#define D_UNDEFINESEED    						(0xFFFFFFFFuL)

#define D_ROUTINESTATUSRECODE_CORRET          	(0x00u)
#define D_ROUTINESTATUSRECODE_INCORRET        	(0x01u)

/* define Clear DTC Information DTC group */
#define D_DESC_CLEAR_ALL_DTC_INFORMATION      	(0x00FFFFFFuL)

#ifdef D_DTC_SNAPSHOT_RECORD
#define D_DEFAULT_DTCSNAPSHOTRECODENUMBER     	(0x01)
#endif

#define     D_FlashEraseAddrAndLen_Format           (0x44) 

/*
**********************************************************************************************************
					TYPEDEFS
**********************************************************************************************************
*/

/*
**********************************************************************************************************
					CONSTANTS
**********************************************************************************************************
*/
static	const ST_DESC_INFO  gst_DescHandlerTbl[] =
{
	{en_SID_DIAGNOG_SESSION_CONTROL,   	DiagnoseAP_DiagnosticSessionControl},
	{en_SID_ECU_HARD_RESET,           	DiagnoseAP_EcuRest},
#if (D_DESC_SID14_CLRDESCINFO_EN == D_DESC_ENABLE)
	{en_SID_CLR_DIAGNOSTIC_DTC,		 	DiagnoseAP_ClearDiagnosticInformation},
#endif
#if (D_DESC_SID19_RDDTCINFO_EN == D_DESC_ENABLE)
	{en_SID_READ_DTC_INFORMATION,		DiagnoseAP_ReadDTCInformation},
#endif
#if (D_DESC_SID22_READDID_EN == D_DESC_ENABLE)
	{en_SID_READ_DATA_BY_IDENTIFIER,  	DiagnoseAP_ReadDataByIdentifier},
#endif
#if (D_DESC_SID27_SECURITYACCESS_EN == D_DESC_ENABLE)
	{en_SID_SECURITY_ACCESS,           	DiagnoseAP_SecurityAccess},
#endif
#if D_DESC_SID28_COMCTL_EN
    {en_SID_COMMUNICATION_CONTROL,   	DiagnoseAP_CommunicationControl},
#endif

#if (D_DESC_SID2E_WRITEDID_EN == D_DESC_ENABLE)
	{en_SID_WRITE_DATA_BY_IDENTIFIER,  	DiagnoseAP_WriteDataByIdentifier},
#endif
#if (D_DESC_SID2F_IOCTRL_EN == D_DESC_ENABLE)
	{en_SID_IOCONTROL_BY_IDENTIFIER,  	DiagnoseAP_InputOutputControlByIdentifier},
#endif

#if (D_DESC_SID31_ROUTINECTRL_EN == D_DESC_ENABLE)
	{en_SID_ROUTINE_CONTROL,           	DiagnoseAP_RoutineControl},
#endif
#if (D_DESC_SID34_REQDWNLOAD_EN == D_DESC_ENABLE)
	{en_SID_REQUEST_DOWNLOAD,          	Diagnose_RequestDownload},
#endif
#if (D_DESC_SID36_TRANFDATA_EN == D_DESC_ENABLE)
	{en_SID_TRANSFER_DATA,            	Diagnose_DescTransferData},
#endif
#if (D_DESC_SID37_TRANFEXIT_EN == D_DESC_ENABLE)
	{en_SID_REQUEST_TRANSFER_EXIT,     	Diagnose_RequestTransferExit},
#endif
#if (D_DESC_SID85_CTRLDTCSET_EN == D_DESC_ENABLE)
    {en_SID_CONTROL_DTC_SETTING,       	DiagnoseAP_ControlDTCSetting},
#endif
	{en_SID_TESTER_PRESENT,				DiagnoseAP_TesterPresent},
};

static	const ST_DESC_SESSIONSACFG gst_DescSecurityConfigTbl[] = 
{
	{{D_SESN_DE,  	D_SA_NULL},		{D_SESN_DE,	D_SA_NULL}},
		
	{{D_SESN_DE,	D_SA_NULL},		{D_SESN_DE,	D_SA_NULL}},
	
#if (D_DESC_SID14_CLRDESCINFO_EN == D_DESC_ENABLE)
	{{D_SESN_DE,	D_SA_NULL},   	{D_SESN_DE,	D_SA_NULL}},
#endif

#if (D_DESC_SID19_RDDTCINFO_EN == D_DESC_ENABLE)
	{{D_SESN_DE,	D_SA_NULL},		{D_SESN_DE,	D_SA_NULL}},
#endif

#if (D_DESC_SID22_READDID_EN == D_DESC_ENABLE)
	{{D_SESN_DE,	D_SA_NULL},		{D_SESN_DE,   D_SA_NULL}},
#endif

#if (D_DESC_SID27_SECURITYACCESS_EN == D_DESC_ENABLE)
	{{D_DESC_SESN_PRGS,	D_SESN_NULL},	{D_SESN_NULL,	    D_SA_NULL}},
#endif

#if (D_DESC_SID28_COMCTL_EN == D_DESC_ENABLE)
	{{D_DESC_SESN_EXTDS,	D_SESN_NULL},	{D_DESC_SESN_EXTDS,	D_SA_NULL}},
#endif

#if (D_DESC_SID2E_WRITEDID_EN == D_DESC_ENABLE)
	{{D_DESC_SESN_PRGS,	D_SA_EXTDS},{D_SESN_NULL,	D_SA_NULL}},
#endif
	
#if (D_DESC_SID2F_IOCTRL_EN == D_DESC_ENABLE)
	{{D_DESC_SESN_EXTDS,	D_SA_EXTDS},{D_SESN_NULL,	D_SA_NULL}},	
#endif
	
#if (D_DESC_SID31_ROUTINECTRL_EN == D_DESC_ENABLE)
   	{{D_DESC_SESN_EXTDS,	D_SA_EXTDS},{D_SESN_NULL,	D_SA_NULL}},
#endif

#if (D_DESC_SID34_REQDWNLOAD_EN == D_DESC_ENABLE)
    {{D_DESC_SESN_PRGS,	D_SA_EXTDS},	{D_SESN_NULL,	D_SA_NULL}},
#endif
#if (D_DESC_SID36_TRANFDATA_EN == D_DESC_ENABLE)
    {{D_DESC_SESN_PRGS,	D_SA_EXTDS},	{D_SESN_NULL,	D_SA_NULL}},
#endif
#if (D_DESC_SID37_TRANFEXIT_EN == D_DESC_ENABLE)
    {{D_DESC_SESN_PRGS,	D_SA_EXTDS},	{D_SESN_NULL,	D_SA_NULL}},
#endif
    {{D_SESN_DPEVS,	D_SA_NULL},	{D_SESN_DPEVS,D_SA_NULL}},
		
#if (D_DESC_SID85_CTRLDTCSET_EN == D_DESC_ENABLE)
    {{D_DESC_SESN_EXTDS,	D_SA_NULL},	{D_DESC_SESN_EXTDS,D_SA_NULL}},
#endif

    {{D_SESN_DPEVS,	D_SA_NULL},	{D_SESN_DPEVS,D_SA_NULL}},
};

static	const INT16U  gDescServiceRespTimeTbl[UBOUND(gst_DescHandlerTbl)] =
{
	D_DESC_P2_CAN_SERVER_MAX, 	/* DiagnoseAP_DiagnosticSessionControl : 50ms 		*/
	66, 					 	/* DiagnoseAP_EcuRest : 200ms                 		*/
#if (D_DESC_SID14_CLRDESCINFO_EN == D_DESC_ENABLE)
	200,						/* DiagnoseAP_ClearDiagnosticInformation: 1000ms 	*/
#endif
#if (D_DESC_SID19_RDDTCINFO_EN == D_DESC_ENABLE)
	60,                     	/* DiagnoseAP_ReadDTCInformation:300ms				*/
#endif
#if (D_DESC_SID22_READDID_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* DiagnoseAP_ReadDataByIdentifier            		*/
#endif
#if (D_DESC_SID27_SECURITYACCESS_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* DiagnoseAP_SecurityAccess                  		*/
#endif
#if (D_DESC_SID28_COMCTL_EN == D_DESC_ENABLE)
    D_DESC_P2_CAN_SERVER_MAX,	/* DiagnoseAP_CommunicationControl       			*/
#endif
#if (D_DESC_SID2E_WRITEDID_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* DiagnoseAP_WriteDataByIdentifier  				*/
#endif
#if (D_DESC_SID2F_IOCTRL_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,	/* DiagnoseAP_InputOutputControlByIdentifier 		*/
#endif
#if (D_DESC_SID31_ROUTINECTRL_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* BootDescRoutineCtrl								*/
#endif
#if (D_DESC_SID34_REQDWNLOAD_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* BootDescRequestDownload		    				*/
#endif
#if (D_DESC_SID36_TRANFDATA_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* BootDescTransferData		    	    			*/
#endif
#if (D_DESC_SID37_TRANFEXIT_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,  	/* BootDescRequestTransferExit           			*/
#endif
#if (D_DESC_SID85_CTRLDTCSET_EN == D_DESC_ENABLE)
	D_DESC_P2_CAN_SERVER_MAX,	/* DiagnoseAP_ControlDTCSetting 					*/
#endif
	D_DESC_P2_CAN_SERVER_MAX,	/* DiagnoseAP_TesterPresent 						*/
};


void DiagnoseAP_ComCtrlRxAndTxEnable(INT8U ComMsgType);
void DiagnoseAP_ComCtrlRxAndTxDisable(INT8U ComMsgType);



static	const ST_DESC_COM_INFO gst_ComCtrlTbl[] =
{
	{en_RxEnable_TxEnable,   /*SESN_EXTDS | SESN_DS, */{3, DiagnoseAP_ComCtrlRxAndTxEnable}},
    {en_RxEnable_TxDisable,   /*SESN_EXTDS | SESN_DS, */{3, DiagnoseAP_ComCtrlRxEnableTxDisable}},
    {en_RxDisable_TxEnable,   /*SESN_EXTDS | SESN_DS, */{3, DiagnoseAP_ComCtrlRxDisableTxEnable}},
 	{en_RxDisable_TxDisable, /*SESN_EXTDS | SESN_DS, */{3, DiagnoseAP_ComCtrlRxAndTxDisable}}
};

/*---------------------- DID List ----------------------------------------------*/
static	const ST_DESC_DID_INFO gst_RWDIDInfoTbl[] =
{
	{
		0xF193, D_LEN_DIDF193,	{D_DESC_SESN_DS | D_DESC_SESN_EXTDS, D_DESC_SA_FALSE, DiagnoseAP_DID_Read_F193_SupplierHWVersion},
									{D_DESC_DIDNOTSUPPORTWRITE}
	},
	{
		0xF195, D_LEN_DIDF195,	{D_DESC_SESN_DS | D_DESC_SESN_EXTDS, D_DESC_SA_FALSE, DiagnoseAP_DID_Read_F195_SupplierSWVersion},
									{D_DESC_DIDNOTSUPPORTWRITE}
	},
	{
        0xF18C, D_LEN_DIDF18C,	{D_DESC_SESN_DS | D_DESC_SESN_EXTDS, D_DESC_SA_FALSE, DiagnoseAP_DID_Read_F18C_ECUSN},
        		                    {D_DESC_SESN_DS | D_DESC_SESN_EXTDS, D_DESC_SA_FALSE, DiagnoseAP_DID_Write_F18C_ECUSN}
    },
    {
        0xF15A, D_LEN_DIDF15A,  {D_DESC_SESN_DS | D_DESC_SESN_EXTDS | D_DESC_SESN_PRGS, D_DESC_SA_FALSE, DiagnoseAP_DID_Read_F15A_Fingerprint},
                                    {D_DESC_SESN_PRGS, D_DESC_SA_TRUE, DiagnoseAP_DID_Write_F15A_Fingerprint}
    },
};

//---------------------- RoutineCtl List ---------------------------------------
static	const ST_DESC_ROUTINT_INFO gst_RoutineCtlTbl[] =
{
	/* SID    SessionAllow                   SecurityAllow    ServiceProcess*/
    {0xFF00, D_DESC_SESN_PRGS,                D_DESC_SA_TRUE,  {  {9, DiagnoseAP_RoutineCtrl_FF00_EraseMemory_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xFF01, D_DESC_SESN_PRGS,                D_DESC_SA_TRUE,  {  {0, DiagnoseAP_RoutineCtrl_FF01_CheckProDependencies_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xFF02, D_DESC_SESN_EXTDS,                D_DESC_SA_FALSE,  {  {0, DiagnoseAP_RoutineCtrl_FF02_CheckProgPrecondition_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xC059, D_DESC_SESN_EXTDS,                D_DESC_SA_TRUE,  {   {0, DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StartRoutile},
                                                                {0, DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StopRoutile},
                                                                {0, DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_RequestRoutileResult}}
    },
    {0xD002, D_DESC_SESN_PRGS,                D_DESC_SA_TRUE,  {  {4, DiagnoseAP_RoutineCtrl_D002_CheckMemory_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xD003, D_DESC_SESN_EXTDS,                D_DESC_SA_FALSE,  {  {0, DiagnoseAP_RoutineCtrl_D003_CheckProgPrecondition_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xD004, D_DESC_SESN_PRGS,                D_DESC_SA_TRUE,  {  {0, DiagnoseAP_RoutineCtrl_D004_CheckProgPrecondition_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
    {0xD005, D_DESC_SESN_PRGS,                D_DESC_SA_TRUE,  {  {0, DiagnoseAP_RoutineCtrl_D005_FlashFileInstallation_StartRoutile},
                                                                {0, NULL},
                                                                {0, NULL}   }
    },
};

static	const ST_RDDTC_INFO gst_ReadDTCInfoTbl[] =
{
	/* Read DTC Req Type             ReqLen   Service */
	{en_RDDTC_RepNumOfDTCByStatusMask,  3,  DiagnoseAP_RdDTCReportNumberOfDTCByStatusMask},
	{en_RDDTC_RepDTCMask,               3,  DiagnoseAP_RdDTCReportDTCByStatusMask},
#ifdef D_DTC_SNAPSHOT_RECORD
    {en_RDDTC_RepDTCSnapshotRecode,     6,  DiagnoseAP_RdDTCReportDTCSnapshotRecodeByDtcNumber},
#endif
	{en_RDDTC_RepSupportedDTC,          2,  DiagnoseAP_RdDTCReportSupportedDTC},
};

#if 0
static	const INT16U gDTCSnapShotIDTbl[] = 
{
	0XF1B1,
	0XF1B2,
	0XF1C1,
	0XF1B0,
	0XF1A9,
	0XF1B3,
	0XF1C2,
	0XF1C3,
	0XF1C4,
	0XF1C5,
	0XF1C6,
	0XF1C7,
};
#endif

static	const ST_DESC_IOCTL_INFO  gst_IOCtrlTbl[] =
{
	{0x0114, D_DESC_SESN_EXTDS, DiagnoseAP_IOCtrl_0114_TestCtrl},
};

static	const INT8U SupplierHWVersion[] =
{
	1,0
};

static	const INT8U SupplierSWVersion[] =
{
	1,0
};

static	INT8U  ECUSN[] = 
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

static ST_FINGERPRINT Fingerprint = {0};

static	const INT8U DescDiagnosticSession[] =
{
	0x01, 0x02, 0x03, 0x40, 0x60,
};

static	const INT8U DesSecurityAccessSubID[] =
{
	0x01, 0x02, 0x07, 0x08, 0x09, 0x0A
};

static	const INT8U DescRoutineControlTypeID[] =
{
	0x01, 0x02, 0x03,
};

/*
**********************************************************************************************************
					GLOBAL VARIABLES
**********************************************************************************************************
*/
static	BOOL AppDescSeedReceive;
static	BOOL AppDescUnlockStatus;
static	BOOL AppDescSessionChangedFlg;
static	BOOL AppDescECUHardRestReq = D_False;
BOOL AppDescJumpToBootFlg = D_False;
BOOL AppDescRestToFactoryModeFlg = D_False;
static	BOOL AppDescIOCtrlFlg = D_False;

static	INT8U  AppDescSecurityAccessLevel = 0u;
static	INT8U  AppDescSession;
static	INT8U  AppDescRespNoSend;
static	INT8U  AppDescTesterPresentTimer;
static	INT8U  AppDescPrevSession;
static	INT8U  AppDescTimer100ms;
static	INT8U  AppDescSecurityAccessErrCnt = 0u;
static	INT8U  AppDescCurrRoutine = 0u;
INT16U  AppDescSecurityAccessErrWaitTime = 0u;

volatile INT8U 	AppDescNrc;
static	volatile INT8U  AppDescOpTimeLongerThanP2Flag;
volatile INT8U  AppDescControlDTCSetting = 0u;
volatile INT8U  AppDescU1gP2ExCntr = 0u;

static INT8U AppDescU8sDTCStatusMask;

static EN_IOCtrlStatus Test_IOCtrlSts = en_IOCtrl_Invaild;
static INT8U  TestCtrl = 0u;

static	INT16U AppDescP4Timer;
static	volatile INT16U AppDescRWDIDIndex = 0u;

static	ST_SecurityAccess_OutInfo  gst_SecurityAccess_stgOutInfo;
static	ST_Desc_SecLvl  gst_Desc_stsSecLvl;

static	volatile ST_DESC_LngTmRspInfo gst_DescLngTmRspInfo = {0};
static	volatile unsigned short AppWrDescP4Timer;

stDownloadInfo  DownloadInfo;
BOOL    DownloadFlashDrvFlg = FALSE;
BOOL    DownloadAppCodeFlg = FALSE;
/*
**********************************************************************************************************
					FUNCTIONS
**********************************************************************************************************
*/

//void DiagnoseAP_EcuHardReset(void);
static	INT8U DiagnoseAP_SessionConverGet(INT8U SenssionType)
{
	INT8U SessionTmp = D_DESC_SESN_DS;
	switch((EN_SESSION_TYPE)SenssionType)
	{
		case en_Session_Default:
			SessionTmp = D_DESC_SESN_DS;
			break;
		case en_Session_Program:
			SessionTmp = D_DESC_SESN_PRGS;
			break;
		case en_Session_Extended:
			SessionTmp = D_DESC_SESN_EXTDS;
			break;
		case en_Session_VehicleFacturer:
			SessionTmp = D_DESC_SESN_VMS;
			break;
		case en_Session_SystemSupplier:
			SessionTmp = D_DESC_SESN_SSS;
			break;
		default:
			SessionTmp = D_DESC_SESN_DS;
			break;
	}
	return SessionTmp;
}

void DiagnoseAP_ComCtrlRxAndTxEnable(INT8U ComMsgType)
{
	if((ComMsgType == 0x01) || (ComMsgType == 0x03))
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		CAN_Application_Msg_Rx_EnableFlg = D_True;
		CAN_Application_Msg_Tx_EnableFlg = D_True;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestOutOfRange;
	}
}

void DiagnoseAP_ComCtrlRxEnableTxDisable(INT8U ComMsgType)
{
	if((ComMsgType == 0x01) || (ComMsgType == 0x03))
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		CAN_Application_Msg_Rx_EnableFlg = D_True;
		CAN_Application_Msg_Tx_EnableFlg = D_False;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestOutOfRange;
	}
}

void DiagnoseAP_ComCtrlRxDisableTxEnable(INT8U ComMsgType)
{
	if((ComMsgType == 0x01) || (ComMsgType == 0x03))
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		CAN_Application_Msg_Rx_EnableFlg = D_False;
		CAN_Application_Msg_Tx_EnableFlg = D_True;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestOutOfRange;
	}
}

void DiagnoseAP_ComCtrlRxAndTxDisable(INT8U ComMsgType)
{
	if((ComMsgType == 0x01) || (ComMsgType == 0x03))
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		CAN_Application_Msg_Rx_EnableFlg = D_False;
		CAN_Application_Msg_Tx_EnableFlg = D_False;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestOutOfRange;
	}
}

static	void DiagnoseAP_WrRdDIDOp(INT8U RWSlc)
{
	INT16U wDID;
	BOOL cSubServiceFound = D_False;
	ST_RDID_INFO tWRBootDIDInfo;

    tWRBootDIDInfo.ServiceProcess = NULL;

	if((RWSlc==D_DESC_DID_W)&&\
	((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex))
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = (D_DescNrcNoRsp);
		return;
	}

	wDID = gst_AppDescTpRxInfo.cDataBuf[1];
	wDID <<= 8;
	wDID |= gst_AppDescTpRxInfo.cDataBuf[2];
	
	if(D_DESC_DID_R == RWSlc)
	{
        if(3 != gst_AppDescTpRxInfo.wDataLength)
        {
            AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
            return;
        }

	}
	else if(D_DESC_DID_W == RWSlc)
	{
		switch(wDID)
		{
			case 0XF18C:
			{
				if(D_LEN_DIDF18C != (gst_AppDescTpRxInfo.wDataLength - 3)) // 2E F1 8C �� 3Byte, ��������14Byte������
			    {
			        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
			        return;
			    }
				break;
			}

            case 0xF15A:
            {
				if(D_LEN_DIDF15A != (gst_AppDescTpRxInfo.wDataLength - 3))
			    {
			        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
			        return;
			    }
				break;
            }

			default:
			{
				break;
			}
		}
	}
	else
	{
		//MISRA:C:2012 15.7
		//All if ... else if constructs shall be terminated with an else statement
	}

	for(AppDescRWDIDIndex = 0; AppDescRWDIDIndex < UBOUND(gst_RWDIDInfoTbl); AppDescRWDIDIndex++)
	{
		if(gst_RWDIDInfoTbl[AppDescRWDIDIndex].sDID == wDID)
		{
			if(D_DESC_DID_R == RWSlc) // Read DID
			{
				tWRBootDIDInfo.SessionAllow = gst_RWDIDInfoTbl[AppDescRWDIDIndex].ReadDIDInfo.SessionAllow;
				tWRBootDIDInfo.SecuAcesReq = gst_RWDIDInfoTbl[AppDescRWDIDIndex].ReadDIDInfo.SecuAcesReq;
				tWRBootDIDInfo.ServiceProcess = gst_RWDIDInfoTbl[AppDescRWDIDIndex].ReadDIDInfo.ServiceProcess;
			}
			else // Write DID
			{
				tWRBootDIDInfo.SessionAllow = gst_RWDIDInfoTbl[AppDescRWDIDIndex].WriteIDInfo.SessionAllow;
				tWRBootDIDInfo.SecuAcesReq = gst_RWDIDInfoTbl[AppDescRWDIDIndex].WriteIDInfo.SecuAcesReq;
				tWRBootDIDInfo.ServiceProcess = gst_RWDIDInfoTbl[AppDescRWDIDIndex].WriteIDInfo.ServiceProcess;
			}

			if(NULL != tWRBootDIDInfo.ServiceProcess)
			{
				cSubServiceFound = D_True;

				if(AppDescSession == (tWRBootDIDInfo.SessionAllow & AppDescSession)) 
				{
					if(((D_DESC_SA_TRUE == tWRBootDIDInfo.SecuAcesReq) && (D_True == AppDescUnlockStatus)) || \
							(D_DESC_SA_FALSE == tWRBootDIDInfo.SecuAcesReq))
					{
						tWRBootDIDInfo.ServiceProcess();
					}
					else
					{
						AppDescNrc = (D_DescNrcAccessDenied);
					}
				}
				else
				{
					AppDescNrc = (D_DescNrcServiceNotSupportedInActiveSession);
				}
			}
			break;
		}
	}

	if(D_False == cSubServiceFound)
	{
		AppDescNrc = (D_DescNrcRequestOutOfRange);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_DiagnosticSessionControl
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_DiagnosticSessionControl(void)
{
	INT8U cIndex;
	INT8U cTempDescSession;
	BOOL cSessionFound = D_False;
	AppDescUnlockStatus = D_False;
	AppDescCurrRoutine = 0;
	AppDescSeedReceive = D_False;
	cTempDescSession =  (gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu);
	for(cIndex = 0; cIndex < UBOUND(DescDiagnosticSession); cIndex++)
	{
		if(DescDiagnosticSession[cIndex] == cTempDescSession)
		{
			cSessionFound = D_True;
		}
	}
	
	if (2 != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	
	if(D_False == cSessionFound)
	{
		if(gst_AppDescTpRxInfo.cCANIDIndex == D_DIAGNOSE_RX_MSG_PHYSICAL)
		{
			AppDescNrc = (D_DescNrcSubfunctionNotSupported);
		}
		return;
	}

	cTempDescSession =	DiagnoseAP_SessionConverGet(gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu);

	if(((D_DESC_SESN_PRGS == cTempDescSession) && ((D_DESC_SESN_EXTDS != AppDescSession)&&(D_DESC_SESN_PRGS != AppDescSession)))||\
	((D_DESC_SESN_EXTDS == cTempDescSession) && ((D_DESC_SESN_DS != AppDescSession)&&(D_DESC_SESN_EXTDS != AppDescSession))))
	{
		AppDescNrc = D_DescNrcSubfunctionNotSupportedInActiveSession;
		return;
	}
	if(AppDescSession != cTempDescSession)
	{
		if(D_DESC_SESN_PRGS == cTempDescSession)
		{
			if(0x80u != (gst_AppDescTpRxInfo.cDataBuf[1] & 0x80u))
			{
				gst_AppDescTpTxInfo.cDataBuf[1] = gst_AppDescTpRxInfo.cDataBuf[1];

				gst_AppDescTpTxInfo.cDataBuf[2] = (INT8U)(((INT16U)D_DESC_P2_CAN_SERVER_MAX * D_DESC_CYCTIME) >> 8);
				gst_AppDescTpTxInfo.cDataBuf[3] = (INT8U)((INT16U)D_DESC_P2_CAN_SERVER_MAX * D_DESC_CYCTIME);
				gst_AppDescTpTxInfo.cDataBuf[4] = (INT8U)(((INT16U)D_DESC_P2EX_CAN_SERVER_MAX * D_DESC_CYCTIME / 10) >> 8);
				gst_AppDescTpTxInfo.cDataBuf[5] = (INT8U)((INT16U)D_DESC_P2EX_CAN_SERVER_MAX * D_DESC_CYCTIME / 10);
		        gst_AppDescTpTxInfo.wDataLength = 6;
				AppDescNrc = D_DescNrcOK;
				CAN_Diagnose_Msg_Rx_Flg = D_True;
			}
			else
			{
				AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
				gst_AppDescTpRxState.engine = en_RxState_Idle;
				gst_AppDescTpTxState.engine = en_TxState_Idle;
				AppDescNrc = D_DescNrcNoRsp;
			}
		}

		AppDescSessionChangedFlg = D_True;
		if(cTempDescSession == D_DESC_SESN_DS)
		{
			AppDescControlDTCSetting = D_DESC_CONTROL_DTC_SETTING_ON;  
			CAN_Application_Msg_Rx_EnableFlg = D_True;
			CAN_Application_Msg_Tx_EnableFlg = D_True;
		}
		AppDescPrevSession = AppDescSession;
		AppDescSession = cTempDescSession;
		AppDescTimer100ms = D_DESC_TIMER_100MS;
	}
	else
	{
		if(D_DESC_SESN_PRGS == cTempDescSession)
		{
			AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
			AppDescTimer100ms = D_DESC_TIMER_100MS;
			AppDescSession = cTempDescSession;
		}
	}
	if(0x80u != (gst_AppDescTpRxInfo.cDataBuf[1] & 0x80u))
	{

        AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
        gst_AppDescTpTxInfo.cDataBuf[1] = gst_AppDescTpRxInfo.cDataBuf[1];

		gst_AppDescTpTxInfo.cDataBuf[2] = (INT8U)(((INT16U)D_DESC_P2_CAN_SERVER_MAX * D_DESC_CYCTIME) >> 8); 
		gst_AppDescTpTxInfo.cDataBuf[3] = (INT8U)((INT16U)D_DESC_P2_CAN_SERVER_MAX * D_DESC_CYCTIME);
		gst_AppDescTpTxInfo.cDataBuf[4] = (INT8U)(((INT16U)D_DESC_P2EX_CAN_SERVER_MAX * D_DESC_CYCTIME / 10) >> 8); 
		gst_AppDescTpTxInfo.cDataBuf[5] = (INT8U)((INT16U)D_DESC_P2EX_CAN_SERVER_MAX * D_DESC_CYCTIME / 10);
        gst_AppDescTpTxInfo.wDataLength = 6;		
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
	}
	else
	{
        AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		gst_AppDescTpTxState.engine = en_TxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_EcuRest
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_EcuRest(void)
{
	if(2 != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}

	if((gst_AppDescTpRxInfo.cDataBuf[1]  == D_DESC_ECU_HARD_REST)||\
	(gst_AppDescTpRxInfo.cDataBuf[1] == D_DESC_ECU_SOFT_REST))
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		AppDescECUHardRestReq = D_True;
	}
	else
	{
		AppDescNrc = (D_DescNrcSubfunctionNotSupported);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_TesterPresent
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_TesterPresent(void)
{
	if(2 != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	if((gst_AppDescTpRxInfo.cDataBuf[1] == D_DESC_TESTER_PRESENT_ZERO_SUB_FUNC) || \
			(gst_AppDescTpRxInfo.cDataBuf[1] == (D_DESC_TESTER_PRESENT_ZERO_SUB_FUNC | 0x80u)))
	{
		AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
		if(gst_AppDescTpRxInfo.cDataBuf[1] == D_DESC_TESTER_PRESENT_ZERO_SUB_FUNC)
		{
			gst_AppDescTpTxInfo.cDataBuf[2] = D_DESC_TESTER_PRESENT_ZERO_SUB_FUNC;
			gst_AppDescTpTxInfo.wDataLength = 2u;
			AppDescNrc = D_DescNrcOK;
			CAN_Diagnose_Msg_Rx_Flg = D_True;
		}
		else
		{
			gst_AppDescTpRxState.engine = en_RxState_Idle;
			gst_AppDescTpTxState.engine = en_TxState_Idle;
			AppDescNrc = D_DescNrcNoRsp;
		}
	}
	else
	{
		if(gst_AppDescTpRxInfo.cCANIDIndex == D_DIAGNOSE_RX_MSG_PHYSICAL)
		{
			AppDescNrc = (D_DescNrcSubfunctionNotSupported);
		}
		else
		{
		}
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SessionSA_CfgChk
* Description   : 
* Date          : 2020/2/14
* Parameter     : SenssionTypeIndex
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	BOOL DiagnoseAP_SessionSA_CfgChk(EN_SID_TYPE_INDEX SenssionTypeIndex)
{
	BOOL	RetVal = D_False;
	if(gst_AppDescTpRxInfo.cCANIDIndex == D_DIAGNOSE_RX_MSG_PHYSICAL)
	{
		if(AppDescSession != (gst_DescSecurityConfigTbl[SenssionTypeIndex].PhySessionSACfg.SessionAllow & AppDescSession))
		{
			RetVal = D_True;
			AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		}
		else if(D_SA_NULL != gst_DescSecurityConfigTbl[SenssionTypeIndex].PhySessionSACfg.SA_Allow)
		{
			if(AppDescUnlockStatus == D_False)
			{
				RetVal = D_True;
				AppDescNrc = D_DescNrcAccessDenied;
			}
		}
		else
		{
			//MISRA:C:2012 15.7
			//All if ... else if constructs shall be terminated with an else statement
		}
		 
	}
	else if(gst_AppDescTpRxInfo.cCANIDIndex == D_DIAGNOSE_RX_MSG_FUNTION)
	{
		if(AppDescSession != (gst_DescSecurityConfigTbl[SenssionTypeIndex].FucSessionSACfg.SessionAllow & AppDescSession))
		{
			RetVal = D_True;
			//DescNrc = kDescNrcServiceNotSupportedInActiveSession;
		}
	}
	else
	{
		//MISRA:C:2012 15.7
		//All if ... else if constructs shall be terminated with an else statement
	}
	return RetVal;
}


/*
**********************************************************************************************************
* Function Name : DiagnoseAP_ClearDiagnosticInformation
* Description   : 
* Date          : 2020/2/14
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_ClearDiagnosticInformation(void)
{
	INT32U	dwGroupOfDTC;
	if(4 != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	if(D_True == DiagnoseAP_SessionSA_CfgChk(en_SID_CLR_DIAGNOSTIC_DTC_INDEX))
	{
		return;
	}
	dwGroupOfDTC = gst_AppDescTpRxInfo.cDataBuf[1];
	dwGroupOfDTC <<= 8;
	dwGroupOfDTC |= gst_AppDescTpRxInfo.cDataBuf[2];
	dwGroupOfDTC <<= 8;
	dwGroupOfDTC |= gst_AppDescTpRxInfo.cDataBuf[3];
	if(dwGroupOfDTC == D_DESC_CLEAR_ALL_DTC_INFORMATION)
	{
		DiagnoseDTC_DescClearAllDTCInformation();
	}
	else
	{
		/* Group not support */
		AppDescNrc = (D_DescNrcRequestOutOfRange);
	}
}

/******************Read DTC Information Sub Function*************************/
/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RdDTCReportNumberOfDTCByStatusMask
* Description   : ͨ
* Date          : 2020/2/17
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RdDTCReportNumberOfDTCByStatusMask(void)
{
	INT8U cIndex, cStatus;
	INT16U wDTCCounter = 0;
	const ST_DESC_DTCObj *psttStatusMask;
	
	psttStatusMask = gst_DTCTblInfo.pDTCObjTbl;
	for(cIndex = 0; cIndex < gst_DTCTblInfo.cDTCParaTblLen; cIndex ++)
	{
		cStatus = psttStatusMask->stDTCStatusInfo.unStatusMask.Byte & gst_AppDescTpRxInfo.cDataBuf[2];
		if(cStatus != 0)
		{
			wDTCCounter ++;
		}
		psttStatusMask++;
	}
	gst_AppDescTpTxInfo.cDataBuf[2] = D_DTCStatusAvailabilityMask;
	gst_AppDescTpTxInfo.cDataBuf[3] = D_DTCFormatIdentifierISO15031_64DTCFormat;
	gst_AppDescTpTxInfo.cDataBuf[4] = (INT8U )(wDTCCounter >> 8);
	gst_AppDescTpTxInfo.cDataBuf[5] = (INT8U)(wDTCCounter);
	gst_AppDescTpTxInfo.wDataLength = 6;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RdDTCReportDTCByStatusMask
* Description   : 
* Date          : 2020/2/17
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RdDTCReportDTCByStatusMask(void)
{
	INT8U cIndex, cStatus;
	INT16U wNum = 3;
	const ST_DESC_DTCObj *psttStatusMask = gst_DTCTblInfo.pDTCObjTbl;

	gst_AppDescTpTxInfo.wDataLength = 3;
	AppDescU8sDTCStatusMask = gst_AppDescTpRxInfo.cDataBuf[2];
	gst_AppDescTpTxInfo.cDataBuf[2] = D_DTCStatusAvailabilityMask;
	for(cIndex = 0; cIndex < gst_DTCTblInfo.cDTCParaTblLen; cIndex ++)
	{
		cStatus =  psttStatusMask->stDTCStatusInfo.unStatusMask.Byte & AppDescU8sDTCStatusMask;
		if(cStatus != 0)
		{
			gst_AppDescTpTxInfo.wDataLength += 4;
			if((wNum + 4) < D_DESC_TP_TX_DATA_BUF_SIZE)
			{
				gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[0];
				gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[1];
				gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[2];
				gst_AppDescTpTxInfo.cDataBuf[wNum++] = psttStatusMask->stDTCStatusInfo.unStatusMask.Byte;
			}
		}
		psttStatusMask++;
	}
	gst_AppDescTpTxInfo.wDataLength = wNum;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

#ifdef D_DTC_SNAPSHOT_RECORD
/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RdDTCReportDTCSnapshotRecodeByDtcNumber
* Description   : 
* Date          : 2020/2/17
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RdDTCReportDTCSnapshotRecodeByDtcNumber(void)
{
    INT8U cIndex;
    INT8U cFoundDTCFlg = D_False;
    for(cIndex = 0; cIndex < gst_DTCTblInfo.cDTCParaTblLen; cIndex ++)
    {
        if(
            (gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[0] == gst_AppDescTpRxInfo.cDataBuf[2]) &&
            (gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[1] == gst_AppDescTpRxInfo.cDataBuf[3]) &&
            (gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[2] == gst_AppDescTpRxInfo.cDataBuf[4])
        )
        {
            cFoundDTCFlg = D_True;
            break;
        }
    }
    if(cFoundDTCFlg != D_True)
    {
        AppDescNrc = (D_DescNrcRequestOutOfRange);
        return;
    }
    if((0xFFu != gst_AppDescTpRxInfo.cDataBuf[5]) &&\
    (D_DEFAULT_DTCSNAPSHOTRECODENUMBER != gst_AppDescTpRxInfo.cDataBuf[5]))
    {
        AppDescNrc = (D_DescNrcRequestOutOfRange);
        return;
    }
    /* this fill response diag  */
    /* step 1: fill DTC Status Recode */
    gst_AppDescTpTxInfo.cDataBuf[2] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[0];
    gst_AppDescTpTxInfo.cDataBuf[3] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[1];
    gst_AppDescTpTxInfo.cDataBuf[4] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[2];
    /* step 2: fill status of dtc */
    gst_AppDescTpTxInfo.cDataBuf[5] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stDTCStatusInfo.unStatusMask.Byte;
    /* step 3: fill Snapshot Recode number */
    gst_AppDescTpTxInfo.cDataBuf[6] = gst_AppDescTpRxInfo.cDataBuf[5];
    /* step 4:fill Snapshot Recode Number of Indentifiers */
    gst_AppDescTpTxInfo.cDataBuf[7] = 0x0c;
    
    /* step 5: Snapshot ID & Data*/
	gst_AppDescTpTxInfo.cDataBuf[8] = ToolGetHiByte(gDTCSnapShotIDTbl[0]);
	gst_AppDescTpTxInfo.cDataBuf[9] = ToolGetLoByte(gDTCSnapShotIDTbl[0]);
	gst_AppDescTpTxInfo.cDataBuf[10] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[0];
	
	gst_AppDescTpTxInfo.cDataBuf[11] = ToolGetHiByte(gDTCSnapShotIDTbl[1]);
	gst_AppDescTpTxInfo.cDataBuf[12] = ToolGetLoByte(gDTCSnapShotIDTbl[1]);
	gst_AppDescTpTxInfo.cDataBuf[13] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[1]; 

	gst_AppDescTpTxInfo.cDataBuf[14] = ToolGetHiByte(gDTCSnapShotIDTbl[2]);
	gst_AppDescTpTxInfo.cDataBuf[15] = ToolGetLoByte(gDTCSnapShotIDTbl[2]);
	gst_AppDescTpTxInfo.cDataBuf[16] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[2]; 

	gst_AppDescTpTxInfo.cDataBuf[17] = ToolGetHiByte(gDTCSnapShotIDTbl[3]);
	gst_AppDescTpTxInfo.cDataBuf[18] = ToolGetLoByte(gDTCSnapShotIDTbl[3]);
	gst_AppDescTpTxInfo.cDataBuf[19] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[3]; 
	gst_AppDescTpTxInfo.cDataBuf[20] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[4];

	gst_AppDescTpTxInfo.cDataBuf[21] = ToolGetHiByte(gDTCSnapShotIDTbl[4]);
	gst_AppDescTpTxInfo.cDataBuf[22] = ToolGetLoByte(gDTCSnapShotIDTbl[4]);
	gst_AppDescTpTxInfo.cDataBuf[23] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[5]; 
	gst_AppDescTpTxInfo.cDataBuf[24] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[6];
	gst_AppDescTpTxInfo.cDataBuf[25] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[7];

	gst_AppDescTpTxInfo.cDataBuf[26] = ToolGetHiByte(gDTCSnapShotIDTbl[5]);
	gst_AppDescTpTxInfo.cDataBuf[27] = ToolGetLoByte(gDTCSnapShotIDTbl[5]);
	gst_AppDescTpTxInfo.cDataBuf[28] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[8]; 
	gst_AppDescTpTxInfo.cDataBuf[29] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[9];

	gst_AppDescTpTxInfo.cDataBuf[30] = ToolGetHiByte(gDTCSnapShotIDTbl[6]);
	gst_AppDescTpTxInfo.cDataBuf[31] = ToolGetLoByte(gDTCSnapShotIDTbl[6]);
	gst_AppDescTpTxInfo.cDataBuf[32] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[10]; 

	gst_AppDescTpTxInfo.cDataBuf[33] = ToolGetHiByte(gDTCSnapShotIDTbl[7]);
	gst_AppDescTpTxInfo.cDataBuf[34] = ToolGetLoByte(gDTCSnapShotIDTbl[7]);
	gst_AppDescTpTxInfo.cDataBuf[35] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[11]; 

	gst_AppDescTpTxInfo.cDataBuf[36] = ToolGetHiByte(gDTCSnapShotIDTbl[8]);
	gst_AppDescTpTxInfo.cDataBuf[37] = ToolGetLoByte(gDTCSnapShotIDTbl[8]);
	gst_AppDescTpTxInfo.cDataBuf[38] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[12]; 

	gst_AppDescTpTxInfo.cDataBuf[39] = ToolGetHiByte(gDTCSnapShotIDTbl[9]);
	gst_AppDescTpTxInfo.cDataBuf[40] = ToolGetLoByte(gDTCSnapShotIDTbl[9]);
	gst_AppDescTpTxInfo.cDataBuf[41] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[13];

	gst_AppDescTpTxInfo.cDataBuf[42] = ToolGetHiByte(gDTCSnapShotIDTbl[10]);
	gst_AppDescTpTxInfo.cDataBuf[43] = ToolGetLoByte(gDTCSnapShotIDTbl[10]);
	gst_AppDescTpTxInfo.cDataBuf[44] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[14]; 

	gst_AppDescTpTxInfo.cDataBuf[45] = ToolGetHiByte(gDTCSnapShotIDTbl[11]);
	gst_AppDescTpTxInfo.cDataBuf[46] = ToolGetLoByte(gDTCSnapShotIDTbl[11]);
	gst_AppDescTpTxInfo.cDataBuf[47] = gst_DTCTblInfo.pDTCObjTbl[cIndex].stSnapshotRecord.snapshotbuf[15]; 
	
    gst_AppDescTpTxInfo.wDataLength = 48;
    AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}
#endif

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RdDTCReportSupportedDTC
* Description   : 
* Date          : 2020/2/17
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RdDTCReportSupportedDTC(void)
{
	INT8U cIndex;
	INT16U wNum = 3;
	const ST_DESC_DTCObj *psttStatusMask = gst_DTCTblInfo.pDTCObjTbl;

	gst_AppDescTpTxInfo.wDataLength = 3;
	gst_AppDescTpTxInfo.cDataBuf[2] = D_DTCStatusAvailabilityMask;
	for(cIndex = 0; cIndex < gst_DTCTblInfo.cDTCParaTblLen; cIndex ++)
	{
		gst_AppDescTpTxInfo.wDataLength += 4;
		if((wNum + 4) < D_DESC_TP_TX_DATA_BUF_SIZE)
		{
			gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[0];
			gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[1];
			gst_AppDescTpTxInfo.cDataBuf[wNum++] = gst_DTCTblInfo.pDTCParaTbl[cIndex].u1DTCCode[2];
			gst_AppDescTpTxInfo.cDataBuf[wNum++] = (psttStatusMask++)->stDTCStatusInfo.unStatusMask.Byte;
		}
	}
	gst_AppDescTpTxInfo.wDataLength = wNum;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_ReadDTCInformation
* Description   : 
* Date          : 2020/2/17
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_ReadDTCInformation(void)
{
	INT8U cIndex;
	INT8U cSubServiceFound = D_False;

	if((gst_ReadDTCInfoTbl[0].ServerReqLen != gst_AppDescTpRxInfo.wDataLength)&&\
	(gst_ReadDTCInfoTbl[1].ServerReqLen != gst_AppDescTpRxInfo.wDataLength)&&\
	(gst_ReadDTCInfoTbl[2].ServerReqLen != gst_AppDescTpRxInfo.wDataLength)&&\
	(gst_ReadDTCInfoTbl[3].ServerReqLen != gst_AppDescTpRxInfo.wDataLength))
	{
		/* Invalid Service Request Length */
		AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
		return;
	}
	for(cIndex = 0; cIndex < UBOUND(gst_ReadDTCInfoTbl); cIndex ++)
	{
		if((INT8U)gst_ReadDTCInfoTbl[cIndex].eSID == gst_AppDescTpRxInfo.cDataBuf[1])
		{
			cSubServiceFound = D_True;
			if(gst_ReadDTCInfoTbl[cIndex].ServerReqLen == gst_AppDescTpRxInfo.wDataLength)
			{
				if(D_True == DiagnoseAP_SessionSA_CfgChk(en_SID_READ_DTC_INFORMATION_INDEX))
				{
					return;
				}
				gst_ReadDTCInfoTbl[cIndex].pServerProcess();
			}
			else
			{
				/* Invalid Service Request Length */
				AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
			}
			break;
		}
	}
	if(cSubServiceFound == D_False)
	{
		/* Sub service not support */
		AppDescNrc = (D_DescNrcSubfunctionNotSupported);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_ReadDataByIdentifier
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_ReadDataByIdentifier(void)
{
	DiagnoseAP_WrRdDIDOp(D_DESC_DID_R);
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SecurityAccess_vogSeedGenerate
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_SecurityAccess_vogSeedGenerate(void)
{
	INT8U i, SeedChgFlg = D_True;

    uint32_t random_data = EXAMPLE_GPT_GetCurrentTimerCount();

    memcpy(&gst_SecurityAccess_stgOutInfo.u1SecLvSeed[0], &random_data, D_SecurityAccess_MSEEDNUM);

	gst_SecurityAccess_stgOutInfo.u1SecLvSeed[2] = ((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[0] << 2) & 0x1Cu) | \
			((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[1] << 5) & 0xE0u) | \
			((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[1] >> 6) & 0x03u);
	gst_SecurityAccess_stgOutInfo.u1SecLvSeed[3] = ((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[1] << 2) & 0x1Cu) | \
			((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[2] << 5) & 0xE0u) | \
			((gst_SecurityAccess_stgOutInfo.u1SecLvSeed[2] >> 6) & 0x03u);
	for(i = 0; i < D_SecurityAccess_MSEEDNUM; i++)
	{
		if(0 != gst_SecurityAccess_stgOutInfo.u1SecLvSeed[i])
		{
			SeedChgFlg = D_False;
		}
	}
	if(D_True == SeedChgFlg)
	{
		for(i = 0; i < D_SecurityAccess_MSEEDNUM; i++)
		{
			gst_SecurityAccess_stgOutInfo.u1SecLvSeed[i] = i + 0xAAu;
		}
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SecurityAccess_vogKeyGenerate
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void  DiagnoseAP_SecurityAccess_vogKeyGenerate(uint8_t level)
{
    uint32_t seed = 0;
    uint32_t KeyK = 0;
    uint32_t key = 0;

    /* get the seed that saved before */
    memcpy(&seed, &gst_SecurityAccess_stgOutInfo.u1SecLvSeed[0], sizeof(seed));

    /* get the KeyK according to the level */
    if(level == 1)
    {
        KeyK = D_KEY_K_LEVEL1;
    }
    else if(level == 2)
    {
        KeyK = D_KEY_K_LEVEL2;
    }
    else if(level == 3)
    {
        KeyK = D_KEY_K_LEVEL3;
    }
    else if(level == 4)
    {
        KeyK = D_KEY_K_LEVEL4;
    }
    else
    {

    }

    /* generate the key */
    SecM_ComputeKeyLevel3(seed, KeyK, &key);

    PRINTF("seed = 0x%x\r\n", seed);
    PRINTF("KeyK = 0x%x\r\n", KeyK);
    PRINTF("key = 0x%x\r\n", key);

    /* save the key, will be used to compare later */
    memcpy(&gst_SecurityAccess_stgOutInfo.u1SecLvKey[0], &key, D_SecurityAccess_MLVKEYNUM);
}


/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SecurityAccessServerAlreadyUnlock
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_SecurityAccessServerAlreadyUnlock(void)
{
	INT8U cIndex;
	AppDescSeedReceive = D_True;
	if(gst_AppDescTpRxInfo.cDataBuf[1] == D_DESC_SECURITY_ACCESS_REQUEST_LV1_SEED || \
			gst_AppDescTpRxInfo.cDataBuf[1] == D_DESC_SECURITY_ACCESS_REQUEST_LV3_SEED)
	{
		gst_AppDescTpTxInfo.wDataLength = 2;
		for(cIndex = 0; cIndex < D_SecurityAccess_MSEEDNUM; cIndex ++)
		{
			gst_AppDescTpTxInfo.cDataBuf[cIndex + 2] = 0;
			gst_AppDescTpTxInfo.wDataLength++;
		}
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SecurityAccessRequestSeed
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_SecurityAccessRequestSeed(BOOL u1tNotRepeatReqFlg)
{
	INT8U cIndex = 0;
	AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
	AppDescSeedReceive = D_True;
	if(D_True == u1tNotRepeatReqFlg)
	{
		DiagnoseAP_SecurityAccess_vogSeedGenerate();
	}

	gst_AppDescTpTxInfo.wDataLength = 2;
	for(cIndex = 0; cIndex < D_SecurityAccess_MSEEDNUM; cIndex ++)
	{
		gst_AppDescTpTxInfo.cDataBuf[cIndex + 2] = gst_SecurityAccess_stgOutInfo.u1SecLvSeed[cIndex];
		gst_AppDescTpTxInfo.wDataLength++;
	}
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_VosSecAccessReqSeed
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_VosSecAccessReqSeed(void)
{
	if(gst_AppDescTpRxInfo.wDataLength == 2)
	{
		if(gst_Desc_stsSecLvl.PreLvl != gst_Desc_stsSecLvl.CurrLvl)
		{
			gst_Desc_stsSecLvl.PreLvl = gst_Desc_stsSecLvl.CurrLvl;
			AppDescSeedReceive = D_False;
			AppDescUnlockStatus = D_False;
		}
		if(AppDescSeedReceive == D_True)
		{
			if(AppDescUnlockStatus == D_False)
			{
				DiagnoseAP_SecurityAccessRequestSeed(D_False);
			}
			else
			{
				DiagnoseAP_SecurityAccessServerAlreadyUnlock();
			}
		}
		else
		{
			if(D_True == AppDescUnlockStatus)
			{
				DiagnoseAP_SecurityAccessServerAlreadyUnlock();
			}
			else
			{
				DiagnoseAP_SecurityAccessRequestSeed(D_True);
			}
		}
	}
	else
	{
		AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_VosSecAccessSendKey
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_VosSecAccessSendKey(uint8_t level)
{
	INT8U Index;
	BOOL bKeyMatch = D_True;
	if(gst_AppDescTpRxInfo.wDataLength == 6)
	{
		AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
		if(AppDescSeedReceive == D_True)
		{
// 			AppDescSeedReceive = D_D_FALSE;
			if((gst_AppDescTpRxInfo.cDataBuf[2] == 0) && \
					(gst_AppDescTpRxInfo.cDataBuf[3] == 0) && \
					(gst_AppDescTpRxInfo.cDataBuf[4] == 0) && \
					(gst_AppDescTpRxInfo.cDataBuf[5] == 0))
			{
				AppDescNrc = (D_DescNrcRequestOutOfRange);
				return;
			}
			DiagnoseAP_SecurityAccess_vogKeyGenerate(level);
			for(Index = 0; Index < D_SecurityAccess_MLVKEYNUM; Index++)
			{
				if(gst_AppDescTpRxInfo.cDataBuf[2 + Index] != gst_SecurityAccess_stgOutInfo.u1SecLvKey[Index])
				{
					bKeyMatch = D_False;
				}
			}
			if(D_True == bKeyMatch)
			{
				memset(gst_SecurityAccess_stgOutInfo.u1SecLvSeed, 0, D_SecurityAccess_MSEEDNUM);
				gst_AppDescTpTxInfo.wDataLength = 2;
				AppDescUnlockStatus = D_True;
				AppDescSeedReceive = D_False;
				AppDescNrc = D_DescNrcOK;
				CAN_Diagnose_Msg_Rx_Flg = D_True;
				AppDescSecurityAccessErrCnt = 0;
			}
			else
			{
				if(AppDescUnlockStatus == D_True)
				{
					AppDescSeedReceive = D_False;
					AppDescNrc = (D_DescNrcRequestSequenceError);
				}
				else
				{
					/* Invalid Key, Denied */
					AppDescSeedReceive = D_False;
					AppDescNrc = (D_DescNrcInvalidKey);
					AppDescSecurityAccessErrCnt ++;
					if(AppDescSecurityAccessErrCnt == 3)
					{
						AppDescNrc = (D_DescNrcExceedNumOfAttempts);
						AppDescSecurityAccessErrWaitTime = 2000;
					}
				}
			}
		}
		else
		{
			AppDescNrc = (D_DescNrcRequestSequenceError);
		}
	}
	else
	{
		AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SecurityAccess
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_SecurityAccess(void)
{
	INT8U wIndex;
	BOOL	cSecurityAccessSubFound = D_False;
	INT8U u1tSubFun, u1tInfoLen;

	if(gst_AppDescTpRxInfo.cCANIDIndex == D_DIAGNOSE_RX_MSG_PHYSICAL)
	{
		u1tInfoLen = (INT8U)gst_AppDescTpRxInfo.wDataLength;
		if(!(u1tInfoLen == 2u || u1tInfoLen == 6u))
		{
			AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
			return;
		}

		u1tSubFun = gst_AppDescTpRxInfo.cDataBuf[1];
		for(wIndex = 0; wIndex < UBOUND(DesSecurityAccessSubID); wIndex++)
		{
			if(DesSecurityAccessSubID[wIndex] == u1tSubFun)
			{
				cSecurityAccessSubFound = D_True;
                break;
			}
		}
		if(D_True == cSecurityAccessSubFound)
		{
			if(AppDescSession != D_DESC_SESN_PRGS)
			{
				AppDescNrc = (D_DescNrcServiceNotSupportedInActiveSession);
			}
			else
			{
				if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_REQUEST_LV2_SEED)
				{
					//if(AppDescSession != D_DESC_SESN_PRGS)
					//{
					//	AppDescNrc = (D_DescNrcConditionsNotCorrect);
					//}
					//else
					{
						if(AppDescSecurityAccessErrWaitTime == 0u)
						{
							AppDescSecurityAccessLevel = 2u;
							DiagnoseAP_VosSecAccessReqSeed();
							if(AppDescSecurityAccessErrCnt == 3u)
							{
								AppDescSecurityAccessErrCnt--;
							}
						}
						else
						{
							AppDescNrc = (D_DescNrcTimeDelayNotExpired);
						}
					}
				}
				else if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_REQUEST_LV1_SEED)
				{
					if(AppDescSecurityAccessErrWaitTime == 0u)
					{
						AppDescSecurityAccessLevel = 1u;
						DiagnoseAP_VosSecAccessReqSeed();
						if(AppDescSecurityAccessErrCnt == 3u)
						{
							AppDescSecurityAccessErrCnt--;
						}
					}
					else
					{
						AppDescNrc = (D_DescNrcTimeDelayNotExpired);
					}
				}
				else if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_REQUEST_LV3_SEED)
				{
					if(AppDescSecurityAccessErrWaitTime == 0u)
					{
						AppDescSecurityAccessLevel = 3u;
						DiagnoseAP_VosSecAccessReqSeed();
						if(AppDescSecurityAccessErrCnt == 3u)
						{
							AppDescSecurityAccessErrCnt--;
						}
					}
					else
					{
						AppDescNrc = (D_DescNrcTimeDelayNotExpired);
					}
				}
				else if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_SEND_LV2_KEY)
				{
				    if(AppDescSecurityAccessLevel == 2u)
				    {
				    	DiagnoseAP_VosSecAccessSendKey(AppDescSecurityAccessLevel);
						AppDescSecurityAccessLevel = 0u;
				    }
					else
					{
						if(AppDescSeedReceive == D_True)
						{
							AppDescSeedReceive = D_False;
							AppDescNrc = (D_DescNrcSubfunctionNotSupported);
						}
						else
						{
							AppDescNrc = (D_DescNrcRequestSequenceError);
						}
						
					}
					
				}
				else if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_SEND_LV1_KEY)
				{
				    if(AppDescSecurityAccessLevel == 1u)
				    {
				    	DiagnoseAP_VosSecAccessSendKey(AppDescSecurityAccessLevel);
						AppDescSecurityAccessLevel = 0u;
				    }
					else
					{
						if(AppDescSeedReceive == D_True)
						{
							AppDescSeedReceive = D_False;
							AppDescNrc = (D_DescNrcSubfunctionNotSupported);
						}
						else
						{
							AppDescNrc = (D_DescNrcRequestSequenceError);
						}
					}
					
				}
				else if((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_SECURITY_ACCESS_SEND_LV3_KEY)
				{
				    if(AppDescSecurityAccessLevel == 3u)
				    {
				        DiagnoseAP_VosSecAccessSendKey(AppDescSecurityAccessLevel);
						AppDescSecurityAccessLevel = 0u;
				    }
					else
					{
						if(AppDescSeedReceive == D_True)
						{
							AppDescSeedReceive = D_False;
							AppDescNrc = (D_DescNrcSubfunctionNotSupported);
						}
						else
						{
							AppDescNrc = (D_DescNrcRequestSequenceError);
						}
					}

				}
				else
				{
					AppDescNrc = (D_DescNrcSubfunctionNotSupported);
				}
			}

		}
		else
		{
			AppDescNrc = (D_DescNrcSubfunctionNotSupported);
		}
	}
	else
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_CommunicationControl
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_CommunicationControl(void)
{
	INT8U cCtrlSubFuncIDIndex, cCtrlSubFuncID;
	//INT8U cCtrlSubFuncIDFound = D_False;
	cCtrlSubFuncID = (gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu);
	if(3u != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	if(D_DESC_SESN_EXTDS != AppDescSession)
	{
		AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		return;
	}
	for(cCtrlSubFuncIDIndex = 0; cCtrlSubFuncIDIndex < UBOUND(gst_ComCtrlTbl); cCtrlSubFuncIDIndex ++)
	{
		if(gst_ComCtrlTbl[cCtrlSubFuncIDIndex].eComCtrlType == (EN_COM_CTL_TYPE)cCtrlSubFuncID)
		{
			//cCtrlSubFuncIDFound = D_True;
			if((gst_AppDescTpRxInfo.cDataBuf[1]&0x80u)==0u) 
			{
				gst_ComCtrlTbl[cCtrlSubFuncIDIndex].ComCtrlInfo.ServiceProcess(gst_AppDescTpRxInfo.cDataBuf[2]);
			}
			else
			{
				if(gst_ComCtrlTbl[cCtrlSubFuncIDIndex].eComCtrlType == en_RxEnable_TxEnable)
				{
					CAN_Application_Msg_Rx_EnableFlg = D_True;
					CAN_Application_Msg_Tx_EnableFlg = D_True;
					AppDescNrc = D_DescNrcNoRsp;
				}
				else if(gst_ComCtrlTbl[cCtrlSubFuncIDIndex].eComCtrlType == en_RxEnable_TxDisable)
				{
					CAN_Application_Msg_Rx_EnableFlg = D_True;
					CAN_Application_Msg_Tx_EnableFlg = D_False;
					AppDescNrc = D_DescNrcNoRsp;
				}
				else if(gst_ComCtrlTbl[cCtrlSubFuncIDIndex].eComCtrlType == en_RxDisable_TxEnable)
				{
					CAN_Application_Msg_Rx_EnableFlg = D_False;
					CAN_Application_Msg_Tx_EnableFlg = D_True;
					AppDescNrc = D_DescNrcNoRsp;
				}
				else if(gst_ComCtrlTbl[cCtrlSubFuncIDIndex].eComCtrlType == en_RxDisable_TxDisable)
				{
					CAN_Application_Msg_Rx_EnableFlg = D_False;
					CAN_Application_Msg_Tx_EnableFlg = D_False;
					AppDescNrc = D_DescNrcNoRsp;
				}
				else
				{
					//MISRA:C:2012 15.7
					//All if ... else if constructs shall be terminated with an else statement
				}
			}
			return;
		}
	}
	
	//if(cCtrlSubFuncIDFound == D_False)
	{
	    if(gst_AppDescTpRxInfo.cCANIDIndex == (INT8U)en_TST_PhysicalReqAPA)
	    {
            AppDescNrc = D_DescNrcSubfunctionNotSupported;
	    }
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_WriteDataByIdentifier
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_WriteDataByIdentifier(void)
{
	DiagnoseAP_WrRdDIDOp(D_DESC_DID_W);
}

/******************************************IO DID Sub Function**************************************************/
/**********************************************************************************************************
* Function Name : DiagnoseAP_IOCtrl_0114_TestCtrl
* Description   : 
* Date          : 2020/3/4
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************/
void DiagnoseAP_IOCtrl_0114_TestCtrl(void)
{
	INT16U radarctrl;
	radarctrl = (INT16U)((INT16U)gst_AppDescTpRxInfo.cDataBuf[4] << 8) | (INT16U)gst_AppDescTpRxInfo.cDataBuf[5];
	if(radarctrl > 0xFFF)
	{
		AppDescNrc = D_DescNrcRequestOutOfRange;
		return;
	}
	if(gst_AppDescTpRxInfo.wDataLength == 6)
	{
		TestCtrl = (INT16U)((INT16U)gst_AppDescTpRxInfo.cDataBuf[4] << 8) | (INT16U)gst_AppDescTpRxInfo.cDataBuf[5];
		gst_AppDescTpTxInfo.cDataBuf[3] = 0x03;
		gst_AppDescTpTxInfo.cDataBuf[4] = gst_AppDescTpRxInfo.cDataBuf[4];
		gst_AppDescTpTxInfo.cDataBuf[5] = gst_AppDescTpRxInfo.cDataBuf[5];
		gst_AppDescTpTxInfo.wDataLength = 6;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
		Test_IOCtrlSts = en_IOCtrl_Vaild;
	}
	else
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
	}
}

/**********************************************************************************************************
* Function Name : DiagnoseAP_Get_TestCtrlSts
* Description   : 
* Date          : 2020/4/8
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************/
EN_IOCtrlStatus DiagnoseAP_Get_TestCtrlSts(void)
{
	return Test_IOCtrlSts;
}

/**********************************************************************************************************
* Function Name : DiagnoseAP_Get_TestCtrlVal
* Description   : 
* Date          : 2020/4/8
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************/
INT16U	DiagnoseAP_Get_TestCtrlVal(void)
{
	return TestCtrl;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_CheckInputOutputControlVaild
* Description   : 
* Date          : 2020/3/4
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_CheckInputOutputControlVaild(void)
{
	if(AppDescIOCtrlFlg == D_True)
	{
		if((AppDescSession == D_DESC_SESN_EXTDS) && (D_True == AppDescUnlockStatus))
		{
			
		}
		else
		{
			Test_IOCtrlSts = en_IOCtrl_Invaild;
			AppDescIOCtrlFlg = D_False;
		}
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_InputOutputControlByIdentifier
* Description   : 
* Date          : 2020/3/4
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_InputOutputControlByIdentifier(void)
{
	INT16U  wIndex, wCPID;
	INT8U cCPIDFound = D_False;
	//INT8U cCtrlTypeFound = D_False;
	
	if((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex)
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
		return;
	}

	if((gst_AppDescTpRxInfo.wDataLength != 4u) && (gst_AppDescTpRxInfo.wDataLength != 5u) && (gst_AppDescTpRxInfo.wDataLength != 6u))
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	/* Check the Request Format */
	wCPID = gst_AppDescTpRxInfo.cDataBuf[1];
	wCPID <<= 8;
	wCPID |= gst_AppDescTpRxInfo.cDataBuf[2];
	for(wIndex = 0; wIndex < UBOUND(gst_IOCtrlTbl); wIndex ++)
	{
		if(gst_IOCtrlTbl[wIndex].sCID == wCPID)
		{
			cCPIDFound = D_True;
			AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;

			if((INT8U)en_IOCTL_NonOperation == gst_AppDescTpRxInfo.cDataBuf[3])    //IO operate parameter = non operation
			{
				if(gst_AppDescTpRxInfo.wDataLength != 4)
				{
					AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
				    return;
				}
				if(D_True == DiagnoseAP_SessionSA_CfgChk(en_SID_IOCONTROL_BY_IDENTIFIER_INDEX))
				{
					return;
				}
				//cCtrlTypeFound = D_True;
				gst_AppDescTpTxInfo.cDataBuf[3] = 0;
	            gst_AppDescTpTxInfo.wDataLength = 4;
	            AppDescNrc = D_DescNrcOK;
	            CAN_Diagnose_Msg_Rx_Flg = D_True;
				AppDescIOCtrlFlg = D_False;
				
				switch(wCPID)
				{
					case 0x0114:
					{
						Test_IOCtrlSts = en_IOCtrl_Invaild;
						break;
					}
					default :
					{
						break;
					}
				}
				break;
				
			}
			else if((INT8U)en_IOCTL_InputOperation == gst_AppDescTpRxInfo.cDataBuf[3])    //IO operate parameter = Input operation
			{
				if((gst_AppDescTpRxInfo.wDataLength != 5) && (gst_AppDescTpRxInfo.wDataLength != 6)) 
				{
					AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
				    return;
				}
				if(D_True == DiagnoseAP_SessionSA_CfgChk(en_SID_IOCONTROL_BY_IDENTIFIER_INDEX))
				{
					return;
				}
				//cCtrlTypeFound = D_True;
				AppDescIOCtrlFlg = D_True;
				gst_IOCtrlTbl[wIndex].ServiceProcess();
				break;
			}
			else
			{
				//MISRA:C:2012 15.7
				//All if ... else if constructs shall be terminated with an else statement
			}
		
			//if(D_False == cCtrlTypeFound)
			{
				AppDescNrc = D_DescNrcRequestOutOfRange;
			}
			break;
		}
	}
	
	if(D_False == cCPIDFound)
	{
		AppDescNrc = (D_DescNrcRequestOutOfRange);
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RoutineControl
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RoutineControl(void)
{
	INT16U wRoutineCtrlID;
	INT8U  gBootRoutCtrlIDIndex;
	INT8U  cRoutineCtrlTypeIndex;
	//BOOL cRoutineCtrlIDFound = D_False;
	//BOOL cRoutineCtrlTypeFound = D_False;
	const ST_ROUTINTE_INFO *pBootRoutCtlInfo;

	if((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex)
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
		return;
	}
	
	wRoutineCtrlID = gst_AppDescTpRxInfo.cDataBuf[2];
	wRoutineCtrlID <<= 8u;
	wRoutineCtrlID |= gst_AppDescTpRxInfo.cDataBuf[3];

	if(gst_AppDescTpRxInfo.wDataLength < 4u)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	else if((wRoutineCtrlID == 0xC059u) ||(wRoutineCtrlID == 0xC059u))
	{
		if(gst_AppDescTpRxInfo.wDataLength > 4u)
		{
			AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
			return;
		}
	}
	else
	{
		//MISRA:C:2012 15.7
		//All if ... else if constructs shall be terminated with an else statement
	}

	for(gBootRoutCtrlIDIndex = 0; gBootRoutCtrlIDIndex < UBOUND(gst_RoutineCtlTbl); gBootRoutCtrlIDIndex++)
	{
		if(gst_RoutineCtlTbl[gBootRoutCtrlIDIndex].sDID == wRoutineCtrlID)
		{
			//cRoutineCtrlIDFound = D_True;
			if(AppDescSession == (gst_RoutineCtlTbl[gBootRoutCtrlIDIndex].SessionAllow & AppDescSession))
			{
				if((gst_RoutineCtlTbl[gBootRoutCtrlIDIndex].SecurityAllow == D_DESC_SA_FALSE) ||\
				((AppDescUnlockStatus == D_True)&&(gst_RoutineCtlTbl[gBootRoutCtrlIDIndex].SecurityAllow == D_DESC_SA_TRUE)))
				{
					for(cRoutineCtrlTypeIndex = 0; cRoutineCtrlTypeIndex < UBOUND(DescRoutineControlTypeID); cRoutineCtrlTypeIndex++)
					{
						if(DescRoutineControlTypeID[cRoutineCtrlTypeIndex] == gst_AppDescTpRxInfo.cDataBuf[1])
						{
							pBootRoutCtlInfo = &gst_RoutineCtlTbl[gBootRoutCtrlIDIndex].RoutineInfo[cRoutineCtrlTypeIndex];
							//cRoutineCtrlTypeFound = D_True;
							if(NULL == pBootRoutCtlInfo->ServiceProcess)
							{
								AppDescNrc = D_DescNrcSubfunctionNotSupported;
							}
							else if(pBootRoutCtlInfo->ReqDatLen == (gst_AppDescTpRxInfo.wDataLength - 4)) // eg. 31 01 FF 02 + Data;
							{
								pBootRoutCtlInfo->ServiceProcess();
							}
							else
							{
								AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
							}
							return;
						}
						else
						{
							AppDescNrc = (D_DescNrcSubfunctionNotSupported);
						}
					}
				}
				else
				{
					AppDescNrc = (D_DescNrcAccessDenied);
				}
			}
			else
			{
				AppDescNrc = (D_DescNrcServiceNotSupportedInActiveSession);
			}
			return;
		}
	}

	//if(cRoutineCtrlIDFound == D_False)
	{
		AppDescNrc = (D_DescNrcRequestOutOfRange);
	}
}

void Diagnose_RequestDownload(void)
{
	if((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex)
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
		return;
	}

    if(gst_AppDescTpRxInfo.wDataLength < 5) // length error NRC13
    {
        AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
        return;
    }

	if(D_DESC_SESN_PRGS != AppDescSession) // session error  NRC7F
	{
		AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		return;
	}

	if(FALSE == AppDescUnlockStatus) // security error NRC33
	{
	    AppDescNrc = (D_DescNrcAccessDenied);
	    return;
	}

    /* get memory address */
    DownloadInfo.FileLogicStartAddr = ToolMake32Bit( gst_AppDescTpRxInfo.cDataBuf[3],
                                                     gst_AppDescTpRxInfo.cDataBuf[4],
                                                     gst_AppDescTpRxInfo.cDataBuf[5],
                                                     gst_AppDescTpRxInfo.cDataBuf[6]  );

    /* get memory length */
    DownloadInfo.BlockDataLen= ToolMake32Bit(    gst_AppDescTpRxInfo.cDataBuf[7],
                                                gst_AppDescTpRxInfo.cDataBuf[8],
                                                gst_AppDescTpRxInfo.cDataBuf[9],
                                                gst_AppDescTpRxInfo.cDataBuf[10] );

    if(D_FlashDrvCodeStart_Addr == DownloadInfo.FileLogicStartAddr) // FlashDriver address
    {
        DownloadAppCodeFlg = FALSE;

        /* download of flash driver request */
        if((0 == DownloadInfo.BlockDataLen) || (DownloadInfo.BlockDataLen > FLASH_DRV_CODE_SIZE))
        {
            AppDescNrc = (D_DescNrcRequestOutOfRange);
            return;
        }

        DownloadFlashDrvFlg = TRUE;
    }
    else
    {
        DownloadFlashDrvFlg = FALSE;
        if(TRUE == CheckAppCodeSectorStartAddr(DownloadInfo.FileLogicStartAddr))
        {
            DownloadAppCodeFlg = TRUE;
        }
        else
        {
            AppDescNrc = (D_DescNrcUploadDownloadNotAccepted);  // NRC70
            return;
        }
    }

    DownloadInfo.BlockSurplusDataLen = DownloadInfo.BlockDataLen;
    DownloadInfo.CurrentLogicAddr = DownloadInfo.FileLogicStartAddr;
    DownloadInfo.CurrentSequenceCnt = 0;
    DownloadInfo.ExpectedSequenceCnt= 1;
    DownloadInfo.SameBlockRetryTimesCnt = D_SameBlockRetryTimes;

    if(TRUE == DownloadFlashDrvFlg)
    {
        DownloadInfo.SectorMaxLen = FLASH_DRV_CODE_SIZE;
    }
    else
    {
        if(TRUE == DownloadAppCodeFlg)
        {
            DownloadInfo.SectorMaxLen = FLASH_SECTOR_SIZE;
            DownloadInfo.FileGlobalStartAddr = DownloadInfo.FileLogicStartAddr;
            DownloadInfo.CurrentGlobalAddr = DownloadInfo.CurrentLogicAddr;
        }
    }

    //fill response data
    // DataFormatIdentifier default is 0x20 // bit7-bit4 block size,bit3-bit0 address(reserved)
    gst_AppDescTpTxInfo.cDataBuf[1] = 0x20;
    // MaxNumberOfBlockLength
    gst_AppDescTpTxInfo.cDataBuf[2] = ToolGetHiByte(D_DESC_TP_RX_DATA_BUF_SIZE);
    gst_AppDescTpTxInfo.cDataBuf[3] = ToolGetLoByte(D_DESC_TP_RX_DATA_BUF_SIZE);

    gst_AppDescTpTxInfo.wDataLength =  (gst_AppDescTpTxInfo.cDataBuf[1] >> 4) + 2u;
    AppDescNrc = D_DescNrcOK;
    CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void Diagnose_DescTransferData(void)
{
    static int8_t FlashBlockCntFlag = 0;

	if((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex)
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
		return;
	}

	if(D_DESC_SESN_PRGS != AppDescSession) // session error  NRC7F
	{
		AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		return;
	}

	if(FALSE == AppDescUnlockStatus) // security error NRC33
	{
	    AppDescNrc = (D_DescNrcAccessDenied);
	    return;
	}

    DownloadInfo.CurrentDataLen = gst_AppDescTpRxInfo.wDataLength - 2;
    if(DownloadInfo.CurrentDataLen < 1) // length error NRC13
    {
        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
        return;
    }

    if(gst_AppDescTpRxInfo.cDataBuf[1] == DownloadInfo.ExpectedSequenceCnt) 
    {
        DownloadInfo.SameBlockRetryTimesCnt = D_SameBlockRetryTimes;
    }
    else
    {
        if(((DownloadInfo.ExpectedSequenceCnt == 0u) && (gst_AppDescTpRxInfo.cDataBuf[1] == 0xFF))||\
        ((DownloadInfo.ExpectedSequenceCnt != 0u) && (gst_AppDescTpRxInfo.cDataBuf[1] == (DownloadInfo.ExpectedSequenceCnt-1u))))
        {
    		gst_AppDescTpTxInfo.cDataBuf[0] = 0x36 + 0x40u;
            gst_AppDescTpTxInfo.cDataBuf[1] = DownloadInfo.CurrentSequenceCnt;
            gst_AppDescTpTxInfo.wDataLength = 2;
            AppDescNrc = D_DescNrcOK;
            CAN_Diagnose_Msg_Rx_Flg = D_True;

            DownloadInfo.SameBlockRetryTimesCnt = D_SameBlockRetryTimes; 
            return;
        }
        else
        {
            if(DownloadInfo.SameBlockRetryTimesCnt) 
            {
                DownloadInfo.SameBlockRetryTimesCnt --;
                AppDescNrc = (D_DescNrcWrongBlockSequenceCounter); // block sequence error NRC73
                return;
            }
            else
            {
                AppDescNrc = (D_DescNrcTransferDataSuspended);//Transfer Data Suspended NRC71
                return;
            }
        }
    }

    // FlashDrv or AppCode
    if(TRUE == DownloadFlashDrvFlg) // FlashDrv
    {
        if((0x00 == ReqDownloadFlashBlockCnt) && (0x00 == DownloadInfo.CurrentSequenceCnt)) // ���ص�һ����ʱ, �������ļ���Ϣ
        {
            if(FALSE == CheckFlashDrvIsValid()) 
            {
                AppDescNrc = D_DescNrcGeneralProgrammingFailure;

                return;
            }
        }


        AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
        if(PROG_REQ_OK == Prog_WriteFlashDrvToRam())
        {
            DownloadInfo.CurrentSequenceCnt = DownloadInfo.ExpectedSequenceCnt;
            DownloadInfo.ExpectedSequenceCnt ++;
			if(DownloadInfo.ExpectedSequenceCnt == 0)
			{
				//DownloadInfo.ExpectedSequenceCnt = 1;
			}

            // Sequence counter value of next transferData request
    		gst_AppDescTpTxInfo.cDataBuf[0] = 0x36 + 0x40u;
            gst_AppDescTpTxInfo.cDataBuf[1] = DownloadInfo.CurrentSequenceCnt;

            gst_AppDescTpTxInfo.wDataLength = 2;
            AppDescNrc = D_DescNrcOK;
            CAN_Diagnose_Msg_Rx_Flg = D_True;
        }
        else
        {
            AppDescNrc = D_DescNrcGeneralProgrammingFailure;
        }

    }
    else
    {
        if(TRUE == DownloadAppCodeFlg) // App code
        {
            if((FlashBlockCntFlag==0u)&&\
            (0x00 == ReqDownloadFlashBlockCnt) && (0x00 == DownloadInfo.CurrentSequenceCnt)) // ���ص�һ����ʱ, �������ļ���Ϣ
            {
                if(TRUE == CheckAppFileIsValid())
                {

                }
				else
				{
                    AppDescNrc = D_DescNrcGeneralProgrammingFailure;

                    return;
				}
            }

            AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME; // ����ʱ��
            if(PROG_REQ_OK == DealReceiveData())
            {
                DownloadInfo.CurrentSequenceCnt = DownloadInfo.ExpectedSequenceCnt;
                if(DownloadInfo.ExpectedSequenceCnt == 0u)
                {
                    FlashBlockCntFlag=1;
                }
                else
                {
                    FlashBlockCntFlag=0;
                }

                DownloadInfo.ExpectedSequenceCnt ++;
				if(DownloadInfo.ExpectedSequenceCnt == 0)
				{
					//DownloadInfo.ExpectedSequenceCnt = 1;
				}

                // Sequence counter value of next transferData request
        		gst_AppDescTpTxInfo.cDataBuf[0] = 0x36 + 0x40u;
                gst_AppDescTpTxInfo.cDataBuf[1] = DownloadInfo.CurrentSequenceCnt;

                gst_AppDescTpTxInfo.wDataLength = 2;
                AppDescNrc = D_DescNrcOK;
                CAN_Diagnose_Msg_Rx_Flg = D_True;
            }
            else
            {
                AppDescNrc = D_DescNrcGeneralProgrammingFailure;
                FlashBlockCntFlag=0;
            }
        }
    }
}

void Diagnose_RequestTransferExit(void)
{
	if((INT8U)en_TST_PhysicalReqAPA != gst_AppDescTpRxInfo.cCANIDIndex)
	{
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		AppDescNrc = D_DescNrcNoRsp;
		return;
	}

	if(D_DESC_SESN_PRGS != AppDescSession) // session error  NRC7F
	{
		AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		return;
	}

	if(FALSE == AppDescUnlockStatus) // security error NRC33
	{
	    AppDescNrc = (D_DescNrcAccessDenied);
	    return;
	}

    DownloadInfo.CurrentDataLen = gst_AppDescTpRxInfo.wDataLength - 2;
    if(DownloadInfo.CurrentDataLen < 1) // length error NRC13
    {
        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
        return;
    }

    gst_AppDescTpTxInfo.wDataLength = 1;
    AppDescNrc = D_DescNrcOK;
    CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_ControlDTCSetting
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_ControlDTCSetting(void)
{
	if(2 != gst_AppDescTpRxInfo.wDataLength)
	{
		AppDescNrc = D_DescNrcIncorrectMessageLengthOrInvalidFormat;
		return;
	}
	if(D_DESC_SESN_EXTDS != AppDescSession)
	{
		AppDescNrc = D_DescNrcServiceNotSupportedInActiveSession;
		return;
	}
	if(((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_CONTROL_DTC_SETTING_ON) || \
	((gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu) == D_DESC_CONTROL_DTC_SETTING_OFF))
	{
	    AppDescControlDTCSetting = gst_AppDescTpRxInfo.cDataBuf[1] & 0x7Fu;
	    gst_AppDescTpTxInfo.wDataLength = 2u;
	    if(0x80u == (gst_AppDescTpRxInfo.cDataBuf[1] & 0x80u))
		{
			gst_AppDescTpRxState.engine = en_RxState_Idle;
			gst_AppDescTpTxState.engine = en_TxState_Idle;
			AppDescNrc = D_DescNrcNoRsp;
		}
		else
		{
			AppDescNrc = D_DescNrcOK;
			CAN_Diagnose_Msg_Rx_Flg = D_True;
		}
	}
	else
	{
	    if(gst_AppDescTpRxInfo.cCANIDIndex == (INT8U)en_TST_PhysicalReqAPA)
	    {
	        AppDescNrc = D_DescNrcSubfunctionNotSupported;
	    }
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_EcuHardReset
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_EcuHardReset(void)
{
    /* Board resetting should after the response */
    __NVIC_SystemReset();
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_SendNegResp
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
static	void DiagnoseAP_SendNegResp(INT8U      cRespCode)
{
	gst_AppDescTpTxInfo.cDataBuf[1] = gst_AppDescTpTxInfo.cDataBuf[0] - 0x40;
	gst_AppDescTpTxInfo.cDataBuf[0] = D_DESC_NEGATIVE_RESPONSE_SERVICE_ID;
	gst_AppDescTpTxInfo.cDataBuf[2] = cRespCode;
	gst_AppDescTpTxInfo.wDataLength = 3;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_Task_Server
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void  DiagnoseAP_Task_Server(void)
{
	INT8U	cIndex;
	INT8U	cServiceFound = D_False;
	EN_DESC_SID_TYPE eBOOT_ReqSID;

	if(D_True == AppDescSessionChangedFlg)
	{
		AppDescSessionChangedFlg = D_False;
		gst_Desc_stsSecLvl.CurrLvl = en_Desc_SecNonLvl;
		gst_Desc_stsSecLvl.PreLvl = en_Desc_SecNonLvl;
	}

	/////////start
	if(AppDescTimer100ms > 0)
	{
		AppDescTimer100ms --;
	}
	
	if(AppDescTimer100ms == 0)
	{
		AppDescTimer100ms = D_DESC_TIMER_100MS;
		if(AppDescTesterPresentTimer > 0)
		{
			AppDescTesterPresentTimer  --;
		}
		if(AppDescTesterPresentTimer == 0)
		{
			AppDescUnlockStatus = D_False;
			AppDescCurrRoutine = 0;
			AppDescSeedReceive = D_False;
			if(AppDescSession != D_DESC_SESN_DS)
			{
				AppDescSession = D_DESC_SESN_DS;
				AppDescControlDTCSetting = D_DESC_CONTROL_DTC_SETTING_ON;  
				CAN_Application_Msg_Rx_EnableFlg = D_True;
				CAN_Application_Msg_Tx_EnableFlg = D_True;
			}
		}
	}
	
	//////till here
	if(D_True == AppDescECUHardRestReq)
	{
		AppDescECUHardRestReq = D_False;
        DiagnoseAP_EcuHardReset();
	}

	if(gst_AppDescTpRxState.engine == en_RxState_CanFrameReceived)
	{
		//AppDescTesterPresentTimer = D_DESC_TESTER_PRESENT_TIME_OUT_DELAY_TIME;
		gst_AppDescTpRxState.engine = en_RxState_ApplInformed;
		AppDescP4Timer = D_DESC_P2_CAN_SERVER_MAX;
		eBOOT_ReqSID = (EN_DESC_SID_TYPE)gst_AppDescTpRxInfo.cDataBuf[0];
		AppDescNrc = D_DescNrcNoRsp;
		for(cIndex = 0; cIndex < UBOUND(gst_DescHandlerTbl); cIndex ++)
		{
			if((gst_DescHandlerTbl[cIndex].eDESC_SID == eBOOT_ReqSID) && (NULL != gst_DescHandlerTbl[cIndex].pServerProcess))
			{
				if((en_SID_TESTER_PRESENT != eBOOT_ReqSID) || \
				((en_SID_TESTER_PRESENT == eBOOT_ReqSID) && (gst_AppDescTpRxInfo.cDataBuf[1] == 0x00u)))
				{
						AppDescOpTimeLongerThanP2Flag = D_False;
						AppWrDescP4Timer = D_DESC_P2_CAN_SERVER_MAX;
				}
				cServiceFound = D_True;
				AppDescRespNoSend = D_True;
				AppDescP4Timer = gDescServiceRespTimeTbl[cIndex];
				gst_AppDescTpTxInfo.cDataBuf[0] = (INT8U)eBOOT_ReqSID + 0X40u;
				/* Service Format is ok */
				gst_AppDescTpTxInfo.cDataBuf[1] = gst_AppDescTpRxInfo.cDataBuf[1];
				gst_AppDescTpTxInfo.cDataBuf[2] = gst_AppDescTpRxInfo.cDataBuf[2];
				if(eBOOT_ReqSID == en_SID_CLR_DIAGNOSTIC_DTC)
				{
					gst_DescLngTmRspInfo.u1RspSID = (INT8U)eBOOT_ReqSID + 0X40u;
					gst_DescLngTmRspInfo.u1DID0 = gst_AppDescTpRxInfo.cDataBuf[1];
					gst_DescLngTmRspInfo.u1DID1 = gst_AppDescTpRxInfo.cDataBuf[2];
				}
				gst_DescHandlerTbl[cIndex].pServerProcess();
				break;
			}
		}

		if(cServiceFound == D_False)
		{
            AppDescOpTimeLongerThanP2Flag = D_False;
            AppWrDescP4Timer = D_DESC_P2_CAN_SERVER_MAX;
			AppDescP4Timer = D_DESC_P2_CAN_SERVER_MAX;
			if(gst_AppDescTpRxInfo.cCANIDIndex == (INT8U)en_TST_PhysicalReqAPA)
			{
				gst_AppDescTpTxInfo.cDataBuf[0] = gst_AppDescTpRxInfo.cDataBuf[0] + 0X40u;
				AppDescNrc = (D_DescNrcServiceNotSupported);
			}
			else
			{
				gst_AppDescTpRxState.engine = en_RxState_Idle;
				gst_AppDescTpTxState.engine = en_TxState_Idle;
				AppDescNrc = D_DescNrcNoRsp;
			}
		}
	}

	if(D_DescNrcOK < AppDescNrc)
	{
		DiagnoseAP_SendNegResp(AppDescNrc);
	}

	if(D_DescNrcNoRsp != AppDescNrc)
	{
		DiagnoseTP_TxStart();
		AppDescNrc = D_DescNrcNoRsp;
	}

	/////////
	if(AppDescP4Timer > 0u)
	{
		AppDescP4Timer -- ;
	}
	
	if((AppDescP4Timer == 0u) && (gst_AppDescTpRxState.engine == en_RxState_ApplInformed) && (D_True == AppDescRespNoSend))
	{
		AppDescRespNoSend = D_False;
		gst_AppDescTpRxState.engine = en_RxState_Idle;
		gst_AppDescTpTxState.engine = en_TxState_Idle;
	}

	DiagnoseAP_CheckInputOutputControlVaild();

}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_APP_Init
* Description   : 
* Date          : 2019/12/25
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_APP_Init(void)
{
	MwCAN_Init();
	DiagnoseTP_Init();
	DiagnoseCAN_Init();
	DiagnoseDTC_Init();

	AppDescSession = D_DESC_SESN_DS;
	AppDescNrc = D_DescNrcNoRsp;
	AppDescTesterPresentTimer = 0;
	AppDescP4Timer = 0;
	AppDescUnlockStatus = D_False;
	AppDescSeedReceive = D_False;
	AppDescTimer100ms = D_DESC_TIMER_100MS;
	AppDescSessionChangedFlg = D_False;
	AppDescPrevSession = 0;
	AppDescRespNoSend = D_True;
	gst_Desc_stsSecLvl.CurrLvl = en_Desc_SecNonLvl;
	gst_Desc_stsSecLvl.PreLvl = en_Desc_SecNonLvl;
	AppDescControlDTCSetting = D_DESC_CONTROL_DTC_SETTING_ON;
}

//---------------------- DID Function Define Start -----------------------------
/*
**********************************************************************************************************
* Function Name : DiagnoseAP_DID_Read_F193_SupplierHWVersion
* Description   : 
* Date          : 2020/1/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_DID_Read_F193_SupplierHWVersion(void)
{
	for(INT8U i = 0;i < D_LEN_DIDF193;i++)
	{
		gst_AppDescTpTxInfo.cDataBuf[3+i] = SupplierHWVersion[i];
	}
	
	gst_AppDescTpTxInfo.wDataLength = D_LEN_DIDF193 + 3;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_DID_Read_F195_SupplierSWVersion
* Description   : 
* Date          : 2020/1/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_DID_Read_F195_SupplierSWVersion(void)
{
	for(INT8U i = 0;i < D_LEN_DIDF195;i++)
	{
		gst_AppDescTpTxInfo.cDataBuf[3+i] = SupplierSWVersion[i];
	}
	
	gst_AppDescTpTxInfo.wDataLength = D_LEN_DIDF195 + 3;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_DID_Read_F18C_ECUSN
* Description   : 
* Date          : 2020/3/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_DID_Read_F18C_ECUSN(void)
{
	for(INT8U i = 0;i < D_LEN_DIDF18C;i++)
	{
		gst_AppDescTpTxInfo.cDataBuf[3+i] = ECUSN[i];
	}

	gst_AppDescTpTxInfo.cDataBuf[15] = (INT8U)' ';
	gst_AppDescTpTxInfo.cDataBuf[16] = (INT8U)' ';
	
	gst_AppDescTpTxInfo.wDataLength = D_LEN_DIDF18C + 3u;
	AppDescNrc = (D_DescNrcOK);
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_DID_Write_F18C_ECUSN
* Description   : 
* Date          : 2020/3/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_DID_Write_F18C_ECUSN(void)
{
	for(INT8U i = 0;i < D_LEN_DIDF18C; i++)
	{
		ECUSN[i] = gst_AppDescTpTxInfo.cDataBuf[3 + i];
	}
	gst_AppDescTpTxInfo.wDataLength = 3;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void DiagnoseAP_DID_Read_F15A_Fingerprint(void)
{
    gst_AppDescTpTxInfo.cDataBuf[3] = Fingerprint.Year;
    gst_AppDescTpTxInfo.cDataBuf[4] = Fingerprint.Month;
    gst_AppDescTpTxInfo.cDataBuf[5] = Fingerprint.Day;

	for(INT8U i = 0;i < sizeof(Fingerprint.RepairShopCode);i++)
	{
		gst_AppDescTpTxInfo.cDataBuf[6+i] = Fingerprint.RepairShopCode[i];
	}

    PRINTF("Date: 20%x-%x-%x\r\n", Fingerprint.Year, Fingerprint.Month, Fingerprint.Day);
    PRINTF("RepairShopCode: %s\r\n", (char *)(&Fingerprint.RepairShopCode[0]));

	gst_AppDescTpTxInfo.wDataLength = D_LEN_DIDF15A + 3u;
	AppDescNrc = (D_DescNrcOK);
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void DiagnoseAP_DID_Write_F15A_Fingerprint(void)
{
    Fingerprint.Year = gst_AppDescTpRxInfo.cDataBuf[3];
    Fingerprint.Month = gst_AppDescTpRxInfo.cDataBuf[4];
    Fingerprint.Day = gst_AppDescTpRxInfo.cDataBuf[5];

	for(INT8U i = 0;i < sizeof(Fingerprint.RepairShopCode);i++)
	{
		Fingerprint.RepairShopCode[i] = gst_AppDescTpRxInfo.cDataBuf[6 + i];
	}

    ReqDownloadFlashBlockCnt = 0;

    PRINTF("Date: 20%x-%x-%x\r\n", Fingerprint.Year, Fingerprint.Month, Fingerprint.Day);
    PRINTF("RepairShopCode: %s\r\n", (char *)(&Fingerprint.RepairShopCode[0]));

	gst_AppDescTpTxInfo.wDataLength = 3;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void DiagnoseAP_RoutineCtrl_FF00_EraseMemory_StartRoutile(void)
{
    if(gst_AppDescTpRxInfo.cDataBuf[4] != D_FlashEraseAddrAndLen_Format)
    {
        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
        return;
    }

    // get memory address
    DownloadInfo.FileStartAddr = ToolMake32Bit( gst_AppDescTpRxInfo.cDataBuf[5],
                                                gst_AppDescTpRxInfo.cDataBuf[6],
                                                gst_AppDescTpRxInfo.cDataBuf[7],
                                                gst_AppDescTpRxInfo.cDataBuf[8]  );
    // get memory length
    DownloadInfo.FileDataLen = ToolMake32Bit(   gst_AppDescTpRxInfo.cDataBuf[9],
                                                gst_AppDescTpRxInfo.cDataBuf[10],
                                                gst_AppDescTpRxInfo.cDataBuf[11],
                                                gst_AppDescTpRxInfo.cDataBuf[12] );

    DownloadInfo.FileSurplusDataLen = DownloadInfo.FileDataLen;

    // Check flash erase address is ok
    if(APP_CODE_START_ADDR != DownloadInfo.FileStartAddr)
    {
        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
        return;
    }
    if((0 == DownloadInfo.FileDataLen) || (DownloadInfo.FileDataLen > APP_CODE_MAX_SIZE))
    {
        AppDescNrc = (D_DescNrcIncorrectMessageLengthOrInvalidFormat);
        return;
    }

    ReqDownloadFlashBlockCnt = 0x00;

    gst_AppDescTpTxInfo.cDataBuf[0] = 0x31 + 0x40u;
    gst_AppDescTpTxInfo.cDataBuf[1] = 0x01;
    gst_AppDescTpTxInfo.cDataBuf[2] = 0xFF;
    gst_AppDescTpTxInfo.cDataBuf[3] = 0x00;
    gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

    gst_AppDescTpTxInfo.wDataLength = 5u;
    AppDescNrc = (D_DescNrcOK);
    CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void DiagnoseAP_RoutineCtrl_FF01_CheckProDependencies_StartRoutile(void)
{
	gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
	gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
	gst_AppDescTpTxInfo.cDataBuf[2] = 0xFFu;
	gst_AppDescTpTxInfo.cDataBuf[3] = 0x01u;
	gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

	gst_AppDescTpTxInfo.wDataLength = 5u;
	AppDescNrc = (D_DescNrcOK);
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

//---------------------- RoutineCtl Function Define Start ----------------------
void DiagnoseAP_RoutineCtrl_FF02_CheckProgPrecondition_StartRoutile(void)
{
    if(D_True == IsE2promPwrVoltNormal())
    {
    	gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
    	gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
    	gst_AppDescTpTxInfo.cDataBuf[2] = 0xFFu;
    	gst_AppDescTpTxInfo.cDataBuf[3] = 0x02u;
        gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

        gst_AppDescTpTxInfo.wDataLength = 5u;
        AppDescNrc = (D_DescNrcOK);
		CAN_Diagnose_Msg_Rx_Flg = D_True;
    }
    else
    {
        AppDescNrc = (D_DescNrcConditionsNotCorrect);
        return;
    }
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StartRoutile
* Description   : 
* Date          : 2020/3/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StartRoutile(void)
{
	DiagnoseDTC_ResetToFactoryClearAllDTCInformation();

	AppDescCurrRoutine = 0x01;
	AppDescRestToFactoryModeFlg = D_True;
	gst_AppDescTpTxInfo.cDataBuf[0] = 0x31 + 0x40u;
	gst_AppDescTpTxInfo.cDataBuf[1] = 0x01;
	gst_AppDescTpTxInfo.cDataBuf[2] = 0xC0;
	gst_AppDescTpTxInfo.cDataBuf[3] = 0x59;
	gst_AppDescTpTxInfo.cDataBuf[4] = 0X02;   //0x02 means that Routine completed with OK

	gst_AppDescTpTxInfo.wDataLength = 5u;
	AppDescNrc = D_DescNrcOK;
	CAN_Diagnose_Msg_Rx_Flg = D_True;
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StopRoutile
* Description   : 
* Date          : 2020/3/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_StopRoutile(void)
{
	if(AppDescCurrRoutine == 0x01)
	{
		gst_AppDescTpTxInfo.cDataBuf[0] = 0x31 + 0x40u;
		gst_AppDescTpTxInfo.cDataBuf[1] = 0x02;
		gst_AppDescTpTxInfo.cDataBuf[2] = 0xC0;
		gst_AppDescTpTxInfo.cDataBuf[3] = 0x59;
		gst_AppDescTpTxInfo.cDataBuf[4] = 0X02;   //0x02 means that Routine completed with OK

		gst_AppDescTpTxInfo.wDataLength = 5u;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestSequenceError;
	}
}

/*
**********************************************************************************************************
* Function Name : DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_RequestRoutileResult
* Description   : 
* Date          : 2020/3/6
* Parameter     : void
* Return Code   : void
* Author        : Leng
**********************************************************************************************************
*/
void DiagnoseAP_RoutineCtrl_C059_ResetToFactortyMode_RequestRoutileResult(void)
{
	if(AppDescCurrRoutine == 0x01)
	{
		gst_AppDescTpTxInfo.cDataBuf[0] = 0x31 + 0x40u;
		gst_AppDescTpTxInfo.cDataBuf[1] = 0x03;
		gst_AppDescTpTxInfo.cDataBuf[2] = 0xC0;
		gst_AppDescTpTxInfo.cDataBuf[3] = 0x59;
		gst_AppDescTpTxInfo.cDataBuf[4] = 0X02;   //0x02 means that Routine completed with OK

		gst_AppDescTpTxInfo.wDataLength = 5u;
		AppDescNrc = D_DescNrcOK;
		CAN_Diagnose_Msg_Rx_Flg = D_True;
	}
	else
	{
		AppDescNrc = D_DescNrcRequestSequenceError;
	}
}

void DiagnoseAP_RoutineCtrl_D002_CheckMemory_StartRoutile(void)
{
    if(DownloadFlashDrvFlg == TRUE)
    {
        //current do not support downloading flash driver, just response positive
        gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
        gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
        gst_AppDescTpTxInfo.cDataBuf[2] = 0xD0u;
        gst_AppDescTpTxInfo.cDataBuf[3] = 0x02u;
        gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

        gst_AppDescTpTxInfo.wDataLength = 5u;
        AppDescNrc = (D_DescNrcOK);
        CAN_Diagnose_Msg_Rx_Flg = D_True;
    }
    else if(DownloadAppCodeFlg == TRUE)
    {
        gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
        gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
        gst_AppDescTpTxInfo.cDataBuf[2] = 0xD0u;
        gst_AppDescTpTxInfo.cDataBuf[3] = 0x02u;
        gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

        gst_AppDescTpTxInfo.wDataLength = 5u;
        AppDescNrc = (D_DescNrcOK);
        CAN_Diagnose_Msg_Rx_Flg = D_True;
    }
}

void DiagnoseAP_RoutineCtrl_D003_CheckProgPrecondition_StartRoutile(void)
{
    if(D_True == IsE2promPwrVoltNormal())
    {
        gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
        gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
        gst_AppDescTpTxInfo.cDataBuf[2] = 0xD0u;
        gst_AppDescTpTxInfo.cDataBuf[3] = 0x03u;
        gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

        gst_AppDescTpTxInfo.wDataLength = 5u;
        AppDescNrc = (D_DescNrcOK);
        CAN_Diagnose_Msg_Rx_Flg = D_True;
    }
    else
    {
        AppDescNrc = (D_DescNrcConditionsNotCorrect);
    }
}

void DiagnoseAP_RoutineCtrl_D004_CheckProgPrecondition_StartRoutile(void)
{
    /* MCU no need security signature check, just response correct */
    gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
    gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
    gst_AppDescTpTxInfo.cDataBuf[2] = 0xD0u;
    gst_AppDescTpTxInfo.cDataBuf[3] = 0x04u;
    gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

    gst_AppDescTpTxInfo.wDataLength = 5u;
    AppDescNrc = (D_DescNrcOK);
    CAN_Diagnose_Msg_Rx_Flg = D_True;
}

void DiagnoseAP_RoutineCtrl_D005_FlashFileInstallation_StartRoutile(void)
{
    int ret = 0;
    if(FLEXSPI_NorFlash_Get_Cur_Running_Area() == RUNNING_AREA_APP)
    {
        /* running in app area, means that we are upgrading the app backup area */
        /* ProgramAppBackupAreaHeader and EraseAppAreaHeader at the last step */
        ret = ProgramAppBackupAreaHeader();
        if(ret == 0)
        {
            ret = EraseAppAreaHeader();
        }
    }
    else
    {
        /* running in bootloader area or app backup area, means that we are upgrading the app area */
        /* ProgramAppAreaHeader and EraseAppBackupAreaHeader at the last step */
        ret = ProgramAppAreaHeader();
        if(ret == 0)
        {
            ret = EraseAppBackupAreaHeader();
        }
    }

    if(ret == 0)
    {
        gst_AppDescTpTxInfo.cDataBuf[0] = 0x31u + 0x40u;
        gst_AppDescTpTxInfo.cDataBuf[1] = 0x01u;
        gst_AppDescTpTxInfo.cDataBuf[2] = 0xD0u;
        gst_AppDescTpTxInfo.cDataBuf[3] = 0x05u;
        gst_AppDescTpTxInfo.cDataBuf[4] = D_ROUTINESTATUSRECODE_CORRET;

        gst_AppDescTpTxInfo.wDataLength = 5u;
        AppDescNrc = (D_DescNrcOK);
        CAN_Diagnose_Msg_Rx_Flg = D_True;
    }
    else
    {
        AppDescNrc = D_DescNrcGeneralProgrammingFailure;
    }
}
//---------------------- RoutineCtl Function Define End ----------------------
