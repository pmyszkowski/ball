#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Ball {
    double _a, _h, _v, _delta_t;

public:
    Ball(double a, double h, double delta_t);
    void save_to_csv();
};

Ball::Ball(double a, double h, double delta_t) {
        _a = a;
        _h = h;
        _delta_t = delta_t;
}

void Ball::save_to_csv() {
    double t = 0;
    double v = 0;
    double h = _h;

    std::ofstream file;
    file.open("result.csv");
    file.clear();

    // save 1st line
    file << "a, h, v, t" << std::endl;
    file << _a << "," << h << "," << v << "," << t << std::endl;

    // while the ball is in the air
    while (h > 0) {
        // calculate values
        h -= v * _delta_t + 0.5 * _a * _delta_t * _delta_t;
        v += _a * _delta_t;
        t += _delta_t;

        // check if we hit the ground
        h = std::max(0.0, h); 
        if (h == 0.0) { v = 0; }

        file << _a << "," << h << "," << v << "," << t << std::endl;
    }
    file.close();
}