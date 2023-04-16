// Core.cpp : Defines the entry point for the application.

#include "Core.h"

#include <tbb/tbb.h>

#include <iostream>

int main() {
    // Input array of numbers
    int nums[] = { 1, 2, 3, 4, 5 };

    // Number of elements in the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Parallel loop using oneTBB
    tbb::parallel_for(0, n, [&](int i) {
        nums[i] = nums[i] * nums[i]; // Square each element
        });

    // Output the squared numbers
    std::cout << "Squared numbers: ";
    for (int i = 0; i < n; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
