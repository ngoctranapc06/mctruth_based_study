#!/usr/bin/perl

#system "source /home/t2k/tvngoc/ingrid/pmmc_t2kreweight_rev/setup.sh";

############################################################
####             antimode_320ka ###      numode_320ka ###
#############################################################
##/nd3_numu:     1087            #       1082
##/nd3_numubar:  1088            #       1082
##/nd3_nue:      1089            #       1082            
##/nd3_nuebar:   1089            #       1082
##/nd4_numu:     1089            #       1029
##/nd4_numubar:  1089            #       1082
##/nd4_nue:      1089            #       1082 
##/nd4_nuebar:   1089            #       1082
###############################################################

############################################################
#####             antimode_250ka ###      numode_250ka ###
##############################################################
###/nd3_numu:     1085            #	1091       
###/nd3_numubar:  1086            #     1091
###/nd3_nue:      1086            #     1091              
###/nd3_nuebar:   1086            #     1091  
###/nd4_numu:     1086            #     1091  
###/nd4_numubar:  1086            #     1090  
###/nd4_nue:      1086            #     1091   
###/nd4_nuebar:   1086            #     1091  
################################################################

#$irun = 1;
#$nrun = 300;

#$irun = 301;
#$nrun = 600;

#$irun = 601;
#$nrun = 900;

$irun = 901;
$nrun = 1091;


for($run_num = $irun; $run_num <= $nrun; $run_num++){
#system "bsub -q s /gpfs/fs03/t2k/beam/work/tvngoc/ingrid/run_pmmc_320.sh ${run_num}";
system "bsub -q s /gpfs/fs03/t2k/beam/work/tvngoc/ingrid/run_pmmc_250.sh ${run_num}";

#set outlog files in working directory
#system "bsub -q s -o outlog_${run_num}.out /gpfs/fs03/t2k/beam/work/tvngoc/ingrid/run_pmmc_test.sh ${run_num}";
}
