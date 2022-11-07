#pragma once
#include "uitily.h"
namespace MySTL
{
	template<typename T,size_t Size>
	class _Array_const_iterator
	{
	public:
		using iterator_category = random_access_iterator_tag;
		using value_type = T;
		using difference_type = ptrdiff_t;
		using pointer = const T*;
		using reference = cosnt T&;

		_Array_const_iterator(): _Ptr(),_idx(0){}
		_Array_const_iterator(pointer _Position,size_t off = 0) : _Ptr(_Position),_idx(off){}

		pointer operator->()const
		{
			checkIndex(_idx);
			return _Ptr + _idx;
		}

		reference operator*() const
		{
			return *operator->();
		}

		_Array_const_iterator& operator++
		{
			++_idx;
			return *this;
		}

		_Array_const_iterator operator++(int)
		{
			_Array_const_iterator tmp = *this;
			++* this;
			return tmp;
		}

		_Array_const_iterator& operator-()
		{
			--_idx;
			return *this;
		}

		_Array_const_iterator operator--(int)
		{
			_Array_const_iterator tmp = *this;
			--* this;
			return tmp;
		}

		_Array_const_iterator& operator+=(const ptrdiff_t off)
		{
			_idx += static_cast<size_t>(off);
			return *this;
		}

		_Array_const_iterator& operator-(const ptrdiff_t off)
		{
			return *this += off;
		}

		reference operator[](const ptrdiff_t off) const
		{
			return *(*this + 0off);
		}

		bool operator==(const _Array_const_iterator& Right) const
		{
			return _idx == Right._idx;
		}

		using _Prevent_inheriting_unwrap = _Array_const_iterator;

		constexpr pointer _Unwrapped() const
		{
			return _Ptr + _idx;
		}

		constexpr void _Verify_with(const _Array_const_iterator& Last) const
		{

		}

		constexpr void _Seek_to(pointer It)
		{
			_idx = static_cast<size_t>(It - _Ptr);
		}

		_Array_const_iterator operator+(const ptrdiff_t Off)
		{
			_Array_const_iterator tmp = *this;
			tmp += Off;
			return tmp;
		}

		_Array_const_iterator operator-(const ptrdiff_t Off)
		{
			_Array_const_iterator tmp = *this;
			tmp -= Off;
			return tmp;
		}
	private:
		constexpr void checkIndex(int theIndex) const
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

	template <class _Ty, size_t _Size>
	class _Array_iterator : public _Array_const_iterator<_Ty, _Size>
	{
		using _Mybase = _Array_const_iterator<_Ty, _Size>;

		using iterator_category = random_access_iterator_tag;
		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = _Ty*;
		using reference = _Ty&;
		
		_Array_iterator(){}

		explicit _Array_iterator(pointer _Parg,size_t _off = 0 ):_Mybase(_Parg,_off){}

		reference operator*() const
		{
			return const_cast<reference>(_Mybase::operator*());
		}

		pointer operator->() const
		{
			return const_cast<pointer>(_Mybase::operator->());
		}

		_Array_iterator& operator++() 
		{
			_Mybase::operator++();
			return *this;
		}

		_Array_iterator operator++(int)
		{
			_Array_iterator _Tmp = *this;
			_Mybase::operator++();
			return _Tmp;
		}

		_Array_iterator& operator--()
		{
			_Mybase::operator--();
			return *this;
		}

		_Array_iterator operator--(int)  
		{
			_Array_iterator _Tmp = *this;
			_Mybase::operator--();
			return _Tmp;
		}

		 _Array_iterator& operator+=(const ptrdiff_t _Off)  
		 {
			_Mybase::operator+=(_Off);
			return *this;
		}

		  _Array_iterator operator+(const ptrdiff_t _Off) const  
		  {
			_Array_iterator _Tmp = *this;
			_Tmp += _Off;
			return _Tmp;
		}

		 _Array_iterator& operator-=(const ptrdiff_t _Off)  
		 {
			_Mybase::operator-=(_Off);
			return *this;
		}

		using _Mybase::operator-;

		_Array_iterator operator-(const ptrdiff_t _Off) const
		{
			_Array_iterator _Tmp = *this;
			_Tmp -= _Off;
			return _Tmp;
		}

		reference operator[](const ptrdiff_t _Off) const
		{
			return const_cast<reference>(_Mybase::operator[](_Off));
		}

		using _Prevent_inheriting_unwrap = _Array_iterator;

		constexpr pointer _Unwrapped() const
		{
			return const_cast<pointer>(_Mybase::_Unwrapped());
		}
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

		using iterator = _Array_iterator<_Ty, _Size>;
		using const_iterator = _Array_const_iterator<_Ty, _Size>;
		
		iterator begin()
		{
			return iterator{};
		}
	private:
		T Elem[Size];
	};
}