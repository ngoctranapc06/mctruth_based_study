//
// Developed by Kenji Yasutome\
//

#include "SignalEnum.hpp"
#include <stdexcept>
#include <unordered_map>
#include <string>

const std::unordered_map<Topology, std::string, SignalEnumClassHash> Topology_NAMES = {
  {Topology::kccinc,      "CC INCLUSIVE"},
  {Topology::kcc0pi,      "CC0pi"},
  {Topology::kcc1pi,   "CC1pi"},
  {Topology::kccother,   "CC Other"},
  {Topology::knc,      "NC"},
};

const std::unordered_map<Particle, std::string, SignalEnumClassHash> Particle_NAMES = {
  {Particle::kmuplus,      "Mu+"},
  {Particle::kmuminus,      "Mu-"},
  {Particle::kpiplus,   "Pi+"},
  {Particle::kpiminus,   "Pi-"},
  {Particle::kpizero,      "Pi0"},
  {Particle::kproton,      "Proton"},
  {Particle::kelectron,      "Electron"},
  {Particle::kothers,      "Others"},
};
