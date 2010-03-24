/*
 * Copyright (c) 1996-2009 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as "Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* $Id: RTmutatedBinary.c,v 1.10 2008/02/20 08:31:08 jaw Exp $ */

/* this file contains the code to restore the necessary
   data for a mutated binary 
 */


#include <unistd.h>
#include <stdlib.h>

extern int isMutatedExec;
char *buffer;

/* checkMutatedFile() is defined in RTmutatedBinary_<fileformat>.c */

extern int checkMutatedFile();

/*
 * This function sets up pre-initialization
 * data structures for SaveTheWorld. Ensure
 * it is called _before_ DYNINSTinit
 */ 
#if defined (cap_save_the_world)
void RTmutatedBinary_init()
{

/* this buffer is allocated to clear
   the first page on the heap. This is necessary
   because loading the heap tramps uses mmap, which
   is going to eat the heap if the heap begins on 
   the same page the heap tramps end on (almost certain)
*/
    /* Call-once protection */
    static int init = 0;
    
    if (!init) {
        buffer = (char*) malloc(getpagesize());
        isMutatedExec =checkMutatedFile();
        /* Can't free this buffer, because we need the same memory footprint
           for when we load in shared libraries */
        /*        free(buffer); */
        init++;
    }
    
}
#endif
