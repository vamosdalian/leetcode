#include "include.h"
using namespace std;

template <typename T>
vector<T> getNums(char c = ' '){
    vector<T> result;
    string str;
    T tmp = 0;
    bool minus = false;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            result.push_back(tmp);
            tmp = 0;
            minus = false;
            continue;
        }
        if(str[i] == '-'){
            minus = true;
            continue;
        }if(str[i] >= '0' && str[i] <= '9'){
            tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
        }
        
    }
    result.push_back(tmp);
    return result;
}

int solution(vector<int> nums, int target){
    vector<vector<int> > points;
    int i = 0, j = 1;
    int sum = nums[0];
    while(j <= nums.size()){
        if(sum == target){
            points.push_back({i,j});
            sum -= nums[i++];
            sum += nums[j++];
        }
        if(sum < target){
            sum += nums[j++];
        }else if(sum > target){
            sum -= nums[i++];
        }
    }
    int result = INT_MAX;
    for(int i = 0; i < points.size();i++){
        for(int j = i + 1; j < points.size(); j++){
            if(points[j][0] >= points[i][1] && points[j][1] - points[j][0] + points[i][1] - points[i][0] < result){
                result = points[j][1] - points[j][0] + points[i][1] - points[i][0];
            }
        }
    }
    if(result == INT_MAX) return -1;
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> inputs = getNums<int>(',');
    vector<int> nums(inputs.begin(), inputs.end() - 1);
    int T = inputs.back();
    cout << solution(nums,T);
    return 0;
}
