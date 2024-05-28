class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxi = 0;
        int sum = 0;
        int i=0,j=0;
//      k r p g j b j j z n p z d f y
//      n x a r g k b y d x m  s g b y
//      3    
        // for(int i=0; i<s.size(); i++){
        //     cout<<abs(s[i] - t[i])<<" ";
        // }
        // cout<<endl;
        while(j < s.size()){
            while(j< s.size() && sum <= maxCost){
                // cout<<i<<" "<<j<<" "<<sum<<endl;
                maxi = max(maxi, j-i);
                sum += abs(s[j] - t[j]);
                j++;
            }
            // cout<<j<<" "<<sum<<endl;
            if(j == s.size()){
                if(sum <= maxCost) maxi = max(maxi,j-i);
                break;
            }
            while(i < s.size() && sum > maxCost){
                sum-= abs(s[i] - t[i]);
                i++;
            } 
            if(i > j) j = i;
        }
        return maxi;
    }
};