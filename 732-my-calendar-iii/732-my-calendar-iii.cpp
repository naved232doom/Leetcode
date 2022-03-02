class MyCalendarThree {
public:
    map<int, int> mp;

    MyCalendarThree() {
        mp.clear();

    }

    int book(int l, int r) {
        mp[l]++;
        mp[r]--;
        int ans = 0;
        int cur = 0;
        for (auto it : mp) {
            cur += it.second;
            ans = max(ans, cur);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */