#include "include.h"

using namespace std;

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

void getPath(vector<string> &inputs, int &k, string &tmpstr, set<char> &visited, bool &hasvis, vector<string> &result){
    if(k == inputs.size()){
        if(hasvis){
            result.push_back(tmpstr+"--circular dependency");
        }else{
            result.push_back(tmpstr);
        }
        return;
    }
    string str = inputs[k];
    for (int i = 0; i < str.size(); i++){
        tmpstr.push_back(str[i]);
        k++;
        auto item = visited.find(str[i]);
        if(item == visited.end()){
            visited.insert(str[i]);
        }else{
            hasvis = true;
        }
        getPath(inputs, k, tmpstr,visited, hasvis, result);
        if(item == visited.end()){
            item = visited.find(str[i]);
            visited.erase(item);
        }else{
            hasvis = false;
        }
        k--;
        tmpstr.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    vector<string> inputs = getStrings();
    vector<string> result;
    int k = 0;
    string tmpstr;
    set<char> visited;
    bool hasvis = false;
    getPath(inputs, k, tmpstr, visited, hasvis, result);
    for(auto str : result){
        cout << str << endl;
    }
    return 0;
}

//a bc df gh
//a bc d eag f



