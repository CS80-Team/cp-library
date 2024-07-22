double shoelace(vector<pair<double, double>> points) {
	double leftSum = 0.0;
	double rightSum = 0.0;

	for (int i = 0; i < points.size(); ++i) {
		int j = (i + 1) % points.size();
		leftSum  += points[i].first * points[j].second;
		rightSum += points[j].first * points[i].second;
	}

	return 0.5 * abs(leftSum - rightSum);
}
