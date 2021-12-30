class Solution {
public:
    typedef long long ll;
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0) return -1;
        if (k == 1) return 1;
        // remainder modulo
        // 1+(1*1)=2
        //prev_rem->2
        // power_ten
        ll prev_rem = 1;
        ll power_ten = 1;
        ll cur_num = 1;
        for (int i = 1; i <= k; ++i) {
            // cur_num*=10;
            // if(cur_num<k) continue;
            prev_rem = (prev_rem * 10 + 1) % k;
            if (prev_rem == 0) return i + 1;
        }

        return -1;
    }
};