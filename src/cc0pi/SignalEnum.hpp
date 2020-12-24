//                                                                                                                                                                                 
// Created by Giorgio Pintaudi on 8/5/20.
// Developed by Kenji Yasutome                                                                                                                                               
//

#ifndef SIGNALSTUDY_ENUM_HH
#define SIGNALSTUDY_ENUM_HH

#include <unordered_map>
#include <string>
#include <cstddef>
#include "B2Const.hh"

struct SignalEnumClassHash {
  template<typename T>
  std::size_t operator()(T t) const {
    return static_cast<std::size_t>(t);
  }
};

enum Topology {
  kccinc = 0,
  kcc0pi = 1,
  kcc1pi = 2,
  kccother = 3,
  knc = 4,

};

const extern std::unordered_map<Topology, std::string, SignalEnumClassHash> Topology_NAMES;
 

enum Particle {
  kmuplus = 0,
  kmuminus = 1,
  kpiplus = 2,
  kpiminus = 3,
  kpizero = 4,
  kproton = 5,
  kelectron = 6,
  kothers = 7,

};

const extern std::unordered_map<Particle, std::string, SignalEnumClassHash> Particle_NAMES;
#endif 
