#pragma once
#include <ostream>

template<typename T>
class linearList
{
public:
	virtual ~linearList() {};
	// 返回true，当且仅当线性表为空
	virtual bool empty() const = 0;
	//返回线性表元素的个数
	virtual int size() const = 0;
	//返回索引为theIndex的元素
	virtual T& get(int theIndex) const = 0;
	//返回元素theElements的索引
	virtual int indexOf(const T& theElements) const = 0;
	//删除索引为theIndex的元素
	virtual void erase(int theIndex) = 0;
	// 把theElement插入线性表中索引为theIndex的位置上
	virtual void insert(int theInex, const T& theElement) = 0;
	//把线性表插入输出流out
	virtual void output(std::ostream& out) const = 0;
};
