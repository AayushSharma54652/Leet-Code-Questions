class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>cur(m,0);
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0)cur[j] = grid[0][0];
                
                else{
                    int up = grid[i][j];
                    //requiring previos row j col
                    if(i > 0)up += prev[j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    //currrent row j-1 col
                    if(j > 0)left += cur[j-1];
                    else left += 1e9;
                    
                    cur[j] = min(up,left);
                }
            }
            prev = cur;
        }
        return prev[m-1];
    }
};