//
//  main.cpp
//  binary_tree
//
//  Created by js on 2019/5/4.
//  Copyright © 2019 js. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

// 二叉树定义
struct TreeNode {
    // 成员
    int data;           //  数据
    TreeNode* left;     //  左子树
    TreeNode* right;    //  右子树
    
    //  构造函数，左子树右子树默认为空
    TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->data  = data;
        this->left  = left;
        this->right = right;
    }
    
//    TreeNode(int data) {
//        this->data = data;
//        this->left = this->right = nullptr;
//    }
};


//  pre-order traversal
//  先序遍历
void preOrder (TreeNode* node)
{
    if (node != nullptr) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

//  in-order traversal
//  中序遍历
void inOrder (TreeNode* node)
{
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}


//  pre-order traversal
//  后序遍历
void postOrder (TreeNode* node)
{
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}


//  BFS
//  层先遍历
void levelOrder (TreeNode* node)
{
    queue<TreeNode*> my_queue;          //  implement by queue structure
    my_queue.push(node);
    while (!my_queue.empty()) {         //  if my_queue is not empty
        TreeNode* front = my_queue.front();     //  get the front pointer
        cout << front->data << " ";             //  print
        my_queue.pop();                         //  deQueue
        
        if (front->left != nullptr) {         //  if left is not NULL, enQueue
            my_queue.push(front->left);
        }
        if (front->right != nullptr) {        //  if right is not NULL, enQueue
            my_queue.push(front->right);
        }
    }
    cout << endl;
}



//  二叉树node中是否包含value节点
bool contains(TreeNode* node, int value)
{
    //  如果节点不为空
    if (node != nullptr) {
        if (node->data == value) {//  节点的data和目标value相等， 返回true
            return true;
        } else {                  //  不想等，搜索左子树和右子树
            return contains(node->left, value) || contains(node->right, value);
        }
    } else {
        //  如果节点是空的直接返回为false
        return false;
    }
}



int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(17);
    root->left     = new TreeNode(41);
    root->right    = new TreeNode(9);
    root->left->left = new TreeNode(29);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(81);
    root->right->right = new TreeNode(40);
    
    cout << "先序遍历" << endl;
    preOrder(root);
    cout << endl << endl;
    cout << "中序遍历" << endl;
    inOrder(root);
    cout << endl << endl;
    cout << "后序遍历" << endl;
    postOrder(root);
    cout << endl << endl;
    
    cout << "BFS" << endl;
    levelOrder(root);
    
    cout << contains(root, 100) << endl;
    cout << contains(root, 17) << endl;
    cout << contains(root, 41) << endl;
    cout << contains(root, 40) << endl;
    return 0;
}
