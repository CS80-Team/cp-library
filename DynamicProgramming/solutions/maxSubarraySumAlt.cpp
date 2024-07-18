/* REF: GeeksForGeeks
	Input: arr[] = {-4, -10, 3, 5}
	Output: 9
	Explanation: Subarray {arr[0], arr[2]} = {-4, -10, 3}. Therefore, the sum of this subarray is 9.
*/
int maxSubarraySumALT(vector<int>& a, int len) {
    int ans = INT_MIN, cur = 0;
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0)
            cur = max(cur + a[i], a[i]);
        else
            cur = max(cur - a[i], -a[i]);
 
        ans = max(ans, cur);
    }
 
    cur = 0;
 
    for (int i = 0; i < len; i++) {
        if (i % 2 == 1)
            cur = max(cur + a[i], a[i]);
        else
            cur = max(cur - a[i], -a[i]);
 
        ans = max(ans, cur);
    }
	
    return ans;
}
