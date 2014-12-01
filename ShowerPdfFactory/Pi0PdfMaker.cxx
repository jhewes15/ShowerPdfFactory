#ifndef PI0PDFMAKER_CXX
#define PI0PDFMAKER_CXX

#include "Pi0PdfMaker.h"

void Pi0PdfMaker::RadLenPdf(double xmin, double xmax, double lambdamin, double lambdamax){

  RadLen_x =      new RooRealVar("x","Distance [cm]",xmin,xmax);
  RadLen_l =      new RooRealVar("l","Radiation Length [cm]",lambdamin, lambdamax);
  RadLen_PDF =    new RooExponential("expo","Radiation Length", *RadLen_x, *RadLen_l);

}

void Pi0PdfMaker::RadLenData(TH1* h){
  
  RadLen_Data =   new RooDataHist("data","Distance [cm]", RooArgSet(*RadLen_x), h);

}

void Pi0PdfMaker::RadLenFit(){
  
  RadLen_PDF->fitTo(*RadLen_Data);

}

void Pi0PdfMaker::RadLenPlot(){
  
  RadLen_xframe = RadLen_x->frame();
  RadLen_Data->plotOn(RadLen_xframe);
  RadLen_PDF->plotOn(RadLen_xframe);
  TCanvas *c = new TCanvas("c","Distance PDF",1000,500);
  RadLen_xframe->Draw();
  c->SaveAs("./radlenPDF.png");

}


// This PDF tries to use the relation between the energy of the two showers
// in a Pi0 event and the opening angle between those showers
// That relation is given by: M_pi0 = 2 * sqrt(E1*E2) * sin( ang/2 )
// This PDF is the distribution Abs{2*arcsin[M/(2*sqrt(E1*E2))]-Ang}
// for each Pi0 event. This distrib. is reasonably exponential
void Pi0PdfMaker::EvsAnglePdf(double anglemin, double anglemax){

  AngRange   = new RooRealVar("AngRange","Angle Range [rad]", anglemin, anglemax);
  AngRes     = new RooRealVar("AngRes","Angle Resolution [rad]", anglemin, anglemax);
  EvsAng_PDF = new RooExponential("EvsAng","Angular Resolution PDF", *AngRange, *AngRes);

}

void Pi0PdfMaker::EvsAngleData(TH1* h){
  
  EvsAng_Data =   new RooDataHist("data","Angle [rad]", RooArgSet(*AngRange), h);

}

void Pi0PdfMaker::EvsAngleFit(){
  
  EvsAng_PDF->fitTo(*EvsAng_Data);

}

void Pi0PdfMaker::EvsAnglePlot(){
  
  EvsAng_frame = AngRange->frame();
  EvsAng_Data->plotOn(EvsAng_frame);
  EvsAng_PDF->plotOn(EvsAng_frame);
  TCanvas *c = new TCanvas("c","Opening Angle PDF",1000,500);
  EvsAng_frame->Draw();
  c->SaveAs("./radlenPDF.png");

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
