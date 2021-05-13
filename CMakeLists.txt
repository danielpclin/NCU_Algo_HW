cmake_minimum_required(VERSION 3.17)
project(Algo)

set(CMAKE_CXX_STANDARD 14)

add_executable(AboveAverage hw1/above_average.cpp)
add_executable(OddSumWithoutPrime hw1/odd_sum_without_prime.cpp)
add_executable(PrimeFactor hw1/prime_factor.cpp)

add_executable(EvenSum hw2/even_sum.cpp)
add_executable(GCD hw2/gcd.cpp)
add_executable(WhatIsTheMedian hw2/what_is_the_median.cpp)

add_executable(PerfectNumber hw3/perfect_number.cpp)
add_executable(UglyNumbers hw3/ugly_numbers.cpp)
add_executable(AddThePage hw3/add_the_page.cpp)

add_executable(AgeSort hw4/age_sort.cpp)
add_executable(Fibonacci hw4/fibonacci.cpp)
add_executable(InsertionSort hw4/insertion_sort.cpp)

add_executable(EulerFunction hw5/euler_function.cpp)
add_executable(ProductOfDigits hw5/product_of_digits.cpp)
add_executable(RelationalOperators hw5/relational_operators.cpp)

add_executable(QuickSort hw6/quick_sort.cpp)
add_executable(Queen hw6/queen.cpp)
add_executable(JoanaAndTheOddNumbers hw6/joana_and_the_odd_numbers.cpp)

add_executable(Bricks hw7/bricks.cpp)
add_executable(Packets hw7/packets.cpp)
add_executable(Peter hw7/peter.cpp)