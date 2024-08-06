//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string sort(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << sort(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string sort(string s){
    vector<int>ans(26,0);
    for(int i=0;i<s.size();i++){
        ans[s[i] - 'a']++;
    }
    string final;
    for(int i=0;i<26;i++){
        char c = 'a' + i;
        while(ans[i]){
            final += c;
            ans[i]--;
        }
    }
    return final;
}