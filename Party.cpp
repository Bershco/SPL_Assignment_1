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
    if (mState == Waiting) setState(CollectingOffers);
    offerers.push_back(c);
}

bool Party::isRelativeMajority() const
{
    return getMandates() > 60;
}

Party::Party(const Party& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mState(other.mState)
{
    mJoinPolicy = mJoinPolicy->clone(other.mJoinPolicy);
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
    mJoinPolicy = mJoinPolicy->clone(other.mJoinPolicy);

    return *this;
}

Party::~Party()
{
    delete(mJoinPolicy);
}

Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy), mState(other.mState)
{}

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
}

void Party::step(Simulation &s)
{
    if (isJoined()) return;
    if (isCollectingOffers()) {
        timer++;
        if (timer >= 3) {
            Coalition bestOfferer = mJoinPolicy->join(offerers);
            setState(Joined);
            bestOfferer.join(*this);
        }
    }
}
