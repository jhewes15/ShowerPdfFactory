/**
 * \file Pi0PdfMaker.h
 *
 * \ingroup MCPartGetter
 * 
 * \brief Class def header for a class Pi0PdfMaker
 *
 * @author David Caratelli
 */

/** \addtogroup MCPartGetter
    David Caratelli
    @{*/
#ifndef LARLITE_PI0PDFMAKER_H
#define LARLITE_PI0PDFMAKER_H

#include <iostream>
#include "RooRealVar.h"
#include "RooExponential.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooAddPdf.h"
#include "RooAbsPdf.h"
#include "RooAbsData.h"
#include "RooDataHist.h"
#include "RooPlot.h"
#include "TCanvas.h"

/**
   \class Pi0PdfMaker
   User defined class Pi0PdfMaker ... these comments are used to generate
   doxygen documentation!
 */
class Pi0PdfMaker {
  
 public:
  
  /// Default constructor
  Pi0PdfMaker(){};
  
  /// Default destructor
  virtual ~Pi0PdfMaker(){};

  // Radiation length PDF functions
  void           RadLenPdf(double xmin, double xmax, double lambdamin, double lambdamax);
  void           RadLenData(TH1* h);
  void           RadLenFit();
  void           RadLenPlot();

  // Opening Angle vs. E PDF functions
  void           EvsAnglePdf(double anglemin, double anglemax);
  void           EvsAngleData(TH1* h);
  void           EvsAngleFit();
  void           EvsAnglePlot();
  
  // dEdx PDF functions
  RooAbsPdf*     dEdxPdf(int pdg);

  /// Set "data" TTree
  void setTree(TTree *t) { tree = t; }
  
 private:
  
  // Radiation length PDF variables
  RooRealVar*    RadLen_x;
  RooRealVar*    RadLen_l;
  RooAbsPdf*     RadLen_PDF;
  RooAbsData*    RadLen_Data;
  RooPlot*       RadLen_xframe;

  // EvsAngle PDF variables
  RooRealVar*       AngRange;
  RooRealVar*       AngRes;
  RooExponential*   EvsAng_PDF;
  RooAbsData*       EvsAng_Data;
  RooPlot*          EvsAng_frame;


  // TTree with data sets in branches
  TTree *tree;
  
};

#endif
/** @} */ // end of doxygen group 

