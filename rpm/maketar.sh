#!/bin/sh

[ $# == 2 ] || { echo "Usage: $0 dyninst_root target_dir"; exit;}
[ -d $1/core ] || { echo "Error: cannot find core directory"; exit;}
[ -d $1/scripts ] || { echo "Error: cannot find scripts directory"; exit;}
[ -d $2 ] || { echo "Error: $2 does not exist or is not a directory"; exit;}
[ -f $1/dyninstProgGuide.pdf ] || { echo "Error: cannot find dyninstProgGuide.pdf"; exit;}
[ -f $1/dynerGuide.pdf ] || { echo "Error: cannot find dynerGuide.pdf"; exit;}
[ -e /tmp/tmp-$$ ] && { "Error: /tmp/tmp-$$ exists"; exit;}

mkdir /tmp/tmp-$$
mkdir /tmp/tmp-$$/dyninst-5.0
cp -R $1/core $1/scripts $1/dyninstProgGuide.pdf $1/dynerGuide.pdf /tmp/tmp-$$/dyninst-5.0
find /tmp/tmp-$$/dyninst-5.0 -name CVS | xargs rm -rf
rm -f $2/dyninst-5.0.tar.gz
(cd /tmp/tmp-$$; tar fcz dyninst-5.0.tar.gz dyninst-5.0)
mv /tmp/tmp-$$/dyninst-5.0.tar.gz $2
rm -rf /tmp/tmp-$$
