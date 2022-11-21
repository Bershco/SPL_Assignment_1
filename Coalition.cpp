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
	Agent a = _s->newAgent(pId, agents.at(0).getSelectionPolicy());
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

bool Coalition::operator==(Coalition c)
{
	return ((mandates == c.mandates) && (parties == c.parties) && (agents == c.agents) && (_s == c._s));
}

vector<int> Coalition::getPartyIDs() const
{
	vector<int> partyIDs;
	for (auto p : parties) {
		partyIDs.push_back(p.getId());
	}
	return partyIDs;
}

Coalition::Coalition(const Coalition& other) : mandates(other.mandates), parties(other.parties), agents(other.agents)
{
	_s = new Simulation(*other._s);
}

Coalition& Coalition::operator=(const Coalition& other)
{
	mandates = other.mandates;
	vector<Party> parties(other.parties);
	vector<Agent> agents(other.agents);
	_s = new Simulation(*other._s);
}

Coalition::~Coalition()
{
	delete _s;
}

Coalition::Coalition(Coalition&& other) : mandates(other.mandates), parties(other.parties), agents(other.agents), _s(other._s) {}

Coalition& Coalition::operator=(Coalition&& other)
{
	mandates = other.mandates;
	vector<Party> parties(other.parties);
	vector<Agent> agents(other.agents);
	_s = other._s;
}



