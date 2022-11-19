#include "Coalition.h"

Coalition::Coalition(const Party& p, const Agent& a, Simulation* s) : mandates(0), parties(vector<Party>()), agents(vector<Agent>()) {
	parties.push_back(p);
	agents.push_back(a);
	_s = s;
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
	cloneAgent(p.getId());
}

void Coalition::cloneAgent(int pId)
{
	SelectionPolicy* selPol = agents.at(0).getSelectionPolicy();
	Agent a = _s->newAgent(pId,selPol);
	a.setCoal(*this);
	agents.push_back(a);
}

bool Coalition::checkOffers(const Party& p) const
{
	for (auto a : agents)
		if (a.offered(p))
			return true;
	return false;
}



