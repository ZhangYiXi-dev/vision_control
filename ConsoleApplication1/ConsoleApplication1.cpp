// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <deque>
#include <sstream>
#include<set>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}

};
class Solution //建树
{
public:
    void create_tree(TreeNode* &node)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            node = NULL;
        }
        else
        {
            node = new TreeNode(a);
            create_tree(node->left);
            create_tree(node->right);
        }
        
    }
    void create2(TreeNode*& node,int &i)
    {
        vector<int> v = { 1,2,4,0,0,5,0,0,3,0,0};
        int v_size = v.size();
        if (v[i] == 0)
        {
            i++;
            return;
        }
        else
        {
            node = new TreeNode(v[i]);
            i++;
            create2(node->left,i);
            create2(node->right,i);
        }
    }
   
    void pre_order(TreeNode* node)
    {
        if(node == NULL)
        {
            return;
        }
        cout << node->val << ' ' ;
        pre_order(node->left);
        pre_order(node->right);
    }
    void in_order(TreeNode* node)
    {
        if (node == NULL) 
        {
            return;
        }
        in_order(node->left);
        cout << node->val << ' ' ;
        in_order(node->right);
    }
    void po_order(TreeNode* node)
    {
        if (node == NULL)
        {
            return;
        }
        po_order(node->left);
        po_order(node->right);
        cout << node->val << ' ';
    }
    
};
struct LRU_Node 
{
    int key;
    int val;
    LRU_Node* last;
    LRU_Node* next;
};
class LRU 
{
public:
    int capacity;
    map<int, LRU_Node*> ma;
    LRU_Node* head = new LRU_Node;
    LRU_Node* tail = new LRU_Node;
    LRU(int capacity)
    {
        head->next = tail;
        tail->last = head;
        this->capacity = capacity;
    }
    int get(int key)
    {
        if (ma.count(key) == 0)
        {
            return -1;
        }
        else
        {
            ma[key]->last->next = ma[key]->next;
            ma[key]->next->last = ma[key]->last;
            ma[key]->next = head->next;
            ma[key]->last = head;
            head->next = ma[key];
            ma[key]->next->last = ma[key];
            return ma[key]->val;
        }
    }
    void put(int key, int val)
    {
        if (ma.size() < capacity)
        {
            LRU_Node* node = new LRU_Node;
            node->key = key;
            node->val = val;
            node->next = head->next;
            node->last = head;
            node->next->last = node;
            ma[key] = node;
        }
        else
        {
            LRU_Node* node = new LRU_Node;
            node->key = key;
            node->val = val;
            node->next = head->next;
            node->last = head;
            node->next->last = node;
            ma[key] = node;
            auto it = ma.find(tail->last->key);
            ma.erase(it);
            tail->last->last->next = tail;
            tail->last = tail->last->last;
            
        }
    }
    
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string str_tree = "";
    deque<string> v_str;
    TreeNode* head = NULL;
    void apart_str()
    {
        stringstream ss(str_tree);
        string s;
        while (getline(ss, s, ' '))
        {
            v_str.push_back(s);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        pre_order(root);
        return str_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        apart_str();
        return build_tree();
    }
    TreeNode* build_tree()
    {
        if (v_str.empty())
        {
            return NULL;
        }
        string s_node = v_str.front();
        v_str.pop_front();
        TreeNode* node;
        if (s_node == "null")
        {
            node = NULL;
            return NULL;
        }
        else
        {
            node = new TreeNode(atoi(s_node.c_str()));
            node->left = build_tree();
            node->right = build_tree();
        }
        return node;
    }
    void pre_order(TreeNode* root)
    {
        if (root == NULL)
        {
            str_tree = str_tree + "null" + " ";
            return;
        }
        str_tree = str_tree + to_string(root->val) + " ";
        pre_order(root->left);
        pre_order(root->right);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main(){
    int a = 2;
    int b = 3;
    auto f = [a, &b]()mutable->int {cout << a << " " << b << endl; return a + b; };
    a++;
    b++;
    //f(); //2 4
    a++;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
