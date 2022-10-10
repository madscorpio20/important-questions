class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<=1)
            return "";
        bool replaced = false;
        for(int i=0; i<palindrome.size(); i++)
        {
            if(palindrome[i] != 'a' && (palindrome.size()%2 == 0 ||  
                                        i!=palindrome.size()/2))
            {
                palindrome[i] = 'a';
                replaced = true;
                break;
            }
        }
        if(replaced)
            return palindrome;
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};