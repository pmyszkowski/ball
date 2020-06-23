#include <iostream>
#include "Ball.cpp"

int main(int argc, char* argv[]) {
    Ball ball = Ball(1, 50, 1);
    ball.save_to_csv();
}