#include "SelectionPolicy.h"


const Party& MandatesSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByMandates(pId, a);
}

const Party& EdgeWeightSelectionPolicy::select(const Graph& g, int pId, const Agent& a) const
{
	return g.selectPartyByEdgeWeight(pId, a);
}