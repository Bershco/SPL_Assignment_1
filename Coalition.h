#pragma once
#include "Party.h"
#include "Simulation.h"
#include <vector>
using std::vector;

class Agent;

class Coalition {
public:
	Coalition(const Party& p, const Agent& a, Simulation* s);
	Coalition();

	int getMandates() const;
	void join(Party& p);
	void cloneAgent(int pId);
	bool checkOffers(const Party& p) const;
	bool operator==(Coalition c);
	vector<int> getPartyIDs() const;

	//Rule of 5 - because of SelecitonPolicy pointer
	Coalition(const Coalition& other);              //Copy constructor
	Coalition& operator=(const Coalition& other);   //Copy assignment operator
	~Coalition();                               //Destructor
	Coalition(Coalition&& other);                   //Move constructor
	Coalition& operator=(Coalition&& other);        //Move assignment operator

private:
	int mandates;
	vector<Party> parties;
	vector<Agent> agents;
	Simulation* _s;
};