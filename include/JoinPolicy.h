#ifndef JOINPOLICY
#define JOINPOLICY

#include <vector>
using std::vector;

class Coalition;
class Party;
class Simulation;

class JoinPolicy {
public:
	virtual Coalition& join(Simulation& s, vector<int>& offerers, Party& p, int aId) = 0;
	virtual JoinPolicy* clone();
	virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
	Coalition& join(Simulation& s, vector<int>& offerers, Party& p, int aId);
	JoinPolicy* clone();
	
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
	Coalition& join(Simulation& s, vector<int>& offerers, Party& p, int aId);
	JoinPolicy* clone();
	
};

#endif