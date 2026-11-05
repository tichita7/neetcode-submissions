class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0; //uint32_t stores full 32 bit integer

        for(int i = 0; i<32; i++){
            uint32_t bit = n&1; //extarct the last bit

            ans = (ans << 1) | bit; //left shift operator to make room for the next bit and append by using or -> |

            n = n >>1;
        }

        return ans;
    }
};
