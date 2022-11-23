#ifndef JOINPOLICY
#define JOINPOLICY

#include <vector>
using std::vector;

class Coalition;
class Party;
class Agent;

class JoinPolicy {
public:
	virtual Agent* join(vector<Coalition*> offerers, Party& p, int aId) = 0;
	virtual JoinPolicy* clone();
	virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	Agent* join(vector<Coalition*> offerers, Party& p, int aId);
	JoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	Agent* join(vector<Coalition*> offerers, Party& p, int aId);
	JoinPolicy* clone();
};

#endif