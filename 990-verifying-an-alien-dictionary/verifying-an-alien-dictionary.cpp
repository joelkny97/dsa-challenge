class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> order_map;
        for(int i=0; i<order.size(); i++){
            order_map[order[i]] = i;
        }
        
        // for (const string w: words) {
        //     if (w.size()==1) continue;
        //     int curr=0;
        //     int prev=-1;
        //     while (curr<w.size()) {
        //         if (prev>=0) {
        //             cout<<"Curr: "<<order_map[w[curr]]<<" Prev: "<< order_map[w[prev]]<<endl;
        //             if (order_map[w[curr]] < order_map[w[prev]]) return false;
        //         }
        //         prev=curr;
        //         curr++;
        //     }
        // }

        for (int i=1; i<words.size(); i++) {
            
            string currStr = words[i];
            string prevStr = words[i-1]; 

            int cPtr=0, pPtr=0;
            int minL = min(currStr.size(), prevStr.size());
            bool diffFound = false;
            while(cPtr < minL && pPtr < minL){

                if (currStr[cPtr] != prevStr[pPtr]){
                    
                    if ( order_map[currStr[cPtr]] < order_map[prevStr[pPtr]] ) return false;
                    diffFound = true;
                    break;  // order decided, no need to check further

                }
                cPtr++;
                pPtr++;
            }

            if (!diffFound && prevStr.size() > currStr.size()) {
                return false;
            }

    
        }

        return true;
    }
};