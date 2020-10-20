#include <gtest/gtest.h>

#include <date/date.h>

#include <fmt/format.h>

#include "StopWatch.h" // hack for now, need to tidy up cmake setup


// https://howardhinnant.github.io/date/date.html#Overview
std::chrono::hours
utc_offset_Eastern_US(std::chrono::system_clock::time_point tp)
{
    using namespace date;
    using namespace std::chrono;

#if __cplusplus / 100 >= 2017
    using days = date::days;
    using sys_days = date::sys_days;
#endif

    constexpr auto EST = hours(-5);
    constexpr auto EDT = hours(-4);
    const auto y = year_month_day{floor<days>(tp)}.year();
    const auto begin = sys_days{Sunday[2]/March/y} + hours(2) - EST; // EDT begins at this UTC time
    const auto end   = sys_days{Sunday[1]/November/y} + hours(2) - EDT; // EST begins at this UTC time
    if (tp < begin || end <= tp)
        return EST;
    return EDT;
}


TEST( date, bench2 )
{
    using namespace std::chrono;
    using namespace date;

#if __cplusplus / 100 >= 2017
    using days = date::days;
    using sys_days = date::sys_days;
#endif

    int n = 10000;

    auto sw = StopWatch();

    // lookup for every call in tz db,,,
    {
        for (int i = 0; i != n; ++i) {
            auto tp = system_clock::now();
            tp += utc_offset_Eastern_US(tp);
            auto const dp  = floor<days>( tp );
            auto const ymd = year_month_day( dp );
        }
    }
    fmt::print( "offset:           : time used {} us\n", sw.elapsedUs() );
    sw.restart();

//    // should be way faster
//    {
//        auto tpUTC = std::chrono::system_clock::now();
//        // auto tpUTC = sys_time<nanoseconds>( 123456789LL );
//
//        for( int i = 0; i != n; ++i )
//        {
//            auto const zt  = make_zoned( "America/New_York", tpUTC ); // locate the timezone every time
//            auto const tp  = zt.get_local_time();
//            auto const dp  = floor<days>( tp );
//            auto const ymd = year_month_day( dp );
//        }
//    }
//    fmt::print( "lookup: once      : time used {} us\n", sw.elapsedUs() );
}
