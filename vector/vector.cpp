
#include <algorithm>
#include <stdexcept>


namespace lasd 
{
    // Vector

    template<typename Data>
    Vector<Data>::Vector(const ulong size)
    {
        this->size = size;

        if(this->size == 0)
            this->array = nullptr;
        else
            this->array = new Data[size];        
    } 


    template<typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& traversableContainer) : Vector(traversableContainer.Size())
    {
        ulong i = 0;
        traversableContainer.Traverse([this, &i] (const Data& data)
                                        -> void{ this->array[i++] = data; });
    }

    
    template<typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& mappableContainer) : Vector(mappableContainer.Size())
    {
        ulong i = 0;
        mappableContainer.Map([this, &i] (Data& data)
                                -> void{ this->array[i++] = std::move(data); });
    }


    template<typename Data>
    Vector<Data>::Vector(const Vector<Data>& vector) : Vector(vector.Size())
    {
        std::copy_n(vector.array, this->size, this->array);
    }


    template<typename Data>
    Vector<Data>::Vector(Vector<Data>&& vector) noexcept 
    {
        std::swap(this->size, vector.size);
        std::swap(this->array, vector.array); 
    }


    template<typename Data>
    Vector<Data>::~Vector()
    {
        this->Clear();
    }


    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vector)
    {
        Vector<Data> tmpVector = vector;
        std::swap(tmpVector, *this);

        return *this; 
    }


    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vector) noexcept
    {
        std::swap(this->size, vector.size);
        std::swap(this->array, vector.array);

        return *this; 
    }


    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data>& vector) const noexcept 
    {
        return LinearContainer<Data>::operator==(vector);
    }


    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data>& vector) const noexcept 
    {
        return !(*this == vector);
    }


    template<typename Data>
	const Data& Vector<Data>::operator[](ulong index) const noexcept(false)
    {
        if(index >= this->size)
            throw std::out_of_range("Invalid index! You're out of the vector size range...");
        
        return this->array[index];
    }


    template<typename Data>
	const Data& Vector<Data>::Front() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("Vector is empty! It wasn't possible to fetch the first element...");

        return (*this)[0];
    }


    template <typename Data>
	const Data& Vector<Data>::Back() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("Vector is empty! It wasn't possible to fetch the last element...");

        return (*this)[this->size-1];
    }


    template<typename Data>
	Data& Vector<Data>::operator[](ulong index) noexcept(false)
    {
        if(index >= this->size)
            throw std::out_of_range("Invalid index! You're out of the vector size range...");
        
        return this->array[index];
    }


    template <typename Data>
    Data& Vector<Data>::Front() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("Vector is empty! It wasn't possible to fetch the first element...");

        return (*this)[0];
    }


    template <typename Data>
    Data& Vector<Data>::Back() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("Vector is empty! It wasn't possible to fetch the last element...");

        return (*this)[this->size-1];
    }


    template<typename Data>
	void Vector<Data>::Clear()
    {            
        delete[] this->array;
        this->array = nullptr;
        this->size = 0;
    }


    template<typename Data>
	void Vector<Data>::Resize(ulong newSize)
    {
        if(newSize == 0)
        {
            this->Clear();
        }
        else if(this->size != newSize)
        {
            Data* tmpArray = new Data[newSize];

            ulong minSize = (this->size < newSize) ? this->size : newSize;
            for(ulong i = 0; i < minSize; i++)
                std::swap(this->array[i], tmpArray[i]); // TODO: modificare con std::move
            
            std::swap(this->array, tmpArray);
            this->size = newSize;

            delete[] tmpArray;
        }
    }





    // SortableVector

    template<typename Data>
    SortableVector<Data>::SortableVector(const ulong size) : Vector<Data>(size)
    {}


    template<typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data>& traversableContainer) : Vector<Data>(traversableContainer)
    {}


    template<typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data>&& mappableContainer) : Vector<Data>(std::move(mappableContainer))
    {}


    template<typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data>& sortableVector) : Vector<Data>(sortableVector)
    {}


    template<typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data>&& sortableVector) : Vector<Data>(std::move(sortableVector))
    {}


    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& sortableVector) 
    {
        Vector<Data>::operator=(sortableVector);
        return *this;
    }

    
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& sortableVector) noexcept
    {
        Vector<Data>::operator=(std::move(sortableVector));
        return *this;
    }
}
