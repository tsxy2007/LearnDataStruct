#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你一个单链表的头节点 head,足够长，请找出倒数第k个节点
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* reserveList(ListNode* head)
{
	ListNode* preNode = nullptr;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = preNode;
		preNode = cur;
		cur = next;
	}
	return preNode;
}

// 方法一: 使用hashmap记录索引
ListNode* kthNodeFromEnd(ListNode* head,int k)
{
	std::unordered_map<int, ListNode*> tmp;
	int index = 0;
	while (head)
	{
		tmp.insert({ index++ ,head });
		head = head->next;
	}
	int tIndex = index - k - 1;

	return tmp[tIndex];
}

//方法二:反转链表
ListNode* kthNodeFromEnd_01(ListNode* head, int k)
{
	ListNode* rhead = reserveList(head);
	int index = 0;
	ListNode* result = nullptr;
	while (index < k)
	{
		result = rhead;
		index++;
		rhead = rhead->next;
	}
	return result;
}

//使用双指针，某一指针提前移动k位
ListNode* kthNodeFromEnd_02(ListNode* head, int k)
{
	if (k<=0)
	{
		return nullptr;
	}
	ListNode* s = head;
	ListNode* f = head;
	int index = 0;
	while (f->next)
	{
		f = f->next;
		if (index < (k - 1))
		{
			index++;
		}
		else
		{
			s = s->next;
		}
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
		ListNode* list5_ = new ListNode(1, nullptr);
		ListNode* list4_ = new ListNode(2, list5_);
		ListNode* list3_ = new ListNode(2, list4_);
		ListNode* list2_ = new ListNode(2, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		ListNode* tListNode = kthNodeFromEnd(list1_, 2);
		std::cout << (tListNode ? tListNode->val : -1) << std::endl;
	}

	{
		ListNode* list5_ = new ListNode(1, nullptr);
		ListNode* list4_ = new ListNode(2, list5_);
		ListNode* list3_ = new ListNode(2, list4_);
		ListNode* list2_ = new ListNode(2, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		ListNode* tListNode = kthNodeFromEnd_01(list1_, 2);
		std::cout << (tListNode ? tListNode->val : -1) << std::endl;
	}

	{
		ListNode* list5_ = new ListNode(5, nullptr);
		ListNode* list4_ = new ListNode(4, list5_);
		ListNode* list3_ = new ListNode(3, list4_);
		ListNode* list2_ = new ListNode(2, list3_);
		ListNode* list1_ = new ListNode(1, list2_);

		ListNode* tListNode = kthNodeFromEnd_02(list1_, 1);
		std::cout << (tListNode ? tListNode->val : -1) << std::endl;
	}

	
	return 0;
}