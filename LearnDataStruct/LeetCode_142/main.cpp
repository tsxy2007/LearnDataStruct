#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
*	如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给
*	定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
*	如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的
*	实际情况。不允许修改 链表。
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
ListNode* detectCycle(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}
	ListNode* slowPtr = head;
	ListNode* fastPtr = head;
	ListNode* Result = nullptr;
	bool bCycle = true;
	while (true)
	{
		if (fastPtr == nullptr || fastPtr->next == nullptr)
		{
			bCycle = false;
			break;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if (slowPtr == fastPtr)
		{
			bCycle = true;
			break;
		}
	}

	if (bCycle)
	{
		ListNode* ptr = head;
		while (ptr != slowPtr)
		{
			ptr = ptr->next;
			slowPtr = slowPtr->next;
		}
		return ptr;
	}
	return nullptr;
}

// HashMap 记录路过节点时间效率O(n) 空间复杂度O(n)
ListNode* detectCycle_01(ListNode* head)
{
	if (head == nullptr)
	{
		return nullptr;
	}
	std::unordered_map<ListNode*, int> Keys;
	while (head)
	{
		if (Keys.contains(head))
		{
			return head;
		}
		Keys.insert({ head,head->val });
		head = head->next;
	}
	return nullptr;
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

		ListNode* l0 = detectCycle(list1);
		ListNode* l1 = detectCycle(list1_);

		std::cout << (l0 ? l0->val : -1) << std::endl;
		std::cout << (l1 ? l1->val : -1) << std::endl;
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

		ListNode* l0 = detectCycle(list1);
		ListNode* l1 = detectCycle(list1_);

		std::cout << (l0 ? l0->val : -1) << std::endl;
		std::cout << (l1 ? l1->val : -1) << std::endl;
	}
	

	return 0;
}