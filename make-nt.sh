#rem Script for building Paradyn & DynInstAPI on WinNT platform
#@echo off
#rem $Id: make-nt.sh,v 1.14 2002/04/17 17:07:57 schendel Exp $
#@echo on

#set LIBRARY_DEST="..\lib"
#set PROGRAM_DEST="..\bin"

#if not exist %LIBRARY_DEST% mkdir %LIBRARY_DEST%
#if not exist %LIBRARY_DEST%\%PLATFORM% mkdir %LIBRARY_DEST%\%PLATFORM%
#if not exist %PROGRAM_DEST% mkdir %PROGRAM_DEST%
#if not exist %PROGRAM_DEST%\%PLATFORM% mkdir %PROGRAM_DEST%\%PLATFORM%
pwd

PDROOT=`pwd`
cd pdutil/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd igen/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd rtinst/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd paradynd/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd thread/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd paradyn/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visi/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visiClients/histVisi/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visiClients/barchart/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visiClients/tableVisi/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visiClients/phaseTable/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd visiClients/tclVisi/$PLATFORM; nmake clean; nmake install
cd $PDROOT
#rem No visiClients/terrain to build for WinNT!

cd dyninstAPI_RT/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd dyninstAPI/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd dyninstAPI/tests/$PLATFORM; nmake clean; nmake install
cd $PDROOT
cd dyner/$PLATFORM; nmake clean; nmake install
cd $PDROOT




