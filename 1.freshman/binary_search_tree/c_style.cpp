//
//  main.cpp
//  binary_search_tree
//
//  Created by js on 2019/5/5.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// 二叉树定义
struct TreeNode {
    // 成员
    int data;           //  数据
    TreeNode* left;     //  左子树
    TreeNode* right;    //  右子树
    
    //  构造函数，左子树右子树默认为空
    TreeNode (int data, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->data  = data;
        this->left  = left;
        this->right = right;
    }
    
    //  是否为叶子节点
    bool isLeaf() {
        return (this->left==nullptr) && (this->right==nullptr);
    }
    
};


//  返回树中节点的个数
//  TreeNode* node: 二叉树指针
int size(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + size(node->left) + size(node->right);
    }
}


//  返回树中最小的值
//  TreeNode* node: 二叉树指针
int getMin(TreeNode* node) {
    if (node->left == nullptr) {
        return node->data;
    } else {
        return getMin(node->left);
    }
}

//  返回树中的最大的值
int getMax(TreeNode* node) {
    if (node->right == nullptr) {
        return node->data;
    } else {
        return getMax(node->right);
    }
}

//  pre-order traversal
//  先序遍历
//  TreeNode* node: 二叉树指针
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
//  TreeNode* node: 二叉树指针
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
//  TreeNode* node: 二叉树指针
void postOrder (TreeNode* node)
{
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}


//  二叉树node中是否包含value节点
//  TreeNode* node: 二叉树指针
//  int value     : 待查找的值
bool contains (TreeNode* node, int value)
{
    //  如果节点不为空
    if (node != nullptr) {
        if (node->data == value) {//  节点的data和目标value相等， 返回true
            return true;
        } else if (node->data < value){ //  二分查找
            return contains(node->right, value);
        } else {                        //  二分查找
            return contains(node->left, value);
        }
    } else {
        //  如果节点是空的直接返回为false
        return false;
    }
}

//  向树中添加节点
//  TreeNode*& node: 指针的引用
//  int value      : 待加入的值
void add (TreeNode*& node, int value)
{
    if (node == nullptr) {              //  树为空，new一个节点，指向它
        node = new TreeNode(value);
    } else if (node->data < value) {    //  二分，递归，交给下一步
        add(node->right, value);
    } else if (node->data > value) {    //  二分，递归，交给下一步
        add(node->left, value);
    }
}


//  从树中删除节点
//  TreeNode*& node: 指针的引用
//  int value      : 待删除的值
//  待删除的节点共有四种情况
//  1. 是叶子节点
//  2. 只有左子树
//  3. 只有右子树
//  4. 既有左子树也有右子树
//  case3和4为同一种情况

void remove (TreeNode*& node, int value)
{
    if (node->data > value) {
        remove(node->left, value);
    } else if (node->data < value){
        remove(node->right, value);
    } else {
        if (node->isLeaf()) {   //  case 1, 是叶子节点
            delete node;        //  don't know why
            node = nullptr;
        } else if (node->right == nullptr) {
            //  case 2, 只有左子树
            TreeNode* trash = node;
            node = node->left;
            delete trash;
        } else if (node->left == nullptr) {
            //  case 3, 只有右子树
            TreeNode* trash = node;
            node = node->right;
            delete trash;
        } else {
            //  case 4, full tree
            int min_right = getMin(node->right);
            node->data = min_right;
            remove(node->right, min_right);
        }
    }
}

int main(int argc, const char * argv[]) {
    TreeNode* root = nullptr;
    add(root, 17);
    add(root, 41);
    add(root, 9);
    add(root, 29);
    add(root, 6);
    add(root, 81);
    add(root, 40);
    
    cout << "先序遍历: ";
    preOrder(root);
    cout << endl << endl;
//    cout << "中序遍历" << endl;
//    inOrder(root);
//    cout << endl << endl;
//    cout << "后序遍历" << endl;
//    postOrder(root);
//    cout << endl << endl;
    
    
//    cout << contains(root, 100) << endl;
//    cout << contains(root, 17) << endl;
//    cout << contains(root, 41) << endl;
//    cout << contains(root, 40) << endl;
    
    cout << "Size: " << size(root) << endl;
    remove(root, 17);
    
    cout << contains(root, 17) << endl;
    cout << "先序遍历: ";
    preOrder(root);
    cout << endl;
    cout << "Size: " << size(root) << endl;
    
    
    return 0;
    
}
