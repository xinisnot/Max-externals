#pragma once

namespace xtool::scale
{
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

        FloatType scaleU2X(FloatType x)
        {
            return x*(yTo-yFrom) + yFrom;
        }

        FloatType scaleX2U(FloatType x)
        {
            return (x-xFrom) / (xTo-xFrom);
        }

        FloatType scaleB2X(FloatType x)
        {
            return scaleU2X(scaleB2U(x), yFrom, yTo);
        }

        FloatType scaleX2B(FloatType x)
        {
            return (x-xFrom) / (xTo-xFrom) * 2 - 1;
        }

        FloatType scaleX2Y(FloatType x)
        {
            return scaleU2X(scaleX2U(x));
        }

    private:
        FloatType xFrom;
        FloatType xTo;
        FloatType yFrom;
        FloatType yTo;
    };
} // namespace xtool::scale