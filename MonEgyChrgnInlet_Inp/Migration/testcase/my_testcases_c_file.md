//BCU Header Inclusions
#include <bcu.h>
#include <bcu_scheduler.h>

// #include <my_asseslets.c>
float ret_ChinaChrgnAuxDig1_I_D;
float ret_CtpCcsSwt_O_D;
uint16 ret_ChinaChrgnCc1U2_I_A;
float ret_DiagCtp1Aux_O_D;
float ret_ChaxProxPltSwtDiag2_O_D;
uint32 ret_Pwmin_tiPeriod;
float ret_ChademoChrgnEna_O_D;
uint16 ret_ChaxCtrlPltU1_I_A;
uint16 ret_ChademoChrgnPxpU1_I_A;
float ret_ChademoChrgnRdy_I_D;
uint32 debugger_tpt_write_status;
uint32 ret_Pwmin_tiHighdur;
uint16 ret_BattU_I_A;
uint16 ret_ChinaChrgnPxpU1_I_A;
float ret_DiagPxpRdnt_O_D;
uint16 ret_ChademoChrgnEnaDiagU_I_A;
uint16 ret_ChaxProxPltU1_I_A;
uint16 ret_UPxP1_I_A;
uint16 ret_ChademoChrgnStrt_I_A;
float ret_ChademoChrgnStrt_I_D;
uint16 ret_Pwmin_stSignal;
float ret_ChademoPxpEna_O_D;
float ret_DiagPxp_O_D;
uint32 debugger_tpt_read_status;
float ret_ChaxCtrlPltSwtDiag_O_D;
float ret_ChademoPxp_Dia_O_D;
float ret_ChaxProxPltSwtDiag1_O_D;
uint16 ret_IntlckChrgPlgPosn_I_A;
uint16 ret_ChaxProxPltDiagUNeg_I_A;
uint16 ret_ChademoChrgnCtpU1_I_A;
float ret_ChaxProxPltSwt21_O_D;
uint16 ret_UCtP_I_A;
uint16 ret_ChinaChrgnAuxU2_I_A;
uint16 ret_ChaxProxPltU2_I_A;
uint16 ret_CtPSwtDiag_I_A;
uint16 ret_ChaxCtrlPltU2_I_A;
uint32 ret_Pwmin_rDutycycle;
uint8 Mo_SyC_stSub;
double tpt_stepsize;
double waitTime;
double currentTime = 0.01;
double i;
uint32 GLOBAL_Fault_Code_CplChk_cntr;
double Get_embedded_data(double current_time, double embedded_array[][2]) {
    int j;
    if (current_time <= embedded_array[0][0]) {
        return  embedded_array[0][1];
    }
    for (j = 0; j < sizeof(embedded_array) / sizeof(embedded_array[0]) - 1; j++) {
        if (current_time >= embedded_array[j][0] && current_time < embedded_array[j + 1][0]) {
            return embedded_array[j][1];
        }
    }
    return embedded_array[sizeof(embedded_array) / sizeof(embedded_array[0]) - 1][1];
}


void Error_Reaction_Variants_error(){
double i;
// Check for error reaction after failed complement check
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
	}
	currentTime = i;

    BCU_ASSERT_ARE_EQUAL(((uint32)Bcu_GetPhysValue("Mo_stMoC") & 0x01u), 0x01u);
    BCU_ASSERT_ARE_EQUAL(((uint32)Bcu_GetPhysValue("Mo_stMoCCpl") & 0x01u), 0x00u);
BCU_ASSERT_ARE_NOT_EQUAL(Mo_stCplChk,0x0);

}

void Reset_Complements_Variants_no_error(){
double i;
// Reset all variables related to complement check
Bcu_SetPhysValue("Mo_stMoC", 0);
Bcu_SetPhysValue("Mo_stMoCCpl", 255);
Bcu_SetPhysValue("Mo_stCplChk", 0);
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut1", 0);
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut2", 0);
if(((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHADEMOANCTPIF_SC)) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)) || (CHRGNFCTSFTY_CHADEMOINLET_SC) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC))))
{
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut1Cpl", 255);
}
if(((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC) || (CHRGNFCTSFTY_CHINAACINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHINAANAUX_SC)) || (CHRGNFCTSFTY_CHINADCINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC))))
{
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut2Cpl", 255);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBatt", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattCpl", 65535);
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag", FALSE);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHADEMOANCTPIF_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1", FALSE);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag", FALSE);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag", FALSE);
}
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena", FALSE);
#endif
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag", FALSE);
}
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna", FALSE);
#endif
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag", FALSE);
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHINAANAUX_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1", FALSE);
}
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag", FALSE);
#endif
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag", FALSE);
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena", FALSE);
}
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpCpl", 65535);
}
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLocCpl", 65535);
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpCpl", 65535);
#endif
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl", 65535);
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpCpl", 4294967295);
}
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLocCpl", 4294967295);
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpCpl", 4294967295);
#endif
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl", 4294967295);
#endif
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl", 65535);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp3", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl", 65535);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoPxP", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoPxPCpl", 65535);
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcAux1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcAux1Cpl", 65535);
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl", 65535);
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc2", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl", 65535);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattAct", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattActCpl", 65535);
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpCpl", 65535);
}
#if ((CHRGNFCTSFTY_CCSPLGLOCK_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl", 65535);
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpCpl", 65535);
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1Cpl", 65535);
}
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3Cpl", 65535);
#endif
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpCpl", 65535);
#endif
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl", 65535);
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcCpl", 65535);
#endif
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpCpl", 65535);
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && (CHRGNFCTSFTY_CHINAANAUX_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1Cpl", 65535);
}
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1Cpl", 65535);
#endif
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2Cpl", 65535);
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl", 65535);
}
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
	}
	currentTime = i;

BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("Mo_stMoC"),0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("Mo_stMoCCpl"),255);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("Mo_stCplChk"),0);

}

BCU_AUTO_TESTCASE(TC_Test_Cases_MASST_Ini_TC_1_0_MonEgyChrgnInlet_Inp_Proc_Ini___MASST_default)
{

    Bcu_AddTestAttribute("Applied Test Method", "DT");
    Bcu_AddTestAttribute("Actions", "Wait for initialization to be finished.");
    Bcu_AddTestAttribute("Preconditions", "Init task (simulation of ECU Startup) has to be executed at beginning of TC (Mo_SyC_stSub == 0).");
    Bcu_AddTestAttribute("Test Case ID", "TC 1.0");
    Bcu_AddTestAttribute("Expected Results", "All variables and correspoding complement variables are initialized as specified.");
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_MASST_Ini_TC_1_0_MonEgyChrgnInlet_Inp_Proc_Ini___MASST_default.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
// Mo_SyC_stSub determines which process should be executed for the TC:  
// MO_SYC_REINI                           1U  
// MO_SYC_PROC                           2U  
// MO_SYC_PROC_EXTDTSK          4U  
// MO_SYC_DIAG                            8U  
// MO_SYC_POSTDRIVE                16U  
// MO_SYC_DSM_CLEAR               32U  
// MO_SYC_INI                              64U
Mo_SyC_stSub=64;
// correction factor for compensation of Scheduling differences between executed Fc process in UDE and TPT teststepsize (= FC process Scheduling/Teststepsize)
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        MonEgyChrgnInlet_Inp_Proc_Ini();
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBattCpl"),0XFFFF);
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
if(((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHADEMOANCTPIF_SC)) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)) || (CHRGNFCTSFTY_CHADEMOINLET_SC) || (CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC))))
{
}
if(((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC) || (CHRGNFCTSFTY_CHINAACINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHINAANAUX_SC)) || (CHRGNFCTSFTY_CHINADCINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC))))
{
}
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
#if ((CHRGNFCTSFTY_CCSPLGLOCK_SC))
#endif
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
}
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
}
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
#endif
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
#endif
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && (CHRGNFCTSFTY_CHINAANAUX_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
}
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
#endif
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
#endif
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
}
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#if (CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLocCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLocCpl"),0XFFFFFFFF);
#endif
#if (CHRGNFCTSFTY_CHINAACINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl"),0XFFFFFFFF);
#endif
#if (CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uAdcRawChademoPxPCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl"),0XFFFF);
#endif
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattActCpl"),0XFFFF);
#if (CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC || CHRGNFCTSFTY_CHADEMOINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInletInp_bbOut1Cpl"),0XFF);
#endif
#if (CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC) || CHRGNFCTSFTY_CHINAACINLET_SC || CHRGNFCTSFTY_CHINADCINLET_SC
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInletInp_bbOut2Cpl"),0XFF);
#endif
#if (CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpCpl"),0XFFFFFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtpCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxpCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHINAACINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpCpl"),0XFFFFFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcCpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CCSPLGLOCK_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC))
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1Cpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHADEMOINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3Cpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHINADCINLET_SC && (CHRGNFCTSFTY_CHINAANAUX_SC || CHRGNFCTSFTY_CHAXHWMODL_SC))
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1Cpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHINADCINLET_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1Cpl"),0XFFFF);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2Cpl"),0XFFFF);
#endif
#if (CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl"),0XFFFF);
#endif
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_MASST_CplChk_TC_2_0_MonEgyChrgnInlet_Inp_Proc___MASST_default)
{

    Bcu_AddTestAttribute("Applied Test Method", "DT");
    Bcu_AddTestAttribute("Actions", "Induce at least one complement error for each protected variable");
    Bcu_AddTestAttribute("Preconditions", "All protected variables have no complement error");
    Bcu_AddTestAttribute("Test Case ID", "TC 2.0");
    Bcu_AddTestAttribute("Expected Results", "WHEN at least for one variable the memory error check failed, THEN \"L3 status bits for demands of error reaction in controller monitoring\" is set TRUE and \"L2 complement check failed\" is set to Component ID.");
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_MASST_CplChk_TC_2_0_MonEgyChrgnInlet_Inp_Proc___MASST_default.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
// Mo_SyC_stSub determines which process should be executed for the TC:  
// MO_SYC_REINI                           1U  
// MO_SYC_PROC                           2U  
// MO_SYC_PROC_EXTDTSK          4U  
// MO_SYC_DIAG                            8U  
// MO_SYC_POSTDRIVE                16U  
// MO_SYC_DSM_CLEAR               32U  
// MO_SYC_INI                              64U
Mo_SyC_stSub=2;
// correction factor for compensation of Scheduling differences between executed Fc process in UDE and TPT teststepsize (= FC process Scheduling/Teststepsize)
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

// monegychrgndefn_flgvrntchinaacinlet
// Positive complement check
Reset_Complements_Variants_no_error();
// Start of negative complement check
if(((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC) || (CHRGNFCTSFTY_CHINAACINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHINAANAUX_SC)) || (CHRGNFCTSFTY_CHINADCINLET_SC) || (CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC))))
{
// Complement check for variable MonEgyChrgnInlet_facCorrUBatt
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBatt", 2);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattCpl", 0);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_flgCcsCtpDiag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag", TRUE);
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut1", 1);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHADEMOANCTPIF_SC)))
{
// Complement check for variable MonEgyChrgnInlet_flgChademoCtp1
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
// Complement check for variable MonEgyChrgnInlet_flgChademoCtp1Diag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_flgChademoCtp3Diag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
// Complement check for variable MonEgyChrgnInlet_flgChademoCtp3Ena
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena", TRUE);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
// Complement check for variable MonEgyChrgnInlet_flgChademoPxpDiag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
// Complement check for variable MonEgyChrgnInlet_flgChademoPxpEna
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna", TRUE);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_flgChinaAcCtpDiag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag", TRUE);
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC) && (!CHRGNFCTSFTY_CHINAANAUX_SC)))
{
// Complement check for variable MonEgyChrgnInlet_flgChinaDcAux1
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
// Complement check for variable MonEgyChrgnInlet_flgChinaDcCc1Diag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag", TRUE);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
// Complement check for variable MonEgyChrgnInlet_flgChinaDcCc2Diag
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag", TRUE);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && (!CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
// Complement check for variable MonEgyChrgnInlet_flgChinaDcCc2Ena
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena", TRUE);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_ratPwmCcsCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_ratPwmCcsCtpLoc
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_ratPwmChinaAcCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_ratPwmChinaAcCtpLoc
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_tiPerdCcsCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_tiPerdCcsCtpLoc
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_tiPerdChinaAcCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_tiPerdChinaAcCtpLoc
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uAdcRawChademoCtp1
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp1", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uAdcRawChademoCtp3
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoCtp3", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uAdcRawChademoPxP
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChademoPxP", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
waitTime = 0.01;
for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
    Bcu_Scheduler_ExecuteStep(i);
    Bcu_DataFile_WriteRecord(handleWriter, i);
}
currentTime = i;
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uAdcRawChinaDcCc1
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc1", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uAdcRawChinaDcCc2
Bcu_SetPhysValue("MonEgyChrgnInlet_uAdcRawChinaDcCc2", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
// Complement check for variable MonEgyChrgnInlet_uBattAct
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattAct", 2);
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattActCpl", 0);
Error_Reaction_Variants_error();
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_uRawCcsCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtp", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CCSPLGLOCK_SC))
// Complement check for variable MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CCSACINLET_SC || CHRGNFCTSFTY_CCSDCINLET_SC))
{
// Complement check for variable MonEgyChrgnInlet_uRawCcsPxp
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxp", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && (CHRGNFCTSFTY_CHADEMOANCTPIF_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
// Complement check for variable MonEgyChrgnInlet_uRawChademoCtp1
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChademoCtp3
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHADEMOINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChademoPxp
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxp", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uRawChademoPxpDiagNeg
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChinaAcCc
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINAACINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChinaAcCtp
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && (CHRGNFCTSFTY_CHINAANAUX_SC || CHRGNFCTSFTY_CHAXHWMODL_SC)))
{
// Complement check for variable MonEgyChrgnInlet_uRawChinaDcAux1
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChinaDcCc1
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
#if ((CHRGNFCTSFTY_CHINADCINLET_SC))
// Complement check for variable MonEgyChrgnInlet_uRawChinaDcCc2
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2", 2);
Error_Reaction_Variants_error();
#else
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

#endif
Reset_Complements_Variants_no_error();
if((CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC))
{
// Complement check for variable MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg", 2);
Error_Reaction_Variants_error();
}
else
{
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

}
Reset_Complements_Variants_no_error();
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_1_1_CCS_ADC)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_1_CCS_ADC.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CCSACINLET_SC==true)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 1);
}
if(CHRGNFCTSFTY_CCSDCINLET_SC==true)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsDcInlet", 1);
}
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_1_CCS_ADC.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_UCtP_I_A", 0);
Bcu_SetPhysValue("ret_UPxP1_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.0000000000);
Bcu_SetPhysValue("ret_UCtP_I_A", 64);
Bcu_SetPhysValue("ret_UPxP1_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 39.9987792968750);
Bcu_SetPhysValue("ret_UCtP_I_A", 64512);
Bcu_SetPhysValue("ret_UPxP1_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), -40.0, 0.01);
Bcu_SetPhysValue("ret_UCtP_I_A", 65535);
Bcu_SetPhysValue("ret_UPxP1_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), -0.0390625000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), -0.0390625000);
Bcu_SetPhysValue("ret_UCtP_I_A", 32);
Bcu_SetPhysValue("ret_UPxP1_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 39.9987792968750);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 0);
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_1_2_CCS_PWM)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_2_CCS_PWM.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CCSACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 1);
#endif
#if (CHRGNFCTSFTY_CCSDCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsDcInlet", 1);
#endif
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_2_CCS_PWM.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 0);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 0);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 0);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 1);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 1);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 1);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 0.01, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.01, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.00000005, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.00000005, 0.00000001);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 64);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 64);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 64);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 64);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 0.64, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.64, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.0000032, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000032, 0.00000001);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 64512);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 64512);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 64512);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 128);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 645.12, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 645.12, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.0032256, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0032256, 0.00000001);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 65536);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 65535);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 65535);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 655.35, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 655.35, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.00327675, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.00327675, 0.00000001);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 32);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 32);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 32);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 32);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpLoc"), 0.32, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.32, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpLoc"), 0.0000016, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000016, 0.00000001);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_1_3_CCS_SubSwt)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
    Bcu_SetPhysValue("ret_UCtP_I_A", 0);
    Bcu_SetPhysValue("ret_UPxP1_I_A", 0);
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_3_CCS_SubSwt.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CCSACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 1);
#endif
#if (CHRGNFCTSFTY_CCSDCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsDcInlet", 1);
#endif
ret_Pwmin_rDutycycle=0;
ret_Pwmin_tiHighdur=0;
ret_Pwmin_tiPeriod=0;
ret_Pwmin_stSignal=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_1_3_CCS_SubSwt.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 0.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 0.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 0.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 0.000000000);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 0.0100000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.01, 0.0001);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 655.35);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 655.35, 0.0001);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 655.35);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 0.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 214.748364750);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 214.74836475, 0.00000001);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", -40.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 1.000000000);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 39.998779296875, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", -40.000000000);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), -40.0, 0.01);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 1.00);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 1.000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 39.998779296875);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.0000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 39.998779296875, 0.01);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 0b1111);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtpSubVal_C", 0.0100000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtpSubVal_C", 0.0000000500);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsCtpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPxpSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmCcsCtp"), 0.01, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdCcsCtp"), 0.00000005, 0.00000001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsCtp"), 0.001220703125, 0.0001);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsPxp"), 0.001220703125, 0.0001);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_2_1_CCS_Lock_ADC)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_2_1_CCS_Lock_ADC.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsPlgLock", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_2_1_CCS_Lock_ADC.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_IntlckChrgPlgPosn_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 0.000000000000);
Bcu_SetPhysValue("ret_IntlckChrgPlgPosn_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 39.998779296875);
Bcu_SetPhysValue("ret_IntlckChrgPlgPosn_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), -40.0, 0.01);
Bcu_SetPhysValue("ret_IntlckChrgPlgPosn_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), -0.039062500000);
Bcu_SetPhysValue("ret_IntlckChrgPlgPosn_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 39.9987792968750);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_2_2_CCS_Lock_SubSwt)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_2_2_CCS_Lock_SubSwt.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsPlgLock", 1);
ret_IntlckChrgPlgPosn_I_A=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_2_2_CCS_Lock_SubSwt.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", -40.000000000000);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), -40.0, 0.01);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcsPlgLock_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawCcsPlgPosnSubVal_C", 39.998779296875);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn"), 39.998779296875);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_1_Chademo_ADC_11)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_1_Chademo_ADC_11.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_1_Chademo_ADC_11.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 0);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 0);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 64);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 64);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 64512);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.0, 0.01);
Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 65535);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -0.039062500000);
Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 32);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 32);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.9987792968750);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_2_Chademo_ADC_00)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_2_Chademo_ADC_00.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_2_Chademo_ADC_00.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 0);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 64);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 64512);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.0, 0.01);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 65535);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -0.039062500000);
Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 32);
Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_3_Chademo_DIO_11)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_3_Chademo_DIO_11.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_3_Chademo_DIO_11.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_DiagCtp1Aux_O_D", 1);
Bcu_SetPhysValue("ret_ChademoChrgnEna_O_D", 1);
Bcu_SetPhysValue("ret_ChademoPxpEna_O_D", 1);
Bcu_SetPhysValue("ret_ChademoChrgnStrt_I_D", 1);
Bcu_SetPhysValue("ret_DiagPxp_O_D", 1);
Bcu_SetPhysValue("ret_ChinaChrgnAuxDig1_I_D", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInletInp_bbOut1"), 0b00111100);
Bcu_SetPhysValue("MonEgyChrgnInletInp_bbOut2", 0b01100000);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_4_Chademo_DIO_00)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 0);
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_4_Chademo_DIO_00.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_4_Chademo_DIO_00.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_DiagCtp1Aux_O_D", 1);
Bcu_SetPhysValue("ret_ChademoChrgnEna_O_D", 1);
Bcu_SetPhysValue("ret_ChademoPxpEna_O_D", 1);
Bcu_SetPhysValue("ret_ChademoChrgnStrt_I_D", 1);
Bcu_SetPhysValue("ret_DiagPxp_O_D", 1);
Bcu_SetPhysValue("ret_ChinaChrgnAuxDig1_I_D", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInletInp_bbOut1"), 0b00111010);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInletInp_bbOut2"), 0b01101000);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_5_Chademo_SubSwt_00)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnCtpU1_I_A", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnEnaDiagU_I_A", 0);
    Bcu_SetPhysValue("ret_ChademoChrgnPxpU1_I_A", 0);
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_5_Chademo_SubSwt_00.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
ret_ChademoChrgnStrt_I_D=0;
ret_ChademoChrgnEnaDiagU_I_A=0;
ret_ChademoChrgnEna_O_D=0;
ret_ChademoChrgnPxpU1_I_A=0;
ret_ChademoPxpEna_O_D=0;
ret_DiagPxp_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_5_Chademo_SubSwt_00.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b01000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b01000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b10000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.16);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b10000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.17);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b11111111);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.18);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_3_6_Chademo_SubSwt_11)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_6_Chademo_SubSwt_11.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
ret_ChademoChrgnCtpU1_I_A=0;
ret_DiagCtp1Aux_O_D=0;
ret_ChademoChrgnEnaDiagU_I_A=0;
ret_ChademoChrgnEna_O_D=0;
ret_ChademoChrgnPxpU1_I_A=0;
ret_ChademoPxpEna_O_D=0;
ret_DiagPxp_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_3_6_Chademo_SubSwt_11.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.16);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.17);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.18);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b01000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.19);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b01000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.20);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b10000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.21);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b10000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.22);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b11111111);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.23);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpDiag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_4_1_ChinaDc_ADC_11)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_1_ChinaDc_ADC_11.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_1_ChinaDc_ADC_11.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 0);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 0);
Bcu_SetPhysValue("ret_ChinaChrgnAuxU2_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 64);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 64);
Bcu_SetPhysValue("ret_ChinaChrgnAuxU2_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.998779296875);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 64512);
Bcu_SetPhysValue("ret_ChinaChrgnAuxU2_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -40.0, 0.01);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 65535);
Bcu_SetPhysValue("ret_ChinaChrgnAuxU2_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -0.039062500000);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 32);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 32);
Bcu_SetPhysValue("ret_ChinaChrgnAuxU2_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.9987792968750);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_4_2_ChinaDc_ADC_00)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_2_ChinaDc_ADC_00.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_2_ChinaDc_ADC_00.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 0);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 64);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -0.039062500000);
Bcu_SetPhysValue("ret_ChinaChrgnPxpU1_I_A", 32);
Bcu_SetPhysValue("ret_ChinaChrgnCc1U2_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_4_3_ChinaDc_SubSwt_00)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_3_ChinaDc_SubSwt_00.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
ret_ChinaChrgnAuxDig1_I_D=0;
ret_ChinaChrgnPxpU1_I_A=0;
ret_ChinaChrgnCc1U2_I_A=0;
ret_ChademoPxpEna_O_D=0;
ret_DiagPxp_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_3_ChinaDc_SubSwt_00.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b111111);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.16);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcAux1"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_4_4_ChinaDc_SubSwt_11)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_4_ChinaDc_SubSwt_11.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
ret_ChinaChrgnAuxU2_I_A=0;
ret_ChinaChrgnPxpU1_I_A=0;
ret_ChinaChrgnCc1U2_I_A=0;
ret_ChademoPxpEna_O_D=0;
ret_DiagPxp_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_4_4_ChinaDc_SubSwt_11.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b000100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b001000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b010000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.16);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b100000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.17);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b01000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.18);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b111111);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.19);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_5_1_ChinaAc_ADC)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_5_1_ChinaAc_ADC.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
		/*place you assert function here*/
	}
        BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);

#if (CHRGNFCTSFTY_CHINAACINLET_SC)
        BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -40.0, 0.01);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcCnv_C", 5);
        BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.0, 0.01);
//     currentTime = 0.0;
//     Bcu_ResetVariables();
        BCU_ASSERT_ARE_EQUAL_FLOAT_TOL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.0, 0.01);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_UCtP_I_A", 0);
Bcu_SetPhysValue("ret_UPxP1_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("ret_UCtP_I_A", 64);
Bcu_SetPhysValue("ret_UPxP1_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 39.998779296875);
Bcu_SetPhysValue("ret_UCtP_I_A", 64512);
Bcu_SetPhysValue("ret_UPxP1_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), -40.000000000000);
Bcu_SetPhysValue("ret_UCtP_I_A", 65535);
Bcu_SetPhysValue("ret_UPxP1_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), -0.039062500000);
Bcu_SetPhysValue("ret_UCtP_I_A", 32);
Bcu_SetPhysValue("ret_UPxP1_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 39.9987792968750);
    waitTime =0.01;
    for (i = currentTime;  i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_5_2_ChinaAc_PWM)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_5_2_ChinaAc_PWM.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaAcInlet", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_5_2_ChinaAc_PWM.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 0);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 0);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 0);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 1);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 1);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 1);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 0.010000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.010000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.000000050000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000050000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 64);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 64);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 64);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 64);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 0.640000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.640000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.000003200000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000003200000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 64512);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 64512);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 64512);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 64512);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 645.120000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 645.120000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.003225600000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.003225600000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 65536);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 65535);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 65535);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 65535);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 655.350000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 655.350000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.003276750000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.003276750000);
Bcu_SetPhysValue("ret_Pwmin_rDutycycle", 32);
Bcu_SetPhysValue("ret_Pwmin_tiHighdur", 32);
Bcu_SetPhysValue("ret_Pwmin_tiPeriod", 32);
Bcu_SetPhysValue("ret_Pwmin_stSignal", 32);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpLoc"), 0.320000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.320000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpLoc"), 0.000001600000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000001600000);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_5_3_ChinaAc_SubSwt)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_5_3_ChinaAc_SubSwt.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaAcInlet", 1);
ret_Pwmin_rDutycycle=0;
ret_Pwmin_tiHighdur=0;
ret_Pwmin_tiPeriod=0;
ret_Pwmin_stSignal=0;
ret_UCtP_I_A=0;
ret_UPxP1_I_A=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_5_3_ChinaAc_SubSwt.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 0.010000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.010000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 655.350000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 655.350000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 0.000000050000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000050000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 214.748364750000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 214.748364750000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 0.000000000000);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", -40.000000000000);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 39.998779296875);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 0b1111);
Bcu_SetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtpSubVal_C", 0.010000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtpSubVal_C", 0.000000050000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaAcCcSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_ratPwmChinaAcCtp"), 0.010000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_tiPerdChinaAcCtp"), 0.000000050000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCtp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaAcCc"), 0.001220703125);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_6_1_Battery_Correction)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_6_1_Battery_Correction.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcCnvBatt_C", 5);
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattNom_C", 12);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_6_1_Battery_Correction.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_BattU_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 15);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattAct"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_SetPhysValue("ret_BattU_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 3);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattAct"), 0.0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_SetPhysValue("ret_BattU_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 7);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattAct"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_SetPhysValue("ret_BattU_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattAct"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_SetPhysValue("ret_BattU_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 255);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uBattAct"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 0.2999267578125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", 4);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"),MonEgyChrgnInlet_facCorrUBattSubVal_C);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_6_2_Battery_SubSwt)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_6_2_Battery_SubSwt.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
ret_BattU_I_A=1;
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcCnvBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcCnv_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShiftBatt_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_uBattNom_C", 0);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_6_2_Battery_SubSwt.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", 0.0001220703125);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 0.0001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", 0.0000000000000);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 0.0000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", -4.0000000000000);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), -4.0000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcBatt_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_facCorrUBattSubVal_C", 3.9998779296875);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_facCorrUBatt"), 3.9998779296875);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_1_CCS_DiagSWT_Ctp)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_1_CCS_DiagSWT_Ctp.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CCSACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 1);
#endif
#if (CHRGNFCTSFTY_CCSDCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsDcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_1_CCS_DiagSWT_Ctp.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 1);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 16);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 0);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_2_China_DiagSWT_Ctp)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_2_China_DiagSWT_Ctp.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CHINAACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaAcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 0);
#if (CHRGNFCTSFTY_CCSDIAGSWTCTP_SC)
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_2_China_DiagSWT_Ctp.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 1);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 16);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_2_China_DiagSWT_Ctp.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 2);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 1);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 16);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 1);
#else
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_2_China_DiagSWT_Ctp.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 1);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 16);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 2);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 1);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 16);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 1);
#endif
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_3_noSWT_CCS)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_3_noSWT_CCS.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CCSACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsAcInlet", 1);
#endif
#if (CHRGNFCTSFTY_CCSDCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntCcsDcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiagSubVal_C", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_3_noSWT_CCS.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcCcs_C", 16);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgCcsCtpDiag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_4_noSWT_China)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_4_noSWT_China.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CHINAACINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaAcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiagSubVal_C", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_4_noSWT_China.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 0);
Bcu_SetPhysValue("ret_CtpCcsSwt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaAc_C", 16);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaAcCtpDiag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_5_China_DC_DiagSWT_CC1)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_5_China_DC_DiagSWT_CC1.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CHINADCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_5_China_DC_DiagSWT_CC1.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 1);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 64);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_7_6_China_DC_no_DiagSWT_CC1)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_6_China_DC_no_DiagSWT_CC1.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
#if (CHRGNFCTSFTY_CHINADCINLET_SC)
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
#endif
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 1);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_7_6_China_DC_no_DiagSWT_CC1.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 2);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
Bcu_SetPhysValue("ret_DiagPxpRdnt_O_D", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 64);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_8_1_CHAX_Chademo_ADC)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_1_CHAX_Chademo_ADC.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_1_CHAX_Chademo_ADC.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChaxCtrlPltU1_I_A", 0);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 0);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 0);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("ret_ChaxCtrlPltU1_I_A", 64);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 64);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 64);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 39.998779296875);
Bcu_SetPhysValue("ret_ChaxCtrlPltU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), -40.000000000000);
Bcu_SetPhysValue("ret_ChaxCtrlPltU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), -0.039062500000);
Bcu_SetPhysValue("ret_ChaxCtrlPltU1_I_A", 32);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 32);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 32);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 39.9987792968750);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_8_2_CHAX_Chademo_DIO)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_2_CHAX_Chademo_DIO.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_2_CHAX_Chademo_DIO.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChaxCtrlPltSwtDiag_O_D", 0);
Bcu_SetPhysValue("ret_ChaxProxPltSwt21_O_D", 0);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag1_O_D", 0);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag2_O_D", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
Bcu_SetPhysValue("ret_ChaxCtrlPltSwtDiag_O_D", 1);
Bcu_SetPhysValue("ret_ChaxProxPltSwt21_O_D", 1);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag1_O_D", 1);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag2_O_D", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_8_3_CHAX_Chademo_ADC_SubValue)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_3_CHAX_Chademo_ADC_SubValue.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
ret_ChaxCtrlPltU1_I_A=0;
ret_ChaxProxPltU1_I_A=0;
ret_ChaxProxPltU2_I_A=0;
ret_ChaxProxPltDiagUNeg_I_A=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_3_CHAX_Chademo_ADC_SubValue.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 39.9987792968750);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 0.000000000000);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", -40.000000000000);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 39.998779296875);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b1111);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3SubVal_C", -0.039062500000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpSubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNegSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoCtp3"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxp"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChademoPxpDiagNeg"), 0.001220703125);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_8_4_CHAX_Chademo_DIO_SubValue)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_4_CHAX_Chademo_DIO_SubValue.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHADEMOINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChademoInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 1);
ret_ChaxCtrlPltSwtDiag_O_D=0;
ret_ChaxProxPltSwt21_O_D=0;
ret_ChaxProxPltSwtDiag1_O_D=0;
ret_ChaxProxPltSwtDiag2_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_8_4_CHAX_Chademo_DIO_SubValue.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b11110000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChademo_C", 0b11110000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3EnaSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoCtp3DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChademoPxpEnaSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Ena"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoCtp3Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChademoPxpEna"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_9_1_CHAX_ChinaDc_ADC)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_1_CHAX_ChinaDc_ADC.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0);
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_1_CHAX_ChinaDc_ADC.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 0);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 0);
Bcu_SetPhysValue("ret_ChaxCtrlPltU2_I_A", 0);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 15);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 64);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 64);
Bcu_SetPhysValue("ret_ChaxCtrlPltU2_I_A", 64);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 64);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 3);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 39.998779296875);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxCtrlPltU2_I_A", 64512);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 64512);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), -40.000000000000);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxCtrlPltU2_I_A", 65535);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 65535);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 7);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), -0.039062500000);
Bcu_SetPhysValue("ret_ChaxProxPltU1_I_A", 32);
Bcu_SetPhysValue("ret_ChaxProxPltU2_I_A", 32);
Bcu_SetPhysValue("ret_ChaxCtrlPltU2_I_A", 32);
Bcu_SetPhysValue("ret_ChaxProxPltDiagUNeg_I_A", 32);
Bcu_SetPhysValue("MonEgyChrgnInlet_nrBitShift_C", 255);
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 39.9987792968750);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_9_2_CHAX_ChinaDc_DIO)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_2_CHAX_ChinaDc_DIO.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0);
    tpt_stepsize =0.01;
    waitTime =0.01;
    for (i = currentTime; i < (currentTime + waitTime); i = i + tpt_stepsize) {
        Bcu_Scheduler_ExecuteStep(i);
        Bcu_DataFile_WriteRecord(handleWriter, i);
		/*place you assert function here*/
	}
	currentTime = i;

// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_2_CHAX_ChinaDc_DIO.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag1_O_D", 0);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag2_O_D", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag1_O_D", 1);
Bcu_SetPhysValue("ret_ChaxProxPltSwtDiag2_O_D", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_9_3_CHAX_ChinaDc_ADC_SubValue)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_3_CHAX_ChinaDc_ADC_SubValue.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_facAdcToPinCnv_C", 1);
ret_ChaxProxPltU1_I_A=0;
ret_ChaxProxPltU2_I_A=0;
ret_ChaxCtrlPltU2_I_A=0;
ret_ChaxProxPltDiagUNeg_I_A=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_3_CHAX_ChinaDc_ADC_SubValue.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000001);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 39.9987792968750);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 39.9987792968750);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.04);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.05);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0010);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.06);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.07);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.08);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.09);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), -40.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b0100);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.10);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 39.998779296875);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.11);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 0.000000000000);
Bcu_Scheduler_ExecuteStep(0.12);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", -40.000000000000);
Bcu_Scheduler_ExecuteStep(0.13);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), -40.000000000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b1000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 39.998779296875);
Bcu_Scheduler_ExecuteStep(0.14);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.000000000000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 39.998779296875);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b1111);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2SubVal_C", -0.039062500000);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1SubVal_C", 0.001220703125);
Bcu_SetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNegSubVal_C", 0.001220703125);
Bcu_Scheduler_ExecuteStep(0.15);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2"), -0.039062500000);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcAux1"), 0.001220703125);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg"), 0.001220703125);
Bcu_DataFile_Close(handleWriter);
}


BCU_AUTO_TESTCASE(TC_Test_Cases_Test_case_TC_9_4_CHAX_ChinaDc_DIO_SubValue)
{
Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_4_CHAX_ChinaDc_DIO_SubValue.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
Mo_SyC_stSub=2;
if(CHRGNFCTSFTY_CHINADCINLET_SC && CHRGNFCTSFTY_CHAXHWMODL_SC)
{
Bcu_SetPhysValue("MonEgyChrgnDefn_flgVrntChinaDcInlet", 1);
}
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 1);
ret_ChaxProxPltSwtDiag1_O_D=0;
ret_ChaxProxPltSwtDiag2_O_D=0;
// Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_Test_Cases_Test_case_TC_9_4_CHAX_ChinaDc_DIO_SubValue.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.00);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b00000000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.01);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b11110000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 0);
Bcu_Scheduler_ExecuteStep(0.02);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 0);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 0);
Bcu_SetPhysValue("MonEgyChrgnInlet_stSwtPreProcChinaDc_C", 0b11110000);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1DiagSubVal_C", 1);
Bcu_SetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2DiagSubVal_C", 1);
Bcu_Scheduler_ExecuteStep(0.03);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc1Diag"), 1);
BCU_ASSERT_ARE_EQUAL(Bcu_GetPhysValue("MonEgyChrgnInlet_flgChinaDcCc2Diag"), 1);
Bcu_DataFile_Close(handleWriter);
}


// Optional fault-injection test cases.
// Use this block in case the fault injection code does not cover 100%. If using this, Make sure to change every instance of Fault_Code_CplChk_cntr to GLOBAL_Fault_Code_CplChk_cntr, initialise in my_testcases.c, remove keyword 'static' in declaration from _fault_inj_code.c.

BCU_AUTO_TESTCASE(TC_CCTool_CplChk)
{
    Bcu_Scheduler_Reset();
    currentTime = 0.0;
    Bcu_ResetVariables();
    Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create("TC_CCTool_CplChk.dat", DataFileFormatMdf);
    Bcu_DataFile_AddAllSignals(handleWriter);
    int idxVar=0;
    for(; idxVar<80; idxVar++)
    {
        Mo_SyC_stSub =130;
        Mo_Fault_Injection_CplChk();
        MonEgyChrgnInlet_Inp_Proc();
        if (GLOBAL_Fault_Code_CplChk_cntr%2==0)
        {
            BCU_ASSERT_ARE_EQUAL(Mo_stMoC,1);
            BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,254);
            BCU_ASSERT_ARE_EQUAL(Mo_stCplChk,MONEGYCHRGNINLET_INP_PFC_ID);
        }
        else
        {
            BCU_ASSERT_ARE_EQUAL(Mo_stMoC,0);
            BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,255);
            BCU_ASSERT_ARE_EQUAL(Mo_stCplChk,0);
        }
        Bcu_DataFile_WriteRecord(handleWriter,idxVar*0.01);
    }

    //Test-Case Details
    Bcu_AddTestAttribute("Test area", "TC_CCTool_CplChk");
    Bcu_AddTestAttribute("Test case ID", "TC_1");
    Bcu_AddTestAttribute("Design Identifier (Link to Design-Doc)", "dSD_1");
    Bcu_AddTestAttribute("Pre-Condition (Preparation)", "1.0.0");
    Bcu_AddTestAttribute("Actions / Stimuli (Description of Procedure)", "For each interface, values are corrupted and checked for its compliment value");
    Bcu_AddTestAttribute("Expected Results", "To check if there is no Compliment error is present");
    Bcu_AddTestAttribute("Applied test method", "DT");
    Bcu_AddTestAttribute("To be retested on impact", "To be checked");
    Bcu_AddTestAttribute("Minimum test environment", "SIL");
    Bcu_AddTestAttribute("Test Case Planning", "Open");
    Bcu_AddTestAttribute("Comment", "");
    Bcu_AddTestAttribute("Review Status","Stable");
}

// BCU_AUTO_TESTCASE(TC_1_CCTool_CplChk2)
// {
//     Bcu_Scheduler_Reset();
//     currentTime = 0.0;
//     Bcu_ResetVariables();
//     Bcu_DataFileHandle_t handleWriter = Bcu_DataFile_Create(" TC_1_CCTool_CplChk2.dat", DataFileFormatMdf);
//     Bcu_DataFile_AddAllSignals(handleWriter);
//     int idxVar=0;
//     for(; idxVar<16; idxVar++)
//     {
//         Mo_SyC_stSub =134;
//         Mo_Fault_Injection_VldFloatChk();
//         FC_Name_Proc();
//         if (Fault_Code_VldFloatChk_cntr%2==0)
//         {
//             BCU_ASSERT_ARE_EQUAL(Mo_stMoC,1);
//             BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,254);
//             BCU_ASSERT_ARE_EQUAL(Mo_stVldR32Chk,81);
//         }
//         else
//         {
//             BCU_ASSERT_ARE_EQUAL(Mo_stMoC,0);
//             BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,255);
//             BCU_ASSERT_ARE_EQUAL(Mo_stVldR32Chk,0);
//         }
//         Bcu_DataFile_WriteRecord(handleWriter,idxVar*0.01);
//     }

//     //Test-Case Details
//     Bcu_AddTestAttribute("Test area", "TC_1_CCTool_CplChk2");
//     Bcu_AddTestAttribute("Test case ID", "TC_1_CCTool_CplChk2");
//     Bcu_AddTestAttribute("Design Identifier (Link to Design-Doc)", "dSD_1");
//     Bcu_AddTestAttribute("Pre-Condition (Preparation)", "1.0.0");
//     Bcu_AddTestAttribute("Actions / Stimuli (Description of Procedure)", "For each interface, values are corrupted and checked for its compliment value");
//     Bcu_AddTestAttribute("Expected Results", "To check if there is no Compliment error is present");
//     Bcu_AddTestAttribute("Applied test method", "DT");
//     Bcu_AddTestAttribute("To be retested on impact", "To be checked");
//     Bcu_AddTestAttribute("Minimum test environment", "SIL");
//     Bcu_AddTestAttribute("Test Case Planning", "Open");
//     Bcu_AddTestAttribute("Comment", "");
//     Bcu_AddTestAttribute("Review Status","Stable");
// }
