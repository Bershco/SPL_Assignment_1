#include "JoinPolicy.h"
#include "Coalition.h"

const Coalition& MandatesJoinPolicy::join(vector<Coalition&> offerers) const
{
	Coalition _c = offerers.at(0);
	int maxMandates = _c.getMandates();
	for (auto c : offerers) {
		if (c.getMandates() > maxMandates)
			_c = c;
	}
	return _c;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone(MandatesJoinPolicy* policy)
{
	return new MandatesJoinPolicy;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone(LastOfferJoinPolicy* policy)
{
	return new MandatesJoinPolicy;
}

const Coalition& LastOfferJoinPolicy::join(vector<Coalition&> offerers) const
{
	return offerers.at(offerers.size() - 1);
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone(MandatesJoinPolicy* policy)
{
	return new LastOfferJoinPolicy;
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone(LastOfferJoinPolicy* policy)
{
	return new LastOfferJoinPolicy;
}

JoinPolicy* JoinPolicy::clone(JoinPolicy* policy)
{
	return policy->clone(this);
}
