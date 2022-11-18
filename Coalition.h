#pragma once
#include "Party.h"
#include <vector>
using std::vector;

class Coalition {
public:
	Coalition(const Party& p);

	int mandates;
	vector<Party> parties;

	int getMandates() const;
	void join(Party& p) const;
	bool checkOffers(Party& p) const;
};