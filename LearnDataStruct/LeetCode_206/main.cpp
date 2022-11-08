#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
	ListNode* pre = nullptr;
	ListNode* cur = head;

	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
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


		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		print(reverseList(list1_));
	}

	
	return 0;
}