class FrequencyTracker {
    map<int,int> m;
    map<int,int> freq;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {

        if(freq[m[number]] > 0)
            freq[m[number]]--;
        m[number]++;
        freq[m[number]]++;
    }
    
    void deleteOne(int number) {

        if(!m[number])
            return;
        freq[m[number]]--;
        freq[m[number]-1]++;
        if(m[number])
            m[number]--;
    }
    
    bool hasFrequency(int frequency) {

        if(freq[frequency])
            return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */