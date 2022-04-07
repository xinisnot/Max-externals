#pragma once
#include <cmath>


namespace xtool::calc::cent
{

    template <typename FloatType>
    FloatType cent2ratio(FloatType x)
    {
        return exp(log(2)*x/1200);
    }

    template <typename FloatType>
    FloatType ratio2cent(FloatType x)
    {
        return 1200 * log2(x);
    }
} // namespace xtool::calc


namespace xtool::calc::scale
{
    template <typename FloatType>
    FloatType scaleB2U(FloatType x)
    {
        return (x+1) * 0.5;
    }

    template <typename FloatType>
    FloatType scaleU2B(FloatType x)
    {
        return x*2 - 1;
    }

    template <typename FloatType>
    FloatType scaleU2X(FloatType x, FloatType yFrom, FloatType yTo)
    {
        return x*(yTo-yFrom) + yFrom;
    }

    template <typename FloatType>
    FloatType scaleX2U(FloatType x, FloatType xFrom, FloatType xTo)
        {
            return (x-xFrom) / (xTo-xFrom);
        }

    template <typename FloatType>
    FloatType scaleB2X(FloatType x, FloatType yFrom, FloatType yTo)
        {
            return scaleU2X<FloatType>(scaleB2U<FloatType>(x), yFrom, yTo);
        }

    template <typename FloatType>
    FloatType scaleX2B(FloatType x, FloatType xFrom, FloatType xTo)
        {
            return (x-xFrom) / (xTo-xFrom) * 2 - 1;
        }

    template <typename FloatType>
    FloatType scaleX2Y(FloatType x, FloatType xFrom, FloatType xTo, FloatType yFrom, FloatType yTo)
        {
            return scaleU2X(scaleX2U<FloatType>(x, xFrom, xTo), yFrom, yTo);
        }
} // namespace xtool::calc::scale