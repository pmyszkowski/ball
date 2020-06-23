#include <iostream>
#include "Ball.cpp"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " --height HEIGHT" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "--height") {
        char* p;
        double h = strtod(argv[2], &p);
        
        if (*p) { 
            std::cerr << "--height parameter must be a number!" << std::endl;
            std::cerr << "Usage: " << argv[0] << " --height HEIGHT" << std::endl;
            return 1;
        }
        else {
            // values 
            double a = 2.0;
            double t = 0.1;
            Ball ball = Ball(a, h, t);
            ball.save_to_csv();
        }     
    } 
    else {
        std::cerr << "Usage: " << argv[0] << " --height HEIGHT" << std::endl;
        return 1;
    }  
}