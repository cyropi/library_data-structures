
#include <stdexcept>


namespace lasd
{
    template <typename Data>
    SetVec<Data>::SetVec() : vector(DEFAULT_SIZE)
    {}


    template <typename Data>
    SetVec<Data>::SetVec(const ulong size) : vector(size)
    {} 


    template <typename Data>
    SetVec<Data>::SetVec(const TraversableContainer<Data>& traversableContainer) : vector(traversableContainer.Size())
    {
        traversableContainer.Traverse([this](const Data& data) 
                                        -> void{ this->Insert(data); });
    }


    template <typename Data>
    SetVec<Data>::SetVec(MappableContainer<Data>&& mappableContainer) : vector(mappableContainer.Size())
    {
        mappableContainer.Map([this](Data& data) 
                                -> void{ this->Insert(std::move(data)); });
    }


    template <typename Data>
    SetVec<Data>::SetVec(const SetVec<Data>& setVec) : vector(setVec.size)
    {
        this->size = setVec.size;
        this->head = 0;
        this->tail = this->size;

        for (ulong i = 0; i < this->size; ++i)
            this->vector[i] = setVec[i];
    }


    template <typename Data>
    SetVec<Data>::SetVec(SetVec<Data>&& setVec) noexcept 
    {
        std::swap(this->vector, setVec.vector);
        std::swap(this->size, setVec.size);
        std::swap(this->head, setVec.head);
        std::swap(this->tail, setVec.tail);
    }


    template <typename Data>
    SetVec<Data>::~SetVec() 
    {
        this->Clear();
    }


    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& setVec)
    {
        SetVec<Data> tmpSetVec = setVec;
        std::swap(*this, tmpSetVec);

        return *this; 
    }


    template<typename Data>
    SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& setVec) noexcept
    {
        std::swap(this->vector, setVec.vector);
        std::swap(this->size, setVec.size);
        std::swap(this->head, setVec.head);
        std::swap(this->tail, setVec.tail);

        return *this; 
    }


    template <typename Data>
    bool SetVec<Data>::operator==(const SetVec<Data>& setVec) const noexcept
    {
        if(this->size != setVec.size)
            return false;

        for(ulong i = 0; i < this->size; ++i) 
        {
            if ((*this)[i] != setVec[i]) 
                return false;
        }

        return true;
    }


    template <typename Data>
    bool SetVec<Data>::operator!=(const SetVec<Data>& setVec) const noexcept
    {
        return !(*this == setVec);
    }


    template <typename Data>
    const Data& SetVec<Data>::Min() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to fetch the min element...");

        return (*this)[0];
    }


    template <typename Data>
    void SetVec<Data>::RemoveMin() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to remove the min element...");

        this->head = (this->head + 1) % this->Capacity();
        this->size--;
    }


    template <typename Data>
    Data SetVec<Data>::MinNRemove() noexcept(false)
    {
        Data minValue;

        try
        {
			minValue = this->Min();
            this->RemoveMin();
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (MinNRemove): " << e.what() << '\n';
            throw;
        }
        
        return minValue;
    }


    template <typename Data>
    const Data& SetVec<Data>::Max() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to fetch the max element...");

        return (*this)[this->size-1];
    }


    template <typename Data>
    void SetVec<Data>::RemoveMax() noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to remove the max element...");

        this->tail = (this->tail - 1) % this->Capacity(); // TODO: cambiare in (this->tail + this->Capacity() - 1) % this->Capacity()
        this->size--;
    }


    template <typename Data>
    Data SetVec<Data>::MaxNRemove() noexcept(false)
    {
        Data maxValue;

        try
        {
			maxValue = this->Max();
            this->RemoveMax();
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (MaxNRemove): " << e.what() << '\n';
            throw;
        }
        
        return maxValue;
    }


    template <typename Data>
    const Data& SetVec<Data>::Predecessor(const Data& data) const noexcept(false)
    {
        if(data > this->Max())
            return this->Max();

        ulong predecessor_index;
        try
        {
            predecessor_index = this->BinarySearchPredecessor(data);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (Predecessor): " << e.what() << '\n';
            throw;
        }

        return (*this)[predecessor_index];
    }


    template <typename Data>
    void SetVec<Data>::RemovePredecessor(const Data& data) noexcept(false)
    {
        try
        {
            const Data& predecessor = this->Predecessor(data);
            this->Remove(predecessor);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (RemovePredecessor): " << e.what() << '\n';
            throw;
        }
    }


    template <typename Data>
    Data SetVec<Data>::PredecessorNRemove(const Data& data) noexcept(false)
    {
        Data predecessor;
        try
        {
            predecessor = this->Predecessor(data);
            this->Remove(predecessor);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (PredecessorNRemove): " << e.what() << '\n';
            throw;
        }
        
        return predecessor;
    }


    template <typename Data>
    const Data& SetVec<Data>::Successor(const Data& data) const noexcept(false)
    {
        if(data < this->Min())
            return this->Min();

        ulong successor_index;
        try
        {
            successor_index = this->BinarySearchSuccessor(data);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (Successor): " << e.what() << '\n';
            throw;
        }

        return (*this)[successor_index];
    }


    template <typename Data>
    void SetVec<Data>::RemoveSuccessor(const Data& data) noexcept(false)
    {
        try
        {
            const Data& successor = this->Successor(data);
            this->Remove(successor);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (RemoveSuccessor): " << e.what() << '\n';
            throw;
        }
    }


    template <typename Data>
    Data SetVec<Data>::SuccessorNRemove(const Data& data) noexcept(false)
    {
        Data successor;
        try
        {
            successor = this->Successor(data);
            this->Remove(successor);
        }
        catch(const std::length_error& e)
        {
            std::cerr << "Exception occurred in SetVec (SuccessorNRemove): " << e.what() << '\n';
            throw;
        }

        return successor;
    }


    template <typename Data>
	bool SetVec<Data>::Insert(const Data& data)
    {
        if(this->size == this->Capacity())
            this->Resize((this->size*2)+1);

        if(this->Empty()) 
        {
            this->vector[this->head] = data;
            this->tail = (this->head + 1) % this->Capacity();
            this->size++;

            return true;
        }
        
        if(data < this->Min())
        {
            this->head = (this->head - 1 + this->Capacity()) % this->Capacity();
            this->vector[this->head] = data;
            this->size++;

            return true;
        }

        if(data > this->Max())
        {
            this->vector[this->tail] = data;
            this->tail = (this->tail + 1) % this->Capacity();
            this->size++;

            return true;
        } 


        ulong logical_index = this->BinarySearchLowerBound(data);

        if(logical_index < this->size && (*this)[logical_index] == data)
            return false;


        if(logical_index <= this->size / 2) 
        {
            // Shift left
            for(ulong i = 0; i < logical_index; i++)
                this->vector[(this->head + i - 1 + this->Capacity()) % this->Capacity()] = this->vector[(this->head + i) % this->Capacity()];

            this->head = (this->head - 1 + this->Capacity()) % this->Capacity();
        } 
        else 
        {
            // Shift right
            for(long i = static_cast<long>(this->size - 1); i >= static_cast<long>(logical_index); i--) 
                this->vector[(this->head + i + 1) % this->Capacity()] = this->vector[(this->head + i) % this->Capacity()];

            this->tail = (this->tail + 1) % this->Capacity();
        }

        ulong physical_index = (this->head + logical_index) % this->Capacity(); 
        this->vector[physical_index] = data;
        this->size++;

        return true;
    }


    template <typename Data>
    bool SetVec<Data>::Insert(Data&& data)
    {
        if(this->size == this->Capacity())
            this->Resize((this->size*2)+1);

        if(this->Empty()) 
        {
            this->vector[this->head] = std::move(data);
            this->tail = (this->head + 1) % this->Capacity();
            this->size++;

            return true;
        }
        
        if(data < this->Min())
        {
            this->head = (this->head - 1 + this->Capacity()) % this->Capacity();
            this->vector[this->head] = std::move(data);
            this->size++;

            return true;
        }

        if(data > this->Max())
        {
            this->vector[this->tail] = std::move(data);
            this->tail = (this->tail + 1) % this->Capacity();
            this->size++;

            return true;
        } 


        ulong logical_index = this->BinarySearchLowerBound(data);

        if(logical_index < this->size && (*this)[logical_index] == data)
            return false;


        if(logical_index <= this->size / 2) 
        {
            // Shift left
            for(ulong i = 0; i < logical_index; i++)
                this->vector[(this->head + i - 1 + this->Capacity()) % this->Capacity()] = std::move(this->vector[(this->head + i) % this->Capacity()]);

            this->head = (this->head - 1 + this->Capacity()) % this->Capacity();
        } 
        else 
        {
            // Shift right
            for(long i = static_cast<long>(this->size - 1); i >= static_cast<long>(logical_index); i--) // TODO: eliminare cast a long
                this->vector[(this->head + i + 1) % this->Capacity()] = std::move(this->vector[(this->head + i) % this->Capacity()]);

            this->tail = (this->tail + 1) % this->Capacity();
        }

        ulong physical_index = (this->head + logical_index) % this->Capacity(); 
        this->vector[physical_index] = std::move(data);
        this->size++;

        return true;
    }


    template <typename Data>
	bool SetVec<Data>::Remove(const Data& data)
    {
        if(this->size == this->Capacity()/2)
            this->Resize(this->size);

        if(this->Empty() || data < this->Min() || data > this->Max())
            return false;


        ulong logical_index = this->BinarySearch(data);
        
        if(logical_index == this->size)
            return false;

        if(logical_index <= size / 2) 
        {
            // Shift right
            for(ulong i = logical_index; i > 0; i--)
                this->vector[(this->head + i) % this->Capacity()] = this->vector[(this->head + i - 1 + this->Capacity()) % this->Capacity()];

            this->head = (this->head + 1) % this->Capacity();
        } 
        else 
        {
            // Shift left
            for(ulong i = logical_index; i < this->size-1; i++)
                this->vector[(this->head + i) % this->Capacity()] = this->vector[(this->head + i + 1) % this->Capacity()];

            this->tail = (this->tail - 1 + this->Capacity()) % this->Capacity();
        }

        this->size--;

        return true;
    }

    
    template <typename Data>
    const Data& SetVec<Data>::operator[](ulong index) const noexcept(false)
    {        
        if(index >= this->size)
            throw std::out_of_range("Invalid index! You're out of the setVec size range...");
        
        return this->vector[(this->head + index) % this->Capacity()];
    }


    template <typename Data>
	const Data& SetVec<Data>::Front() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to fetch the first element...");

        return this->Min();
    }


    template <typename Data>
	const Data& SetVec<Data>::Back() const noexcept(false)
    {
        if(this->Empty())
            throw std::length_error("SetVec is empty! It wasn't possible to fetch the last element...");
            
        return this->Max();
    }


    template <typename Data>
    bool SetVec<Data>::Exists(const Data &data) const noexcept
    {
        ulong index = BinarySearch(data);
        return index != this->size ? true : false;
    }


    template <typename Data>
    void SetVec<Data>::Clear() 
    {
        this->vector.Clear();
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }


    template <typename Data>
    void SetVec<Data>::Resize(ulong newSize) 
    {
        if(newSize == 0)
        {
            this->Clear();
        }
        else if(this->size != newSize)
        {
            Vector<Data> tmpVec = Vector<Data>(newSize);

            ulong minSize = (this->size < newSize) ? this->size : newSize;
            for(ulong i = 0; i < minSize; i++)
                tmpVec[i] = std::move((*this)[i]); 

            std::swap(this->vector, tmpVec);
            this->head = 0;
            this->tail = this->size;
        }
    }


    template <typename Data>
    ulong SetVec<Data>::Capacity() const noexcept
    {
        return this->vector.Size();
    }


    template <typename Data>
    ulong SetVec<Data>::BinarySearch(const Data& data) const
    {
        if(this->Empty()) 
            return this->size;

        long start = 0;
        long end = this->size - 1;
        
        while(start <= end)
        {
            ulong middle = (start + end) / 2;

            if(data == (*this)[middle]) 
                return middle;
            else if(data > (*this)[middle])
                start = middle + 1;
            else
                end = middle - 1;
        }

        return this->size;
    }


    template <typename Data>
    ulong SetVec<Data>::BinarySearchLowerBound(const Data& data) const 
    {
        ulong start = 0;
        ulong end = this->size;
                
        while(start < end)
        {
            ulong middle = (start + end) / 2;

            if(data == (*this)[middle]) 
                return middle;
            else if(data > (*this)[middle])
                start = middle + 1;
            else
                end = middle;
        }

        return start;
    } 


    template <typename Data>
    ulong SetVec<Data>::BinarySearchPredecessor(const Data& data) const noexcept(false)
    {
        ulong start = 0;
        ulong end = this->size;

        ulong predecessor_index = 0;
        bool isPredecessorFound = false;
        
        while(start < end)
        {
            ulong middle = (start + end) / 2;

            if(data > (*this)[middle])
            {
                predecessor_index = middle;
                isPredecessorFound = true;
                start = middle + 1;
            }
            else
                end = middle;
        }

        if(isPredecessorFound == false)
            throw std::length_error("Non è stato possibile trovare il predecessore nel Set Vec...");

        return predecessor_index;
    }


    template <typename Data>
    ulong SetVec<Data>::BinarySearchSuccessor(const Data& data) const noexcept(false)
    {
        ulong start = 0;
        ulong end = this->size;

        ulong successor_index = 0;
        bool isSuccessorFound = false;
        
        while(start < end)
        {
            ulong middle = (start + end) / 2;

            if(data >= (*this)[middle])
                start = middle + 1;
            else
            {
                successor_index = middle;
                isSuccessorFound = true;
                end = middle;
            }
        }

        if(isSuccessorFound == false)
            throw std::length_error("Non è stato possibile trovare il successore nel Set Vec...");

        return successor_index;
    }
}




// TODO: migliorare Insert e Remove
/*
if (this->size == this->Capacity()) {
    // Se size è 0 (ovvero setvec appena creato/vuoto), diventa DEFAULT_SIZE. Altrimenti raddoppia.
    ulong newSize = (this->size == 0) ? DEFAULT_SIZE : this->size * 2;
    this->Resize(newSize);
}


// Riduci solo se:
// 1. Siamo sotto 1/4 (per lasciare spazio di crescita)
// 2. E siamo sopra la dimensione minima (per non fare allocazioni minuscole)
if (this->size <= this->Capacity() / 4 && this->Capacity() > DEFAULT_SIZE) {
    // Dimezza, ma mai sotto DEFAULT_SIZE
    ulong newSize = this->Capacity() / 2;
    if (newSize < DEFAULT_SIZE) newSize = DEFAULT_SIZE;

    this->Resize(newSize);
}


AGGIUNGERE funzioni ausiliari shift:

template <typename Data>
void SetVec<Data>::ShiftLeft(ulong index) {
    // Spostiamo verso sinistra solo gli elementi PRIMA dell'indice
    // Nota: head viene decrementata alla fine del processo o dal chiamante?
    // Meglio farlo qui dentro per coerenza.

    // 1. Sposto gli elementi
    for(ulong i = 0; i < index; i++) {
        this->vector[(this->head + i - 1 + this->Capacity()) % this->Capacity()] =
            this->vector[(this->head + i) % this->Capacity()];
    }
    // 2. Aggiorno la Head
    this->head = (this->head - 1 + this->Capacity()) % this->Capacity();
}

template <typename Data>
void SetVec<Data>::ShiftRight(ulong index) {
    // Spostiamo verso destra gli elementi DALL'indice in poi
    for(long i = static_cast<long>(this->size - 1); i >= static_cast<long>(index); i--) {
        this->vector[(this->head + i + 1) % this->Capacity()] =
            this->vector[(this->head + i) % this->Capacity()];
    }
    // Aggiorno la Tail
    this->tail = (this->tail + 1) % this->Capacity();
}



*/
