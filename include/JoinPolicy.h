#pragma once

#include <vector>
using std::vector;

class Coalition;

class JoinPolicy {
public:
	virtual const Coalition& join(vector<Coalition&>) const = 0;
	virtual JoinPolicy* clone(JoinPolicy* policy);
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition&>) const;
	virtual MandatesJoinPolicy* clone(MandatesJoinPolicy* policy);
	virtual MandatesJoinPolicy* clone(LastOfferJoinPolicy* policy);
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition&>) const;
	virtual LastOfferJoinPolicy* clone(MandatesJoinPolicy* policy);
	virtual LastOfferJoinPolicy* clone(LastOfferJoinPolicy* policy);
};