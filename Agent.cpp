#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
#include "Graph.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    offeredParty = -1;
    
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method

    
    Party selected = mSelectionPolicy->select(sim.getGraph(),mPartyId);
    selected.offer(*coal);

}

void Agent::clone(Party& p)
{
    throw _exception();
}

bool Agent::offered(Party& p)
{

    if (p.getId() == offeredParty) {
        return true;
    }
    return false;
}

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}
