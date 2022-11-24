#include "JoinPolicy.h"
#include "Coalition.h"
#include "Party.h"
#include "Agent.h"
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
	return new MandatesJoinPolicy; //TODO check if any work is need in deleting the object
}

Coalition& LastOfferJoinPolicy::join(Simulation& s, vector<int>& offerers, Party& p, int aId)
{
	return s.getCoalById(offerers[offerers.size()-1]).join(p, aId);
}


JoinPolicy* LastOfferJoinPolicy::clone()
{
	return new LastOfferJoinPolicy; //TODO check if any work is need in deleting the object
}

JoinPolicy* JoinPolicy::clone()
{
	return this->clone();
}
