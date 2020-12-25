#include <iostream>
using namespace std;

void plot_basic_dist(){

  TString histname;

  TChain *tchain = new TChain("tree", "tree");
  Int_t nfile = 300;
  for(int ifile=0; ifile<nfile; ifile++){
    TString filename;
    filename.Form("/gpfs/group/t2k/beam/work/yasuken/Latest/testbench/data/signaldef/test_inclusive_%d.root", ifile);
    tchain->Add(filename);
  }

  Int_t event;
  tchain->SetBranchAddress("event", &event);
  Int_t inttype;
  tchain->SetBranchAddress("inttype", &inttype);
  Int_t flavor;
  tchain->SetBranchAddress("flavor", &flavor);
  Int_t vertexdetector;
  tchain->SetBranchAddress("vertexdetector", &vertexdetector);
  Double_t weight;
  tchain->SetBranchAddress("weight", &weight);
  Int_t matching;
  tchain->SetBranchAddress("matching", &matching);
  Int_t ntrack;
  tchain->SetBranchAddress("ntrack", &ntrack);
  Int_t fvcut;
  tchain->SetBranchAddress("fvcut", &fvcut);
  Int_t fccut;
  tchain->SetBranchAddress("fccut", &fccut);
  Int_t ntrack_except_proton = 0;

  std::vector<Int_t> *pdg = new std::vector<Int_t>;
  tchain->SetBranchAddress("pdg", &pdg);
  std::vector<Double_t> *angle = new std::vector<Double_t>;
  tchain->SetBranchAddress("angle", &angle);
  std::vector<Double_t> *momentum = new std::vector<Double_t>;
  tchain->SetBranchAddress("momentum", &momentum);
  std::vector<Int_t> *mrd = new std::vector<Int_t>;
  tchain->SetBranchAddress("mrd", &mrd);

  Int_t nentry = tchain->GetEntries();
  cout << "nentry = " << nentry << '\n';

  Double_t num_angle_selection2[36];
  Double_t num_angle_pur_selection2[36];
  Double_t angle_pur_selection2[36];
  Double_t xerr_selection2[36];
  Double_t yerr_u_selection2[36];
  Double_t yerr_d_selection2[36];

  Double_t num_angle_selection3[36];
  Double_t num_angle_pur_selection3[36];
  Double_t angle_pur_selection3[36];
  Double_t xerr_selection3[36];
  Double_t yerr_u_selection3[36];
  Double_t yerr_d_selection3[36];

  Double_t num_angle_selection4[36];
  Double_t num_angle_pur_selection4[36];
  Double_t angle_pur_selection4[36];
  Double_t xerr_selection4[36];
  Double_t yerr_u_selection4[36];
  Double_t yerr_d_selection4[36];

  Double_t num_mom_selection2[36];
  Double_t num_mom_pur_selection2[36];
  Double_t mom_pur_selection2[36];
  Double_t xerr_mom_selection2[36];
  Double_t yerr_mom_u_selection2[36];
  Double_t yerr_mom_d_selection2[36];

  Double_t num_mom_selection3[36];
  Double_t num_mom_pur_selection3[36];
  Double_t mom_pur_selection3[36];
  Double_t xerr_mom_selection3[36];
  Double_t yerr_mom_u_selection3[36];
  Double_t yerr_mom_d_selection3[36];

  Double_t num_mom_selection4[36];
  Double_t num_mom_pur_selection4[36];
  Double_t mom_pur_selection4[36];
  Double_t xerr_mom_selection4[36];
  Double_t yerr_mom_u_selection4[36];
  Double_t yerr_mom_d_selection4[36];

  Double_t num_event_total_selection1 = 0; 
  Double_t num_event_cc0pi_selection1 = 0;
  Double_t num_event_cc1pi_selection1 = 0;
  Double_t num_event_ccother_selection1 = 0;
  Double_t num_event_bg_selection1 = 0;

  Double_t num_event_total_selection2 = 0; 
  Double_t num_event_cc0pi_selection2 = 0;
  Double_t num_event_cc1pi_selection2 = 0;
  Double_t num_event_ccother_selection2 = 0;
  Double_t num_event_bg_selection2 = 0;

  Double_t num_event_total_selection3 = 0; 
  Double_t num_event_cc0pi_selection3 = 0;
  Double_t num_event_cc1pi_selection3 = 0;
  Double_t num_event_ccother_selection3 = 0;
  Double_t num_event_bg_selection3 = 0;

  Double_t num_event_total_selection4 = 0; 
  Double_t num_event_cc0pi_selection4 = 0;
  Double_t num_event_cc1pi_selection4 = 0;
  Double_t num_event_ccother_selection4 = 0;
  Double_t num_event_bg_selection4 = 0;

  Int_t MRD = 5;
  Int_t angleID;
  Int_t dangle = 5;

  Int_t momID;
  Int_t dmom = 100;

  TH1D* hist_cc0pi[7];
  TH1D* hist_cc1pi[7];
  TH1D* hist_ccother[7];
  TH1D* hist_nc[7];
  TH1D* hist_bg[7];

  for(int i=0; i<7; i++){
    histname.Form("hist_cc0pi_%d", i);
    hist_cc0pi[i] = new TH1D(histname,"", 72, 0, 180);
    histname.Form("hist_cc1pi_%d", i);
    hist_cc1pi[i] = new TH1D(histname,"", 72, 0, 180);
    histname.Form("hist_other_%d", i);
    hist_ccother[i] = new TH1D(histname,"", 72, 0, 180);
    histname.Form("hist_nc_%d", i);
    hist_nc[i] = new TH1D(histname,"", 72, 0, 180);
    histname.Form("hist_bg_%d", i);
    hist_bg[i] = new TH1D(histname,"", 72, 0, 180);
  }

  for(int i=0; i<36; i++){
    num_angle_selection2[i]=0;
    num_angle_pur_selection2[i]=0;    

    num_angle_selection3[i]=0;
    num_angle_pur_selection3[i]=0;    

    num_angle_selection4[i]=0;
    num_angle_pur_selection4[i]=0;    
  }

  for(int i=0; i<30; i++){
    num_mom_selection2[i]=0;
    num_mom_pur_selection2[i]=0;    

    num_mom_selection3[i]=0;
    num_mom_pur_selection3[i]=0;    

    num_mom_selection4[i]=0;
    num_mom_pur_selection4[i]=0;    
  }

  Double_t num_0_0_3 = 0;
  Double_t num_0_1_2 = 0;
  Double_t num_0_2_1 = 0;
  Double_t num_1_0_2 = 0;
  Double_t num_2_0_1 = 0;
  Double_t num_1_2_0 = 0;
  Double_t num_2_1_0 = 0;
  Double_t num_0_3_0 = 0;
  Double_t num_3_0_0 = 0;

  Double_t cc1pi_num_0_0_3 = 0;
  Double_t cc1pi_num_0_1_2 = 0;
  Double_t cc1pi_num_0_2_1 = 0;
  Double_t cc1pi_num_1_0_2 = 0;
  Double_t cc1pi_num_2_0_1 = 0;
  Double_t cc1pi_num_1_2_0 = 0;
  Double_t cc1pi_num_2_1_0 = 0;
  Double_t cc1pi_num_0_3_0 = 0;
  Double_t cc1pi_num_3_0_0 = 0;

  for(int ientry=0; ientry<nentry; ientry++){
    tchain->GetEntry(ientry);
    weight = weight/nfile*0.5;

    Bool_t selection = false;
    Bool_t cc1piselection = false;

    Int_t protonnumber = 0;

    Int_t mulike = 0;
    Int_t plike = 0;
    Int_t other = 0;

    for(int i=0; i<pdg->size(); i++){
      if(fabs(pdg->at(i)) == 2212){
	protonnumber ++;
	plike++;
      }

      else if(fabs(pdg->at(i)) == 211){
	mulike++;
      }

      else if(fabs(pdg->at(i)) == 13){
	mulike++;
      }

      else{
	other++;
      }
      
    }
    ntrack_except_proton = ntrack - protonnumber;

    if(mrd->size()==0){
      if(fvcut==1){
	num_event_total_selection1 += weight;

	if(vertexdetector==0 && flavor==1){
	  if(inttype==1){
	    num_event_cc0pi_selection1 += weight;
	    //hist_cc0pi[0]->Fill(angle->at(0), weight);
	  }

	  else if(inttype==2){
	    num_event_cc1pi_selection1 += weight;
	    //hist_cc1pi[0]->Fill(angle->at(0), weight);
	  }
	  
	  else if(inttype==3){
	    num_event_ccother_selection1 += weight;
	    //hist_ccother[0]->Fill(angle->at(0), weight);
	  }
	  
	  else{
	    num_event_bg_selection1 += weight;
	    //hist_nc[0]->Fill(angle->at(0), weight);
	  }
	}

	else{
	  num_event_bg_selection1 += weight;
	  //hist_bg[0]->Fill(angle->at(0), weight);
	}
      }//fvcut
    }//mrd->size()==0

    if(mrd->size()>=1){
      Bool_t bmflag=false;
      for(int i=0; i<mrd->size();i++){
        if(mrd->at(i)==MRD)
          bmflag=true;
	angleID = angle->at(0)/dangle;
	momID = momentum->at(0)/dmom;
      }

      if(bmflag){
	if(fvcut==1){
	  num_event_total_selection2 += weight;
	  num_angle_selection2[angleID] += weight;
	  if(momID>=0)
	    num_mom_selection2[momID] += weight;
	  
	  if(vertexdetector==0 && flavor==1){
	    if(inttype==1){
	      num_event_cc0pi_selection2 += weight;
	      //num_angle_pur_selection2[angleID] += weight;
	      if(momID>=0)
		num_mom_pur_selection2[momID] += weight;
	      hist_cc0pi[1]->Fill(angle->at(0), weight);
	    }
	    
	    else if(inttype==2){
	      num_event_cc1pi_selection2 += weight;
	      num_angle_pur_selection2[angleID] += weight;
	      hist_cc1pi[1]->Fill(angle->at(0), weight);
	    }
	    
	    else if(inttype==3){
	      num_event_ccother_selection2 += weight;
	      hist_ccother[1]->Fill(angle->at(0), weight);
	    }
	    
	    else{
	      num_event_bg_selection2 += weight;
	      hist_nc[1]->Fill(angle->at(0), weight);
	    }
	  }
	  else{
	    num_event_bg_selection2 += weight;
	    hist_bg[1]->Fill(angle->at(0), weight);
	  }
	}//fvcut
      }
    }//mrd->size()==1

    if(mrd->size()>=1){
      Bool_t bmflag=false;
      for(int i=0; i<mrd->size();i++){
	if(mrd->at(i)==MRD)
	  bmflag=true;
	angleID = angle->at(0)/dangle;
	momID = momentum->at(0)/dmom;
      }

      if(bmflag){
	if(fvcut==1 && ntrack==3){
	  num_angle_selection3[angleID] += weight;
	  if(momID>=0)
	    num_mom_selection3[momID] += weight;
	  num_event_total_selection3 += weight;
	  selection = true;
	  
	  if(vertexdetector==0 && flavor==1){
	    if(inttype==1){
	      num_event_cc0pi_selection3 += weight;
	      //num_angle_pur_selection3[angleID] += weight;
	      if(momID>=2)
		num_mom_pur_selection3[momID] += weight;
	      hist_cc0pi[2]->Fill(angle->at(0), weight);

	      if(mulike==1 && plike==2 && other==0){
		hist_cc0pi[5]->Fill(angle->at(0), weight);
	      }

	      if(mulike==2 && plike==1 && other==0){
		hist_cc0pi[6]->Fill(angle->at(0), weight);
	      }
	    }
	    
	    else if(inttype==2){
	      cc1piselection = true;
	      num_event_cc1pi_selection3 += weight;
	      num_angle_pur_selection3[angleID] += weight;
	      hist_cc1pi[2]->Fill(angle->at(0), weight);

	      if(mulike==1 && plike==2 && other==0){
		hist_cc1pi[5]->Fill(angle->at(0), weight);
	      }

	      if(mulike==2 && plike==1 && other==0){
		hist_cc1pi[6]->Fill(angle->at(0), weight);
	      }

	    }
	    
	    else if(inttype==3){
	      num_event_ccother_selection3 += weight;
	      hist_ccother[2]->Fill(angle->at(0), weight);

	      if(mulike==1 && plike==2 && other==0){
		hist_ccother[5]->Fill(angle->at(0), weight);
	      }

	      if(mulike==2 && plike==1 && other==0){
		hist_ccother[6]->Fill(angle->at(0), weight);
	      }

	    }
	    
	    else{
	      num_event_bg_selection3 += weight;
	      hist_ccother[2]->Fill(angle->at(0), weight);

	      if(mulike==1 && plike==2 && other==0){
		hist_nc[5]->Fill(angle->at(0), weight);
	      }

	      if(mulike==2 && plike==1 && other==0){
		hist_cc1pi[6]->Fill(angle->at(0), weight);
	      }

	    }
	  }
	  else{
	    num_event_bg_selection3 += weight;
	    hist_bg[2]->Fill(angle->at(0), weight);
	    
	    if(mulike==1 && plike==2 && other==0){
	      hist_bg[5]->Fill(angle->at(0), weight);
	    }
	    
	    if(mulike==2 && plike==1 && other==0){
	      hist_bg[5]->Fill(angle->at(0), weight);
	    }

	  }
	}//fvcut
      }
    }//mrd->size()==1
      
    if(mrd->size()>=1){
      Bool_t bmflag=false;
      for(int i=0; i<mrd->size();i++){
	if(mrd->at(i)==MRD)
	  bmflag=true;
	angleID = angle->at(0)/dangle;
	momID = momentum->at(0)/dmom;
      }
      if(bmflag){
	if(fvcut==1 && ntrack_except_proton==1){
	  num_event_total_selection4 += weight;
	  num_angle_selection4[angleID] += weight;
	  if(momID>=0)
	    num_mom_selection4[momID] += weight;
	  
	  if(vertexdetector==0 && flavor==1){
	    if(inttype==1){
	      num_event_cc0pi_selection4 += weight;
	      //num_angle_pur_selection4[angleID] += weight;
	      if(momID>=0)
		num_mom_pur_selection4[momID] += weight;
	      hist_cc0pi[3]->Fill(angle->at(0), weight);
	    }
	    
	    else if(inttype==2){
	      num_event_cc1pi_selection4 += weight;
	      num_angle_pur_selection4[angleID] += weight;
	      hist_cc1pi[3]->Fill(angle->at(0), weight);
	    }
	    
	    else if(inttype==3){
	      num_event_ccother_selection4 += weight;
	      hist_ccother[3]->Fill(angle->at(0), weight);
	    }
	    
	    else{
	      //cout << "entry= " << event << " " << inttype  << '\n';
	      num_event_bg_selection4 += weight;
	      hist_nc[3]->Fill(angle->at(0), weight);
	    }
	  }
	  else{
	    num_event_bg_selection4 += weight;
	    hist_bg[3]->Fill(angle->at(0), weight);
	  }
	}//fvcut
      }
    }//mrd->size()==1

    if(ntrack==3){
      //std::cout << "mu:p:else = " << mulike << " : " << plike << " : " << other << " ntrack  " << ntrack  << " " << pdg->size()  << '\n'; 

      if(selection){

	if(mulike==0 && plike==0 && other==3){
	  num_0_0_3 +=weight;
	}
	
	else if(mulike==0 && plike==3 && other==0){
	  num_0_3_0 += weight;
	}
	
	else if(mulike==3 && plike==0 && other==0){
	  num_3_0_0 += weight;
	}
	
	else if(mulike==0 && plike==1 && other==2){
	  num_0_1_2 += weight;
	}
	
	else if(mulike==0 && plike==2 && other==1){
	  num_0_2_1 += weight;
	}
	
	else if(mulike==1 && plike==0 && other==2){
	  num_1_0_2 += weight;
	}
	
	else if(mulike==1 && plike==2 && other==0){
	  num_1_2_0 += weight;
	  if(cc1piselection)
	    cc1pi_num_1_2_0 += weight;
	}
	
	else if(mulike==2 && plike==1 && other==0){
	  num_2_1_0 += weight;
	  if(cc1piselection)
	    cc1pi_num_2_1_0 += weight;
	}
      }
    }
  }//ientry

  cout << num_1_2_0 << " " << num_2_1_0 << " " << num_0_2_1 << " " << num_0_0_3 << '\n';
  cout << cc1pi_num_2_1_0 << " " << cc1pi_num_1_2_0 << '\n';

  TH1I* hist_num_3track = new TH1I("hist_num_3track", "", 9, 0, 9);
  hist_num_3track->SetBinContent(1, num_2_1_0);
  hist_num_3track->GetXaxis()->SetBinLabel(1, "mu:2 p:1 else:0");
  hist_num_3track->SetBinContent(2, num_1_2_0);
  hist_num_3track->GetXaxis()->SetBinLabel(2, "mu:1 p:2 else:0");
  hist_num_3track->SetBinContent(3, num_3_0_0);
  hist_num_3track->GetXaxis()->SetBinLabel(3, "mu:3 p:0 else:0");
  hist_num_3track->SetBinContent(4, num_0_2_1);
  hist_num_3track->GetXaxis()->SetBinLabel(4, "mu:0 p:2 else:1");
  hist_num_3track->SetBinContent(5, num_0_1_2);
  hist_num_3track->GetXaxis()->SetBinLabel(5, "mu:0 p:1 else:2");
  hist_num_3track->SetBinContent(6, num_0_3_0);
  hist_num_3track->GetXaxis()->SetBinLabel(6, "mu:0 p:3 else:0");
  hist_num_3track->SetBinContent(7, num_1_0_2);
  hist_num_3track->GetXaxis()->SetBinLabel(7, "mu:1 p:0 else:2");
  hist_num_3track->SetBinContent(8, num_2_0_1);
  hist_num_3track->GetXaxis()->SetBinLabel(8, "mu:2 p:0 else:1");
  hist_num_3track->SetBinContent(9, num_0_0_3);
  hist_num_3track->GetXaxis()->SetBinLabel(9, "mu:0 p:0 else:3");

  Double_t anglerow[36];
  Double_t momrow[30];

  for(int i=0; i<36; i++){
    anglerow[i] = 2.5 + dangle*i;
    xerr_selection2[i] = 0;
    xerr_selection3[i] = 0;
    xerr_selection4[i] = 0;

    if(num_angle_selection2[i]!=0)
      angle_pur_selection2[i] = num_angle_pur_selection2[i] / num_angle_selection2[i];
    else
      angle_pur_selection2[i] = 0;

    if(num_angle_selection3[i]!=0)
      angle_pur_selection3[i] = num_angle_pur_selection3[i] / num_angle_selection3[i];
    else
      angle_pur_selection3[i] = 0;

    if(num_angle_selection4[i]!=0)
      angle_pur_selection4[i] = num_angle_pur_selection4[i] / num_angle_selection4[i];
    else
      angle_pur_selection4[i] = 0;

    Double_t x = num_angle_pur_selection2[i];
    Double_t y = num_angle_selection2[i] - num_angle_pur_selection2[i];
    Double_t nume = sqrt(x*x*y + y*y*x);
    Double_t deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_d_selection2[i] = nume/deno;
      yerr_u_selection2[i] = nume/deno;
    }
    else{
      Double_t p = angle_pur_selection2[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_u_selection2[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_d_selection2[i] = nume/deno;
    }

    yerr_d_selection2[i] = yerr_d_selection2[i]/sqrt(nfile);
    yerr_u_selection2[i] = yerr_u_selection2[i]/sqrt(nfile);

    x = num_angle_pur_selection3[i];
    y = num_angle_selection3[i] - num_angle_pur_selection3[i];
    nume = sqrt(x*x*y + y*y*x);
    deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_u_selection3[i] = nume/deno;
      yerr_d_selection3[i] = nume/deno;
    }
    else{
      Double_t p = angle_pur_selection3[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_u_selection3[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_d_selection3[i] = nume/deno;
    }

    yerr_d_selection3[i] = yerr_d_selection3[i]/sqrt(nfile);
    yerr_u_selection3[i] = yerr_u_selection3[i]/sqrt(nfile);

    x = num_angle_pur_selection4[i];
    y = num_angle_selection4[i] - num_angle_pur_selection4[i];
    nume = sqrt(x*x*y + y*y*x);
    deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_u_selection4[i] = nume/deno;
      yerr_d_selection4[i] = nume/deno;
    }
    else{
      Double_t p = angle_pur_selection4[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_u_selection4[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_d_selection4[i] = nume/deno;
    }

    yerr_d_selection4[i] = yerr_d_selection4[i]/sqrt(nfile);
    yerr_u_selection4[i] = yerr_u_selection4[i]/sqrt(nfile);
  }

  for(int i=0; i<30; i++){
    momrow[i] = 50. + dmom*i;
    xerr_mom_selection2[i] = 0;
    xerr_mom_selection3[i] = 0;
    xerr_mom_selection4[i] = 0;

    if(num_mom_selection2[i]!=0)
      mom_pur_selection2[i] = num_mom_pur_selection2[i] / num_mom_selection2[i];
    else
      mom_pur_selection2[i] = 0;

    if(num_mom_selection3[i]!=0)
      mom_pur_selection3[i] = num_mom_pur_selection3[i] / num_mom_selection3[i];
    else
      mom_pur_selection3[i] = 0;

    if(num_mom_selection4[i]!=0)
      mom_pur_selection4[i] = num_mom_pur_selection4[i] / num_mom_selection4[i];
    else
      mom_pur_selection4[i] = 0;

    Double_t x = num_mom_pur_selection2[i];
    Double_t y = num_mom_selection2[i] - num_mom_pur_selection2[i];
    Double_t nume = sqrt(x*x*y + y*y*x);
    Double_t deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_mom_d_selection2[i] = nume/deno;
      yerr_mom_u_selection2[i] = nume/deno;
    }
    else{
      Double_t p = mom_pur_selection2[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_u_selection2[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_d_selection2[i] = nume/deno;
    }
    yerr_mom_d_selection2[i] = yerr_mom_d_selection2[i]/sqrt(nfile);
    yerr_mom_u_selection2[i] = yerr_mom_u_selection2[i]/sqrt(nfile);


    x = num_mom_pur_selection3[i];
    y = num_mom_selection3[i] - num_mom_pur_selection3[i];
    nume = sqrt(x*x*y + y*y*x);
    deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_mom_u_selection3[i] = nume/deno;
      yerr_mom_d_selection3[i] = nume/deno;
    }
    else{
      Double_t p = mom_pur_selection3[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_u_selection3[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_d_selection3[i] = nume/deno;
    }
    yerr_mom_d_selection3[i] = yerr_mom_d_selection3[i]/sqrt(nfile);
    yerr_mom_u_selection3[i] = yerr_mom_u_selection3[i]/sqrt(nfile);


    x = num_mom_pur_selection4[i];
    y = num_mom_selection4[i] - num_mom_pur_selection4[i];
    nume = sqrt(x*x*y + y*y*x);
    deno = (x+y)*(x+y);
    if(x+y>10){
      yerr_mom_u_selection4[i] = nume/deno;
      yerr_mom_d_selection4[i] = nume/deno;
    }
    else{
      Double_t p = mom_pur_selection4[i];
      Double_t n = x+y;
      nume = (2*n*p + 1) + sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_u_selection4[i] = nume/deno;
      nume = (2*n*p + 1) - sqrt(4*n*p + 1 -4*n*p*p);
      deno = 2*(n + 1);
      yerr_mom_d_selection4[i] = nume/deno;
    }
    yerr_mom_d_selection4[i] = yerr_mom_d_selection4[i]/sqrt(nfile);
    yerr_mom_u_selection4[i] = yerr_mom_u_selection4[i]/sqrt(nfile);

  }

  TCanvas* c1 = new TCanvas("c1", "c1", 1000, 1200);
  c1->cd();
  c1->Divide(1, 2);
  c1->cd(1);
  TGraphAsymmErrors* purity_graph_selection2 = new TGraphAsymmErrors(36, anglerow, angle_pur_selection2, xerr_selection2, xerr_selection2, yerr_u_selection2, yerr_d_selection2);
  purity_graph_selection2->Draw("AP");
  purity_graph_selection2->SetMarkerStyle(21);
  purity_graph_selection2->SetMarkerColor(2);
  purity_graph_selection2->SetMaximum(1);
  purity_graph_selection2->SetMinimum(0);
  purity_graph_selection2->SetTitle("Selection2; angle (degree); purity");

  c1->cd(2);
  TGraphAsymmErrors* mom_purity_graph_selection2 
    = new TGraphAsymmErrors(30, momrow, mom_pur_selection2, xerr_mom_selection2, xerr_mom_selection2, yerr_mom_u_selection2, yerr_mom_d_selection2);
  mom_purity_graph_selection2->Draw("AP");
  mom_purity_graph_selection2->SetMarkerStyle(21);
  mom_purity_graph_selection2->SetMarkerColor(2);
  mom_purity_graph_selection2->SetMaximum(1);
  mom_purity_graph_selection2->SetMinimum(0);
  mom_purity_graph_selection2->SetTitle("Selection2; momentum (MeV/c); purity");
  c1->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection2_differencial_purity_%d.png",MRD));

  TCanvas* c2 = new TCanvas("c2", "c2", 1000, 1200);
  c2->cd();
  c2->Divide(1, 2);
  c2->cd(1);
  TGraphAsymmErrors* purity_graph_selection3 = new TGraphAsymmErrors(36, anglerow, angle_pur_selection3, xerr_selection3, xerr_selection3, yerr_u_selection3, yerr_d_selection3);
  purity_graph_selection3->Draw("AP");
  purity_graph_selection3->SetMarkerStyle(21);
  purity_graph_selection3->SetMarkerColor(2);
  purity_graph_selection3->SetMaximum(1);
  purity_graph_selection3->SetMinimum(0);
  purity_graph_selection3->SetTitle("Selection3; angle (degree); purity");

  c2->cd(2);
  TGraphAsymmErrors* mom_purity_graph_selection3
    = new TGraphAsymmErrors(30, momrow, mom_pur_selection3, xerr_mom_selection3, xerr_mom_selection3, yerr_mom_u_selection3, yerr_mom_d_selection3);
  mom_purity_graph_selection3->Draw("AP");
  mom_purity_graph_selection3->SetMarkerStyle(21);
  mom_purity_graph_selection3->SetMarkerColor(2);
  mom_purity_graph_selection3->SetMaximum(1);
  mom_purity_graph_selection3->SetMinimum(0);
  mom_purity_graph_selection3->SetTitle("Selection3; momentum (MeV/c); purity");
  c2->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection3_differencial_purity_%d.png",MRD));


  TCanvas* c4 = new TCanvas("c4", "c4", 1000, 1200);
  c4->cd();
  c4->Divide(1, 2);
  c4->cd(1);
  TGraphAsymmErrors* purity_graph_selection4 = new TGraphAsymmErrors(36, anglerow, angle_pur_selection4, xerr_selection4, xerr_selection4, yerr_u_selection4, yerr_d_selection4);
  purity_graph_selection4->Draw("AP");
  purity_graph_selection4->SetMarkerStyle(21);
  purity_graph_selection4->SetMarkerColor(2);
  purity_graph_selection4->SetMaximum(1);
  purity_graph_selection4->SetMinimum(0);
  purity_graph_selection4->SetTitle("Selection4; angle (degree); purity");

  c4->cd(2);
  TGraphAsymmErrors* mom_purity_graph_selection4 
    = new TGraphAsymmErrors(30, momrow, mom_pur_selection4, xerr_mom_selection4, xerr_mom_selection4, yerr_mom_u_selection4, yerr_mom_d_selection4);
  mom_purity_graph_selection4->Draw("AP");
  mom_purity_graph_selection4->SetMarkerStyle(21);
  mom_purity_graph_selection4->SetMarkerColor(2);
  mom_purity_graph_selection4->SetMaximum(1);
  mom_purity_graph_selection4->SetMinimum(0);
  mom_purity_graph_selection4->SetTitle("Selection4; momentum (MeV/c); purity");
  c4->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection4_differencial_purity_%d.png",MRD));

  TCanvas* c5 = new TCanvas("c5", "c5", 1000, 600);
  THStack *stack_topology3 = new THStack("stack_topology3", "");
  hist_cc0pi[3]->SetFillColor(2);
  stack_topology3->Add(hist_cc0pi[3]);
  hist_cc1pi[3]->SetFillColor(4);
  stack_topology3->Add(hist_cc1pi[3]);
  hist_ccother[3]->SetFillColor(6);
  stack_topology3->Add(hist_ccother[3]);
  hist_nc[3]->SetFillColor(7);
  stack_topology3->Add(hist_nc[3]);
  hist_bg[3]->SetFillColor(5);
  stack_topology3->Add(hist_bg[3]);
  stack_topology3->Draw("hist");
  stack_topology3->SetTitle("Selection 4;Angle(degree);Events(/5.0#times10^{20} P.O.T)");

  TLegend* legend3 = new TLegend(0.70, 0.60, 0.90, 0.90);
  //TLegend* legend3 = new TLegend(0.10, 0.60, 0.40, 0.90);
  legend3->AddEntry(hist_cc0pi[3], "CC0#pi", "f");
  legend3->AddEntry(hist_cc1pi[3], "CC1#pi", "f");
  legend3->AddEntry(hist_ccother[3], "CC other", "f");
  legend3->AddEntry(hist_nc[3], "NC", "f");
  legend3->AddEntry(hist_bg[3], "BG", "f");
  legend3->Draw("");
  c5->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection4_topology_%d.png",MRD));


  TCanvas* c6 = new TCanvas("c6", "c6", 1000, 600);
  THStack *stack_topology2 = new THStack("stack_topology2", "");
  hist_cc0pi[2]->SetFillColor(2);
  stack_topology2->Add(hist_cc0pi[2]);
  hist_cc1pi[2]->SetFillColor(4);
  stack_topology2->Add(hist_cc1pi[2]);
  hist_ccother[2]->SetFillColor(6);
  stack_topology2->Add(hist_ccother[2]);
  hist_nc[2]->SetFillColor(7);
  stack_topology2->Add(hist_nc[2]);
  hist_bg[2]->SetFillColor(5);
  stack_topology2->Add(hist_bg[2]);
  stack_topology2->Draw("hist");
  stack_topology2->SetTitle("Selection 3;Angle(degree);Events(/5.0#times10^{20} P.O.T)");

  //TLegend* legend2 = new TLegend(0.10, 0.60, 0.40, 0.90);
  TLegend* legend2 = new TLegend(0.70, 0.60, 0.90, 0.90);
  legend2->AddEntry(hist_cc0pi[2], "CC0#pi", "f");
  legend2->AddEntry(hist_cc1pi[2], "CC1#pi", "f");
  legend2->AddEntry(hist_ccother[2], "CC other", "f");
  legend2->AddEntry(hist_nc[2], "NC", "f");
  legend2->AddEntry(hist_bg[2], "BG", "f");
  legend2->Draw("");
  c6->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection3_topology_ntrack3_%d.png",MRD));

  TCanvas* c7 = new TCanvas("c7", "c7", 1000, 600);
  THStack *stack_topology1 = new THStack("stack_topology1", "");
  hist_cc0pi[1]->SetFillColor(2);
  stack_topology1->Add(hist_cc0pi[1]);
  hist_cc1pi[1]->SetFillColor(4);
  stack_topology1->Add(hist_cc1pi[1]);
  hist_ccother[1]->SetFillColor(6);
  stack_topology1->Add(hist_ccother[1]);
  hist_nc[1]->SetFillColor(7);
  stack_topology1->Add(hist_nc[1]);
  hist_bg[1]->SetFillColor(5);
  stack_topology1->Add(hist_bg[1]);
  stack_topology1->Draw("hist");
  stack_topology1->SetTitle("Selection 2;Angle(degree);Events(/5.0#times10^{20} P.O.T)");

  TLegend* legend1 = new TLegend(0.70, 0.60, 0.90, 0.90);
  //TLegend* legend1 = new TLegend(0.10, 0.60, 0.40, 0.90);
  legend1->AddEntry(hist_cc0pi[1], "CC0#pi", "f");
  legend1->AddEntry(hist_cc1pi[1], "CC1#pi", "f");
  legend1->AddEntry(hist_ccother[1], "CC other", "f");
  legend1->AddEntry(hist_nc[1], "NC", "f");
  legend1->AddEntry(hist_bg[1], "BG", "f");
  legend1->Draw("");
  c7->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/selection2_topology_%d.png",MRD));

  TCanvas* c8 = new TCanvas("c8", "c8", 1000, 800);
  c8->cd();
  hist_num_3track->Draw("");
  hist_num_3track->SetTitle("CC1#pi 3 track sample;;Events(/5.0#times10^{20} P.O.T)");
  c8->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/type_%d.png",MRD));

  TCanvas* c9 = new TCanvas("c9", "c9", 1000, 800);
  c9->cd();
  THStack *stack_topology9 = new THStack("stack_topology9", "");
  hist_cc0pi[5]->SetFillColor(2);
  stack_topology9->Add(hist_cc0pi[5]);
  hist_cc1pi[5]->SetFillColor(4);
  stack_topology9->Add(hist_cc1pi[5]);
  hist_ccother[5]->SetFillColor(6);
  stack_topology9->Add(hist_ccother[5]);
  hist_nc[5]->SetFillColor(7);
  stack_topology9->Add(hist_nc[5]);
  hist_bg[5]->SetFillColor(5);
  stack_topology9->Add(hist_bg[5]);
  stack_topology9->Draw("hist");
  stack_topology9->SetTitle("cc1#pi #mu like 1, p like 2;Angle(degree);Events(/5.0#times10^{20} P.O.T)");

  TLegend* legend9 = new TLegend(0.70, 0.60, 0.90, 0.90);
  legend9->AddEntry(hist_cc0pi[5], "CC0#pi", "f");
  legend9->AddEntry(hist_cc1pi[5], "CC1#pi", "f");
  legend9->AddEntry(hist_ccother[5], "CC other", "f");
  legend9->AddEntry(hist_nc[5], "NC", "f");
  legend9->AddEntry(hist_bg[5], "BG", "f");
  legend9->Draw("");
  c9->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/cc1pi_purity_1_%d.png",MRD));

  TCanvas* c10 = new TCanvas("c10", "c10", 1000, 800);
  c10->cd();
  THStack *stack_topology10 = new THStack("stack_topology10", "");
  hist_cc0pi[6]->SetFillColor(2);
  stack_topology10->Add(hist_cc0pi[6]);
  hist_cc1pi[6]->SetFillColor(4);
  stack_topology10->Add(hist_cc1pi[6]);
  hist_ccother[6]->SetFillColor(6);
  stack_topology10->Add(hist_ccother[6]);
  hist_nc[6]->SetFillColor(7);
  stack_topology10->Add(hist_nc[6]);
  hist_bg[6]->SetFillColor(5);
  stack_topology10->Add(hist_bg[6]);
  stack_topology10->Draw("hist");
  stack_topology10->SetTitle("cc1#pi #mu like 2, p like 1;Angle(degree);Events(/5.0#times10^{20} P.O.T)");

  TLegend* legend10 = new TLegend(0.70, 0.60, 0.90, 0.90);
  legend10->AddEntry(hist_cc0pi[6], "CC0#pi", "f");
  legend10->AddEntry(hist_cc1pi[6], "CC1#pi", "f");
  legend10->AddEntry(hist_ccother[6], "CC other", "f");
  legend10->AddEntry(hist_nc[6], "NC", "f");
  legend10->AddEntry(hist_bg[6], "BG", "f");
  legend10->Draw("");
  c10->SaveAs(Form("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/cc1pi_purity_2_%d.png",MRD));

  /*
  TCanvas* c8 = new TCanvas("c8", "c8", 1000, 1200);
  c8->cd();
  c8->Divide(1, 2);
  c8->cd(1);
  TGraphAsymmErrors* mom_purity_graph_selection2 
    = new TGraphAsymmErrors(36, anglerow, angle_pur_selection2, xerr_selection2, xerr_selection2, yerr_u_selection2, yerr_d_selection2);
  mom_purity_graph_selection2->Draw("AP");
  mom_purity_graph_selection2->SetMarkerStyle(21);
  mom_purity_graph_selection2->SetMarkerColor(2);
  mom_purity_graph_selection2->SetMaximum(1);
  mom_purity_graph_selection2->SetMinimum(0);

  TCanvas* c9 = new TCanvas("c9", "c9", 1000, 1200);
  c9->cd();
  c9->Divide(1, 2);
  c9->cd(1);
  TGraphAsymmErrors* mom_purity_graph_selection3 
    = new TGraphAsymmErrors(36, anglerow, angle_pur_selection3, xerr_selection3, xerr_selection3, yerr_u_selection3, yerr_d_selection3);
  mom_purity_graph_selection3->Draw("AP");
  mom_purity_graph_selection3->SetMarkerStyle(21);
  mom_purity_graph_selection3->SetMarkerColor(2);
  mom_purity_graph_selection3->SetMaximum(1);
  mom_purity_graph_selection3->SetMinimum(0);

  TCanvas* c10 = new TCanvas("c10", "c10", 1000, 1200);
  c10->cd();
  c10->Divide(1, 2);
  c10->cd(1);
  TGraphAsymmErrors* mom_purity_graph_selection4 
    = new TGraphAsymmErrors(36, anglerow, angle_pur_selection4, xerr_selection4, xerr_selection4, yerr_u_selection4, yerr_d_selection4);
  mom_purity_graph_selection4->Draw("AP");
  mom_purity_graph_selection4->SetMarkerStyle(21);
  mom_purity_graph_selection4->SetMarkerColor(2);
  mom_purity_graph_selection4->SetMaximum(1);
  mom_purity_graph_selection4->SetMinimum(0);
  */

  cout << "=========== Event Summary ===========" << '\n';

  cout << "Selection 1" << '\n';
  cout << "Purity = " << num_event_cc0pi_selection1 << "/" << num_event_total_selection1 << " = " << num_event_cc0pi_selection1/num_event_total_selection1 << '\n';
  cout << "cc0pi/cc1pi/ccother/bg : " << num_event_cc0pi_selection1 << "/" << num_event_cc1pi_selection1 << "/" 
       << num_event_ccother_selection1 << "/" << num_event_bg_selection1 << '\n';

  cout << '\n';
  cout << "Selection 2" << '\n';
  cout << "Purity = " << num_event_cc0pi_selection2 << "/" << num_event_total_selection2 << " = " << num_event_cc0pi_selection2/num_event_total_selection2 << '\n';
  cout << "Purity = " << num_event_cc1pi_selection2 << "/" << num_event_total_selection2 << " = " << num_event_cc1pi_selection2/num_event_total_selection2 << '\n';
  cout << "cc0pi/cc1pi/ccother/bg : " << num_event_cc0pi_selection2 << "/" << num_event_cc1pi_selection2 << "/" 
       << num_event_ccother_selection2 << "/" << num_event_bg_selection2 << '\n';

  cout << '\n';
  cout << "Selection 3" << '\n';
  cout << "Purity = " << num_event_cc0pi_selection3 << "/" << num_event_total_selection3 << " = " << num_event_cc0pi_selection3/num_event_total_selection3 << '\n';
  cout << "Purity = " << num_event_cc1pi_selection3 << "/" << num_event_total_selection3 << " = " << num_event_cc1pi_selection3/num_event_total_selection3 << '\n';
  cout << "cc0pi/cc1pi/ccother/bg : " << num_event_cc0pi_selection3 << "/" << num_event_cc1pi_selection3 << "/" 
       << num_event_ccother_selection3 << "/" << num_event_bg_selection3 << '\n';

  cout << '\n';
  cout << "Selection 4" << '\n';
  cout << "Purity = " << num_event_cc0pi_selection4 << "/" << num_event_total_selection4 << " = " << num_event_cc0pi_selection4/num_event_total_selection4 << '\n';
  cout << "cc0pi/cc1pi/ccother/bg : " << num_event_cc0pi_selection4 << "/" << num_event_cc1pi_selection4 << "/" 
       << num_event_ccother_selection4 << "/" << num_event_bg_selection4 << '\n';

/*
  cout << "PM - BM = " << hist_total_event_by_angle[4]->Integral() << '\n';
  cout << "PM - WMRD South = " << hist_total_event_by_angle[1]->Integral() << '\n';
  cout << "PM - WMRD North = " << hist_total_event_by_angle[2]->Integral() << '\n';

  cout << "Bare Purity" << '\n';
  cout << "BM event = "  << num_event_cc0pi[4]/hist_total_event_by_angle[4]->Integral() << '\n'; 
  cout << "WMRD S event = "  << num_event_cc0pi[1]/hist_total_event_by_angle[1]->Integral() << '\n'; 
  cout << "WMRD N event = "  << num_event_cc0pi[2]/hist_total_event_by_angle[2]->Integral() << '\n'; 

  cout << "Selection1 Purity" << '\n';
  cout << "BM event = "  << num_event_cc0pi_selection1[4]/hist_total_event_by_angle_selection1[4]->Integral() <<  " "
       << num_event_cc0pi_selection1[4] << " / " << hist_total_event_by_angle_selection1[4]->Integral() << '\n'; 
  cout << "WMRD S event = "  << num_event_cc0pi_selection1[1]/hist_total_event_by_angle_selection1[1]->Integral() << '\n'; 
  cout << "WMRD N event = "  << num_event_cc0pi_selection1[2]/hist_total_event_by_angle_selection1[2]->Integral() << '\n'; 

  cout << "Selection2 Purity" << '\n';
  cout << "BM event = "  << num_event_cc0pi_selection2[4]/hist_total_event_by_angle_selection2[4]->Integral() << " " 
       << num_event_cc0pi_selection2[4] << " / " << hist_total_event_by_angle_selection2[4]->Integral() << '\n';
  cout << "WMRD S event = "  << num_event_cc0pi_selection2[1]/hist_total_event_by_angle_selection2[1]->Integral() << '\n'; 
  cout << "WMRD N event = "  << num_event_cc0pi_selection2[2]/hist_total_event_by_angle_selection2[2]->Integral() << '\n'; 

  cout << "CC0Pi/CC1Pi/CCother = " << num_event_cc0pi_selection2[4] << "/" << num_event_cc1pi_selection2[4] << "/" << num_event_ccother_selection2[4] << '\n';
*/

}
