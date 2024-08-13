//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    void lps_find(vector<int>&lps,string s){
        int pre = 0;
        int suf = 1;
        while(suf < s.size()){
            if(s[pre] == s[suf]){
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
    }
    
    int kmp_match(string a,string b){
        vector<int>lps(b.size(),0);
        lps_find(lps,b);
        
        int first = 0;
        int second = 0;
        while(first < a.size()&& second < b.size()){
            //Match
            if(a[first] == b[second]){
                first++;
                second++;
            }
            //else Not matched
            else{
                if(second == 0){
                    first++;
                }
                else{
                    second = lps[second-1];
                }
            }
        }
        //Answer exist
        if(second == b.size())return 1;
        return 0;
    }
  
  
  
    int repeatedStringMatch(string a, string b) {
        // Your code goes here
        if(a == b)return 1;
        int repeat = 1;
        string temp = a;
        while(temp.size() < b.size()){
            temp += a;
            repeat++;
        }
        // Kmp Pattern Search
        if(kmp_match(temp,b) == 1)return repeat;
        //Temp+a,Kmp Search
        if(kmp_match(temp+a,b) == 1)return repeat+1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    }
    return 0;
}

// } Driver Code Ends