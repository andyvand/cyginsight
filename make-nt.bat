rem Script for building Paradyn & DynInstAPI on WinNT platform
@echo off
rem $Id: make-nt.bat,v 1.15 2003/06/10 03:58:18 pcroth Exp $
@echo on

set LIBRARY_DEST="..\lib"
set PROGRAM_DEST="..\bin"

if not exist %LIBRARY_DEST% mkdir %LIBRARY_DEST%
if not exist %LIBRARY_DEST%\%PLATFORM% mkdir %LIBRARY_DEST%\%PLATFORM%
if not exist %PROGRAM_DEST% mkdir %PROGRAM_DEST%
if not exist %PROGRAM_DEST%\%PLATFORM% mkdir %PROGRAM_DEST%\%PLATFORM%

cmd /c "cd igen\%PLATFORM% && nmake clean"
cmd /c "cd igen\%PLATFORM% && nmake install"
cmd /c "cd pdutil\%PLATFORM% && nmake clean"
cmd /c "cd pdutil\%PLATFORM% && nmake install"
cmd /c "cd mdl\%PLATFORM% && nmake clean"
cmd /c "cd mdl\%PLATFORM% && nmake install"
cmd /c "cd rtinst\%PLATFORM% && nmake clean"
cmd /c "cd rtinst\%PLATFORM% && nmake install"
cmd /c "cd paradynd\%PLATFORM% && nmake clean"
cmd /c "cd paradynd\%PLATFORM% && nmake install"
cmd /c "cd thread\%PLATFORM% && nmake clean"
cmd /c "cd thread\%PLATFORM% && nmake install"
cmd /c "cd paradyn\%PLATFORM% && nmake clean"
cmd /c "cd paradyn\%PLATFORM% && nmake install"
cmd /c "cd visi\%PLATFORM% && nmake clean"
cmd /c "cd visi\%PLATFORM% && nmake install"
cmd /c "cd visiClients\histVisi\%PLATFORM% && nmake clean"
cmd /c "cd visiClients\histVisi\%PLATFORM% && nmake install"
cmd /c "cd visiClients\barchart\%PLATFORM% && nmake clean"
cmd /c "cd visiClients\barchart\%PLATFORM% && nmake install"
cmd /c "cd visiClients\tableVisi\%PLATFORM% && nmake clean"
cmd /c "cd visiClients\tableVisi\%PLATFORM% && nmake install"
cmd /c "cd visiClients\phaseTable\%PLATFORM% && nmake clean"
cmd /c "cd visiClients\phaseTable\%PLATFORM% && nmake install"
cmd /c "cd visiClients\tclVisi\%PLATFORM% && nmake clean"
cmd /c "cd visiClients\tclVisi\%PLATFORM% && nmake install"
rem No visiClients/terrain to build for WinNT!

cmd /c "cd dyninstAPI_RT\%PLATFORM% && nmake clean"
cmd /c "cd dyninstAPI_RT\%PLATFORM% && nmake install"
cmd /c "cd dyninstAPI\%PLATFORM% && nmake clean"
cmd /c "cd dyninstAPI\%PLATFORM% && nmake install"
cmd /c "cd dyninstAPI\tests\%PLATFORM% && nmake clean"
cmd /c "cd dyninstAPI\tests\%PLATFORM% && nmake install"
cmd /c "cd dyner\%PLATFORM% && nmake clean"
cmd /c "cd dyner\%PLATFORM% && nmake install"
