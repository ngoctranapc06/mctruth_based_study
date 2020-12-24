#include "ParticleTrack.hpp"
#include <math.h>
#include "TMath.h"

#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>

ParticleTrack::ParticleTrack() = default;

void ParticleTrack::Initial(){
  BOOST_LOG_TRIVIAL(info) << "ParticleTrack";  
}

void ParticleTrack::SetParticle(Int_t pdg){
  if(pdg == 13)
    particle_ = kmuplus;

  else if(pdg == -13)
    particle_ = kmuminus;

  else if(pdg == 211)
    particle_ = kpiplus;

  else if(pdg == -211)
    particle_ = kpiminus;

  else if(pdg == 111)
    particle_ = kpizero;

  else if(pdg == 2212)
    particle_ = kproton;

  else if(pdg == 11)
    particle_ = kelectron;

  else
    particle_ = kothers;
}

void ParticleTrack::AddHits(const B2HitSummary &hit){
  //BOOST_LOG_TRIVIAL(debug) << hit.GetDetectorId();
  Int_t detector =  hit.GetDetectorId();
  num_total_hits_ ++;
  num_detector_hits_[detector]++;
  activedetector_.push_back(detector);
}

void ParticleTrack::SetActiveDetector(){
  std::sort(activedetector_.begin(), activedetector_.end());
  activedetector_.erase(std::unique(activedetector_.begin(), activedetector_.end()), activedetector_.end());
}

void ParticleTrack::SetInitialPosition(B2Position initialpos){
  initial_position_ = initialpos;
}
void ParticleTrack::SetFinalPosition(B2Position finalpos){
  final_position_ = finalpos;
}
void ParticleTrack::SetInitialDirection(B2Direction initialdir){
  initial_direction_ = initialdir;
  Double_t internalproduct = initialdir.GetValue().Z();
  Double_t distance = sqrt(pow(initialdir.GetValue().X(), 2) + pow(initialdir.GetValue().Y(), 2) + pow(initialdir.GetValue().Z(), 2));
  angle_ = TMath::ACos(internalproduct/distance)*180/TMath::Pi();

}
void ParticleTrack::SetFinalDirection(B2Direction finaldir){
  final_direction_ = finaldir;
}
void ParticleTrack::SetEnergy(Double_t energy){
  energy_ = energy;
}

std::vector<Int_t> ParticleTrack::GetActiveDetector() const{
  return activedetector_;
}

Int_t ParticleTrack::GetDetectorHits(Int_t detector) const{
  return num_detector_hits_[detector];
}

B2Position ParticleTrack::GetInitialPosition() const{
  return initial_position_;
}
B2Position ParticleTrack::GetFinalPosition() const{
  return final_position_;
}
B2Direction ParticleTrack::GetInitialDirection() const{
  return initial_direction_;
}
B2Direction ParticleTrack::GetFinalDirection() const{
  return final_direction_;
}

Double_t ParticleTrack::GetEnergy() const{
  return energy_;
}

Double_t ParticleTrack::GetAngle() const{
  return angle_;
}

Particle ParticleTrack::GetParticle() const{
  return particle_;
}
