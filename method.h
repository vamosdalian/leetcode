#ifndef _METHOD_H_
#define _METHOD_H_

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

using namespace std;

//获取素数列表(n > 1)
//返回vector<bool>代表该位是否为素数
vector<bool> countPrimes(int n);
//二分查找
//查找target值
int binary_search(vector<int> nums, int target);
//二分查找
//查找target区间的最左侧端点
int left_bound(vector<int> nums, int target);
//二分查找
//查找target区间的最右侧端点
int right_bound(vector<int> nums, int target);

#endif