# DAA_Parallel_Merge_Sort

Sequential and Parallel Merge Sort Performance Comparison using OpenMP

## Problem Statement

Develop sequential and parallel implementations of Merge Sort and compare their performance for increasingly large datasets.

## Objective

The objective of this project is to implement Merge Sort using both sequential and parallel approaches and compare their performance based on execution time, speedup, parallel efficiency, input size, and number of threads.

## Technologies Used

- C Programming
- OpenMP
- GCC Compiler
- Visual Studio Code

## Project Components

### 1. Sequential Merge Sort

The sequential implementation uses the standard Divide and Conquer approach of Merge Sort.

File: `sequential_merge_sort.c`

### 2. Parallel Merge Sort

The parallel implementation uses OpenMP tasks to process the two halves of the array concurrently.

File: `parallel_merge_sort.c`

### 3. OpenMP Test

An OpenMP test program is included to verify the OpenMP environment and display the number of available threads.

File: `openmp_test.c`

## Algorithm

Merge Sort follows the Divide and Conquer approach:

1. Divide the array into two halves.
2. Recursively sort the two halves.
3. Merge the sorted halves.
4. Continue until the complete array is sorted.

In the parallel implementation, the two halves can be processed concurrently using OpenMP tasks.

## Compilation

### Sequential Merge Sort

gcc sequential_merge_sort.c -o sequential_merge_sort.exe -fopenmp

### Parallel Merge Sort

gcc parallel_merge_sort.c -o parallel_merge_sort.exe -fopenmp

### OpenMP Test

gcc openmp_test.c -o openmp_test.exe -fopenmp

## Execution

### Run Sequential Merge Sort

sequential_merge_sort.exe

### Run Parallel Merge Sort

parallel_merge_sort.exe

### Run OpenMP Test

openmp_test.exe

## Correctness Verification

Both sequential and parallel implementations verify whether the final array is sorted correctly.

The output confirms the correctness of the implementation after sorting.

## Performance Evaluation

The performance of sequential and parallel Merge Sort is evaluated using:

- Execution time
- Increasing input sizes
- Different thread counts
- Speedup
- Parallel efficiency

The experimental data is stored in the following CSV files:

- `input_size_scaling.csv`
- `thread_scaling.csv`

## Performance Metrics

### Speedup

Speedup is calculated using:

Speedup = Sequential Execution Time / Parallel Execution Time

### Parallel Efficiency

Parallel efficiency is calculated using:

Parallel Efficiency = (Speedup / Number of Threads) × 100

## Input Size Scaling

The input-size experiment compares the execution time of Merge Sort for increasingly large datasets.

The results are stored in:

`input_size_scaling.csv`

## Thread Scaling

The thread-scaling experiment evaluates the performance of the parallel implementation using different numbers of threads.

The results are stored in:

`thread_scaling.csv`

## Performance Analysis

The performance results will be analyzed by comparing sequential and parallel execution times for different input sizes and thread configurations.

The analysis will also consider the effect of increasing the number of threads, parallel overhead, and possible performance bottlenecks.

## Team Members

- Nandani Waghmare 
- Ruchita Telang 
- Anchal Parteki

## Project Type

DAA Mini Project
