struct Rectangle {
    int x1, y1; // Bottom-left corner
    int x2, y2; // Top-right corner
};

int intersectionArea(const Rectangle& rect1, const Rectangle& rect2){
    
    int x_left = max(rect1.x1, rect2.x1);
    int y_bottom = max(rect1.y1, rect2.y1);
    int x_right = min(rect1.x2, rect2.x2);
    int y_top = min(rect1.y2, rect2.y2);
    
    int intersection_width = x_right - x_left;
    int intersection_height = y_top - y_bottom;

    if (intersection_width > 0 && intersection_height > 0) {
        return intersection_width * intersection_height;
    }

    return 0;
}
