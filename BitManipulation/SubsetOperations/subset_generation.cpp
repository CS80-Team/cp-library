void subsetGeneration(int x, int n) {
    // Generate all non-empty subsets of a set represented by an integer x
    for (int subset = x; subset > 0; subset = (subset - 1) & x) {
        // Process subset
        cout << subset << endl;
    }
}
