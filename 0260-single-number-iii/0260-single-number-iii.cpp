class Solution {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        long long XOR = accumulate(nums.begin(), nums.end(), 0LL, bit_xor<>());
        int lastBit=XOR ^ (XOR & (-XOR) );
        int a = 0, b = 0;
        for (int x: nums)
            (x & lastBit) ? b ^= x : a ^= x; 
        
        return {a, b};
    }
};