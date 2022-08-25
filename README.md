# Little_endian_and_Big_endian
Little endian and Big endian

## Source code
```cpp
#include <iostream>

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
```
