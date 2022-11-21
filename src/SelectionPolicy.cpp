#include "SelectionPolicy.h"
#include "Agent.h"
#include "Party.h"
#include "Graph.h"


const Party& MandatesSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByMandates(pId, a);
}

SelectionPolicy* MandatesSelectionPolicy::clone(SelectionPolicy* policy)
{
	return new MandatesSelectionPolicy;
	
}

const Party& EdgeWeightSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByEdgeWeight(pId, a);
}


SelectionPolicy* EdgeWeightSelectionPolicy::clone(SelectionPolicy* policy)
{

	return new EdgeWeightSelectionPolicy;
	
}

SelectionPolicy* SelectionPolicy::clone(SelectionPolicy* policy)
{
	return policy->clone(this);
}
