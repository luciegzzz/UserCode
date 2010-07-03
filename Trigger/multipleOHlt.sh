#!bin/sh

if [ $# -lt 1 ]; then
        echo "Usage: $0 run.number"
        exit
fi

RUNNUMBER=$1

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_MB_temp.cfg
sed "s|##MB||" hltmenu_16e29_r138746_DS_FullTable_MB.cfg> hltmenu_16e29_r138746_DS_FullTable_MB_temp.cfg
sed "s|FullTable|FullTable_MB|" hltmenu_16e29_r138746_DS_FullTable_MB_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_MB.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_MB.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_Mu.cfg
sed "s|##Mu||" hltmenu_16e29_r138746_DS_FullTable_Mu.cfg> hltmenu_16e29_r138746_DS_FullTable_Mu_temp.cfg
sed "s|FullTable|FullTable_Mu|" hltmenu_16e29_r138746_DS_FullTable_Mu_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_Mu.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_Mu.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_EG.cfg
sed "s|##EG||" hltmenu_16e29_r138746_DS_FullTable_EG.cfg> hltmenu_16e29_r138746_DS_FullTable_EG_temp.cfg
sed "s|FullTable|FullTable_EG|" hltmenu_16e29_r138746_DS_FullTable_EG_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_EG.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_EG.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_JMT.cfg
sed "s|##EG||" hltmenu_16e29_r138746_DS_FullTable_JMT.cfg> hltmenu_16e29_r138746_DS_FullTable_JMT_temp.cfg
sed "s|FullTable|FullTable_JMT|" hltmenu_16e29_r138746_DS_FullTable_JMT_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_JMT.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_JMT.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_MuMon.cfg
sed "s|##MonMu||" hltmenu_16e29_r138746_DS_FullTable_MuMon.cfg> hltmenu_16e29_r138746_DS_FullTable_MuMon_temp.cfg
sed "s|FullTable|FullTable_MuMon|" hltmenu_16e29_r138746_DS_FullTable_MuMon_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_MuMon.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_MuMon.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_EGMon.cfg
sed "s|##MonEG||" hltmenu_16e29_r138746_DS_FullTable_EGMon.cfg> hltmenu_16e29_r138746_DS_FullTable_EGMon_temp.cfg
sed "s|FullTable|FullTable_EGMon|" hltmenu_16e29_r138746_DS_FullTable_EGMon_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_EGMon.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_EGMon.cfg

cp hltmenu_16e29_r138746_DS_FullTable.cfg.template hltmenu_16e29_r138746_DS_FullTable_JMTMon.cfg
sed "s|##MonJMT||" hltmenu_16e29_r138746_DS_FullTable_JMTMon.cfg> hltmenu_16e29_r138746_DS_FullTable_JMTMon_temp.cfg
sed "s|FullTable_|FullTable_JMTMon|" hltmenu_16e29_r138746_DS_FullTable_JMTMon_temp.cfg> hltmenu_16e29_r138746_DS_FullTable_JMTMon.cfg
./OHltRateEff hltmenu_16e29_r138746_DS_FullTable_JMTMon.cfg

mkdir r${RUNNUMBER}
mv *16e29_r138746_DS_FullTable_* r${RUNNUMBER}

#rm hltmenu_16e29_r138746_DS_FullTable_*
