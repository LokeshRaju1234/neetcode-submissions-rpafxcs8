class MedianFinder 
{
     priority_queue<int> maxHeap; // stores smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        maxHeap.push(num);

        // Step 2: Balance order → largest of maxHeap should go to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance sizes (maxHeap can have 1 more element)
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    
    double findMedian() 
    {
 if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};
