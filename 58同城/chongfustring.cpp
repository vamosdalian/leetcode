#include "include.h"

using namespace std;

class Solution {
public:
    /**
     * 
     * @param values string字符串二维数组 
     * @param valuesRowLen int values数组行数
     * @param valuesColLen int* values数组列数
     * @return string字符串vector
     */
    vector<string> findCommonString(string** values, int valuesRowLen, int* valuesColLen) {
        if(valuesRowLen == 0) return {};
        if(valuesColLen[0] == 0) return {};
        unordered_map<string, int> visited;
        for (int i = 0; i < valuesColLen[0]; i++)
        {
            visited.insert(make_pair(values[0][i], 1));
        }
        for (int i = 0; i < valuesRowLen; i++)
        {
            for (int j = 0; j < valuesColLen[i]; j++)
            {
                auto item =  visited.find(values[i][j]);
                if(item != visited.end()){
                    item->second++;
                }
            }
            
        }
        vector<string> result;
        for (auto item : visited)
        {
            if(item->second == valuesRowLen){
                result.push_back(item->first);
            }
        }
        
        return result;
        
    }
};