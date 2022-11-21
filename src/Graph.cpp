#include "Graph.h"
#include "Agent.h"
#include "Party.h"

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

const Party& Graph::selectPartyByMandates(int pId, const Agent& a) const {
    int mandates = 0, maxMandatePartyId = -1;
    int currPartyInd = 0;
    for (int p : mEdges[pId]) {
        Coalition c = a.getCoalition();
        if (p != 0 && !( (getParty(currPartyInd)).isJoined() ) && !c.checkOffers(getParty(currPartyInd)) ) {
            //Make sure they are neighbors, the party isn't 'Joined' and that a's coalition didn't already offer that party this iteration.
            int checkMandates = (getParty(currPartyInd)).getMandates();
            if (checkMandates > mandates)
            {
                maxMandatePartyId = currPartyInd;
                mandates = checkMandates;
            }
            //Note: because we're going through the indices in ascending order, 
            //there's no need to find the smaller Id value in the occurence of two equaling parties, 
            //because the first will already be present.
        }
        currPartyInd++;
    }
    if (maxMandatePartyId == -1) {
        return Party(-10,"dummy",0,0);
    }
    return getParty(maxMandatePartyId);
}

const Party& Graph::selectPartyByEdgeWeight(int pId, const Agent& a) const {
    int maxEdgeWeight = 0;
    int retPartyId = -1;
    for (int i = 0; i < mEdges[pId].size(); i++) {
        Coalition c = a.getCoalition();
        if (mEdges[pId][i] != 0 && !( (getParty(i)).isJoined() ) && !c.checkOffers(getParty(i)) ) { 
            //Make sure they are neighbors, and the party isn't 'Joined' and that a's coalition didn't already offer that party this iteration.
            if (mEdges[pId][i] > maxEdgeWeight) {
                maxEdgeWeight = mEdges[pId][i];
                retPartyId = i;
            }
        }
    }
    if (retPartyId == -1) {
        return Party(-10, "dummy", 0, 0);
    }
    return getParty(retPartyId);

}