class BrowserHistory {
    public:
    
    
public:
    vector<string> v;
    int ind;
    BrowserHistory(string homepage) {
        ind = 0;
        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.erase(v.begin() + ind+1,v.end());
        v.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        if(ind - steps >= 0 )
        {
            ind = ind - steps;
        }
        else
        {
            ind = 0;
        }
        return v[ind];

    }
    
    string forward(int steps) {
        if(ind + steps < v.size())
        {
            ind += steps;
        }
        else
        {
            ind = v.size() - 1;
        }
        return v[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */