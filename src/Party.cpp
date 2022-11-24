#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"


Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offerersIds(), timer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

int Party::getId() const
{
    return mId;
}

int Party::getTimer() const
{
    return timer;
}

bool Party::isJoined() const
{
    return mState == Joined;
}

bool Party::isCollectingOffers() const
{
    return mState == CollectingOffers;
}

void Party::receiveOffer(Coalition& c)
{
    if (mState == Waiting) 
        setState(CollectingOffers);
    offerersIds.push_back(c.getId());
}

bool Party::isRelativeMajority() const
{
    return getMandates() > 60;
}

bool Party::isNotDummy() const {
    return mId != -10;
}

bool Party::receiveOfferFromId(int cId) const {
    for (int i = 0; i < abs(offerersIds.size()); i++)
        if (offerersIds[i] == cId)
            return true;
    return false;
}

Party::Party(const Party& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates),  mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), offerersIds(other.offerersIds), timer(other.timer)
{
    
}
Party& Party::operator=(const Party& other)
{
    mId = other.mId;
    mMandates = other.mMandates;
    mState = other.mState;

    mName.clear();
    mName = other.mName;

    if (mJoinPolicy)
        delete mJoinPolicy;
    mJoinPolicy = mJoinPolicy->clone();

    return *this;
}



Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState), offerersIds(other.offerersIds), timer(other.timer)
{
    other.mJoinPolicy = 0;
} 

Party& Party::operator=(Party && other)
{
    if (this != &other) {
        mId = other.mId;
        mMandates = other.mMandates;
        mState = other.mState;

        mName.clear();
        mName = other.mName;
        other.mName.clear();


        if (mJoinPolicy)
            delete mJoinPolicy;
        mJoinPolicy = other.mJoinPolicy;
        other.mJoinPolicy = 0; //nullptr
    }
    return *this;
}

void Party::step(Simulation &s)
{
    if (isJoined()) return;
    if (isCollectingOffers()) {
        timer++;
        if (timer >= 3) {
            setState(Joined);
            s.addAgent(mJoinPolicy->join(s,offerersIds, *this, s.getNextAgentId()),mId);
        }
    }
}

JoinPolicy* Party::getJoinPolicy(){
    return mJoinPolicy;
}

Party::~Party()
{
    if (mJoinPolicy)
        delete  mJoinPolicy; 
}

