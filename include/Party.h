#ifndef PARTY
#define PARTY

#include <string>
#include <vector>
#include "Coalition.h"
#include "JoinPolicy.h"

using std::vector;
using std::string;

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
    bool receiveOfferFromId(int cId) const;
    JoinPolicy* getJoinPolicy();
    bool isNotDummy() const;

    //Rule of 5 - because of JoinPolicy pointer
    Party(const Party& other);              //Copy constructor
    Party& operator=(const Party& other);   //Copy assignment operator
    ~Party();                               //Destructor
    Party(Party&& other);                   //Move constructor
    Party& operator=(Party&& other);        //Move assignment operator


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;

    vector<int> offerersIds;
    int timer;
};

#endif