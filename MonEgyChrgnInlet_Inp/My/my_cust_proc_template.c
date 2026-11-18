/*******************************************************
*** This template contains customized proc scheduler ***
********************************************************/

void CallScheduler_ini(double stepsize, double waitTime, Bcu_DataFileHandle_t handleWriter);
void CallScheduler_ReIni(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter);
void CallScheduler_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter);
void CallScheduler_embedded_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter);
void CallScheduler_diag_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter);
void CallScheduler_fault_injection_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter);

void CallScheduler_ini(double stepsize, double waitTime, Bcu_DataFileHandle_t handleWriter)
{
	Bcu_DataFile_AddAllSignals(handleWriter);
	for(double i=stepsize;i<=waitTime;i=i+stepsize)
	{
		// Module_ini_proc()
		Bcu_DataFile_WriteRecord(handleWriter,i);
	}
}

void CallScheduler_ReIni(double rasterTime, double waitTime,Bcu_DataFileHandle_t handleWriter)
{
	double i;
	for(i=rasterTime;i<rasterTime+waitTime*0.001;i=i+0.01)
	{	
		// Module_reini_proc()	
		Bcu_DataFile_WriteRecord(handleWriter,i);
	}
	rasterTime=i;
}

void CallScheduler_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter)
{
	double i;
	for(i=rasterTime;i<rasterTime+waitTime*0.001;i=i+0.01)
	{
		// call assesslet/script 
		Bcu_Scheduler_ExecuteStep(i);
		//assert the expected and actual values 
		Bcu_DataFile_WriteRecord(handleWriter,i);
	}
	rasterTime=i;
}
void CallScheduler_embedded_proc(double rasterTime, double waitTime, Bcu_DataFileHandle_t handleWriter)
{
    double i;
    int k;
    for(i=rasterTime;i<rasterTime+waitTime*0.001;i=i+0.01)
    {
        k=i*100;
        // initialize all the input using the embedded array
        // call assesslet/script
        Bcu_Scheduler_ExecuteStep(i);
        //assert the expected and actual values 
        Bcu_DataFile_WriteRecord(handleWriter,i);
    }
    rasterTime=i;
}

void CallScheduler_diag_proc(double rasterTime, double waitTime,Bcu_DataFileHandle_t handleWriter)
{
	double i;
	for(i=rasterTime;i<rasterTime+waitTime*0.001;i=i+0.01)
	{	
		//Module diag proc
		Bcu_DataFile_WriteRecord(handleWriter,i);
	}
	rasterTime=i;
}

void CallScheduler_fault_injection_proc(double rasterTime, double waitTime,Bcu_DataFileHandle_t handleWriter)
{
uint32 GLOBAL_Fault_Code_CplChk_cntr;
double i;
for(i=rasterTime;i<rasterTime+waitTime*0.001;i=i+0.01)
{
Bcu_Scheduler_ExecuteStep(i);
Bcu_DataFile_WriteRecord(handleWriter,i);
GLOBAL_Fault_Code_CplChk_cntr = (i*100)-1;
if(GLOBAL_Fault_Code_CplChk_cntr / 2 == 0)
{
BCU_ASSERT_ARE_EQUAL(Mo_stMoC,158);
BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,63);
BCU_ASSERT_ARE_EQUAL(Mo_stCplChk,240);
}
else
{
BCU_ASSERT_ARE_EQUAL(Mo_stMoC,0);
BCU_ASSERT_ARE_EQUAL(Mo_stMoCCpl,255);
BCU_ASSERT_ARE_EQUAL(Mo_stCplChk,0);
}
}
rasterTime=i;
}

