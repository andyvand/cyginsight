rem Script for building Paradyn & DynInstAPI on WinNT platform
@echo off
rem $Id: make-nt.bat,v 1.11 2000/10/17 17:10:08 schendel Exp $
@echo on

set LIBRARY_DEST="..\lib"
set PROGRAM_DEST="..\bin"

if not exist %LIBRARY_DEST% mkdir %LIBRARY_DEST%
if not exist %LIBRARY_DEST%\%PLATFORM% mkdir %LIBRARY_DEST%\%PLATFORM%
if not exist %PROGRAM_DEST% mkdir %PROGRAM_DEST%
if not exist %PROGRAM_DEST%\%PLATFORM% mkdir %PROGRAM_DEST%\%PLATFORM%

cmd /c "cd pdutil\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd pdutilOld\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd igen\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd rtinst\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd paradynd\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd thread\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd paradyn\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visi\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visiClients\histVisi\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visiClients\barchart\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visiClients\tableVisi\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visiClients\phaseTable\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd visiClients\tclVisi\%PLATFORM% && nmake clean && nmake install"
rem No visiClients/terrain to build for WinNT!

cmd /c "cd dyninstAPI_RT\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\tests\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyner\%PLATFORM% && nmake clean && nmake install"

