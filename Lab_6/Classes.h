#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // ��� accumulate 


using std::cout;
using std::vector;
using std::max;
using std::max_element;
using std::invalid_argument;


template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows;
    size_t columns;

public:
    Matrix(size_t r, size_t c) : rows(r), columns(c) {
        data.resize(rows, vector<T>(columns));
    }


    T& operator()(size_t i, size_t j) {
        return data[i][j];
    }


    const T& operator()(size_t i, size_t j) const {
        return data[i][j];
    }


    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << '\n';
        }
    }


    T findMax() const {
        T max_el = data[0][0];

        for (const auto& row : data) {
            max_el = max(max_el, *max_element(row.begin(), row.end()));
        }

        return max_el;
    }


    T calculateAverage() const {
        T sum = 0;
        size_t count = 0;

        for (const auto& row : data) {
            sum = accumulate(row.begin(), row.end(), sum);
            count += row.size();
        }

        return sum / count;
    }


    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw invalid_argument("Размеры матриц не совпадают!");
        }

        Matrix result(rows, columns);

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }

        return result;
    }


    bool operator<(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw invalid_argument("Размеры матриц не совпадают!");
        }

        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < columns; ++j) {
                if (data[i][j] >= other(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
};