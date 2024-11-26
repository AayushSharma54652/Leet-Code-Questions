//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        int n = arr.size();
        vector<int>temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i = 1;i<n;i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind] = arr[i];
            }
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends