#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给定一个头结点为 head 的非空单链表，返回链表的中间结点。
*	如果有两个中间结点，则返回第二个中间结点。
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
	ListNode* s = head;
	ListNode* f = head;
	while (f && f->next)
	{
		s = s->next;
		f = f->next->next;
	}
	return s;
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


		ListNode* list6_ = new ListNode(1, nullptr);
		ListNode* list5_ = new ListNode(1, list6_);
		ListNode* list4_ = new ListNode(4, list5_);
		ListNode* list3_ = new ListNode(3, list4_);
		ListNode* list2_ = new ListNode(2, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		ListNode* mid = middleNode(list1_);
		std::cout << (mid ? mid->val : -1) << std::endl;
	}

	
	return 0;
}