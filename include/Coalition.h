#ifndef COALITION
#define COALITION

#include <vector>
#include "Party.h"
#include "Agent.h"

using std::vector;


class Coalition {
public:
	Coalition(const Party& p, Agent& a, int coalId);

	int getMandates() const;
	Coalition& join(Party& p, int aId);
	Agent& cloneAgent(int pId, int aId);
	bool checkOffers(const Party& p) const;
	bool operator==(Coalition c);
	vector<int> getPartyIDs() const;
	int getId() const;
	void checkMandates();
	bool findAgent(Agent& a);
	int getRepresentativeId();

private:
	int cId;
	int mandates;
	vector<int> partyIds;
	vector<int> agentIds;
};

#endif