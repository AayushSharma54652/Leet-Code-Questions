class Solution {
public:
    int lower(vector<int>&arr,int n,int x){
    int low =0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    
    }
    int upper(vector<int>&arr,int n,int x){
    int low =0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
    
    }
    vector<int>getboth(vector<int> &nums,int n,int x){
        int f = lower(nums,n,x);
        int l = upper(nums,n,x)-1;
        if(f == n || nums[f] != x)return{-1,-1};
        return{f,l};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans = getboth(nums,n,target);
        return ans;
    }
};