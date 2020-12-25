#include <iostream>
using namespace std;

void particle_kinematics(){

  TString histname;

  TChain *tchain = new TChain("tree", "tree");
  Int_t nfile = 100;
  for(int ifile=0; ifile<nfile; ifile++){
    TString filename;
    filename.Form("/gpfs/group/t2k/beam/work/yasuken/Latest/testbench/data/signaldef/pion_kinematics_%d.root", ifile);
    tchain->Add(filename);
  }

  Int_t event;
  tchain->SetBranchAddress("event", &event);
  Int_t inttype;
  tchain->SetBranchAddress("inttype", &inttype);
  Int_t flavor;
  tchain->SetBranchAddress("flavor", &flavor);
  Double_t weight;
  tchain->SetBranchAddress("weight", &weight);

  std::vector<Double_t> *angle = new std::vector<Double_t>;
  tchain->SetBranchAddress("angle", &angle);
  std::vector<Double_t> *momentum = new std::vector<Double_t>;
  tchain->SetBranchAddress("momentum", &momentum);

  TH1D* pion_angle = new TH1D("pion_angle", "pion_angle", 100, 0, 180);

  Int_t nentry = tchain->GetEntries();
  cout << "nentry = " << nentry << '\n';

  for(int ientry=0; ientry<nentry; ientry++){
    tchain->GetEntry(ientry);
    weight = weight/nfile*0.5;

    for(int i=0; i<angle->size(); i++){
      pion_angle->Fill(angle->at(i));
    }

  }//ientry

  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 600);
  c1->cd();
  pion_angle->Draw("");
  
}
