#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    timer = 0;
    offerer = 0;
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

bool Party::isRelativeMajority() const
{
    return getMandates() > 60;
}

void Party::step(Simulation &s)
{
    if (isJoined()) return;
    if (isCollectingOffers()) {
        timer++;
        if (timer >= 3) {
            offerer->join(*this); //TODO: implement Coalition::join(Party& s); and also make sure to clone agent in it.
        }
    }
}
