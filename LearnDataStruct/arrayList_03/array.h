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
		using reference = const T&;

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

		_Array_const_iterator& operator++()
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
			return *(*this + off);
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
				s << "_Ptr is null" << theIndex;
				throw illegalParameterValue(s.str());
			}
			if (theIndex < 0)
			{
				std::ostringstream s;
				s << "index = " << theIndex << " size = ";
				throw illegalParameterValue(s.str());
			}
		}
	private:
		pointer _Ptr;
		size_t _idx;
	};

	template <class _Ty, size_t Size>
	class _Array_iterator : public _Array_const_iterator<_Ty, Size>
	{

		using _Mybase = _Array_const_iterator<_Ty, Size>;

		using iterator_category = random_access_iterator_tag;
		using value_type = _Ty;
		using difference_type = ptrdiff_t;
		using pointer = _Ty*;
		using reference = _Ty&;
	public:
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

		using iterator = _Array_iterator<T, Size>;
		using const_iterator = _Array_const_iterator<T, Size>;
		
		iterator begin()
		{
			return iterator{ Elems,0 };
		}

		const_iterator begin()const
		{
			return const_iterator{ Elems,0 };
		}

		iterator end() noexcept 
		{
			return iterator(Elems, Size);
		}

		const_iterator end() const
		{
			return const_iterator{ Elems,Size };
		}

		const_iterator cbegin()const
		{
			return begin();
		}

		const_iterator cend()const
		{
			return end();
		}

		T* _Unchecked_begin() noexcept
		{
			return Elems;
		}

		const T* _Unchecked_begin() const 
		{
			return Elems;
		}

		T* _Unchecked_end() 
		{
			return Elems + Size;
		}
		T* _Unchecked_end() const noexcept 
		{
			return Elems + Size;
		}

		constexpr size_type size() const noexcept
		{
			return Size;
		}

		constexpr size_type max_size() const noexcept
		{
			return Size;
		}

		constexpr bool empty() const noexcept
		{
			return false;
		}

		reference at(size_type _Pos)
		{
			if (Size <= _Pos) {
				_Xran();
			}

			return Elems[_Pos];
		}

		constexpr const_reference at(size_type _Pos) const
		{
			if (Size <= _Pos) {
				_Xran();
			}

			return Elems[_Pos];
		}

		reference operator[](_In_range_(0, Size - 1) size_type _Pos)  /* strengthened */
		{

			return Elems[_Pos];
		}

		constexpr const_reference operator[](_In_range_(0, Size - 1) size_type _Pos) const
		{

			return Elems[_Pos];
		}

		reference front() noexcept /* strengthened */
		{
			return Elems[0];
		}

		constexpr const_reference front() const noexcept /* strengthened */
		{
			return Elems[0];
		}

		reference back() noexcept /* strengthened */
		{
			return Elems[Size - 1];
		}

		constexpr const_reference back() const noexcept /* strengthened */
		{
			return Elems[Size - 1];
		}

		T* data() noexcept
		{
			return Elems;
		}

		const T* data() const noexcept
		{
			return Elems;
		}

		[[noreturn]] void _Xran() const
		{
		}
	private:
		T Elems[Size];
	};

	template <class _First, class... _Rest>
	struct _Enforce_same {
		static_assert(std::conjunction_v<std::is_same<_First, _Rest>...>,
			"N4687 26.3.7.2 [array.cons]/2: "
			"Requires: (is_same_v<T, U> && ...) is true. Otherwise the program is ill-formed.");
		using type = _First;
	};

	template <class _First, class... _Rest>
	array(_First, _Rest...)->array<typename _Enforce_same<_First, _Rest...>::type, 1 + sizeof...(_Rest)>;
}