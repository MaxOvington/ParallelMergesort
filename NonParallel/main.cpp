#include <iostream>
#include <vector>

void sortArray(std::vector<int>& array);
void print_vector(std::vector<int>& array);
void combine(std::vector<int>& array, int lo1, int hi1, int lo2, int hi2);
void mergesort(std::vector<int>& array, int lo, int hi);
void sortArray(std::vector<int>& array);

int main() {
    auto size = 0;
    std::cin >> size;
    std::vector<int> array = std::vector<int>(size);
    for (int i = 0; i < array.size(); i++) {
        std::cin >> array[i];
    }
    print_vector(array);
    mergesort(array, 0, array.size());
    print_vector(array);
    return 0;
}

void print_vector(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array.at(i) << " ";
    }
    std::cout << std::endl;
}

void combine(std::vector<int>& array, int lo1, int hi1, int lo2, int hi2) {

    auto temp = std::vector<int>();
    int i = lo1;
    int j = lo2;

    while (i < hi1 && j < hi2) {
        if (array[i] < array[j]) {
            temp.push_back(array[i]);
            i++;
        } else {
            temp.push_back(array[j]);
            j++;
        }
    }

    //merge the remaining parts
    if (i < hi1 && j >= hi2) {
        while (i < hi1) {
            temp.push_back(array[i]);
            i++;
        }
    } else if (i >= hi1 && j < hi2) {
        while (j < hi2) {
            temp.push_back(array[j]);
            j++;
        }
    }

    //set the array segment to the sorted array part
    for (int k = lo1; k < hi2; k++) {
        array[k] = temp[k - lo1];
    }
    return;
}

void mergesort(std::vector<int>& array, int lo, int hi) {
    if (lo == hi || lo > hi || hi - lo <= 1) {
        return;
    }
    int mid = lo + ((hi - lo) / 2);
    mergesort(array, lo, mid);
    mergesort(array, mid, hi);
    combine(array, lo, mid, mid, hi);
    return;
}




