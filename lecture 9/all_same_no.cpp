#include <iostream>

int main() {
    const int size = 10;

    // Initialize a 1D array with 10 elements all set to 1
    int array[size];
    std::fill_n(array, size, 1);

    // Print the 1D array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    const int rows = 3;
    const int cols = 3;

    // Initialize a 2D array (3x3) with all elements set to 1
    int array_2d[rows][cols];
    for (int i = 0; i < rows; ++i) {
        std::fill_n(array_2d[i], cols, 1);
    }

    // Print the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array_2d[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
