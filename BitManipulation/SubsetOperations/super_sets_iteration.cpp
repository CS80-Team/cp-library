void iterateOverSupersets(int x, int n) {
    // Iterate over all supersets of a set represented by x
    int subset = x;
    do {
        // Process subset
        cout << subset << endl;
        subset = (subset + 1) | x;
    } while (subset <= (1 << n) - 1);
}
