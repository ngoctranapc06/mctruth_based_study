#include <iostream>
using namespace std;

void kinematics_dist(){

  TString histname;

  TChain *tchain = new TChain("tree", "tree");
  Int_t nfile = 300;
  for(int ifile=0; ifile<nfile; ifile++){
    TString filename;
    filename.Form("/gpfs/group/t2k/beam/work/yasuken/Latest/testbench/data/signaldef/test_all_%d.root", ifile);
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
  Double_t vertex[3];
  tchain->SetBranchAddress("vertex", vertex);
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

  TH1D* hist_cc0pi[5];
  TH1D* hist_cc1pi[5];
  TH1D* hist_ccother[5];
  TH1D* hist_nc[5];
  TH1D* hist_bg[5];

  histname.Form("hist_cc0pi_ntrack");
  hist_cc0pi[0] = new TH1D(histname,"", 10, 0, 10);
  histname.Form("hist_cc1pi_ntrack");
  hist_cc1pi[0] = new TH1D(histname,"", 10, 0, 10);
  histname.Form("hist_other_ntrack");
  hist_ccother[0] = new TH1D(histname,"", 10, 0, 10);
  histname.Form("hist_nc_ntrack");
  hist_nc[0] = new TH1D(histname,"", 10, 0, 10);
  histname.Form("hist_bg_ntrack");
  hist_bg[0] = new TH1D(histname,"", 10, 0, 10);

  histname.Form("hist_cc0pi_posx");
  hist_cc0pi[1] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_cc1pi_posx");
  hist_cc1pi[1] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_other_posx");
  hist_ccother[1] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_nc_posx");
  hist_nc[1] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_bg_posx");
  hist_bg[1] = new TH1D(histname,"", 40, -1000, 1000);

  histname.Form("hist_cc0pi_posy");
  hist_cc0pi[2] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_cc1pi_posy");
  hist_cc1pi[2] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_other_posy");
  hist_ccother[2] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_nc_posy");
  hist_nc[2] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_bg_posy");
  hist_bg[2] = new TH1D(histname,"", 40, -1000, 1000);

  histname.Form("hist_cc0pi_posz");
  hist_cc0pi[3] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_cc1pi_posz");
  hist_cc1pi[3] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_other_posz");
  hist_ccother[3] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_nc_posz");
  hist_nc[3] = new TH1D(histname,"", 40, -1000, 1000);
  histname.Form("hist_bg_posz");
  hist_bg[3] = new TH1D(histname,"", 40, -1000, 1000);

  for(int ientry=0; ientry<nentry; ientry++){
    tchain->GetEntry(ientry);
    weight = weight/nfile*0.5;

    if(vertexdetector==0){
      if(inttype==1){
	hist_cc0pi[0]->Fill(ntrack, weight);
	hist_cc0pi[1]->Fill(vertex[0], weight);
	hist_cc0pi[2]->Fill(vertex[1], weight);
	hist_cc0pi[3]->Fill(vertex[2], weight);
      }
      
      else if(inttype==2){
	hist_cc1pi[0]->Fill(ntrack, weight);
	hist_cc1pi[1]->Fill(vertex[0], weight);
	hist_cc1pi[2]->Fill(vertex[1], weight);
	hist_cc1pi[3]->Fill(vertex[2], weight);
      }
      
      else if(inttype==3){
	hist_ccother[0]->Fill(ntrack, weight);
	hist_ccother[1]->Fill(vertex[0], weight);
	hist_ccother[2]->Fill(vertex[1], weight);
	hist_ccother[3]->Fill(vertex[2], weight);
      }
      
      else if(inttype==4){
	hist_nc[0]->Fill(ntrack, weight);
	hist_nc[1]->Fill(vertex[0], weight);
	hist_nc[2]->Fill(vertex[1], weight);
	hist_nc[3]->Fill(vertex[2], weight);
      }
    }

    else{
      hist_bg[0]->Fill(ntrack, weight);
      hist_bg[1]->Fill(vertex[0], weight);
      hist_bg[2]->Fill(vertex[1], weight);
      hist_bg[3]->Fill(vertex[2], weight);
    }
      
  }//ientry

  TCanvas* c1 = new TCanvas("c1", "c1", 1000, 600);
  THStack *stack_ntrack = new THStack("stack_ntrack", "");
  hist_cc0pi[0]->SetFillColor(2);
  stack_ntrack->Add(hist_cc0pi[0]);
  hist_cc1pi[0]->SetFillColor(4);
  stack_ntrack->Add(hist_cc1pi[0]);
  hist_ccother[0]->SetFillColor(6);
  stack_ntrack->Add(hist_ccother[0]);
  hist_nc[0]->SetFillColor(7);
  stack_ntrack->Add(hist_nc[0]);
  hist_bg[0]->SetFillColor(5);
  stack_ntrack->Add(hist_bg[0]);
  stack_ntrack->Draw("hist");
  stack_ntrack->SetTitle("The number of track;the number of track;Events(/5.0#times10^{20} P.O.T)");

  //TLegend* legend3 = new TLegend(0.70, 0.60, 0.90, 0.90);
  TLegend* legend = new TLegend(0.75, 0.60, 0.90, 0.90);
  legend->AddEntry(hist_cc0pi[0], "CC0#pi", "f");
  legend->AddEntry(hist_cc1pi[0], "CC1#pi", "f");
  legend->AddEntry(hist_ccother[0], "CC other", "f");
  legend->AddEntry(hist_nc[0], "NC", "f");
  legend->AddEntry(hist_bg[0], "BG", "f");
  legend->Draw("");
  c1->SaveAs("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/ntrack_topology.png");

  TCanvas* c2 = new TCanvas("c2", "c2", 1000, 600);
  THStack *stack_posx = new THStack("stack_posx", "");
  hist_cc0pi[1]->SetFillColor(2);
  stack_posx->Add(hist_cc0pi[1]);
  hist_cc1pi[1]->SetFillColor(4);
  stack_posx->Add(hist_cc1pi[1]);
  hist_ccother[1]->SetFillColor(6);
  stack_posx->Add(hist_ccother[1]);
  hist_nc[1]->SetFillColor(7);
  stack_posx->Add(hist_nc[1]);
  hist_bg[1]->SetFillColor(5);
  stack_posx->Add(hist_bg[1]);
  stack_posx->Draw("hist");
  stack_posx->SetTitle("Vertex X;PosX (mm);Events(/5.0#times10^{20} P.O.T)");
  stack_posx->SetMaximum(3000);

  TLegend* legend1 = new TLegend(0.75, 0.60, 0.90, 0.90);
  legend1->AddEntry(hist_cc0pi[1], "CC0#pi", "f");
  legend1->AddEntry(hist_cc1pi[1], "CC1#pi", "f");
  legend1->AddEntry(hist_ccother[1], "CC other", "f");
  legend1->AddEntry(hist_nc[1], "NC", "f");
  legend1->AddEntry(hist_bg[1], "BG", "f");
  legend1->Draw("");
  c2->SaveAs("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/posx_topology.png");

  TCanvas* c3 = new TCanvas("c3", "c3", 1000, 600);
  THStack *stack_posy = new THStack("stack_posy", "");
  hist_cc0pi[2]->SetFillColor(2);
  stack_posy->Add(hist_cc0pi[2]);
  hist_cc1pi[2]->SetFillColor(4);
  stack_posy->Add(hist_cc1pi[2]);
  hist_ccother[2]->SetFillColor(6);
  stack_posy->Add(hist_ccother[2]);
  hist_nc[2]->SetFillColor(7);
  stack_posy->Add(hist_nc[2]);
  hist_bg[2]->SetFillColor(5);
  stack_posy->Add(hist_bg[2]);
  stack_posy->Draw("hist");
  stack_posy->SetTitle("Vertex Y;PosY (mm);Events(/5.0#times10^{20} P.O.T)");
  stack_posy->SetMaximum(3000);

  TLegend* legend2 = new TLegend(0.75, 0.60, 0.90, 0.90);
  legend2->AddEntry(hist_cc0pi[2], "CC0#pi", "f");
  legend2->AddEntry(hist_cc1pi[2], "CC1#pi", "f");
  legend2->AddEntry(hist_ccother[2], "CC other", "f");
  legend2->AddEntry(hist_nc[2], "NC", "f");
  legend2->AddEntry(hist_bg[2], "BG", "f");
  legend2->Draw("");
  c3->SaveAs("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/posy_topology.png");

  TCanvas* c4 = new TCanvas("c4", "c4", 1000, 600);
  THStack *stack_posz = new THStack("stack_posz", "");
  hist_cc0pi[3]->SetFillColor(2);
  stack_posz->Add(hist_cc0pi[3]);
  hist_cc1pi[3]->SetFillColor(4);
  stack_posz->Add(hist_cc1pi[3]);
  hist_ccother[3]->SetFillColor(6);
  stack_posz->Add(hist_ccother[3]);
  hist_nc[3]->SetFillColor(7);
  stack_posz->Add(hist_nc[3]);
  hist_bg[3]->SetFillColor(5);
  stack_posz->Add(hist_bg[3]);
  stack_posz->Draw("hist");
  stack_posz->SetTitle("Vertex Z;PosZ (mm);Events(/5.0#times10^{20} P.O.T)");
  stack_posz->SetMaximum(4000);

  TLegend* legend3 = new TLegend(0.70, 0.60, 0.90, 0.90);
  legend3->AddEntry(hist_cc0pi[3], "CC0#pi", "f");
  legend3->AddEntry(hist_cc1pi[3], "CC1#pi", "f");
  legend3->AddEntry(hist_ccother[3], "CC other", "f");
  legend3->AddEntry(hist_nc[3], "NC", "f");
  legend3->AddEntry(hist_bg[3], "BG", "f");
  legend3->Draw("");
  c4->SaveAs("/gpfs/group/t2k/beam/work/yasuken/Latest/wagasci-babymind-mctruth-based-study/plots/posz_topology.png");



}
