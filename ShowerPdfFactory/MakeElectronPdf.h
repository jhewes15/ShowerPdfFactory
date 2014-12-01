/**
 * \file MakeElectronPdf.h
 *
 * \ingroup ShowerPdfFactory
 * 
 * \brief Class def header for a class MakeElectronPdf
 *
 * @author jhewes15
 */

/** \addtogroup ShowerPdfFactory

    @{*/

#ifndef LARLITE_MAKEELECTRONPDF_H
#define LARLITE_MAKEELECTRONPDF_H

#include "Analysis/ana_base.h"
#include "Pi0PdfMaker.h"

namespace larlite {
  /**
     \class MakeElectronPdf
     User custom analysis class made by jhewes15
   */
  class MakeElectronPdf : public ana_base{
  
  public:

    /// Default constructor
    MakeElectronPdf(){ _name="MakeElectronPdf"; _fout=0;};

    /// Default destructor
    virtual ~MakeElectronPdf(){};

    /** IMPLEMENT in MakeElectronPdf.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in MakeElectronPdf.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in MakeElectronPdf.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:
    TTree* InputData;
    Pi0PdfMaker* Maker;
    double RadLen_x = 0;

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
