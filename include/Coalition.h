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
	Agent* join(Party& p);
	Agent* cloneAgent(int pId);
	bool checkOffers(const Party& p) const;
	bool operator==(Coalition c);
	vector<int> getPartyIDs() const;
	int getId() const;
	void checkMandates();
	bool findAgent(Agent& a);

private:
	int cId;
	int mandates;
	vector<Party> parties;
	vector<Agent> agents;
};

#endif