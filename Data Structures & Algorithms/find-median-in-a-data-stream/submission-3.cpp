class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() || num <= maxi.top()){
            maxi.push(num);
        } else{
            mini.push(num);
        }

        //check size balance
        if(maxi.size() > mini.size() + 1){
            mini.push(maxi.top());
            maxi.pop();
        } else if (maxi.size() < mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size()){
            double mean = (maxi.top() + mini.top()) / 2.0;
            return mean;
        } else{
            return maxi.top();
        }
    }
};
