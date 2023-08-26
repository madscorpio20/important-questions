//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int missing,repeating;
        for(int i=0; i<n; i++){
            int ind = abs(arr[i]);
            if(arr[ind-1] < 0){
                repeating = ind;
            }
            else{
                arr[ind-1] *=-1;
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                missing = i+1;
            }
        }
        vector<int> ans;
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends