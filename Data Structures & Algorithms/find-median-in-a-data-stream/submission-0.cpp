class MedianFinder {
public:
    priority_queue<int> maxi; //max_heap --1st half
    priority_queue<int, vector<int>, greater<int>> mini; // min_heap --2nd half

    vector<int> arr;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() || num < maxi.top()){ //we need to store in sorted way
            maxi.push(num);
        } else{
            mini.push(num);
        }

        //check if balanced
        if(maxi.size() > mini.size() + 1){
            mini.push(maxi.top());
            maxi.pop();
        } else if(mini.size() >  maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }

    }
    
    double findMedian() {
        if(maxi.size() == mini.size()){ //even
            double ans = (maxi.top() + mini.top())/2.0;
            return ans;
        } else{
            return maxi.top();
        }
    }
};
