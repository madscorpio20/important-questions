class KthLargest {
    public :
    int k;
    map<int,int> m;
    int siz;
public:
    KthLargest(int pos, vector<int>& nums) {
        siz = 0;
        k= pos;
        for(auto it: nums)
        {
            m[it]++;
            siz++;
        }
        
    }
    
    int add(int val) {
        m[val]++;
        siz++;
        int cnt = 0;
        
        for(auto it: m)
        {
                        cnt+= it.second;
            if(cnt >= siz-k+1)
                return it.first;
        }
        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */