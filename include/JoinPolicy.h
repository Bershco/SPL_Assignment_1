#ifndef JOINPOLICY
#define JOINPOLICY

#include <vector>
using std::vector;

class Coalition;

class JoinPolicy {
public:
	virtual const Coalition& join(vector<Coalition>) const = 0;
	virtual JoinPolicy* clone();
	virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition>) const;
	JoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	const Coalition& join(vector<Coalition>) const;
	JoinPolicy* clone();
};

#endif