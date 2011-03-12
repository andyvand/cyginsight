#!/bin/sh

TMP_DIR=/tmp/tmp-$$
TAR_DIR=dyninst-7.0
TAR_FILE=dyninst-7.0.tar.gz

[ $# == 2 ] || { echo "Usage: $0 dyninst_root target_dir"; exit;}
[ -d $1/dyninst ] || { echo "Error: cannot find dyninst directory"; exit;}
[ -d $1/scripts ] || { echo "Error: cannot find scripts directory"; exit;}
[ -d $2 ] || { echo "Error: $2 does not exist or is not a directory"; exit;}
[ -e $TMP_DIR ] && { "Error: $TMP_DIR exists"; exit;}

mkdir $TMP_DIR
mkdir $TMP_DIR/$TAR_DIR
cp -R $1/dyninst $1/scripts $1/*.pdf $TMP_DIR/$TAR_DIR
for i in $DOC_FILES; do
    cp $1/$i $TMP_DIR/$TAR_DIR
done
find $TMP_DIR/$TAR_DIR -name .git | xargs rm -rf
find $TMP_DIR/$TAR_DIR -name .gitignore | xargs rm -rf
find $TMP_DIR/$TAR_DIR -name DyninstAPI.sln | xargs rm -rf
find $TMP_DIR/$TAR_DIR -type d -name i386-unknown-winXP | xargs rm -rf
find $TMP_DIR/$TAR_DIR -type d -name sparc-sun-solaris2.8 | xargs rm -rf
find $TMP_DIR/$TAR_DIR -type d -name sparc-sun-solaris2.9 | xargs rm -rf
find $TMP_DIR/$TAR_DIR -type d -name rs6000-ibm-aix5.1 | xargs rm -rf
find $TMP_DIR/$TAR_DIR -type d -name rs6000-ibm-aix64-5.2 | xargs rm -rf

rm -f $2/$TAR_FILE
(cd $TMP_DIR; tar fcz $TAR_FILE $TAR_DIR)
mv $TMP_DIR/$TAR_FILE $2
rm -rf $TMP_DIR
