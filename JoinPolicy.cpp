#include "JoinPolicy.h"

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

const Coalition& LastOfferJoinPolicy::join(vector<Coalition&> offerers) const
{
	return offerers.at(offerers.size() - 1);
}
