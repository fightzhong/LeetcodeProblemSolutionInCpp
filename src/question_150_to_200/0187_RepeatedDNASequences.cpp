//
// Created by 钟胜龙 on 2022/3/6.
//
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences_1(string s) {
        map<string, int> countMap;
        for (int i = 0 ; i + 10 <= s.length(); i ++) {
            string curstr = s.substr(i, 10);
            map<string, int>::iterator it = countMap.find(curstr);
            if (it != countMap.end()) {
                countMap[curstr] = it->second + 1;
            } else {
                countMap[curstr] = 1;
            }
        }

        vector<string> result;
        for(map<string, int>::iterator it = countMap.begin(); it != countMap.end(); it++) {
            if (it->second > 1) {
                result.push_back(it->first);
            }
        }

        return result;
    }

    vector<string> findRepeatedDnaSequences_2(string s) {
        vector<string> result;
        if (s.length() < 10) {
            return result;
        }

        int temp = (1 << 20) - 1;

        map<unsigned int, int> mymap;
        unsigned int val = string_to_int(s, 0, 10);
        mymap[val] = 1;
        mymap[val] = 1;
        for (int i = 10; i < s.length(); i ++) {
            val = ((val << 2) | string_to_int(s, i, 1)) & temp;
            map<unsigned int, int>::iterator it = mymap.find(val);
            if (it == mymap.end()) {
                mymap[val] = 1;
            } else if (it->second == 1) {
                result.push_back(s.substr(i - 9, 10));
                mymap[val] = 2;
            }
        }

        return result;
    }

    int string_to_int(string &s, int index, int count) {
        int data = 0;
        for (int i = 1; i <= count; i ++) {
            char cur = s.at(index);
            int val;
            if (cur == 'A') {
                val = 0;
            } else if (cur == 'C') {
                val = 1;
            } else if (cur == 'G') {
                val = 2;
            } else {
                val = 3;
            }

            data = (data << 2) | val;
            index ++;
        }

        return data;
    }
};

int main() {
//    Solution solution;
//    solution.findRepeatedDnaSequences( "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT" );

    return 0;
}