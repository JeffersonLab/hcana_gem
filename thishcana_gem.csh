#!/bin/csh

set called=($_)
if ("$called" != "") then
  set scriptdir=$called[2]
  set HCANA_GEM_DIR=`dirname $scriptdir`
  set HCANA_GEM_DIR=`c\d $HCANA_GEM_DIR && pwd`    # ensure absolute path
else
  set scriptdir=$1
  set HCANA_GEM_DIR=$scriptdir
endif
setenv LD_LIBRARY_PATH "${LD_LIBRARY_PATH}:${HCANA_GEM_DIR}/lib"
