/**
 * \file MakeGammaPdf.h
 *
 * \ingroup ShowerPdfFactory
 * 
 * \brief Class def header for a class MakeGammaPdf
 *
 * @author jhewes15
 */

/** \addtogroup ShowerPdfFactory

    @{*/

#ifndef LARLITE_MAKEGAMMAPDF_H
#define LARLITE_MAKEGAMMAPDF_H

#include "Analysis/ana_base.h"
#include "Pi0PdfMaker.h"

namespace larlite {
  /**
     \class MakeGammaPdf
     User custom analysis class made by jhewes15
   */
  class MakeGammaPdf : public ana_base{
  
  public:

    /// Default constructor
    MakeGammaPdf(){ _name="MakeGammaPdf"; _fout=0;};

    /// Default destructor
    virtual ~MakeGammaPdf(){};

    /** IMPLEMENT in MakeGammaPdf.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in MakeGammaPdf.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in MakeGammaPdf.cc! 
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
