class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        big.push(-small.top());
        small.pop();
        if(small.size()<big.size())
        {
            small.push(-big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        return small.size()>big.size() ?  small.top() : 0.5*(small.top()-big.top());
    }
private:
    priority_queue<int> big,small;
};