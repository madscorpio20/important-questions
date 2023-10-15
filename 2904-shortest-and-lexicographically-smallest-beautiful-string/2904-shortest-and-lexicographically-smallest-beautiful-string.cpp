class Solution {
public:
    
    // bool cmp(string &s1, string &s2){
    //     int ind1 = s1.size()-1;
    //     int ind2 = s2.size()-1;
    //     int cnt1 = ind1;
    //     int cnt2 = ind2;
    //     vector<int> v1;
    //     vector<int> v2;
    //     // cout<<"in"<<endl;
    //     while(ind1 >=0){
    //         // cout<<ind1<<endl;
    //         if(s1[ind1] == '1'){
    //             v1.push_back(s1.size() - ind1);
    //         }
    //         ind1--;
    //     }
    //     while(ind2 >=0){
    //         if(s2[ind2] == '1'){
    //             v2.push_back(s2.size() - ind2);
    //         }
    //         ind2--;
    //     }
    //     for(int i=v1.size()-1; i>=0; i--){
    //         if(v1[i]!=v2[i]){
    //             return v1[i] < v2[i];
    //         }
    //     }
    //     // cout<<cnt1<<" "<<cnt2<<endl;
    //     return true;
    // }
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int value = 1e9;
        for(int i=0; i<s.size(); i++){
            string curr = "";
            int cnt = 0;
            for(int j=i; j<s.size(); j++){
                curr += s[j];
                if(s[j] == '1') cnt++;
                if(cnt == k){
                    // cout<<i<<" "<<j<<endl;
                    // cout<<curr<<endl;
                    if(ans.size() == 0 || curr.size() < ans.size()){
                        ans = curr;
                        continue;
                    }
                    if(curr.size() == ans.size())
                        ans = min(ans,curr);
                }
            }
        }
        return ans;
    }
};