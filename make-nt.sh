#!/bin/sh
# Paradyn/DynInstAPI build script for WinNT platform
# $Id: make-nt.sh,v 1.5 1999/02/09 15:57:44 wylie Exp $
# usage: make-nt [-no] [-new|-clean] [componentlist]

# Note: these IDs are only used for local purposes!  Real IDs are in makefiles.
PARADYN_BUILD_ID="Paradyn v2.1"
DYNINST_BUILD_ID="DynInst v1.2"

MAKE="nmake /nologo"
PARADYN_COMPS="util igen rtinst paradynd"
DYNINST_COMPS="dyninstAPI dyninstAPI_RT dyninstAPI/tests"
ALL_COMPS="$PARADYN_COMPS $DYNINST_COMPS"
LIBRARY_DEST=../lib/$PLATFORM
PROGRAM_DEST=../bin/$PLATFORM

BUILDOPT=TRUE

if [ "$1" = "-no" ]; then
    MAKE="$MAKE -n"
    echo MAKE=$MAKE
    shift
fi

if [ "$1" = "-new" ]; then
    CLEANOPT=TRUE
    shift
fi

if [ "$1" = "-clean" ]; then
    CLEANOPT=TRUE
    BUILDOPT=FALSE
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

if [ ! -d $LIBRARY_DEST ]; then
    echo "Creating installation directory LIBRARY_DEST=$LIBRARY_DEST"
    mkdir -p $LIBRARY_DEST
fi
if [ ! -d $PROGRAM_DEST ]; then
    echo "Creating installation directory PROGRAM_DEST=$PROGRAM_DEST"
    mkdir -p $PROGRAM_DEST
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
    if [ "$BUILDOPT" = "TRUE" ]; then
        $MAKE install
        if [ "$?" != 0 ]; then
            echo "Aborting $CWD"
            exit
        fi
    fi
    echo "Leaving  $CWD"
    cd ../..
done
echo "$BUILD_ID build complete for $PLATFORM!"
date

