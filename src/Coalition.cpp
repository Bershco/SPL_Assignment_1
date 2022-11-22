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
	for (int i = 0; i < parties.size(); i++) {
		mandates += parties[i].getMandates();
	}
}

void Coalition::join(Party& p)
{
	parties.push_back(p);
	mandates += p.getMandates();
	cloneAgent(p.getId());
}

void Coalition::cloneAgent(int pId)
{
	Agent a(-1,pId,agents[0].getSelectionPolicy());
	a.setCoalId(cId);
	a.setId(abs(agents.size()));
	agents.push_back(a);
}

bool Coalition::checkOffers(const Party& p) const
{
	for (int i = 0; i < agents.size(); i++)
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
	for (int i = 0; i < parties.size(); i++)
		partyIDs.push_back(parties[i].getId());
	return partyIDs;
}

bool Coalition::findAgent(Agent& a) {
	for (int i = 0; i < agents.size(); i++)
		if (agents[i].getId() == a.getId())
			return true;
	return false;
}