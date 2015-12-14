#include <bits/stdc++.h>
using namespace std;

typedef double Real;
typedef conplex<Real> Point;

struct Line {
    Point a,b;
};

const Real EPS = 10e-8;

double point_dist(point a,point b=Point(0,0)) {
    return abs(a-b);
}
