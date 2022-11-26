#include "Coalition.h"
#include "Agent.h"
#include "Party.h"

Coalition::Coalition(const Party& p, Agent& a, int coalId) : cId(coalId), mandates(p.getMandates()), partyIds(), agentIds() {
	partyIds.push_back(p.getId());
	a.setCoalId(coalId);
	agentIds.push_back(a.getId());
}

int Coalition::getMandates() const
{
	return mandates;
}

int Coalition::getId() const {
	return cId;
}


Coalition& Coalition::join(Party& p, int aId)
{
	partyIds.push_back(p.getId());
	mandates += p.getMandates();
	agentIds.push_back(aId);
	return *this;
}

int Coalition::getRepresentativeId() {
	return agentIds[0];
}



bool Coalition::operator==(Coalition c)
{
	for (int i = 0; i < abs(partyIds.size()); i++) {
		if (partyIds[i] != c.partyIds[i])
			return false;
	}
	for (int i = 0; i < abs(agentIds.size()); i++) {
		if (agentIds[i] != c.agentIds[i])
			return false;
	}
	return (mandates == c.mandates);
}

vector<int> Coalition::getPartyIDs() const
{
	vector<int> partyIDs;
	for (int i = 0; i < abs(partyIds.size()); i++)
		partyIDs.push_back(partyIds[i]);
	return partyIDs;
}

bool Coalition::findAgent(Agent& a) {
	for (int i = 0; i < abs(agentIds.size()); i++)
		if (agentIds[i] == a.getId())
			return true;
	return false;
}