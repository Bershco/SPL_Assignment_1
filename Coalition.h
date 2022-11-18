#pragma once
#include "Party.h"
#include <vector>
using std::vector;

class Coalition {
public:
	Coalition(const Party& p);

	int getMandates() const;
	void join(Party& p) const;
	bool checkOffers(Party& p) const;

private:
	int mandates;
	vector<Party> parties;
};