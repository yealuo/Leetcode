//
// Created by Administrator on 2024/4/13.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int all_num;
    cin >> all_num;
    string op;
    cin >> op;

    //初始化滑动窗口和指针
    int ptr = 1, top = 1, bottom;
    if (all_num <= 4)    // 只有一页
        bottom = all_num;
    else
        bottom = 4;     //有多页

    for (const auto &o: op) {
        if (o == 'U') {
            if (ptr != top) //指针在滑动窗口之间
                ptr -= 1;
            else if (ptr == top && top == 1) {  //指针在滑动窗口顶部，且滑动窗口上边界在歌曲列表顶部的位置
                bottom = all_num;
                top = bottom - 3 <= 1 ? 1 : bottom - 3;
                ptr = bottom;
            } else {    //指针在滑动窗口顶部，且滑动窗口在歌曲列表中间
                top -= 1;
                bottom -= 1;
                ptr = top;
            }
        } else if (o == 'D') {
            if (ptr != bottom)  //指针在滑动窗口之间
                ptr += 1;
            else if (ptr == bottom && bottom == all_num) {  //指针在滑动窗口底部，且滑动窗口下边界在歌曲列表底部的位置
                top = 1;
                bottom = top + 3 >= all_num ? all_num : 4;
                ptr = top;
            } else {    //指针在滑动窗口底部，且滑动窗口在歌曲列表中间
                bottom += 1;
                top += 1;
                ptr = bottom;
            }
        }
    }

    for (int i = top; i <= bottom; ++i) //遍历滑动窗口
        cout << i << " ";
    cout << "\n" << ptr;    //输出指针当前的位置


    return 0;
}