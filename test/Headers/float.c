// RUN: %clang_cc1 -fsyntax-only -verify -std=c89 -ffreestanding %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c99 -ffreestanding %s
// RUN: %clang_cc1 -fsyntax-only -verify -std=c11 -ffreestanding %s
// expected-no-diagnostics

// XFAIL: ppc64

/* Basic conformance checks against the N1570 draft of C11 Std. */
/*
    5.2.4.2.2p11, pp. 30
*/
#include <float.h>

#ifndef FLT_RADIX
    #error "Mandatory macro FLT_RADIX is missing."
#elif   FLT_RADIX < 2
    #error "Mandatory macro FLT_RADIX is invalid."
#endif


#ifndef FLT_MANT_DIG
    #error "Mandatory macro FLT_MANT_DIG is missing."
#elif   FLT_MANT_DIG < 1
    #error "Mandatory macro FLT_MANT_DIG is invalid."
#endif
#ifndef DBL_MANT_DIG
    #error "Mandatory macro DBL_MANT_DIG is missing."
#elif   DBL_MANT_DIG < 1
    #error "Mandatory macro DBL_MANT_DIG is invalid."
#endif
#ifndef LDBL_MANT_DIG
    #error "Mandatory macro LDBL_MANT_DIG is missing."
#elif   LDBL_MANT_DIG < 1
    #error "Mandatory macro LDBL_MANT_DIG is invalid."
#endif
#if ((FLT_MANT_DIG > DBL_MANT_DIG) || (DBL_MANT_DIG > LDBL_MANT_DIG))
    #error "Mandatory macros {FLT,DBL,LDBL}_MANT_DIG are invalid."
#endif


#if __STDC_VERSION__ >= 201112L || !defined(__STRICT_ANSI__)
    #ifndef FLT_DECIMAL_DIG
        #error "Mandatory macro FLT_DECIMAL_DIG is missing."
    #elif   FLT_DECIMAL_DIG < 6
        #error "Mandatory macro FLT_DECIMAL_DIG is invalid."
    #endif
    #ifndef DBL_DECIMAL_DIG
        #error "Mandatory macro DBL_DECIMAL_DIG is missing."
    #elif   DBL_DECIMAL_DIG < 10
        #error "Mandatory macro DBL_DECIMAL_DIG is invalid."
    #endif
    #ifndef LDBL_DECIMAL_DIG
        #error "Mandatory macro LDBL_DECIMAL_DIG is missing."
    #elif   LDBL_DECIMAL_DIG < 10
        #error "Mandatory macro LDBL_DECIMAL_DIG is invalid."
    #endif
    #if ((FLT_DECIMAL_DIG > DBL_DECIMAL_DIG) || (DBL_DECIMAL_DIG > LDBL_DECIMAL_DIG))
        #error "Mandatory macros {FLT,DBL,LDBL}_DECIMAL_DIG are invalid."
    #endif
#else
    #ifdef FLT_DECIMAL_DIG
        #error "Macro FLT_DECIMAL_DIG should not be defined."
    #endif
    #ifdef DBL_DECIMAL_DIG
        #error "Macro DBL_DECIMAL_DIG should not be defined."
    #endif
    #ifdef LDBL_DECIMAL_DIG
        #error "Macro LDBL_DECIMAL_DIG should not be defined."
    #endif
#endif


#ifndef DECIMAL_DIG
    #error "Mandatory macro DECIMAL_DIG is missing."
#elif   DECIMAL_DIG < 10
    #error "Mandatory macro DECIMAL_DIG is invalid."
#endif


#ifndef FLT_DIG
    #error "Mandatory macro FLT_DIG is missing."
#elif   FLT_DIG < 6
    #error "Mandatory macro FLT_DIG is invalid."
#endif
#ifndef DBL_DIG
    #error "Mandatory macro DBL_DIG is missing."
#elif   DBL_DIG < 10
    #error "Mandatory macro DBL_DIG is invalid."
#endif
#ifndef LDBL_DIG
    #error "Mandatory macro LDBL_DIG is missing."
#elif   LDBL_DIG < 10
    #error "Mandatory macro LDBL_DIG is invalid."
#endif
#if ((FLT_DIG > DBL_DIG) || (DBL_DIG > LDBL_DIG))
    #error "Mandatory macros {FLT,DBL,LDBL}_DIG, are invalid."
#endif


#ifndef FLT_MIN_EXP
    #error "Mandatory macro _MIN_EXP is missing."
#elif   FLT_MIN_EXP > -2
    #error "Mandatory macro _MIN_EXP is invalid."
#endif
#ifndef DBL_MIN_EXP
    #error "Mandatory macro DBL_MIN_EXP is missing."
#elif   DBL_MIN_EXP > -2
    #error "Mandatory macro DBL_MIN_EXP is invalid."
#endif
#ifndef LDBL_MIN_EXP
    #error "Mandatory macro LDBL_MIN_EXP is missing."
#elif   LDBL_MIN_EXP > -2
    #error "Mandatory macro LDBL_MIN_EXP is invalid."
#endif
#if ((FLT_MIN_EXP < DBL_MIN_EXP) || (DBL_MIN_EXP < LDBL_MIN_EXP))
    #error "Mandatory macros {FLT,DBL,LDBL}_MIN_EXP are invalid."
#endif


#ifndef FLT_MIN_10_EXP
    #error "Mandatory macro FLT_MIN_10_EXP is missing."
#elif   FLT_MIN_10_EXP > -37
    #error "Mandatory macro FLT_MIN_10_EXP is invalid."
#endif
#ifndef DBL_MIN_10_EXP
    #error "Mandatory macro DBL_MIN_10_EXP is missing."
#elif   DBL_MIN_10_EXP > -37
    #error "Mandatory macro DBL_MIN_10_EXP is invalid."
#endif
#ifndef LDBL_MIN_10_EXP
    #error "Mandatory macro LDBL_MIN_10_EXP is missing."
#elif   LDBL_MIN_10_EXP > -37
    #error "Mandatory macro LDBL_MIN_10_EXP is invalid."
#endif
#if ((FLT_MIN_10_EXP < DBL_MIN_10_EXP) || (DBL_MIN_10_EXP < LDBL_MIN_10_EXP))
    #error "Mandatory macros {FLT,DBL,LDBL}_MIN_10_EXP are invalid."
#endif


#ifndef FLT_MAX_EXP
    #error "Mandatory macro FLT_MAX_EXP is missing."
#elif   FLT_MAX_EXP < 2
    #error "Mandatory macro FLT_MAX_EXP is invalid."
#endif
#ifndef DBL_MAX_EXP
    #error "Mandatory macro DBL_MAX_EXP is missing."
#elif   DBL_MAX_EXP < 2
    #error "Mandatory macro DBL_MAX_EXP is invalid."
#endif
#ifndef LDBL_MAX_EXP
    #error "Mandatory macro LDBL_MAX_EXP is missing."
#elif   LDBL_MAX_EXP < 2
    #error "Mandatory macro LDBL_MAX_EXP is invalid."
#endif
#if ((FLT_MAX_EXP > DBL_MAX_EXP) || (DBL_MAX_EXP > LDBL_MAX_EXP))
    #error "Mandatory macros {FLT,DBL,LDBL}_MAX_EXP are invalid."
#endif


#ifndef FLT_MAX_10_EXP
    #error "Mandatory macro FLT_MAX_10_EXP is missing."
#elif   FLT_MAX_10_EXP < 37
    #error "Mandatory macro FLT_MAX_10_EXP is invalid."
#endif
#ifndef DBL_MAX_10_EXP
    #error "Mandatory macro DBL_MAX_10_EXP is missing."
#elif   DBL_MAX_10_EXP < 37
    #error "Mandatory macro DBL_MAX_10_EXP is invalid."
#endif
#ifndef LDBL_MAX_10_EXP
    #error "Mandatory macro LDBL_MAX_10_EXP is missing."
#elif   LDBL_MAX_10_EXP < 37
    #error "Mandatory macro LDBL_MAX_10_EXP is invalid."
#endif
#if ((FLT_MAX_10_EXP > DBL_MAX_10_EXP) || (DBL_MAX_10_EXP > LDBL_MAX_10_EXP))
    #error "Mandatory macros {FLT,DBL,LDBL}_MAX_10_EXP are invalid."
#endif


/* Internal consistency checks */
_Static_assert(FLT_RADIX == __FLT_RADIX__, "");

_Static_assert(FLT_MANT_DIG == __FLT_MANT_DIG__, "");
_Static_assert(DBL_MANT_DIG == __DBL_MANT_DIG__, "");
_Static_assert(LDBL_MANT_DIG == __LDBL_MANT_DIG__, "");

#if __STDC_VERSION__ >= 201112L || !defined(__STRICT_ANSI__)
_Static_assert(FLT_DECIMAL_DIG == __FLT_DECIMAL_DIG__, "");
_Static_assert(DBL_DECIMAL_DIG == __DBL_DECIMAL_DIG__, "");
_Static_assert(LDBL_DECIMAL_DIG == __LDBL_DECIMAL_DIG__, "");
#endif

_Static_assert(DECIMAL_DIG == __DECIMAL_DIG__, "");

_Static_assert(FLT_DIG == __FLT_DIG__, "");
_Static_assert(DBL_DIG == __DBL_DIG__, "");
_Static_assert(LDBL_DIG == __LDBL_DIG__, "");

_Static_assert(FLT_MIN_EXP == __FLT_MIN_EXP__, "");
_Static_assert(DBL_MIN_EXP == __DBL_MIN_EXP__, "");
_Static_assert(LDBL_MIN_EXP == __LDBL_MIN_EXP__, "");

_Static_assert(FLT_MIN_10_EXP == __FLT_MIN_10_EXP__, "");
_Static_assert(DBL_MIN_10_EXP == __DBL_MIN_10_EXP__, "");
_Static_assert(LDBL_MIN_10_EXP == __LDBL_MIN_10_EXP__, "");

_Static_assert(FLT_MAX_EXP == __FLT_MAX_EXP__, "");
_Static_assert(DBL_MAX_EXP == __DBL_MAX_EXP__, "");
_Static_assert(LDBL_MAX_EXP == __LDBL_MAX_EXP__, "");

_Static_assert(FLT_MAX_10_EXP == __FLT_MAX_10_EXP__, "");
_Static_assert(DBL_MAX_10_EXP == __DBL_MAX_10_EXP__, "");
_Static_assert(LDBL_MAX_10_EXP == __LDBL_MAX_10_EXP__, "");