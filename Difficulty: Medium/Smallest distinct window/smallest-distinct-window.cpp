//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        vector<int>count(256,0);
        int first = 0;
        int second = 0;
        int len = str.size();
        int diff = 0;
        //Calculate all the unique characters
        while(first < str.size()){
            if(count[str[first]] == 0)diff++;
            count[str[first]]++;
            first++;
        }
        for(int i=0;i<256;i++){
            count[i] = 0;
        }
        first = 0;
        while(second < str.size()){
            //diff exist krta hai
            while(diff && second<str.size()){
                if(count[str[second]] == 0){
                    diff--;
                }
                count[str[second]]++;
                second++;
            }
            len = min(len,second-first);
            while(diff != 1){
                len = min(len,second-first);
                count[str[first]]--;
                if(count[str[first]] == 0)diff++;
                first++;
            }
        }
        
        // diff ki value 1 na ban jaye
        return len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends