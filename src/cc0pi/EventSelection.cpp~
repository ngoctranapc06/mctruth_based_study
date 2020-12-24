#include "EventSelection.hpp"

#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>


EventSelection::EventSelection(){

  offset_[0][0] = PROTON_MODULE_POS_X;
  offset_[0][1] = PROTON_MODULE_POS_Y;
  offset_[0][2] = PROTON_MODULE_POS_Z;

  offset_[1][0] = WAGASCI_UPSTREAM_POS_X;
  offset_[1][1] = WAGASCI_UPSTREAM_POS_Y;
  offset_[1][2] = WAGASCI_UPSTREAM_POS_Z;

  offset_[2][0] = WAGASCI_DOWNSTREAM_POS_X;
  offset_[2][1] = WAGASCI_DOWNSTREAM_POS_Y;
  offset_[2][2] = WAGASCI_DOWNSTREAM_POS_Z;

  offset_[3][0] = WALLMRD_SOUTH_POS_X;
  offset_[3][1] = WALLMRD_SOUTH_POS_X;
  offset_[3][2] = WALLMRD_SOUTH_POS_Z;

  offset_[4][0] = WALLMRD_NORTH_POS_X;
  offset_[4][1] = WALLMRD_SOUTH_POS_X;
  offset_[4][2] = WALLMRD_SOUTH_POS_Z;

  offset_[5][0] = BABYMIND_POS_X;
  offset_[5][1] = BABYMIND_POS_Y;
  offset_[5][2] = BABYMIND_POS_Z;

  fvlimit[0][0] = 500;
  fvlimit[0][1] = 500;
  fvlimit[0][2] = 300;

  fvlimit[1][0] = 400;
  fvlimit[1][1] = 400;
  fvlimit[1][2] = 150;

  fvlimit[2][0] = 400;
  fvlimit[2][1] = 400;
  fvlimit[2][2] = 150;

  fclimit[3][0] = 170;
  fclimit[3][1] = 500;
  fclimit[3][2] = 600;

  fclimit[4][0] = 170;
  fclimit[4][1] = 500;
  fclimit[4][2] = 600;

  fclimit[5][0] = 1100;
  fclimit[5][1] = 1100;
  fclimit[5][2] = 1800;

}

void EventSelection::Initial(){
  BOOST_LOG_TRIVIAL(info) << "EventSelection";
}

void EventSelection::SetVertexDetector(Int_t detector){
  vertexdetector_ = detector;
}

void EventSelection::SetMRDDetector(Int_t detector){
  mrddetector_ = detector;
}

void EventSelection::SetVertexPos(B2Position vertexpos){ 
  //Double_t vertexx = vertexpos.GetValue().X() - offset_[vertexdetector_][0];
  //Double_t vertexy = vertexpos.GetValue().Y() - offset_[vertexdetector_][1];
  //Double_t vertexz = vertexpos.GetValue().Z() - offset_[vertexdetector_][2];   
  Double_t vertexx = vertexpos.GetValue().X();
  Double_t vertexy = vertexpos.GetValue().Y();
  Double_t vertexz = vertexpos.GetValue().Z();   
  vertexpos_.Set(vertexx, vertexy, vertexz, 0, 0, 0);
}

void EventSelection::SetStopPos(B2Position stoppos){
  Double_t stopx = stoppos.GetValue().X() - offset_[mrddetector_][0];
  Double_t stopy = stoppos.GetValue().Y() - offset_[mrddetector_][1];
  Double_t stopz = stoppos.GetValue().Z() - offset_[mrddetector_][2];   
  stoppos_.Set(stopx, stopy, stopz, 0, 0, 0);
}

Bool_t EventSelection::MatchingCut(std::vector<Int_t> activedetector){
  Bool_t tmdet = false;
  Bool_t mrddet = false;
  Bool_t matching = false;
  Int_t mrd = -1;

  for(int idet=0; idet<3; idet++){
    if(std::find(activedetector.begin(), activedetector.end(), idet)!=activedetector.end()){
      tmdet = true;
      mrd = idet;
    }
  }

  for(int idet=3; idet<6; idet++){
    if(std::find(activedetector.begin(), activedetector.end(), idet)!=activedetector.end()){
      matchingmrd_.push_back(5);
      mrddet = true;
      mrd = idet;
    }
  }

  if(mrddet){
    std::sort(matchingmrd_.begin(), matchingmrd_.end());
    matchingmrd_.erase(std::unique(matchingmrd_.begin(), matchingmrd_.end()), matchingmrd_.end());
  }

  if(tmdet && mrddet){
    matching = true;
    matchingcut_ = true;
    mrddetector_ = mrd;
  }
  
  return matching;
}

Bool_t EventSelection::FVCut(){
  if(vertexpos_.GetValue().X() > -fvlimit[vertexdetector_][0] && vertexpos_.GetValue().X() < fvlimit[vertexdetector_][0]){
    if(vertexpos_.GetValue().Y() > -fvlimit[vertexdetector_][1] && vertexpos_.GetValue().Y() < fvlimit[vertexdetector_][1]){
      if(vertexpos_.GetValue().Z() > -fvlimit[vertexdetector_][2] && vertexpos_.GetValue().Z() < fvlimit[vertexdetector_][2]){
	fvcut_ = true;
      }
    }
  }
  return fvcut_;
}

Bool_t EventSelection::FCCut(){
  
  if(mrddetector_ == 5){
    if(stoppos_.GetValue().X() > -fclimit[mrddetector_][0] && stoppos_.GetValue().X() < fclimit[mrddetector_][0]){
      if(stoppos_.GetValue().Y() > -fclimit[mrddetector_][1] && stoppos_.GetValue().Y() < fclimit[mrddetector_][1]){
	if(stoppos_.GetValue().Z() > -fclimit[mrddetector_][2] && stoppos_.GetValue().Z() < fclimit[mrddetector_][2]){
	  fccut_ = true;
	}
      }
    }
  }//mrddetector

  if(mrddetector_ == 3 || mrddetector_ == 4){
    if(stoppos_.GetValue().X() > -fclimit[mrddetector_][0] && stoppos_.GetValue().X() < fclimit[mrddetector_][0]){
	if(stoppos_.GetValue().Z() > -fclimit[mrddetector_][2] && stoppos_.GetValue().Z() < fclimit[mrddetector_][2]){
	  fccut_ = true;
	}
    }
  }//tmdetector

  BOOST_LOG_TRIVIAL(info) << stoppos_.GetValue().X() << " " << stoppos_.GetValue().Y() << " " << stoppos_.GetValue().Z();

  return fccut_;
}

std::vector<Int_t> EventSelection::GetMatchingMRD() const{
  return matchingmrd_;
}

Int_t EventSelection::GetMRD() const{
  return mrddetector_;
}

B2Position EventSelection::GetVertexPos() const{
  return vertexpos_;
}

Bool_t EventSelection::GetFVCut() const{
  return fvcut_;
}

Bool_t EventSelection::GetFCCut() const{
  return fccut_;
}

Bool_t EventSelection::GetMatchingCut() const{
  return matchingcut_;
}
