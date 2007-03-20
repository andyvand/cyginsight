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

// $Id: PCintern.h,v 1.21 2004/03/23 01:12:27 eli Exp $
// Included by PC modules only

#ifndef PC_INTERN_H
#define PC_INTERN_H

#include <iostream>

#include "../pdMain/paradyn.h"
#include "common/h/List.h"
#include "pdutil/h/PriorityQueue.h"
#include "pdthread/h/thread.h"
#include "dataManager.thread.CLNT.h"
#include "UI.thread.CLNT.h"
#include "../DMthread/DMinclude.h"
#include "../TCthread/tunableConst.h"
#include "performanceConsultant.thread.SRVR.h"

struct PCInterval {
  relTimeStamp start;
  relTimeStamp end;
  pdRate value;
};

#define PCdataQSize 20
ostream& operator <<(ostream &os, PCInterval &i);

typedef resourceListHandle focus;
typedef metricInstanceHandle PCmetDataID;
class experiment;
typedef experiment* PCmetSubscriber;
typedef enum { averaging, nonfiltering} filterType; 

// known or "base" resources -- these don't vary across applications
extern resourceHandle rootResource;
extern resourceHandle SyncObject;
extern resourceHandle Procedures;
extern resourceHandle Machines;
extern resourceHandle Locks;
extern resourceHandle Barriers;
extern resourceHandle Semaphores;
extern resourceHandle Messages;

extern focus topLevelFocus;

class hypothesis;
class whyAxis;
class costServer;

extern whyAxis *PCWhyAxis;
extern hypothesis *const topLevelHypothesis;
extern const unsigned GlobalPhaseID;

#endif
