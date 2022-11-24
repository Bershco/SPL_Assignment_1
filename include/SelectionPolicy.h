#ifndef SELECTIONPOLICY
#define SELECTIONPOLICY

class Party;
class Graph;
class Agent;

class SelectionPolicy {
public:
	virtual Party& select(Graph& g, int pId, const Agent& a) = 0;
	virtual SelectionPolicy* clone();
	virtual ~SelectionPolicy() = default;
	
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
	Party& select(Graph& g, int pId, const Agent& a);
	SelectionPolicy* clone();
	
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
	Party& select(Graph& g, int pId, const Agent& a);
	SelectionPolicy* clone();
	
};

#endif