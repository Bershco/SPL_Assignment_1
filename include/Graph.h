#ifndef GRAPH
#define GRAPH

#include <vector>
//#include "Party.h"//TODO CHECK WITH ROEE

using std::vector;

class Agent;
class Party; 

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party& selectPartyByMandates(int pId, const Agent& a);
    Party& selectPartyByEdgeWeight(int pId, const Agent& a);
    Party& getParty2(int id);
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};

#endif