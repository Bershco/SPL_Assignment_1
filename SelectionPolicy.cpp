#include "SelectionPolicy.h"


const Party& MandatesSelectionPolicy::select(const vector<Party>& p) const
{
	Party won = p[0];
	int maxMandate = -1;
	int idMax = -1;
	for (Party pr : p) {
		int pr_id = pr.getId();
		if (pr.getMandates() > maxMandate) {
			maxMandate = pr.getMandates();
			idMax = pr_id;
			won = pr;
		}
		if (pr.getMandates() == maxMandate) { //incase somthing was messed up
			if (pr_id < idMax) {
				idMax = pr_id;
			}
		}
	}
	return won;
}

const Party& EdgeWeightSelectionPolicy::select(const vector<Party>& p) const
{
	
}