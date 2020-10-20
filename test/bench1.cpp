#include <regex>
#include <gtest/gtest.h>

#include <date/date.h>
#include <date/tz.h>
#include <date/tz_private.h>

#include <fmt/format.h>

#include "StopWatch.h" // hack for now, need to tidy up cmake setup



// [ RUN      ] date.bench1
// lookup: every call: time used 1230945 us
// lookup: once      : time used 757349 us
// [       OK ] date.bench1 (1989 ms)
//
// using internal tz db
// [ RUN      ] date.bench1
// lookup: every call: time used 31581 us
// lookup: once      : time used 16827 us
// [       OK ] date.bench1 (48 ms)

TEST( date, bench1 )
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
        auto tpUTC = std::chrono::system_clock::now();
        // auto        tpUTC = sys_time<nanoseconds>( 123456789LL );    // some time point
        auto const* tz = date::locate_zone( "America/New_York" ); // locate the timezone once

        fmt::print( "locate_zone: time used {} us\n", sw.elapsedUs() );
        sw.restart();
        for( int i = 0; i != n; ++i )
        {
            auto const zt  = make_zoned( tz, tpUTC );
            auto const tp  = zt.get_local_time(); // expensive call
            auto const dp  = floor<days>( tp );
            auto const ymd = year_month_day( dp );
        }
    }
    fmt::print( "lookup: every call: time used {} us\n", sw.elapsedUs() );
    sw.restart();

    // should be way faster
    {
        auto tpUTC = std::chrono::system_clock::now();
        // auto tpUTC = sys_time<nanoseconds>( 123456789LL );

        for( int i = 0; i != n; ++i )
        {
            const std::string zone = "America/New_York";
            auto const zt  = make_zoned( zone, tpUTC ); // locate the timezone every time
            auto const tp  = zt.get_local_time();
            auto const dp  = floor<days>( tp );
            auto const ymd = year_month_day( dp );
        }
    }
    fmt::print( "lookup: once      : time used {} us\n", sw.elapsedUs() );
}
