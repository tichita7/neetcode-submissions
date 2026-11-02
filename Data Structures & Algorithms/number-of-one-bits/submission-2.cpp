class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while(n > 0){
            if(n & 1){ //check if this bit is 1
                cnt++;
            }
            n >>= 1; //move to the left by right shifting
        }
        return cnt;
    }
};
