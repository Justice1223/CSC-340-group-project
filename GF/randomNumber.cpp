//
// Created by Carter on 2024/3/15.
//
#include "randomNumber.h"
#include <random>
#include <iostream>
#include <algorithm>


namespace GE_RANDOM_NUMBER {


//Implementation for generating random integers with normal distribution
    std::vector<int> RandomIntegersNormalDist(int count, double mean, double stddev) {
        std::random_device rd;// Obtain a random number from hardware
        std::mt19937 gen(rd()); // Generate seed value
        std::normal_distribution<> d(mean, stddev);// Defines a normal distribution with mean and standard deviation.


        std::vector<int> numbers(count); // Creates a vector to store the generated numbers, with the size specified by count.
        for (int &number: numbers) { // Iterates over each element in the vector.
            number = static_cast<int>(d(gen)); // Generates a number from the normal distribution and assigns it to the current vector element, converting it to an int.
        }
        return numbers; // Returns the vector of generated numbers.
    }

//Implementation for generating random float with normal distribution
    std::vector<float> RandomFloatsUniformDist(int count, float lowerBound, float upperBound) {
        std::random_device rd;  // Obtain a random number from hardware
        std::mt19937 gen(rd()); // Generate seed value
        std::uniform_real_distribution<> distribution(lowerBound, upperBound); // Define the range

        std::vector<float> numbers(count);
        for (float &number: numbers) {// Iterates each element in the vector
            number = distribution(gen); // Generate a random float within the specified range NOLINT(*-narrowing-conversions)
        }
        return numbers;// Returns the vector of generated numbers.
    }

// Implementation for calculating histogram data
    std::vector<int> HistogramData(const std::vector<int> &data, int min, int max, int bins) {
        std::vector<int> histogram(bins,0); // Initializes a histogram vector with a specified number of bins, set them to 0.
        int binSize = (max - min) / bins; // Calculates the size of each bin.

        for (int number: data) { // Iterates over each number in the input data vector.
            int index = (number - min) / binSize; // Determines the bin index for the current number.
            if (index >= 0 && index < bins) { // Checks if the index is within the range of bins.
                ++histogram[index]; // Increments the count in the corresponding bin.
            }
        }
        return histogram; // Returns the populated histogram vector.
    }


// Implementation for printing a histogram
    void printHistogram(const std::vector<int> &histogramData, char symbol) {
        for (int bin: histogramData) {
            for (int i = 0; i < bin; ++i) {
                std::cout << symbol;
            }
            std::cout << std::endl;
        }
    }

    template<typename T, typename Compare>
    int partition(std::vector<T> &arr, int left, int right, Compare comp) {
        std::random_device rd; //Obtain random number from hardware.
        std::mt19937 gen(rd()); // Generate seed value
        std::uniform_int_distribution<> distrib(left, right); // Distribution in range [left, right]

        int pivotIndex = distrib(gen); // Randomly select pivot index
        T pivotValue = arr[pivotIndex]; // Assign pivot value
        std::swap(arr[pivotIndex], arr[right]); // Move pivot element to the end
        int partitionIndex = left; // Initialize partition index to leftmost

        for (int i = left; i < right; i++) {
            if (comp(arr[i], pivotValue)) { // If current element is less than pivot based on comparison
                std::swap(arr[i], arr[partitionIndex]);
                partitionIndex++;
            }
        }
        std::swap(arr[partitionIndex], arr[right]); // Move pivot to its final place

        return partitionIndex; // Return the partition index
    }

    template<typename T, typename Compare>
    void quickSort(std::vector<T> &arr, int left, int right, Compare comp) {
        if (left < right) {    // Base condition: if the current segment has more than one element
            int pivotIndex = partition(arr, left, right, comp); // Partition the array segment around a pivot element
            quickSort(arr, left, pivotIndex - 1,comp); // Recursively apply the same logic to the sub-array of elements that to the left
            quickSort(arr, pivotIndex + 1, right, comp);// Recursively apply the same logic to the sub-array of elements that to the right
        }
    }

    template<typename T, typename Comparator>
    T kthRanked(std::vector<T> &arr, int left, int right, int k, Comparator cmp) {
        if (left == right) // Base case: If the array contains only one element
            return arr[left];

        // Partition the array and get the index of the pivot element
        int pivotIndex = partition(arr, left, right, cmp);

        // Number of elements in the left partition
        int numLeft = pivotIndex - left + 1;

        if (k == numLeft) // If the pivot is the k-th ranked element
            return arr[pivotIndex];
        else if (k < numLeft) // If k-th ranked element lies in the left partition
            return kthRanked(arr, left, pivotIndex - 1, k, cmp);
        else // If k-th ranked element lies in the right partition
            return kthRanked(arr, pivotIndex + 1, right, k - numLeft, cmp);
    }
}
