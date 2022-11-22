#include "SelectionPolicy.h"
#include "Agent.h"
#include "Party.h"
#include "Graph.h"


const Party& MandatesSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByMandates(pId, a);
}

SelectionPolicy* MandatesSelectionPolicy::clone()
{
	return new MandatesSelectionPolicy; //TODO check if any work is need in deleting the object
	
}

const Party& EdgeWeightSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByEdgeWeight(pId, a);
}


SelectionPolicy* EdgeWeightSelectionPolicy::clone()
{

	return new EdgeWeightSelectionPolicy; //TODO check if any work is need in deleting the object
	
}

SelectionPolicy* SelectionPolicy::clone()
{
	return this->clone();
}
