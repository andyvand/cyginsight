#!/bin/sh
# Paradyn/DynInstAPI build script for WinNT platform
# $Id: make-nt.sh,v 1.1 1998/04/06 16:09:33 wylie Exp $
# usage: make-nt [-new] [componentlist]

# Note: these IDs are only used for local purposes!  Real IDs are in makefiles.
PARADYN_BUILD_ID="Paradyn v2.1"
DYNINST_BUILD_ID="DynInst v1.1"

MAKE="nmake /nologo"
PARADYN_COMPS="util igen rtinst paradynd"
DYNINST_COMPS="dyninstAPI dyninstAPI_RT dyninstAPI/tests"
ALL_COMPS="$PARADYN_COMPS $DYNINST_COMPS"
LIBRARY_DEST=../lib/$PLATFORM
PROGRAM_DEST=../bin/$PLATFORM

if [ "$1" = "-new" ]; then
    CLEANOPT=TRUE
    shift
fi

BUILD_ID=$PARADYN_BUILD_ID

if [ -z "$*" ]; then
    COMPS=$ALL_COMPS
    TITLE=world
else
    case "$1" in
      Paradyn)
        COMPS=$PARADYN_COMPS
        TITLE=Paradyn
        ;;
      DynInst*)
        BUILD_ID=$DYNINST_BUILD_ID
        COMPS=$DYNINST_COMPS
        TITLE=DynInst
        ;;
      *)
        COMPS=$*
        ;;
    esac
fi

PATH="\
//P/paradyn/development/$USER/bin/$PLATFORM/:\
//P/paradyn/bin/$PLATFORM/:\
/Program Files/DevStudio/VC/bin/:\
/Program Files/DevStudio/SharedIDE/bin/:\
//E/GNU/gnuwin32/b18/H-i386-cygwin32/bin/:\
/bin/\
"

if [ ! -d $LIBRARY_DEST ]; then
    mkdir $LIBRARY_DEST
fi
if [ ! -d $PROGRAM_DEST ]; then
    mkdir $PROGRAM_DEST
fi

echo "Making $BUILD_ID $TITLE for $PLATFORM!"
date
for COMP in $COMPS
do
    if [ ! -d $COMP/$PLATFORM ]; then
        echo "Target directory $COMP/$PLATFORM does not exist!"
        continue
    fi
    cd $COMP/$PLATFORM
    CWD=`pwd`
    echo "Entering $CWD"
    if [ "$CLEANOPT" = "TRUE" ]; then
        $MAKE clean
    fi
    $MAKE install
    if [ "$?" != 0 ]; then
        exit
    fi
    echo "Leaving  $CWD"
    cd ../..
done
echo "$BUILD_ID build complete for $PLATFORM!"
date

