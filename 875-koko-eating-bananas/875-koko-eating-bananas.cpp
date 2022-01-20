class Solution {
private:
    bool possible(vector<int> &piles, int x, int h) {
        int time_taken = 0;
        int n = (int)(piles.size());
        for (int i = 0; i < n; ++i) {
            time_taken += (piles[i] + x - 1) / x;
        }

        return (time_taken <= h ? 1 : 0);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = (piles.size());
        int lb = 1, rb = *max_element(piles.begin(), piles.end()) + 1;
        while (lb < rb) {
            int mid = lb + (rb - lb) / 2;
            if (possible(piles, mid, h)) {
                rb = mid;
            }
            else {
                lb = mid + 1;
            }
        }
        return lb;
    }
};