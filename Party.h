#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class Coalition;
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


    bool selfCheck() const; //TODO: check if parameters are needed here.
    const vector<Party> getNeighbors() const;
    void offer(Coalition& c) const;
    bool isRelativeMajority() const;


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;

    int timer;
};
