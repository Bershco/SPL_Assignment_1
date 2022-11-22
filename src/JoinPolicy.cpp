#include "JoinPolicy.h"
#include "Coalition.h"

const Coalition& MandatesJoinPolicy::join(vector<Coalition> offerers) const
{
	Coalition _c = offerers[0];
	int maxMandates = _c.getMandates();
	for (int i = 0; i < abs(offerers.size()); i++)
		if (offerers[i].getMandates() > maxMandates)
			_c = offerers[i];
	return *(new Coalition(_c)); //resolved
}

JoinPolicy* MandatesJoinPolicy::clone()
{
	return new MandatesJoinPolicy; //TODO check if any work is need in deleting the object
}

const Coalition& LastOfferJoinPolicy::join(vector<Coalition> offerers) const
{
	return offerers[offerers.size() - 1];
}


JoinPolicy* LastOfferJoinPolicy::clone()
{
	return new LastOfferJoinPolicy; //TODO check if any work is need in deleting the object
}

JoinPolicy* JoinPolicy::clone()
{
	return this->clone();
}
