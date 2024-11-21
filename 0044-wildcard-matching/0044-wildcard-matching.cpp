class Solution {
public:
    
    bool isMatch(string p, string s) {
        int n = s.size();
        int m = p.size();
        vector<bool>prev(m+1,false),cur(m+1,false);
        prev[0] = true;
        for(int j=1;j<=m;j++)prev[j] = false;
        
        for(int i=1;i<=n;i++){
            bool fl = true;
            for(int ii=1;ii<=i;ii++){
                if(s[ii-1] != '*'){
                    fl = false;
                    break;
                }
            }
            cur[0] = fl;
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || s[i-1] == '?'){
                    cur[j] = prev[j-1];
                }
                else if(s[i-1] == '*'){
                    cur[j] = prev[j] || cur[j-1];
                }
                else cur[j] = false;
            }
            prev = cur;
        }
            
        return prev[m];
    }
};