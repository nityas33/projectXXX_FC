/* over all TPT wait time for CplChk should be : 80 * 10ms */

#include "moexe_co_dat.h"

#include "monegychrgninlet_inp_dat.h"
extern uint8 Mo_SyC_stSub;

uint32 GLOBAL_Fault_Code_CplChk_cntr = 0 ;
/*------ All variables are reset in this code ----------- */
void Mo_Fault_Injection_ResetCode(void)
{
    uint32 cntr = 0;
    MonEgyChrgnInlet_ratPwmCcsCtpLoc = 0;
    MonEgyChrgnInlet_ratPwmCcsCtpLocCpl = 65535;
    MonEgyChrgnInlet_ratPwmChinaAcCtpLoc = 0;
    MonEgyChrgnInlet_ratPwmChinaAcCtpLocCpl = 65535;
    MonEgyChrgnInlet_tiPerdCcsCtpLoc = 0;
    MonEgyChrgnInlet_tiPerdCcsCtpLocCpl = 4294967295;
    MonEgyChrgnInlet_tiPerdChinaAcCtpLoc = 0;
    MonEgyChrgnInlet_tiPerdChinaAcCtpLocCpl = 4294967295;
    MonEgyChrgnInlet_uAdcRawChademoCtp1 = 0;
    MonEgyChrgnInlet_uAdcRawChademoCtp1Cpl = 65535;
    MonEgyChrgnInlet_uAdcRawChademoCtp3 = 0;
    MonEgyChrgnInlet_uAdcRawChademoCtp3Cpl = 65535;
    MonEgyChrgnInlet_uAdcRawChademoPxP = 0;
    MonEgyChrgnInlet_uAdcRawChademoPxPCpl = 65535;
    MonEgyChrgnInlet_uAdcRawChinaDcCc1 = 0;
    MonEgyChrgnInlet_uAdcRawChinaDcCc1Cpl = 65535;
    MonEgyChrgnInlet_uAdcRawChinaDcCc2 = 0;
    MonEgyChrgnInlet_uAdcRawChinaDcCc2Cpl = 65535;
    MonEgyChrgnInlet_uBattAct = 0;
    MonEgyChrgnInlet_uBattActCpl = 65535;
    MonEgyChrgnInletInp_bbOut1 = 0;
    MonEgyChrgnInletInp_bbOut1Cpl = 255;
    MonEgyChrgnInletInp_bbOut2 = 0;
    MonEgyChrgnInletInp_bbOut2Cpl = 255;
    MonEgyChrgnInlet_facCorrUBatt = 0;
    MonEgyChrgnInlet_facCorrUBattCpl = 65535;
    MonEgyChrgnInlet_ratPwmCcsCtp = 0;
    MonEgyChrgnInlet_ratPwmCcsCtpCpl = 65535;
    MonEgyChrgnInlet_ratPwmChinaAcCtp = 0;
    MonEgyChrgnInlet_ratPwmChinaAcCtpCpl = 65535;
    MonEgyChrgnInlet_tiPerdCcsCtp = 0;
    MonEgyChrgnInlet_tiPerdCcsCtpCpl = 4294967295;
    MonEgyChrgnInlet_tiPerdChinaAcCtp = 0;
    MonEgyChrgnInlet_tiPerdChinaAcCtpCpl = 4294967295;
    MonEgyChrgnInlet_uRawCcsCtp = 0;
    MonEgyChrgnInlet_uRawCcsCtpCpl = 65535;
    MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn = 0;
    MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosnCpl = 65535;
    MonEgyChrgnInlet_uRawCcsPxp = 0;
    MonEgyChrgnInlet_uRawCcsPxpCpl = 65535;
    MonEgyChrgnInlet_uRawChademoCtp1 = 0;
    MonEgyChrgnInlet_uRawChademoCtp1Cpl = 65535;
    MonEgyChrgnInlet_uRawChademoCtp3 = 0;
    MonEgyChrgnInlet_uRawChademoCtp3Cpl = 65535;
    MonEgyChrgnInlet_uRawChademoPxp = 0;
    MonEgyChrgnInlet_uRawChademoPxpCpl = 65535;
    MonEgyChrgnInlet_uRawChademoPxpDiagNeg = 0;
    MonEgyChrgnInlet_uRawChademoPxpDiagNegCpl = 65535;
    MonEgyChrgnInlet_uRawChinaAcCc = 0;
    MonEgyChrgnInlet_uRawChinaAcCcCpl = 65535;
    MonEgyChrgnInlet_uRawChinaAcCtp = 0;
    MonEgyChrgnInlet_uRawChinaAcCtpCpl = 65535;
    MonEgyChrgnInlet_uRawChinaDcAux1 = 0;
    MonEgyChrgnInlet_uRawChinaDcAux1Cpl = 65535;
    MonEgyChrgnInlet_uRawChinaDcCc1 = 0;
    MonEgyChrgnInlet_uRawChinaDcCc1Cpl = 65535;
    MonEgyChrgnInlet_uRawChinaDcCc2 = 0;
    MonEgyChrgnInlet_uRawChinaDcCc2Cpl = 65535;
    MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg = 0;
    MonEgyChrgnInlet_uRawChinaDcCc2DiagNegCpl = 65535;
    /* reset complement error information */
    Mo_stMoC    = 0;
    Mo_stMoCCpl = 255;
    Mo_stCplChk = 0;
}

/*------ Fault injection code for complement check ----------- */
void Mo_Fault_Injection_CplChk(void)
{
    if(Mo_SyC_stSub == 130U)
    {
        Mo_Fault_Injection_ResetCode();
        // even numbers no error
        switch (GLOBAL_Fault_Code_CplChk_cntr)
        {
            case 1:
                MonEgyChrgnInlet_ratPwmCcsCtpLoc= 1;
            break;
            case 3:
                MonEgyChrgnInlet_ratPwmChinaAcCtpLoc= 1;
            break;
            case 5:
                MonEgyChrgnInlet_tiPerdCcsCtpLoc= 1;
            break;
            case 7:
                MonEgyChrgnInlet_tiPerdChinaAcCtpLoc= 1;
            break;
            case 9:
                MonEgyChrgnInlet_uAdcRawChademoCtp1= 1;
            break;
            case 11:
                MonEgyChrgnInlet_uAdcRawChademoCtp3= 1;
            break;
            case 13:
                MonEgyChrgnInlet_uAdcRawChademoPxP= 1;
            break;
            case 15:
                MonEgyChrgnInlet_uAdcRawChinaDcCc1= 1;
            break;
            case 17:
                MonEgyChrgnInlet_uAdcRawChinaDcCc2= 1;
            break;
            case 19:
                MonEgyChrgnInlet_uBattAct= 1;
            break;
            case 21:
                MonEgyChrgnInlet_facCorrUBatt= 1;
            break;
            case 23:
        MonEgyChrgnInletInp_bbOut1= 1;
            break;
            case 25:
        MonEgyChrgnInletInp_bbOut1= 2;
            break;
            case 27:
        MonEgyChrgnInletInp_bbOut1= 4;
            break;
            case 29:
        MonEgyChrgnInletInp_bbOut2= 1;
            break;
            case 31:
        MonEgyChrgnInletInp_bbOut1= 8;
            break;
            case 33:
        MonEgyChrgnInletInp_bbOut1= 16;
            break;
            case 35:
        MonEgyChrgnInletInp_bbOut1= 32;
            break;
            case 37:
        MonEgyChrgnInletInp_bbOut2= 2;
            break;
            case 39:
        MonEgyChrgnInletInp_bbOut2= 8;
            break;
            case 41:
        MonEgyChrgnInletInp_bbOut2= 4;
            break;
            case 43:
        MonEgyChrgnInletInp_bbOut2= 32;
            break;
            case 45:
        MonEgyChrgnInletInp_bbOut2= 64;
            break;
            case 47:
                MonEgyChrgnInlet_ratPwmCcsCtp= 1;
            break;
            case 49:
                MonEgyChrgnInlet_ratPwmChinaAcCtp= 1;
            break;
            case 51:
                MonEgyChrgnInlet_tiPerdCcsCtp= 1;
            break;
            case 53:
                MonEgyChrgnInlet_tiPerdChinaAcCtp= 1;
            break;
            case 55:
                MonEgyChrgnInlet_uRawCcsCtp= 1;
            break;
            case 57:
                MonEgyChrgnInlet_uRawCcsIntlckChrgPlgPosn= 1;
            break;
            case 59:
                MonEgyChrgnInlet_uRawCcsPxp= 1;
            break;
            case 61:
                MonEgyChrgnInlet_uRawChademoCtp1= 1;
            break;
            case 63:
                MonEgyChrgnInlet_uRawChademoCtp3= 1;
            break;
            case 65:
                MonEgyChrgnInlet_uRawChademoPxp= 1;
            break;
            case 67:
                MonEgyChrgnInlet_uRawChademoPxpDiagNeg= 1;
            break;
            case 69:
                MonEgyChrgnInlet_uRawChinaAcCc= 1;
            break;
            case 71:
                MonEgyChrgnInlet_uRawChinaAcCtp= 1;
            break;
            case 73:
                MonEgyChrgnInlet_uRawChinaDcAux1= 1;
            break;
            case 75:
                MonEgyChrgnInlet_uRawChinaDcCc1= 1;
            break;
            case 77:
                MonEgyChrgnInlet_uRawChinaDcCc2= 1;
            break;
            case 79:
                MonEgyChrgnInlet_uRawChinaDcCc2DiagNeg= 1;
            break;
			default:
			break;
        }
        GLOBAL_Fault_Code_CplChk_cntr++;
    }
}

/* over all TPT wait time for VldFloatChk should be : 0 * 10ms */

// static uint32 Fault_Code_VldFloatChk_cntr = 0 ;

// /*------ All variables are reset in this code ----------- */
// void Mo_Fault_Injection_ResetCode_VldFloat(void)
// {
//     uint32 cntr = 0;
//     /* reset Valid Float error information */
//     Mo_stMoC         = 0;
//     Mo_stMoCCpl      = 255;
//     //Mo_stVldR32Chk   = 0;
// }

// /*------ Fault injection code for ValidFloat check ----------- */
// void Mo_Fault_Injection_VldFloatChk(void)
// {
//     if(Mo_SyC_stSub == 134U)
//     {
//         Mo_Fault_Injection_ResetCode();
//         Mo_Fault_Injection_ResetCode_VldFloat();
//         // even numbers no error
//         switch (Fault_Code_VldFloatChk_cntr)
//         {
//          default:
//          break;
//         }
//         Fault_Code_VldFloatChk_cntr++;
//     }
// }

