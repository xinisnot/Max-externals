#pragma once

#include <cmath>

namespace xtool
{
//==============================================================================
// Scale value.

template <typename FloatType>
class Scale
{
public:
    void setXFrom(FloatType v)
    {
        xFrom = v;
    }

    void setXTo(FloatType v)
    {
        xTo = v;
    }

    void setYFrom(FloatType v)
    {
        yFrom = v;
    }

    void setYTo(FloatType v)
    {
        yTo = v;
    }

    FloatType scaleB2U(FloatType x)
    {
        return (x+1) * 0.5;
    }

    FloatType scaleU2B(FloatType x)
    {
        return x*2 - 1;
    }

    FloatType scaleU2Y(FloatType x)
    {
        return x*(yTo-yFrom) + yFrom;
    }

    FloatType scaleX2U(FloatType x)
    {
        return (x-xFrom) / (xTo-xFrom);
    }

    FloatType scaleB2Y(FloatType x)
    {
        return scaleU2Y(scaleB2U(x), yFrom, yTo);
    }

    FloatType scaleX2B(FloatType x)
    {
        return (x-xFrom) / (xTo-xFrom) * 2 - 1;
    }

    FloatType scaleX2Y(FloatType x)
    {
        return scaleU2Y(scaleX2U(x));
    }

private:
    FloatType xFrom;
    FloatType xTo;
    FloatType yFrom;
    FloatType yTo;
};

//==============================================================================
// Convert cent value to frequency ratio.

template <typename FloatType>
class Cent2Ratio
{
public:
    FloatType calc(FloatType x)
    {
        if(x != x1)
        {
            y1 = exp(log(2)*x/1200);
            x1 = x;
        }

        return y1;
    }

private:
    FloatType x1;
    FloatType y1;
};

//==============================================================================
// Convert frequency ratio to cent value.

template <typename FloatType>
class Ratio2Cent
{
public:
    FloatType calc(FloatType x)
    {
        if(x != x1)
        {
            y1 = 1200 * log2(x);
            x1 = x;
        }

        return y1;
    }

private:
    FloatType x1;
    FloatType y1;
};

//==============================================================================
}
