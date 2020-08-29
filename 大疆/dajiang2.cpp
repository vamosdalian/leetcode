#include <iostream>
#include <vector>
 
using namespace std;
 
int fun(int n,int v,vector<int> weight,vector<int> price,vector<int> res){
    for(int i=1;i<=n;++i){
        for(int j=v;j>=weight[i];--j){//注意j必须从v开始
            res[j] = max(res[j-weight[i]]+price[i],res[j]);
        }
    }
    return res[v];
}
 
int main(){
    int n,v;
    cin>>n>>v;
    
    vector<int> weight(n+1,0);
    vector<int> price(n+1,0);
    vector<int> res(v+1);
    
    for(int i=1;i<=n;++i){
        // cin>>weight[i]>>price[i];
        cin>>price[i]>>weight[i];
    }
    
    int ans = fun(n,v,weight,price,res);
    cout<<ans<<endl;
    
    return 0;
}