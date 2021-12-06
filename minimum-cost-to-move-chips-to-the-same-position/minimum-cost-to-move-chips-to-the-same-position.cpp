class Solution {
public:
    int minCostToMoveChips(vector<int>& arr) {
        int minCost=INT_MAX;
            int n=(int)(arr.size());
            for(int i=0;i<n;++i){
                    int curCost=0;
                    int curPos=arr[i];
                    for(int j=0;j<n;++j){
                            int dis=abs(curPos-arr[j]);
                            if(dis%2){
                                curCost++;    
                            }
                    }
                    minCost=min(minCost,curCost);
            }
            return  minCost;
    }
};