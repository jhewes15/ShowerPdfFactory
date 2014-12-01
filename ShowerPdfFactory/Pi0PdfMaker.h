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
  void           RadLenFit(TTree* t);
  void           RadLenPlot();
  double         RadLenIntegrate(double range,double width);

  // Opening Angle vs. E PDF functions
  void           EvsAnglePdf(double anglemin, double anglemax);
  void           EvsAngleFit(TTree* t);
  void           EvsAnglePlot();
  double         EvsAngIntegrate(double range, double width);
  
  // dEdx PDF functions
  RooAbsPdf*     dEdxPdf(int pdg);

  /// Set "data" TTree
  void setTree(TTree *t) { tree = t; }
  
 private:
  
  // Radiation length PDF variables
  RooRealVar*    _RadLenx;
  RooRealVar*    _RadLenl;
  RooAbsPdf*     _RadLenPDF;
  RooAbsData*    _RadLenData;
  RooPlot*       _RadLenframe;

  // EvsAngle PDF variables
  RooRealVar*       _EvsAngRange;
  RooRealVar*       _EvsAngRes;
  RooExponential*   _EvsAngPDF;
  RooAbsData*       _EvsAngData;
  RooPlot*          _EvsAngframe;


  // TTree with data sets in branches
  TTree *tree;
  
};

#endif
/** @} */ // end of doxygen group 

