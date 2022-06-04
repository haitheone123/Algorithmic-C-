#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 

void xuly(){
    vector<ll>nums;
    ll k;
    while(cin>>k){
        nums.push_back(k);
        sort(nums.begin(),nums.end());
        if(nums.size()%2==0){
            cout<<(nums[nums.size()/2-1] + nums[nums.size()/2])/2<<endl;
        }
        else{
            cout<<nums[(nums.size()-1)/2]<<endl;
        }
    }
}
int main(){
    xuly();
}