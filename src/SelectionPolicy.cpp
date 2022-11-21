#include "SelectionPolicy.h"
#include "Agent.h"
#include "Party.h"
#include "Graph.h"


const Party& MandatesSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByMandates(pId, a);
}

MandatesSelectionPolicy* MandatesSelectionPolicy::clone(MandatesSelectionPolicy* policy)
{
	return new MandatesSelectionPolicy;
	
}

MandatesSelectionPolicy* MandatesSelectionPolicy::clone(EdgeWeightSelectionPolicy* policy)
{
	return new MandatesSelectionPolicy;
}

const Party& EdgeWeightSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByEdgeWeight(pId, a);
}


EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone(MandatesSelectionPolicy* policy)
{
	return new EdgeWeightSelectionPolicy;
	
}

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone(EdgeWeightSelectionPolicy* policy)
{

	return new EdgeWeightSelectionPolicy;
	
}

SelectionPolicy* SelectionPolicy::clone(SelectionPolicy* policy)
{
	return policy->clone(this);
}
