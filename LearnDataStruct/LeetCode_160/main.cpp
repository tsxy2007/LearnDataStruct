#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你两个单链表的头节点 headA 和 headB ，
*	请你找出并返回两个单链表相交的起始节点。
*	如果两个链表不存在相交节点，返回 null 。
*	图示两个链表在节点 c1 开始相交：
*/ 

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// 方法一: 使用双指针(路线长度不一致，速度一致赛跑问题) 时间效率O(n) 空间复杂度O(1)
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if (headA == nullptr || headB == nullptr)
	{
		return nullptr;
	}
	ListNode* TailA = headA;
	ListNode* TailB = headB;
	while (TailA != TailB)
	{
		TailA = (TailA == nullptr) ? headB : TailA->next;
		TailB = (TailB == nullptr) ? headA : TailB->next;
	}

	return TailA;
}

//方法二: 暴力解法 两层循环
ListNode* getIntersectionNode_01(ListNode* headA, ListNode* headB)
{
	
	while (headA)
	{
		ListNode* tail = headB;
		while (tail)
		{
			if (headA == tail)
			{
				return headA;
			}
			tail = tail->next;
		}
		headA = headA->next;
	}
	return nullptr;
}

//方法三: HashMap
ListNode* getIntersectionNode_02(ListNode* headA, ListNode* headB)
{
	std::unordered_map<ListNode*, int> tmp;
	while (headA)
	{
		tmp.insert({ headA,headA->val });
		headA = headA->next;
	}

	while (headB)
	{
		if (tmp.contains(headB))
		{
			return headB;
		}
		headB = headB->next;
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


		ListNode* list2 = new ListNode(6, nullptr);
		ListNode* list1 = new ListNode(2, list2);

		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		list2->next = list2_;

		ListNode* IntersectionNode = getIntersectionNode(list1, list1_);
		int result = IntersectionNode ? IntersectionNode->val : -1;
		std::cout << "值是 = " << result << std::endl;
	}

	{
		std::cout << "--------------使用暴力方法--------------------" << std::endl;


		ListNode* list2 = new ListNode(6, nullptr);
		ListNode* list1 = new ListNode(2, list2);

		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		list2->next = list2_;

		ListNode* IntersectionNode = getIntersectionNode_01(list1, list1_);
		int result = IntersectionNode ? IntersectionNode->val : -1;
		std::cout << "值是 = " << result << std::endl;
	}
	
	{
		std::cout << "--------------使用HashMap方法------------------" << std::endl;


		ListNode* list2 = new ListNode(6, nullptr);
		ListNode* list1 = new ListNode(2, list2);

		ListNode* list4_ = new ListNode(5, nullptr);
		ListNode* list3_ = new ListNode(4, list4_);
		ListNode* list2_ = new ListNode(3, list3_);
		ListNode* list1_ = new ListNode(1, list2_);
		list2->next = list2_;

		ListNode* IntersectionNode = getIntersectionNode_02(list1, list1_);
		int result = IntersectionNode ? IntersectionNode->val : -1;
		std::cout << "值是 = " << result << std::endl;
	}
	return 0;
}