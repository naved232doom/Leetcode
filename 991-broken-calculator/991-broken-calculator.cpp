class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        // case 1
        if(startValue>=target){
            return startValue-target;
        }
        // case 2
        while(startValue!=target){
            //cout<<target<<endl;
            if(target<startValue){
                ans+=startValue-target;
                break;
            }
            else if(target%2){
                ans++;
                target++;
            }
            
            else{
                target/=2;
                ans++;
            }
        }
        
        return ans;
    }
};