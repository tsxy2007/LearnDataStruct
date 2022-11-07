#include <iostream>
#include <vector>
#include <algorithm>
/*
*	给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
*	请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
	ListNode* New = new ListNode(-1);
	ListNode* tmp = New;
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			tmp->next = list1;
			list1 = list1->next;
		}
		else
		{
			tmp->next = list2;
			list2 = list2->next;
		}
		tmp = tmp->next;
	}

	tmp->next = list1 ? list1 : list2;
	return New->next;
}

// 方法二： 使用递归
ListNode* mergeTwoLists_02(ListNode* list1, ListNode* list2)
{
	ListNode* New = new ListNode(-1);
	if (list1==nullptr)
	{
		return list2;
	}
	else if (list2 == nullptr)
	{
		return list1;
	}
	else if (list1->val < list2->val)
	{
		list1->next = mergeTwoLists_02(list1->next, list2);
		return list1;
	}
	else
	{
		list2->next = mergeTwoLists_02(list1, list2->next);
		return list2;
	}
	return New->next;
}

void print(ListNode* list1)
{
	ListNode* Tail = list1;
	while (Tail)
	{
		std::cout << Tail->val << ' ';
		Tail = Tail->next;
	}
	std::cout << std::endl;
}

int main()
{

	{
		ListNode* list3 = new ListNode(4, nullptr);
		ListNode* list2 = new ListNode(2, list3);
		ListNode* list1 = new ListNode(1, list2);

		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		print(mergeTwoLists(list1, list1_));
	}

	{
		ListNode* list3 = new ListNode(4, nullptr);
		ListNode* list2 = new ListNode(2, list3);
		ListNode* list1 = new ListNode(1, list2);

		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		print(mergeTwoLists_02(list1, list1_));
	}
	

	return 0;
}