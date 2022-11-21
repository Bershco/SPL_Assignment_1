#include "Coalition.h"

Coalition::Coalition(const Party& p, const Agent& a, Simulation* s) : cId(a.getCoalId()), mandates(p.getMandates()), parties(vector<Party>()), agents(vector<Agent>()), _s(s) {
	parties.push_back(p);
	agents.push_back(a);
}

int Coalition::getMandates() const
{
	return mandates;
}

int Coalition::getId() const {
	return cId;
}

void Coalition::checkMandates() {
	mandates = 0;
	for (auto p : parties)
		mandates += p.getMandates();
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
	a.setCoalId(cId);
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
	for (int i = 0; i < abs(parties.size()); i++) {
		if (parties[i].getId() != c.parties[i].getId())
			return false;
	}
	for (int i = 0; i < abs(agents.size()); i++) {
		if (agents[i].getId() != c.agents[i].getId())
			return false;
	}
	return (mandates == c.mandates) && (_s == c._s);
}

vector<int> Coalition::getPartyIDs() const
{
	vector<int> partyIDs;
	for (auto p : parties) {
		partyIDs.push_back(p.getId());
	}
	return partyIDs;
}

Coalition::Coalition(const Coalition& other) : cId(other.cId), mandates(other.mandates), parties(other.parties), agents(other.agents),_s(new Simulation(*other._s))
{}

Coalition& Coalition::operator=(const Coalition& other)
{
	mandates = other.mandates;
	parties.clear();
	vector<Party> parties(other.parties);
	agents.clear();
	vector<Agent> agents(other.agents);
	_s = new Simulation(*other._s);

	return *this;
}

Coalition::~Coalition()
{
	delete _s;
}

Coalition::Coalition(Coalition&& other) : cId(other.cId), mandates(other.mandates), parties(other.parties), agents(other.agents), _s(other._s) 
{
	other.parties.clear();
	other.agents.clear();
	other._s = 0; //nullptr
	
}

Coalition& Coalition::operator=(Coalition&& other)
{
	if (this != &other) {
		mandates = other.mandates;
		parties.clear();
		vector<Party> parties(other.parties);
		other.parties.clear();
		agents.clear();
		vector<Agent> agents(other.agents);
		other.agents.clear();
		_s = other._s;
		
	}
	return *this;
}



