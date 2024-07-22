double area(int x0, int y0, int r0, int x1, int y1, int r1){
    const double PI = 3.14159265358979323846;
    double rr0 = r0 * r0;
    double rr1 = r1 * r1;
    double d = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    if(d >= r0 + r1){
        return 0;
    }
    double phiAngle = (rr0 + (d * d) - rr1) / (2 * r0 * d);
    double phi = acos(phiAngle) * 2;
    double thetaAngle = (rr1 + (d * d) - rr0) / (2 * r1 * d);
    double theta = acos(thetaAngle) * 2;
    double area1 = 0.5 * theta * rr1 - 0.5 * rr1 * sin(theta);
    double area2 = 0.5 * phi * rr0 - 0.5 * rr0 * sin(phi);
    return area1+area2;
}
