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
