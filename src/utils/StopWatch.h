#pragma once

#include <chrono>
#include <iostream>
#include <string>


class StopWatch
{
  public:
    typedef std::chrono::steady_clock clock;
    typedef std::chrono::microseconds microseconds;
    typedef std::chrono::milliseconds milliseconds;
    typedef std::chrono::seconds      seconds;

    StopWatch();
    StopWatch( const StopWatch& );
    StopWatch& operator=( const StopWatch& rhs );

    uint64_t elapsedUs() const;
    uint64_t elapsedMs() const;
    uint64_t elapsedSec() const;

    std::chrono::steady_clock::time_point restart();

  private:
    clock::time_point mStart;
};

