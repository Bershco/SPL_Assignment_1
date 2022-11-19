#pragma once
#include "Party.h"

class SelectionPolicy {
public:
	virtual const Party& select(const Graph& g, int pId) const = 0;
	Graph g;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select(const Graph& g, int pId) const;

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select(const Graph& g, int pId) const;
};