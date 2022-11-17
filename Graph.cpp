#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

const Party& Graph::selectPartyByMandates(const Party& currParty) const {
    int partyID = currParty.getId();
    int mandates = 0, maxMandateParty = -1;
    int currPartyInd = 0;
    for (int p : mEdges[partyID]) {
        if (p != 0) {
            Party check = getParty(currPartyInd);
            int checkMandates = check.getMandates();
            if (checkMandates > mandates)
            {
                maxMandateParty = currPartyInd;
                mandates = checkMandates;
            }
            //Note: because we're going through the indices in ascending order, 
            //there's no need to find the smaller Id value in the occurence of two equaling parties, 
            //because it will be present.
        }
        currPartyInd++;
    }
    return getParty(maxMandateParty);
}

const Party& Graph::selectPartyByEdgeWeight(const Party& currParty) const {
    //TODO: Implement SPBEW()
}