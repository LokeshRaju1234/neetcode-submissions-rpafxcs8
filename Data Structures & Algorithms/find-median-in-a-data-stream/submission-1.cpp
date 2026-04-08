class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> maxHeap;
    priority_queue<int,vector<int>,less<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push_back(num);

        minHeap.push_back(maxHeap.top())
        maxHeap.pop()

        if(maxHeap.size() < minHeap.size())
        {
        maxHeap.push_back(minheap.top());
        minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            return maxHeap.top();
        }
    }
};
