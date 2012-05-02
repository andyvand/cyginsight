#!/bin/sh

TMP_DIR=/tmp/tmp-$$
DOC_FILES="docs/stackwalk/stackwalker.pdf docs/symtabAPI/symtabProgGuide.pdf"

[ $# == 2 ] || { echo "Usage: $0 dyninst_src_root target_dir"; exit; }
#check the git repos exist and have no uncommited changes
for i in dyninst scripts docs; do
    [ -d $1/$i ] || { echo "Error: cannot find $i directory"; exit; }
    cd $1/$i; git status | grep -q working.directory.clean || { echo "You should commit and push your changes in $i before '$0'."; exit; }
done
[ -d $2 ] || { echo "Error: $2 does not exist or is not a directory"; exit;}

# Determine the version
RELEASE_NUM=`grep RELEASE_NUM $1/dyninst/make.config | grep -o \[0-9.\]*`
TAR_DIR=dyninst-${RELEASE_NUM}
TAR_FILE=${TAR_DIR}.tar.gz

[ -e $TMP_DIR ] && { "Error: $TMP_DIR exists"; exit;}

mkdir -p $TMP_DIR/$TAR_DIR

# Copy source files
# Use git archive to export files
for i in dyninst scripts; do
    cd $1/$i; git archive --format=tar --prefix=${i}/ HEAD | (cd $TMP_DIR/$TAR_DIR && tar xpf -)
done
# Copy the documentation
cp -R $1/docs/*.pdf $TMP_DIR/$TAR_DIR
for i in $DOC_FILES; do
    cp $1/$i $TMP_DIR/$TAR_DIR
done

#do cleanup
find $TMP_DIR/$TAR_DIR -name .gitignore | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -name DyninstAPI.sln | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -type d -name i386-unknown-winXP | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -type d -name sparc-sun-solaris2.8 | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -type d -name sparc-sun-solaris2.9 | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -type d -name rs6000-ibm-aix5.1 | xargs rm -rf
#find $TMP_DIR/$TAR_DIR -type d -name rs6000-ibm-aix64-5.2 | xargs rm -rf

rm -f $2/$TAR_FILE
(cd $TMP_DIR; tar cpfz $TAR_FILE $TAR_DIR)
mv $TMP_DIR/$TAR_FILE $2
rm -rf $TMP_DIR

echo "Generated $2/$TAR_FILE."