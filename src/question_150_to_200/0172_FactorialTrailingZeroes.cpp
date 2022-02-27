//
// Created by 钟胜龙 on 2022/2/27.
//
#include <iostream>
using namespace std;

int trailingZeroes(int n);

int main() {
    cout << trailingZeroes( 25 ) << endl;
}

int trailingZeroes(int n) {
    if ( n == 0 ) {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= n; i ++) {
        int temp = i;
        while ( (temp % 5) == 0 ) {
            count ++;
            temp /= 5;
        }
    }

    return count;
}