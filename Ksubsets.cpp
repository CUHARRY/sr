//partition a given set into 2 equal sum subsets
#include<bits/stdc++.h>
using namespace std;

bool backtrack(vector<int>& sums, vector<int>& nums, int target, int cur, int n, int k) 
    { 
        if(cur==n)
        {
            for(auto& sum:sums)
            {
                if(sum!=target)
                    return false;
            }
            return true;
        }
        
        for(int i=0;i<k;i++)
        {   
            if(sums[i]+nums[cur]>target)
                continue;
            
            sums[i]+=nums[cur];
            cout<<nums[cur]<<" "<<sums[i]<<"\n";
            if(backtrack(sums,nums,target,cur+1,n,k))
                    return true;
            
            sums[i]-=nums[cur];
            cout<<"!!"<<nums[cur];
            if(sums[i]==0)
                return false;
        
        }
        return false;

    }
#check if subsets are possible>

bool CanSubset(vector<int> &vc, int k) {
    int sum = accumulate(vc.begin(), vc.end(), 0);
    if (sum % k != 0) return false;
    sort(vc.rbegin(), vc.rend());

    vector<int>sums(k, 0);

    return backtrack(sums, vc, sum/k, 0, vc.size(), k);
  }


int main(){
    int num; cin>>num;
    vector<int> v(num); 
    for(int i=0;i<num;i++){
        cin>>v[i];
    }

    int k; cin>>k;//k is the number of ss.
   cout<<endl<<CanSubset(v,k);
    
    return 0;

} 
