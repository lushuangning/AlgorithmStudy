// 二叉树的中序遍历

#include <vector>
#include <iostream>
#include "Vector2Other.h"
#include "LeetcodePrint.h"

using namespace std;

void inorder(TreeNode* node, vector<int>& vec);

// 递归方法
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> order = {};
    inorder(root, order);
    
    return order;
}

void inorder(TreeNode* node, vector<int>& vec)
{
    if (node)
    {
        inorder(node->left, vec);
        vec.push_back(node->val);
        inorder(node->right, vec);
    }
}


// Morris 方法实现中序遍历
vector<int> morrisIn(TreeNode* root) 
{
    TreeNode* curr, * most_right;
    vector<int> order;
    curr = root;
    while (curr)
    {
        if (curr->left)
        {
            most_right = curr->left;
            while (most_right->right && most_right->right != curr)
                most_right = most_right->right;
            if (!most_right->right)
            {
                most_right->right = curr;
                curr = curr->left;
            }
            else
            {
                most_right->right = nullptr;
                order.push_back(curr->val);
                curr = curr->right;
            }
        }
        else
        {
            order.push_back(curr->val);
            curr = curr->right;
        }
    }

    return order;
}

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node1->left = node2;
    node1->right = node3;

    vector<int> tree;
    tree = morrisIn(node1);
    show1DVector(tree);

	return 0;
}