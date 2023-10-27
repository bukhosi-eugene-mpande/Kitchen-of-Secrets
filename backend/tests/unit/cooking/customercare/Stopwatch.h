#ifndef Stopwatch_H
#define Stopwatch_H

#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

class Stopwatch {
    public:
        Stopwatch(std::chrono::milliseconds interval, std::function<void()> callback);

        ~Stopwatch();

        void start();

        void stop();

    private:
        std::chrono::milliseconds interval_;
        std::function<void()> callback_;
        bool running_;
};

#endif