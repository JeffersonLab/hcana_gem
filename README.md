hcana_gem - Analyze SHMS Active Sieve slit data
===============================================

This is an hcana event handler that is used to analyze GEM data that is
part of the SHMS data.

To compile, first install and compile an up to data copy of hcana and
source the setup.sh or setup.csh script in hcana.

Go to the src directory of this repo to compile the GEM analysis code
with "make."

This will build a module libGEM.so.

To do an analysis that includes the GEM, add the following to the replay
script, correcting paths and spectrometer apparatuses as needed:

  THcGEM* gem = new THcGEM("gem","GEM data");
  gem->SetConfigFile("../hcana_gem/config/gem_hcana.cfg");
  SHMS->AddDetector(gem);

At the top of your replay script add these lines:

R__ADD_LIBRARY_PATH(../GEM_Offline_Program/src)
R__LOAD_LIBRARY(libGEM.so);

again, adjusting the library path as needed.


