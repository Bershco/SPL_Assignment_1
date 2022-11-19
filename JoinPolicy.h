#pragma once
#include "Graph.h"

class JoinPolicy {
public:
	virtual const Coalition& join(vector<Coalition&>) const = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition&>) const;
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition&>) const;
};