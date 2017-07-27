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
script, correcting paths and event types as needed:

  GEMEvtHandler* gem = new GEMEvtHandler("GEM","GEM data");
  gem->SetEvtType(1);
  gem->SetConfigFile("../hcana_gem/config/gem_hcana.cfg");
  gHaEvtHandlers->Add(gem);

After starting hcana, but before running the replay script, load the GEM
analysis software with:

  gSystem->Load("../hcana_gem/src/libGEM.so");

