class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (left.empty()) {
            left.push(num);
            return;
        }
        if (left.size() > right.size()) {
            if (num <= left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
                return;
            }
            else right.push(num);
        }
        else {
            if (num >= right.top()) {
                left.push(right.top());
                right.pop();
                right.push(num);
                return;
            }
            else left.push(num);
        }
    }

    double findMedian() {
        
        if (left.size() > right.size())
            return (double) left.top();

        if (left.size() == right.size())
            return (double)(left.top() + right.top()) / 2.0;

        if (!right.empty())
            return (double) right.top();

        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */