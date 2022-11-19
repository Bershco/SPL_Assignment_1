#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    void clone(Party& p);
    bool offered(const Party& p) const;
    SelectionPolicy* getSelectionPolicy() const;
    void setCoal(const Coalition& c);
    const Coalition& getCoalition() const;


private:
    vector<Party> offeredParties;
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition coal;
};
