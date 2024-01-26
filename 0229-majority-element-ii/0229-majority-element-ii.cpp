class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1)cnt1++;
            else if(nums[i] == el2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int>ls;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
        }
        int mini = (int)(n/3)+1;
        if(cnt1 >= mini)ls.push_back(el1);
        if(cnt2 >= mini)ls.push_back(el2);
        sort(ls.begin(),ls.end());
        return ls;
    }
};