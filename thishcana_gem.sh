#!/bin/bash

###  Adopted from hcana setup.sh with minor tweak -- Latif
###


HCANA_GEM_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HCANA_GEM_DIR/lib
