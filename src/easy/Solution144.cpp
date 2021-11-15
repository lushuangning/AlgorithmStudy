#include <vector>
#include <iostream>
#include "Vector2Other.h"
#include "LeetcodePrint.h"

using namespace std;

vector<int> leaf = {};

// 递归实现
vector<int> preorderTraversal(TreeNode* root)
{	
	if (root)
	{
		//leaf.insert(leaf.end(), root->val);
		leaf.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}

	return leaf;
}

// 非递归，栈实现


// Morris方法实现
vector<int> morrisPre(TreeNode* root) {
	TreeNode *curr, *most_right;
	vector<int> morris = {};
	curr = root;
	while (curr)
	{
		morris.push_back(curr->val);
		if (curr->left)
		{
			most_right = curr->left;
			while (most_right->right && most_right->right != curr)
			{
				most_right = most_right->right;
			}
			if (!most_right->right)
			{
				most_right->right = curr;
				curr = curr->left;
			}
			else
			{
				morris.pop_back();
				most_right->right = nullptr;
				curr = curr->right;
			}
		}
		else
		{
			curr = curr->right;
		}
	}
	return morris;
}

int main()
{
	//vector<int> vec = {1, 2, 3, 4, 5, 6, 7, -1, -1};
	//vector<int> tree;
	//TreeNode* root = buildBinTree(vec);
	//tree = preorderTraversal(root);
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
	tree = morrisPre(node1);
	show1DVector(tree);

	return 0;
}