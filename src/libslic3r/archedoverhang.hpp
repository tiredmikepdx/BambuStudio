#ifndef ARCHED_OVERHANG_HPP
#define ARCHED_OVERHANG_HPP

#include "segment.hpp"        // Segment definition, likely includes point data
#include <vector>             // To handle vectors used in segments
#include <cmath>              // For math operations like sqrt and pow

// Function prototypes
double calculate_curvature(const Segment& segment);
double calculate_curvature_from_points(const Point& p1, const Point& p2, const Point& p3);
double distance_between(const Point& p1, const Point& p2);
bool is_arch_segment(const Segment& segment);

#endif // ARCHED_OVERHANG_HPP
