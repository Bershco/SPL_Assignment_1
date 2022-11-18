#pragma once
#include "Party.h"
#include <vector>
using std::vector;

class Coalition {
public:
	Coalition(const Party& p);
	Coalition();

	int getMandates() const;
	void join(Party& p);
	bool checkOffers(Party& p) const;

private:
	int mandates;
	vector<Party> parties;
	vector<Agent> agents;
};