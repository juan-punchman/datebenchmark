/*
 * Timer.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: Jiri
 */

#include "utils/StopWatch.h"


StopWatch::StopWatch()
: mStart( clock::now() )
{
    static_assert( std::chrono::steady_clock::is_steady, "Serious OS/C++ library issues. Steady clock is not steady" );
    // FYI:  This would fail  static_assert(std::chrono::high_resolution_clock::is_steady(), "High Resolution Clock is NOT steady on CentOS?!");
}

StopWatch::StopWatch( const StopWatch& other )
: mStart( other.mStart )
{
}

StopWatch& StopWatch::operator=( const StopWatch& rhs )
{
    mStart = rhs.mStart;
    return *this;
}

uint64_t StopWatch::elapsedUs() const
{
    return std::chrono::duration_cast<microseconds>( clock::now() - mStart ).count();
}

uint64_t StopWatch::elapsedMs() const
{
    return std::chrono::duration_cast<milliseconds>( clock::now() - mStart ).count();
}

uint64_t StopWatch::elapsedSec() const
{
    return std::chrono::duration_cast<seconds>( clock::now() - mStart ).count();
}

std::chrono::steady_clock::time_point StopWatch::restart()
{
    mStart = clock::now();
    return mStart;
}

