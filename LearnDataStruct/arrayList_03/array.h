#pragma once
#include "uitily.h"
namespace MySTL
{
	template<typename T,size_t Size>
	class Array_const_iterator
	{
	public:
		using iterator_category = random_access_iterator_tag;
		using value_type = T;
		using difference_type = ptrdiff_t;
		using pointer = const T*;
		using reference = cosnt T&;

		Array_const_iterator(): _Ptr(),_idx(0){}
		Array_const_iterator(pointer _Position,size_t off = 0) : _Ptr(_Position),_idx(off){}

		pointer operator->()const
		{
			checkIndex(_idx);
			return _Ptr + _idx;
		}

		reference operator*() const
		{
			return *operator->();
		}

		Array_const_iterator& operator++
		{
			++_idx;
			return *this;
		}

		Array_const_iterator operator++(int)
		{
			Array_const_iterator tmp = *this;
			++* this;
			return tmp;
		}

		Array_const_iterator& operator-()
		{
			--_idx;
			return *this;
		}

		Array_const_iterator operator--(int)
		{
			Array_const_iterator tmp = *this;
			--* this;
			return tmp;
		}

		Array_const_iterator& operator+=(const ptrdiff_t off)
		{
			_idx += static_cast<size_t>(off);
			return *this;
		}

		Array_const_iterator& operator-(const ptrdiff_t off)
		{
			return *this += off;
		}
	private:
		void checkIndex(int theIndex) const
		{
			if (_Ptr == nullptr)
			{
				std::ostringstream s;
				s << "_Ptr is null" << listSize;
				throw illegalParameterValue(s.str());
			}
			if (theIndex < 0 || theIndex >= Size)
			{
				std::ostringstream s;
				s << "index = " << theIndex << " size = " << listSize;
				throw illegalParameterValue(s.str());
			}
		}
	private:
		pointer _Ptr;
		size_t _idx;
	};
	template<typename T, size_t Size>
	class array
	{
	public:
		using value_type = T;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
	private:
		T Elem[Size];
	};
}