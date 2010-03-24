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

/* -*- Mode: C; indent-tabs-mode: true -*- */
/* $Id: writeBackElf.h,v 1.21 2007/01/09 02:02:08 giri Exp $ */

#ifndef writeBackElf__
#define writeBackElf__

#if defined(sparc_sun_solaris2_4) \
 || defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(ia64_unknown_linux2_4)

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libelf.h>
#if defined(i386_unknown_linux2_0) \
 || defined(x86_64_unknown_linux2_4) /* Blind duplication - Ray */ \
 || defined(ia64_unknown_linux2_4)

#include "linux.h"
#endif
#include "common/h/Vector.h"
#include "dyninstAPI/src/symtab.h"
#include "ELF_Section.h"
#include <unistd.h>
#include "imageUpdate.h"

class process;

class writeBackElf{

private:
	
	Elf* newElf;
	Elf* oldElf;

	int oldfd, newfd;
	//important data sections in the
	//new Elf that need updated
	Elf_Data *textData;
	Elf_Data *symStrData;
	Elf_Data *dynStrData;
        Elf_Data *symTabData;
	Elf_Data *hashData;
	Elf_Data *dynsymData;
	Elf_Data *rodata;
	Elf_Data *dataData;

	Elf32_Shdr *textSh;
	Elf32_Shdr *rodataSh;
	Elf32_Ehdr *newEhdr;
	Elf32_Phdr *newPhdr;

	//when this is added to dyninst make this a
	//vector or something nice like that
	ELF_Section *newSections;
	unsigned int newSectionsSize;

	unsigned int lastAddr; //last used address in the old Elf
	unsigned int shiftSize; //shift caused by adding program headers, a multiple of 0x20
	unsigned int dataStartAddress; 
	unsigned int insertPoint; //index in newElf of first new section 

	unsigned int startAddr; //start address of .text in newElf
	unsigned int endAddr; //end address of .text in newElf 
	unsigned int rodataAddr; //start address of .rodata in newElf 
	unsigned int rodataSize; //size of .rodata in newElf
	unsigned int newHeapAddr; //location of the heap in the newElf

	unsigned int oldLastPage;//location of the last page in memory allocated in the oldElf
	int DEBUG_MSG;
	int pageSize ; // page size on this system
	process* mutateeProcess;
	int mutateeTextSize;
	unsigned int mutateeTextAddr;
	unsigned int newHeapAddrIncr;
	char **newElfNewData_d_buf;
	int newElfNewData_d_buf_count;

	void updateSymbols(Elf_Data* symtabData,Elf_Data* strData);
	void updateDynamic(Elf_Data* dynamicData);
	void driver(); // main processing loop of outputElf()
	void createSections();
	void addSectionNames(Elf_Data* newdata, Elf_Data *olddata);
	void fixPhdrs(Elf32_Phdr*);
	void parseOldElf();

public:

	writeBackElf(const char* oldElfName, const char* newElfName,
					 int debugOutputFlag=0);
	~writeBackElf();

	void registerProcess(process *proc);
	
	int addSection(unsigned int addr, void *data, unsigned int dataSize,
						const char* name, bool loadable=true);

	bool createElf();
	void compactSections(pdvector<imageUpdate*> imagePatches,
								pdvector<imageUpdate*> &newPatches); 
	void compactLoadableSections(pdvector<imageUpdate*> imagePatches,
										  pdvector<imageUpdate*> &newPatches);
	void alignHighMem(pdvector<imageUpdate*> imagesPatches);
	Elf* getElf();
};

#endif
#endif