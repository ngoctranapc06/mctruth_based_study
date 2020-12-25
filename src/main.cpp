//
// Created by Kenji Yasutome on 2020/12/02.
//

// system includes
#include <string>
#include <cstdlib>
#include <iostream>
#include <math.h>

// boost includes
#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>

// B2MC includes
#include <B2Reader.hh>
#include <B2EventSummary.hh>
#include <B2VertexSummary.hh>
#include <B2TrackSummary.hh>

// project includes
#include "EventMap.hpp"
#include "ParticleTrack.hpp"
#include "EventSelection.hpp"

// ROOT
#include "TTree.h"
#include "TFile.h"

// print_help
// prints an help message with all the arguments taken by the program
void print_help(const char * program_name) {
  std::cout << 
      "  -h         : help\n"
      "  -i (char*) : input ROOT file (mandatory)\n"
      "  -o (char*) : output txt file (default = same as input)\n"
      exit(0);
}

int main(int argc, char *argv[]) {

bool rename = false;
bool renamef = false;

int opt;
char inputfile[300];
char outputfile[300];

while ((opt = getopt(argc, argv, "i:o")) != -1){
  switch(opt){
    case 'i':
    sprintf(inputfile, "%s", optarg);
    rename = true;
    break;
    case 'o':
    sprintf(outputfile, "%s", optarg);
    renamef = true;
    break;
    case 'h':
    default:
    print_help(argv[0]);
    break;
  }
}
  //TString outputfile = "/gpfs/group/t2k/beam/work/yasuken/Latest/testbench/signalstudy/data/test.root";
  //TString outputfile = "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/test.root";
  TFile* ofile = new TFile(outputfile, "RECREATE");
  TTree* tree = new TTree("tree", "tree");
  Int_t event;
  tree->Branch("event", &event, "event/I");
  Int_t inttype;
  tree->Branch("inttype", &inttype, "inttype/I");
  Double_t weight;
  tree->Branch("weight", &weight, "weight/D");
  Int_t matching;
  tree->Branch("matching", &matching, "matching/I");
  Int_t fvcut;
  tree->Branch("fvcut", &fvcut, "fvcut/I");
  Int_t fccut;
  tree->Branch("fccut", &fccut, "fccut/I");

  Double_t angle;
  tree->Branch("angle", &angle, "angle/D");
  Double_t momentum;
  tree->Branch("momentum", &momentum, "momentum/D");
  Int_t mrd;
  tree->Branch("mrd", &mrd, "mrd/I");
  
try {

  //const char inputfile[100] = "/gpfs/group/t2k/beam/work/yasuken/Latest/testbench/data/monte-carlo/outputroot_pm.root";
  //const char inputfile[100] = "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/output_mc/uwg/uwg_mc_numu_run1.root";
  B2Reader reader(inputfile);
  if((!rename)||(gSystem->GetPathInfo(inputfile,fs))){
    cout<<"Cannot open file "<<inputfile<<endl;
    exit(1);
  }

  Int_t ievent=0;
  while (reader.ReadNextSpill() > 0) {

    event = ievent;

    /*
    if(ievent<theevent){
      ievent++;
      continue;
    }

    else if(ievent>theevent)
      break;
    */

    auto &input_spill_summary = reader.GetSpillSummary();

    BOOST_LOG_TRIVIAL(debug) << "Num Track = " << input_spill_summary.GetNumTrueTracks();
    const int numtruetracks = input_spill_summary.GetNumTrueTracks();
    Int_t itrack = 0;
    Int_t muid = -1;
    std::vector<Int_t> matchingtrackid;
    std::vector<Int_t> matchingmrd;

    EventMap eventmap;
    ParticleTrack particletrack[numtruetracks];
    EventSelection eventselection;

    auto it_vertex = input_spill_summary.BeginTrueVertex();
    const auto *vertex = it_vertex.Next();
    BOOST_LOG_TRIVIAL(info) << "Interaction Type = "  << vertex->GetInteractionType() << " Detector = " << vertex->GetDetector();
    
        
    auto it_event = input_spill_summary.BeginTrueEvent();
    const auto *event = it_event.Next();
    BOOST_LOG_TRIVIAL(info) << "Normalization = "  << event->GetNormalization() << " TotalCrossSection = " << event->GetTotalCrossSection();

    eventmap.SetDetector(vertex->GetDetector());
    eventmap.SetTopology(vertex->GetInteractionType());
    eventmap.SetWeight(event->GetNormalization(), event->GetTotalCrossSection(), 1.0);
    BOOST_LOG_TRIVIAL(info) << "Topology = " << Topology_NAMES.at(eventmap.GetTopology());
    BOOST_LOG_TRIVIAL(info) << "Weight = " << eventmap.GetWeight();

    weight = eventmap.GetWeight();
    inttype = eventmap.GetTopology();
    
    auto it_track = input_spill_summary.BeginTrueTrack();
    while  (const auto *track = it_track.Next()) {
      
      BOOST_LOG_TRIVIAL(info) << '\n';
      BOOST_LOG_TRIVIAL(info) << "trackinfo : " << track->GetTrackId() << " Particle = " << track->GetParticlePdg();
      BOOST_LOG_TRIVIAL(info) << "number of hits = " << track->GetNumHits();
      BOOST_LOG_TRIVIAL(info) << "Final position = " << track->GetFinalPosition() << " Initial position = " << track->GetInitialPosition();
      BOOST_LOG_TRIVIAL(info) << track->GetFinalPosition().GetValue().X();
      BOOST_LOG_TRIVIAL(info) << track->GetFinalDirection().GetValue().X();
      BOOST_LOG_TRIVIAL(info) << "Final direction = " << track->GetFinalDirection() << " Initial position = " << track->GetInitialDirection();
      BOOST_LOG_TRIVIAL(info) << "Energy : " << track->GetTotalEnergy() << '\n';
      
      auto it_hit = track->BeginHit();
      while (const auto *hit = it_hit.Next()) {
	//BOOST_LOG_TRIVIAL(debug) << *hit << '\n';
	particletrack[itrack].AddHits(*hit);
      }

      Double_t momentum = sqrt(pow(track->GetTotalEnergy().GetValue(), 2.0) - pow(track->GetMass().GetValue(), 2.0));
      particletrack[itrack].SetParticle(track->GetParticlePdg());
      particletrack[itrack].SetInitialPosition(track->GetInitialPosition());
      particletrack[itrack].SetFinalPosition(track->GetFinalPosition());
      particletrack[itrack].SetInitialDirection(track->GetInitialDirection());
      particletrack[itrack].SetFinalDirection(track->GetFinalDirection());
      particletrack[itrack].SetEnergy(momentum);

      itrack++;
    }//track

    for(int itrack=0; itrack<numtruetracks; itrack++){
      particletrack[itrack].SetActiveDetector();
      BOOST_LOG_TRIVIAL(info) << particletrack[itrack].GetActiveDetector().size();
      for(int i=0; i<particletrack[itrack].GetActiveDetector().size(); i++){
	Int_t det = particletrack[itrack].GetActiveDetector().at(i);
	BOOST_LOG_TRIVIAL(info) << "num hits = " << particletrack[itrack].GetDetectorHits(det);
      }
      if(eventselection.MatchingCut(particletrack[itrack].GetActiveDetector())){
	matchingtrackid.push_back(itrack);
	matchingmrd.push_back(eventselection.GetMRD());
      }
    }

    eventselection.SetVertexDetector(vertex->GetDetector());
    eventselection.SetVertexPos(vertex->GetRelativePosition());
    eventselection.FVCut();

    /*
    for(int i=0; i<eventselection.GetMatchingMRD().size(); i++){
      Int_t mrddetector = eventselection.GetMatchingMRD().at(i);
      BOOST_LOG_TRIVIAL(info) << "Matching MRD= " << mrddetector;
      eventselection.FCCut();
    }
    */

    matching = eventselection.GetMatchingCut();
    fvcut = eventselection.GetFVCut();

    for(int i=0; i<matchingtrackid.size(); i++){
      BOOST_LOG_TRIVIAL(info) << "Matching MRD= " << matchingmrd.at(i)  << " Matching track ID = " << matchingtrackid.at(i) << " particle = " 
			      << Particle_NAMES.at(particletrack[matchingtrackid.at(i)].GetParticle());
      eventselection.SetStopPos(particletrack[matchingtrackid.at(i)].GetFinalPosition());
      eventselection.FCCut();

      angle = particletrack[matchingtrackid.at(i)].GetAngle();
      momentum = particletrack[matchingtrackid.at(i)].GetEnergy();
      mrd = matchingmrd.at(i);
      
      BOOST_LOG_TRIVIAL(info) << angle << " " << momentum;
    }

    fccut = eventselection.GetFCCut();

    BOOST_LOG_TRIVIAL(info) << "X/Y/Z = " << eventselection.GetVertexPos().GetValue().X() << "/" << eventselection.GetVertexPos().GetValue().Y()
			    << "/" << eventselection.GetVertexPos().GetValue().Z() << " FV? " << eventselection.GetFVCut() 
			    << " Matching? " << eventselection.GetMatchingCut() << " FC? " << eventselection.GetFCCut();
    
    ievent++;
    tree->Fill();
  }
  
 } catch (const std::exception &error) {
  BOOST_LOG_TRIVIAL(fatal) << "Program terminated with error : " << error.what();
  std::exit(1);
 }

 ofile->cd();
 tree->Write();
 ofile->Close();

 std::exit(0);
 
}
