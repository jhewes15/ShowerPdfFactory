/**
 * \file SaveData.h
 *
 * \ingroup ShowerPdfFactory
 * 
 * \brief Class def header for a class SaveData
 *
 * @author jhewes15
 */

/** \addtogroup ShowerPdfFactory

    @{*/

#ifndef LARLITE_SAVEDATA_H
#define LARLITE_SAVEDATA_H

#include "Analysis/ana_base.h"
#include "Pi0PdfMaker.h"
#include "TTree.h"

namespace larlite {
  /**
     \class SaveData
     User custom analysis class made by jhewes15
   */
  class SaveData : public ana_base{
  
  public:

    SaveData(){ _name="SaveData"; _fout=0;};
    virtual ~SaveData(){};
    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
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
