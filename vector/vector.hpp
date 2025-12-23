
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../container/linear.hpp"


namespace lasd 
{
	template <typename Data>
	class Vector : virtual public ResizableContainer,
				   virtual public MutableLinearContainer<Data>
	{
		protected:
			Data* array = nullptr;
			

		public:
			// Default constructor
			Vector() = default;


			// Specific constructors
			Vector(const ulong); // A vector with a given initial dimension
			Vector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
			Vector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer


			// Copy constructor
			Vector(const Vector<Data>&);
			// Move constructor
			Vector(Vector<Data>&&) noexcept;


			// Destructor
			virtual ~Vector();


			// Copy assignment
            Vector<Data>& operator=(const Vector<Data>&); 
			// Move assignment
            Vector<Data>& operator=(Vector<Data>&&) noexcept; 


			// Comparison operators
			bool operator==(const Vector<Data>&) const noexcept;
			bool operator!=(const Vector<Data>&) const noexcept;


			// Specific member functions (inherited from LinearContainer)
			const Data& operator[](ulong) const noexcept(false) override; // Override LinearContainer member (must throw std::out_of_range when out of range)
			const Data& Front() const noexcept(false) override; // (non-mutable version; concrete function must throw std::length_error when empty)
			const Data& Back() const noexcept(false) override; // (non-mutable version; concrete function must throw std::length_error when empty)


			// Specific member functions (inherited from MutableLinearContainer)
			Data& operator[](ulong) noexcept(false) override; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)
			Data& Front() noexcept(false) override; // (mutable version; concrete function must throw std::length_error when empty)
			Data& Back() noexcept(false) override; // (mutable version; concrete function must throw std::length_error when empty)


  			// Specific member function (inherited from ClearableContainer)
			void Clear() override; // Override ClearableContainer member


			// Specific member function (inherited from ResizableContainer)
			void Resize(ulong) override;
	};




	template <typename Data>
    class SortableVector : virtual public Vector<Data>, // TODO: Non necessario
                           virtual public SortableLinearContainer<Data>
	{
		public:
			// Default constructor
			SortableVector() = default;


			// Specific constructors
			SortableVector(const ulong); // A vector with a given initial dimension
			SortableVector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
			SortableVector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer


			// Copy constructor
			SortableVector(const SortableVector<Data>&);
			// Move constructor
			SortableVector(SortableVector<Data>&&);


			// Destructor
			virtual ~SortableVector() = default;


			// Copy assignment
    		SortableVector<Data>& operator=(const SortableVector<Data>&);
			// Move assignment
			SortableVector<Data>& operator=(SortableVector<Data>&&) noexcept;
	};

}

#include "vector.cpp"

#endif

