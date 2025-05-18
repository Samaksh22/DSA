#pragma once

#include <cstdlib>
#include <stdexcept>

template <class T>
class Matrix
{
private:
    std::size_t _row;
    std::size_t _col;

    T *_mat_elem;

public:
    Matrix(std::size_t r, std::size_t c = 0)
    {
        _row = r;
        _col = (c == 0 ? r : c);
        _mat_elem = new T[r * c];
    }

    ~Matrix()
    {
        delete[] _mat_elem;
    }

    T &at(std::size_t r, std::size_t c)
    {
        if (r < 0 || r >= _row || c < 0 || c >= _col)
            throw std::runtime_error("Index Out of Range");
        else
            return _mat_elem[r * _col + c];
    }
};