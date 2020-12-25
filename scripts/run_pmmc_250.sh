#!/bin/sh

############################################################
####             antimode_250ka ###      numode_250ka ###
#############################################################
##/nd3_numu:     1085            #       
##/nd3_numubar:  1086            #       
##/nd3_nue:      1086            #                   
##/nd3_nuebar:   1086            #       
##/nd4_numu:     1086            #       
##/nd4_numubar:  1086            #       
##/nd4_nue:      1086            #        
##/nd4_nuebar:   1086            #       
###############################################################

#mkdir /home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/antimode_250ka
#mkdir /home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka

#for i in {1..1089}
#do

i=${1}

#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd3_numu_fe_${i}.nt"`
#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd3_numubar_fe_${i}.nt"`
#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd3_nue_fe_${i}.nt"`
#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd3_nuebar_fe_${i}.nt"`

#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd4_numu_fe_${i}.nt"`
#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd4_numubar_fe_${i}.nt"`
#neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd4_nue_fe_${i}.nt"`
neutfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_neut5d3d2/numode_250ka/fluka_nd4_nuebar_fe_${i}.nt"`

######################################################
######################################################

#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numu_fe_${i}.root"`
#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numubar_fe_${i}.root"`
#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nue_fe_${i}.root"`
#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nuebar_fe_${i}.root"`

#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numu_fe_${i}.root"`
#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numubar_fe_${i}.root"`
#g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nue_fe_${i}.root"`
g4file=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nuebar_fe_${i}.root"`

######################################################
######################################################

#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numu_fe_${i}_recon.root"`
#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numubar_fe_${i}_recon.root"`
#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nue_fe_${i}_recon.root"`
#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nuebar_fe_${i}_recon.root"`

#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numu_fe_${i}_recon.root"`
#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numubar_fe_${i}_recon.root"`
#reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nue_fe_${i}_recon.root"`
reconfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nuebar_fe_${i}_recon.root"`

######################################################
######################################################

#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numu_fe_${i}_ana.root"`
#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numubar_fe_${i}_ana.root"`
#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nue_fe_${i}_ana.root"`
#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nuebar_fe_${i}_ana.root"`

#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numu_fe_${i}_ana.root"`
#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numubar_fe_${i}_ana.root"`
#inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nue_fe_${i}_ana.root"`
inganavertexfile=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nuebar_fe_${i}_ana.root"`

######################################################
######################################################

#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numu_fe_${i}_onlybasic_mc.root"`
#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_numubar_fe_${i}_onlybasic_mc.root"`
#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nue_fe_${i}_onlybasic_mc.root"`
#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd3_nuebar_fe_${i}_onlybasic_mc.root"`

#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numu_fe_${i}_onlybasic_mc.root"`
#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_numubar_fe_${i}_onlybasic_mc.root"`
#onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nue_fe_${i}_onlybasic_mc.root"`
onlybasic=`printf "/home/t2k/tvngoc/tvngoc_link/ingrid/output_pmmc/numode_250ka/fluka_nd4_nuebar_fe_${i}_onlybasic_mc.root"`

################################################################################
#./IngMC -o (output_filename) -i (input_filename) -m (module ID) -f (flavor ID)#
# 		module ID:                                                     #
# 		 # 2: proton module                                            #
#		 # 3: horizontal module (nd3)                                  #  
# 		 # 4: vertical module (nd4)                                    #
#		flavor ID:                                                     #
#  		 # 1: numu                                                     #
# 		 # 2: numubar                                                  #
# 		 # 3: nue                                                      #
# 		 # 4: nuebar                                                   #
################################################################################
#cd /home/t2k/tvngoc/ingrid/pmmc_t2kreweight_rev
#source /home/t2k/tvngoc/ingrid/pmmc_t2kreweight_rev/setup.sh
cd /home/t2k/tvngoc/ingrid/pmmc_t2kreweight_rev/bin/Linux-g++
#./IngMC -o ${g4file} -i ${neutfile} -m 3 -f 1
#./IngMC -o ${g4file} -i ${neutfile} -m 3 -f 2
#./IngMC -o ${g4file} -i ${neutfile} -m 3 -f 3
#./IngMC -o ${g4file} -i ${neutfile} -m 3 -f 4
#./IngMC -o ${g4file} -i ${neutfile} -m 4 -f 1
#./IngMC -o ${g4file} -i ${neutfile} -m 4 -f 2
#./IngMC -o ${g4file} -i ${neutfile} -m 4 -f 3
./IngMC -o ${g4file} -i ${neutfile} -m 4 -f 4


cd /home/t2k/tvngoc/ingrid/basesoft/INGRID_analysis/app
./PMrecon -f ${g4file} -o ${reconfile}

rm ${g4file}
cd /home/t2k/tvngoc/ingrid/basesoft/INGRID_analysis/app
./IngAnaVertex -f ${reconfile} -o ${inganavertexfile}

rm ${reconfile}
cd /home/t2k/tvngoc/ingrid/basesoft/INGRID_analysis/app

./IngGetOnlyBasicMC -f ${inganavertexfile} -o ${onlybasic}

rm ${inganavertexfile}
#done
