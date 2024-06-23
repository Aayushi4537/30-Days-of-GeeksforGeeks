//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int> result;
        stack<int> bracketStack;
        int bracketCount = 0;

        for (char ch : str) {
            if (ch == '(') {
                bracketCount++;
                bracketStack.push(bracketCount);
                result.push_back(bracketCount);
            } else if (ch == ')') {
                result.push_back(bracketStack.top());
                bracketStack.pop();
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends