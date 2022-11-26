#include "JoinPolicy.h"
#include "Coalition.h"
#include "Party.h"
#include "Simulation.h"

Coalition& MandatesJoinPolicy::join(Simulation& s, vector<int>& offerersIds, Party& p,int aId)
{
	Coalition& _c = s.getCoalById(offerersIds[0]);
	int maxMandates = _c.getMandates();
	int saveInd = 0;
	for (int i = 0; i < abs(offerersIds.size()); i++)
		if (s.getCoalById(offerersIds[i]).getMandates() > maxMandates) {
			_c = s.getCoalById(offerersIds[i]);
			saveInd = i;
		}
	return s.getCoalById(offerersIds[saveInd]).join(p, aId);
}

JoinPolicy* MandatesJoinPolicy::clone()
{
	return new MandatesJoinPolicy; 
}

Coalition& LastOfferJoinPolicy::join(Simulation& s, vector<int>& offerers, Party& p, int aId)
{
	return s.getCoalById(offerers[offerers.size()-1]).join(p, aId);
}


JoinPolicy* LastOfferJoinPolicy::clone()
{
	return new LastOfferJoinPolicy; 
}

JoinPolicy* JoinPolicy::clone()
{
	return this->clone();
}
