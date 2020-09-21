// // #include <bits/stdc++.h>
// #include "include.h"

// using namespace std;

// class Solution {
// public:
//     bool isMagic(vector<int>& target) {
//         int n = target.size();
        
//         for(int k=1; k<=n; k++){
//             vector<int> a;
//             for(int i = n; i>0; i--){
//                 a.push_back(i);
//             }
//             vector<int> res;
//             while(1){
//                 vector<int> ou;
//                 vector<int> ji;
//                 for(int i=0; i<a.size(); i++) {
//                     if(i%2 == 1){
//                         ou.push_back(a[i]);
//                     }else{
//                         ji.push_back(a[i]);
//                     }
//                 }
//                 for(int i=0; i<ou.size(); i++) {
//                     ji.push_back(ou[i]);
//                 }

//                 int flag1 = 0;
//                 for(int i=0; i<k; i++){
//                     int len = ji.size();
//                     if(len == 0){
//                         flag1 = 1;
//                         break;
//                     }
//                     int num = ji[len-1];
//                     ji.pop_back();
//                     res.push_back(num);
//                 }

//                 a.clear();
//                 for(int i=0;i<ji.size(); i++){
//                     a.push_back(ji[i]);
//                 }

//                 int flag = 0;
//                 for(int i=0; i<res.size(); i++) {
//                     //cout << res[i] << " ";
//                     if(res[i] != target[i]){
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if(flag == 0 && res.size() == n){
//                     //cout << "k:" << k<<endl;
//                     return true;
//                 }
//                 if(flag1 == 1)
//                     break;
//             }
//             //cout << endl;
//         }
//         return false;
//     }
// };

// int main(){
//     vector<int> vec;
//     vec.push_back(2);
//     vec.push_back(4);
//     vec.push_back(3);
//     vec.push_back(1);
//     vec.push_back(5);
//     Solution s;
//     int res = s.isMagic(vec);
//     cout << "res" << res << endl;
//     }

#include "include.h"

using namespace std;
//     int c(int n,int m){
//         // cout << "c(" << n << ","<< m<<endl;
//         if(m == 0) return 0;
//         if(m == n) return 1;
//         int result = 1;
//         int s = n - m;
//         for(int i = n;i > m;i--){
//             result *= i;
//         }
//         for(int i = s;i >= 1;i--){
//             result /= i;
//         }
//         return result;
//     }

//     //模拟
//     int paintingPlan(int n, int k) {
//         if(k < n) return 0;
//         if(k > n * n) return 0;
//         if(k == n * n) return 1;
//         int result = 0;
//         if(k % n == 0){
//             result += 2 * c(n,k/n);
//         }
//         for(int i = 1; i <= n; i++){  
//             for(int j = 1; j <= n;j ++){
//                 if(i * n + j * n - i * j == k){
//                     result += c(n, i) * c(n, j);
//                 }
//             }
//         }
//         return result;
//     }


// int main(int argc, char const *argv[])
// {
//     for (int i = 1; i <= 6; i++)
//     {
//         for (int j = 0; j <= i*i; j++)
//         {
//             cout  << i << " " << j << " "<< paintingPlan(i,j) << endl;
//         }
        
//     }
    
//     return 0;
// }


int main(int argc, char const *argv[])
{
    int a = 10;
    char s[] = "ascdefg";
    cout << strlen(s);
    return 0;
}
