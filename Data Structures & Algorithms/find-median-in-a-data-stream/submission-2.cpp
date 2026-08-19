class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    MedianFinder() {
        //nothing
    }
    
    void addNum(int num) {
        if(maxi.empty() || num <= maxi.top()){
            maxi.push(num);
        } else{
            mini.push(num);
        }

        //conditions:
        //both sizes should be equal, or,
        //maxi sould be just one unit bigger than mini, or,
        //maxi should not be smaller than mini

        if(maxi.size() > mini.size() + 1){
            mini.push(maxi.top());
            maxi.pop();
        } else if (maxi.size() <  mini.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size() == mini.size()){
            double ans = (maxi.top() + mini.top())/2.0;
            return ans;
        } else{
            return maxi.top();
        }
    }
};
