#ifndef _INC_EVENTMAP
#define _INC_EVENTMAP

// system includes
#include <vector>
#include <iostream>

// ROOT includes
#include <TObject.h>
#include <TVector2.h>

#include "EventMap.hpp"
#include "SignalEnum.hpp"
#include "B2HitSummary.hh"

class  EventMap{

public:

  EventMap();
  ~EventMap() = default;

  void Initial();
  void SetDetector(Int_t detector);
  void SetTopology(Int_t interactiontype);
  void SetWeight(Double_t norm, Double_t totalxsec, Double_t constant);

  Topology GetTopology() const;
  Double_t GetWeight() const;

private:

  Int_t detector_;
  Topology topology_;
  Int_t interactiontype_;
  Double_t weight_;
  

};

#endif
