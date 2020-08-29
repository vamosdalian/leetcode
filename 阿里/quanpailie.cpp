#include "include.h"

using namespace std;

//vector<string>res为全局变量，表示最终的结果集，最后要返回的
vector<string> res;
void backtrack(string s,string& path,vector<bool>& used)//used数组
{
    if(path.size()==s.size())
    {
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        if(!used[i])
        {
            if(i>=1&&s[i-1]==s[i]&&!used[i-1])//判重剪枝
                continue;
            path.push_back(s[i]);
            used[i]=true;
            backtrack(s,path,used);
            used[i]=false;
            path.pop_back();
        }   
    }
}

vector<string> permutation(string s) {
    if(s.size()==0)
        return{};
    string temp="";
    sort(s.begin(),s.end());
    vector<bool>used(s.size());
    backtrack(s,temp,used);
    return res;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
