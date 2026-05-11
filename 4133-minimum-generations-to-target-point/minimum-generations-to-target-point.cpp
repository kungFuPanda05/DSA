#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using Point = array<int, 3>;

    struct PointHash {
        size_t operator()(const Point& p) const {
            size_t h1 = hash<int>{}(p[0]);
            size_t h2 = hash<int>{}(p[1]);
            size_t h3 = hash<int>{}(p[2]);

            // Simple hash combine
            size_t seed = h1;
            seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= h3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };

    bool generateNext(unordered_set<Point, PointHash>& points, const Point& target) {
        unordered_set<Point, PointHash> next;
        next.reserve(points.size() * points.size());

        for (const auto& a : points) {
            for (const auto& b : points) {
                Point mid = {
                    (a[0] + b[0]) / 2,
                    (a[1] + b[1]) / 2,
                    (a[2] + b[2]) / 2
                };

                if (mid == target) return true;
                next.insert(mid);
            }
        }

        points = move(next);
        return false;
    }

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        unordered_set<Point, PointHash> ps;

        for (const auto& p : points) {
            ps.insert({p[0], p[1], p[2]});
        }

        Point t = {target[0], target[1], target[2]};

        if (ps.find(t) != ps.end()) return 0;

        for (int gen = 1; gen <= 27; gen++) {
            int prevSize = ps.size();

            if (generateNext(ps, t)) return gen;

            if ((int)ps.size() == prevSize) return -1;
        }

        return -1;
    }
};