struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

struct Rectangle {
    Point bottomLeft, topRight;
};

const double PI = acos(-1.0);

bool point_inside_circle(const Point &p, const Circle &c) {
    double dx = p.x - c.center.x;
    double dy = p.y - c.center.y;
    return (dx * dx + dy * dy) <= (c.radius * c.radius);
}



double rect_area(const Rectangle &rect) {
    return (rect.topRight.x - rect.bottomLeft.x) * (rect.topRight.y - rect.bottomLeft.y);
}

bool rect_in_circle(const Circle &circle, const Rectangle &rect) {
    vector<Point> corners = {
        rect.bottomLeft,
        {rect.topRight.x, rect.bottomLeft.y},
        rect.topRight,
        {rect.bottomLeft.x, rect.topRight.y}
    };
    for (const auto &corner : corners) {
        if (!isPointInsideCircle(corner, circle)) {
            return false;
        }
    }
    return true;
}

bool circle_in_rect(const Circle &circle, const Rectangle &rect) {
 return circle.center.x - circle.radius >= rect.bottomLeft.x &&
           circle.center.x + circle.radius <= rect.topRight.x &&
           circle.center.y - circle.radius >= rect.bottomLeft.y &&
           circle.center.y + circle.radius <= rect.topRight.y;
}


double intersection(const Circle &circle, const Rectangle &rect) {
    if (rect_in_circle(circle, rect)) {
        return rect_area(rect);
    }

    if (circle_in_rect(circle, rect)) {
        return PI * circle.radius * circle.radius;
    }

    double intersectionArea = 0.0;
    double dx1 = max(rect.bottomLeft.x, circle.center.x - circle.radius);
    double dx2 = min(rect.topRight.x, circle.center.x + circle.radius);
    double dy1 = max(rect.bottomLeft.y, circle.center.y - circle.radius);
    double dy2 = min(rect.topRight.y, circle.center.y + circle.radius);

    for (double x = dx1; x < dx2; x += 0.001) {
        for (double y = dy1; y < dy2; y += 0.001) {
            Point p = {x, y};
            if (point_inside_circle(p, circle)) {
                intersectionArea += 0.001 * 0.001;
            }
        }
    }

    return intersectionArea;
}
