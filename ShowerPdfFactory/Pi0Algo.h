/**
 * \file Pi0Algo.h
 *
 * \ingroup ShowerPdfFactory
 * 
 * \brief Class def header for a class Pi0Algo
 *
 * @author jhewes15
 */

/** \addtogroup ShowerPdfFactory

    @{*/

#ifndef LARLITE_PI0ALGO_H
#define LARLITE_PI0ALGO_H

#include "Analysis/ana_base.h"
#include "Pi0PdfMaker.h"

namespace larlite {
  /**
     \class Pi0Algo
     User custom analysis class made by jhewes15
   */
  class Pi0Algo : public ana_base{
  
  public:

    Pi0Algo(){ _name="Pi0Algo"; _fout=0;};
    virtual ~Pi0Algo(){};
    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

  protected:

    Pi0PdfMaker* Maker;
    RooAbsPdf* DistancePdf;
    TH1* RadLenHist;
    RooAbsData* RadLenData;
    TCanvas* c;
    double x_min = 0;
    double x_max = 100;
    double lambda_min = -0.05;
    double lambda_max = -0.1;
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
