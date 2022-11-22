#ifndef JOINPOLICY
#define JOINPOLICY

#include <vector>
using std::vector;

class Coalition;

class JoinPolicy {
public:
	virtual const Coalition& join(vector<Coalition>) const = 0;
	virtual JoinPolicy* clone(JoinPolicy* policy);
	virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition>) const;
	JoinPolicy* clone(JoinPolicy* policy);
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition>) const;
	JoinPolicy* clone(JoinPolicy* policy);
};

#endif