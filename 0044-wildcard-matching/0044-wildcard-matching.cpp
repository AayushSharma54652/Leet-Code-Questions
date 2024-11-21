class Solution {
public:
    bool f(int i,int j,string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0)return true;
        if(i == 0 && j > 0)return false;
        if(j == 0 && i > 0){
            for(int ii=1;ii<=i;ii++){
                if(s[ii - 1] != '*')return false;
            }
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i-1] == p[j-1] || s[i-1] == '?')return dp[i][j] = f(i-1,j-1,s,p,dp);
        
        if(s[i-1] == '*'){
            return dp[i][j] = f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string p, string s) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
    }
};