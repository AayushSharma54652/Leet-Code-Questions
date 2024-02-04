class Solution {
public:
    int total_days(vector<int> &weights,int n,int cap){
        int load = 0;
        int days = 1;
        for(int i=0;i<n;i++){
            if(load + weights[i] > cap){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n =  weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = (low+high)/2;
            int val = total_days(weights,n,mid);
            if(val <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};