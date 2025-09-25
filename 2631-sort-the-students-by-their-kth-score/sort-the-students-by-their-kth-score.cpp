

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {

        if (score.empty()) return {};

        int m =score.size();
        int n = score[0].size();

        map<int, int, std::greater<int>> maxElements;

        for (int i=0; i<m; i++) {
            // push largest elements into the map
            maxElements[score[i][k]] = i;
        }

        vector<vector<int>> result;

        for (auto& student: maxElements) {
            int row = student.second;
            result.push_back(score[row]);
        }
        
        return result;
    }
};