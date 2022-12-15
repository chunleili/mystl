#pragma once

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#pragma once
#include <string>

namespace mystl
{
    using ValueType = int;
    class vector
    {
    private:
        int _capacity;
        int _count;
        ValueType* _elements;
    public:
        vector(size_t capacity);
        vector(size_t n, ValueType val);
        ~vector();
        size_t size();
        size_t capacity();
    };

    vector::vector(size_t capacity)
    {
        _capacity = capacity;
        _count = 0;
        _elements = new ValueType[_capacity]();
    }

    vector::vector(size_t n, ValueType val)
    {
        _capacity = n;
        _count = n;
        _elements = new ValueType[_capacity]();
        for (int i = 0; i < _count; i++)
        {
            _elements[i] = val;
        }
    }

    vector::~vector()
    {
        delete[] _elements;
    }

    size_t vector::size()
    {
        return _count;
    }

    size_t vector::capacity()
    {
        return _capacity;
    }

} // namespace mystl
