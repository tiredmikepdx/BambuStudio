#include "ArchedOverhang.hpp"
#include "geometry.hpp"       // Includes functions for general geometric operations
#include "segment.hpp"        // Provides Segment and Point definitions
#include <cmath>              // For mathematical operations
#include <vector>             // To manage segments and points

// Calculate the curvature of a given segment
double calculate_curvature(const Segment& segment) {
    // Ensure the segment has enough points to calculate curvature
    if (segment.points.size() < 3) {
        return 0.0;  // Not enough points to determine curvature
    }

    // Choose points along the segment to approximate the curvature
    Point p1 = segment.points.front();
    Point p2 = segment.points[segment.points.size() / 2];
    Point p3 = segment.points.back();

    // Call helper function to calculate curvature using these points
    return calculate_curvature_from_points(p1, p2, p3);
}

// Calculate curvature from three points
double calculate_curvature_from_points(const Point& p1, const Point& p2, const Point& p3) {
    // Calculate distances between points
    double a = distance_between(p1, p2);
    double b = distance_between(p2, p3);
    double c = distance_between(p3, p1);

    // Calculate the semi-perimeter
    double s = (a + b + c) / 2.0;

    // Use Heron's formula to calculate the area of the triangle formed by these three points
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // If the area is zero, the points are collinear
    if (area == 0.0) {
        return 0.0;
    }

    // Calculate the radius of the circumcircle of the triangle
    double radius = (a * b * c) / (4.0 * area);

    // Return the curvature, which is the inverse of the radius
    return 1.0 / radius;
}

// Calculate the distance between two points
double distance_between(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Determine if a segment is an arch based on curvature
bool is_arch_segment(const Segment& segment) {
    // Calculate the curvature of the segment
    double curvature = calculate_curvature(segment);

    // Define a curvature threshold for determining arches
    const double ARCH_CURVATURE_THRESHOLD = 0.005;

    // Return true if the curvature is below the threshold, indicating an arch
    return curvature < ARCH_CURVATURE_THRESHOLD;
}
