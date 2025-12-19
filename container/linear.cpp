
#include <stdexcept>


namespace lasd 
{
    // LinearContainer

    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data>& linearContainer) const noexcept
    {
        if(this->size != linearContainer.size)
            return false;

        for(ulong i = 0; i < this->size; i++)
        {
            if((*this)[i] != linearContainer[i])
                return false;
        }

        return true;
    }


    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& linearContainer) const noexcept
    {
        return !(*this == linearContainer);
    }


    template <typename Data>
	const Data& LinearContainer<Data>::Front() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("LinearContainer is empty! It wasn't possible to fetch the first element...");

        return (*this)[0];
    }


    template <typename Data>
	const Data& LinearContainer<Data>::Back() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("LinearContainer is empty! It wasn't possible to fetch the last element...");

        return (*this)[this->size-1];
    }


    template <typename Data>
    void LinearContainer<Data>::Traverse(TraverseFun traverseFun) const 
    {
        this->PreOrderTraverse(traverseFun);
    };


    template <typename Data>
    void LinearContainer<Data>::PreOrderTraverse(TraverseFun traverseFun) const 
    {
        for(ulong i = 0; i < this->size; i++)
            traverseFun((*this)[i]);
    };

        
    template <typename Data>
    void LinearContainer<Data>::PostOrderTraverse(TraverseFun traverseFun) const 
    {
        if(this->Empty())
            return;

        for(ulong i = this->size; i > 0;)
            traverseFun((*this)[--i]);
    };
    
    
    

    // MutableLinearContainer

    template <typename Data>
    Data& MutableLinearContainer<Data>::Front() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("MutableLinearContainer is empty! It wasn't possible to fetch the first element...");

        return (*this)[0];
    }


    template <typename Data>
    Data& MutableLinearContainer<Data>::Back() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("MutableLinearContainer is empty! It wasn't possible to fetch the last element...");

        return (*this)[this->size-1];
    }


    template <typename Data>
    void MutableLinearContainer<Data>::Map(MapFun mapFun)
    {
        this->PreOrderMap(mapFun);
    }


    template <typename Data>
    void MutableLinearContainer<Data>::PreOrderMap(MapFun mapFun)
    {
        for(ulong i = 0; i < this->size; i++)
            mapFun((*this)[i]);
    }


    template <typename Data>
    void MutableLinearContainer<Data>::PostOrderMap(MapFun mapFun)
    {
        if(this->Empty())
            return;

        for(ulong i = this->size; i > 0;)
            mapFun((*this)[--i]);
    }




    // SortableLinearContainer

    template<typename Data>
    void SortableLinearContainer<Data>::Sort()
    {
        InsertionSort();
    }


    template<typename Data>
    void SortableLinearContainer<Data>::InsertionSort()
    {
        for(ulong i = 1; i < this->size; ++i) 
        { 
            Data temp = (*this)[i];

            ulong j = i;
            while(j > 0 && (*this)[j-1] > temp) 
            { 
                (*this)[j] = (*this)[j-1];
                --j;
            }

            (*this)[j] = temp; 
        }   
    }
}

