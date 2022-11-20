#include "Simulation.h"

using std::move;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    int numOfParties = mGraph.getNumVertices();
    for (int i = 0; i < numOfParties; i++) {
        Party p = getParty(i);
        p.step(*this);
    }
    for (Agent& a : mAgents) {
        a.step(*this);
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

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<Coalition> allCoalitions;
    for (const auto& a : mAgents) {
        bool same = false;
        Coalition _c = a.getCoalition();
        for (const auto& c : allCoalitions) {
            if (_c == c) {
                same = true;
                break;
            }
        }
        if (same) continue;
        else allCoalitions.push_back(_c);
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
    return a;
}
