//==================================================================//
//                                                                  //
// Xinzhan Bai                                                      //
// 02/10/2017                                                       //
// xb4zp@virginia.edu                                               //
//==================================================================//

#ifndef SIGNAL_FITTING_h
#define SIGNAL_FITTING_h

#include <vector>

class GEMOnlineHitDecoder;
class GEMHit;
class GEMCluster;

class GEMSignalFitting
{
public:
    GEMSignalFitting();
    ~GEMSignalFitting();

    void SetGEMOnlineHitDecoder(GEMOnlineHitDecoder* decoder);

    void Fit();
    void SetTSADC();
    void FitGraph(const std::vector<double> &);


private:
    GEMOnlineHitDecoder *hit_decoder;

    std::vector<double> hit_ts_adc;
    std::vector<double> cluster_ts_adc;
};

#endif
