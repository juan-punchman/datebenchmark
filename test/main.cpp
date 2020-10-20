#include <gtest/gtest.h>
#include <fmt/format.h>

int main(int argc, char **argv)
{
    fmt::print(
#if USE_OS_TZDB
        "USE_OS_TZDB: ON"
#else
        "USE_OS_TZDB: OFF"
#endif
        "\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
