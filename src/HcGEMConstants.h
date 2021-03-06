// Filename: HcGEMConstants.h
// Description: 
// Author: Latif Kabir < latif@jlab.org >
// Created: Tue Oct 24 01:35:05 2017 (-0400)
// URL: latifkabir.github.io


//Modify these path before compiling on new system
#define PATH_FOR_CONFIG "/home/siplu/GIT/JLAB/Public/GEM_DAQ/DataExplorer/config/gem.cfg"
#define PATH_FOR_MAPPING "/home/siplu/GIT/JLAB/Public/GEM_DAQ/DataExplorer/config/mapping.cfg"

#define NADC 6                 // Number of ADC
#define NTIME_BINS 21          // NUmber of time bins
#define N_STRIPS 128           // Number of strip of the GEM readout board
#define HEADER_CUTOFF 1500     // Header cutoff level
#define BLOCK_LENGTH 140       // 12 headers + 128 channels 
#define GEM_LENGTH 15.36       // 15.36 cm x 15.36 cm GEM


//---------- Hall C GEM Mapping -----------------------

#define X1_ADC_NO 2
#define X2_ADC_NO 0
#define X3_ADC_NO 1

#define Y1_ADC_NO 3
#define Y2_ADC_NO 5
#define Y3_ADC_NO 4



/*

GEM Coordinate System:

     Y1         Y2            Y3
     --------------------------> Y     HV Connector Here
X1   |
     |     
X2   |       Readout Board
     |
X3   |
    \|/
     X


Hall C Coordinate System:

 Beam left  Y<------------------------x Z (beam direction)
	                              |
				      |
				      |
				      |
				      |
				      |
				      |
				     \|/
				      X (Towards the floor) 


*/
