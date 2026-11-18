# Script Conversion Template
Start of Phase 1
Phase :1
Step 1:
TPTcode:
Example input1:

     <assesslet_script><![CDATA[MoFRelsMngt_flgBrkSt_Out = TPT.BooleanX();

def BrakeStatus(_flgBrkMai, _flgBrkRdnt,_flgBrkErr, TYPE):
 _flgBrkSt = TPT.Boolean();
 
 if((MoFRelsMngt_stSwtCfgPtRels_C & 1) == 1):
   _flgBrkSt = (_flgBrkMai || _flgBrkRdnt) and (not _flgBrkErr);
 else:
   _flgBrkSt = (_flgBrkMai && _flgBrkRdnt) and (not _flgBrkErr);

 if(TYPE=="flgBrkSt"):
   return _flgBrkSt;
      
during TPT.regexp([t >= 0]):                           

 MoFRelsMngt_flgBrkSt_Out(t)       := BrakeStatus(MoFBrk_flgBrkMai,
                                                  MoFBrk_flgBrkRdnt,
                                                  MoFBrk_flgBrkErr,
                                                  "flgBrkSt")            
								]]></assesslet_script>

Example output1:
Note: FileName refer <execconfigattr key="FC under Test" value="FC : MoFRelsMngt_PtRels / 4.7.0;1"/>

python_content

FileName.py

/* BrakeStatus*/

MoFRelsMngt_flgBrkSt_Out = TPT.BooleanX();

def BrakeStatus(_flgBrkMai, _flgBrkRdnt,_flgBrkErr, TYPE):
 _flgBrkSt = TPT.Boolean();
 
 if((MoFRelsMngt_stSwtCfgPtRels_C & 1) == 1):
   _flgBrkSt = (_flgBrkMai || _flgBrkRdnt) and (not _flgBrkErr);
 else:
   _flgBrkSt = (_flgBrkMai && _flgBrkRdnt) and (not _flgBrkErr);

 if(TYPE=="flgBrkSt"):
   return _flgBrkSt;
   
 MoFRelsMngt_flgBrkSt_Out(t)       := BrakeStatus(MoFBrk_flgBrkMai,
                                                  MoFBrk_flgBrkRdnt,
                                                  MoFBrk_flgBrkErr,
                                                  "flgBrkSt")		
End of Phase 1  

# python to c code Conversion Template
Start of Phase 2
Phase :2
Step 1:
Example input1:

python_content
/*convert_python_to_c*/

FileName.py

/* BrakeStatus*/

MoFRelsMngt_flgBrkSt_Out = TPT.BooleanX();

def BrakeStatus(_flgBrkMai, _flgBrkRdnt,_flgBrkErr, TYPE):
 _flgBrkSt = TPT.Boolean();
 
 if((MoFRelsMngt_stSwtCfgPtRels_C & 1) == 1):
   _flgBrkSt = (_flgBrkMai || _flgBrkRdnt) and (not _flgBrkErr);
 else:
   _flgBrkSt = (_flgBrkMai && _flgBrkRdnt) and (not _flgBrkErr);

 if(TYPE=="flgBrkSt"):
   return _flgBrkSt;
   
 MoFRelsMngt_flgBrkSt_Out(t)       := BrakeStatus(MoFBrk_flgBrkMai,
                                                  MoFBrk_flgBrkRdnt,
                                                  MoFBrk_flgBrkErr,
                                                  "flgBrkSt")

Example output1:

Note: FileName refer <execconfigattr key="FC under Test" value="FC : MoFRelsMngt_PtRels / 4.7.0;1"/>

convert_to_c:
/*c convertion sample */
```C
assesslets.c

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mofsrv_lib.h"
#include "my_pavast_stubs.h"
#include "my_stubs.h"
#include "assesslets.h"

/* Function: BrakeStatus */
bool MoFRelsMngt_flgBrkSt_Out_t = false; /* Output variable declaration */
bool BrakeStatus(bool flgBrkMai, bool flgBrkRdnt, bool flgBrkErr, const char* TYPE);
bool MoFRelsMngt_flgBrkSt_Out(void);

/* Function: BrakeStatus */
bool BrakeStatus(bool flgBrkMai, bool flgBrkRdnt, bool flgBrkErr, const char* TYPE)
{
    bool flgBrkSt;
    
    /* Check configuration bit 0 of MoFRelsMngt_stSwtCfgPtRels_C */
    if ((MoFRelsMngt_stSwtCfgPtRels_C & 1U) == 1U) {
        /* OR logic: Either main OR redundant brake active, AND no error */
        flgBrkSt = (flgBrkMai || flgBrkRdnt) && (!flgBrkErr);
    } else {
        /* AND logic: Both main AND redundant brake active, AND no error */
        flgBrkSt = (flgBrkMai && flgBrkRdnt) && (!flgBrkErr);
    }
    
    return flgBrkSt;
}

bool MoFRelsMngt_flgBrkSt_Out(void)
{
    return (MoFRelsMngt_flgBrkSt_Out_t =  BrakeStatus(MoFBrk_flgBrkMai, MoFBrk_flgBrkRdnt, MoFBrk_flgBrkErr, "flgBrkSt"));
}
```
/*Header convertion sample */
```C
assesslets.h
#include <stdbool.h>
#include <stdint.h>
#include "my_pavast_stubs.h"
#include "my_stubs.h"

/* Function declarations */

/* Function: BrakeStatus */
extern bool MoFRelsMngt_flgBrkSt_Out_t; /* Output variable declaration */
extern bool BrakeStatus(bool flgBrkMai, bool flgBrkRdnt, bool flgBrkErr, const char* TYPE);
extern bool MoFRelsMngt_flgBrkSt_Out(void);
```
End of Phase 2
