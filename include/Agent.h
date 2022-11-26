#ifndef AGENT
#define AGENT

#include <vector>
using std::vector;
#include "SelectionPolicy.h"


class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    
    void setCoalId(int cId);
    int getCoalId() const;
    SelectionPolicy* getSelectionPolicy2();

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
    vector<int> offeredPartiesIds;
};

#endif