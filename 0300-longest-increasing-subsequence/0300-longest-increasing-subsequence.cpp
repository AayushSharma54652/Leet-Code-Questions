class Solution {
public:
    int f(int index,int prev_index,vector<int> &nums,int &n, vector<vector<int>>&dp){
        if(index == n)return 0;
        if(dp[index][prev_index + 1] != -1)return dp[index][prev_index + 1];
        int notTake = 0 + f(index+1,prev_index,nums,n,dp);
        int take = 0;
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            take = 1 + f(index+1,index,nums,n,dp);
        }
        return dp[index][prev_index + 1] = max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1,vector<int>(n+1,0));
        for(int index = n-1;index >= 0;index--){
            for(int prev_index = index-1;prev_index >= -1; prev_index--){
                int notTake = 0 + dp[index+1][prev_index + 1];
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                    take = 1 + dp[index + 1][index + 1];
                } 
                
                dp[index][prev_index + 1] = max(take,notTake);
            }
        }
        
        return dp[0][-1 + 1];
    }
};