// O(N+M), where N and M are the size of inputArray[] and countArray[]
// The main function that sorts arr[] of size n using Counting Sort
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - minElement]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}
