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


// $Id: language.h,v

// Put C++ language specific code in here

#ifndef __LANGUAGE__
#define __LANGUAGE__

#if ! defined( TYPENAME )

#if defined( __GNUC__ )
#  define TYPENAME typename
#elif defined(__SUNPRO_CC)
#  define TYPENAME typename
#elif defined (__XLC__) || defined(__xlC__)
#define TYPENAME typename
#elif defined(mips_sgi_irix6_4)  // not sure what MACRO the IRIX compiler uses
#  define TYPENAME typename
#elif defined(_MSC_VER) && (_MSC_VER >= 1310)
    // Visual Studio .NET or greater
#  define TYPENAME typename
#else  // other compilers may not support the typename keyword yet
#define TYPENAME
#endif

#endif



#endif

#if !defined(DLLEXPORT)
#if defined (_MSC_VER)
/* If we're on Windows, we need to explicetely export these functions: */
	#if defined(DLL_BUILD)
		#define DLLEXPORT __declspec(dllexport)
	#else
		#define DLLEXPORT __declspec(dllimport)	
	#endif
#else
	#define DLLEXPORT
#endif
#endif
