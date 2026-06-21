#ifndef DynamicArray_hpp
#define DynamicArray_hpp

template< typename T >
class DynamicArray
{
private:
    T* data;
    int _capacity;
    int _size;

    void ensureCapacity()
    {
        if(_size >= _capacity)
        {
            if(_capacity == 0)
            {
                _capacity = 4;
            }
            else 
            {
                _capacity = _capacity * 2;
            } 
            T* newData = new T[_capacity];
            for(int i=0; i<_size; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

public:
    DynamicArray()
    {
        data = nullptr;
        _capacity = 0;
        _size = 0;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void push_back(const T& item)
    {
        ensureCapacity();
        data[_size] = item;
        _size++;
    }

    int size() const
    {
        return _size;
    }

    void erase(int index)
    {
        if(index < 0 || index >= _size) return;
        for(int i=index; i<_size-1; i++)
        {
            data[i] = data[i+1];
        }
        _size--;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    const T& operator[](int index) const
    {
        return data[index];
    }
};

#endif