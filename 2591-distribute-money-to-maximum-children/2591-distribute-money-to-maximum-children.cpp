class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        money -= children;
        if(money/7 > children) return children-1;
        if(money%7 == 0)
        {
            if(money/7 <= children) return money/7;
            else
                return money/7-2 > 0 ? money/7 -2 : 0;
        }
        if(money% 7 == 3)
        {
            if(money/7 == children-1)
            {
                return money/7-1 >=0 ? money/7-1 : 0;
            }
            if(money/7 == children) return children-1;
            if(money/7 < children) return money/7;
        }
        else
        {
            if(money/7 == children)
            {
                return money/7 -1;
            }
            return money/7;
        }
        return money/7;
    }
};