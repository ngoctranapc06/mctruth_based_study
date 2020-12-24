#ifndef _INC_PARTICLETRACK
#define _INC_PARTICLETRACK

// system includes
#include <vector>
#include <iostream>

// ROOT includes
#include <TObject.h>
#include <TVector2.h>

#include "ParticleTrack.hpp"
#include "SignalEnum.hpp"
#include "B2HitSummary.hh"
#include "B2Measurement.hh"

class  ParticleTrack{

public:

  ParticleTrack();
  ~ParticleTrack() = default;

  void Initial();
  void AddHits(const B2HitSummary &hit);
  void SetParticle(Int_t pdg);
  void SetActiveDetector();
  void SetInitialPosition(B2Position initialpos);
  void SetFinalPosition(B2Position finalpos);
  void SetInitialDirection(B2Direction initialdir);
  void SetFinalDirection(B2Direction finaldir);
  void SetEnergy(Double_t energy);

  std::vector<Int_t> GetActiveDetector() const;
  Int_t GetDetectorHits(Int_t detector) const;
  B2Position GetInitialPosition() const;
  B2Position GetFinalPosition() const;
  B2Direction GetInitialDirection() const;
  B2Direction GetFinalDirection() const;
  Double_t GetEnergy() const;
  Double_t GetAngle() const;
  Particle GetParticle() const;

private:

  Particle particle_;
  Int_t num_total_hits_ = 0;
  Int_t num_detector_hits_[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  std::vector<Int_t> activedetector_;
  B2Position initial_position_;
  B2Direction initial_direction_;
  B2Position final_position_;
  B2Direction final_direction_;
  Double_t energy_;
  Double_t angle_;

};

#endif
