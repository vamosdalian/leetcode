#include "include.h"

using namespace std;

//获取一个数字
template <typename T>
T getNum(){
    T result = 0;
    string str;
    bool isFushu = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '-'){
            isFushu = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}

//获取一维字符串组
vector<string> getStrings(char c = ' '){
    vector<string> result;
    string str;
    string tmpStr;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            if(!tmpStr.empty()){
                result.push_back(tmpStr);
                tmpStr.clear();
            }
            continue;
        }
        tmpStr.push_back(str[i]);
    }
    result.push_back(tmpStr);
    return result;
}

bool isHuangJiaTongHuaShun(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    char tmpchar = '0';
    for(auto num : nums){
        mymap[num[0]]++;
        if(mymap[num[0]] == 5){
            tmpchar = num[0];
            break;
        }
    }
    if(tmpchar == '0') return false;
    unordered_map<char, int> duiyin;
    duiyin.insert(make_pair(1,0));
    duiyin.insert(make_pair(13,0));
    duiyin.insert(make_pair(12,0));
    duiyin.insert(make_pair(11,0));
    duiyin.insert(make_pair(10,0));
    for(auto num : nums){
        if(num[0] == tmpchar){
            duiyin[num[1]]++;
        }
    }
    for(auto item : duiyin){
        if(item.second == 0){
            return false;
        }
    }
    return true;
}

bool isTongHuaShun(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    char tmpchar = '0';
    for(auto num : nums){
        mymap[num[0]]++;
        if(mymap[num[0]] == 5){
            tmpchar = num[0];
            break;
        }
    }
    if(tmpchar == '0') return false;
    // char max = 0;
    // char min = 14;
    vector<int> tmpvec(15,0);
    for(auto num : nums){
        if(num[0] == tmpchar){
            tmpvec[num[1]]++;
        }
    }
    int count = 0;
    for(int i = 1;i <= 14 ;i++){
        if(tmpvec[i]==0){
            count = 0;
        }else{
            count++;
        }
        if(count == 5){
            return true;
        }
    }
    return false;
    
}

bool isSiTiao(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
        if(mymap[num[1]] >= 4){
            return true;
        }
    }
    return false;
}

bool isHuLu(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
    }
    int has2 = false;
    int has3 = false;
    for(auto item : mymap){
        if(item.second == 2){
            has2 = true;
        }else if(item.second == 3){
            has3 = true;
        }
    }if(has2 && has3) return true;
    return false;
}

bool isTongHua(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
        if(mymap[num[1]] >= 5){
            return true;
        }
    }
    return false;
}

bool isShunZi(vector<vector<char> > nums){
    vector<int> myvec(15,0);
    for(auto num : nums){
        myvec[num[1]]++;
    }
    if(myvec[1] && myvec[13]&& myvec[12]&& myvec[11]&& myvec[10]) return true;
    int count = 0;
    for(int i = 1; i <= 14;i++){
        if(myvec[i] == 0){
            count = 0;
        }else {
            count ++;
        }
        if(count >= 5){
            return true;
        }
    }
    return false;
}

bool isSanTiao(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
        if(mymap[num[1]] >= 3){
            return true;
        }
    }
    return false;
}

bool isLiangDui(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
    }
    int count = 0;
    for(auto item : mymap){
        if(item.second>=2){
            count++;
        }
    }
    if(count >=2){
        return true;
    }
    return false;
}

bool isYiDui(vector<vector<char> > nums){
    unordered_map<char, int> mymap;
    for(auto num : nums){
        mymap[num[1]]++;
        if(mymap[num[1]] >= 2){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    vector<string> str = getStrings();
    vector<vector<char> > nums;
    vector<char> tmpnum(2,0);
    for(auto s : str){
        if(s[1] == 'A'){
            tmpnum[0] = s[0];
            tmpnum[1] = 1;
            nums.push_back(tmpnum);
        }else if(s[1] == '1'){
            tmpnum[0] = s[0];
            tmpnum[1] = 10;
            nums.push_back(tmpnum);
        }else if(s[1] == 'J'){
            tmpnum[0] = s[0];
            tmpnum[1] = 11;
            nums.push_back(tmpnum);
        }else if(s[1] == 'Q'){
            tmpnum[0] = s[0];
            tmpnum[1] = 12;
            nums.push_back(tmpnum);
        }else if(s[1] == 'K'){
            tmpnum[0] = s[0];
            tmpnum[1] = 13;
            nums.push_back(tmpnum);
        }else{
            tmpnum[0] = s[0];
            tmpnum[1] = s[1] - '0';
            nums.push_back(tmpnum);
        }
    }
    if(isHuangJiaTongHuaShun(nums)){
        cout << "HuangJiaTongHuaShun";
    }else if(isTongHuaShun(nums)){
        cout << "TongHuaShun";
    }else if(isSiTiao(nums)){
        cout << "SiTiao";
    }else if(isHuLu(nums)){
        cout << "HuLu";
    }else if(isTongHua(nums)){
        cout << "TongHua";
    }else if(isShunZi(nums)){
        cout << "ShunZi";
    }else if(isSanTiao(nums)){
        cout << "SanTiao";
    }else if(isLiangDui(nums)){
        cout << "LiangDui";
    }else if(isYiDui(nums)){
        cout << "YiDui";
    }else{
        cout << "GaoPai";
    }
    // cout << isTongHuaShun(nums);
    // cout << isSiTiao(nums);
    // cout << isHuLu(nums);
    // cout << isTongHua(nums);
    // cout << isShunZi(nums);
    // cout << isSanTiao(nums);
    // isLiangDui(nums);
    // isYiDui(nums;)
    return 0;
}
