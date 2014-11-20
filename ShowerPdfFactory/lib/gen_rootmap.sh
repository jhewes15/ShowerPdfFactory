#!/bin/bash

temp=make_rootmap.$$.temp

rootlibmap() {
 ROOTMAP=$1
 SOFILE=$2
 LINKDEF=$3
 shift 3
 DEPS=$*
 if [[ -e $SOFILE && -e $LINKDEF ]]; then
     rlibmap -f -o $ROOTMAP -l $SOFILE -d $DEPS -c $LINKDEF 2>> $temp
     rm -f $temp
 fi
}

######################################################
# ShowerPdfFactory
rootlibmap libshower_pdf_factory_ShowerPdfFactory.rootmap libshower_pdf_factory_ShowerPdfFactory.so $LARLITE_USERDEVDIR/shower_pdf_factory/ShowerPdfFactory/LinkDef.h \
    libLArLite_Analysis.so libRooFit.so













