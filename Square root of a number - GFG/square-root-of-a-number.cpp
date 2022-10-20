//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        long long s = 0; 
        long long e = x;
        long long ans = s;
        while( s <= e)
        {
            long long mid = (s+e)/2;
            if(pow(mid,2) == x)
            return mid;
            else if(pow(mid,2) < x)
            {
                s = mid + 1;
                ans = mid;
            }
            else
            {
               e = mid-1; 
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends