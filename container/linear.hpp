
#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "mappable.hpp"


namespace lasd 
{
	
	template <typename Data>
	class LinearContainer : virtual public PreOrderTraversableContainer<Data>, 
							virtual public PostOrderTraversableContainer<Data>
	{
		public:
			// Destructor
			virtual ~LinearContainer() = default;


			// Copy assignment
			LinearContainer& operator=(const LinearContainer&) = delete;
			// Move assignment
			LinearContainer& operator=(LinearContainer&&) noexcept = delete;


			// Comparison operators
			bool operator==(const LinearContainer<Data>&) const noexcept; 
			bool operator!=(const LinearContainer<Data>&) const noexcept;


			// Specific member functions
			virtual const Data& operator[](ulong) const noexcept(false) = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
			virtual const Data& Front() const noexcept(false); // (non-mutable version; concrete function must throw std::length_error when empty)
			virtual const Data& Back() const noexcept(false); // (non-mutable version; concrete function must throw std::length_error when empty)


			// Specific member function (inherited from TraversableContainer)
			using typename TraversableContainer<Data>::TraverseFun;
			void Traverse(TraverseFun) const override;


			// Specific member function (inherited from PreOrderTraversableContainer)
			void PreOrderTraverse(TraverseFun) const override;


			// Specific member function (inherited from PostOrderTraversableContainer)
			void PostOrderTraverse(TraverseFun) const override;
	};


	

	template <typename Data>
	class MutableLinearContainer : virtual public LinearContainer<Data>, 
								   virtual public PreOrderMappableContainer<Data>, 
								   virtual public PostOrderMappableContainer<Data>
	{
		protected:
			using LinearContainer<Data>::operator[];
			using LinearContainer<Data>::Front;
			using LinearContainer<Data>::Back;


		public:
			// Destructor
			virtual ~MutableLinearContainer() = default;


			// Copy assignment
			MutableLinearContainer& operator=(const MutableLinearContainer&) = delete;
			// Move assignment
			MutableLinearContainer& operator=(MutableLinearContainer&&) noexcept = delete;


			// Specific member functions
            virtual Data& operator[](ulong) noexcept(false) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)
			virtual Data& Front() noexcept(false); // (mutable version; concrete function must throw std::length_error when empty)
			virtual Data& Back() noexcept(false); // (mutable version; concrete function must throw std::length_error when empty)


			// Specific member function (inherited from MappableContainer)
			using typename MappableContainer<Data>::MapFun;
			void Map(MapFun) override; 


			// Specific member function (inherited from PreOrderMappableContainer)
			void PreOrderMap(MapFun) override;


			// Specific member function (inherited from PostOrderMappableContainer)
			void PostOrderMap(MapFun) override;
	};




	template <typename Data>
	class SortableLinearContainer : virtual public MutableLinearContainer<Data>
	{
		public:
			// Destructor
			virtual ~SortableLinearContainer() = default;


			// Copy assignment
			SortableLinearContainer& operator=(const SortableLinearContainer&) = delete;
			// Move assignment
			SortableLinearContainer& operator=(SortableLinearContainer&&) noexcept = delete;


			// Specific member function
			virtual void Sort();


		protected:
			// Auxiliary member functions
			void InsertionSort();
	};
	
}

#include "linear.cpp"

#endif
