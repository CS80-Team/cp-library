// O(n + b), where n is the number of elements and b is the base of the number system
// A function to do counting sort of arr[] according to the digit represented by exp.
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr now
    // contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int mx = *max_element(arr.begin(), arr.end());

    // Do counting sort for every digit. Note that instead
    // of passing the digit number, exp is passed. exp is 10^i
    // where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}
