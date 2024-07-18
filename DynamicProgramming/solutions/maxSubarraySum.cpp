int maxSubarraySum(vector<int>& arr, int len) {
    int ans = INT_MIN, cur = 0;

    for (int i = 0; i < len; i++) {
        cur = cur + arr[i];
        if (ans < cur)
            ans = cur;

        if (cur < 0)
            cur = 0;
    }

    return ans;
}
