#include "../include/LE_system.hpp"
#include "catch_amalgamated.hpp"

TEST_CASE("swap little endian to big endian [by pointer]") {
    SECTION("When all bytes are different values") {
        uint32_t value = 0xABCDEF12;
        uint32_t expected_value = 0x12EFCDAB;

        swap_LE_BE_by_pointer(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When all bytes are same value") {
        uint32_t value = 0xFFFFFFFF;
        uint32_t expected_value = 0xFFFFFFFF;

        swap_LE_BE_by_pointer(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When first and last bytes are same value") {
        uint32_t value = 0xFF12CDFF;
        uint32_t expected_value = 0xFFCD12FF;

        swap_LE_BE_by_pointer(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When first and last two bytes are same value") {
        uint32_t value = 0xFFFD1FFF;
        uint32_t expected_value = 0xFF1FFDFF;

        swap_LE_BE_by_pointer(value);

        REQUIRE(value == expected_value);
    }
}

TEST_CASE("swap little endian to big endian [by bitwise]") {
    SECTION("When all bytes are different values") {
        uint32_t value = 0xABCDEF12;
        uint32_t expected_value = 0x12EFCDAB;

        swap_LE_BE_by_bitwise(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When all bytes are same value") {
        uint32_t value = 0xFFFFFFFF;
        uint32_t expected_value = 0xFFFFFFFF;

        swap_LE_BE_by_bitwise(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When first and last bytes are same value") {
        uint32_t value = 0xFF12CDFF;
        uint32_t expected_value = 0xFFCD12FF;

        swap_LE_BE_by_bitwise(value);

        REQUIRE(value == expected_value);
    }
    SECTION("When first and last two bytes are same value") {
        uint32_t value = 0xFFFD1FFF;
        uint32_t expected_value = 0xFF1FFDFF;

        swap_LE_BE_by_bitwise(value);

        REQUIRE(value == expected_value);
    }
}
