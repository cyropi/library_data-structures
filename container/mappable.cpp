
namespace lasd 
{
    // PreOrderMappableContainer

    template <typename Data>
	void PreOrderMappableContainer<Data>::Map(MapFun mapFun)
	{
		this->PreOrderMap(mapFun);
	}




	// PostOrderMappableContainer

    template <typename Data>
	void PostOrderMappableContainer<Data>::Map(MapFun mapFun)
	{
		this->PostOrderMap(mapFun);
	}	
}
