class Solution {
public:
    int max_r(vector<vector<int>> &mat,int n,int m,int col){
        int maxi = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        while(low <= high){
            int mid = (low+high)/2;
            int max_row = max_r(mat,n,m,mid);
            int left = mid-1 >= 0 ? mat[max_row][mid-1]:-1;
            int right = mid+1 < m ? mat[max_row][mid+1]:-1;
            if(mat[max_row][mid] > left && mat[max_row][mid] > right){
                return {max_row,mid};
            }
            else if(mat[max_row][mid] < left)high = mid-1;
            else low = mid+1;
        }
        return {-1,-1};
    }
};