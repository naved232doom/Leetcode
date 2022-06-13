class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=(int)(arr.size());
        k%=n;
        // 1 2 3 4 5 6 7
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
    }
};