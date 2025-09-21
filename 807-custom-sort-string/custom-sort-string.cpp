class Solution {
public:
    string customSortString(string order, string s) {

        string res="";
        unordered_set<char> used;
        for (char c: order) {
            for (int t=0;t<s.size();t++) {
                if (s[t]==c) {
                    res+=s[t];
                    s[t]='#';
                }
            }
        }

        for (char t: s){
            if (t=='#') continue;
            res+=t;
        }
        
        return res;
        
    }
};