class MyHashSet {
public:
    vector<int> u;
    MyHashSet() {
        u.assign(1e6+1,0);
    }
    
    void add(int key) {
        u[key]|=1;
    }
    
    void remove(int key) {
        u[key]&=0;
    }
    
    bool contains(int key) {
        return u[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */