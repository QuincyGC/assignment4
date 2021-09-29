//
//  sort.h
//  
//  Functions for bubble sort, selection sort, and insertion sort.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm> // for swap()

using namespace std;

namespace csi281 {

    // Performs an in-place ascending sort of *array* of size *length*
    // using the bubble sort algorithm
    template <typename T>
    void bubbleSort(T array[], const int length) {
        // YOUR CODE HERE
        //https://www.geeksforgeeks.org/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

        bool notSwapped = true;

        for (int i = 0; i < (length - 1); i++)
        {
            notSwapped = true;//make sure it gets reset to true

            for (int j = 0; j < (length - i); j++)
            {
                //if first is larger than next
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);//first is now next and vise versa
                    notSwapped = false;
                }
            }
            //if the array did not swap
            if (notSwapped)
            {
                break;
            }
        }
    }

    // Performs an in-place ascending sort of *array* of size *length*
    // using the selection sort algorithm
    template <typename T>
    void selectionSort(T array[], const int length) {
        // YOUR CODE HERE
        //https://www.geeksforgeeks.org/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

        int min = 0;

        for (int i = 0; i < (length - 1); i++)
        {
            min = i;

            //j starts one after i
            for (int j = (i + 1); j < length; j++)
            {
                if (array[j] < array[min])
                {
                    min = j;//min is now the now the selected array position with the current smallest value
                }
            }

            //if the min location is not what it was before
            if (min != i)
            {
                //make min knew smallest element
                swap(array[i], array[min]);
            }
        }
    }

    // Performs an in-place ascending sort of *array* of size *length*
    // using the insertion sort algorithm
    template <typename T>
    void insertionSort(T array[], const int length) {
        // YOUR CODE HERE
        //https://www.geeksforgeeks.org/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

        int insert = 0;
        T item;//any type of item

        //
        for (int i = 1; i < length; i++)
        {
            insert = i;
            item = array[i];
            int j = i - 1;

            while (j >= 0 && item < array[j])
            {
                array[j + 1] = array[j];
                j--;
            }

            insert = j + 1;
            array[insert] = item;
        }
    }
}


#endif /* sort_hpp */


