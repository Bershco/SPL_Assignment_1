#include "Simulation.h"
#include "Party.h"
#include "SelectionPolicy.h"

using std::move;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions()
{
    // You can change the implementation of the constructor, but not the signature!
    for (int i = 0; i < abs(mAgents.size()); i++) {
        int coalSize = abs(mCoalitions.size());
        mCoalitions.push_back(Coalition(getParty(mAgents[i].getPartyId()),mAgents[i],coalSize));
    }
 
}


void Simulation::step()
{
    int numOfParties = mGraph.getNumVertices();
    for (int i = 0; i < numOfParties; i++) {
        Party& p = mGraph.getParty2(i);
        p.step(*this);
    }
    for (int i = 0; i < abs(mAgents.size()); i++) {
        if (mAgents[i].getCoalId() == -1) {
            fixAgent_CoalId(mAgents[i]);
        }
        mAgents[i].
        step(*this);
    }
}

void Simulation::fixAgent_CoalId(Agent& a) {
    if (abs(mCoalitions.size()) == 0)
        initiateCoalitions();
    else {
        for (int i = 0; i < abs(mCoalitions.size()); i++) {
            if (mCoalitions[i].findAgent(a)) {
                a.setCoalId(mCoalitions[i].getId());
                break;
            }

        }
       
    }
}

void Simulation::initiateCoalitions() {
    for (int i = 0; i < abs(mAgents.size()); i++) {
        Coalition c(getParty(mAgents[i].getPartyId()),mAgents[i],mCoalitions.size());
        mAgents[i].setCoalId(c.getId());
        mCoalitions.push_back(c);
    }
}

bool Simulation::shouldTerminate() const
{
    int numOfParties = mGraph.getNumVertices();
    int numOfJoinedParties = 0;
    for (int i = 0; i < abs(mCoalitions.size()); i++) {
        if (mCoalitions[i].getMandates() > 60)
            return true;
    }
    for (int i = 0; i < numOfParties; i++) {
        if (getParty(i).getState() == Joined) numOfJoinedParties++;
    }
    return numOfJoinedParties == numOfParties;

}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph& Simulation::getGraph2() {
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

int Simulation::addAgent(Coalition& c, int pId) {
    int aId = abs(mAgents.size());
    mAgents.push_back(Agent(aId,pId,mAgents[c.getRepresentativeId()].getSelectionPolicy2()->clone()));
    return aId;
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<Coalition> allCoalitions;
    for (int i = 0; i < abs(mAgents.size()) ;i++) {
        bool same = false;
        int agent_cId = mAgents[i].getCoalId();
        if (!allCoalitions.empty()) {
            for (int j = 0; j < abs(allCoalitions.size()); j++) {
                if (agent_cId == allCoalitions[j].getId()) {
                    same = true;
                    break;
                }
            }
        }
        if (same) continue;
        else {
            if (!mCoalitions.empty())
                allCoalitions.push_back(mCoalitions[agent_cId]);
        }
    }
 
    vector<vector<int>> coalitionsByPartyID;
    for (int p = 0; p < abs(allCoalitions.size());p++) {
        coalitionsByPartyID.push_back(allCoalitions[p].getPartyIDs());
    }
  
    return coalitionsByPartyID;
}


Coalition& Simulation::getCoalById(int cId) {
    return mCoalitions[cId];
}

int Simulation::getNextAgentId() {
    return mAgents.size();
}

