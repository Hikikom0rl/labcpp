/* Image iterator.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include <cmath>
#include <iterator>
#include <type_traits>

#include <iostream>

#include <utility>

#include <boost/iterator/iterator_adaptor.hpp>

//{ image iterator
template<class Iterator>
class image_iterator: public boost::iterator_adaptor<
		image_iterator<Iterator>
		, Iterator
		, boost::use_default
		, boost::random_access_traversal_tag
	>
{
public:
	explicit image_iterator(Iterator base_it, std::size_t width, std::size_t stride)
		: image_iterator::iterator_adaptor_(base_it),
		  m_width{width},
		  m_stride{stride},
		  m_row_iter{base_it}
	{};

private:
	friend class boost::iterator_core_access;
	// Since this iterator is using random traversal tag,
	// we can go at a random index in given container.

	// Also, we are bounded only for the same data types
	// that support random access to it.

	// Meaning, image_iterator expects only those data types
	// that have random access to any element (they have at least operator[])
	template<class Sub_Iterator>
	class row_iterator : public boost::iterator_adaptor<
			row_iterator<Sub_Iterator>
			, Sub_Iterator
			, boost::use_default
			, boost::random_access_traversal_tag
		>
	{
	public:
		row_iterator(Sub_Iterator from_base_it)
			: row_iterator::iterator_adaptor_{from_base_it} 
		{};

	private:

		friend class boost::iterator_core_access;
		friend class image_iterator<Sub_Iterator>;

		void increment() {this->base_reference() += 1;}
		void decrement() {this->base_reference() -= 1;}
		void advance(typename row_iterator::difference_type amount)
		{
			this->base_reference() += amount;
		}
		typename row_iterator::difference_type distance_to(const row_iterator& other) const
		{
			return other.base_reference() - this->base_reference();
		}

	};

	std::size_t m_width{};
	std::size_t m_stride{};

	friend class row_iterator<Iterator>;
	row_iterator<Iterator> m_row_iter;
									
	void increment() // increment is just advance by step in positive direction
	{
		advance(1);
	}

	void decrement() // decrement is just advance by step in negative direction
	{
		advance(-1);
	}

	void advance(typename image_iterator::difference_type amount)
	{
		const int next_row = (this->base() - m_row_iter.base() + amount + 1) / m_width;
		m_row_iter.base_reference() += m_stride * next_row;
		this->base_reference() += amount + (m_stride - m_width)*next_row;
	}

	typename image_iterator::difference_type distance_to(const image_iterator& other) const
	{
		const int row = (m_row_iter.base_reference() - other.m_row_iter.base_reference()) / m_stride;
		return other.base() - this->base() + (m_stride - m_width)*row;
	}
};
//}

#endif // __ITERATOR_HPP__
