/*////////////////////////////////////////////////////////////
1.两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
///////////////////////////////////////////////////////////*/
/*


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i, j;
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if ((nums[i] + nums[j]) == target){
					return{ i, j };
				}
			}

		}
		return{ i, j };
	}
};

*/



/*///////////////////////////////////////////////////////////////////
2.两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//////////////////////////////////////////////////////////////////*/


/*
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *pre = new ListNode(0);
		ListNode *cur = pre;
		int carry = 0;
		while (l1 != NULL || l2 != NULL)
		{
			int x = 0;
			int y = 0;
			if (l1 != NULL)
			{
				x = l1->val;
				l1 = l1->next;
			}

			if (l2 != NULL)
			{
				y = l2->val;
				l2 = l2->next;
			}
			int temp;
			temp = carry + x + y;
			carry = temp / 10;
			temp %= 10;
			if (cur != NULL){
				cur->val = temp;
			}
			if (l1 != NULL || l2 != NULL){
				cur->next = new ListNode(0);
				cur = cur->next;
				cur->next = NULL;
			}


		}
		if (carry == 1)
		{
			cur->next = new ListNode(1);
		}
		return pre;
	}
};

*/