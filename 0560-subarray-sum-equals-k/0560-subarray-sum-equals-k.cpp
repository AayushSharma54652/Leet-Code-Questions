class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int n = nums.size();
        int count = 0;
        int presum = 0;
        for(int i=0;i<n;i++){
            presum += nums[i];
            int remain = presum - k;
            count += mpp[remain];
            mpp[presum] += 1;
        }
        return count;
    }
};