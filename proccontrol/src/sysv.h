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

#if !defined(SYSV_H_)
#define SYSV_H_

#include "dynutil/h/ProcReader.h"
#include "proccontrol/src/int_process.h"
#include "proccontrol/h/Handler.h"
#include "common/h/addrtranslate.h"

using namespace Dyninst;
using namespace ProcControlAPI;

class sysv_process;

class PCProcReader : public ProcessReader
{
   friend class sysv_process;
private:
   sysv_process *proc;
   
   long word_cache;
   Dyninst::Address word_cache_addr;
   bool word_cache_valid;

   bool postAsyncRead(Dyninst::Address addr);
   bool ReadMemAsync(Address addr, void *buffer, unsigned size);
   bool handleAsyncCompletion();
   void clearBuffers();

   static const unsigned long async_read_align = 0x1000;
   std::map<Dyninst::Address, char *> async_read_buffers;
   mem_response::ptr memresult;
   Dyninst::Address pending_addr;
public:
   PCProcReader(sysv_process *proc_);
   virtual ~PCProcReader();
   virtual bool start();
   virtual bool isAsync();
   virtual bool ReadMem(Address addr, void *buffer, unsigned size);
   virtual bool GetReg(MachRegister reg, MachRegisterVal &val);
   virtual bool done();
};

class sysv_process : virtual public int_process
{
   friend class PCProcReader;
 public:
   sysv_process(Dyninst::PID p, std::string e, std::vector<std::string> a, std::map<int,int> f);
   sysv_process(Dyninst::PID pid_, int_process *p);
   virtual ~sysv_process();
   virtual bool refresh_libraries(std::set<int_library *> &added_libs,
                                  std::set<int_library *> &rmd_libs,
                                  std::set<response::ptr> &async_responses);
   virtual bool initLibraryMechanism();

   Dyninst::Address getLibBreakpointAddr() const;

   bool isLibraryTrap(Dyninst::Address trap_addr);
 protected:
   virtual bool plat_execed();
   virtual bool plat_isStaticBinary();

   static int_breakpoint *lib_trap;

   Address breakpoint_addr;
   AddressTranslate *translator;
   bool lib_initialized;
   PCProcReader *procreader;
};

#endif