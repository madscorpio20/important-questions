class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        if(n == 0) return true;
        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0) return n == 1;
            else
                return 0;
        }
        for(int i=0; i<flowerbed.size(); i++)
        {
            
            if(i==0)
            {
                if(flowerbed[i+1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    cnt++;
                }
                else
                    continue;
            }
            else if(i == flowerbed.size()-1)
            {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    cnt++;
                }
                else
                    continue;
            }
            else if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {

                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;
    }
};