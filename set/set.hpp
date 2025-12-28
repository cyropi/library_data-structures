
#ifndef SET_HPP
#define SET_HPP

#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"


namespace lasd 
{
	template <typename Data>
	class Set : virtual public ClearableContainer, 
				virtual public LinearContainer<Data>, 
				virtual public OrderedDictionaryContainer<Data>
	{ 
		public:
			// Destructor
			virtual ~Set() = default;


			// Copy assignment
			Set& operator=(const Set&) = delete; // Copy assignment of abstract types is not possible.
			// Move assignment
			Set& operator=(Set&&) = delete; // Move assignment of abstract types is not possible.
	};
}

#endif
