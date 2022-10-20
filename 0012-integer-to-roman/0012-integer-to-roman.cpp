class Solution {
public:
    string intToRoman(int num) {
        string output;
        if(num >= 1000)
        {
            int cnt = num/1000;
            while(cnt > 0)
            {
                cnt--;
                output+="M";
            }
            num = num%1000;
        }
        if(num >=900 && num < 1000)
        {
            output += "CM";
            num = num - 900;
        }
        if(num >=500 && num < 900)
        {
            output += "D";
            num = num - 500;
        }
        if(num >=400 && num <500)
        {
            output += "CD";
            num = num - 400;
        }
        if(num >= 100 && num < 400)
        {
            int cnt = num/100;
            while(cnt > 0)
            {
                cnt--;
                output+="C";
            }
            num = num%100;
        }
        if(num >=90 && num <100)
        {
            output += "XC";
            num = num%10;
        }
        if(num >=50 && num < 90)
        {
            output += "L";
            num = num%50;
        }
        if(num >= 40 && num <50)
        {
            output += "XL";
            num = num%40;
        }
        if(num >= 10 && num <=39)
        {
            int cnt = num/10;
            while(cnt > 0)
            {
                cnt--;
                output+="X";
            }
            num = num%10;
        }
        if(num <=3)
        {
            for(int i=1; i<=num; i++)
                output+= 'I';
            return output;
        }
        if(num == 4)
            output += "IV";
        if(num <=8 && num >=5)
        {
            output += "V";
            for(int i=1; num - i >=5; i++)
            {
                output+= "I";
            }
        }
        if(num == 9)
            output+= "IX";
        return output;
        
    }
};