#include <iostream>
#include "matrix.hpp"

using namespace std;

void assign(Matrix<int> &T)
{
    int count = 5;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            T.at(i, j) = count++;
}

int main()
{
    Matrix<int> M(3);

    assign(M);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cout << M.at(i, j) << endl;
}