class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int k=(minutesToTest )/minutesToDie +1;
        int ans=0;
        int s=1;
        while(s<buckets){
            s*=k;
            ans++;
        }
        return ans;
        // 14/3 =4 
    }
};