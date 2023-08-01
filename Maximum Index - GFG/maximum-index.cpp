//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        vector<int> left(N);
        vector<int> right(N);
        int mini = A[0];
        for(int i=0; i<N; i++)
        {
            mini = min(A[i], mini);
            left[i] = mini;
        }
        int maxi = A[N-1];
        for(int i= N-1; i>=0; i--)
        {
            maxi = max(maxi, A[i]);
            right[i] = maxi;
        }
        int leftInd = 0;
        int rightInd = 0;
        int ans = 0;
        while(leftInd < N && rightInd < N)
        {
           
            if(left[leftInd] <= right[rightInd]){
                 ans = max(ans, rightInd - leftInd);
                rightInd++;
            }
            else
                leftInd++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends