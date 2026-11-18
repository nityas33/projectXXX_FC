//
// my_pavast_stubs.c
// Copyright (C) 2026 Robert Bosch GmbH. All rights reserved.
//

#include <bcu.h>
// [BCU-GeneratedIncludes-Start]
#include "my_pavast_stubs.h"
// [BCU-GeneratedIncludes-End]

///////////////////////////////////////////////////////////////////////////////

// [BCU-GeneratedCode-Start]

//-----------------------------------------------------------------------------
// Local parameters

sint16 MonEgyChrgnInlet_facAdcCnv_C = 4096;
sint16 MonEgyChrgnInlet_facAdcCnvBatt_C = 4096;
sint16 MonEgyChrgnInlet_facAdcToPinCnv_C = 0;
sint16 MonEgyChrgnInlet_facCorrUBattSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoCtp1SubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChinaDcAux1SubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C = 0;
uint8 MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C = 0;
uint8 MonEgyChrgnInlet_nrBitShift_C = 0;
uint8 MonEgyChrgnInlet_nrBitShiftBatt_C = 15;
uint16 MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C = 0;
uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcBatt_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcCcs_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcChademo_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcChinaAc_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcChinaDc_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcMcs_C = 0;
uint8 MonEgyChrgnInlet_stSwtPreProcMcsPlgLock_C = 0;
uint32 MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C = 0;
uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uBattNom_C = 9830;
sint16 MonEgyChrgnInlet_uRawCcsCtpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawCcsPxpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChademoCtp1SubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChademoCtp3SubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChademoPxpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaAcCcSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawMcsCtpSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawMcsPlgPosnSubVal_C = 0;
sint16 MonEgyChrgnInlet_uRawMcsPxpSubVal_C = 0;

//-----------------------------------------------------------------------------
// External parameters


//-----------------------------------------------------------------------------
// Local variables

sint16 MonEgyChrgnInlet_facCorrUBatt;
uint16 MonEgyChrgnInlet_facCorrUBattCpl;
bool MonEgyChrgnInlet_flgCcsCtpDiag;
bool MonEgyChrgnInlet_flgChademoCtp1;
bool MonEgyChrgnInlet_flgChademoCtp1Diag;
bool MonEgyChrgnInlet_flgChademoCtp3Diag;
bool MonEgyChrgnInlet_flgChademoCtp3Ena;
bool MonEgyChrgnInlet_flgChademoPxpDiag;
bool MonEgyChrgnInlet_flgChademoPxpEna;
bool MonEgyChrgnInlet_flgChinaAcCtpDiag;
bool MonEgyChrgnInlet_flgChinaDcAux1;
bool MonEgyChrgnInlet_flgChinaDcCc1Diag;
bool MonEgyChrgnInlet_flgChinaDcCc2Diag;
bool MonEgyChrgnInlet_flgChinaDcCc2Ena;
bool MonEgyChrgnInlet_flgMcsSv3RdntClsd;
uint16 MonEgyChrgnInlet_ratPwmCcsCtp;
uint16 MonEgyChrgnInlet_ratPwmCcsCtpCpl;
uint16 MonEgyChrgnInlet_ratPwmCcsCtpLoc;
uint16 MonEgyChrgnInlet_ratPwmCcsCtpLocCpl;
uint16 MonEgyChrgnInlet_ratPwmChinaAcCtp;
uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpCpl;
uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpLoc;
uint16 MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl;
uint32 MonEgyChrgnInlet_tiPerdCcsCtp;
uint32 MonEgyChrgnInlet_tiPerdCcsCtpCpl;
uint32 MonEgyChrgnInlet_tiPerdCcsCtpLoc;
uint32 MonEgyChrgnInlet_tiPerdCcsCtpLocCpl;
uint32 MonEgyChrgnInlet_tiPerdChinaAcCtp;
uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpCpl;
uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpLoc;
uint32 MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl;
sint16 MonEgyChrgnInlet_uAdcRawChademoCtp1;
uint16 MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl;
sint16 MonEgyChrgnInlet_uAdcRawChademoCtp3;
uint16 MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl;
sint16 MonEgyChrgnInlet_uAdcRawChademoPxP;
uint16 MonEgyChrgnInlet_uAdcRawChademoPxPCpl;
sint16 MonEgyChrgnInlet_uAdcRawChinaDcCc1;
uint16 MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl;
sint16 MonEgyChrgnInlet_uAdcRawChinaDcCc2;
uint16 MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl;
sint16 MonEgyChrgnInlet_uBattAct;
uint16 MonEgyChrgnInlet_uBattActCpl;
sint16 MonEgyChrgnInlet_uRawCcsCtp;
uint16 MonEgyChrgnInlet_uRawCcsCtpCpl;
sint16 MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn;
uint16 MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl;
sint16 MonEgyChrgnInlet_uRawCcsPxp;
uint16 MonEgyChrgnInlet_uRawCcsPxpCpl;
sint16 MonEgyChrgnInlet_uRawChademoCtp1;
uint16 MonEgyChrgnInlet_uRawChademoCtp1Cpl;
sint16 MonEgyChrgnInlet_uRawChademoCtp3;
uint16 MonEgyChrgnInlet_uRawChademoCtp3Cpl;
sint16 MonEgyChrgnInlet_uRawChademoPxp;
uint16 MonEgyChrgnInlet_uRawChademoPxpCpl;
sint16 MonEgyChrgnInlet_uRawChademoPxpDiagNeg;
uint16 MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl;
sint16 MonEgyChrgnInlet_uRawChinaAcCc;
uint16 MonEgyChrgnInlet_uRawChinaAcCcCpl;
sint16 MonEgyChrgnInlet_uRawChinaAcCtp;
uint16 MonEgyChrgnInlet_uRawChinaAcCtpCpl;
sint16 MonEgyChrgnInlet_uRawChinaDcAux1;
uint16 MonEgyChrgnInlet_uRawChinaDcAux1Cpl;
sint16 MonEgyChrgnInlet_uRawChinaDcCc1;
uint16 MonEgyChrgnInlet_uRawChinaDcCc1Cpl;
sint16 MonEgyChrgnInlet_uRawChinaDcCc2;
uint16 MonEgyChrgnInlet_uRawChinaDcCc2Cpl;
sint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg;
uint16 MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl;
sint16 MonEgyChrgnInlet_uRawMcsCtp;
uint16 MonEgyChrgnInlet_uRawMcsCtpCpl;
sint16 MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosn;
uint16 MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosnCpl;
sint16 MonEgyChrgnInlet_uRawMcsPxp;
uint16 MonEgyChrgnInlet_uRawMcsPxpCpl;
int MonEgyChrgnInletInp_bbOut1;
uint8 MonEgyChrgnInletInp_bbOut1Cpl;
int MonEgyChrgnInletInp_bbOut2;
uint8 MonEgyChrgnInletInp_bbOut2Cpl;

//-----------------------------------------------------------------------------
// External variables

uint32 Mo_stCplChk;
uint8 Mo_stMoC;
uint8 Mo_stMoCCpl;
bool MonEgyChrgnDefn_flgVrntCcsAcInlet;
bool MonEgyChrgnDefn_flgVrntCcsDcInlet;
bool MonEgyChrgnDefn_flgVrntCcsPlgLock;
bool MonEgyChrgnDefn_flgVrntChademoInlet;
bool MonEgyChrgnDefn_flgVrntChinaAcInlet;
bool MonEgyChrgnDefn_flgVrntChinaDcInlet;
bool MonEgyChrgnDefn_flgVrntMcsInlet;
bool MonEgyChrgnDefn_flgVrntMcsPlgLock;

//-----------------------------------------------------------------------------
// Local structures


//-----------------------------------------------------------------------------
// External structures


//-----------------------------------------------------------------------------
// Local class instances


//-----------------------------------------------------------------------------
// External class instances


//-----------------------------------------------------------------------------
// Initialization functions

BCU_NO_INSTRUMENT_FUNCTION void My_InitializePavastStubs(void)
{
    // Compu-methods
    Bcu_AddLinearCompuMethod("fak_q0p000122", "%6.3", "", 8192, 0);
    Bcu_AddLinearCompuMethod("RBPtCel_Perc_0p01_1", "%6.3", "%", 100, 0);
    Bcu_AddLinearCompuMethod("spg_q0p0012207_V", "%6.3", "V", 819.2, 0);
    Bcu_AddLinearCompuMethod("t_q5Em8_s", "%6.3", "s", 20000000, 0);
    Bcu_AddVerbalCompuMethod("B_TRUE", "%6.3", "", "FALSE=0,TRUE=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CCSACINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CCSDCINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CCSDIAGSWTCTP_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CCSPLGLOCK_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHADEMOANCTPIF_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHADEMOINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHAXHWMODL_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHINAACINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHINAANAUX_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_CHINADCINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_GBTDCDIAGSWTCC1_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_MCSINLET_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_MCSPLGLOCK_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_MCSRDNTCTPSWT_SC_Compu", "%6.3", "", "False=0,True=1");
    Bcu_AddVerbalCompuMethod("CHRGNFCTSFTY_MCSRDNTCTPSWTACTTNFB_SC_Compu", "%6.3", "", "False=0,True=1");

    // Record-layouts
    Bcu_AddRecordLayout("Mo_DataS16", "FNC_VALUES 1 SWORD");
    Bcu_AddRecordLayout("Mo_DataU16", "FNC_VALUES 1 UWORD");
    Bcu_AddRecordLayout("Mo_DataU32", "FNC_VALUES 1 ULONG");
    Bcu_AddRecordLayout("Mo_DataU8", "FNC_VALUES 1 UBYTE");

    // Local system constants
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CCSACINLET_SC", CHRGNFCTSFTY_CCSACINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CCSDCINLET_SC", CHRGNFCTSFTY_CCSDCINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CCSDIAGSWTCTP_SC", CHRGNFCTSFTY_CCSDIAGSWTCTP_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CCSPLGLOCK_SC", CHRGNFCTSFTY_CCSPLGLOCK_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHADEMOANCTPIF_SC", CHRGNFCTSFTY_CHADEMOANCTPIF_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHADEMOINLET_SC", CHRGNFCTSFTY_CHADEMOINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHAXHWMODL_SC", CHRGNFCTSFTY_CHAXHWMODL_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHINAACINLET_SC", CHRGNFCTSFTY_CHINAACINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHINAANAUX_SC", CHRGNFCTSFTY_CHINAANAUX_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_CHINADCINLET_SC", CHRGNFCTSFTY_CHINADCINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_GBTDCDIAGSWTCC1_SC", CHRGNFCTSFTY_GBTDCDIAGSWTCC1_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_MCSINLET_SC", CHRGNFCTSFTY_MCSINLET_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_MCSPLGLOCK_SC", CHRGNFCTSFTY_MCSPLGLOCK_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_MCSRDNTCTPSWT_SC", CHRGNFCTSFTY_MCSRDNTCTPSWT_SC);
    Bcu_AddSystemConstant("CHRGNFCTSFTY_MCSRDNTCTPSWTACTTNFB_SC", CHRGNFCTSFTY_MCSRDNTCTPSWTACTTNFB_SC);

    // External system constants

    // Local axis

    // External axis

    // Local parameters
    Bcu_AddParameter_s16("MonEgyChrgnInlet_facAdcCnv_C", Bidirectional, &MonEgyChrgnInlet_facAdcCnv_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_facAdcCnvBatt_C", Bidirectional, &MonEgyChrgnInlet_facAdcCnvBatt_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_facAdcToPinCnv_C", Bidirectional, &MonEgyChrgnInlet_facAdcToPinCnv_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_facCorrUBattSubVal_C", Bidirectional, &MonEgyChrgnInlet_facCorrUBattSubVal_C)->SetCompuMethod("fak_q0p000122");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoCtp1SubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChinaDcAux1SubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", Bidirectional, &MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C)->SetCompuMethod("B_TRUE");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_nrBitShift_C", Bidirectional, &MonEgyChrgnInlet_nrBitShift_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_nrBitShiftBatt_C", Bidirectional, &MonEgyChrgnInlet_nrBitShiftBatt_C);
    Bcu_AddParameter_u16("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C)->SetCompuMethod("RBPtCel_Perc_0p01_1");
    Bcu_AddParameter_u16("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C)->SetCompuMethod("RBPtCel_Perc_0p01_1");
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcBatt_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcBatt_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcCcs_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcCcs_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcChademo_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcChademo_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcChinaAc_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcChinaDc_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcMcs_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcMcs_C);
    Bcu_AddParameter_u8("MonEgyChrgnInlet_stSwtPreProcMcsPlgLock_C", Bidirectional, &MonEgyChrgnInlet_stSwtPreProcMcsPlgLock_C);
    Bcu_AddParameter_u32("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C)->SetCompuMethod("t_q5Em8_s");
    Bcu_AddParameter_u32("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C)->SetCompuMethod("t_q5Em8_s");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uBattNom_C", Bidirectional, &MonEgyChrgnInlet_uBattNom_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawCcsCtpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawCcsPxpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChademoCtp1SubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChademoCtp3SubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChademoPxpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaAcCcSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawMcsCtpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawMcsCtpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawMcsPlgPosnSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawMcsPlgPosnSubVal_C)->SetCompuMethod("spg_q0p0012207_V");
    Bcu_AddParameter_s16("MonEgyChrgnInlet_uRawMcsPxpSubVal_C", Bidirectional, &MonEgyChrgnInlet_uRawMcsPxpSubVal_C)->SetCompuMethod("spg_q0p0012207_V");

    // External parameters

    // Local variables
    Bcu_AddVariable_s16("MonEgyChrgnInlet_facCorrUBatt", Output, &MonEgyChrgnInlet_facCorrUBatt)->SetCompuMethod("fak_q0p000122")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_facCorrUBattCpl", Output, &MonEgyChrgnInlet_facCorrUBattCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmCcsCtp", Output, &MonEgyChrgnInlet_ratPwmCcsCtp)->SetCompuMethod("RBPtCel_Perc_0p01_1")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmCcsCtpCpl", Output, &MonEgyChrgnInlet_ratPwmCcsCtpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmCcsCtpLoc", Output, &MonEgyChrgnInlet_ratPwmCcsCtpLoc)->SetCompuMethod("RBPtCel_Perc_0p01_1")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmCcsCtpLocCpl", Output, &MonEgyChrgnInlet_ratPwmCcsCtpLocCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmChinaAcCtp", Output, &MonEgyChrgnInlet_ratPwmChinaAcCtp)->SetCompuMethod("RBPtCel_Perc_0p01_1")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmChinaAcCtpCpl", Output, &MonEgyChrgnInlet_ratPwmChinaAcCtpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc", Output, &MonEgyChrgnInlet_ratPwmChinaAcCtpLoc)->SetCompuMethod("RBPtCel_Perc_0p01_1")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl", Output, &MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdCcsCtp", Output, &MonEgyChrgnInlet_tiPerdCcsCtp)->SetCompuMethod("t_q5Em8_s")->SetAddrMethod("Mo_RamCyclicCheckLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdCcsCtpCpl", Output, &MonEgyChrgnInlet_tiPerdCcsCtpCpl)->SetAddrMethod("Mo_RamCplLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdCcsCtpLoc", Output, &MonEgyChrgnInlet_tiPerdCcsCtpLoc)->SetCompuMethod("t_q5Em8_s")->SetAddrMethod("Mo_RamCyclicCheckLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdCcsCtpLocCpl", Output, &MonEgyChrgnInlet_tiPerdCcsCtpLocCpl)->SetAddrMethod("Mo_RamCplLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdChinaAcCtp", Output, &MonEgyChrgnInlet_tiPerdChinaAcCtp)->SetCompuMethod("t_q5Em8_s")->SetAddrMethod("Mo_RamCyclicCheckLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdChinaAcCtpCpl", Output, &MonEgyChrgnInlet_tiPerdChinaAcCtpCpl)->SetAddrMethod("Mo_RamCplLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc", Output, &MonEgyChrgnInlet_tiPerdChinaAcCtpLoc)->SetCompuMethod("t_q5Em8_s")->SetAddrMethod("Mo_RamCyclicCheckLong");
    Bcu_AddVariable_u32("MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl", Output, &MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl)->SetAddrMethod("Mo_RamCplLong");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uAdcRawChademoCtp1", Output, &MonEgyChrgnInlet_uAdcRawChademoCtp1)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl", Output, &MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uAdcRawChademoCtp3", Output, &MonEgyChrgnInlet_uAdcRawChademoCtp3)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl", Output, &MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uAdcRawChademoPxP", Output, &MonEgyChrgnInlet_uAdcRawChademoPxP)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uAdcRawChademoPxPCpl", Output, &MonEgyChrgnInlet_uAdcRawChademoPxPCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uAdcRawChinaDcCc1", Output, &MonEgyChrgnInlet_uAdcRawChinaDcCc1)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl", Output, &MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uAdcRawChinaDcCc2", Output, &MonEgyChrgnInlet_uAdcRawChinaDcCc2)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl", Output, &MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uBattAct", Output, &MonEgyChrgnInlet_uBattAct)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uBattActCpl", Output, &MonEgyChrgnInlet_uBattActCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawCcsCtp", Output, &MonEgyChrgnInlet_uRawCcsCtp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawCcsCtpCpl", Output, &MonEgyChrgnInlet_uRawCcsCtpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn", Output, &MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl", Output, &MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawCcsPxp", Output, &MonEgyChrgnInlet_uRawCcsPxp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawCcsPxpCpl", Output, &MonEgyChrgnInlet_uRawCcsPxpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChademoCtp1", Output, &MonEgyChrgnInlet_uRawChademoCtp1)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChademoCtp1Cpl", Output, &MonEgyChrgnInlet_uRawChademoCtp1Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChademoCtp3", Output, &MonEgyChrgnInlet_uRawChademoCtp3)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChademoCtp3Cpl", Output, &MonEgyChrgnInlet_uRawChademoCtp3Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChademoPxp", Output, &MonEgyChrgnInlet_uRawChademoPxp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChademoPxpCpl", Output, &MonEgyChrgnInlet_uRawChademoPxpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChademoPxpDiagNeg", Output, &MonEgyChrgnInlet_uRawChademoPxpDiagNeg)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl", Output, &MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaAcCc", Output, &MonEgyChrgnInlet_uRawChinaAcCc)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaAcCcCpl", Output, &MonEgyChrgnInlet_uRawChinaAcCcCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaAcCtp", Output, &MonEgyChrgnInlet_uRawChinaAcCtp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaAcCtpCpl", Output, &MonEgyChrgnInlet_uRawChinaAcCtpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaDcAux1", Output, &MonEgyChrgnInlet_uRawChinaDcAux1)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaDcAux1Cpl", Output, &MonEgyChrgnInlet_uRawChinaDcAux1Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaDcCc1", Output, &MonEgyChrgnInlet_uRawChinaDcCc1)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaDcCc1Cpl", Output, &MonEgyChrgnInlet_uRawChinaDcCc1Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaDcCc2", Output, &MonEgyChrgnInlet_uRawChinaDcCc2)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaDcCc2Cpl", Output, &MonEgyChrgnInlet_uRawChinaDcCc2Cpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg", Output, &MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl", Output, &MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawMcsCtp", Output, &MonEgyChrgnInlet_uRawMcsCtp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawMcsCtpCpl", Output, &MonEgyChrgnInlet_uRawMcsCtpCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosn", Output, &MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosn)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosnCpl", Output, &MonEgyChrgnInlet_uRawMcsIntlckChrgPlgPosnCpl)->SetAddrMethod("Mo_RamCplWord");
    Bcu_AddVariable_s16("MonEgyChrgnInlet_uRawMcsPxp", Output, &MonEgyChrgnInlet_uRawMcsPxp)->SetCompuMethod("spg_q0p0012207_V")->SetAddrMethod("Mo_RamCyclicCheckWord");
    Bcu_AddVariable_u16("MonEgyChrgnInlet_uRawMcsPxpCpl", Output, &MonEgyChrgnInlet_uRawMcsPxpCpl)->SetAddrMethod("Mo_RamCplWord");
    // Undefined Data Type of 'MonEgyChrgnInletInp_bbOut1' and it requires Class definition of 'TYP_Mo_RamBbCyclicCheckU8' to define the data type
	Bcu_AddVariable_u16("MonEgyChrgnInletInp_bbOut1", Output, &MonEgyChrgnInletInp_bbOut1);
    Bcu_AddVariable_u8("MonEgyChrgnInletInp_bbOut1Cpl", Output, &MonEgyChrgnInletInp_bbOut1Cpl)->SetAddrMethod("Mo_RamCplByte");
    // Undefined Data Type of 'MonEgyChrgnInletInp_bbOut2' and it requires Class definition of 'TYP_Mo_RamBbCyclicCheckU8' to define the data type
	Bcu_AddVariable_u8("MonEgyChrgnInletInp_bbOut2", Output, &MonEgyChrgnInletInp_bbOut2);
    Bcu_AddVariable_u8("MonEgyChrgnInletInp_bbOut2Cpl", Output, &MonEgyChrgnInletInp_bbOut2Cpl)->SetAddrMethod("Mo_RamCplByte");
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgCcsCtpDiag", Output, &MonEgyChrgnInlet_flgCcsCtpDiag)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(0);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoCtp1", Output, &MonEgyChrgnInlet_flgChademoCtp1)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(1);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoCtp1Diag", Output, &MonEgyChrgnInlet_flgChademoCtp1Diag)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(2);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoCtp3Diag", Output, &MonEgyChrgnInlet_flgChademoCtp3Diag)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(0);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoCtp3Ena", Output, &MonEgyChrgnInlet_flgChademoCtp3Ena)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(3);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoPxpDiag", Output, &MonEgyChrgnInlet_flgChademoPxpDiag)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(4);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChademoPxpEna", Output, &MonEgyChrgnInlet_flgChademoPxpEna)->SetHostVariable("MonEgyChrgnInletInp_bbOut1")->SetBitPosition(5);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChinaAcCtpDiag", Output, &MonEgyChrgnInlet_flgChinaAcCtpDiag)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(1);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChinaDcAux1", Output, &MonEgyChrgnInlet_flgChinaDcAux1)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(3);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChinaDcCc1Diag", Output, &MonEgyChrgnInlet_flgChinaDcCc1Diag)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(2);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChinaDcCc2Diag", Output, &MonEgyChrgnInlet_flgChinaDcCc2Diag)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(5);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgChinaDcCc2Ena", Output, &MonEgyChrgnInlet_flgChinaDcCc2Ena)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(6);
    Bcu_AddVariable_b("MonEgyChrgnInlet_flgMcsSv3RdntClsd", Output, &MonEgyChrgnInlet_flgMcsSv3RdntClsd)->SetHostVariable("MonEgyChrgnInletInp_bbOut2")->SetBitPosition(4);

    // External variables
    Bcu_AddVariable_u32("Mo_stCplChk", Input, &Mo_stCplChk);
    Bcu_AddVariable_u8("Mo_stMoC", Input, &Mo_stMoC);
    Bcu_AddVariable_u8("Mo_stMoCCpl", Input, &Mo_stMoCCpl);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntCcsAcInlet", Input, &MonEgyChrgnDefn_flgVrntCcsAcInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntCcsDcInlet", Input, &MonEgyChrgnDefn_flgVrntCcsDcInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntCcsPlgLock", Input, &MonEgyChrgnDefn_flgVrntCcsPlgLock);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntChademoInlet", Input, &MonEgyChrgnDefn_flgVrntChademoInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntChinaAcInlet", Input, &MonEgyChrgnDefn_flgVrntChinaAcInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntChinaDcInlet", Input, &MonEgyChrgnDefn_flgVrntChinaDcInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntMcsInlet", Input, &MonEgyChrgnDefn_flgVrntMcsInlet);
    Bcu_AddVariable_b("MonEgyChrgnDefn_flgVrntMcsPlgLock", Input, &MonEgyChrgnDefn_flgVrntMcsPlgLock);

    // Local class instances

    // External class instances
}

// [BCU-GeneratedCode-End]
