/*
Given an m x n integer matrix matrix, if an element is 0, 
set its entire row and column to 0's.

You must do it in place.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
    void setRowsAndColumnsToZero(std::vector<std::vector<int>>& matrix, int x, int y)
    {   
        for(size_t col = 0; col < matrix[0].size(); col++)
        {
            matrix[(size_t)x][col] = 0;
        }

        for(size_t row = 0; row < matrix.size(); row++)
        {
            matrix[row][(size_t)y] = 0;
        }
    }

    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
        std::vector<std::pair<int, int>> coordinatesZeros; 

        for(int row = 0; (size_t)row < matrix.size(); row++)
        {
            for(int col = 0; (size_t)col < matrix[0].size(); col++)
            {
                if(matrix[(size_t)row][(size_t)col] == 0)
                {
                    std::pair<int, int> pair = {row, col};
                    coordinatesZeros.emplace_back(pair);
                }
            }
        }

        for(int i = 0; (size_t)i < coordinatesZeros.size(); i++)
        {
            setRowsAndColumnsToZero(matrix, 
                coordinatesZeros[(size_t)i].first, coordinatesZeros[(size_t)i].second);
        }
    }

    void printVector(const std::vector<std::vector<int>>& matrix) const
    {
        for(size_t row = 0; row < matrix.size(); row++)
        {
            for(size_t col = 0; col < matrix[0].size(); col++)
            {
                std::cout << matrix[row][col] << " ";
            }
            std::cout << std::endl;
        } 
        std::cout << std::endl;
    }
};
