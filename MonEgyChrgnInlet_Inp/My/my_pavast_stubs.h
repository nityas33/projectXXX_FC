//
// my_pavast_stubs.h
// Copyright (C) 2026 Robert Bosch GmbH. All rights reserved.
//

#pragma once
#define _DAT_H
#include "std_type.h"
#include "esc.h"
#include "srv.h"
// [BCU-GeneratedIncludes-Start]
#include "my_config.h"
// [BCU-GeneratedIncludes-End]

BCU_BEGIN_C_HEADER

///////////////////////////////////////////////////////////////////////////////

// [BCU-GeneratedCode-Start]

#ifndef BCU_UNKNOWN
#define BCU_UNKNOWN 0
#endif

//-----------------------------------------------------------------------------
// Local system constants


//-----------------------------------------------------------------------------
// External system constants


//-----------------------------------------------------------------------------
// Classes


//-----------------------------------------------------------------------------
// Local parameters

extern sint16 MonEgyChrgnInlet_facAdcCnv_C;
extern sint16 MonEgyChrgnInlet_facAdcCnvBatt_C;
extern sint16 MonEgyChrgnInlet_facAdcToPinCnv_C;
extern sint16 MonEgyChrgnInlet_facCorrUBattSubVal_C;
extern uint8 MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoCtp1SubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChinaDcAux1SubVal_C;
extern uint8 MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C;
extern uint8 MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C;
extern uint8 MonEgyChrgnInlet_nrBitShift_C;
extern uint8 MonEgyChrgnInlet_nrBitShiftBatt_C;
extern uint16 MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C;
extern uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcBatt_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcCcs_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcChademo_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcChinaAc_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcChinaDc_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcMcs_C;
extern uint8 MonEgyChrgnInlet_stSwtPreProcMcsPlgLock_C;
extern uint32 MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C;
extern uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C;
extern sint16 MonEgyChrgnInlet_uBattNom_C;
extern sint16 MonEgyChrgnInlet_uRawCcsCtpSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawCcsPxpSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChademoCtp1SubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChademoCtp3SubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChademoPxpSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaAcCcSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C;
extern sint16 MonEgyChrgnInlet_uRawMcsCtpSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawMcsPlgPosnSubVal_C;
extern sint16 MonEgyChrgnInlet_uRawMcsPxpSubVal_C;

//-----------------------------------------------------------------------------
// External parameters


//-----------------------------------------------------------------------------
// Local variables

extern sint16 MonEgyChrgnInlet_facCorrUBatt;
extern uint16 MonEgyChrgnInlet_facCorrUBattCpl;
extern bool MonEgyChrgnInlet_flgCcsCtpDiag;
extern bool MonEgyChrgnInlet_flgChademoCtp1;
extern bool MonEgyChrgnInlet_flgChademoCtp1Diag;
extern bool MonEgyChrgnInlet_flgChademoCtp3Diag;
extern bool MonEgyChrgnInlet_flgChademoCtp3Ena;
extern bool MonEgyChrgnInlet_flgChademoPxpDiag;
extern bool MonEgyChrgnInlet_flgChademoPxpEna;
extern bool MonEgyChrgnInlet_flgChinaAcCtpDiag;
extern bool MonEgyChrgnInlet_flgChinaDcAux1;
extern bool MonEgyChrgnInlet_flgChinaDcCc1Diag;
extern bool MonEgyChrgnInlet_flgChinaDcCc2Diag;
extern bool MonEgyChrgnInlet_flgChinaDcCc2Ena;
extern bool MonEgyChrgnInlet_flgMcsSv3RdntClsd;
extern uint16 MonEgyChrgnInlet_ratPwmCcsCtp;
extern uint16 MonEgyChrgnInlet_ratPwmCcsCtpCpl;
extern uint16 MonEgyChrgnInlet_ratPwmCcsCtpLoc;
extern uint16 MonEgyChrgnInlet_ratPwmCcsCtpLocCpl;
extern uint16 MonEgyChrgnInlet_ratPwmChinaAcCtp;
extern uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpCpl;
extern uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpLoc;
extern uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl;
extern uint32 MonEgyChrgnInlet_tiPerdCcsCtp;
extern uint32 MonEgyChrgnInlet_tiPerdCcsCtpCpl;
extern uint32 MonEgyChrgnInlet_tiPerdCcsCtpLoc;
extern uint32 MonEgyChrgnInlet_tiPerdCcsCtpLocCpl;
extern uint32 MonEgyChrgnInlet_tiPerdChinaAcCtp;
extern uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpCpl;
extern uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpLoc;
extern uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl;
extern sint16 MonEgyChrgnInlet_uAdcRawChademoCtp1;
extern uint16 MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl;
extern sint16 MonEgyChrgnInlet_uAdcRawChademoCtp3;
extern uint16 MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl;
extern sint16 MonEgyChrgnInlet_uAdcRawChademoPxP;
extern uint16 MonEgyChrgnInlet_uAdcRawChademoPxPCpl;
extern sint16 MonEgyChrgnInlet_uAdcRawChinaDcCc1;
extern uint16 MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl;
extern sint16 MonEgyChrgnInlet_uAdcRawChinaDcCc2;
extern uint16 MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl;
extern sint16 MonEgyChrgnInlet_uBattAct;
extern uint16 MonEgyChrgnInlet_uBattActCpl;
extern sint16 MonEgyChrgnInlet_uRawCcsCtp;
extern uint16 MonEgyChrgnInlet_uRawCcsCtpCpl;
extern sint16 MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn;
extern uint16 MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl;
extern sint16 MonEgyChrgnInlet_uRawCcsPxp;
extern uint16 MonEgyChrgnInlet_uRawCcsPxpCpl;
extern sint16 MonEgyChrgnInlet_uRawChademoCtp1;
extern uint16 MonEgyChrgnInlet_uRawChademoCtp1Cpl;
extern sint16 MonEgyChrgnInlet_uRawChademoCtp3;
extern uint16 MonEgyChrgnInlet_uRawChademoCtp3Cpl;
extern sint16 MonEgyChrgnInlet_uRawChademoPxp;
extern uint16 MonEgyChrgnInlet_uRawChademoPxpCpl;
extern sint16 MonEgyChrgnInlet_uRawChademoPxpDiagNeg;
extern uint16 MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl;
extern sint16 MonEgyChrgnInlet_uRawChinaAcCc;
extern uint16 MonEgyChrgnInlet_uRawChinaAcCcCpl;
extern sint16 MonEgyChrgnInlet_uRawChinaAcCtp;
extern uint16 MonEgyChrgnInlet_uRawChinaAcCtpCpl;
extern sint16 MonEgyChrgnInlet_uRawChinaDcAux1;
extern uint16 MonEgyChrgnInlet_uRawChinaDcAux1Cpl;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc1;
extern uint16 MonEgyChrgnInlet_uRawChinaDcCc1Cpl;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc2;
extern uint16 MonEgyChrgnInlet_uRawChinaDcCc2Cpl;
extern sint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg;
extern uint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl;
extern sint16 MonEgyChrgnInlet_uRawMcsCtp;
extern uint16 MonEgyChrgnInlet_uRawMcsCtpCpl;
extern sint16 MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosn;
extern uint16 MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosnCpl;
extern sint16 MonEgyChrgnInlet_uRawMcsPxp;
extern uint16 MonEgyChrgnInlet_uRawMcsPxpCpl;
extern int MonEgyChrgnInletInp_bbOut1;
extern uint8 MonEgyChrgnInletInp_bbOut1Cpl;
extern int MonEgyChrgnInletInp_bbOut2;
extern uint8 MonEgyChrgnInletInp_bbOut2Cpl;

//-----------------------------------------------------------------------------
// External variables

extern uint32 Mo_stCplChk;
extern uint8 Mo_stMoC;
extern uint8 Mo_stMoCCpl;
extern bool MonEgyChrgnDefn_flgVrntCcsAcInlet;
extern bool MonEgyChrgnDefn_flgVrntCcsDcInlet;
extern bool MonEgyChrgnDefn_flgVrntCcsPlgLock;
extern bool MonEgyChrgnDefn_flgVrntChademoInlet;
extern bool MonEgyChrgnDefn_flgVrntChinaAcInlet;
extern bool MonEgyChrgnDefn_flgVrntChinaDcInlet;
extern bool MonEgyChrgnDefn_flgVrntMcsInlet;
extern bool MonEgyChrgnDefn_flgVrntMcsPlgLock;

//-----------------------------------------------------------------------------
// Local structures


//-----------------------------------------------------------------------------
// External structures


//-----------------------------------------------------------------------------
// Local class instances


//-----------------------------------------------------------------------------
// External class instances


//-----------------------------------------------------------------------------
// Access macros


#define GET_MonEgyChrgnDefn_flgVrntCcsAcInlet (MonEgyChrgnDefn_flgVrntCcsAcInlet)
#define SET_MonEgyChrgnDefn_flgVrntCcsAcInlet (MonEgyChrgnDefn_flgVrntCcsAcInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntCcsAcInlet (MonEgyChrgnDefn_flgVrntCcsAcInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntCcsAcInlet(value) (MonEgyChrgnDefn_flgVrntCcsAcInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntCcsDcInlet (MonEgyChrgnDefn_flgVrntCcsDcInlet)
#define SET_MonEgyChrgnDefn_flgVrntCcsDcInlet (MonEgyChrgnDefn_flgVrntCcsDcInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntCcsDcInlet (MonEgyChrgnDefn_flgVrntCcsDcInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntCcsDcInlet(value) (MonEgyChrgnDefn_flgVrntCcsDcInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntCcsPlgLock (MonEgyChrgnDefn_flgVrntCcsPlgLock)
#define SET_MonEgyChrgnDefn_flgVrntCcsPlgLock (MonEgyChrgnDefn_flgVrntCcsPlgLock = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntCcsPlgLock (MonEgyChrgnDefn_flgVrntCcsPlgLock = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntCcsPlgLock(value) (MonEgyChrgnDefn_flgVrntCcsPlgLock = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntChademoInlet (MonEgyChrgnDefn_flgVrntChademoInlet)
#define SET_MonEgyChrgnDefn_flgVrntChademoInlet (MonEgyChrgnDefn_flgVrntChademoInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntChademoInlet (MonEgyChrgnDefn_flgVrntChademoInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntChademoInlet(value) (MonEgyChrgnDefn_flgVrntChademoInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntChinaAcInlet (MonEgyChrgnDefn_flgVrntChinaAcInlet)
#define SET_MonEgyChrgnDefn_flgVrntChinaAcInlet (MonEgyChrgnDefn_flgVrntChinaAcInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntChinaAcInlet (MonEgyChrgnDefn_flgVrntChinaAcInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntChinaAcInlet(value) (MonEgyChrgnDefn_flgVrntChinaAcInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntChinaDcInlet (MonEgyChrgnDefn_flgVrntChinaDcInlet)
#define SET_MonEgyChrgnDefn_flgVrntChinaDcInlet (MonEgyChrgnDefn_flgVrntChinaDcInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntChinaDcInlet (MonEgyChrgnDefn_flgVrntChinaDcInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntChinaDcInlet(value) (MonEgyChrgnDefn_flgVrntChinaDcInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntMcsInlet (MonEgyChrgnDefn_flgVrntMcsInlet)
#define SET_MonEgyChrgnDefn_flgVrntMcsInlet (MonEgyChrgnDefn_flgVrntMcsInlet = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntMcsInlet (MonEgyChrgnDefn_flgVrntMcsInlet = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntMcsInlet(value) (MonEgyChrgnDefn_flgVrntMcsInlet = (value) ? TRUE : FALSE)

#define GET_MonEgyChrgnDefn_flgVrntMcsPlgLock (MonEgyChrgnDefn_flgVrntMcsPlgLock)
#define SET_MonEgyChrgnDefn_flgVrntMcsPlgLock (MonEgyChrgnDefn_flgVrntMcsPlgLock = TRUE)
#define CLR_MonEgyChrgnDefn_flgVrntMcsPlgLock (MonEgyChrgnDefn_flgVrntMcsPlgLock = FALSE)
#define PUT_MonEgyChrgnDefn_flgVrntMcsPlgLock(value) (MonEgyChrgnDefn_flgVrntMcsPlgLock = (value) ? TRUE : FALSE)

//-----------------------------------------------------------------------------
// Initialization functions

void My_InitializePavastStubs(void);

// [BCU-GeneratedCode-End]

///////////////////////////////////////////////////////////////////////////////

BCU_END_C_HEADER
