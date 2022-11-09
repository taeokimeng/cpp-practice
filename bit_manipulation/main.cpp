#include <bitset>
#include <cstdint>
#include <iostream>

std::bitset<4> rotl(std::bitset<4> bits)
{
    std::bitset<4> bits_check{0b1000};

    // if((bits_check & bits) == 0b1000)
    // {
    //     bits <<= 1;
    //     bits |= 0b0001;
    // }
    // else
    // {
    //     bits <<= 1;
    // }

    // return bits;

    // bits << 1 does the left shift
	// bits >> 3 handle the rotation of the leftmost bit
	return (bits<<1) | (bits>>3);
}

int main()
{
    std::bitset<8> bits{0b0000'0101};
    bits.set(3);
    bits.flip(4);
    bits.reset(4);

    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    std::bitset<4> x {0b1100};
    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n';
    std::cout << (x << 1) << '\n';

    std::cout << ~std::bitset<4>{0b0100} << ' ' << ~std::bitset<8>{0b0100} << '\n';

    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';
    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    constexpr std::uint8_t option_viewed{ 0x01 };
    constexpr std::uint8_t option_edited{ 0x02 };
    constexpr std::uint8_t option_favorited{ 0x04 };
    constexpr std::uint8_t option_shared{ 0x08 };
    constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };

    myArticleFlags |= option_viewed;
    myArticleFlags &= ~option_favorited;

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}