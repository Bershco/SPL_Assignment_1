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

    bool offered(const Party& p) const;
    SelectionPolicy* getSelectionPolicy() const;
    void setCoal(const Coalition& c);
    const Coalition& getCoalition() const;

    //Rule of 5 - because of SelecitonPolicy pointer
    Agent(const Agent& other);              //Copy constructor
    Agent& operator=(const Agent& other);   //Copy assignment operator
    ~Agent();                               //Destructor
    Agent(Agent&& other);                   //Move constructor
    Agent& operator=(Agent&& other);        //Move assignment operator



private:
    vector<Party> offeredParties;
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition coal;
};
