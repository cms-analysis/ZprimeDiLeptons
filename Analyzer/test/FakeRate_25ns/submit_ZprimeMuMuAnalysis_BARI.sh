#!/bin/bash


mkdir -p /lustre/cms/store/user/defilip/ZprimeAnalysis/80X/jobdir
mkdir -p /lustre/cms/store/user/defilip/ZprimeAnalysis/80X/histodir

echo "Running ZprimeMuMu Analysis_FR with executables RunZprimeMuMuAnalysis_FR"
source /cvmfs/cms.cern.ch/cmsset_default.sh

export LD_LIBRARY_PATH=lib:$LD_LIBRARY_PATH
export PATH=path:$PATH


if [ -d "$_CONDOR_SCRATCH_DIR" ]; then
    workdir=`echo $_CONDOR_SCRATCH_DIR`;
    cd ${workdir};
else 
    workdir=`echo $PWD`;
    cd ${workdir};
fi


savedir=`echo /lustre/cms/store/user/defilip/ZprimeAnalysis/80X/histodir`

echo "Working dir is $workdir"
#echo "Executable dir is $exedir"
echo "Saving dir is $savedir"

echo "Compiling the macros"
bash compileZprimeMuMuAnalysis.sh

./RunZprimeMuMuAnalysis_FR which sig_input.txt 1 bkg_input.txt 1 data_input.txt 1 site year mc >& ${workdir}/RunZprimeMuMuAnalysis_FR.log

mv -f ${workdir}/RunZprimeMuMuAnalysis_FR.log /lustre/cms/store/user/defilip/ZprimeAnalysis/80X/jobdir/output.log
mv -f ${workdir}/CMSSW803-Analyse_ZprimeToMuMu_13TeV.root     ${savedir}/output.root
mv -f ${workdir}/CMSSW803-Analyse_ZprimeToMuMu_13TeV_cand.txt ${savedir}/output_cand.txt

