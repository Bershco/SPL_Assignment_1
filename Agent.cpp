#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
#include "Graph.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{}

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
    Party p = mSelectionPolicy->select(sim.getGraph(), mPartyId, *this);
    offeredParties.push_back(p);
    p.receiveOffer(coal);
}

bool Agent::offered(const Party& p) const
{
    for (auto _p : offeredParties) {
        if (p.getId() == _p.getId()) {
            return true;
        }
    }
    return false;
}

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::setCoal(const Coalition& c)
{
    coal = c;
}

const Coalition& Agent::getCoalition() const
{
    return coal;
}
