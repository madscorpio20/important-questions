class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        int curr = 0;
        int start = 0;
        int end = 0;
        for(int i=0; i<words.size(); i++){
            if(words[i].size() + curr <= maxWidth){
                end = i;
                curr+= words[i].size() + 1;
                string s  = "";
                if( i ==words.size()-1){
                    while(start < end){
                        s+= words[start] + " ";
                        start++;
                    }
                    s+= words[end];
                    while(s.size() < maxWidth){
                        s+= " ";
                    }
                    output.push_back(s);
                }
            }
            else{
                string s = "";
                
                if(start == end){
                    s+= words[start];
                    while(s.size() < maxWidth){
                        s+= " ";
                    }
                }
                else
                {
                    int curr_words = end - start + 1;
                    int total_space = maxWidth - (curr - (curr_words));
                    int gaps_space = total_space / (curr_words-1);
                    int left_space = total_space%(curr_words-1);
                    while(start!=end){
                        s+= words[start];
                        for(int k=0; k<gaps_space; k++){
                            s+= " ";
                        }
                        if(left_space > 0){
                            s+= " ";
                            left_space--;
                        }
                        start++;
                    }
                    s+= words[end];
                }
                start = i;
                end = i;
                curr = words[i].size() + 1;
                output.push_back(s);
                if( i ==words.size()-1){
                    string s = "";
                    while(start < end){
                        s+= words[start] + " ";
                        start++;
                    }
                    s+= words[end];
                    while(s.size() < maxWidth){
                        s+= " ";
                    }
                    output.push_back(s);
                }
            }
        }
        return output;
    }
};