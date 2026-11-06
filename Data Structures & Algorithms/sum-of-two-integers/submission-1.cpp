class Solution {
public:
    int getSum(int a, int b) {
        while( b != 0){
            int sum = a^b;
            int carry = (a&b) << 1; //left shift as we store carry for the left el in normal addition

            a = sum;
            b = carry;
        }
        return a;
    }
};
