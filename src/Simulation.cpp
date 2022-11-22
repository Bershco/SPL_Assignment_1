#include "Simulation.h"
#include "Party.h"
#include "SelectionPolicy.h"

using std::move;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions()
{
    // You can change the implementation of the constructor, but not the signature!
    for (Agent a : mAgents) {
        int coalSize = mCoalitions.size();
        mCoalitions.push_back(Coalition(getParty(a.getPartyId()),a,coalSize));
    }
    for (Coalition c : mCoalitions) {
        c.checkMandates();
    }
}

void Simulation::step()
{
    int numOfParties = mGraph.getNumVertices();
    for (int i = 0; i < numOfParties; i++) {
        Party p = getParty(i);
        p.step(*this);
    }
    for (Agent& a : mAgents) {
        if (a.getCoalId() == -1) 
            fixAgent_CoalId(a);
        a.step(*this);
    }
}

void Simulation::fixAgent_CoalId(Agent& a) {
    if (mCoalitions.size() == 0)
        initiateCoalitions();
    else {
        for (auto c : mCoalitions) {
            if (c.findAgent(a)) {
                a.setCoalId(c.getId());
                break;
            }
        }
    }
}

void Simulation::initiateCoalitions() {

    for (auto& a : mAgents) {
        Coalition c(getParty(a.getPartyId()),a,mCoalitions.size());
        a.setCoalId(c.getId());
        mCoalitions.push_back(c);
    }
}

bool Simulation::shouldTerminate() const
{
    bool relativeMajority = false, noMoreOptions = false;
    int numOfParties = mGraph.getNumVertices();
    int numOfJoinedParties = 0;
    for (int i = 0; i < numOfParties; i++) {
        Party p = getParty(i);
        if (p.isRelativeMajority()) {
            relativeMajority = true;
            break;
        }
        if (p.getState() == Joined)
            numOfJoinedParties++;
    }
    if (numOfParties == numOfJoinedParties)
        noMoreOptions = true;
    return relativeMajority || noMoreOptions;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

int Simulation::addAgent(Agent& a) {
    int aId = mAgents.size();
    mAgents.push_back(a);
    return aId;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<Coalition> allCoalitions;
    for (auto a : mAgents) {
        bool same = false;
        int agent_cId = a.getCoalId();
        if (!allCoalitions.empty())
            for (auto c : allCoalitions) {
                if (agent_cId == c.getId()) {
                    same = true;
                    break;
                }
            }
        if (same) continue;
        else {
            if (!mCoalitions.empty())
                allCoalitions.push_back(mCoalitions.at(agent_cId));
        }
    }
    vector<vector<int>> coalitionsByPartyID;
    for (const auto& c : allCoalitions) {
        coalitionsByPartyID.push_back(c.getPartyIDs());
    }

    return coalitionsByPartyID;
}

int Simulation::getNumOfAgents() const
{
    return mAgents.size();
}

const Agent& Simulation::newAgent(int pId, SelectionPolicy* _sp)
{
    Agent a(mAgents.size(), pId, _sp);
    mAgents.push_back(a);
    return *(new Agent(a)); //TODO check if any work is need in deleting the object
}

Coalition& Simulation::getCoalById(int cId) {
    return mCoalitions[cId];
}
