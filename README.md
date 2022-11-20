# SPL_Assignment_1
Systems Programming first assignment - SPLand coalition creation.


Parser::readSimulation(cmd line args)
While {
  Simulation::step {
	  Party::step(Simulation& s) (for each party) {
      Check if party is still collectingOffers or waiting – new method – Party::selfCheck()
      Update the time properly (part of Party::selfCheck())
      If still collectingOffers and timer reached 3 iterations – join some coalition 
      (using the proper join policy) (part of Party::selfCheck – and use coalition::join() )
      Change party’s state to joined and clone agent to said party that joined (Party::join() & agent::clone(Party& p) )
		}
	  Agent::step(Simulation& s) (for each agent) {
		  Select party using selectionPolicy::select() out of a party that is:
        -	Neighbor of the party that the agent belongs to ( Party::getNeighbors() )
        -	The party is waiting or collectingOffers (try using party::selfCheck() or just do something similar)
        -	The party hasn’t yet received an offer from our coalition (coalition::checkOffers() )
      Offer said party to join the proper coalition (in which the agent is a member) (party::offer(Coalition& c))
    }
}
**Save data using line that’s already present**
}
