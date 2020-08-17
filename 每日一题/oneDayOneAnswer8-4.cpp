#include "include.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        for(int i = 0 ; i < prerequisites.size();++i){
            int len = prerequisites[i].size();
            cout << "len:"<<len<<endl;
        }
        vector<int> indegrees(numCourses, 0);
        queue<int> visited;

        for(int i = 0; i < prerequisites.size(); ++i){
            indegrees[prerequisites[i][0]]++;
        }
        // for(auto i : indegrees){
        //     cout << i << "   ";
        // }
        // cout <<endl;
        for(int i = 0; i < indegrees.size(); ++i){
            if(indegrees[i] == 0){
                visited.push(i);
            }
        }
        while(!visited.empty()){
            auto item = visited.front();
            cout<<item <<":"<<indegrees[item]<<endl;
            for(int i = 0; i < prerequisites.size(); ++i){
                if(prerequisites[i][1] == item){
                    indegrees[prerequisites[i][0]]--;
                    if(indegrees[prerequisites[i][0]] == 0){
                    visited.push(prerequisites[i][0]);
                }
                }
                
            }
            indegrees[item] = -1;
            visited.pop();
            // numCourses--;
        }
        for(int i = 0; i < indegrees.size(); ++i){
            if(indegrees[i] >= 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int input = 4;
    vector<vector<int> > inlist;
    inlist.push_back({2,0});
    inlist.push_back({3,1});
    inlist.push_back({3,2});
    inlist.push_back({1,0});
    inlist.push_back({1,3});
    // {,{1,0},{3,1},{3,2},{1,3}};
    Solution *method = new Solution();
    cout << method->canFinish(input,inlist);
}