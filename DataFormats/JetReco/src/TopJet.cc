// BasicJet.cc
// Fedor Ratnikov, UMd
// $Id: BasicJet.cc,v 1.4 2007/09/20 21:04:58 fedor Exp $

#include <sstream>

//Own header file
#include "DataFormats/JetReco/interface/TopJet.h"

using namespace reco;


TopJet::TopJet (const LorentzVector& fP4, const Point& fVertex, const float topTag) 
  : BasicJet (fP4, fVertex), mTopTag(topTag)
{}

TopJet::TopJet (const LorentzVector& fP4, const Point& fVertex, const reco::Jet::Constituents& fConstituents, const float topTag) 
  : BasicJet (fP4, fVertex, fConstituents), mTopTag(topTag)
{}

TopJet::TopJet (const BasicJet& jet, const float topTag)
  : BasicJet( jet.p4(), jet.vertex(), jet.getJetConstituents()), mTopTag(topTag)
{}

TopJet* TopJet::clone () const {
  return new TopJet (*this);
}

bool TopJet::overlap( const Candidate & ) const {
  return false;
}

std::string TopJet::print () const {
  std::ostringstream out;
  out << Jet::print () // generic jet info
      << "    TopJet specific: None" << std::endl;
  return out.str ();
}
