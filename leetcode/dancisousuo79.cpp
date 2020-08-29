#include "include.h"

using namespace std;

bool dfs(vector<vector<char> >& board, string& word, int i,int j,int length){
    if(i>=board.size()||j>=board[0].size()||i<0||j<0||length>=word.size()||word[length]!=board[i][j]){
        return false;
    }
    if(length==word.size()-1&&word[length]==board[i][j]){
        return true;
    }
    char temp=board[i][j];
    board[i][j]='0';
    bool flag=dfs(board,word,i,j+1,length+1)||dfs(board,word,i,j-1,length+1)||dfs(board,word,i+1,j,length+1)||dfs(board,word,i-1,j,length+1);
    board[i][j]=temp;  // 标记过的点恢复原状，以便进行下一次搜索
    return flag;
}

bool exist(vector<vector<char> >& board, string word) {
    if(board.size() == 0) return false;
    for (int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if (dfs(board,word,i,j,0)){
                return true;
            }
        }
    }
    return false;
}

string getString(){
    string result;
    getline(cin, result);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<char> > m{{'0','1','C','H','A'},{'9','E','7','B','I'},{'k','D','4','8','J'},{'6','5','F','G','O'},{'L','N','M','2','3'}};
    string str;
    while (getline(cin,str))
    {
        if(exist(m,str)){
            cout << "Y"<<endl;
        }else{
            cout << "N"<<endl;
        }
    }
    return 0;
}
