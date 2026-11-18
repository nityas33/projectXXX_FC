//
// my_stubs.h
// Copyright (C) 2019 Robert Bosch GmbH. All rights reserved.
//
// This file contains stubs that allow this project to compile.
//

#pragma once
#include "common.h"
#include "dsm.h"
#include "eep.h"
#include "syc.h"
#include "coeng.h"
#include "cdgen.h"
#include "srv.h"
// [BCU-GeneratedIncludes-Start]
#include "my_config.h"
#include "my_pavast_stubs.h"
// [BCU-GeneratedIncludes-End]

BCU_BEGIN_C_HEADER

///////////////////////////////////////////////////////////////////////////////

// [BCU-GeneratedCode-Start]
// [BCU-GeneratedCode-End]

// Add more stub declarations here

///////////////////////////////////////////////////////////////////////////////

BCU_END_C_HEADER
extern void Mo_Fault_Injection_CplChk();
extern void Mo_Fault_Injection_VldFloatChk();
extern void MonEgyChrgnInlet_Inp_Proc();
extern void MonEgyChrgnInlet_Inp_Proc_Ini();
uint8 Mo_SyC_stSub;
extern uint16 ret_UCtP_I_A;
extern uint16 ret_UPxP1_I_A;
extern uint16 ret_IntlckChrgPlgPosn_I_A;
extern uint16 ret_McsChrgEnaLineU_I_A;
extern uint16 ret_McsInsertDetnLineU_I_A;
extern uint16 ret_IntlckChrgPlg3Posn_I_A;
extern uint16 ret_BattU_I_A;
extern uint16 ret_ChademoChrgnCtpU1_I_A;
extern uint16 ret_ChademoChrgnEnaDiagU_I_A;
extern uint16 ret_ChademoChrgnPxpU1_I_A;
extern uint16 ret_ChinaChrgnPxpU1_I_A;
extern uint16 ret_ChinaChrgnCc1U2_I_A;
extern uint16 ret_ChinaChrgnAuxU2_I_A;
extern uint16 ret_ChaxCtrlPltU1_I_A;
extern uint16 ret_ChaxProxPltU1_I_A;
extern uint16 ret_ChaxProxPltU2_I_A;
extern uint16 ret_ChaxProxPltDiagUNeg_I_A;
extern uint16 ret_CtPSwtDiag_I_A;
extern uint16 ret_ChaxCtrlPltU2_I_A;
extern float ret_CtpCcsSwt_O_D;
extern float ret_DiagCtp1Aux_O_D;
extern float ret_ChademoChrgnStrt_I_D;
extern float ret_ChademoChrgnEna_O_D;
extern float ret_ChademoPxpEna_O_D;
extern float ret_DiagPxp_O_D;
extern float ret_ChinaChrgnAuxDig1_I_D;
extern float ret_DiagPxpRdnt_O_D;
extern float ret_ChaxCtrlPltSwtDiag_O_D;
extern float ret_ChaxProxPltSwt21_O_D;
extern float ret_ChaxProxPltSwtDiag1_O_D;
extern float ret_ChaxProxPltSwtDiag2_O_D;
extern float ret_McsChrgEnaLineRdy2Diag_I_D;
extern uint32 ret_Pwmin_rDutycycle;
extern uint32 ret_Pwmin_tiHighdur;
extern uint32 ret_Pwmin_tiPeriod;
extern uint16 ret_Pwmin_stSignal;

// STUBIT BEGIN

#define UPxP1_I_A 29

#define CtpCcsSwt_O_D 14

#define MonEgyChrgnInlet_flgCcsCtpDiag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 0) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 0))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 0))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 0) );}

#define MonEgyChrgnInlet_flgChademoCtp1Diag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 2) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 2))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 2))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 2) );}
#define MonEgyChrgnInlet_flgChademoCtp1_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 1) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 1))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 1))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 1) );}
#define MonEgyChrgnInlet_flgChademoCtp3Diag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 0) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 0))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 0))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 0) );}
#define MonEgyChrgnInlet_flgChademoCtp3Ena_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 3) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 3))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 3))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 3) );}
#define MonEgyChrgnInlet_flgChademoPxpDiag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 4) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 4))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 4))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 4) );}
#define MonEgyChrgnInlet_flgChademoPxpEna_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 | ((( uint8)1u) << 5) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl & ((uint8) (~(((uint8)1u) << 5))) );}else{MonEgyChrgnInletInp_bbOut1 =( MonEgyChrgnInletInp_bbOut1 & ((uint8)(~(((uint8)1u) << 5))) );MonEgyChrgnInletInp_bbOut1Cpl = ( MonEgyChrgnInletInp_bbOut1Cpl | (((uint8)1u) << 5) );}
#define MonEgyChrgnInlet_flgChinaDcAux1_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 3) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 3))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 3))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 3) );}
#define MonEgyChrgnInlet_flgChinaAcCtpDiag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 1) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 1))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 1))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 1) );}
#define MonEgyChrgnInlet_flgChinaDcCc1Diag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 2) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 2))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 2))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 2) );}
#define MonEgyChrgnInlet_flgChinaDcCc2Diag_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 5) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 5))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 5))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 5) );}
#define MonEgyChrgnInlet_flgMcsSv3RdntClsd_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 4) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 4))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 4))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 4) );}
#define MonEgyChrgnInlet_flgChinaDcCc2Ena_MoPut(a1) if((a1)){MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 | ((( uint8)1u) << 6) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl & ((uint8) (~(((uint8)1u) << 6))) );}else{MonEgyChrgnInletInp_bbOut2 =( MonEgyChrgnInletInp_bbOut2 & ((uint8)(~(((uint8)1u) << 6))) );MonEgyChrgnInletInp_bbOut2Cpl = ( MonEgyChrgnInletInp_bbOut2Cpl | (((uint8)1u) << 6) );}

#define PwmCtP_I_P 12

#define BattU_I_A 1

#define UCtP_I_A 28

#define IntlckChrgPlgPosn_I_A 16
#define McsChrgEnaLineU_I_A 54
#define McsInsertDetnLineU_I_A 55
#define IntlckChrgPlg3Posn_I_A 56
#define McsChrgEnaLineRdy2Diag_I_D 57

#define ChademoChrgnCtpU1_I_A 32
#define ChademoChrgnEnaDiagU_I_A 33
#define ChademoChrgnPxpU1_I_A 34
#define ChaxCtrlPltU1_I_A 35
#define ChaxProxPltU1_I_A 36
#define ChaxProxPltU2_I_A 37
#define ChaxProxPltDiagUNeg_I_A 38
#define ChinaChrgnAuxU2_I_A 39
#define ChinaChrgnPxpU1_I_A 40
#define ChinaChrgnCc1U2_I_A 41
#define ChademoChrgnStrt_I_D 42
#define ChademoChrgnEna_O_D 43
#define ChademoPxpEna_O_D 44
#define DiagPxp_O_D 45
#define ChinaChrgnAuxDig1_I_D 46
#define DiagCtp1Aux_O_D 47
#define DiagPxpRdnt_O_D 48
#define ChaxCtrlPltSwtDiag_O_D 49
#define ChaxProxPltSwt21_O_D 50
#define ChaxProxPltSwtDiag1_O_D 51
#define ChaxProxPltSwtDiag2_O_D 52
#define ChaxCtrlPltU2_I_A 53

#define MONEGYCHRGNINLET_INP_PFC_ID 0x00000008UL

#define MonEgyChrgnDefn_flgVrntCcsAcInlet_MoGet (MonEgyChrgnDefn_flgVrntCcsAcInlet)

#define MonEgyChrgnDefn_flgVrntCcsDcInlet_MoGet (MonEgyChrgnDefn_flgVrntCcsDcInlet)

#define MonEgyChrgnDefn_flgVrntCcsPlgLock_MoGet (MonEgyChrgnDefn_flgVrntCcsPlgLock)

#define MonEgyChrgnDefn_flgVrntChademoInlet_MoGet (MonEgyChrgnDefn_flgVrntChademoInlet)

#define MonEgyChrgnDefn_flgVrntChinaDcInlet_MoGet (MonEgyChrgnDefn_flgVrntChinaDcInlet)

#define MonEgyChrgnDefn_flgVrntChinaAcInlet_MoGet (MonEgyChrgnDefn_flgVrntChinaAcInlet)

#define MonEgyChrgnDefn_flgVrntMcsInlet_MoGet (MonEgyChrgnDefn_flgVrntMcsInlet)

#define MonEgyChrgnDefn_flgVrntMcsPlgLock_MoGet (MonEgyChrgnDefn_flgVrntMcsPlgLock)

typedef uint16 rba_IoSigAdc_idSignal_tu16;
typedef uint16 rba_IoSigDio_idSignal_tu16;
typedef struct
{
   uint32 Pwmin_rDutycycle;
   uint8 Pwmin_stSignal;
   uint32 Pwmin_tiHighdur;
   uint32 Pwmin_tiPeriod;
} PWMIN_RESULT_T_IMPL;

extern uint8 MonEgyChrgnDefnVrntHndlg_bbOut1;
static inline __attribute__ ((always_inline)) void PWM_IN_IMPL_PwmIn(uint32 Signalname, PWMIN_RESULT_T_IMPL* xResult_ps)
{
    (void)Signalname;
    xResult_ps->Pwmin_rDutycycle = ret_Pwmin_rDutycycle;
    xResult_ps->Pwmin_tiHighdur = ret_Pwmin_tiHighdur;
    xResult_ps->Pwmin_tiPeriod = ret_Pwmin_tiPeriod;
    xResult_ps->Pwmin_stSignal = ret_Pwmin_stSignal;
}
static inline __attribute__ ((always_inline)) boolean Dio_Get(rba_IoSigDio_idSignal_tu16 idSignal_u16)
{
    if (idSignal_u16 == CtpCcsSwt_O_D) return ret_CtpCcsSwt_O_D != 0.0f;
    if (idSignal_u16 == DiagCtp1Aux_O_D) return ret_DiagCtp1Aux_O_D != 0.0f;
    if (idSignal_u16 == ChademoChrgnStrt_I_D) return ret_ChademoChrgnStrt_I_D != 0.0f;
    if (idSignal_u16 == ChademoChrgnEna_O_D) return ret_ChademoChrgnEna_O_D != 0.0f;
    if (idSignal_u16 == ChademoPxpEna_O_D) return ret_ChademoPxpEna_O_D != 0.0f;
    if (idSignal_u16 == DiagPxp_O_D) return ret_DiagPxp_O_D != 0.0f;
    if (idSignal_u16 == ChinaChrgnAuxDig1_I_D) return ret_ChinaChrgnAuxDig1_I_D != 0.0f;
    if (idSignal_u16 == DiagPxpRdnt_O_D) return ret_DiagPxpRdnt_O_D != 0.0f;
    if (idSignal_u16 == ChaxCtrlPltSwtDiag_O_D) return ret_ChaxCtrlPltSwtDiag_O_D != 0.0f;
    if (idSignal_u16 == ChaxProxPltSwt21_O_D) return ret_ChaxProxPltSwt21_O_D != 0.0f;
    if (idSignal_u16 == ChaxProxPltSwtDiag1_O_D) return ret_ChaxProxPltSwtDiag1_O_D != 0.0f;
    if (idSignal_u16 == ChaxProxPltSwtDiag2_O_D) return ret_ChaxProxPltSwtDiag2_O_D != 0.0f;
    if (idSignal_u16 == McsChrgEnaLineRdy2Diag_I_D) return ret_McsChrgEnaLineRdy2Diag_I_D != 0.0f;
    return (boolean){0};
}
static inline __attribute__ ((always_inline)) sint16 Adc_GetRawRatio(rba_IoSigAdc_idSignal_tu16 idSignal_u16)
{
    if (idSignal_u16 == UCtP_I_A) return (sint16)ret_UCtP_I_A;
    if (idSignal_u16 == UPxP1_I_A) return (sint16)ret_UPxP1_I_A;
    if (idSignal_u16 == IntlckChrgPlgPosn_I_A) return (sint16)ret_IntlckChrgPlgPosn_I_A;
    if (idSignal_u16 == McsChrgEnaLineU_I_A) return (sint16)ret_McsChrgEnaLineU_I_A;
    if (idSignal_u16 == McsInsertDetnLineU_I_A) return (sint16)ret_McsInsertDetnLineU_I_A;
    if (idSignal_u16 == IntlckChrgPlg3Posn_I_A) return (sint16)ret_IntlckChrgPlg3Posn_I_A;
    if (idSignal_u16 == BattU_I_A) return (sint16)ret_BattU_I_A;
    if (idSignal_u16 == ChademoChrgnCtpU1_I_A) return (sint16)ret_ChademoChrgnCtpU1_I_A;
    if (idSignal_u16 == ChademoChrgnEnaDiagU_I_A) return (sint16)ret_ChademoChrgnEnaDiagU_I_A;
    if (idSignal_u16 == ChademoChrgnPxpU1_I_A) return (sint16)ret_ChademoChrgnPxpU1_I_A;
    if (idSignal_u16 == ChinaChrgnPxpU1_I_A) return (sint16)ret_ChinaChrgnPxpU1_I_A;
    if (idSignal_u16 == ChinaChrgnCc1U2_I_A) return (sint16)ret_ChinaChrgnCc1U2_I_A;
    if (idSignal_u16 == ChinaChrgnAuxU2_I_A) return (sint16)ret_ChinaChrgnAuxU2_I_A;
    if (idSignal_u16 == ChaxCtrlPltU1_I_A) return (sint16)ret_ChaxCtrlPltU1_I_A;
    if (idSignal_u16 == ChaxCtrlPltU2_I_A) return (sint16)ret_ChaxCtrlPltU2_I_A;
    if (idSignal_u16 == ChaxProxPltU1_I_A) return (sint16)ret_ChaxProxPltU1_I_A;
    if (idSignal_u16 == ChaxProxPltU2_I_A) return (sint16)ret_ChaxProxPltU2_I_A;
    if (idSignal_u16 == ChaxProxPltDiagUNeg_I_A) return (sint16)ret_ChaxProxPltDiagUNeg_I_A;
    return (sint16){0};
}

// STUBIT END