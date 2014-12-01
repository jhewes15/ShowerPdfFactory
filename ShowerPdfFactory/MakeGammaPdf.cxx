#ifndef MAKEGAMMAPDF_CXX
#define MAKEGAMMAPDF_CXX

#include "MakeGammaPdf.h"

namespace larlite {

  bool MakeGammaPdf::initialize() {

    Maker = new Pi0PdfMaker();
    InputData = new TTree("InputData","Data tree");
    InputData->Branch("RadLen_x",&RadLen_x);
    
    Maker->RadLenPdf(0,100,-0.1,-0.01);

    return true;
  }
  
  bool MakeGammaPdf::analyze(storage_manager* storage) {
      
    auto shower = storage->get_data<event_mcshower>("mcreco");
      
    for (auto const &c : *shower) {
      RadLen_x = sqrt(pow(c.Start().X()-c.DetProfile().X(),2)+pow(c.Start().Y()-c.DetProfile().Y(),2)+pow(c.Start().Z()-c.DetProfile().Z(),2));
        
      InputData->Fill();
    }
  
    return true;
  }

  bool MakeGammaPdf::finalize() {

    Maker->RadLenFit(InputData);
    Maker->Save();
    Maker->RadLenPlot();
  
    return true;
  }

}
#endif
