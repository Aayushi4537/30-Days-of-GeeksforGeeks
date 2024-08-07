//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  const int MOD = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        int n= arr.size();
        long long int product =1;
        int max_neg= INT_MIN;
        int count_neg=0;
        int count_zero=0;
        if(n==1){
            return arr[0];
            }
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count_zero++;
                continue;
            }
            if(arr[i]<0){
                count_neg++;
                max_neg= max(max_neg, arr[i]);
            }
            
           
           
            product= product*arr[i]%MOD;
                
            
        }
        if (count_zero == n) {
        return 0;
    }

    // If there's exactly one negative number and all others are zeros
    if (count_neg == 1 && count_zero + count_neg == n) {
        return 0;
    }
        if(count_neg & 1){
            product=product/max_neg;
        }
        return product;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends