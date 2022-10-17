class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=num; i>=0; i--)
        {
            string rev = to_string(i);
            string rev2;
            for(int i=rev.size()-1; i>=0; i--)
                rev2+=rev[i];
            int j = stoi(rev2);
            if(i+j == num)
                return true;
        }
        return false;
    }
};