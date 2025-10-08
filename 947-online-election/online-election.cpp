class TopVotedCandidate {
public:

    unordered_map<int, int> leadsMap;
    unordered_map<int, int> totalVotes;
    vector<int> times;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        int leader = persons[0];

        for (int i=0; i<persons.size(); i++) {
            // increase the total votes received for the current person
            totalVotes[persons[i]]++;
            
            // if total votes received for current person is greater than the leader, assign leaeder to that person
            if (totalVotes[persons[i]] >= totalVotes[leader]) {
                leader = persons[i];
            }
            // store the leader at time i
            leadsMap[times[i]] = leader;
            // cout<<leadsMap[times[i]]<<endl;
        }
        
    }
    
    int q(int t) {

        if (leadsMap.count(t) != 0) return leadsMap[t];

        int low = 0;
        int high = times.size()-1;

        while (low<=high) {
            int mid = low + (high - low) /2;

            if (times[mid] <= t) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }

        }
        // cout<<low<<endl;
        return leadsMap[times[high]];
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */