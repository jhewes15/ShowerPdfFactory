#ifndef PI0PDFMAKER_CXX
#define PI0PDFMAKER_CXX

#include "Pi0PdfMaker.h"

/* PDF functions for shower conversion length */

// Instantiate params & PDF //
void Pi0PdfMaker::RadLenPdf(double xmin, double xmax, double lambdamin, double lambdamax){

  _RadLenx = new RooRealVar("_RadLenx","Distance [cm]",xmin,xmax);
  _RadLenl = new RooRealVar("_RadLenl","Radiation Length [cm]",lambdamin, lambdamax);
  _RadLenPDF = new RooExponential("_RadLenPDF","Radiation Length", *_RadLenx, *_RadLenl);

}

// Instantiate RooFit data holder & fit PDF //
void Pi0PdfMaker::RadLenFit(TTree* t){
  
  _RadLenData = new RooDataSet("_RadLenData","Distance [cm]",RooArgSet(*_RadLenx),RooFit::Import(*t));
  _RadLenPDF->fitTo(*_RadLenData);

}

// Plot PDF //
void Pi0PdfMaker::RadLenPlot(){
  
  _RadLenframe = _RadLenx->frame();
  _RadLenData->plotOn(_RadLenframe);
  _RadLenPDF->plotOn(_RadLenframe);
  TCanvas *c = new TCanvas("c","Distance PDF",1000,500);
  _RadLenframe->Draw();
  c->SaveAs("./PDF_RadLen.png");

}

// Integrate PDF //
double Pi0PdfMaker::RadLenIntegrate(double range, double width){
  
  double min = range * (1 - width);
  double max = range * (1 + width);
  _RadLenx->setRange("xrange",min,max);
  RooAbsReal* p_real = _RadLenPDF->createIntegral(RooArgSet(*_RadLenx),RooFit::NormSet(*_RadLenx),RooFit::Range("xrange"));
  double p = p_real->getValV();
  
  return p;
}


// This PDF tries to use the relation between the energy of the two showers
// in a Pi0 event and the opening angle between those showers
// That relation is given by: M_pi0 = 2 * sqrt(E1*E2) * sin( ang/2 )
// This PDF is the distribution Abs{2*arcsin[M/(2*sqrt(E1*E2))]-Ang}
// for each Pi0 event. This distrib. is reasonably exponential
void Pi0PdfMaker::EvsAnglePdf(double anglemin, double anglemax){

  _EvsAngRange = new RooRealVar("_EvsAngRange","Angle Range [rad]", anglemin, anglemax);
  _EvsAngRes   = new RooRealVar("_EvsAngRes","Angle Resolution [rad]", anglemin, anglemax);
  _EvsAngPDF   = new RooExponential("_EvsAngPDF","Angular Resolution PDF", *_EvsAngRange, *_EvsAngRes);

}

void Pi0PdfMaker::EvsAngleFit(TTree* t){
  
  _EvsAngData = new RooDataSet("_EvsAngData","Angle [rad]",RooArgSet(*_EvsAngRange),RooFit::Import(*t));
  _EvsAngPDF->fitTo(*_EvsAngData);

}

void Pi0PdfMaker::EvsAnglePlot(){
  
  _EvsAngframe = _EvsAngRange->frame();
  _EvsAngData->plotOn(_EvsAngframe);
  _EvsAngPDF->plotOn(_EvsAngframe);
  TCanvas *c = new TCanvas("c","Opening Angle PDF",1000,500);
  _EvsAngframe->Draw();
  c->SaveAs("./PDF_EvsAng.png");

}

double Pi0PdfMaker::EvsAngleIntegrate(double range, double width){
  
  double min = range * (1 - width);
  double max = range * (1 + width);
  _EvsAngRange->setRange("xrange",min,max);
  RooAbsReal* p_real = _EvsAngPDF->createIntegral(RooArgSet(*_EvsAngRange),RooFit::NormSet(*_EvsAngRange),RooFit::Range("xrange"));
  double p = p_real->getValV();
  
  return p;
}


RooAbsPdf* Pi0PdfMaker::dEdxPdf(int pdg){
  
  RooRealVar dedx("dEdx","dEdx [MeV/cm]",0,10);
  RooRealVar part("part","Particle PDG",-1000,1000);
  RooRealVar sigma("sigma","Spread in dEdx",1);
  if (pdg==22)
    part.setVal(4);
  else if ( (pdg==11) or (pdg==-11) )
    part.setVal(2);
  else
    part.setVal(0);
  RooGaussian *gauss = new RooGaussian("gauss","dEdx Gauss Pdf",dedx,part,sigma);
  
  return gauss;
}

#endif
