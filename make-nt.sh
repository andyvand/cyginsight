#!/bin/sh
# Paradyn/DyninstAPI build script for WinNT platform
# $Id: make-nt.sh,v 1.12 2000/10/17 17:10:08 schendel Exp $
# usage: make-nt [-no] [-new|-clean] [componentlist]

# Note: these IDs are only used for local purposes!  Real IDs are in makefiles.
PARADYN_BUILD_ID="Paradyn v3.1"
DYNINST_BUILD_ID="Dyninst v2.2"

MAKE="nmake /nologo"
PARADYN_VISIS="visiClients/histVisi visiClients/barchart visiClients/tableVisi visiClients/phaseTable visiClients/tclVisi"
PARADYN_COMPS="pdutil pdutilOld igen rtinst paradynd thread paradyn visi $PARADYN_VISIS"
DYNINST_COMPS="dyninstAPI dyninstAPI_RT dyninstAPI/tests dyner"
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
      Dyninst*)
        BUILD_ID=$DYNINST_BUILD_ID
        COMPS=$DYNINST_COMPS
        TITLE=Dyninst
        ;;
      *)
        COMPS=$*
        TITLE=
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
CORE_DIR=`pwd`
echo "Build in $CORE_DIR"
for COMP in $COMPS
do
    MODULE_DIR=$CORE_DIR/$COMP/$PLATFORM
    if [ ! -d $MODULE_DIR ]; then
        echo "Target directory $COMP/$PLATFORM does not exist!"
        continue
    fi
    cd \\$MODULE_DIR
    echo "Entering $MODULE_DIR"
    if [ "$CLEANOPT" = "TRUE" ]; then
        $MAKE clean
    fi
    if [ "$BUILDOPT" = "TRUE" ]; then
        $MAKE install
        if [ "$?" != 0 ]; then
            echo "Aborting $COMP"
            exit
        fi
    fi
    echo "Leaving  $MODULE_DIR"
done
echo "$BUILD_ID build complete for $PLATFORM!"
date

