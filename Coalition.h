#pragma once
#include "Party.h"
#include "Simulation.h"
#include <vector>
using std::vector;

class Coalition {
public:
	Coalition(const Party& p, const Agent& a, Simulation* s);
	Coalition();

	int getMandates() const;
	void join(Party& p);
	void cloneAgent(int pId);
	bool checkOffers(const Party& p) const;

private:
	int mandates;
	vector<Party> parties;
	vector<Agent> agents;
	Simulation* _s;
};