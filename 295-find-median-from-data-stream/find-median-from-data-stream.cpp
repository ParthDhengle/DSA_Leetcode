class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>>right;
    priority_queue<int>left;
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.empty() or num<=left.top()){
            left.push(num);
        }else{
            right.push(num);
        }
        //check balance;
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()>right.size()){
            return left.top();
        }
        return (double)(left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */