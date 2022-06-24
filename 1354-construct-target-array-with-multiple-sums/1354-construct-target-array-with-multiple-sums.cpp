class Solution {
public:
    bool isPossible(vector<int>& arr) {
        // 1 2 3 2 3 5
        int n=(int)(arr.size());
        //
        // 3 9 17
        // 3 5 17
        // 3 5 9
        multiset<int64_t,greater<int64_t>> st(arr.begin(),arr.end());
        bool ok=1;
        int64_t S=0;
        for(int i=0;i<n;++i) S+=arr[i];
        // 8 5
        // here=8, s_left=5, rem= 3
        // S= 10
        // 3 5
        // s_left=3, here=5, rem= 2
        // s_left=5-3=2, here=3, rem= 1
        // 9
        // 
        while(true){
            auto here=*(st.begin());
            // cout<<"here "<<here<<endl;
            // cout<<"S "<<S<<endl;
            auto s_left=S-here;
            if(here==1|| s_left==1) return true;
            if(here <= s_left ||s_left<=0) break;
            auto rem= here%s_left;
            //cout<<rem<<endl;
            if(rem==0){
                break;
            }
            st.erase(st.begin());
            S-=here;
            st.insert(rem);
            S+=rem;
            // cout<<"rem "<<rem<<endl;
            // cout<<"st: ";
            // for(auto v:st){
            //     cout<<v<<" ";
            // }
            // cout<<"\n";
            // int B=*(st.begin());
            // if(B==1) break;
           // cout<<"*(st.begin()) "<<*(st.begin())<<endl;
        }
        int B=*(st.begin());
        // cout<<"st.size() "<<st.size()<<endl;
        // cout<<"B "<<B<<endl;
        if((int)(st.size())==n && B==1) return true;
        return false;
    }
};