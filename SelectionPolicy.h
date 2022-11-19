#pragma once
#include "Party.h"

class SelectionPolicy {
public:
	virtual const Party& select(const Graph& g, int pId, const Agent& a) const = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;
};