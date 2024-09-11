class Solution {
public:
    int minBitFlips(int start, int goal) {
        return bitset<32>(start^goal).count();
    }
};