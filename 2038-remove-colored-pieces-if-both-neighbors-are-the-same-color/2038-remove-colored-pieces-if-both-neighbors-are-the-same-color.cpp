class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnt_a = 0;
        int cnt_b = 0;
        for(int i=1; i<colors.size()-1; i++){
            if(colors[i-1] == colors[i] && colors[i+1] == colors[i]){
                if(colors[i] == 'A') cnt_a++;
                else cnt_b++;
            }
        }
        if(cnt_a > cnt_b) return true;
        return false;
    }
};