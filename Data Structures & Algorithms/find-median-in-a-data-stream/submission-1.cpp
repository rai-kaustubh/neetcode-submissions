class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    priority_queue<int, vector<int>> maxHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(!minHeap.size() && !maxHeap.size()){
            minHeap.push(num);
            return;
        }

        if(num >= minHeap.top()){
            minHeap.push(num);
        } else{
            maxHeap.push(num);
        }

        if(abs((int)maxHeap.size()-(int)minHeap.size())>1){
            if(maxHeap.size()>minHeap.size()){
                int x = maxHeap.top();
                maxHeap.pop();
                minHeap.push(x);
            } else {
                int x = minHeap.top();
                minHeap.pop();
                maxHeap.push(x);
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            int mini = minHeap.top();
            int maxi = maxHeap.top();
            return (double)(mini+maxi)/2;
        }

        if(minHeap.size()>maxHeap.size()){
            return minHeap.top();
        }

        return maxHeap.top();
    }
};
