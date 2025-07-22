class TimeMap {
    unordered_map<string, vector<pair<int,string>>> keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        string res="";

        int l=0; int r=values.size()-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(values[mid].first <= timestamp){
                res=values[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */