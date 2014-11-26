#ifndef SAVEDATA_CXX
#define SAVEDATA_CXX

#include "SaveData.h"

namespace larlite {

  bool SaveData::initialize() {

    Maker = new Pi0PdfMaker();
    InputData = new TTree("./SaveData.root","RECREATE");
    InputData->Branch("RadLen_x",&RadLen_x);
    
    Maker->RadLenPdf(0,100,-1,-0.001);
    
    return true;
  }
  
  bool SaveData::analyze(storage_manager* storage) {
  
    auto shower = storage->get_data<event_mcshower>("mcreco");
    
    for (auto const &c : *shower) {
      RadLen_x = sqrt(pow(c.Start().X()-c.DetProfile().X(),2)+pow(c.Start().Y()-c.DetProfile().Y(),2)+pow(c.Start().Z()-c.DetProfile().Z(),2));
      
      InputData->Fill();
    }
    
    return true;
  }

  bool SaveData::finalize() {

    int n = InputData->GetEntries();
    for (int i = 0; i < n; i++) {
      InputData->GetEntry(i);
      std::cout << RadLen_x << std::endl;
    }
    
    Maker->RadLenFit(InputData);
    Maker->Save();
    Maker->RadLenPlot();
    
    InputData->Write();
  
    return true;
  }

}
#endif
