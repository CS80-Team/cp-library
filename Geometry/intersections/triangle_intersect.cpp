struct Point {
    double x, y;
};

typedef vector<Point> Polygon;

bool inside(const Point &p, const pair<Point, Point> &edge) {
    Point a = edge.first, b = edge.second;
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x) >= 0;
}
Point compute_intersection(const Point &p1, const Point &p2, const pair<Point, Point> &edge) {
    Point a = edge.first, b = edge.second;
    double A1 = b.y - a.y, B1 = a.x - b.x, C1 = b.x * a.y - a.x * b.y;
    double A2 = p2.y - p1.y, B2 = p1.x - p2.x, C2 = p2.x * p1.y - p1.x * p2.y;
    double det = A1 * B2 - A2 * B1;
    if (det == 0) return {numeric_limits<double>::quiet_NaN(), numeric_limits<double>::quiet_NaN()}; // parallel
    double x = (B1 * C2 - B2 * C1) / det;
    double y = (A2 * C1 - A1 * C2) / det;
    return {x, y};
}

Polygon HodgmanClip(const Polygon &subjectPolygon, const Polygon &clipPolygon) {
    Polygon outputList = subjectPolygon;
    for (size_t i = 0; i < clipPolygon.size(); ++i) {
        Point a = clipPolygon[i];
        Point b = clipPolygon[(i + 1) % clipPolygon.size()];
        Polygon inputList = outputList;
        outputList.clear();
        if (inputList.empty()) break;
        Point s = inputList.back();
        for (const auto &e : inputList) {
            if (inside(e, {a, b})) {
                if (!inside(s, {a, b})) {
                    Point intersection = compute_intersection(s, e, {a, b});
                    if (!std::isnan(intersection.x)) {
                        outputList.push_back(intersection);
                    }
                }
                outputList.push_back(e);
            } else if (inside(s, {a, b})) {
                Point intersection = compute_intersection(s, e, {a, b});
                if (!std::isnan(intersection.x)) {
                    outputList.push_back(intersection);
                }
            }
            s = e;
        }
    }
    return outputList;
}

// area of polygon
double shoelace(const Polygon &vertices) {
    double area = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % vertices.size()];
        area += p1.x * p2.y - p2.x * p1.y;
    }
    return fabs(area) / 2.0;
}
