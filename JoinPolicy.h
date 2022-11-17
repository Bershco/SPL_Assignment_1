#pragma once
#include "Graph.h"

class JoinPolicy {
public:
	virtual const Party& join() const = 0;
	Graph g;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	const Party& join() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	const Party& join() const;
};