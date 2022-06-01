class Solution {
public:
    void coordinate_compression(vector<int> &a) {
    auto d = a;
    int n = (d.size());
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin()+1;
    }
}
struct bit {
  int n;
  vector<long long> a;
 
  void init(int s) {
    a = vector<long long>(s + 1, 0);
    n = s;
  }
 
  void add(int loc, long long x) {
    if (loc <= 0) return;
    while (loc <= n) {
      a[loc] += x;
      loc += loc & (-loc);
    }
  }
 
  long long query(int loc) {
    long long sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
};


    vector<int> countSmaller(vector<int>& nums) {
        coordinate_compression(nums);
        int n=(int)(nums.size());
        vector<int> ans(n);
        bit BIT;
        BIT.init(n);
        for(int i=n-1;i>=0;--i){
            ans[i]=BIT.query(nums[i]-1)-BIT.query(0);
            BIT.add(nums[i],1);
        }
        
        
        return ans;
    }
};