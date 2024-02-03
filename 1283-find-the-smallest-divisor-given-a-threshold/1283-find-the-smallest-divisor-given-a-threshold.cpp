class Solution {
public:
    int total(vector<int> &nums,int d){
        int n = nums.size();
        int total = 0;
        for(int i =0;i<n;i++){
            total += ceil((double)(nums[i])/(double)(d));
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        if(n>threshold)return -1;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            int val = total(nums,mid);
            if(val <= threshold){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};