
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                // cout << i<< " "<<j<<endl;
                if(board[i][j] == word[0] && find(board, visited, word, i, j, 0)){
                    // cout<<visited[0][0]<<visited[0][1]<<endl;
                    return true;
                }
            }
        }
        return false;
    }
    bool find(vector<vector<char> >& board,vector<vector<bool> >& visited, string word, int i, int j, int k){
        // cout<<k<<endl;
        // cout<<visited[0][0]<<visited[0][1]<<endl;
        visited[i][j] = true;
        if(k == word.length() - 1){
            return true;
        }
        if(i+1 < board.size() && board[i+1][j] == word[k+1] && visited[i+1][j] == false){
            // visited[i+1][j] = true;
            if(find(board,visited,word,i+1,j,k+1)){
                return true;
            }
            // visited[i+1][j] = false;
        }
        if(i-1 >= 0 && board[i-1][j] == word[k+1] && visited[i-1][j] == false){
            // visited[i-1][j] = true;
            if(find(board,visited,word,i-1,j,k+1)){
                return true;
            }
            // visited[i-1][j] = false;
        }
        if(j+1 < board[0].size() && board[i][j+1] == word[k+1] && visited[i][j+1] == false){
            // visited[i][j+1] = true;
            // cout << i << j+1 << endl;
            if (find(board,visited,word,i,j+1,k+1)){
                return true;
            }
            // visited[i][j+1] = false;
        }
        if(j-1 >= 0 && board[i][j-1] == word[k+1] && visited[i][j-1] == false){
            // visited[i][j-1] = true;
            // cout << i << j-1 << endl;
            if (find(board,visited,word,i,j-1,k+1)){
                return true;
            }
            // visited[i][j-1] = false;
        }
        visited[i][j] = false;
        return false;
    }
};

// [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
// "ABCESEEEFS"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCCED"

int main(int argc, char const *argv[])
{
    vector<vector<char> > input;
    vector<char> tmp;
    // tmp.push_back('A');
    // tmp.push_back('A');
    // input.push_back(tmp);
    tmp.push_back('A');
    tmp.push_back('B');
    tmp.push_back('C');
    tmp.push_back('E');
    input.push_back(tmp);
    tmp.clear();
    tmp.push_back('S');
    tmp.push_back('F');
    tmp.push_back('E');
    tmp.push_back('S');
    input.push_back(tmp);
    tmp.clear();
    tmp.push_back('A');
    tmp.push_back('D');
    tmp.push_back('E');
    tmp.push_back('E');
    input.push_back(tmp);
    tmp.clear();
    // input.push_back({'A','B','C','E'});
    // input.push_back({'S','F','E','S'});
    // input.push_back({'A','D','E','E'});
    // vector<char> tmp = {'A','B','C','E'};
    // vector<char> tmp = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    // vector<char> tmp = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string str = "ABCESEEEFS";
    Solution *method = new Solution();
    cout << method->exist(input,str);
    return 0;
}
