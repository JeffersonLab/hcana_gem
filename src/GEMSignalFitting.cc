#include "GEMSignalFitting.h"
#include "GEMOnlineHitDecoder.h"
#include "GEMHit.h"
#include "GEMCluster.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TFile.h"
#include <map>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

GEMSignalFitting::GEMSignalFitting()
{
}

GEMSignalFitting::~GEMSignalFitting()
{
}


void GEMSignalFitting::Fit()
{
    SetTSADC();
}


void GEMSignalFitting::SetGEMOnlineHitDecoder(GEMOnlineHitDecoder* d)
{
    hit_decoder = d;
}


void GEMSignalFitting::SetTSADC()
{
    hit_ts_adc.clear();
    cluster_ts_adc.clear();

    map<TString, list<GEMHit*>>* mhit 
	= hit_decoder->GetListOfHitsCleanFromPlanes();

    map<TString, list<GEMCluster*>>* mcluster 
	= hit_decoder->GetListOfClustersCleanFromPlane();

    // hit adc vs time bin
    for(auto &i: *mhit)
    {
        //cout<<"Plane: "<<i.first<<endl;
	for(auto &j: i.second)
	{
	    vector<double> time_bin_adc;

	    for(auto &k: j->GetTimeBinADCs()){
	        //cout<<"time bin: "<<k.first<<", adc: "<<k.second<<endl;
		time_bin_adc.push_back(k.second);
	    }

	    FitGraph(time_bin_adc);
	    //cout<<"next strip: "<<endl;
	}
    }

    // cluster adc vs time bin
    for(auto &i: *mcluster)
    {
        //cout<<"Plane: "<<i.first<<endl;
	for(auto &j: i.second){

	    int z = 0;
	    for(auto &k: j->GetClusterTimeBinADCs()){
	        //cout<<"time bin: "<<z<<", adc: "<<k<<endl;
		z++;
	    }
	}
    }

    //getchar();
}

void GEMSignalFitting::FitGraph(const vector<double> & v)
{
    int N = v.size();

    double x[N];
    double y[N];

    //cout<<"time bins: "<<N<<endl;

    for(int i=0;i<N;i++)
    {
        x[i] = 25*i;
	y[i] = v[i];
    }

    //TFile *f = new TFile("f.root", "recreate");
    //TCanvas *c = new TCanvas("c", "c", 10, 10, 800, 600);
    //TGraph *g = new TGraph(N, x, y);
    //g->Draw("APL*");
    //c->Modified();
    //c->Update();
    //c->Write();
    //cout<<"enter to contiue..."<<endl;
    //f->Close();
    //getchar();
    //delete c;
    //delete g;
}
