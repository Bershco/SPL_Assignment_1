#ifndef SIMULATION
#define SIMULATION

#include <vector>

#include "Coalition.h"
#include "Graph.h"
#include "Agent.h"

using std::vector;

class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    int addAgent(Coalition& a, int pId);

    Coalition& getCoalById(int cId);
    void fixAgent_CoalId(Agent& a);
    void initiateCoalitions();
    Graph& getGraph2();
    int getNextAgentId();
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};

#endif