// Filename: THcGEMPhysics.h
// Description: 
// Author: Latif Kabir < latif@jlab.org >
// Created: Tue Oct 24 23:46:08 2017 (-0400)
// URL: jlab.org/~latif

#ifndef THCGEMPHYSICS_H
#define THCGEMPHYSICS_H

#include <iostream>
#include <vector>
#include "TObject.h"

using namespace std;

struct RawCoordinate
{
    Int_t adcNo;
    Int_t stripNo;
    Int_t ADCValue;
};

struct GEMCoordinate
{
    Double_t X;
    Double_t Y;
    Int_t charge_x;
    Int_t charge_y;	
};

class THcGEMPhysics : public TObject
{
    Int_t ***fProcessedData;
    Int_t fEventNumber;
public:

    void RegisterBuffer(Int_t ***processedData);
    void FillRawCoordinate();
    void ComputeCoordinate();
    Bool_t FitCluster(Int_t adc, Int_t tbin, Int_t strip);
    void PlotGEMCoord();
    void SetEventNumber(Int_t eventNumber);
    GEMCoordinate GetGEMCoordinate();
    void ResetCoordinate();
    
    RawCoordinate fCoord;
    std::vector <RawCoordinate> fRawCoord;
    GEMCoordinate fGEM_Coord;
    
    void Init();
    THcGEMPhysics();
    ~THcGEMPhysics();
    ClassDef(THcGEMPhysics,0)
};

#endif
