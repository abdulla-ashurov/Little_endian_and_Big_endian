#include <iostream>
#include "catch_amalgamated.hpp"

bool is_LE_system()
{
    const uint32_t hex_number = 0x61626364;
    const uint8_t *ptr = (const uint8_t *)(&hex_number);

    uint8_t sequence_of_hex_number_value_in_memory[sizeof(uint32_t)] = {0x64, 0x63, 0x62, 0x61};

    for (size_t i = 0; i < sizeof(uint32_t); i++) {
        if (ptr[i] != sequence_of_hex_number_value_in_memory[i])
            return false;
    }

    return true;
}

void swap_LE_BE_by_pointer(uint32_t &value) {
    uint8_t *ptr = (uint8_t *)(&value);

    for (int i = 0, j = sizeof(uint32_t) - 1; i < 2; i++, j--)
        std::swap(ptr[i], ptr[j]);
}

void swap_LE_BE_by_bitwise(uint32_t &value) {
    value = ((value & 0x000000FF) << 24) | 
            ((value & 0x0000FF00) << 8) | 
            ((value & 0x00FF0000) >> 8) |
            ((value & 0xFF000000) >> 24);
}

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

int main()
{
    if (is_LE_system())
        std::cout << "CPU is a little endian" << std::endl;
    else
        std::cout << "CPU is a big endian" << std::endl;

    uint32_t hex_number = 0x61626364;
    std::cout << std::hex;
    std::cout << "hex number is " << hex_number << std::endl;

    swap_LE_BE_by_pointer(hex_number);
    std::cout << "hex number is " << hex_number << std::endl;

    swap_LE_BE_by_bitwise(hex_number);
    std::cout << "hex number is " << hex_number << std::endl;

    return 0;
}