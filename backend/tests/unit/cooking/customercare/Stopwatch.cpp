#include "Stopwatch.h"

Stopwatch::Stopwatch(std::chrono::milliseconds interval, std::function<void()> callback)
    : interval_(interval), callback_(callback), running_(false) {}

Stopwatch::~Stopwatch() {
    stop();
}

void Stopwatch::start() {
    running_ = true;
    std::thread([this]() {
        while (running_) {
            std::this_thread::sleep_for(interval_);
            if (running_) {
                callback_();
            }
        }
    }).detach(); // Detach the thread to run in the background.
}

void Stopwatch::stop() {
    running_ = false;
}