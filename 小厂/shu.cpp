#include "include.h"
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n;
    m = n;
    vector<int> nums;
    while(n > 0){
        nums.push_back(n%10);
        n /= 10;
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size();j++){
            if(nums[j] < nums[i]){
                swap(nums[i],nums[j]);
                i = nums.size();
                j = nums.size();
            }
        }
    }
    int result = 0;
    for(auto iter = nums.rbegin(); iter != nums.rend();iter++){
        result = result*10 + *iter;
    }
    if(m == result){
        cout << -1;
    }else{
        cout << result;
    }
    return 0;
}
