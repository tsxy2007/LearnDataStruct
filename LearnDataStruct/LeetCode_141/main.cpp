#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你一个链表的头节点 head ，判断链表中是否有环。
*	如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
*	为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
*	注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
*	如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 方法一: 使用快慢指针 时间效率O(n) 空间复杂度O(1)
bool hasCycle(ListNode* head)
{
	if (head == nullptr)
	{
		return false;
	}
	ListNode* slowPtr = head;
	ListNode* fastPtr = head;

	while (slowPtr->next && fastPtr->next && fastPtr->next->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
		{
			return true;
		}
	}
	return false;
}

// HashMap 记录路过节点时间效率O(n) 空间复杂度O(n)
bool hasCycle_01(ListNode* head)
{
	if (head == nullptr)
	{
		return false;
	}
	std::unordered_map<ListNode*, int> Keys;
	while (head)
	{
		if (Keys.contains(head))
		{
			return true;
		}
		Keys.insert({ head,head->val });
		head = head->next;
	}
	return false;
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
		std::cout << "--------------使用正常方法--------------------" << std::endl;
		ListNode* list4 = new ListNode(5, nullptr);
		ListNode* list3 = new ListNode(4, list4);
		ListNode* list2 = new ListNode(3, list3);
		ListNode* list1 = new ListNode(1, list2);



		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		list4_->next = list2_;

		std::cout << hasCycle(list1_) << std::endl;
		std::cout << hasCycle(list1) << std::endl;
	}

	std::cout << "--------------使用递归------------------------" << std::endl;
	{
		ListNode* list4 = new ListNode(5, nullptr);
		ListNode* list3 = new ListNode(4, list4);
		ListNode* list2 = new ListNode(3, list3);
		ListNode* list1 = new ListNode(1, list2);



		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		list4_->next = list2_;

		std::cout << hasCycle_01(list1_) << std::endl;
		std::cout << hasCycle_01(list1) << std::endl;
	}
	

	return 0;
}