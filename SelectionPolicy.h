#pragma once
#include "Party.h"

class SelectionPolicy {
public:
	virtual const Party& select() const = 0;
	Graph g;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select() const;

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select() const;
};