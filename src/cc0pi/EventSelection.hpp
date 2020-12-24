#ifndef _INC_EVENTSELECTION
#define _INC_EVENTSELECTION

// system includes
#include <vector>
#include <iostream>

// ROOT includes
#include <TObject.h>
#include <TVector2.h>

#include "EventSelection.hpp"
#include "B2HitSummary.hh"
#include "B2Const.hh"

class  EventSelection{

public:

  EventSelection();
  ~EventSelection() = default;

  void Initial();
  void SetVertexDetector(Int_t detector);
  void SetMRDDetector(Int_t detector);
  void SetVertexPos(B2Position vertexpos);
  void SetStopPos(B2Position stoppos);

  Bool_t MatchingCut(std::vector<Int_t> activedetector);
  Bool_t FVCut();
  Bool_t FCCut();

  std::vector<Int_t> GetMatchingMRD() const;
  Int_t GetMRD() const;
  B2Position GetVertexPos()const;
  Bool_t GetFVCut() const;
  Bool_t GetFCCut() const;
  Bool_t GetMatchingCut() const;  

private:
  B2Position vertexpos_;
  B2Position stoppos_;
  Int_t vertexdetector_;
  Int_t mrddetector_;
  std::vector<Int_t> matchingmrd_;
  Double_t offset_[6][3];
  Double_t fvlimit[3][3];
  Double_t fclimit[6][3];
  Bool_t fvcut_ = false;
  Bool_t fccut_ = false;
  Bool_t matchingcut_ = false;

};

#endif
