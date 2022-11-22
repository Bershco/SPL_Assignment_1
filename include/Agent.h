#ifndef AGENT
#define AGENT

#include <vector>
using std::vector;
#include "SelectionPolicy.h"
#include "Party.h"
#include "Coalition.h" //TODO make sure this is needed fr

class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    bool offered(const Party& p) const;
    SelectionPolicy* getSelectionPolicy() const;
    void setCoalId(int cId);
    int getCoalId() const;

    //Rule of 5 - because of SelecitonPolicy pointer
    Agent(const Agent& other);              //Copy constructor
    Agent& operator=(const Agent& other);   //Copy assignment operator
    ~Agent();                               //Destructor
    Agent(Agent&& other);                   //Move constructor
    Agent& operator=(Agent&& other);        //Move assignment operator



private:
    int mAgentId;
    int mPartyId;
    int coalId;
    SelectionPolicy *mSelectionPolicy;
    vector<Party> offeredParties;
};

#endif