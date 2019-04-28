#ifndef RECURSIONTRANSEITERATION_H
#define RECURSIONTRANSEITERATION_H
#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
} TreeNode;
/*
 * 递归转迭代两种方式
 * 1. 尾递归： 将递归作为最后一条语句, 自顶向下-> 自底向上
*/

class RecursionTranseIteration
{
public:
    RecursionTranseIteration();

    // 0, 1, 1, 2, 3, 5
    // 尾递归， （求解斐波那契数列)
    // 递归版本
    int fibRecursion(int n) {
        if (n <= 1) return n;
        return fibRecursion(n-1) + fibRecursion(n+1);
    }

    int fibaIteration(int n) {
        if (n <= 1) return n;
        int f0 = 0, f1 = 1;
        for (int i = 0; i < n; ++i) {
            int f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
    }

    // 非尾递归 -> 使用堆栈进行转换
    // 快排算法的迭代算法
    template<typename T>
    void fastSort(T* a, int n) {
        stack<pair<int,int>> stack_of_index;//
        stack_of_index.push(pair<int, int>(0, n - 1));

        while(!stack_of_index.empty())
        {
            pair<int, int> tmp = stack_of_index.top();
            stack_of_index.pop();//模拟函数调用，去除栈顶元素，进行处理

            if (tmp.first >= tmp.second)
            {
                int pos;
//                int pos = partion(a, tmp.first, tmp.second);
                stack_of_index.push(pair<int,int>(tmp.first, pos));
                stack_of_index.push(pair<int,int>(pos + 1, tmp.second));
            }
        }
    }

    // lizi  二叉树的遍历
    void doSomething(TreeNode *) {}

    // 递归前序
    void preoderRecursion(TreeNode *node) {
        doSomething(node);
        if (node->left != nullptr) preoderRecursion(node->left);
        if (node->right != nullptr) preoderRecursion(node->right);
    }


    //迭代的辅助函数（用于遍历左子树）
    void precorderHelp(TreeNode *node, stack<TreeNode *> *s)
    {

        while (node != nullptr) {
            doSomething(node);
            s->push(node);
            node = node->left;
        }
    }
    // 迭代 -前序
    void precorderDieDai(TreeNode *root)
    {
        stack<TreeNode *> s;

        precorderHelp(root, &s); // befor, cur
        //right
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->right != nullptr) {
                precorderHelp(node->right, &s);
            }
        }
    }
};

#endif // RECURSIONTRANSEITERATION_H
