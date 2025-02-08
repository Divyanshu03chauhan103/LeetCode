class NumberContainers {
public:
    unordered_map<int,int>mp;
    // unordered_map<int,set<int>>mp1;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp1;
    NumberContainers() {
       
    }
    
    void change(int index, int number) {
        
        // if(mp.find(index)!=mp.end()){
        //     int value = mp[index];
        //     mp1[value].erase(index);
        //     if(mp1[value].empty())
        //         mp1.erase(value);
        // }
        // mp[index]=number;
        // mp1[number].insert(index);

        mp[index]=number;
        mp1[number].push(index);
    }
    
    int find(int number) {
        
        // int index=-1;

        // if(mp1.find(number)!=mp1.end())
        //     index=*mp1[number].begin();

        // return index;

        if(mp1.find(number)==mp1.end()) return -1;

        auto &pq = mp1[number];

        while(!pq.empty()){

            int index=pq.top();

            if(mp[index]==number) return index;
            pq.pop();
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */