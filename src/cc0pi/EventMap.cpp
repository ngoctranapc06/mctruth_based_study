#include "EventMap.hpp"

#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>

EventMap::EventMap() = default;

void EventMap::Initial(){
  BOOST_LOG_TRIVIAL(info) << "EventMap";  
}

void EventMap::SetTopology(Int_t interactiontype) {
  interactiontype_ = interactiontype;
  if(fabs(interactiontype) < 30){
    if(fabs(interactiontype) <= 2)
      topology_ = kcc0pi;
    else if(fabs(interactiontype) > 10 && fabs(interactiontype) <= 16)
      topology_ = kcc1pi;
    else {
      topology_ = kccother;
    }
  }
  else{
    topology_ = knc;
  }
}

void EventMap::SetDetector(Int_t detector) {
  detector_ = detector;
}

void EventMap::SetWeight(Double_t norm, Double_t totalxsec, Double_t constant) {
  Double_t weight;
  Double_t N_A = 6.0 * pow(10, 23);
  Double_t xsecvalue = pow(10, -38);
  Double_t thick;
  if(detector_ == 0){
    thick = 46.2;    
  }

  if(detector_ == 1 || detector_ == 2){
    thick = 50.0 + 0.8*7.98;    
  }

  if(detector_ == -1){
    thick =470*2.2;
  }

  weight_ = N_A * xsecvalue * norm * totalxsec * thick;
}

Topology EventMap::GetTopology() const{
  return topology_;
}

Double_t EventMap::GetWeight() const{
  return weight_;
}
