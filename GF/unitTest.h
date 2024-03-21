//
// Created by 10073 on 2024/3/20.
//

#ifndef GROUP_PROJECT_UNITTEST_H
#define GROUP_PROJECT_UNITTEST_H
#include "randomNumber.h" //include the path
#include <cassert>
#include <iostream>
#include <numeric>


namespace GE_RANDOM_NUMBER {

    void test1_RandomIntegersNormalDist() {//Generated the non-zero vector
        auto numbers = RandomIntegersNormalDist(10000, 0, 1);
        assert(!numbers.empty()); // The result should not be empty
    }

    void test2_RandomIntegersNormalDist() { //Generated the large sample and the mean is close to 0.
        auto numbers = RandomIntegersNormalDist(10000, 0, 1);
        long long sum = std::accumulate(numbers.begin(), numbers.end(), 0LL);
        double mean = static_cast<double>(sum) / static_cast<double>(numbers.size());
        assert(std::abs(mean) < 0.1); // Expect the mean to be close to 0
    }

    void test1_RandomFloatsUniformDist() { // Generated the non-zero vector
        auto floats = RandomFloatsUniformDist(10000, 0.0f, 1.0f);
        assert(!floats.empty()); // The result should not be empty
    }

    void test2_RandomFloatsUniformDist() { //Test random number in specific range.
        auto floats = RandomFloatsUniformDist(10000, 0.0f, 1.0f);
        for (float f : floats) {
            assert(f >= 0.0f && f <= 1.0f);
        }
    }
    void test1_HistogramData() { // Test with a known distribution
        std::vector<int> data(100, 1); // 100 times the number 1
        auto histogram = HistogramData(data, 1, 1, 1); // Single bin
        assert(histogram.size() == 1 && histogram[0] == 100); // All values should fall into the single bin
    }

    void test2_HistogramData() {  // Test with empty input data
        std::vector<int> data;
        auto histogram = HistogramData(data, 0, 10, 5);
        assert(histogram.size() == 5);
        for (int bin : histogram) {
            assert(bin == 0); // Each bin should be empty
        }
    }

    void test1_printHistogram() {
        std::cout << "Manual test for printHistogram: Please check out the output for correctness.\n";
        auto histogramData = std::vector<int>{1, 2, 3};
        printHistogram(histogramData, '*');
    }

    void test2_printHistogram() {
        std::cout << "Manual test for printHistogram: Testing with empty histogram data.\n";
        auto histogramData = std::vector<int>{};
        printHistogram(histogramData, '*');
    }
    //this function will test if the array is correctly split around a pivot point
    //input: a vector, a pivotIndex, and comparison
    //output: a boolean true or false depending on if it is correctly sorted
    template<typename T, typename Compare>
    bool test1_Partition(const std::vector<T>& arr, int pivotIndex, Compare comp){
        for(int i = 0; i < pivotIndex; ++i){	//loop through elements before the pivotIndex
            if(comp(arr[i], arr[pivotIndex])){	//check if any element before pivot is greater than pivot
                return false;
            }

        }
        //looping through elements after the pivot point
        for(size_t i = pivotIndex + 1; i < arr.size(); ++i ){
            //check elements after pivot index
            if(comp(arr[pivotIndex], arr[i])){	//check if any element is less that pivot index
                return false;
            }

        }
        return true;	//if both checks dont return false, then return true
    }
//This function checks if the selected pivot index is corerectly within range
//input: none
//output: boolean true or false
    bool test2_Partition(){
        std::vector<int> arr = {1,2,3,4,5,6,7,8,9};

        //partition array to get pivot
        int pivotIndex = GE_RANDOM_NUMBER::partition(arr, 0, static_cast<int>(arr.size()) - 1, std::less<int>());

        //checking if pivot index is within range
        if(pivotIndex < 0 || pivotIndex >= static_cast<int>(arr.size())) {
            return false;
        }
        //if index is within range return true
        return true;
    }

    template<typename T, typename Compare>
    void test_1quickSort(){
        std::vector<T> data = {2,4,6,7,7};
        quickSort(data, 0, data.size() - 1, std:: less <int>());
        assert(quicksort(data, std::less <int> ()));
    }

    template<typename T, typename Compare>
    void test_2quickSort(){
        std::vector<T> data = {0, 2, 6, 9, 12};
        quickSort(data, 0, data.size() - 1, std::less <int>());
        assert(quicksort(data, std:: less <int>()));
    }
}

#endif //GROUP_PROJECT_UNITTEST_H
