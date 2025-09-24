class MedianFinder {
public:
    // vector<int> arr;
    priority_queue<int, vector<int>, std::greater<int>> minHeap; // second half of sorted array
    priority_queue<int, vector<int>> maxHeap; // first half of sorted array
    int count;
    unordered_map<int,int> delayed;
    int k;
    int smallSize, largeSize;
    MedianFinder(int k):k(k) {
        count=0;

        smallSize =0;
        largeSize=0;
    }
    
    void addNum(int num) {
        // place into correct half
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            smallSize++;
        } else {
            minHeap.push(num);
            largeSize++;
        }
        rebalance();

    }

    void removeNum(int num) {
        delayed[num]++;

        // decide which half logically contains num
        if (!maxHeap.empty() && num <= maxHeap.top()) {
            smallSize--;
            // if it happens to be at the top, clean it now
            pruneMax();
        } else {
            largeSize--;
            pruneMin();
        }
        rebalance();
    }
    
    double findMedian() {
        // ensure tops are valid before reading
        pruneMax();
        pruneMin();

        if ((smallSize + largeSize) % 2 == 1) {
            // odd: left side holds the extra
            return (double)maxHeap.top();
        } else {
            // even: average of both tops
            return ((long long)maxHeap.top() + minHeap.top()) / 2.0;
        }

    }
private:
    void pruneMax() {
        while (!maxHeap.empty()) {
            int x = maxHeap.top();
            auto it = delayed.find(x);
            if (it != delayed.end()) {
                if (--(it->second) == 0) delayed.erase(it);
                maxHeap.pop();
            } else break;
        }
    }

    void pruneMin() {
        while (!minHeap.empty()) {
            int x = minHeap.top();
            auto it = delayed.find(x);
            if (it != delayed.end()) {
                if (--(it->second) == 0) delayed.erase(it);
                minHeap.pop();
            } else break;
        }
    }

    void rebalance() {
        // keep sizes: smallSize == largeSize or smallSize == largeSize + 1
        if (smallSize > largeSize + 1) {
            // move one from left to right
            pruneMax();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            smallSize--;
            largeSize++;
            pruneMax();
        } else if (smallSize < largeSize) {
            // move one from right to left
            pruneMin();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            smallSize++;
            largeSize--;
            pruneMin();
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        MedianFinder mf = MedianFinder(k);
        int start=0;
        int end=k-1;

        // calculate median for first k elements
        for(int i=start; i<k; i++) {
            mf.addNum(nums[i]);
        }
        res.push_back(mf.findMedian());

        // start sliding window
        for (int i = k; i < nums.size(); i++) {
            mf.removeNum(nums[i-k]);  // remove outgoing element
            mf.addNum(nums[i]);
            res.push_back(mf.findMedian());
        }

        return res;

    }
};