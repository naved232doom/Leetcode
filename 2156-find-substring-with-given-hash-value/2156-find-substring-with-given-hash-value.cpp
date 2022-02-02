class Solution {
    typedef long long ll;
    const int N = 2e4 + 5;
    ll fact[200000];
    ll invFact[200000];
    ll mod;
    ll fast_pow(ll a, ll p)
    {
        ll res = 1;
        while (p)
        {
            if (p % 2 == 0)
            {
                a = (a * a) % mod;
                p /= 2;
            }
            else
            {
                res = (res * a) % mod;
                p--;
            }
        }
        return res;
    }

    void precalc()
    {
        fact[0] = invFact[0] = 1;
        for (int i = 1; i < N; i++)
        {
            fact[i] = (fact[i - 1] * i) % mod;
            invFact[i] = fast_pow(fact[i], mod - 2);
        }
    }

    ll C(int n, int k)
    {
        if (k > n)
        {
            return 0;
        }
        return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
    }
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        mod = modulo;
        ll K = k;
        ll H = hashValue;
        ll P = power;
        int n = (int)(s.size());
        ll hash_here = 0;
        ll pref = 0;
        for (ll i = n - 1, cnt = k - 1; i >= 0 && cnt >= 0; --i, --cnt) {
            ll c_here = s[i] - 'a' + 1;
            ll v_here = (c_here * fast_pow(P, cnt))%mod;
            hash_here += v_here;
            //pref+=c_here;
            hash_here %= mod;
        }
        //cout << hash_here << endl;
        reverse(s.begin(), s.end());
        vector<ll> hashes(n,-1);
        hashes[k-1]=hash_here;
        for (int i = 0; i < n; ++i) {
            if (i < k) continue;
            ll prev_c = s[i - k] - 'a' + 1;
            ll cur_c = s[i] - 'a' + 1;
            hash_here = hash_here * P;
            hash_here %= mod;
            hash_here = (hash_here - (prev_c * fast_pow(P, k) % mod) + mod) % mod;
            hash_here += cur_c;
            hash_here %= mod;
            hashes[i] = hash_here;
        }
            reverse(s.begin(),s.end());
        reverse(hashes.begin(), hashes.end());
        for (int i = 0; i < n; ++i) {
                if(hashes[i]==-1) continue;
            if (hashes[i] == H) return s.substr(i,k);
        }
        return "";
    }
};