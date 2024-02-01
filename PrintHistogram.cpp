/*
Not a leetcode problem but one I got in an interview, originaly in C.
Given an array of integers print histogram as shown:

Input:  [1,3,5,2,4,2]

Output:

  #
  # #
 ## # 
 #####
######

*/

#include <iostream>
#include <vector>

void printHistogram(std::vector<int>& values)
{
    for(int row = values.size(); row > 0; row--)
    {
        for(int col = 0; col <= values.size(); col++)
        {
            if(row == values[col])
            {
                std::cout << "#";

                // If column is found continue 
                // searcing for other columns in the same row
                values[col]--; 
            }
            else
            {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }
}