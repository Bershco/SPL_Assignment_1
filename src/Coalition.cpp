#include "Coalition.h"

Coalition::Coalition(const Party& p, Agent& a, int coalId) : cId(coalId), mandates(p.getMandates()), parties(vector<Party>()), agents(vector<Agent>()) {
	parties.push_back(p);
	a.setCoalId(coalId);
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
	for (int i = 0; i < abs(parties.size()); i++) {
		mandates += parties[i].getMandates();
	}
}

Agent* Coalition::join(Party& p, int aId)
{
	parties.push_back(p);
	mandates += p.getMandates();
	return cloneAgent(p.getId(), aId);
}

Agent* Coalition::cloneAgent(int pId, int aId)
{
	Agent* a = new Agent(-1,pId,agents[0].getSelectionPolicy());
	a->setCoalId(cId);
	a->setId(aId);
	agents.push_back(*a);
	return a;
}

bool Coalition::checkOffers(const Party& p) const
{
	for (int i = 0; i < abs(agents.size()); i++)
		if (agents[i].offered(p))
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
	return (mandates == c.mandates);
}

vector<int> Coalition::getPartyIDs() const
{
	vector<int> partyIDs;
	for (int i = 0; i < abs(parties.size()); i++)
		partyIDs.push_back(parties[i].getId());
	return partyIDs;
}

bool Coalition::findAgent(Agent& a) {
	for (int i = 0; i < abs(agents.size()); i++)
		if (agents[i].getId() == a.getId())
			return true;
	return false;
}