class Solution {
public:
    int countPartitions(vector<int> &nums,int maxSum){
        int n = nums.size();
        int partitions = 1;
        long long subSum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] + subSum <= maxSum){
                subSum += nums[i];
            }
            else{
                partitions++;
                subSum = nums[i];
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        if(k>n)return -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(countPartitions(nums,mid) > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};