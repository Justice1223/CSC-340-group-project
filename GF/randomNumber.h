//
// Created by Carter on 2024/3/15.
//

#ifndef GROUP_PROJECT_RANDOMNUMBER_H
#define GROUP_PROJECT_RANDOMNUMBER_H
#include <vector>
#include <functional>

namespace GE_RANDOM_NUMBER {

// Function prototypes for generating random numbers
    std::vector<int> RandomIntegersNormalDist(int count, double mean, double stddev);

    std::vector<float> RandomFloatsUniformDist(int count, float lowerBound, float upperBound);

// Function prototype for calculating histogram data
    std::vector<int> HistogramData(const std::vector<int> &data, int min, int max, int bins);

// Function prototype for printing out a histogram
    void printHistogram(const std::vector<int> &histogramData, char symbol);

// Function prototype for partition
    template<typename T, typename Compare>
    int partition(std::vector<T> &arr, int left, int right, Compare comp);

// Function prototype for quickSort algorithm
    template<typename T, typename Compare>
    void quickSort(std::vector<T> &arr, int left, int right, Compare comp);

    template<typename T, typename Comparator>
    T kthRanked(std::vector<T> &arr, int left, int right, int k, Comparator cmp);
}
#endif //GROUP_PROJECT_RANDOMNUMBER_H
