#include "include.h"
#include "bits/stdc++.h"

using namespace std;

int shuzi(int n){
    vector<int> dp;
    if(n == 0) return 0;
    else dp.push_back(0);
    int p2 = 0, p3 =0, p5 = 0;
    while(--n >= 0){
        int tmp = min(dp[p2] * 10 + 2, min(dp[p3]*10+3, dp[p5] * 10 + 5));
        if(tmp == dp[p2] * 10 + 2){
            dp.push_back(tmp);
            p2++;
        }else if(tmp == dp[p3] * 10 + 3){
            dp.push_back(tmp);
            p3++;
        }else if(tmp == dp[p5] * 10 + 5){
            dp.push_back(tmp);
            p5++;
        }
    }
    return dp[dp.size() - 1];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << shuzi(n);
    return 0;
}
