// Filename: THcGEMPhysics.cc
// Description: 
// Author: Latif Kabir < latif@jlab.org >
// Created: Wed Oct 25 00:11:08 2017 (-0400)
// URL: jlab.org/~latif

#include"THcGEMPhysics.h"
#include "TGraph.h"
#include "TF1.h"
#include "TString.h"
#include "HcGEMConstants.h"

ClassImp(THcGEMPhysics)
//Constructor
THcGEMPhysics::THcGEMPhysics()
{
    fEventNumber = -1;
}

//Destructor
THcGEMPhysics::~THcGEMPhysics()
{
    
}
// Set pointer to processed data
void THcGEMPhysics::RegisterBuffer(Int_t ***processedData)
{
    fProcessedData = processedData;
}

// Accumulate raw coordinate
void THcGEMPhysics::FillRawCoordinate()
{
    Int_t cutOffPrimary = 400;
    Int_t cutOffSecondary = 250;
    Double_t sigma;
    Double_t ratio;
    Bool_t status;
        
    Int_t previousVal;
    Int_t presentVal;
    Bool_t clusterFound = false;

    Int_t tbin_;
    Int_t strip_;
    
    fRawCoord.clear();
    
    for(Int_t adc = 0; adc < NADC; ++adc)
    {
	clusterFound = false;
	for(Int_t tbin = 0; tbin < (NTIME_BINS -3); ++tbin)
	{
	    for(Int_t strip = 0; strip < N_STRIPS; ++strip)
	    {
		tbin_ = tbin;
		strip_ = strip;

		if(fProcessedData[adc][tbin_][strip_]<cutOffSecondary)
		    continue;

		previousVal = fProcessedData[adc][tbin_][strip_];
		presentVal = fProcessedData[adc][tbin_][strip_];
		
		while(presentVal>=previousVal)
		{
		    if(strip_ >= (N_STRIPS - 1))
			break;
		    ++strip_;
		    previousVal = presentVal;
		    presentVal = fProcessedData[adc][tbin_][strip_];
		}
		if(strip_>0)
		    --strip_;
		presentVal = fProcessedData[adc][tbin_][strip_];
		previousVal = presentVal;
		
		while(presentVal>=previousVal)
		{
		    if(tbin_ >= (NTIME_BINS - 4))
			break;
		    ++tbin_;
		    previousVal = presentVal;
		    presentVal = fProcessedData[adc][tbin_][strip_];
		}
		if(tbin_>0)
		    --tbin_;
		presentVal = fProcessedData[adc][tbin_][strip_];

		if(presentVal > cutOffSecondary && presentVal < cutOffPrimary)
		{
		    status = FitCluster(adc,tbin_,strip_);
		    if(!status)
			continue;
		}

		fCoord.adcNo = adc;
		fCoord.stripNo = strip_;
		fCoord.ADCValue = presentVal;
		clusterFound = true;
		fRawCoord.push_back(fCoord);
		// cout << "Found GEM Cluster !!! Event: "<< fEventNumber <<"\t ADC: "<<coord.adcNo<<"\t Strip no."<<coord.stripNo<<"\t ADC value: "<< coord.ADCValue<<endl;
		break;  //<------------- Assume we will have single track events only
	    }
	    if(clusterFound)
		break;
	}
    }
}

//------------ Fit the signal to check if it's a GEM signal ------
Bool_t THcGEMPhysics:: FitCluster(Int_t adc, Int_t tbin, Int_t strip)
{
    //TCanvas *c2 = new TCanvas();
    TGraph gr;
    TString title = "GEM Event: ";
    title += fEventNumber;
    title += " ADC: ";
    title += adc;
    gr.SetTitle(title);
    Int_t point = 0;
    for (Int_t i = tbin - 2; i < tbin + 9; i++) 
    {
	if(i>= NTIME_BINS || i <0)
	    continue;	
	gr.SetPoint(point, i, fProcessedData[adc][i][strip]);
	++point;
    }
    gr.Fit("landau","Q");
    TF1 *f1 = gr.GetFunction("landau");
    // cout << f1->GetParameter(0) << "\t"<<f1->GetParError(0)<<endl;
    // cout << f1->GetParameter(1) <<endl;
    // Double_t sigma = f1->GetParameter(2);
    // cout << sigma <<endl;
    Double_t ratio0 = f1->GetParError(0) / f1->GetParameter(0);
    Double_t ratio1 = f1->GetParError(1) / f1->GetParameter(1);
    Double_t ratio2 = f1->GetParError(2) / f1->GetParameter(2);
    Double_t ratio3 = f1->GetChisquare() / f1->GetNDF();

    // cout << ratio0 << "\t" <<ratio1 << "\t" << ratio2 << "\t" <<ratio3 <<endl;

    
    //gStyle->SetOptFit();
    // gr.Draw("AP*");

    // c2->Update();
    // c2->SaveAs("test.pdf");
    
    if(ratio0 > 0.1 || ratio1 > 0.1 || ratio2 > 0.1 || ratio3 > 3000.0 || f1->GetParameter(1) < 0)
	return false;
    else
	return true;
}

void THcGEMPhysics:: ComputeCoordinate()
{
    ResetCoordinate();
    const Double_t length = GEM_LENGTH;
    const Double_t stripNoToCm = length/(3.0*N_STRIPS);

    Int_t X1 = 0;
    Int_t X2 = 1;
    Int_t X3 = 2;
    Int_t Y1 = 0;
    Int_t Y2 = 1;
    Int_t Y3 = 2;
    
    for(RawCoordinate rc : fRawCoord)
    {     
	//----------- Last level (APV orientation) of mapping correction happes here ------- 
        // The GEM coordinate is also transformed to align the axes with Hall C transport coordinate system
	 switch (rc.adcNo)
	 {
	   case X1_ADC_NO:
	     fGEM_Coord.X = X1*(Double_t)N_STRIPS*stripNoToCm + (N_STRIPS - rc.stripNo - 1)*stripNoToCm;
	     fGEM_Coord.charge_x = rc.ADCValue;
	     break;
	   case X2_ADC_NO:
	     fGEM_Coord.X = X2*(Double_t)N_STRIPS*stripNoToCm + (N_STRIPS - rc.stripNo - 1)*stripNoToCm;
	     fGEM_Coord.charge_x = rc.ADCValue;
	     break;
	   case X3_ADC_NO:
	     fGEM_Coord.X = X3*(Double_t)N_STRIPS*stripNoToCm + (N_STRIPS - rc.stripNo - 1)*stripNoToCm;
	     fGEM_Coord.charge_x = rc.ADCValue;
	     break;
	   case Y1_ADC_NO:
	     fGEM_Coord.Y = Y1*(Double_t)N_STRIPS*stripNoToCm + (rc.stripNo + 1)*stripNoToCm;
	     fGEM_Coord.Y = length - fGEM_Coord.Y;
	     fGEM_Coord.charge_y = rc.ADCValue;
	     break;
	   case Y2_ADC_NO:
	     fGEM_Coord.Y = Y2*(Double_t)N_STRIPS*stripNoToCm + (rc.stripNo + 1)*stripNoToCm;
	     fGEM_Coord.Y = length - fGEM_Coord.Y;
	     fGEM_Coord.charge_y = rc.ADCValue;
	     break;
	   case Y3_ADC_NO:
	     fGEM_Coord.Y = Y3*(Double_t)N_STRIPS*stripNoToCm + (rc.stripNo + 1)*stripNoToCm;
	     fGEM_Coord.Y = length - fGEM_Coord.Y;
	     fGEM_Coord.charge_y = rc.ADCValue;
	     break;
	}
    }    
}

void THcGEMPhysics::ResetCoordinate()
{
    fGEM_Coord.X = -1.0;
    fGEM_Coord.Y = -1.0;
    fGEM_Coord.charge_x = -1;
    fGEM_Coord.charge_y = -1;    
}
void THcGEMPhysics::SetEventNumber(Int_t eventNumber)
{
    fEventNumber = eventNumber;
}
