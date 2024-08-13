//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        //String reverse
        string rev = str;
        reverse(rev.begin(),rev.end());
        int size = str.size();
        str += '$';
        str += rev;
        int n = str.size();
        vector<int>lps(n,0);
        int pre = 0;
        int suf = 1;
        while(suf < n){
            //Matched
            if(str[pre] == str[suf]){
                lps[suf] = pre+1;
                suf++;
                pre++;
            }
            else{
                if(pre == 0){
                    suf++;
                }
                else{
                    pre = lps[pre-1];
                }
            }
        }
        return size - lps[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends