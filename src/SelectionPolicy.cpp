#include "SelectionPolicy.h"
#include "Agent.h"
#include "Party.h"
#include "Graph.h"


Party& MandatesSelectionPolicy::select(Graph& g, int pId, const Agent& a)
{
	return g.selectPartyByMandates(pId, a);
}

SelectionPolicy* MandatesSelectionPolicy::clone()
{
	return new MandatesSelectionPolicy; 
	
}

Party& EdgeWeightSelectionPolicy::select(Graph& g, int pId, const Agent& a)
{
	return g.selectPartyByEdgeWeight(pId, a);
}


SelectionPolicy* EdgeWeightSelectionPolicy::clone()
{

	return new EdgeWeightSelectionPolicy; 
	
}

SelectionPolicy* SelectionPolicy::clone()
{
	return this->clone();
}