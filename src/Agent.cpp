#include "Agent.h"
#include "Simulation.h"
#include "Party.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), coalId(-1), mSelectionPolicy(selectionPolicy), offeredPartiesIds()
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
    Party& p = mSelectionPolicy->select(sim.getGraph2(), mPartyId, *this);
    if (p.getId() != mPartyId) {
        bool add = true;
        for (int i = 0; i < abs(offeredPartiesIds.size()); i++) {
            if (offeredPartiesIds[i] == p.getId()) {
                add = false;
                break;
            }
        }
        if (add) {
            offeredPartiesIds.push_back(p.getId());
            p.receiveOffer(sim.getCoalById(coalId));
        }
    }
}



SelectionPolicy* Agent::getSelectionPolicy2() 
{
    return mSelectionPolicy;
}
void Agent::setCoalId(int cId)
{
    this->coalId = cId;
}


int Agent::getCoalId() const{
    return coalId;
}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), 
mPartyId(other.mPartyId), 
coalId(other.coalId), 
mSelectionPolicy(other.mSelectionPolicy->clone()), 
offeredPartiesIds(other.offeredPartiesIds)
{}

Agent& Agent::operator=(const Agent& other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    //TODO check if coalID is missing
    if (mSelectionPolicy)
     delete mSelectionPolicy;
    mSelectionPolicy = mSelectionPolicy->clone();

    return *this;
}


Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), coalId(other.coalId), mSelectionPolicy(other.mSelectionPolicy), offeredPartiesIds(other.offeredPartiesIds)
{
    other.mSelectionPolicy = 0; // nullptr
}

Agent& Agent::operator=(Agent && other)
{
    if (this != &other) {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = 0; //nullptr
    }
    return *this;
}
Agent::~Agent()
{
    if (mSelectionPolicy)
        delete  mSelectionPolicy; 
}

