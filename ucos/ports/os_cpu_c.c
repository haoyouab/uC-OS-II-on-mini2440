#define  OS_CPU_GLOBALS
#include "includes.h"
#include "ucos_ii.h"

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void  OSInitHookBegin (void)
{

}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void  OSInitHookEnd (void)
{
	
}
#endif

#if OS_CPU_HOOKS_EN > 0 
void  OSTaskCreateHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}
#endif

#if OS_CPU_HOOKS_EN > 0 
void  OSTaskDelHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION >= 251
void  OSTaskIdleHook (void)
{
	
}
#endif

#if OS_CPU_HOOKS_EN > 0 
void  OSTaskStatHook (void)
{
}
#endif

OS_STK *OSTaskStkInit (void (*task)(void *pd), void *p_arg, OS_STK *ptos, INT16U opt)
{
    OS_STK *stk;

    opt      = opt;                 /* 'opt' is not used, prevent warning                      */
    	
    stk      = ptos;                /* Load stack pointer                                      */
    
    *(stk)   = (OS_STK)task;        /* Entry Point                                             */
    *(--stk) = (INT32U)0;         	/* LR                                                      */
    *(--stk) = (INT32U)0;         	/* R12                                                     */
    *(--stk) = (INT32U)0;         	/* R11                                                     */
    *(--stk) = (INT32U)0;         	/* R10                                                     */
    *(--stk) = (INT32U)0;         	/* R9                                                      */
    *(--stk) = (INT32U)0;         	/* R8                                                      */
    *(--stk) = (INT32U)0;         	/* R7                                                      */
    *(--stk) = (INT32U)0;         	/* R6                                                      */
    *(--stk) = (INT32U)0;         	/* R5                                                      */
    *(--stk) = (INT32U)0;         	/* R4                                                      */
    *(--stk) = (INT32U)0;         	/* R3                                                      */
    *(--stk) = (INT32U)0;         	/* R2                                                      */
    *(--stk) = (INT32U)0;         	/* R1                                                      */
    *(--stk) = (INT32U)p_arg;		/* R0 : argument                                           */
    *(--stk) = (INT32U)0x00000013L; /* CPSR  (SVC mode, Enable both IRQ and FIQ interrupts)    */
 									         
    return (stk);
}

#if OS_CPU_HOOKS_EN > 0 
void  OSTaskSwHook (void)
{
	
}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void  OSTCBInitHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                                           /* Prevent Compiler warning                 */
}
#endif

#if OS_CPU_HOOKS_EN > 0 
void  OSTimeTickHook (void)
{
	
}
#endif