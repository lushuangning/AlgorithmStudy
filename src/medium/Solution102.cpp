// ¶þ²æÊ÷µÄ²ãÐò±éÀú

#include <vector>
#include <iostream>
#include <queue>
#include "StructDefinition.h"
#include "LeetcodePrint.h"


using namespace std;

vector<vector<int>> levelOrder(TreeNode* root);

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> order;
    vector<int> level;
    TreeNode* node = root;
    if (!node) {
        return order;
    }

    q.push(node);
    q.push(NULL);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (NULL == node) {
            order.push_back(level);
            level.clear();
            if (q.empty()){
                break;
            }
            q.push(NULL);
        }
        else {
            level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return order;
}

int main()
{
	TreeNode* node1 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(9);
	TreeNode* node3 = new TreeNode(20);
	TreeNode* node4 = new TreeNode(15);
	TreeNode* node5 = new TreeNode(7);
    vector<vector<int>> leor;

	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;

    leor = levelOrder(node1);

    show2DVector(leor);

	return 0;
}