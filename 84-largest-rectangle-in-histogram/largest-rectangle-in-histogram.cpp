class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        if (heights.empty()) return 0;

        stack<int> st;
        int area=0;

        st.push(-1);

        for (int i=0; i<heights.size(); i++) {

            while (st.top() != -1 && heights[st.top()] > heights[i] ) {

                // pop the top element to get max height so far
                int lastMaxHeightIdx = st.top();
                st.pop();
                // calculate width using next lower element height's and max height's index  
                int width = i - st.top() -1 ;

                area = max(area, heights[lastMaxHeightIdx] * width );
            }

            st.push(i);

        }

        while(st.top() != -1) {
            // pop the top element to get max height so far
            int lastMaxHeightIdx = st.top();
            st.pop();
            // calculate width using next lower element height's and max height's index  
            int width = heights.size() - st.top() -1 ;

            area = max(area, heights[lastMaxHeightIdx] * width );

        }
        return area;
        
    }
};