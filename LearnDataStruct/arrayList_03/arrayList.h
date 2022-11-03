#pragma once
#include "linearList.h"
#include <sstream>
#include "illegalParameterValue.h"
#include <iostream>

template<typename T>
class iterator
{
public:
	//typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	//���캯��
	iterator(T* thePosition = 0) { position = thePosition; }
	//�����ò�����
	T& operator*() const { return *position; }
	T* operator->()const { return &*position; }

	//��������ֵ����
	//ǰ��
	iterator& operator++()
	{
		++position;
		return *this;
	}
	//���
	iterator operator++(int)
	{
		T* Old = position;
		++position;
		return Old;
	}

	//��������ֵ����
	//ǰ��
	iterator& operator--()
	{
		--position;
		return *this;
	}
	//���
	iterator operator--(int)
	{
		T* Old = position;
		--position;
		return Old;
	}

	//�������
	bool operator!=(const iterator right) const
	{
		return position != right.position;
	}

	bool operator==(const iterator right) const
	{
		return position == right.position;
	}
protected:
	T* position;
};

template<typename T,size_t N>
class arrayList;

template<typename T,size_t N>
std::ostream& operator<<(std::ostream&, const arrayList<T,N>&);

template<typename T, size_t N>
class arrayList : public linearList<T>
{
	using iterator = iterator<T>;
public:
	// ���캯��,���ƹ��캯������������
	arrayList(int initialCcapacity = 10);
	arrayList(const arrayList<T,N>& other);
	~arrayList()
	{
		delete[]element;
	}

	//ADT����
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }

	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	//
	int capacity()const { return arrayLength; }

	// ��ָ��������ض��� T ��ȫ�ػ� 
	friend std::ostream& operator<< <T,N>(std::ostream& out, const arrayList<T,N>& InArray);

	iterator begin();
	iterator end();

	T& operator[](const int _pos) noexcept;
	const T& operator[](const int _pos) const noexcept;
protected:
	// ��������Ч���׳��쳣
	void checkIndex(int theIndex) const;

	//���ٿռ�Ϊԭ��������
	void changeLengh1D( T* SrcElement, int OldSize, int NewSize);

	//���ٿռ�Ϊԭ����һ��
	void changeLengh1D_half(T* SrcElement, int OldSize, int NewSize);

	T* element;// �洢���Ա�Ԫ�ص�һά����
	int arrayLength; // һά���������
	int listSize;//���Ա��Ԫ�ظ���
	int ExpansionCount;
};

template<typename T,size_t N>
inline arrayList<T,N>::arrayList(int initialCcapacity)
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
	ExpansionCount = N;
}

template<typename T,size_t N>
inline arrayList<T, N>::arrayList(const arrayList<T,N>& other)
{
	arrayLength = other.arrayLength;
	listSize = other.listSize;
	element = new T[arrayLength];
	ExpansionCount = other.ExpansionCount;
	std::copy(other.element, other.element + listSize, element);
}

template<typename T,size_t N>
inline T& arrayList<T, N>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}

template<typename T,size_t N>
inline int arrayList<T, N>::indexOf(const T& theElement) const
{
	// ����Ԫ��theElement
	int theIndex = (int)(std::find(element, element + listSize, theElement) - element);
	//ȷ��Ԫ��theElement�Ƿ��ҵ�
	if (theIndex == listSize)
		return -1;
	return theIndex;
}

template<typename T,size_t N>
inline void arrayList<T,N>::erase(int theIndex)
{
	// �ȼ��theindex�Ƿ����
	checkIndex(theIndex);
	// ��Ч�������ƶ�����������theIndex��Ԫ��
	std::copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();
	int half = arrayLength / 4;
	if (listSize == half)
	{
		changeLengh1D_half(element, listSize, half * 2);
		arrayLength = half * 2;
	}
}

template<typename T,size_t N>
inline void arrayList<T, N>::insert(int theIndex, const T& theElement)
{
	// ������theIndex������Ԫ��theElement
	if (theIndex <0 || theIndex > listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalParameterValue(s.str());
	}

	// ��Ч������ȷ�������Ƿ�����
	if (listSize == arrayLength)
	{
		// ����ռ����������鳤�ȱ���
		int newSize = (ExpansionCount == -1) ? 2 * arrayLength : arrayLength + ExpansionCount;
		changeLengh1D(element, arrayLength, newSize);
		arrayLength = newSize;
	}

	// ��Ԫ�������ƶ�һλ
	std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;
	listSize++;
}

template<typename T,size_t N>
std::ostream& operator<<(std::ostream& os,const arrayList<T,N>& InArray)
{
	// TODO: insert return statement here
	arrayList<T,N> tmpArray = InArray;
	for (auto iter : tmpArray)
	{
		os << iter << ' ';
	}
	std::cout << std::endl;
	return os;
}

template<typename T,size_t N>
inline arrayList<T,N>::iterator arrayList<T,N>::begin()
{
	return iterator(element);
}

template<typename T,size_t N>
inline arrayList<T,N>::iterator arrayList<T,N>::end()
{
	return iterator(element + listSize);
}

template<typename T,size_t N>
inline T& arrayList<T,N>::operator[](const int _pos) noexcept
{
	// TODO: insert return statement here
	return element[_pos];
}

template<typename T,size_t N>
inline const T& arrayList<T,N>::operator[](const int _pos) const noexcept
{
	// TODO: insert return statement here
	return element[_pos];
}

template<typename T,size_t N>
inline void arrayList<T,N>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		std::ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalParameterValue(s.str());
	}
}

template<typename T,size_t N>
inline void arrayList<T,N>::changeLengh1D(T* SrcElement, int OldSize, int NewSize)
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

template<typename T,size_t N>
inline void arrayList<T,N>::changeLengh1D_half(T* SrcElement, int OldSize, int NewSize)
{
	if (NewSize < OldSize)
	{
		std::ostringstream s;
		s << "NewSize = " << NewSize << " samller than oldSize " << OldSize;
		throw illegalParameterValue(s.str());
	}

	int number = std::max(OldSize, NewSize);
	T* newElement = new T[number];
	std::copy(SrcElement, SrcElement + OldSize, newElement);

	delete[] element;

	element = newElement;
}
