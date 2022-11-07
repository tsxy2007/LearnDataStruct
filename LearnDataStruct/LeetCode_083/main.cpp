#include <iostream>
#include <vector>
#include <algorithm>
/*
*	给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
*/ 


struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//方法一: 直接循环
ListNode* deleteDuplicates(ListNode* head) 
{
	ListNode* tmp = head;

	while (tmp && tmp->next)
	{
		if (tmp->val == tmp->next->val)
		{
			tmp->next = tmp->next->next;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return head;
}

// 方法二: 递归
ListNode* deleteDuplicates_01(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	head->next = deleteDuplicates_01(head->next);
	return head->val == head->next->val ? head->next : head;
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
		ListNode* list4_04 = new ListNode(5, nullptr);
		ListNode* list4_03 = new ListNode(5, list4_04);
		ListNode* list4_02 = new ListNode(5, list4_03);
		ListNode* list4_01 = new ListNode(5, list4_02);
		ListNode* list3_03 = new ListNode(4, list4_01);
		ListNode* list3_02 = new ListNode(4, list3_03);
		ListNode* list3_01 = new ListNode(4, list3_02);
		ListNode* list2_01 = new ListNode(3, list3_01);
		ListNode* list1_02 = new ListNode(1, list2_01);
		ListNode* list1_01 = new ListNode(1, list1_02);

		print(deleteDuplicates(list1_01));
	}

	{
		ListNode* list4_04 = new ListNode(5, nullptr);
		ListNode* list4_03 = new ListNode(5, list4_04);
		ListNode* list4_02 = new ListNode(5, list4_03);
		ListNode* list4_01 = new ListNode(5, list4_02);
		ListNode* list3_03 = new ListNode(4, list4_01);
		ListNode* list3_02 = new ListNode(4, list3_03);
		ListNode* list3_01 = new ListNode(4, list3_02);
		ListNode* list2_01 = new ListNode(3, list3_01);
		ListNode* list1_02 = new ListNode(1, list2_01);
		ListNode* list1_01 = new ListNode(1, list1_02);

		print(deleteDuplicates_01(list1_01));
	}

	return 0;
}