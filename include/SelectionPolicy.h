#ifndef SELECTIONPOLICY
#define SELECTIONPOLICY

class Party;
class Graph;
class Agent;

class SelectionPolicy {
public:
	virtual const Party& select(const Graph& g, int pId, const Agent& a) const = 0;
	virtual SelectionPolicy* clone(SelectionPolicy* policy);
	virtual ~SelectionPolicy() = default;
	
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;
	SelectionPolicy* clone(SelectionPolicy* policy);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	const Party& select(const Graph& g, int pId, const Agent& a) const;
	SelectionPolicy* clone(SelectionPolicy* policy);
};

#endif