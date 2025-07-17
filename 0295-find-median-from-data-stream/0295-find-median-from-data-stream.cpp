class MedianFinder {
    priority_queue<int> smallHeap;
    priority_queue<int , vector<int>, greater<int>> bigHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!bigHeap.empty() && smallHeap.top()>bigHeap.top()){
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > bigHeap.size()+1){
            bigHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(bigHeap.size() > smallHeap.size()+1){
            smallHeap.push(bigHeap.top());
            bigHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == bigHeap.size()){
            return (smallHeap.top()+bigHeap.top())/ 2.0;
        }
        else if(smallHeap.size() > bigHeap.size()){
            return smallHeap.top();
        }
        else{
            return bigHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */