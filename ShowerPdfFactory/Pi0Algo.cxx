#ifndef PI0ALGO_CXX
#define PI0ALGO_CXX

#include "Pi0Algo.h"

namespace larlite {

  bool Pi0Algo::initialize() {
    
    std::cout << "Initialise stage beginning..." << std::endl;
    
    Maker = new Pi0PdfMaker();
    RadLenHist = new TH1D("RadLenHist","Data histogram",50,x_min,x_max);
    Maker->RadLenPdf(x_min,x_max,lambda_min,lambda_max);

    std::cout << "Initialise stage complete." << std::endl;
    
    return true;
  }
  
  bool Pi0Algo::analyze(storage_manager* storage) {
    
    auto shower = storage->get_data<event_mcshower>("mcreco");

    for (auto const &c : *shower) {
      double d = sqrt(pow(c.Start().X()-c.DetProfile().X(),2)+pow(c.Start().Y()-c.DetProfile().Y(),2)+pow(c.Start().Z()-c.DetProfile().Z(),2));
      RadLenHist->Fill(d);
    }

    return true;
  }

  bool Pi0Algo::finalize() {

    std::cout << "Finalise stage beginning..." << std::endl;
    
    Maker->RadLenData(RadLenHist);
    Maker->RadLenFit();
    Maker->RadLenPlot();
    
    std::cout << "Finalise stage complete." << std::endl;
  
    return true;
  }

}
#endif
