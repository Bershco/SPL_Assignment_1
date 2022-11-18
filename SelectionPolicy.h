#pragma once
#include "Party.h"

class SelectionPolicy {
public:
	virtual const Party& select(const vector<Party>& p) const = 0;
	Graph g;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select(const vector<Party>& p) const;

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select(const vector<Party>& p) const;
};