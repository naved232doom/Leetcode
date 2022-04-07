class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=(int)(stones.size());
        multiset<int,greater<int>> ms(stones.begin(),stones.end());
        while((int)(ms.size())>1){
            auto st1=*(ms.begin());
            ms.erase(ms.begin());
            auto st2=*(ms.begin());
            ms.erase(ms.begin());
            if(st1!=st2){
                ms.insert(st1-st2);
            }
        }
        if(ms.empty()) return 0;
        return *(ms.begin());
    }
};