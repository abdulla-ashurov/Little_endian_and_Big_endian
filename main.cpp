#include <iostream>

bool is_LE_system()
{
    const uint32_t hex_number = 0x61626364;
    const uint8_t *ptr = (const uint8_t *)(&hex_number);

    uint8_t sequence_of_hex_number_in_memory[4] = {0x64, 0x63, 0x62, 0x61};

    for (size_t i = 0; i < sizeof(uint32_t); i++) {
        if (ptr[i] != sequence_of_hex_number_in_memory[i])
            return false;
    }

    return true;
}

void swap_LE_BE_by_pointer(uint32_t& value) {
    uint8_t *ptr = (uint8_t *)(&value);

    for (int i = 0, j = sizeof(uint32_t) - 1; i < 2; i++, j--) {
        uint8_t temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp; // or there i can use std::swap(ptr[i], ptr[j])
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

    return 0;
}