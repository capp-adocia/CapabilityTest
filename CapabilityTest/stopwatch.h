#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <chrono>
#include <string>

class Stopwatch {
public:
    using tick_t = std::chrono::microseconds;

    explicit Stopwatch(const std::string& activity = "Stopwatch", bool start = true)
        : m_activity(activity), m_lap(0), m_started(false) {
        if (start) {
            Start();
        }
    }

    ~Stopwatch() {
        if (m_started) {
            Stop();
        }
    }

    void Start() {
        if (!m_started) {
            m_startTime = std::chrono::steady_clock::now();
            m_started = true;
            std::cout << m_activity << ": start" << std::endl;
        }
        else {
            std::cout << m_activity << ": already started" << std::endl;
        }
    }

    tick_t Stop() {
        if (m_started) {
            auto endTime = std::chrono::steady_clock::now();
            m_lap = std::chrono::duration_cast<tick_t>(endTime - m_startTime);
            std::cout << m_activity << ": stop " << GetMs(m_lap) << " ms" << std::endl;
            m_started = false;
        }
        else {
            std::cout << m_activity << ": not started" << std::endl;
        }
        return m_lap;
    }

    tick_t LapGet() const {
        return m_lap;
    }

    bool IsStarted() const {
        return m_started;
    }

private:
    std::string m_activity;
    tick_t m_lap;
    std::chrono::steady_clock::time_point m_startTime;
    bool m_started;

    long GetMs(tick_t t) const {
        return t.count() / 1000;
    }
};

#endif // STOPWATCH_H
