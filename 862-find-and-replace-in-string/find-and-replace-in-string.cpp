class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        if (s.empty()){
            return "";
        }

        unordered_map<int, int> indices_map;
        string res;

        for (int i = 0; i < indices.size(); i++) {
            int idx = indices[i];
            if (idx + sources[i].size() <= s.size() &&
                s.substr(idx, sources[i].size()) == sources[i]) {
                indices_map[idx] = i;
            }
        }
        
        int idx=0;

        while (idx<s.size()) {

            if(indices_map.count(idx) ){
                string tgt = sources[indices_map[idx] ];
                int length=tgt.size();
                string src = s.substr(idx, length);
                if (src == tgt){
                    res+=targets[indices_map[idx]];
                    // indicesPtr++;
                    idx+=length;
                }

            }
            else{
                // index doesnt exist in indices
                res+= s[idx];
                idx++;

            }

        }

        return res;
    }

};