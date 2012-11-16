#include "Lucie/ThirdGeneration/plugins/TopJetFactory.h"

using namespace std;


bool cmp(const std::vector< double > &v0, const std::vector< double > &v1 ){

  if (v0[0] > v1[0])
    return true;
  else 
    return false;
}

TopJetFactory::TopJetFactory( const edm::ParameterSet & iConfig ):
  inputTagJets_(iConfig.getParameter< edm::InputTag >("fatjets") ),   
  weightsfile_( iConfig.getUntrackedParameter< std::string >("weightsfile") ),
  mva_(weightsfile_.c_str())
{
   
  produces < TopJetCollection >   ("topCandidates") ;  
}


TopJetFactory::~TopJetFactory()
{
  ;
}


void
TopJetFactory::beginRun( edm::Run& run,const edm::EventSetup & es )
{
  ;
}


void
TopJetFactory::produce( edm::Event& iEvent, const edm::EventSetup& iSetup )
{

  std::auto_ptr< TopJetCollection >    jOutput(new TopJetCollection());

  //grab jets 
  edm::Handle< BasicJetCollection > jets ;
  int nJets = -10;
  try {
    iEvent.getByLabel( inputTagJets_, jets);
    nJets = jets -> size();
  }
  catch (exception &e)
    {
      cout << "no jets found " << inputTagJets_ << endl;
    }
 
  //loop over jet collection and compute mva, build top jet
  for ( BasicJetCollection::const_iterator it_jet = jets -> begin() ; it_jet != jets -> end() ; it_jet++ ){
   
    double mva = -10.;
       
    //Computes MVA
    if (nJets > 0 ){
      mva = ComputeMVA( it_jet );
    }
    reco::TopJet tj( *it_jet, mva);
    jOutput -> push_back( tj );
  }
 
  iEvent.put( jOutput , "topCandidates" );
  
}


double TopJetFactory::ComputeMVA( const BasicJetCollection::const_iterator it_jet ) {

  double radius          = -1.;
  double sumPtOvernConst = 0.;                       
  double firstBtag_btag  = 0.;                     
  double firstBtag_pt    = 0.;
  double firstBtag_mass  = 0.; 
  double secondBtag_btag = 0.;                     
  double secondBtag_pt   = 0.;
  double secondBtag_mass = 0.;

  //radius - could be / should be added as a top jet class member...
  TString pattern = "aktRecluster([0-9])p([0-9]+)Hadronic";
  TString label   = inputTagJets_.label() ;
  TPRegexp match(pattern);

  if (match.MatchB(label)){
     TObjArray *subStrL   = TPRegexp(pattern).MatchS(label);
     unsigned int i =  (((TObjString *)subStrL->At(1))->GetString()).Atof() ;
     unsigned int d =  (((TObjString *)subStrL->At(2))->GetString()).Atof() ;
     radius = i+d/100.;
   }
  if (radius < 0.) std::cout << "didn't find radius !!\n";

  //info about fat jet constituents
  std::vector<reco::CandidatePtr > Constituents = it_jet -> getJetConstituents();
  std::vector<reco::CandidatePtr >::const_iterator it_const;
  unsigned int nConstituents = Constituents.size();
  std::vector< std::vector< double > > v_btag;             

  for ( it_const = Constituents.begin() ;
	it_const != Constituents.end()  ;
	it_const++)
    {
      const cmg::PFJet* constituent = dynamic_cast< const cmg::PFJet* >(it_const->get());
      sumPtOvernConst+= constituent -> pt();
      std::vector< double > v_tmp;
      v_tmp.push_back( constituent -> btag(6));
      v_tmp.push_back( constituent -> pt()   );
      v_tmp.push_back( constituent -> mass() );
      v_btag.push_back( v_tmp );
    }

  sumPtOvernConst /= nConstituents ;

  if (v_btag.size() == 0){
    std::vector< double > v_tmp;
    v_tmp.push_back( -1. ); // maybe would be better to set it to -10. need to synchronize with training though
    v_tmp.push_back( 0.  );
    v_tmp.push_back( 0. );
    v_btag.push_back( v_tmp );
    v_btag.push_back( v_tmp );
  }
  else if (v_btag.size() == 1){
    std::vector< double > v_tmp;
    v_tmp.push_back( -1. );
    v_tmp.push_back( 0.  );
    v_tmp.push_back( 0. );
    v_btag.push_back( v_tmp );
  }
  std::sort(v_btag.begin(), v_btag.end(), cmp);
  firstBtag_btag  = v_btag[0][0] ;                    
  firstBtag_pt    = v_btag[0][1] ;
  firstBtag_mass  = v_btag[0][2] ; 
  secondBtag_btag = v_btag[1][0] ;                    
  secondBtag_pt   = v_btag[1][1] ;
  secondBtag_mass = v_btag[1][2] ; // it's way more elegant in python...
 
  double mvaValue =   mva_.val(
			       it_jet -> pt(),                        
			       it_jet -> eta(),                       
			       it_jet -> mass(),                       
			       radius,                       
			       sumPtOvernConst,                       
			       firstBtag_btag,                     
			       firstBtag_pt,
			       firstBtag_mass, 
			       secondBtag_btag,                     
			       secondBtag_pt,
			       secondBtag_mass
			       );

  return mvaValue;
}

//define this as a plug-in

DEFINE_FWK_MODULE(TopJetFactory);

//TRASH
//  std::cout << "before sorting\n";
//   for (unsigned int i = 0 ; i < v_btag.size() ; i++){
//     std::cout <<  v_btag[i][0] << " " <<  v_btag[i][1] << " " <<  v_btag[i][2] << "\n ";
//   }
// for (unsigned int i_const = 0; i_const++ < (it_jet -> getJetConstituents()).size(); i_const++ ){
//     std::cout << "in loop\n";
//     sumPtOvernConst+= (it_jet -> getJetConstituents())[i_const] -> pt();
//   }
