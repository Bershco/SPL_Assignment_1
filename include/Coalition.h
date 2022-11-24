#ifndef COALITION
#define COALITION

#include <vector>



using std::vector;
class Agent;
class Party;

class Coalition {
public:
	Coalition(const Party& p, Agent& a, int coalId);

	int getMandates() const;
	Coalition& join(Party& p, int aId);
	bool operator==(Coalition c);
	vector<int> getPartyIDs() const;
	int getId() const;
	bool findAgent(Agent& a);
	int getRepresentativeId();

private:
	int cId;
	int mandates;
	vector<int> partyIds;
	vector<int> agentIds;
};

#endif