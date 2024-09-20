#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <chrono>
#include <string>

enum class OutputUnit {
    Microseconds, // 微秒
    Milliseconds // 毫秒
};

class Stopwatch {
public:
    using tick_t = std::chrono::microseconds;

    

    explicit Stopwatch(OutputUnit unit = OutputUnit::Milliseconds, const std::string& activity = "Stopwatch", bool start = true)
        : m_activity(activity), m_lap(0), m_started(false), m_unit(unit) {
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
            std::cout << m_activity << ": stop " << GetElapsedTime(m_lap) << " " << GetUnitString() << std::endl;
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
    OutputUnit m_unit;

    long GetElapsedTime(tick_t t) const {
        return (m_unit == OutputUnit::Milliseconds) ? t.count() / 1000 : t.count();
    }

    std::string GetUnitString() const {
        return (m_unit == OutputUnit::Milliseconds) ? "ms" : "um";
    }
};

#endif // STOPWATCH_H
