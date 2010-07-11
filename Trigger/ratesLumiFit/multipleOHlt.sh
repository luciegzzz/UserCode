#!bin/sh

if [ $# -lt 1 ]; then
        echo "Usage: $0 run.number"
        exit
fi

RUNNUMBER=$1

nsls /castor/cern.ch/user/a/apana/OpenHLT/Commish2010/>ntupleslist.txt

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_MB_r${RUNNUMBER}_temp.cfg
sed "s|##MB||" hltmenu_ratesLumiFit_MB_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_MB_r${RUNNUMBER}.cfg
resMB="$(sed -n '/r'${RUNNUMBER}'__MinimumBias/p' ntupleslist.txt)"
echo $resMB
sed "s|rtemplateMB|"${resMB}"|g" hltmenu_ratesLumiFit_MB_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_MB_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|MB_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_MB_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_MB_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_MB_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}_temp.cfg
sed "s|##Mu||" hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__Mu_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateMu|"${res}"|g" hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|Mu_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_Mu_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_EG_r${RUNNUMBER}_temp.cfg
sed "s|##EG||" hltmenu_ratesLumiFit_EG_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_EG_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__EG_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateEG|"${res}"|g" hltmenu_ratesLumiFit_EG_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_EG_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|EG_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_EG_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_EG_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_EG_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}_temp.cfg
sed "s|##JMT||" hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__JetMETTau_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateJMT|"${res}"|g" hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|JMT_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_JMT_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}_temp.cfg
sed "s|##Comm||" hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__Commissioning_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateComm|"${res}"|g" hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|Comm_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_Comm_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}_temp.cfg
sed "s|##MonMu||" hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__MuMonitor_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateMonMu|"${res}"|g" hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|MuMon_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_MuMon_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}_temp.cfg
sed "s|##MonEG||" hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__EGMonitor_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateMonEG|"${res}"|g" hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|EGMon_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_EGMon_r${RUNNUMBER}.cfg

cp hltmenu_ratesLumiFit.cfg.template hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}_temp.cfg
sed "s|##MonJMT||" hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}.cfg
res="$(sed -n '/r'${RUNNUMBER}'__JetMETTauMonitor_/p' ntupleslist.txt)"
echo $res
sed "s|rtemplateMonJMT|"${res}"|g" hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}.cfg> hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}_temp.cfg
sed "s|FullTable|JMTMon_r"${RUNNUMBER}"|" hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}_temp.cfg> hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}.cfg
./OHltRateEff hltmenu_ratesLumiFit_JMTMon_r${RUNNUMBER}.cfg

mkdir r${RUNNUMBER}
rm *.tex
rm *snippet.py
mv *2.0e29_startup_RatesLumiFit_*_r${RUNNUMBER}* r${RUNNUMBER}

rm hltmenu_ratesLumiFit_*temp*
