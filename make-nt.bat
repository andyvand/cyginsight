rem Script for building Paradyn & DynInstAPI on WinNT platform
@echo off
rem $Id: make-nt.bat,v 1.5 1998/04/24 18:10:02 wylie Exp $
@echo on

set LIBRARY_DEST="..\lib"
set PROGRAM_DEST="..\bin"

if not exist %LIBRARY_DEST% mkdir %LIBRARY_DEST%
if not exist %LIBRARY_DEST%\%PLATFORM% mkdir %LIBRARY_DEST%\%PLATFORM%
if not exist %PROGRAM_DEST% mkdir %PROGRAM_DEST%
if not exist %PROGRAM_DEST%\%PLATFORM% mkdir %PROGRAM_DEST%\%PLATFORM%

cmd /c "cd util\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd igen\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd rtinst\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd paradynd\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI_RT\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\tests\%PLATFORM% && nmake clean && nmake install"
