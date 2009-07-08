#!/bin/sh

[ $# == 2 ] || { echo "Usage: $0 dyninst_root target_dir"; exit;}
[ -d $1/dyninst ] || { echo "Error: cannot find dyninst directory"; exit;}
[ -d $1/scripts ] || { echo "Error: cannot find scripts directory"; exit;}
[ -d $2 ] || { echo "Error: $2 does not exist or is not a directory"; exit;}
[ -f $1/dyninstProgGuide.pdf ] || { echo "Error: cannot find dyninstProgGuide.pdf"; exit;}
[ -e /tmp/tmp-$$ ] && { "Error: /tmp/tmp-$$ exists"; exit;}

mkdir /tmp/tmp-$$
mkdir /tmp/tmp-$$/dyninst-6.0
cp -R $1/dyninst $1/scripts $1/dyninstProgGuide.pdf /tmp/tmp-$$/dyninst-6.0
find /tmp/tmp-$$/dyninst-6.0 -name .git | xargs rm -rf
find /tmp/tmp-$$/dyninst-6.0 -name .gitignore | xargs rm -rf
find /tmp/tmp-$$/dyninst-6.0 -name DyninstAPI.sln | xargs rm -rf
rm -f $2/dyninst-6.0.tar.gz
(cd /tmp/tmp-$$; tar fcz dyninst-6.0.tar.gz dyninst-6.0)
mv /tmp/tmp-$$/dyninst-6.0.tar.gz $2
rm -rf /tmp/tmp-$$
