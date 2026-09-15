class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t p2 = (1u << 31);
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            int bit = n & 1;

            ans += p2 * bit;

            n >>= 1;
            p2 >>= 1;
        }

        return ans;
    }
};