#include "include.h"

using namespace std;

//获取一维数组
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
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

//获取一维数组
template <typename T>
vector<T> getNums(string str, char c = ' '){
    vector<T> result;
    T tmp = 0;
    bool minus = false;
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
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

int container(vector<int> nums){
    vector<int> leftMax(nums.size(), 0);
    vector<int> rightMax(nums.size(), 0);
    int tmp = 0;
    for(int i = 0;i < nums.size(); i++){
        leftMax[i] = tmp;
        tmp = nums[i] > tmp ? nums[i] : tmp;
    }
    tmp = 0;
    for(int i = nums.size() - 1; i >= 0;i--){
        rightMax[i] = tmp;
        tmp = nums[i] > tmp ? nums[i] : tmp;
    }
    int result = 0;
    for(int i = 0; i < nums.size(); i++){
        result += min(leftMax[i], rightMax[i]) - nums[i] > 0 ? min(leftMax[i], rightMax[i]) - nums[i] : 0;
    }
    return result;
}

void volume(const char *ifile, const char *ofile){
    ifstream infile(ifile);
    ofstream outfile(ofile);
    if(!infile.good()){
        cout << "couldn't open file " << ifile << endl;
        return ;
    }
    while(!infile.eof()){
        char cstr[1024];
        infile.getline(cstr, 1024);
        string str(cstr);
        vector<int> nums = getNums<int>(str,' ');
        outfile << container(nums) << endl;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char const *argv[])
{
    if(argc < 3){
        cout << "input error ";
        return 0;
    }
    volume(argv[1], argv[2]);
    return 0;
}
