#ifndef SELECTIONPOLICY
#define SELECTIONPOLICY

class Party;
class Graph;
class Agent;

class SelectionPolicy {
public:
	virtual const Party& select(const Graph& g, int pId, const Agent& a) const = 0;
	virtual SelectionPolicy* clone(SelectionPolicy* policy);
	
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;
	virtual MandatesSelectionPolicy* clone(MandatesSelectionPolicy* policy);
	virtual MandatesSelectionPolicy* clone(EdgeWeightSelectionPolicy* policy);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;
	virtual EdgeWeightSelectionPolicy* clone(MandatesSelectionPolicy* policy);
	virtual EdgeWeightSelectionPolicy* clone(EdgeWeightSelectionPolicy* policy);
};

#endif