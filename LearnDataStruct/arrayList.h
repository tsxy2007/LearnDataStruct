#pragma once
#include "linearList.h"
#include <sstream>
#include "illegalParameterValue.h"

template<typename T>
class arrayList : public linearList<T>
{
public:
	// 构造函数,复制构造函数和析构函数
	arrayList(int initialCcapacity = 10);
	arrayList(const arrayList<T>& other);
	~arrayList()
	{
		delete[]element;
	}

	//ADT方法
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }

	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out) const;
	//
	int capacity()const { return arrayLength; }
protected:
	// 若索引无效则抛出异常
	void checkIndex(int theIndex) const;

	//开辟空间为原来的两倍
	void changeLengh1D( T* SrcElement, int OldSize, int NewSize);

	T* element;// 存储线性表元素的一维数组
	int arrayLength; // 一维数组的容量
	int listSize;//线性表的元素个数
};

template<typename T>
inline arrayList<T>::arrayList(int initialCcapacity)
{
	if (initialCcapacity < 1)
	{
		std::ostringstream s;
		s << "Initial capacity = " << initialCcapacity << " Must be > 0! ";
		throw illegalParameterValue(s.str());
	}

	arrayLength = initialCcapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<typename T>
inline arrayList<T>::arrayList(const arrayList<T>& other)
{
	arrayLength = other.arrayLength;
	listSize = other.listSize;
	element = new T[arrayLength];
	std::copy(other.element, other.element + listSize, element);
}

template<typename T>
inline T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<typename T>
inline int arrayList<T>::indexOf(const T& theElement) const
{
	// 查找元素theElement
	int theIndex = (int)(std::find(element, element + listSize, theElement) - element);
	//确定元素theElement是否找到
	if (theIndex == listSize)
		return -1;
	return theIndex;
}

template<typename T>
inline void arrayList<T>::erase(int theIndex)
{
	// 先检查theindex是否存在
	checkIndex(theIndex);
	// 有效索引，移动其索引大于theIndex的元素
	std::copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
}

template<typename T>
inline void arrayList<T>::insert(int theIndex, const T& theElement)
{
	// 在索引theIndex处插入元素theElement
	if (theIndex <0 || theIndex > listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalParameterValue(s.str());
	}

	// 有效索引，确定数组是否已满
	if (listSize == arrayLength)
	{
		// 数组空间已满，数组长度倍增
		changeLengh1D(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}

	// 把元素向右移动一位
	std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;
	listSize++;
}

template<typename T>
inline void arrayList<T>::output(std::ostream& out) const
{
	for (size_t i = 0; i < listSize; i++)
	{
		if (i==(listSize-1))
		{
			out << element[i];
		}
		else
		{
			out << element[i] << std::endl;
		}
	}
}

template<typename T>
inline void arrayList<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalParameterValue(s.str());
	}
}

template<typename T>
inline void arrayList<T>::changeLengh1D(T* SrcElement, int OldSize, int NewSize)
{
	

	if (NewSize < OldSize)
	{
		std::ostringstream s;
		s << "NewSize = " << NewSize << " smaller than oldSize " << OldSize;
		throw illegalParameterValue(s.str());
	}

	int number = std::max(OldSize, NewSize); 
	T* newElement = new T[number];
	std::copy(SrcElement, SrcElement + OldSize, newElement);

	delete[] element;

	element = newElement;
}
