#include "include.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {
        //bfs
        int count = 0;
        vector<vector<int> > map(m, vector<int>(n, 0));
        queue<vector<int> > visited;
        visited.push({0,0});
        map[0][0] = 1;
        while(!visited.empty()){
            auto item = visited.front();
            cout << item[0] << item[1] << endl;
            count++;
            if(item[0] + 1 < m && map[item[0] + 1][item[1]] == 0 && canGo(item[0] + 1, item[1], k)){
                map[item[0] + 1][item[1]] = 1;
                visited.push({item[0] + 1,item[1]});
            }
            if(item[0] - 1 >= 0 && map[item[0] - 1][item[1]] == 0 && canGo(item[0] - 1, item[1], k)){
                map[item[0] - 1][item[1]] = 1;
                visited.push({item[0] - 1,item[1]});
            }
            if(item[1] + 1 < n && map[item[0]][item[1] + 1] == 0 && canGo(item[0], item[1] + 1, k)){
                map[item[0]][item[1] + 1] = 1;
                visited.push({item[0],item[1] + 1});
            }
            if(item[1] - 1 >= 0 && map[item[0]][item[1] - 1] == 0 && canGo(item[0], item[1] - 1, k)){
                map[item[0]][item[1] - 1] = 1;
                visited.push({item[0],item[1] - 1});
            }
            visited.pop();
        }
        return count;
    }
    bool canGo(int i, int j, int k){
        while(i){
            k -= i % 10;
            i /= 10;
        }
        while(j){
            k -= j % 10;
            j /= 10;
        }
        if(k < 0){
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution *method = new Solution();
    cout << method->movingCount(2,3,17);
    return 0;
}