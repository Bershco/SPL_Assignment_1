#include "Agent.h"
#include "Simulation.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) :
    mAgentId(agentId), mPartyId(partyId), coalId(-1), mSelectionPolicy(selectionPolicy), offeredParties()
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
    if (mAgentId == -1) mAgentId = sim.addAgent(*this);
    Party p = mSelectionPolicy->select(sim.getGraph(), mPartyId, *this);
    if (p.getId() != -10) { //if p.id IS 10 - that means it's a dummy ,and should not be used.
        offeredParties.push_back(p);
        p.receiveOffer(sim.getCoalById(coalId));
    }
    else
        delete &p;
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

void Agent::setCoalId(int cId)
{
    coalId = cId;
}


int Agent::getCoalId() const{
    return coalId;
}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), coalId(other.coalId), mSelectionPolicy(other.mSelectionPolicy->clone(other.mSelectionPolicy)), offeredParties(other.offeredParties)
{
    
}

Agent& Agent::operator=(const Agent& other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;

    if (mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy = mSelectionPolicy->clone(other.mSelectionPolicy);

    return *this;
}

Agent::~Agent()
{
    delete mSelectionPolicy;
}

Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), coalId(other.coalId), mSelectionPolicy(other.mSelectionPolicy), offeredParties(other.offeredParties)
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

