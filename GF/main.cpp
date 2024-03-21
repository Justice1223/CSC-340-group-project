#include "randomNumber.h"
#include "unitTest.h" // include your unit test header file
#include <vector>
#include <functional> // For std::less

    int main() {
        // Call all tests defined in the unittest.h header
        GE_RANDOM_NUMBER::test1_RandomIntegersNormalDist();
        GE_RANDOM_NUMBER::test2_RandomIntegersNormalDist();

        GE_RANDOM_NUMBER::test1_RandomFloatsUniformDist();
        GE_RANDOM_NUMBER::test2_RandomFloatsUniformDist();

        GE_RANDOM_NUMBER::test1_HistogramData();
        GE_RANDOM_NUMBER::test2_HistogramData();

        // For printHistogram, you're supposed to check the output manually.
        GE_RANDOM_NUMBER::test1_printHistogram();
        GE_RANDOM_NUMBER::test2_printHistogram();

        std::vector<int> arr = {9, 3, 6, 1, 8, 5, 2};
        int pivotIndex = GE_RANDOM_NUMBER::partition(arr, 0, static_cast<int>(arr.size()) - 1, std::less<int>());
        if (GE_RANDOM_NUMBER::test1_Partition(arr, pivotIndex, std::less<int>())) {
            std::cout << "The array IS correctly partitioned." << std::endl;
        } else {
            std::cout << "The array IS NOT correctly partitioned." << std::endl;
        }

        if (GE_RANDOM_NUMBER::test2_Partition()) {
            std::cout << "The Test for Pivot index being in range has PASSED." << std::endl;
        } else {
            std::cout << "The Test for Pivot index being in range has FAILED." << std::endl;
        }
        return 0;
    }
