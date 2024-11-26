class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>next(n+1,0),cur(n+1,0);
        for(int index = n-1;index >= 0;index--){
            for(int prev_index = index-1;prev_index >= -1; prev_index--){
                int notTake = 0 + next[prev_index + 1];
                int take = 0;
                if(prev_index == -1 || nums[index] > nums[prev_index]){
                    take = 1 + next[index + 1];
                } 
                
                cur[prev_index + 1] = max(take,notTake);
            }
            next = cur;
        }
        
        return cur[-1 + 1];
    }
};