struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

struct Line {
    double slope;
    double intercept;
};

vector<Point> intersect_points(const Circle &circle, const Line &line) {
    vector<Point> intersections;
    
    // solve y = mx + b with (x - h)^2 + (y - k)^2 = r^2
    double h = circle.center.x;
    double k = circle.center.y;
    double r = circle.radius;
    double m = line.slope;
    double b = line.intercept;

    // Quadratic coefficients
    double A = 1 + m * m;
    double B = 2 * (m * b - m * k - h);
    double C = k * k - r * r + h * h - 2 * b * k + b * b;

    // Discriminant
    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0) {
        // No intersection
        return intersections;
    } else if (discriminant == 0) {
        // One intersection (tangent line)
        double x = -B / (2 * A);
        double y = m * x + b;
        intersections.push_back({x, y});
    } else {
        // Two intersections
        double sqrtDiscriminant = sqrt(discriminant);
        double x1 = (-B + sqrtDiscriminant) / (2 * A);
        double y1 = m * x1 + b;
        double x2 = (-B - sqrtDiscriminant) / (2 * A);
        double y2 = m * x2 + b;
        intersections.push_back({x1, y1});
        intersections.push_back({x2, y2});
    }

    return intersections;
}
