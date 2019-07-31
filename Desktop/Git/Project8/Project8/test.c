#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>

bool isMirror(struct TreeNode* p, struct  TreeNode* q)
{
	if (p == NULL&&q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->val == q->val&&isMirror(p->left, q->right) && isMirror(p->left, q->right);
}

bool isSymmetric(struct TreeNode* root)
{
	ir()
	return isMirror(root->left, root->right);
}
