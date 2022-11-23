#include "JoinPolicy.h"
#include "Coalition.h"
#include "Party.h"
#include "Agent.h"

Agent* MandatesJoinPolicy::join(vector<Coalition*> offerers, Party& p)
{
	Coalition* _c = offerers[0];
	int maxMandates = _c->getMandates();
	int saveInd = 0;
	for (int i = 0; i < abs(offerers.size()); i++)
		if (offerers[i]->getMandates() > maxMandates) {
			_c = offerers[i];
			saveInd = i;
		}
	return offerers[saveInd]->join(p);
}

JoinPolicy* MandatesJoinPolicy::clone()
{
	return new MandatesJoinPolicy; //TODO check if any work is need in deleting the object
}

Agent* LastOfferJoinPolicy::join(vector<Coalition*> offerers, Party& p)
{
	return offerers[offerers.size()-1]->join(p);
}


JoinPolicy* LastOfferJoinPolicy::clone()
{
	return new LastOfferJoinPolicy; //TODO check if any work is need in deleting the object
}

JoinPolicy* JoinPolicy::clone()
{
	return this->clone();
}
