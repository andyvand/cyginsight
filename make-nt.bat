rem Script for building Paradyn & DynInstAPI on WinNT platform
@echo off
rem $Id: make-nt.bat,v 1.4 1998/04/03 22:45:26 wylie Exp $
@echo on

cmd /c "cd util\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd igen\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd rtinst\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd paradynd\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI_RT\%PLATFORM% && nmake clean && nmake install"
cmd /c "cd dyninstAPI\tests\%PLATFORM% && nmake clean && nmake install"

