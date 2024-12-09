//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.size();
        stack<string>st;
        
        for(int i=0;i<n;i++){
            char c = post_exp[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                st.push(string(1,c));
            }
            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                string con = c + t2 + t1;
                st.push(con);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends