#include "Party.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    timer = 0;
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
    offerers.push_back(c);
}

bool Party::isRelativeMajority() const
{
    return getMandates() > 60;
}

void Party::step(Simulation &s)
{
    if (isJoined()) return;
    if (isCollectingOffers()) { //TODO make sure to set collectingOffers when the first agent offers a party.
        timer++;
        if (timer >= 3) {
            Coalition bestOfferer = mJoinPolicy->join(offerers);
            bestOfferer.join(*this);
            setState(Joined);
        }
    }
}
