#include "Coalition.h"

Coalition::Coalition(const Party& p) : mandates(0), parties(vector<Party>()), agents(vector<Agent>()) {
	parties.push_back(p);
}

Coalition::Coalition() {}

int Coalition::getMandates() const
{
	return mandates;
}

void Coalition::join(Party& p)
{
	parties.push_back(p);
	mandates += p.getMandates();
}

bool Coalition::checkOffers(Party& p) const
{
	for (auto a : agents)
		if (a.offered(p))
			return true;
	return false;
}



