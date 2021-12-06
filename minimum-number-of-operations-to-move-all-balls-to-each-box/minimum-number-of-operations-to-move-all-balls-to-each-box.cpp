class Solution {
public:
    vector<int> minOperations(string boxes) {
        int prefixBalls=0,suffixBalls=0;
        int prefixSum=0,suffixSum=0;
            int n=(int)(boxes.size());
            for(int i=0;i<n;++i){
                    if(boxes[i]=='1'){
                            suffixBalls++;
                            suffixSum+=i;    
                    }
                    
            }
            vector<int> ans;
            for(int i=0;i<n;++i){
                    if(boxes[i]=='0'){
                            ans.push_back(suffixSum+prefixSum);
                            prefixSum+=prefixBalls;
                            suffixSum-=suffixBalls;
                    }
                    else{
                            //suffixSum--;
                            ans.push_back(suffixSum+prefixSum);
                            suffixBalls--;
                            suffixSum-=suffixBalls;
                            prefixBalls++;
                            prefixSum+=prefixBalls;
                    }
            }
            return ans;
    }
};