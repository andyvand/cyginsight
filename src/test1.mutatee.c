/*
 * Copyright (c) 1996-2004 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * This license is for research uses.  For such uses, there is no
 * charge. We define "research use" to mean you may freely use it
 * inside your organization for whatever purposes you see fit. But you
 * may not re-distribute Paradyn or parts of Paradyn, in any form
 * source or binary (including derivatives), electronic or otherwise,
 * to any other organization or entity without our permission.
 * 
 * (for other uses, please contact us at paradyn@cs.wisc.edu)
 * 
 * All warranties, including without limitation, any warranty of
 * merchantability or fitness for a particular purpose, are hereby
 * excluded.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * Even if advised of the possibility of such damages, under no
 * circumstances shall we (or any other person or entity with
 * proprietary rights in the software licensed hereunder) be liable
 * to you or any third party for direct, indirect, or consequential
 * damages of any character regardless of type of action, including,
 * without limitation, loss of profits, loss of use, loss of good
 * will, or computer failure or malfunction.  You agree to indemnify
 * us (and any other person or entity with proprietary rights in the
 * software licensed hereunder) for any and all liability it may
 * incur to third parties resulting from your use of Paradyn.
 */

/* Test application (Mutatee) */

/* $Id: test1.mutatee.c,v 1.11 2006/10/11 21:52:11 cooksey Exp $ */

#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "mutatee_util.h"

#ifdef i386_unknown_nt4_0
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "test1.h"
#ifdef __cplusplus
#include "cpp_test.h"
#include <iostream>
#endif

#if defined(sparc_sun_solaris2_4) \
 || defined(alpha_dec_osf4_0) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(i386_unknown_solaris2_5) \
 || defined(ia64_unknown_linux2_4) \
 || defined(os_aix)
#include <dlfcn.h> /* For replaceFunction test */
#endif

#if defined(os_windows)
#define DLLEXPORT __declspec( dllexport )
#else
#define DLLEXPORT
#endif

#include "test1.mutateeCommon.h"

#ifdef __cplusplus
int mutateeCplusplus = 1;
#else
int mutateeCplusplus = 0;
#endif

int mutateeFortran = 0;
int mutateeF77 = 0;


/*
typedef struct {
    int field1;
    int field2;
} struct26_1;
*/
struct struct26_1 {
    int field1;
    int field2;
};

/*
typedef struct {
    int field1;
    int field2;
    int field3[10];
    struct26_1 field4;
} struct26_2;
*/

struct struct26_2 {
    int field1;
    int field2;
    int field3[10];
    struct struct26_1 field4;
};

int globalVariable1_1 = 0;
int globalVariable3_1 = 31;
int globalVariable4_1 = 41;
int globalVariable5_1 = 51;
int globalVariable5_2 = 51;

int constVar0 = 0;
int constVar1 = 1;
int constVar2 = 2;
int constVar3 = 3;
int constVar4 = 4;
int constVar5 = 5;
int constVar6 = 6;
int constVar7 = 7;
int constVar9 = 9;
int constVar10 = 10;
int constVar60 = 60;
int constVar64 = 64;
int constVar66 = 66;
int constVar67 = 67;

int globalVariable6_1 = (int)0xdeadbeef;
int globalVariable6_2 = (int)0xdeadbeef;
int globalVariable6_3 = (int)0xdeadbeef;
int globalVariable6_4 = (int)0xdeadbeef;
int globalVariable6_5 = (int)0xdeadbeef;
int globalVariable6_6 = (int)0xdeadbeef;
int globalVariable6_1a = (int)0xdeadbeef;
int globalVariable6_2a = (int)0xdeadbeef;
int globalVariable6_3a = (int)0xdeadbeef;
int globalVariable6_4a = (int)0xdeadbeef;
int globalVariable6_5a = (int)0xdeadbeef;
int globalVariable6_6a = (int)0xdeadbeef;

int globalVariable7_1 = 71, globalVariable7_2 = 71,
    globalVariable7_3 = 71, globalVariable7_4 = 71,
    globalVariable7_5 = 71, globalVariable7_6 = 71,
    globalVariable7_7 = 71, globalVariable7_8 = 71,
    globalVariable7_9 = 71, globalVariable7_10 = 71,
    globalVariable7_11 = 71, globalVariable7_12 = 71,
    globalVariable7_13 = 71, globalVariable7_14 = 71,
    globalVariable7_15 = 71, globalVariable7_16 = 71;

int globalVariable7_1a = 73, globalVariable7_2a = 73,
    globalVariable7_3a = 73, globalVariable7_4a = 73,
    globalVariable7_5a = 73, globalVariable7_6a = 73,
    globalVariable7_7a = 73, globalVariable7_8a = 73,
    globalVariable7_9a = 73, globalVariable7_10a = 73,
    globalVariable7_11a = 73, globalVariable7_12a = 73,
    globalVariable7_13a = 73, globalVariable7_14a = 73,
    globalVariable7_15a = 73, globalVariable7_16a = 73;

int globalVariable8_1 = 1;

int globalVariable10_1 = 0, globalVariable10_2 = 0,
    globalVariable10_3 = 0, globalVariable10_4 = 0;

int globalVariable11_1 = 0, globalVariable11_2 = 0,
    globalVariable11_3 = 0, globalVariable11_4 = 0, globalVariable11_5 = 0;

int globalVariable12_1 = 0;

int globalVariable13_1 = 0;

int globalVariable14_1 = 0;
int globalVariable14_2 = 0;

int globalVariable15_1 = 0;
int globalVariable15_2 = 0;
int globalVariable15_3 = 0;
int globalVariable15_4 = 0;

int globalVariable16_1 = 0;
int globalVariable16_2 = 0;
int globalVariable16_3 = 0;
int globalVariable16_4 = 0;
int globalVariable16_5 = 0;
int globalVariable16_6 = 0;
int globalVariable16_7 = 0;
int globalVariable16_8 = 0;
int globalVariable16_9 = 0;
int globalVariable16_10 = 0;

int globalVariable17_1 = 0;
int globalVariable17_2 = 0;

int globalVariable18_1 = 42;

int globalVariable19_1 = (int)0xdeadbeef;
int globalVariable19_2 = (int)0xdeadbeef;

int globalVariable20_1 = (int)0xdeadbeef;
double globalVariable20_2 = 0.0;

int globalVariable22_1 = 0;
int globalVariable22_2 = 0;
int globalVariable22_3 = 0;
int globalVariable22_4 = 0;

unsigned long globalVariable30_1 = 0;
unsigned long globalVariable30_2 = 0;

unsigned long globalVariable30_3 = 0;
unsigned long globalVariable30_4 = 0;
unsigned long globalVariable30_5 = 0;
unsigned long globalVariable30_6 = 0;

int globalVariable31_1 = 0;
int globalVariable31_2 = 0;
int globalVariable31_3 = 0;
int globalVariable31_4 = 0;

int globalVariable32_1 = 0;
int globalVariable32_2 = 0;
int globalVariable32_3 = 0;
int globalVariable32_4 = 0;

int globalVariable33_1 = 0;

int globalVariable36_1 = 0;
int globalVariable36_2 = 0;
int globalVariable36_3 = 0;
int globalVariable36_4 = 0;
int globalVariable36_5 = 0;
int globalVariable36_6 = 0;
int globalVariable36_7 = 0;
int globalVariable36_8 = 0;
int globalVariable36_9 = 0;
int globalVariable36_10 = 0;

/* A couple of dlopen-related functions. Moved here from mutatee_util
   so as not to introduce the libdl dependency on all mutatees */
#if defined(os_windows)
void printSysError(unsigned errNo) {
    char buf[1000];
    int result = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, errNo, 
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		  buf, 1000, NULL);
    if (!result) {
        fprintf(stderr, "Couldn't print error message\n");
    }
    fprintf(stderr, "%s\n", buf);
}

void *loadDynamicLibrary(char *name) {
  void *result = (void *) LoadLibrary(name);
  if (!result) {
      fprintf(stderr, "[%s:%u] - The mutatee could not load %s\n", __FILE__, __LINE__);
      printSysError(GetLastError());
  }
  return result;
}

void *getFuncFromDLL(void *libhandle, char *func_name) {
    void *result;
    if (!libhandle || !func_name) {
        fprintf(stderr, "[%s:%u] - Test error - getFuncFromDLL passed NULL "
                "parameter\n", __FILE__, __LINE__);
        return NULL;            
    }
    result = GetProcAddress((HMODULE) libhandle, func_name);
    if (!result) {
        fprintf(stderr, "[%s:%u] - Couldn't load symbol %s\n", __FILE__, __LINE__, func_name);
        printSysError(GetLastError());
    }
    return result;
}
#else
void *loadDynamicLibrary(char *name) {
    void *result;
#if defined(os_solaris)
    int dlopenMode = RTLD_NOW | RTLD_GLOBAL;
#else
    int dlopenMode = RTLD_NOW;
#endif
    result = dlopen(name, dlopenMode);
    if (!result) {
        perror("The mutatee couldn't load a dynamic library");
    }
    return result;
}

void *getFuncFromDLL(void *libhandle, char *func_name) {
    void *result = dlsym(libhandle, func_name);
    if (!result) {
        perror("The mutatee couldn't find a function");
    }
    return result;
}
#endif

/*
 * Determine if two doubles are close to being equal (for our purposes, that
 * means to ten decimal places).
 */
int eq_doubles(double a, double b)
{
    double diff = a - b;

    if (diff < 0) diff = -diff;

    if (diff < 0.00000000001) return 1;
    else return 0;
}

void call1_1()
{
    dprintf("call1() called - setting globalVariable1_1 = 11\n");
    globalVariable1_1 = 11;
}

void call2_1(int arg1, int arg2, char *arg3, void *arg4)
{
    assert(TEST_PTR_SIZE == sizeof(void *));

    if ((arg1 == 1) && (arg2 == 2) && (!strcmp(arg3, "testString2_1")) &&
	(arg4 == TEST_PTR)) {
	logerror("Passed test #2 (four parameter function)\n");
	passedTest[2] = TRUE;
    } else {
	logerror("**Failed** test #2 (four parameter function)\n");
	if (arg1 != 1)
	    logerror("    arg1 = %d, should be 1\n", arg1);
	if (arg2 != 2)
	    logerror("    arg2 = %d, should be 2\n", arg2);
	if (strcmp(arg3, "testString2_1"))
	    logerror("    arg3 = %s, should be \"testString2_1\"\n", arg3);
	if (arg4 != TEST_PTR)
	    logerror("    arg4 = %p, should be %p\n", arg4, TEST_PTR);
    }
}

void call3_1(int arg1, int arg2)
{
    if ((arg1 == 31) && (arg2 == 32))  {
	logerror("Passed test #3 (passing variables to functions)\n");
	passedTest[3] = TRUE;
    } else {
	logerror("**Failed** test #3 (passing variables to functions)\n");
	logerror("    arg1 = %d, should be 31\n", arg1);
	logerror("    arg2 = %d, should be 32\n", arg2);
    }
}

int call9_1(int p1, int p2, int p3, int p4, int p5)
{
    int x;
    x = (((p1 + p2) + (p3 + p4) + (p5)));
    if (x != (91 + 92 + 93 + 94 + 95 )) {
      logerror("**Failed** test case #9 (preserve registers - funcCall)\n");
      if (p1 != 91) logerror("    call9_1 parameter 1 is %d not 91\n", p1);
      if (p2 != 92) logerror("    call9_1 parameter 2 is %d not 92\n", p2);
      if (p3 != 93) logerror("    call9_1 parameter 3 is %d not 93\n", p3);
      if (p4 != 94) logerror("    call9_1 parameter 4 is %d not 94\n", p4);
      if (p5 != 95) logerror("    call9_1 parameter 5 is %d not 95\n", p5);
      exit(-1);
    }
    dprintf("inside call9_1\n");
    return x;
}

void call10_1()
{
    if (globalVariable10_4 == 0) {
	globalVariable10_4 = 1;
	globalVariable10_1 = 1;
    }
}


void call10_2()
{
    if (globalVariable10_4 == 1) {
	globalVariable10_4 = 2;
	globalVariable10_2 = 1;
    }
}

void call10_3()
{
    if (globalVariable10_4 == 2) {
	globalVariable10_4 = 3;
	globalVariable10_3 = 1;
    }
}

void call11_1()
{
    if (globalVariable11_1 == 0) globalVariable11_2 = 1;
}

void call11_2()
{
    if (globalVariable11_1 == 1) globalVariable11_3 = 1;
}

void call11_3()
{
    if (globalVariable11_1 == 2) globalVariable11_4 = 1;
}

void call11_4()
{
    if (globalVariable11_1 == 3) globalVariable11_5 = 1;

    if (globalVariable11_2 && globalVariable11_3 &&
	globalVariable11_4 && globalVariable11_5) {
        logerror("Passed test #11 (snippets at entry,exit,call)\n");
	passedTest[11] = TRUE;
    } else {
        logerror("**Failed test #11 (snippets at entry,exit,call)\n");
	if (!globalVariable11_2)
	    logerror("    entry snippet not called at the correct time\n");
	if (!globalVariable11_3)
	    logerror("    pre call snippet not called at the correct time\n");
	if (!globalVariable11_4)
	    logerror("    post call snippet not called at the correct time\n");
	if (!globalVariable11_5)
	    logerror("    exit snippet not called at the correct time\n");
    }
}

void call12_1()
{
    globalVariable12_1++;
}

void call13_1(int a1, int a2, int a3, int a4, int a5)
{
    if (a1 == 131) globalVariable13_1 |= 1;
    if (a2 == 132) globalVariable13_1 |= 2;
    if (a3 == 133) globalVariable13_1 |= 4;
    if (a4 == 134) globalVariable13_1 |= 8;
    if (a5 == 135) globalVariable13_1 |= 16;
    dprintf("a1 = %d\n", a1);
    dprintf("a2 = %d\n", a2);
    dprintf("a3 = %d\n", a3);
    dprintf("a4 = %d\n", a4);
    dprintf("a5 = %d\n", a5);
}

void call13_2(int ret)
{
    if (ret == RET13_1) globalVariable13_1 |= 32;
}

void call14_1()
{
    globalVariable14_1 = 1;
}

void call15_1()
{
    globalVariable15_1++;
}

void call15_2()
{
    globalVariable15_2++;
}

void call15_3()
{
    globalVariable15_3++;
}

int call17_1(int p1)
{
     /* make sure the function uses lots of registers */

     int a1, a2, a3, a4, a5, a6, a7;

     dprintf("call17_1 (p1=%d)\n", p1);
     assert(p1!=0); /* shouldn't try to divide by zero! */
     assert(p1==1); /* actually only expect calls with p1==1 */

     a1 = p1;
     a2 = a1 + p1;
     a3 = a1 * a2;
     a4 = a3 / p1;
     a5 = a4 + p1;
     a6 = a5 + a1;
     a7 = a6 + p1;

     dprintf("call17_1 (ret=%d)\n", a7);

     return a7;
}

int call17_2(int p1)
{
     /* make sure the function uses lots of registers */

     int a1, a2, a3, a4, a5, a6, a7;

     dprintf("call17_2 (p1=%d)\n", p1);
     assert(p1!=0); /* shouldn't try to divide by zero! */
     assert(p1==1); /* actually only expect calls with p1==1 */

     a1 = p1;
     a2 = a1 + p1;
     a3 = a1 * a2;
     a4 = a3 / p1;
     a5 = a4 + p1;
     a6 = a5 + a1;
     a7 = a6 + p1;
     globalVariable17_2 = RAN17_1;

     dprintf("call17_2 (ret=%d)\n", a7);

     return a7;
}

void call19_1()
{
    globalVariable19_1 = MAGIC19_1;
}

void call19_2()
{
    globalVariable19_2 = MAGIC19_2;
}

volatile int ta = TEST20_A;
volatile double tb = TEST20_B;



void call20_1()
{
    globalVariable20_1 = ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+
			 (ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+
			 (ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+
			 (ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta+(ta
			 ))))))))))))))))))))))))))))))))))))))));

    globalVariable20_2 = tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+
			 (tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+
			 (tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+
			 (tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb+(tb
			 ))))))))))))))))))))))))))))))))))))))));
}

int call22_1(int x)
{
    return x + MAGIC22_1;
}

int call22_2(int x)
{
    return x + MAGIC22_2;
}

int call22_3(int x)
{
    return x + MAGIC22_3;
}

int call22_7(int x)
{
    return x + MAGIC22_7;
}

#if defined(sparc_sun_solaris2_4) \
 || defined(i386_unknown_solaris2_5) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(i386_unknown_nt4_0) \
 || defined(rs6000_ibm_aix4_1) \
 || defined(alpha_dec_osf4_0) \
 || defined(ia64_unknown_linux2_4)

/* this function has to be only 1 line for test30 to pass */
/* these two lines has to be together otherwise test30 will fail */
unsigned long globalVariable30_7 = __LINE__;
void call30_1(){ globalVariable30_1 = __LINE__; globalVariable30_2 = (unsigned long)call30_1;}

#endif

/*
 * This is a series of nearly empty functions to attach code to
 */

/*
 * Start of Test #1
 */
void func1_1()
{
    void func1_2();
    dprintf("Value of globalVariable1_1 is %d.\n", globalVariable1_1);

    func1_2();

    dprintf("Value of globalVariable1_1 is now %d.\n", globalVariable1_1);

    if (globalVariable1_1 == 11) {
        logerror("\nPassed test #1 (zero arg function call)\n");
		passedTest[1] = TRUE;
    } else {
        logerror("\n**Failed** test #1 (zero arg function call)\n");
    }
    flushOutputLog();
}

void func1_2() { dprintf("func1_2 () called\n"); }

/*
 * Start of Test #2
 */
void func2_1() { dprintf("func2_1 () called\n"); }

/*
 * Start of Test #3
 */
void func3_1() { dprintf("func3_1 () called\n"); }

/*
 * Start of Test #4 - sequence
 *	Run two expressions and verify correct ordering.
 */
void func4_1()
{
    void func4_2();

    kludge = 1;	/* Here so that the following function call isn't the first
		   instruction */
    func4_2();

    if (globalVariable4_1 == 41) {
	logerror("**Failed** test #4 (sequence)\n");
	logerror("    none of the items were executed\n");
    } else if (globalVariable4_1 == 42) {
	logerror("**Failed** test #4 (sequence)\n");
	logerror("    first item was the last (or only) one to execute\n");
    } else if (globalVariable4_1 == 43) {
        logerror("Passed test #4 (sequence)\n");
	passedTest[4] = TRUE;
    }
}

void func4_2() { dprintf("func4_1 () called\n"); }

/*
 * Start of Test #5 - if w.o. else
 *	Execute two if statements, one true and one false.
 */
void func5_1()
{
    void func5_2();
    func5_2();

    if ((globalVariable5_1 == 51) && (globalVariable5_2 == 53)) {
        logerror("Passed test #5 (if w.o. else)\n");
		passedTest[5] = TRUE;
    } else {
	logerror("**Failed** test #5 (if w.o. else)\n");
	if (globalVariable5_1 != 51) {
	    logerror("    condition executed for false\n");
	}
	if (globalVariable5_2 != 53) {
	    logerror("    condition not executed for true\n");
	}
    }
}

void func5_2() { dprintf("func5_1 () called\n"); }

/*
 * Start of Test #6 - arithmetic operators
 *	Verify arithmetic operators:
 *		constant integer addition
 *		constant integer subtraction
 *		constant integer divide (using large constants)
 *		constant integer divide (small consts)
 *		constant integer multiply
 *		constant comma operator
 *		variable integer addition
 *		variable integer subtraction
 *		variable integer divide (using large constants)
 *		variable integer divide (small consts)
 *		variable integer multiply
 *		variable comma operator
 *
 *	constant - use constant expressions
 *	variable - use variables in the expressions
 *
 */
void func6_1()
{
    void func6_2();
    func6_2();
    if ((globalVariable6_1 == 60+2) && (globalVariable6_2 == 64-1) &&
	(globalVariable6_3 == 66/3) && (globalVariable6_4 == 67/3) &&
	(globalVariable6_5 == 6 * 5) && (globalVariable6_6 == 3) &&
    	(globalVariable6_1a == 60+2) && (globalVariable6_2a == 64-1) &&
	(globalVariable6_3a == 66/3) && (globalVariable6_4a == 67/3) &&
	(globalVariable6_5a == 6 * 5) && (globalVariable6_6a == 3)) {
	logerror("Passed test #6 (arithmetic operators)\n");
	passedTest[6] = TRUE;
    } else {
	logerror("**Failed** test #6 (arithmetic operators)\n");
	if (globalVariable6_1 != 60+2)
	    logerror("    addition error 60+2 got %d\n", globalVariable6_1);
	if (globalVariable6_2 != 64-1)
	    logerror("    subtraction error 64-1 got %d\n", globalVariable6_2);
	if (globalVariable6_3 != 66/3)
	    logerror("    division error 66/3 got %d\n", globalVariable6_3);
	if (globalVariable6_4 != 67/3)
	    logerror("    division error 67/3 got %d\n", globalVariable6_4);
	if (globalVariable6_5 != 6 * 5)
	    logerror("    mult error 6*5 got %d\n", globalVariable6_5);
	if (globalVariable6_6 != 3)
	    logerror("    comma error 10,3 got %d\n", globalVariable6_6);
	if (globalVariable6_1a != 60+2)
	    logerror("    addition error 60+2 got %d\n", globalVariable6_1a);
	if (globalVariable6_2a != 64-1)
	    logerror("    subtraction error 64-1 got %d\n", globalVariable6_2a);
	if (globalVariable6_3a != 66/3)
	    logerror("    division error 66/3 got %d\n", globalVariable6_3a);
	if (globalVariable6_4a != 67/3)
	    logerror("    division error 67/3 got %d\n", globalVariable6_4a);
	if (globalVariable6_5a != 6 * 5)
	    logerror("    mult error 6*5 got %d\n", globalVariable6_5a);
	if (globalVariable6_6a != 3)
	    logerror("    comma error 10,3 got %d\n", globalVariable6_6a);
    }
}

void func6_2() { dprintf("func6_2 () called\n"); }

/*
 * Start Test Case #7 - relational operators
 *	Generate all relational operators (eq, gt, le, ne, ge, and, or)
 *	in both the true and false forms.
 */

void fail7Print(int tCase, int fCase, const char *op)
{
    if (tCase != 72)
	logerror(" operator %s was not true when it should be - const expr\n",
	    op);
    if (fCase != 71)
       logerror(" operator %s was not false when it should be - const expr\n",
	    op);
}

void fail7aPrint(int tCase, int fCase, const char *op)
{
    if (tCase != 74)
	logerror(" operator %s was not true when it should be - var expr\n", op);
    if (fCase != 73)
	logerror(" operator %s was not false when it should be - var expr\n",op);
}

void func7_1()
{
    void func7_2();

    func7_2();
    if ((globalVariable7_1 == 72) && (globalVariable7_2 == 71) &&
	(globalVariable7_3 == 72) && (globalVariable7_4 == 71) &&
	(globalVariable7_5 == 72) && (globalVariable7_6 == 71) &&
	(globalVariable7_7 == 72) && (globalVariable7_8 == 71) &&
	(globalVariable7_9 == 72) && (globalVariable7_10 == 71) &&
	(globalVariable7_11 == 72) && (globalVariable7_12 == 71) &&
	(globalVariable7_13 == 72) && (globalVariable7_14 == 71) &&
	(globalVariable7_15 == 72) && (globalVariable7_16 == 71) &&
        (globalVariable7_1a == 74) && (globalVariable7_2a == 73) &&
	(globalVariable7_3a == 74) && (globalVariable7_4a == 73) &&
	(globalVariable7_5a == 74) && (globalVariable7_6a == 73) &&
	(globalVariable7_7a == 74) && (globalVariable7_8a == 73) &&
	(globalVariable7_9a == 74) && (globalVariable7_10a == 73) &&
	(globalVariable7_11a == 74) && (globalVariable7_12a == 73) &&
	(globalVariable7_13a == 74) && (globalVariable7_14a == 73) &&
	(globalVariable7_15a == 74) && (globalVariable7_16a == 73)) {
	logerror("Passed test #7 (relational operators)\n");
	passedTest[7] = TRUE;
    } else {
	logerror("**Failed** test #7 (relational operators)\n");
	fail7Print(globalVariable7_1, globalVariable7_2, "BPatch_lt");
	fail7Print(globalVariable7_3, globalVariable7_4, "BPatch_eq");
	fail7Print(globalVariable7_5, globalVariable7_6, "BPatch_gt");
	fail7Print(globalVariable7_7, globalVariable7_8, "BPatch_le");
	fail7Print(globalVariable7_9, globalVariable7_10, "BPatch_ne");
	fail7Print(globalVariable7_11, globalVariable7_12, "BPatch_ge");
	fail7Print(globalVariable7_13, globalVariable7_14, "BPatch_and");
	fail7Print(globalVariable7_15, globalVariable7_16, "BPatch_or");

	fail7aPrint(globalVariable7_1a, globalVariable7_2a, "BPatch_lt");
	fail7aPrint(globalVariable7_3a, globalVariable7_4a, "BPatch_eq");
	fail7aPrint(globalVariable7_5a, globalVariable7_6a, "BPatch_gt");
	fail7aPrint(globalVariable7_7a, globalVariable7_8a, "BPatch_le");
	fail7aPrint(globalVariable7_9a, globalVariable7_10a, "BPatch_ne");
	fail7aPrint(globalVariable7_11a, globalVariable7_12a, "BPatch_ge");
	fail7aPrint(globalVariable7_13a, globalVariable7_14a, "BPatch_and");
	fail7aPrint(globalVariable7_15a, globalVariable7_16a, "BPatch_or");
    }
}

void func7_2() { dprintf("func7_2 () called\n"); }

/*
 * Test #8 - preserve registers - expr
 *	Verify the complex AST expressions do not clobber application
 *	paramter registers.
 */
void func8_1(int p1, int p2, int p3, int p4, int p5, int p6, int p7,
	     int p8, int p9, int p10)
{
    dprintf("func8_1 (...) called\n");
    if ((p1 == 1) && (p2 == 2) && (p3 == 3) && (p4 == 4) && (p5 == 5) &&
	(p6 == 6) && (p7 == 7) && (p8 == 8) && (p9 == 9) && (p10 == 10))  {
        logerror("Passed test #8 (preserve registers - expr)\n");
	passedTest[8] = TRUE;
    } else {
	logerror("**Failed** test #8 (preserve registers - expr )\n");
	if (p1 != 1)  logerror("    parameter #1 is %d not 1\n", p1);
	if (p2 != 2)  logerror("    parameter #2 is %d not 2\n", p2);
	if (p3 != 3)  logerror("    parameter #3 is %d not 3\n", p3);
	if (p4 != 4)  logerror("    parameter #4 is %d not 4\n", p4);
	if (p5 != 5)  logerror("    parameter #5 is %d not 5\n", p5);
	if (p6 != 6)  logerror("    parameter #6 is %d not 6\n", p6);
	if (p7 != 7)  logerror("    parameter #7 is %d not 7\n", p7);
	if (p8 != 8)  logerror("    parameter #8 is %d not 8\n", p8);
	if (p9 != 9)  logerror("    parameter #9 is %d not 9\n", p9);
	if (p10 != 10) logerror("    parameter #10 is %d not 10\n", p10);
    }
}

/*
 * Test #9 - reserve registers - funcCall
 *	Verify the a snippet that calls a function does not clobber the
 *	the parameter registers.
 */
void func9_1(int p1, int p2, int p3, int p4, int p5, int p6, int p7,
	     int p8, int p9, int p10)
{
    dprintf("func9_1 (...) called\n");
    if ((p1 == 1) && (p2 == 2) && (p3 == 3) && (p4 == 4) && (p5 == 5) &&
	(p6 == 6) && (p7 == 7) && (p8 == 8) && (p9 == 9) && (p10 == 10))  {
        logerror("Passed test #9 (preserve registers - funcCall)\n");
	passedTest[9] = TRUE;
    } else {
	logerror("**Failed** test #9 (preserve registers - funcCall )\n");
	if (p1 != 1)  logerror("    parameter #1 is %d not 1\n", p1);
	if (p2 != 2)  logerror("    parameter #2 is %d not 2\n", p2);
	if (p3 != 3)  logerror("    parameter #3 is %d not 3\n", p3);
	if (p4 != 4)  logerror("    parameter #4 is %d not 4\n", p4);
	if (p5 != 5)  logerror("    parameter #5 is %d not 5\n", p5);
	if (p6 != 6)  logerror("    parameter #6 is %d not 6\n", p6);
	if (p7 != 7)  logerror("    parameter #7 is %d not 7\n", p7);
	if (p8 != 8)  logerror("    parameter #8 is %d not 8\n", p8);
	if (p9 != 9)  logerror("    parameter #9 is %d not 9\n", p9);
	if (p10 != 10)  logerror("    parameter #10 is %d not 10\n", p10);
    }
}

/*
 * Test #10 - insert snippet order
 *	Verify that a snippet are inserted in the requested order.  We insert
 *	one snippet and then request two more to be inserted.  One before
 *	the first snippet and one after it.
 */
void func10_1()
{
    if ((globalVariable10_1 == 1) && (globalVariable10_2 == 1) &&
	(globalVariable10_3 == 1) && (globalVariable10_4 == 3)) {
	logerror("Passed test #10 (insert snippet order)\n");
	passedTest[10] = TRUE;
    } else {
	logerror("** Failed test #10 (insert snippet order)\n");
	if (!globalVariable10_1)
	    logerror("    call10_1 was not called first\n");
	if (!globalVariable10_2)
	    logerror("    call10_2 was not called second\n");
	if (!globalVariable10_3)
	    logerror("    call10_3 was not called third\n");
    }
}

/*
 * Test #11 - snippets at entry,exit,call
 */ 	
void func11_2() {
    globalVariable11_1 = 2;
}

void func11_1()
{
    globalVariable11_1 = 1;
    func11_2();
    globalVariable11_1 = 3;
}

/*
 * Test #12 - insert/remove and malloc/free
 */	
void func12_2()
{
    DUMMY_FN_BODY;
}

void func12_1()
{
    kludge = 1;	/* Here so that the following function call isn't the first
		   instruction */
    func12_2();
    stop_process_();
    func12_2();
    if (globalVariable12_1 == 1) {
        logerror("Passed test #12 (insert/remove and malloc/free)\n");
	passedTest[12] = TRUE;
    } else {
        logerror("**Failed test #12 (insert/remove and malloc/free)\n");
	logerror("ZANDY: #12 failed because globalVariable12_1 == %d\n", globalVariable12_1);
    }
}

/*
 * Test #13 - paramExpr,retExpr,nullExpr
 *	Test various expressions
 */
int func13_2()
{
    return(RET13_1);
}

void func13_1(int p1, int p2, int p3, int p4, int p5)
{
    func13_2();

    if ((p1 == 131) && (p2 == 132) && (p3 == 133) &&
	(p4 == 134) && (p5 == 135) && (globalVariable13_1 == 63)) {
	logerror("Passed test #13 (paramExpr,retExpr,nullExpr)\n");
	passedTest[13] = TRUE;
    } else {
	logerror("**Failed test #13 (paramExpr,retExpr,nullExpr)\n");
	if (p1 != 131) logerror("  parameter 1 is %d, not 131\n", p1);
	if (p2 != 132) logerror("  parameter 2 is %d, not 132\n", p2);
	if (p3 != 133) logerror("  parameter 3 is %d, not 133\n", p3);
	if (p4 != 134) logerror("  parameter 4 is %d, not 134\n", p4);
	if (p5 != 135) logerror("  parameter 5 is %d, not 135\n", p5);
	if (!(globalVariable13_1 & 1)) logerror("    passed param a1 wrong\n");
	if (!(globalVariable13_1 & 2)) logerror("    passed param a2 wrong\n");
	if (!(globalVariable13_1 & 4)) logerror("    passed param a3 wrong\n");
	if (!(globalVariable13_1 & 8)) logerror("    passed param a4 wrong\n");
	if (!(globalVariable13_1 & 16)) logerror("    passed param a5 wrong\n");
	if (!(globalVariable13_1 & 32)) logerror("    return value wrong\n");
    }
}

/*
 * Test #14 - replace function call
 */
void func14_2()
{
    globalVariable14_1 = 2;
}

void func14_3()
{
    globalVariable14_2 = 1;
}

void func14_1()
{
    kludge = 1;	/* Here so that the following function call isn't the first
		   instruction */

    func14_2();

    func14_3();

    if (globalVariable14_1 == 1 && globalVariable14_2 == 0) {
        logerror("Passed test #14 (replace/remove function call)\n");
	passedTest[14] = TRUE;
    } else {
        logerror("**Failed test #14 (replace/remove function call)\n");
	if (globalVariable14_1 != 1)
    	    logerror("    call to func14_2() was not replaced\n");
	if (globalVariable14_2 != 0)
	    logerror("    call to func14_3() was not removed\n");
    }
}

/*
 * Test #15 - setMutationsActive
 */
void check15result(const char *varname, int value, int expected,
                   const char *errstr, int *failed)
{
    if (value != expected) {
	if (!*failed)
	    logerror("**failed test #15 (setMutationsActive)\n");
	*failed = TRUE;

	logerror("    %s = %d %s\n", varname, value, errstr);
    }		
}


void func15_2()
{
    DUMMY_FN_BODY;
}

void func15_3()
{
    globalVariable15_3 = 100;
    /* increment a dummy variable to keep alpha code generator from assuming
       too many free registers on the call into func15_3. jkh 3/7/00 */
    globalVariable15_4++;
}

void func15_4()
{
    int localkludge = 1;
    kludge = localkludge;	/* Here so that the following function call isn't the first
		   instruction */

    func15_3();
}

void func15_1()
{
    int failed = FALSE;

    func15_2();
    check15result("globalVariable15_1", globalVariable15_1, 1,
		  "after first call to instrumented function", &failed);

#if 0
    // Deprecated pending rewrite of function relocation
#if defined(sparc_sun_sunos4_1_3) \
 || defined(sparc_sun_solaris2_4)
    /* Test a function that makes a system call (is a special case on Sparc) */
    access(".", R_OK);
    check15result("globalVariable15_2", globalVariable15_2, 2,
		  "after first call to instrumented function", &failed);
#endif
#endif

    func15_4();
    check15result("globalVariable15_3", globalVariable15_3, 1,
		  "after first call to instrumented function", &failed);

    /***********************************************************/

    stop_process_();

    func15_2();
    check15result("globalVariable15_1", globalVariable15_1, 1,
		  "after second call to instrumented function", &failed);
#if 0
#if defined(sparc_sun_sunos4_1_3) \
 || defined(sparc_sun_solaris2_4)
    access(".", R_OK);
    check15result("globalVariable15_2", globalVariable15_2, 2,
		  "after second call to instrumented function", &failed);
#endif
#endif

    func15_4();
    check15result("globalVariable15_3", globalVariable15_3, 100,
		  "after second call to instrumented function", &failed);

    /***********************************************************/

    stop_process_();

    func15_2();
    check15result("globalVariable15_1", globalVariable15_1, 2,
		  "after third call to instrumented function", &failed);
#if 0
#if defined(sparc_sun_sunos4_1_3) \
 || defined(sparc_sun_solaris2_4)
    access(".", R_OK);
    check15result("globalVariable15_2", globalVariable15_2, 4,
		  "after third call to instrumented function", &failed);
#endif
#endif
    func15_4();
    check15result("globalVariable15_3", globalVariable15_3, 101,
		  "after third call to instrumented function", &failed);

    if (!failed) {
        logerror("Passed test #15 (setMutationsActive)\n");
	passedTest[15] = TRUE;
    }
}

/*
 * Test #16 - if-else
 *	Test if-then-else clauses
 */
void func16_2() { dprintf("func16_2 () called\n"); }
void func16_3() { dprintf("func16_3 () called\n"); }
void func16_4() { dprintf("func16_4 () called\n"); }

void func16_1()
{
    int failed = FALSE;

    func16_2();
    if (globalVariable16_1 != 1 || globalVariable16_2 != 0) {
        logerror("**Failed test #16 (if-else)\n");
	if (globalVariable16_1 != 1)
	    logerror("    True clause of first if should have been executed but was not.\n");
	if (globalVariable16_2 != 0)
	    logerror("    False clause of first if should not have been executed but was.\n");
	failed = 1;
    }

    func16_3();
    if (globalVariable16_3 != 0 || globalVariable16_4 != 1) {
        logerror("**Failed test #16 (if-else)\n");
	if (globalVariable16_3 != 1)
	    logerror("    True clause of second if should not have been executed but was.\n");
	if (globalVariable16_4 != 0)
	    logerror("    False clause of second if should have been executed but was not.\n");
	failed = 1;
    }

    func16_4();
    if ((globalVariable16_5 != 0 || globalVariable16_6 != 1) ||
        (globalVariable16_7 != 0 || globalVariable16_8 != 1) ||
        (globalVariable16_9 != 0 || globalVariable16_10 != 1)) {
	    logerror("    failed large if clauses tests.\n");
	failed = 1;
    }

    if (!failed)
    	logerror("Passed test #16 (if-else)\n");
	passedTest[16] = TRUE;
}

/*
 * Test #17 - return values from func calls
 *	See test1.C for a detailed comment
 */
void func17_1()
{
    int ret17_1;
    int func17_2();
    void func17_3();

    kludge = 1;	/* Here so that the following function call isn't the first
    		   instruction */

    ret17_1 = func17_2();
    func17_3();

    if ((ret17_1 != RET17_1) ||
	(globalVariable17_1 != RET17_2) ||
	(globalVariable17_2 != RAN17_1)) {
        logerror("**Failed** test case #17 (return values from func calls)\n");
        if (ret17_1 != RET17_1) {
            logerror("  return value was %d, not %d\n", ret17_1, RET17_1);
        }
        if (globalVariable17_1 != RET17_2) {
            logerror("  return value was %d, not %d\n",
                globalVariable17_1, RET17_2);
        }
        if (globalVariable17_2 != RAN17_1) {
            logerror("  function call17_2 was not inserted\n");
        }
    } else {
        logerror("Passed test #17 (return values from func calls)\n");
	passedTest[17] = TRUE;
    }
}

int func17_2()
{
    return RET17_1;
}

int func17_4()
{
    return RET17_2;
}

void func17_3()
{
    globalVariable17_1 = func17_4();
    return;
}

/*
 * Test #18 - read/write a variable in the mutatee
 */
void func18_1()
{
    if (globalVariable18_1 == 17) {
    	logerror("Passed test #18 (read/write a variable in the mutatee)\n");
	passedTest[18] = TRUE;
    } else {
	logerror("**Failed test #18 (read/write a variable in the mutatee)\n");
	if (globalVariable18_1 == 42)
	    logerror("    globalVariable18_1 still contains 42 (probably it was not written to)\n");
	else
	    logerror("    globalVariable18_1 contained %d, not 17 as expected\n",
		    globalVariable18_1);
    }
}

/*
 * Test #19 - oneTimeCode
 */
void func19_1()
{
    stop_process_();

    if (globalVariable19_1 != MAGIC19_1) {
	logerror("**Failed test #19 (oneTimeCode)\n");
	logerror("    globalVariable19_1 contained %d, not %d as expected\n",
		globalVariable19_1, MAGIC19_1);
    }

    stop_process_();

    if (globalVariable19_2 == MAGIC19_2) {
	logerror("Passed test #19 (oneTimeCode)\n");
	passedTest[19] = TRUE;
    } else {
	logerror("**Failed test #19 (oneTimeCode)\n");
	logerror("    globalVariable19_2 contained %d, not %d as expected\n",
		globalVariable19_2, MAGIC19_2);
    }
}

/*
 * Test #20 - instrumentation at arbitrary points
 */
int func20_3()
{
    static int n = 1;

    return n++;
}

volatile int tc = TEST20_C;
volatile double td = TEST20_D;
int test20_iter = 50;

int func20_2(int *int_val, double *double_val)
{
    int i, ret = 1;
    *int_val = tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+
	       (tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+
	       (tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+
	       (tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc+(tc
	       ))))))))))))))))))))))))))))))))))))))));

    *double_val = td+(td+(td+(td+(td+(td+(td+(td+(td+(td+
		  (td+(td+(td+(td+(td+(td+(td+(td+(td+(td+
		  (td+(td+(td+(td+(td+(td+(td+(td+(td+(td+
		  (td+(td+(td+(td+(td+(td+(td+(td+(td+(td+(td
		  ))))))))))))))))))))))))))))))))))))))));
    for (i = 0; i < test20_iter; i++) {
	ret *= 3;
	if (i % 2 == 1) {
	    ret *= 5;
	} else if (i < 10) {
	    ret *= 7;
	} else if (i > 20) {
	    ret *= 11;
	}
    }

/* The answer we expect from the above is: */
#define TEST20_ANSWER 1088896211
    return ret;
}

void func20_1()
{
    int ret;
    int int_val;
    double double_val;
    ret = func20_2(&int_val, &double_val);
    if (globalVariable20_1 == (TEST20_A * TEST20_TIMES) &&
	eq_doubles(globalVariable20_2, (TEST20_B * (double)TEST20_TIMES)) &&
	int_val == (TEST20_C * TEST20_TIMES) &&
	eq_doubles(double_val, (TEST20_D * (double)TEST20_TIMES)) &&
	ret == TEST20_ANSWER) {
	logerror("Passed test #20 (instrument arbitrary points)\n");
	passedTest[20] = TRUE;
    } else {
	logerror("**Failed test #20 (instrument arbitrary points)\n");
	if (globalVariable20_1 != (TEST20_A * TEST20_TIMES))
    	    logerror("    globalVariable20_1 contained %d, not %d as expected\n",
		   globalVariable20_1, TEST20_A * TEST20_TIMES);
	if (!eq_doubles(globalVariable20_2, (TEST20_B * (double)TEST20_TIMES)))
    	    logerror("    globalVariable20_2 contained %g, not %g as expected\n",
		   globalVariable20_2, TEST20_B * (double)TEST20_TIMES);
	if (int_val != (TEST20_C * TEST20_TIMES))
    	    logerror("    int_val contained %d, not %d as expected\n",
		   int_val, TEST20_C * TEST20_TIMES);
	if (!eq_doubles(double_val, (TEST20_D * (double)TEST20_TIMES)))
    	    logerror("    double_val contained %g, not %g as expected\n",
		   double_val, TEST20_D * (double)TEST20_TIMES);
	if (ret != TEST20_ANSWER)
    	    logerror("    ret contained %d, not %d as expected\n",
		   ret, TEST20_ANSWER);
    }

}

/*
 * Test #21 - findFunction in module
 */
void func21_1()
{
     /* Nothing for the mutatee to do in this test (findFunction in module) */
#if defined(os_aix) \
 || defined(os_osf) \
 || defined(os_solaris) \
 || defined(os_linux) \
 || defined(os_windows)
     logerror("Passed test #21 (findFunction in module)\n");
     passedTest[21] = TRUE;
#else
    logerror("Skipped test #21 (findFunction in module)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[21] = TRUE;
#endif
}

/*
 * Test #22 - replace function
 *
 * These are defined in libtestA.so
 */
extern void call22_5A(int);
extern void call22_6(int);

volatile int _unused;	/* move decl here to dump compiler warning - jkh */

typedef int (*call_type)(int);

void func22_1()
{
#if defined(os_solaris) \
 || defined(alpha_dec_osf4_0) \
 || defined(os_linux) \
 || defined(os_windows)
    /* libtestA.so should already be loaded (by the mutator), but we
       need to use the dl interface to get pointers to the functions
       it defines. */
    int (*call22_5)(int);
    int (*call22_6)(int);

    void *handleA;
    char dlopenName[128];
    int result;
    _unused = sprintf(dlopenName, "./%s", libNameA);

    handleA = loadDynamicLibrary(dlopenName);
    if (! handleA) {
	 logerror("**Failed test #22 (replaceFunction)\n");
	 logerror("  Mutatee couldn't get handle for %s\n", libNameA);
    }
    call22_5 = (int(*)(int)) getFuncFromDLL(handleA, "call22_5");
    if (! call22_5) {
	 logerror("**Failed test #22 (replaceFunction)\n");
	 logerror("  Mutatee couldn't get handle for call22_5 in %s\n", libNameA);
    }
    call22_6 = (int(*)(int)) getFuncFromDLL(handleA, "call22_6");
    if (! call22_6) {
	 logerror("**Failed test #22 (replaceFunction)\n");
	 logerror("  Mutatee couldn't get handle for call22_6 in %s\n", libNameA);
    }

    /* Call functions that have been replaced by the mutator.  The
       side effects of these calls (replaced, not replaced, or
       otherwise) are independent of each other. */
    result = call22_1(10);  /* replaced by call22_2 */
    if (result != 10 + MAGIC22_2) {
	 logerror("**Failed test #22 (replace function) (a.out -> a.out)\n");
	 return;
    }
    result = call22_3(20);  /* replaced by call22_4 */
    if (result != 20 + MAGIC22_4) {
	 logerror("**Failed test #22 (replace function) (a.out -> shlib)\n");
	 return;
    }
    result = call22_5(30);  /* replaced by call22_5 (in libtestB) */
    if (result != 30 + MAGIC22_5B) {
	 logerror("**Failed test #22 (replace function) (shlib -> shlib)\n");
	 return;
    }
    result = call22_6(40);  /* replaced by call22_7 */
    if (result != 40 + MAGIC22_7) {
	 logerror("**Failed test #22 (replace function) (shlib -> a.out)\n");
	 return;
    }
    logerror("Passed test #22 (replace function)\n");
    passedTest[22] = TRUE;
#else
    logerror("Skipped test #22 (replace function)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[22] = TRUE;
#endif
}

/*
 * Test #23 - local variables
 */
int shadowVariable23_1 = 2300010;
int shadowVariable23_2 = 2300020;
int globalShadowVariable23_1 = (int)0xdeadbeef;
int globalShadowVariable23_2 = (int)0xdeadbeef;
int globalVariable23_1 = 2300000;

void verifyScalarValue23(const char *name, int a, int value)
{
    verifyScalarValue(name, a, value, 23, "local variables");
}

void call23_2()
{
    /* copy shadowed global variables to visible global variables to permit
     *    checking their values
     */
    globalShadowVariable23_1 = shadowVariable23_1;
    globalShadowVariable23_2 = shadowVariable23_2;
}

void call23_1()
{
    int localVariable23_1 = 2300019;
    int shadowVariable23_1 = 2300011;
    int shadowVariable23_2 = 2300021;

    call23_2();			/* place to manipulate local variables */

    passedTest[23] = TRUE;

    /* snippet didn't update local variable */
    verifyScalarValue23("localVariable23_1", localVariable23_1, 2300001);

    /* did snippet update shadow variable (in the global scope) */
    verifyScalarValue23("globalShadowVariable23_1", globalShadowVariable23_1,
	2300010);

    /* did snippet correctly update shadow variable call23_2 */
    verifyScalarValue23("shadowVariable23_1", shadowVariable23_1, 2300012);

    /* did snippet correctly update shadow variable via global
       scope in call23_2 */
    verifyScalarValue23("shadowVariable23_2", shadowVariable23_2, 2300021);

    /* did snippet correctly update shadow variable via global
       scope in call23_2 */
    verifyScalarValue23("globalShadowVariable23_2", globalShadowVariable23_2,
	2300023);

    /* did snippet correctly read local variable in call23_2 */
    verifyScalarValue23("globalVariable23_1", globalVariable23_1, 2300001);
    dprintf("Leaving call23_1...\n");
}

void func23_1()
{
#if defined(mips_sgi_irix6_4)
    logerror("Skipped test #23 (local variables)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[23] = TRUE;
#else
    call23_1();

    if (passedTest[23]) logerror("Passed test #23 (local variables)\n");
#endif
}

/*
 * Test #24 - arrary variables
 */
int dummy;
int foo;

int globalVariable24_1[100];
int globalVariable24_2 = 53;
int globalVariable24_3;
int globalVariable24_4 = 83;
int globalVariable24_5;

/* to hold values from local array */
int globalVariable24_6;
int globalVariable24_7;

/* for 2-d arrays - array is not square and we avoid using diagonal elements
 *    to make sure we test address computation
 */
int globalVariable24_8[10][15];
int globalVariable24_9;

void verifyValue24(const char *name, int *a, int index, int value)
{
    verifyValue(name, a, index, value, 24, "array variables");
}

void verifyScalarValue24(const char *name, int a, int value)
{
    verifyScalarValue(name, a, value, 24, "array variables");
}

void call24_2()
{
}

void call24_1()
{
#ifdef sparc_sun_solaris2_4
    unsigned i=0; /* hack to prevent g++'s optimizer making func uninstr'uble */
#else
    unsigned i;
#endif
    int localVariable24_1[100];

    for (i=0; i < 100; i++) localVariable24_1[i] = 2400000;

    localVariable24_1[79] = 2400007;
    localVariable24_1[83] = 2400008;

    call24_2();

    verifyValue24("localVariable24_1", localVariable24_1, 1, 2400005);
    verifyValue24("localVariable24_1", localVariable24_1, 53, 2400006);
}

void func24_1()
{
#if !defined(sparc_sun_solaris2_4) \
 && !defined(rs6000_ibm_aix4_1) \
 && !defined(alpha_dec_osf4_0) \
 && !defined(i386_unknown_linux2_0) \
 && !defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 && !defined(i386_unknown_solaris2_5) \
 && !defined(i386_unknown_nt4_0) \
 && !defined(ia64_unknown_linux2_4)

    logerror("Skipped test #24 (array variables)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[24] = TRUE;
#else
    int i, j;

    passedTest[24] = TRUE;


    for (i=0; i < 100; i++) globalVariable24_1[i] = 2400000;
    globalVariable24_1[79] = 2400003;
    globalVariable24_1[83] = 2400004;

    for (i=0; i < 10; i++) {
	for (j=0; j < 15; j++) {
	    globalVariable24_8[i][j] = 2400010;
	}
    }
    globalVariable24_8[7][9] = 2400012;

    /* inst code we put into this function:
     *  At Call:
     *     globalVariable24_1[1] = 2400001
     *     globalVariable24_1[globalVariable24_2] = 2400002
     *	   globalVariable24_3 = globalVariable24_1[79]
     *	   globalVariable24_5 = globalVariable24_1[globalVariable24_4]
     *     localVariable24_1[1] = 2400001
     *     localVariable24_1[globalVariable24_2] = 2400002
     *	   globalVariable24_8[2][3] = 2400011
     *	   globalVariable24_6 = localVariable24_1[79]
     *	   globalVariable24_7 = localVariable24_1[globalVariable24_4]
     */
    call24_1();

    for (i=0; i < 100; i++) {
	if (i == 1) {
	    /* 1st element should be modified by the snippet (constant index) */
	    verifyValue24("globalVariable24_1", globalVariable24_1, 1, 2400001);
	} else if (i == 53) {
	    /* 53rd element should be modified by the snippet (variable index) */
	    verifyValue24("globalVariable24_1", globalVariable24_1, 53, 2400002);
	} else if (i == 79) {
	    /* 79th element was modified by us  */
	    verifyValue24("globalVariable24_1", globalVariable24_1, 79, 2400003);
	} else if (i == 83) {
	    /* 83rd element was modified by us  */
	    verifyValue24("globalVariable24_1", globalVariable24_1, 83, 2400004);
	} else if (globalVariable24_1[i] != 2400000) {
	    /* rest should still be the original value */
	    verifyValue24("globalVariable24_1", globalVariable24_1, i, 2400000);
	}
    }

    verifyScalarValue24("globalVariable24_3", globalVariable24_3, 2400003);
    verifyScalarValue24("globalVariable24_5", globalVariable24_5, 2400004);

    /* now for the two elements read from the local variable */
    verifyScalarValue24("globalVariable24_6", globalVariable24_6, 2400007);
    verifyScalarValue24("globalVariable24_7", globalVariable24_7, 2400008);

    /* verify 2-d element use */
    verifyScalarValue24("globalVariable24_8[2][3]", globalVariable24_8[2][3],
	 2400011);
    verifyScalarValue24("globalVariable24_9", globalVariable24_9, 2400012);

    if (passedTest[24]) logerror("Passed test #24 (array variables)\n");
#endif
}

/*
 * Test #25 - unary operators
 */
int globalVariable25_1;
int *globalVariable25_2;	/* used to hold addres of globalVariable25_1 */
int globalVariable25_3;
int globalVariable25_4;
int globalVariable25_5;
int globalVariable25_6;
int globalVariable25_7;

void call25_1()
{
  DUMMY_FN_BODY;
}

void func25_1()
{
#if defined(mips_sgi_irix6_4)
    logerror("Skipped test #25 (unary operators)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[25] = TRUE;
#else

    passedTest[25] = TRUE;

    globalVariable25_1 = 25000001;
    globalVariable25_2 = (int *) 25000002;
    globalVariable25_3 = 25000003;
    globalVariable25_4 = 25000004;
    globalVariable25_5 = 25000005;
    globalVariable25_6 = -25000006;
    globalVariable25_7 = 25000007;

    /* inst code we put into this function:
     *  At Entry:
     *     globalVariable25_2 = &globalVariable25_1
     *     globalVariable25_3 = *globalVariable25_2
     *     globalVariable25_5 = -globalVariable25_4
     *     globalVariable25_7 = -globalVariable25_6
     */

    call25_1();

    if ((int *) globalVariable25_2 != &globalVariable25_1) {
	if (passedTest[25]) logerror("**Failed** test #25 (unary operators)\n");
	passedTest[25] = FALSE;
	logerror("    globalVariable25_2 = %p, not %p\n",
	    globalVariable25_2, (void *) &globalVariable25_1);
    }

    if (globalVariable25_3 != globalVariable25_1) {
	if (passedTest[25]) logerror("**Failed** test #25 (unary operators)\n");
	passedTest[25] = FALSE;
	logerror("    globalVariable25_3 = %d, not %d\n",
	    globalVariable25_3, globalVariable25_1);
    }

    if (globalVariable25_5 != -globalVariable25_4) {
	if (passedTest[25]) logerror("**Failed** test #25 (unary operators)\n");
	passedTest[25] = FALSE;
	logerror("    globalVariable25_5 = %d, not %d\n",
	    globalVariable25_5, -globalVariable25_4);
    }

    if (globalVariable25_7 != -globalVariable25_6) {
	if (passedTest[25]) logerror("**Failed** test #25 (unary operators)\n");
	passedTest[25] = FALSE;
	logerror("    globalVariable25_7 = %d, not %d\n",
	    globalVariable25_7, -globalVariable25_6);
    }

    if (passedTest[25]) logerror("Passed test #25 (unary operators)\n");
#endif
}

/*
 * Test #26 - field operators
 */
/*  struct26_2 globalVariable26_1;  */
struct struct26_2 globalVariable26_1;
int globalVariable26_2 = 26000000;
int globalVariable26_3 = 26000000;
int globalVariable26_4 = 26000000;
int globalVariable26_5 = 26000000;
int globalVariable26_6 = 26000000;
int globalVariable26_7 = 26000000;

int globalVariable26_8 = 26000000;
int globalVariable26_9 = 26000000;
int globalVariable26_10 = 26000000;
int globalVariable26_11 = 26000000;
int globalVariable26_12 = 26000000;
int globalVariable26_13 = 26000000;

void verifyScalarValue26(const char *name, int a, int value)
{
    verifyScalarValue(name, a, value, 26, "field operators");
}

void call26_2()
{
}

void call26_1()
{
    int i;
    /*    struct26_2 localVariable26_1;  */
    struct struct26_2 localVariable26_1;

    localVariable26_1.field1 = 26002001;
    localVariable26_1.field2 = 26002002;
    for (i=0; i < 10; i++) localVariable26_1.field3[i] = 26002003 + i;
    localVariable26_1.field4.field1 = 26002013;
    localVariable26_1.field4.field2 = 26002014;

    /* check local variables at this point (since we known locals are still
       on the stack here. */
    call26_2();

}

void func26_1()
{
#if !defined(sparc_sun_solaris2_4) \
 && !defined(alpha_dec_osf4_0) \
 && !defined(rs6000_ibm_aix4_1) \
 && !defined(i386_unknown_linux2_0) \
 && !defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 && !defined(i386_unknown_solaris2_5) \
 && !defined(i386_unknown_nt4_0) \
 && !defined(ia64_unknown_linux2_4)

    logerror("Skipped test #26 (struct elements)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[26] = TRUE;
#else
    int i;

    passedTest[26] = TRUE;

    globalVariable26_1.field1 = 26001001;
    globalVariable26_1.field2 = 26001002;
    for (i=0; i < 10; i++) globalVariable26_1.field3[i] = 26001003 + i;
    globalVariable26_1.field4.field1 = 26000013;
    globalVariable26_1.field4.field2 = 26000014;

    call26_1();

    verifyScalarValue26("globalVariable26_2", globalVariable26_2, 26001001);
    verifyScalarValue26("globalVariable26_3", globalVariable26_3, 26001002);
    verifyScalarValue26("globalVariable26_4", globalVariable26_4, 26001003);
    verifyScalarValue26("globalVariable26_5", globalVariable26_5, 26001003+5);
    verifyScalarValue26("globalVariable26_6", globalVariable26_6, 26000013);
    verifyScalarValue26("globalVariable26_7", globalVariable26_7, 26000014);

    /* local variables */
    verifyScalarValue26("globalVariable26_8", globalVariable26_8, 26002001);
    verifyScalarValue26("globalVariable26_9", globalVariable26_9, 26002002);
    verifyScalarValue26("globalVariable26_10", globalVariable26_10, 26002003);
    verifyScalarValue26("globalVariable26_11", globalVariable26_11, 26002003+5);
    verifyScalarValue26("globalVariable26_12", globalVariable26_12, 26002013);
    verifyScalarValue26("globalVariable26_13", globalVariable26_13, 26002014);

    if (passedTest[26]) logerror("Passed test #26 (field operators)\n");
#endif
}

/*
 * Test #27 - type compatibility
 */
typedef struct {
    /* void *field27_11; */
    int field27_11;
    float field27_12;
} type27_1;

typedef struct {
    /* void *field27_21; */
    int field27_21;
    float field27_22;
} type27_2;

typedef struct {
    int field3[10];
    struct struct26_2 field4;
} type27_3;

typedef struct {
    int field3[10];
    struct struct26_2 field4;
} type27_4;

int globalVariable27_1;
/* Note for future reference: -Wl,-bgcbypass:3 is NECESSARY for
   compilation (gcc) on AIX. Damn efficient linkers. */
int globalVariable27_5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int globalVariable27_6[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
float globalVariable27_7[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0,
				6.0, 7.0, 8.0, 9.0};
float globalVariable27_8[12];

/* need this variables or some compilers (AIX xlc) will removed unused
   typedefs - jkh 10/13/99 */
type27_1 dummy1;
type27_2 dummy2;
type27_3 dummy3;
type27_4 dummy4;

void func27_1()
{
#if !defined(sparc_sun_solaris2_4) \
 && !defined(rs6000_ibm_aix4_1) \
 && !defined(alpha_dec_osf4_0) \
 && !defined(i386_unknown_linux2_0) \
 && !defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 && !defined(i386_unknown_solaris2_5) \
 && !defined(i386_unknown_nt4_0) \
 && !defined(ia64_unknown_linux2_4)

    logerror("Skipped test #27 (type compatibility)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[27] = TRUE;
#else
    passedTest[27] = (globalVariable27_1 == 1);

    if (passedTest[27]) logerror("Passed test #27 (type compatibility)\n");
#endif
}

/*
 * Test #28 - field operators
 */
struct struct28_1 {
    int field1;
    int field2;
};

struct struct28_2 {
    int field1;
    int field2;
    int field3[10];
    struct struct28_1 field4;
};

char globalVariable28_1[sizeof(struct struct28_2)];
struct struct28_2 *temp;
int globalVariable28_2 = 28000000;
int globalVariable28_3 = 28000000;
int globalVariable28_4 = 28000000;
int globalVariable28_5 = 28000000;
int globalVariable28_6 = 28000000;
int globalVariable28_7 = 28000000;
int globalVariable28_8 = 28000000;	

void verifyScalarValue28(const char *name, int a, int value)
{
    verifyScalarValue(name, a, value, 28, "user defined fields");
}

void call28_1()
{
    int i = 42;

    int j = i;

    for (j=0; j < 400; j++);
}

void func28_1()
{
    int i;

    passedTest[28] = TRUE;


    temp = (struct struct28_2 *) globalVariable28_1;

    temp->field1 = 28001001;
    temp->field2 = 28001002;
    for (i=0; i < 10; i++) temp->field3[i] = 28001003 + i;
    temp->field4.field1 = 28000013;
    temp->field4.field2 = 28000014;

    call28_1();

    verifyScalarValue28("globalVariable28_2", globalVariable28_2, 28001001);
    verifyScalarValue28("globalVariable28_3", globalVariable28_3, 28001002);
    verifyScalarValue28("globalVariable28_4", globalVariable28_4, 28001003);
    verifyScalarValue28("globalVariable28_5", globalVariable28_5, 28001003+5);
    verifyScalarValue28("globalVariable28_6", globalVariable28_6, 28000013);
    verifyScalarValue28("globalVariable28_7", globalVariable28_7, 28000014);

    if (passedTest[28]) logerror("Passed test #28 (user defined fields)\n");
}

int globalVariable29_1;

int func29_1()
{
    passedTest[29] = (globalVariable29_1 == 1);

    if (passedTest[29]) logerror("Passed test #29 (BPatch_srcObj class)\n");

    return 0;
}

void func30_2()
{
    DUMMY_FN_BODY;
}

/* variables to keep the base addr and last addr of call30_1 */
unsigned long globalVariable30_8 = 0;
unsigned long globalVariable30_9 = 0;
int func30_1()
{
    kludge = 1;	/* Here so that the following function call isn't the first
		   instruction */

#if defined(sparc_sun_solaris2_4) \
 || defined(i386_unknown_solaris2_5) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(ia64_unknown_linux2_4) \
 || defined(i386_unknown_nt4_0) \
 || defined(rs6000_ibm_aix4_1) \
 || defined(alpha_dec_osf4_0)
    
    func30_2();

    passedTest[30] = !globalVariable30_3 ||
#if defined(rs6000_ibm_aix4_1)
		     ((globalVariable30_8 <= globalVariable30_3) &&
#else
		     ((globalVariable30_2 <= globalVariable30_3) &&
#endif
		      (globalVariable30_3 <= globalVariable30_9));

    if (!passedTest[30]){
    	logerror("**Failed** test #30 (line information) in %s[%d]\n", __FILE__, __LINE__ );
	return 0;
    }

    passedTest[30] = !globalVariable30_4 ||
#if defined(rs6000_ibm_aix4_1)
		     ((globalVariable30_8 <= globalVariable30_4) &&
#else
		     ((globalVariable30_2 <= globalVariable30_4) &&
#endif
		      (globalVariable30_4 <= globalVariable30_9));

    if (!passedTest[30]){
    	logerror("**Failed** test #30 (line information) in %s[%d]\n", __FILE__, __LINE__ );
	return 0;
    }

    passedTest[30] = !globalVariable30_5 ||
#if defined(rs6000_ibm_aix4_1)
		     ((globalVariable30_8 <= globalVariable30_5) &&
#else
		     ((globalVariable30_2 <= globalVariable30_5) &&
#endif
		      (globalVariable30_5 <= globalVariable30_9));

		      if (!passedTest[30]){
			logerror("**Failed** test #30 (line information) in %s[%d]\n", __FILE__, __LINE__ );
			logerror("gv30_5 = %lu, gv30_2 = %lu, gv30_9 = %lu\n", globalVariable30_5,
			       globalVariable30_2, globalVariable30_9);
			return 0;
		      }

    passedTest[30] = !globalVariable30_6 ||
		     (globalVariable30_1 == globalVariable30_6);
    if (!passedTest[30]){
    	logerror("**Failed** test #30 (line information) in %s[%d]\n", __FILE__, __LINE__ );
	logerror("gv30_6 = %lu, gv30_1 = %lu, should be equal and nonzero!\n", globalVariable30_6,
	       globalVariable30_1);
	return 0;
    }

    logerror("Passed test #30 (line information)\n");

#else
    logerror("Skipped test #30 (line information)\n");
    logerror("\t- not implemented on this platform\n");
    passedTest[30] = TRUE;
#endif
    return 1;
}

void func31_2()
{
  globalVariable31_2 = 1;
}

void func31_3()
{
  globalVariable31_3 = 1;
}

void func31_4( int value )
{
  if( value == 0 )
    {
      logerror( "func_31_4 called with value = 0 !\n" );
    }
  globalVariable31_4 += value;
}

int func31_1()
{
#if defined(alpha_dec_osf4_0)
    logerror( "Skipped test #31 (non-recursive base tramp guard)\n" );
    logerror( "\t- not implemented on this platform\n" );
    passedTest[ 31 ] = TRUE;

    return 1;
#else
  globalVariable31_1 = 0;
  globalVariable31_2 = 0;
  globalVariable31_3 = 0;
  globalVariable31_4 = 0;
  func31_2();
  passedTest[ 31 ] = ( globalVariable31_3 == 1 );
  if( ! passedTest[ 31 ] )
    {
      logerror( "**Failed** test #31 (non-recursive base tramp guard)\n" );
      logerror( "    globalVariable31_3 = %d, should be 1 (no instrumentation got executed?).\n",
	      globalVariable31_3 );
      return 0;
    }

  passedTest[ 31 ] = ( globalVariable31_4 == 0 );
  if( ! passedTest[ 31 ] )
    {
      logerror( "**Failed** test #31 (non-recursive base tramp guard)\n" );
      logerror( "    globalVariable31_4 = %d, should be 0.\n",
	      globalVariable31_4 );
      switch( globalVariable31_4 )
	{
	case 0: logerror( "    Recursive guard works fine.\n" ); break;
	case 1: logerror( "    Pre-instr recursive guard does not work.\n" ); break;
	case 2: logerror( "    Post-instr recursive guard does not work.\n" ); break;
	case 3: logerror( "    None of the recursive guards work.\n" ); break;
	default: logerror( "    Something is really wrong.\n" ); break;
	}
      return 0;
    }

  passedTest[ 31 ] = TRUE;
  logerror( "Passed test #31 (non-recursive base tramp guard)\n" );

  return 1;
#endif
}

void func32_2()
{
  globalVariable32_2 = 1;
}

void func32_3()
{
  globalVariable32_3 = 1;
}

void func32_4( int value )
{
  if( value == 0 )
    {
      logerror( "func_32_4 called with value = 0 !\n" );
    }

  globalVariable32_4 += value;
}

int func32_1()
{
  globalVariable32_1 = 0;
  globalVariable32_2 = 0;
  globalVariable32_3 = 0;
  globalVariable32_4 = 0;

  func32_2();

  passedTest[ 32 ] = ( globalVariable32_3 == 1 );
  if( ! passedTest[ 32 ] )
    {
      logerror( "**Failed** test #32 (non-recursive base tramp guard)\n" );
      logerror( "    globalVariable32_3 = %d, should be 1 (no instrumentation got executed?).\n",
	      globalVariable32_3 );
      return 0;
    }

  passedTest[ 32 ] = ( globalVariable32_4 == 3 );
  if( ! passedTest[ 32 ] )
    {
      logerror( "**Failed** test #32 (non-recursive base tramp guard)\n" );
      logerror( "    globalVariable32_4 = %d, should be 3.\n",
	      globalVariable32_4 );
      switch( globalVariable32_4 )
	{
	case 0: logerror( "    Recursive guard works fine.\n" ); break;
	case 1: logerror( "    Pre-instr recursive guard does not work.\n" ); break;
	case 2: logerror( "    Post-instr recursive guard does not work.\n" ); break;
	case 3: logerror( "    None of the recursive guards work.\n" ); break;
	default: logerror( "    Something is really wrong.\n" ); break;
	}
      return 0;
    }

  passedTest[ 32 ] = TRUE;
  logerror( "Passed test #32 (recursive base tramp guard)\n" );

  return 1;
}

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
int global33_2 = 0;
void func33_2(int x)
{
    /* dprintf("Hello\n"); */

    if (x == 1) {
        /* dprintf("Goodbye.\n"); */
	global33_2 = 1;
    } else {
        /* dprintf("See you.\n"); */
	global33_2 = 2;
    }

    /* dprintf("That's all.\n"); */
}

int func33_3(int x)
{
    /* dprintf("Entry.\n"); */

    /* The Intel compiler for IA-64 requires at least 18 entries to
       trigger the generation of a jump table. */
    switch (x) {
      case 0:
	/* dprintf("0\n"); */
	x += 11;
	break;
      case 1:
	/* dprintf("1\n"); */
	x += 10;
	break;
      case 2:
	/* dprintf("2\n"); */
	x-= 12;
	break;
      case 3:
	/* dprintf("3\n"); */
	x *= 33;
	break;
      case 4:
	/* dprintf("4\n"); */
	x /= 42;
	break;
      case 5:
	/* dprintf("5\n"); */
	x %= 57;
	break;
      case 6:
	/* dprintf("6\n"); */
	x <<= 2;
	break;
      case 7:
	/* dprintf("7\n"); */
	x >>= 3;
	break;
      case 8:
	/* dprintf("8\n"); */
	x ^= 0xfe;
	break;
      case 9:
	/* dprintf("9\n"); */
	x &= 0x44;
	break;
      case 10:
	/* dprintf("10\n"); */
	x |= 0x11;
	break;
      case 11:
	/* dprintf("11\n"); */
	x += 110;
	break;
      case 12:
	/* dprintf("12\n"); */
	x-= 112;
	break;
      case 13:
	/* dprintf("13\n"); */
	x *= 133;
	break;
      case 14:
	/* dprintf("14\n"); */
	x /= 142;
	break;
      case 15:
	/* dprintf("15\n"); */
	x %= 157;
	break;
      case 16:
	/* dprintf("16\n"); */
	x <<= 12;
	break;
      case 17:
	/* dprintf("17\n"); */
	x >>= 13;
	break;
      case 18:
	/* dprintf("18\n"); */
	x ^= 0x1fe;
	break;
      case 19:
	/* dprintf("19\n"); */
	x &= 0x144;
	break;
    };

    /* dprintf("Exit.\n"); */

    return x;
}

void func33_1()
{
#if defined(os_osf)
    passedTest [ 33 ] = TRUE;
    logerror( "Skipped test #33 (control flow graphs)\n" );
    logerror( "\t- known to be a problem on this platform-- hah!\n" );
#else
    /* The only possible failures occur in the mutator. */

    passedTest[ 33 ] = globalVariable33_1;
    if ( passedTest[33] ) {
       logerror( "Passed test #33 (control flow graphs)\n" );
    } else {
       logerror( "Failed test #33 (control flow graphs)\n" );
    }
#endif
}

/*
 * Nested loops.
 */
void func34_2()
{
    int i, j, k;

    /* There are four loops in total. */
    for (i = 0; i < 10; i++) { /* Contains two loops. */
	dprintf("i = %d\n", i);

	for (j = 0; j < 10; j++) { /* Contains one loop. */
	    dprintf("j = %d\n", j);

	    k = 0;
	    while (k < 10) {
		dprintf("k = %d\n", k);
		k++;
	    }
	}

	do {
	    j++;
	    dprintf("j = %d\n", j);

	} while (j < 10);
    }
}

void func34_1()
{
    /* The only possible failures occur in the mutator. */

    passedTest[ 34 ] = TRUE;
    logerror( "Passed test #34 (loop information)\n" );
}

#if defined(i386_unknown_solaris2_5) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(sparc_sun_solaris2_4)

#ifndef Fortran
#ifdef __cplusplus
extern "C" int call35_1();
#else
extern int call35_1();
#endif
#endif
#endif

void func35_1()
{
#if defined(i386_unknown_solaris2_5) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(sparc_sun_solaris2_4)  

#if !defined Fortran

    int value;
    value = call35_1();

    if( value != 35 )
    {
      logerror( "**Failed** test #35 (function relocation)\n" );

      logerror( "    total = %d, should be 35.\n", value );

      switch(value)
      {
        case 1: logerror( "    Entry instrumentation did not work.\n" ); break;
        case 2: logerror( "    Exit instrumentation did not work.\n" ); break;
        default: logerror("    Take a look at the call to call35_2.\n" ); break;
      }
      passedTest[ 35 ] = FALSE;
      return;
    }

    passedTest[ 35 ] = TRUE;
    logerror( "Passed test #35 (function relocation)\n" );
#endif
#else
    passedTest[ 35 ] = TRUE;
    logerror( "Skipped test #35 (function relocation)\n" );
#if defined(i386_unknown_nt4_0)
    logerror( "\t- test not implemented for this platform\n" );
#else
#if defined(ia64_unknown_linux2_4)
    logerror( "\t- not applicable to this platform.\n" );
#else
    logerror( "\t- not implemented on this platform\n" );
#endif
#endif
#endif
}

int call36_1(int i1, int i2, int i3, int i4, int i5, int i6, int i7,
             int i8, int i9, int i10) {
   return i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10;
}

/* Test #36 (callsite parameter referencing) */

void func36_1()
{
   int failure = 0;

   int result = call36_1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

   if(result != 55) {
      logerror("  expecting a value of 55 from call36_1, got %d\n",
              result);
      failure = 1;
   }

   if(globalVariable36_1 != 1) {
      logerror("   for test 36, expecting arg1 value of 1, got %d\n",
              globalVariable36_1);
      failure = 1;      
   }
   if(globalVariable36_2 != 2) {
      logerror("   for test 36, expecting arg2 value of 2, got %d\n",
              globalVariable36_2);
      failure = 1;      
   }
   if(globalVariable36_3 != 3) {
      logerror("   for test 36, expecting arg3 value of 3, got %d\n",
              globalVariable36_3);
      failure = 1;      
   }
   if(globalVariable36_4 != 4) {
      logerror("   for test 36, expecting arg4 value of 4, got %d\n",
              globalVariable36_4);
      failure = 1;
   }
   if(globalVariable36_5 != 5) {
      logerror("   for test 36, expecting arg5 value of 5, got %d\n",
              globalVariable36_5);
      failure = 1;
   }
   if(globalVariable36_6 != 6) {
      logerror("   for test 36, expecting arg6 value of 6, got %d\n",
              globalVariable36_6);
      failure = 1;
   }
#if !defined(alpha_dec_osf4_0) && !defined(arch_x86_64)  /* alpha and AMD64 don't handle more than 6 */
   if(globalVariable36_7 != 7) {
      logerror("   for test 36, expecting arg7 value of 7, got %d\n",
              globalVariable36_7);
      failure = 1;
   }
   if(globalVariable36_8 != 8) {
      logerror("   for test 36, expecting arg8 value of 8, got %d\n",
              globalVariable36_8);
      failure = 1;
   }
   if(globalVariable36_9 != 9) {
      logerror("   for test 36, expecting arg9 value of 9, got %d\n",
              globalVariable36_9);
      failure = 1;
   }
   if(globalVariable36_10 != 10) {
      logerror("   for test 36, expecting arg10 value of 10, got %d\n",
              globalVariable36_10);
#if defined(sparc_sun_solaris2_4)
      logerror("   not marking as an error since this needs "
              "to be implemented for sparc-sol\n");
#else
      failure = 1;
#endif
   }
#else
   logerror("    test 36: AMD64 and alpha currently do not handle referencing more than\n");
   
   logerror("    6 callsite args, so not testing past 6 args\n");
#endif

   if(failure == 0) {
      passedTest[ 36 ] = TRUE;
      logerror( "Passed test #36 (callsite parameter referencing)\n" );    
   } else {
      passedTest[ 36 ] = FALSE;
      logerror( "**Failed** test #36 (callsite parameter referencing)\n");
   }
}

/* Test #37 (loop instrumentation) */

volatile int globalVariable37_1 = 0;
        
void inc37_1() { globalVariable37_1++; }
        
/* At the end of normal execution, globalVariable37_1 should
   hold 100 + 500 + ( 100 * 10 ) + ( 100 * 10 * 7 ) = 8600
    
   If we instrument the entry and exit edge of each loop with a call
   to inc37_1, globalVariable37_1 should be increased by
   2 + ( 2 * 100 ) + ( 2 * 100 * 10 ) + ( 2 * 100 ) = 2402
        
   Successful loop edge instrumentation will give us a value of 11002.
*/  
void call37_1()
{
    int i, j, k, m;

    for (i = 0; i < 100; i++) {
        globalVariable37_1++;

        for (j = 0; j < 10; j++) {
            globalVariable37_1++;
            
            for (k = 0; k < 7; k++) {
                globalVariable37_1++;
            }
        }
        
        m = 0;
        do {
            globalVariable37_1++;
            m++;
        } while (m < 5);
    }
}

volatile int globalVariable37_2 = 0;

void inc37_2() { globalVariable37_2++; }

/* At the end of normal execution, globalVariable37_2 should
   hold 20.
   If we instrument the entry and exit edge of each loop with a call
   to inc37_2, globalVariable37_2 should be increased by
   2 + 2 + 2 = 6

   Successful loop edge instrumentation will give us a value of 26.
*/

/* The comment below is no longer relevant, but has been left in as an
 explanation of how this test arose. The original mechanism for testing
 loops (instrumenting some arbitrary block in the body that was expected
 to execute a certain number of times was fundamentally flawed, for
 reasons that will become apparent with a little thought. We're leaving
 these tests in, though, in the hopes that the compiler will produce
 different loop idioms and thus stress-test our loop detection code.
*/

/* test with small loop bodies. since there are no statements right after the
   start of the outer two loops there isn't much space to instrument. */
void call37_2()
{                
    volatile int i = 0;
    volatile int j = 0;
    volatile int k = 0;
    
    while (i < 5) {
        while (j < 10) {
            do {
                globalVariable37_2++;
                i++; j++; k++;
            } while (k < 20);
        }
    }
}


volatile int globalVariable37_3 = 0;

void inc37_3() { globalVariable37_3++; }

/* At the end of normal execution, globalVariable37_3 should
   hold 100 / 2 + (100 / 2 ) * 10 = 550
   
   If we instrument the entry and exit edge of each loop with a call
   to inc37_3, globalVariable37_3 should be increased by
   2 * 100 + 2 = 202

   Successful loop edge instrumentation will give us a value of 752.
*/

/* test with if statements as the only statements in a loop body. */
void call37_3()
{
    volatile int i, j;

    for (i = 0; i < 100; i++) {
        if (0 == (i % 2)) {
            globalVariable37_3++;
        }
        for (j = 0; j < 10; j++) {
            if (0 == (i % 2)) {
                globalVariable37_3++;
            }
        }
    }
}


void func37_1() {
#if defined(os_osf)
    passedTest [ 37 ] = TRUE;
    logerror( "Skipped test #37 (instrument loops)\n" );
    logerror( "\t- known to be a problem on this platform-- hah!\n" );
#else
    const int ANSWER37_1 = 11002;
    const int ANSWER37_2 = 26;
    const int ANSWER37_3 = 752;

    call37_1();
    call37_2();
    call37_3();

    passedTest[ 37 ] = TRUE;

    if (globalVariable37_1 != ANSWER37_1) {
	passedTest[ 37 ] = FALSE;
	logerror( "**Failed** test #37 (instrument loops)\n");
	logerror( "  globalVariable37_1 is %d, should have been %d.\n",
		globalVariable37_1, ANSWER37_1);
    }
    if (globalVariable37_2 != ANSWER37_2) {
	passedTest[ 37 ] = FALSE;
	logerror( "**Failed** test #37 (instrument loops)\n");
	logerror( "  globalVariable37_2 is %d, should have been %d.\n",
		globalVariable37_2, ANSWER37_2);
    } 
    if (globalVariable37_3 != ANSWER37_3) {
	passedTest[ 37 ] = FALSE;
	logerror( "**Failed** test #37 (instrument loops)\n");
	logerror( "  globalVariable37_3 is %d, should have been %d.\n",
		globalVariable37_3, ANSWER37_3);
    } 
    
    if (passedTest[ 37 ]) {
	logerror( "Passed test #37 (instrument loops)\n" );    
    }
#endif
}


/* Test #38 (basic block addresses) */

int globalVariable38_1 = 0;

void funCall38_1() { globalVariable38_1++; }
void funCall38_2() { globalVariable38_1++; }
void funCall38_3() { globalVariable38_1++; }
void funCall38_4() { globalVariable38_1++; }
void funCall38_5() { globalVariable38_1++; }
void funCall38_6() { globalVariable38_1++; }
void funCall38_7() { globalVariable38_1++; }


/* the mutator checks if the addresses of these call* functions are within 
   the address ranges of the basic blocks in the flowgraph */
void call38_1() {
    int i, j, k, m;

    funCall38_1();

    for (i = 0; i < 50; i++) {
	m = i;
	funCall38_2();

	for (j = 0; i < 100; i++) {
	    for (k = 0; k < i ; i++) {
		funCall38_3();
	    }
	}

	funCall38_4();

	while (m < 100) {
	    funCall38_5();
	    m++;
	}

	funCall38_6();
    }

    funCall38_7();
}

void func38_1() {
    /* The only possible failures occur in the mutator. */
    passedTest[ 38 ] = TRUE;
    logerror( "Passed test #38 (basic block addresses)\n" );
}


/* Test #39 (refex function search) */
void func39_1() {
#if defined(sparc_sun_solaris2_4) \
 || defined(alpha_dec_osf4_0) \
 || defined(i386_unknown_solaris2_5) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(ia64_unknown_linux2_4) \
 || defined(mips_sgi_irix6_4) \
 || defined(rs6000_ibm_aix4_1)

    /* The only possible failures occur in the mutator. */
    passedTest[ 39 ] = TRUE;
    logerror( "Passed test #39 (regex function search)\n" );
#else
   /*  no regex for windows */
   logerror("Skipped test #39 (regex function search)\n");
   logerror("\t- not implemented on this platform\n");
   passedTest[ 39 ] = TRUE;
#endif
}

/* Test #40 (monitor dynamic function calls) */
typedef void (*intFuncArg) (void);
int gvDummy40 = 0;

void call40_1(void) {  gvDummy40 += 401;}
void call40_2(void) {  gvDummy40 += 402;}
void call40_3(void) {  gvDummy40 += 403;}
void call40_4(void) {  gvDummy40 += -1;}

/*  these should be set by the monitoring function
  (and will be checked afterwards)
   callees: */
unsigned gv40_call40_1_addr = (unsigned)-1;
unsigned gv40_call40_2_addr = (unsigned)-1;
unsigned gv40_call40_3_addr = (unsigned)-1;

/*   callsite addr -- measured thrice: */
unsigned gv40_call40_5_addr1 = (unsigned)-1;
unsigned gv40_call40_5_addr2 = (unsigned)-1;
unsigned gv40_call40_5_addr3 = (unsigned)-1;

unsigned callsite40_5_addr =  0;
int call40_5(intFuncArg callme)
{
  int ret = 0;
  intFuncArg tocall = (intFuncArg) callme;

  call40_4(); /* lets have a non-dynamic call site here too */

  if (!tocall) {
    logerror("%s[%d]:  FIXME!\n", __FILE__, __LINE__);
    return ret;
  }

  (tocall)();

  return ret;
}

unsigned int gv_addr_of_call40_1 = 0;
unsigned int gv_addr_of_call40_2 = 0;
unsigned int gv_addr_of_call40_3 = 0;
int call_counter = 0;

void func_40_monitorFunc(unsigned int callee_addr, unsigned int callsite_addr)
{
  if (call_counter == 0) {
    gv40_call40_5_addr1 = callsite_addr;
    gv40_call40_1_addr = callee_addr;
    call_counter++;
    return;
  }
  if (call_counter == 1) {
    gv40_call40_5_addr2 = callsite_addr;
    gv40_call40_2_addr = callee_addr;
    call_counter++;
    return;
  }
  if (call_counter == 2) {
    gv40_call40_5_addr3 = callsite_addr;
    gv40_call40_3_addr = callee_addr;
    call_counter++;
    return;
  }
   logerror("%s[%d]:  FIXME! call counter = %d\n", __FILE__, __LINE__, call_counter);
  return;
}

void func40_1(void) 
{
#ifdef __XLC__
  /*  xlc does not produce dynamic inst points with this example, 
      so we just ignore it.
  */
   logerror("Skipped test #40 (monitor dynamic call sites)\n");
   logerror("\t- not implemented for mutatees compiled with xlc \n");
   passedTest[ 40 ] = TRUE;
   return;
#endif
   
#if !defined(alpha_dec_osf4_0) \
 && !defined(ia64_unknown_linux2_4) \
 && !defined(mips_sgi_irix6_4) \
 && !defined(os_windows)
    
    passedTest [40 ] = TRUE;  /* lets be optimistic  -- ha! */

    call40_5(call40_1);
    call40_5(call40_2);
    call40_5(call40_3);

    if (gv_addr_of_call40_1 != gv40_call40_1_addr) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)gv_addr_of_call40_1, (void *)gv40_call40_1_addr);
      passedTest[ 40 ] = FALSE;
    }

    if (gv_addr_of_call40_2 != gv40_call40_2_addr) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)gv_addr_of_call40_2, (void *)gv40_call40_2_addr);
      passedTest[ 40 ] = FALSE;
    }

    if (gv_addr_of_call40_3 != gv40_call40_3_addr) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)gv_addr_of_call40_3, (void *)gv40_call40_3_addr);
      passedTest[ 40 ] = FALSE;
    }

    if (callsite40_5_addr != gv40_call40_5_addr1) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)callsite40_5_addr, (void *)gv40_call40_5_addr1);
      passedTest[ 40 ] = FALSE;
    }

    if (callsite40_5_addr != gv40_call40_5_addr2) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)callsite40_5_addr, (void *)gv40_call40_5_addr2);
      passedTest[ 40 ] = FALSE;
    }

    if (callsite40_5_addr != gv40_call40_5_addr3) {
      logerror( "Failed test #40 (monitor dynamic call site)\n" );
      logerror( "%s[%d]: addr %p != addr %p\n", __FILE__, __LINE__,
              (void *)callsite40_5_addr, (void *)gv40_call40_5_addr3);
      passedTest[ 40 ] = FALSE;
    }
    if (passedTest[40] == FALSE)
      return;

    passedTest[ 40 ] = TRUE;
    logerror( "Passed test #40 (monitor dynamic call site)\n" );
    fflush(NULL);
#else
   /*  no alpha yet */
   logerror("Skipped test #40 (monitor dynamic call sites)\n");
   logerror("\t- not implemented on this platform\n");
   passedTest[ 40 ] = TRUE;
#endif
}

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

/* "replaceFunctionCall()" on Irix usually requires that the new
   callee have a GOT entry.  This dummy function forces GOT entries to
   be created for these functions. */
#if defined(mips_sgi_irix6_4)
void dummy_force_got_entries()
{
    call14_1();
    call15_3();
}
#endif

#ifdef i386_unknown_nt4_0
#define USAGE "Usage: test1.mutatee [-attach] [-verbose] -run <num> .."
#else
#define USAGE "Usage: test1.mutatee [-attach <fd>] [-verbose] -run <num> .."
#endif


#ifdef __cplusplus
extern "C" void runTests();
#endif

void runTests()
{
    int j;

    for (j=0; j <= MAX_TEST; j++) {
	passedTest [j] = FALSE;
    }
    if (runTest[1]) func1_1();
    if (runTest[2]) func2_1();
    if (runTest[3]) func3_1();
    if (runTest[4]) func4_1();
    if (runTest[5]) func5_1();
    if (runTest[6]) func6_1();
    if (runTest[7]) func7_1();
    if (runTest[8]) func8_1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    if (runTest[9]) func9_1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    if (runTest[10]) func10_1();
    if (runTest[11]) func11_1();
    if (runTest[12]) {
      func12_1();
      /* I need to insert a stop_process_() here for fast-and-loose mode */
      if (fastAndLoose && runAnyAfter(12, 40)) {
	stop_process_();
      }
    }
    if (runTest[13]) func13_1(131, 132, 133, 134, 135);
    if (runTest[14]) func14_1();
    if (runTest[15]) {
      func15_1();
      if (fastAndLoose && runAnyAfter(15, 40)) {
	stop_process_();
      }
    }
    if (runTest[16]) func16_1();
    if (runTest[17]) func17_1();
    if (runTest[18]) func18_1();
    if (runTest[19]) {
      func19_1();
      if (fastAndLoose && runAnyAfter(19, 40)) {
	stop_process_();
      }
    }
    if (runTest[20]) func20_1();
    if (runTest[21]) func21_1();
    if (runTest[22]) func22_1();
    if (runTest[23]) func23_1();
    if (runTest[24]) func24_1();
    if (runTest[25]) func25_1();
    if (runTest[26]) func26_1();
    if (runTest[27]) func27_1();
    if (runTest[28]) func28_1();
    if (runTest[29]) func29_1();
    if (runTest[30]) func30_1();
    if (runTest[31]) func31_1();
    if (runTest[32]) func32_1();
    if (runTest[33]) func33_1();
    if (runTest[34]) func34_1();
    if (runTest[35]) func35_1();
    if (runTest[36]) func36_1();    
    if (runTest[37]) func37_1();
    if (runTest[38]) func38_1();
    if (runTest[39]) func39_1();
    if (runTest[40]) func40_1();
}