/*
 * Copyright (c) 1996-2011 Barton P. Miller
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

#if !defined(FDG_GRAPH_H)
#define FDG_GRAPH_H

#include "Node.h"
#include "Graph.h"

#include <boost/shared_ptr.hpp>

class BPatch_function;
class BPatch_basicBlock;

namespace Dyninst {

namespace DepGraphAPI {

// This class represents a Flow Dependence Graph for a given function.
class FDG : public Graph {
public:
    typedef dyn_detail::boost::shared_ptr<FDG> Ptr;

private:
    typedef BPatch_function Function;
    typedef BPatch_basicBlock Block;
    
public:
    // Creates and returns the FDG for the given function.
    static FDG::Ptr analyze(Function *func);

    virtual ~FDG() {};

    // Returns the entry node for the FDG.
    Node::Ptr virtualEntryNode() { return virtEntryNode_; }

    // Creates an empty FDG and returns.
    static Ptr createGraph() { return FDG::Ptr(new FDG()); }

    // Finds the BlockNode that contains the given basic block.
    virtual bool findBlock(BPatch_basicBlock *block, NodeIterator &begin, NodeIterator &end);
private:
    FDG();

    // Node to make sure everyone is reachable...
    Node::Ptr virtEntryNode_;
};

};
}
#endif
