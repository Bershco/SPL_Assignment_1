#include "SelectionPolicy.h"


const Party& MandatesSelectionPolicy::select(const Graph& g, int pId) const
{
	return g.selectPartyByMandates(pId);
}

const Party& EdgeWeightSelectionPolicy::select(const Graph& g, int pId) const
{
	return g.selectPartyByEdgeWeight(pId);
}