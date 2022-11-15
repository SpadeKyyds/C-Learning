/**
 * 功能描述：求两个集合的差集
 * 函数原型：set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
 * 求两个集合的差集
 *
 * 注意:两个集合必须是有序序列!!!!!!!!
 *
 * beg1 容器1开始迭代器
 * end1 容器1结束迭代器
 * beg2 容器2开始迭代器
 * end2 容器2结束迭代器
 * dest 目标容器开始迭代器
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class myPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

int main()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    //取两个里面较大的值给目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    //返回目标容器的最后一个元素的迭代器地址
    cout << "v1与v2的差集为: " << endl;
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;

    cout << "v2与v1的差集为: " << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;

    return 0;
}