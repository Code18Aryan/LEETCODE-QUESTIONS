class LRUCachee{
public:
    vector<pair<int,int>> v;
    int n;

    LRUCachee(int capacity){
        
        this -> n = capacity;
    }
    
    int get(int key) {
        
        for(int i=0; i<v.size(); i++){

            if(v[i].first == key){

                int val = v[i].second;
                v.erase(v.begin() + i);
                v.push_back({key,val});

                return val;
            }
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        for(int i=0; i<v.size(); i++){

            if(v[i].first == key){

                v.erase(v.begin()+i);
                v.push_back({key,value});
                return;
            }
        }

        v.push_back({key,value});
        
        if(v.size() > n){

            v.erase(v.begin());
        }
        
    }
};


class LRUCache{
public:

    list<int> dll;
    unordered_map<int,pair<int,list<int>::iterator>> mpp;
    int n;

    LRUCache(int capacity) {
        
        this -> n = capacity;
    }

    void makeRecentUse(int key){

        dll.erase(mpp[key].second);
        dll.push_front(key);
        mpp[key].second = dll.begin();
    }
    
    int get(int key) {
        
        if(mpp.find(key) == mpp.end()) return -1;
        makeRecentUse(key);

        return mpp[key].first;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key) != mpp.end()){

            mpp[key].first = value;
            makeRecentUse(key);

            return;
        }

        dll.push_front(key);
        mpp[key] = {value,dll.begin()};
        n--;

        if(n < 0){

            int val = dll.back();
            dll.pop_back();
            mpp.erase(val);
            n++;
        }
            
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */