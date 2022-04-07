#pragma once

namespace xtool::constant
{
    template <typename FloatType>
    constexpr FloatType Pi = static_cast<FloatType>(3.1415926535897932384626433832795028841971693993751058209749445923);

    template <typename FloatType>
    constexpr FloatType TwoPi = static_cast<FloatType>(Pi<FloatType>*2);

    template <typename FloatType>
    constexpr FloatType HalfPi = static_cast<FloatType>(Pi<FloatType>*0.5);

    template <typename FloatType>
    constexpr FloatType E = static_cast<FloatType>(2.7182818284590452353602874713526624977572470936999595749669676277);
} // namespace xtool::constant
