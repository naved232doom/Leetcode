class Solution {
        private:
        typedef long long ll;
        long long get_ans_positive(ll num){
            string s=to_string(num);
            int n=(int)(s.size());
            sort(s.begin(),s.end());    
                int non_zero_index=-1;
            for(int i=0;i<n;++i){
                    if(s[i]!='0'){
                            non_zero_index=i;
                            break;
                    }
            }
            if(non_zero_index!=-1){
                    swap(s[non_zero_index],s[0]);
            }
            reverse(s.begin(),s.end());
                long long ans=get_ans(s);
                return ans;
        }
        long long get_ans_negative(ll num){
                num=-num;
            string s=to_string(num);
            int n=(int)(s.size());
            sort(s.rbegin(),s.rend());
              reverse(s.begin(),s.end());
            long long ans=get_ans(s);  
        return -ans;
        }
        long long get_ans(string &s){
                long long ans_here=0;
                int n=s.length();
                for(int i=0;i<n;++i){
                        auto last_digit=(s.back()-'0');
                        s.pop_back();
                        ans_here=ans_here*10+last_digit;
                }
                return ans_here;
        }
public:
    long long smallestNumber(long long num) {
        
                long long ans;
            if(num>=0) return get_ans_positive(num);
            else return get_ans_negative(num);
            //cout<<ans<<"\n";
            return ans;
            
    }
};