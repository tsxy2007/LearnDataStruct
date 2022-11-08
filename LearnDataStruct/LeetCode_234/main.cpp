#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
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

bool isPalindrome(ListNode* head)
{
	if (head == nullptr)
	{
		return false;
	}

	ListNode* f = head;
	ListNode* s = head;
	while (f && f->next)
	{
		s = s->next;
		f = f->next->next;
	}
	// 奇数往后移一位
	if (f != nullptr)
	{
		s = s->next;
	}

	ListNode* reversHalf = reverseList(s);

	f = head;

	while (reversHalf)
	{
		if (reversHalf->val != f->val)
		{
			return false;
		}
		f = f->next;
		reversHalf = reversHalf->next;
	}
	return true;
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


		ListNode* list5_ = new ListNode(1, nullptr);
		ListNode* list4_ = new ListNode(2, list5_);
		ListNode* list3_ = new ListNode(2, list4_);
		ListNode* list2_ = new ListNode(2, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		std::cout<< isPalindrome(list1_)<<std::endl;
	}

	
	return 0;
}