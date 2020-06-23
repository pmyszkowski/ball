#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Ball {
    static int n;

    double _a, _h, _v, _delta_t;
    uint8_t _n;

public:
    Ball(double a, double h, double delta_t);

    void save_to_csv();
};

int Ball::n = 0; 

Ball::Ball(double a, double h, double delta_t) {
        _a = a;
        _h = h;
        _delta_t = delta_t;
        _n = n++;
}

void Ball::save_to_csv() {
    double t = 0;
    double v = 0;
    double h = _h;

    std::ofstream file;
    file.open("result_" + std::to_string(_n));

    // save 1st line
    file << "a, h, v, t" << std::endl;
    file << _a << "," << h << "," << v << "," << t << std::endl;

    while (h > 0) {
        h -= v * _delta_t + 0.5 * _a * _delta_t * _delta_t;
        h = std::max(0.0, h); 
        v += _a * _delta_t;
        t += _delta_t;
        if (h == 0.0) { v = 0; }
        file << _a << "," << h << "," << v << "," << t << std::endl;
    }
}