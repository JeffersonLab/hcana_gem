#include "GEMPhysics.h"
#include <iostream>
#include "GEMPedestal.h"
#include "GEMMapping.h"
#include "GEMOnlineHitDecoder.h"
#include "GEMSignalFitting.h"
#include <TCanvas.h>
#include "GEMTree.h"
#include "GEMCoord.h"

//#define PROD_GEM_OFFSET

using namespace std;

GEMPhysics::GEMPhysics()
{
    cout<<"GEMPhysics Constructor..."
        <<endl;
    mapping = GEMMapping::GetInstance();
    fGEMDataProcessor = new THcGEMDataProcessor();
    fHcGEMPhysics = new THcGEMPhysics();
}

GEMPhysics::~GEMPhysics()
{
}

void GEMPhysics::SetGEMPedestal(GEMPedestal *ped)
{
    pedestal = ped;
    pedestal -> LoadPedestal();

    hit_decoder = new GEMOnlineHitDecoder();
    hit_decoder -> SetPedestal(pedestal);

    sig_fitting = new GEMSignalFitting();
    sig_fitting->SetGEMOnlineHitDecoder(hit_decoder);

    gem_coord = new GEMCoord();
    gem_coord -> SetHitDecoder(hit_decoder);
}

void GEMPhysics::SetGEMConfigure(GEMConfigure *c)
{
    config = c;

    hit_decoder -> SetGEMConfigure(config);
}

void GEMPhysics::SetGEMTree(GEMTree *tree)
{
    rst_tree = tree;
}

void GEMPhysics::AccumulateEvent(int evtID, std::unordered_map<int, std::vector<int> > event)
{
    //cout<<"event number from gem: "<<evtID<<endl;
    SetEvtID( evtID );
    // -------------- Hall C GEM implementation -----------------
    bool hasGEMData = false;
    hasGEMData = fGEMDataProcessor->ProcessEvent(event);
    if(!hasGEMData)
    {
	fHcGEMPhysics->ResetCoordinate();
	CharactorizeGEM();
	return;
    }
	
    fHcGEMPhysics->RegisterBuffer(fGEMDataProcessor->GetProcessedData());

    fHcGEMPhysics->FillRawCoordinate();	
    if(fHcGEMPhysics->fRawCoord.size() != 2) // For now lets consider only pair of clusters
	fHcGEMPhysics->ResetCoordinate();
    else
    {
	fHcGEMPhysics->ComputeCoordinate();
	if(fHcGEMPhysics->fGEM_Coord.X == -1 || fHcGEMPhysics->fGEM_Coord.Y == -1) // Discard double hits on same axis
	    fHcGEMPhysics->ResetCoordinate();
    }

    CharactorizeGEM();
}

void GEMPhysics::CharactorizeGEM()
{
    // int n = mapping->GetNbOfDetectors();

    // vector<GEMClusterStruct> gem;
    // for(int i=0;i<n;i++)
    // {
    // 	gem.clear();
    // 	gem_coord->GetClusterGEM(i, gem);
    // 	rst_tree -> PushDetector(i, gem);
    // }
    rst_tree -> PushCoordinate(fHcGEMPhysics->fGEM_Coord);
    rst_tree -> FillGEMTree();
}

void GEMPhysics::CharactorizePhysics()
{
    //#ifndef PROD_GEM_OFFSET
    CharactorizePlanePhysics();
    //#else
    CharactorizeOverlapPhysics();
    //#endif
}

void GEMPhysics::CharactorizePlanePhysics()
{
    gem_coord -> SetGEMOffsetX(0.);
    gem_coord -> SetGEMOffsetY(0.);

    // place holer
}

void GEMPhysics::CharactorizeOverlapPhysics()
{
    gem_coord -> SetGEMOffsetX(0.);
    gem_coord -> SetGEMOffsetY(0.);

    // place holer
}

void GEMPhysics::SavePhysResults()
{
    //rst_tree->WriteToDisk();
    sig_fitting->Write();
}

void GEMPhysics::SetEvtID(unsigned int id)
{
    evt_id = id;
}

unsigned int GEMPhysics::GetEvtID()
{
    return evt_id;
}

