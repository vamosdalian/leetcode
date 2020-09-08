#include "include.h"

using namespace std;

//获取一个字符串
string getString(){
    string result;
    getline(cin, result);
    return result;
}


bool find(vector<vector<char> >& board,vector<vector<bool> >& visited, string word, int i, int j, int k){
    visited[i][j] = true;
    if(k == word.length() - 1){
        return true;
    }
    if(i+1 < board.size() && board[i+1][j] == word[k+1] && visited[i+1][j] == false){
        if(find(board,visited,word,i+1,j,k+1)){
            return true;
        }
    }
    if(i-1 >= 0 && board[i-1][j] == word[k+1] && visited[i-1][j] == false){
        if(find(board,visited,word,i-1,j,k+1)){
            return true;
        }
    }
    if(j+1 < board[0].size() && board[i][j+1] == word[k+1] && visited[i][j+1] == false){
        if (find(board,visited,word,i,j+1,k+1)){
            return true;
        }
    }
    if(j-1 >= 0 && board[i][j-1] == word[k+1] && visited[i][j-1] == false){
        if (find(board,visited,word,i,j-1,k+1)){
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
            if(board[i][j] == word[0] && find(board, visited, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char const *argv[])
{
    vector<vector<char> > input{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string str = getString();
    bool result = exist(input, str);
    if(result){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}
