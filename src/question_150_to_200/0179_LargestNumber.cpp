//
// Created by 钟胜龙 on 2022/3/6.
//
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool MyCompare(int n1, int n2) {
    string s1 = to_string(n1);
    string s2 = to_string(n2);
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        if ( nums.size() == 1 ) {
            return to_string(*nums.begin());
        }

        sort(nums.begin(), nums.end(), MyCompare);
        if ( *nums.begin() == 0 ) {
            return "0";
        }

        string result;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i ++) {
            result += to_string(*i);
        }

        return result;
    }
};

int main() {
    vector<int> nums;
    nums.push_back( 111311 );
    nums.push_back( 1113 );

    Solution solution;
    solution.largestNumber(nums);


    return 0;
}