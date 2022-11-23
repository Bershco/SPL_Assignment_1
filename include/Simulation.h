#ifndef SIMULATION
#define SIMULATION

#include <vector>

#include "Coalition.h"
#include "Graph.h"
#include "Agent.h"


using std::string;
using std::vector;

class Party;
class SelectionPolicy;

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
    int addAgent(Agent& a);

    Coalition* getCoalById(int cId);
    int getNumOfAgents() const;
    const Agent& newAgent(int pId, SelectionPolicy* _sp);
    void fixAgent_CoalId(Agent& a);
    void initiateCoalitions();
    Graph& getGraph2();
    int getNextAgentId();
    void helpToDelete();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalitions;
};

#endif