#include "include.h"

using namespace std;

vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
    vector<int> result;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < (n+1)/2; i++)
    {
        cout << i<<endl;
        for (int j = i; j < m - i; j++)
        {
            result.push_back(matrix[i][j]);
            // cout << i <<':'<<j<<endl;
        }
        for (int j = i+1; j < n - i; j++)
        {
            result.push_back(matrix[j][m-i-1]);
            // cout << i <<':'<<m-i-1<<endl;
        }
        for (int j = m-i-2; j > i; j--)
        {
            result.push_back(matrix[n-1-i][j]);
            // cout << n-1-i <<':'<<j<<endl;
        }
        for (int j = n-i-1; j >= i+1; j--)
        {
            result.push_back(matrix[j][i]);
            // cout << j <<':'<<i<<endl;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // vector<vector<int> > input{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // vector<vector<int> > input{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int> > input{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,28,19,20}};
    vector<int> output =  SpiralMatrix(input);
    for (auto item : output)    
    {
        cout << item << " ";
    }
    
    return 0;
}
    