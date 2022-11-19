#pragma once
#include <string>
#include <vector>
#include "Agent.h"
#include "Coalition.h"

using std::vector;
using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;


    int getTimer() const;
    bool isJoined() const;
    bool isCollectingOffers() const;
    void receiveOffer(Coalition& c);
    bool isRelativeMajority() const;


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;

    vector<Coalition&> offerers;
    int timer;
};
