/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"
#include "../../xtool/include/xtool.h"

using namespace c74::min;
//using namespace xtool::scale;

class xin_joy_tilde : public object<xin_joy_tilde>, public sample_operator<1, 1>
{
public:
    MIN_DESCRIPTION     {"Scale values."};
    MIN_TAGS            {"utilities"};
    MIN_AUTHOR          {"xin"};
    MIN_RELATED         {"scale, scale~"};

    inlet<>     in1     { this, "(signal) x" };
    outlet<>    out1    { this, "(signal) y", "signal" };

    argument<number> xFrom_arg
    {
        this, "xFrom", "x From",
        MIN_ARGUMENT_FUNCTION
        {
            xFrom = arg;
        }
    };

    argument<number> xTo_arg
    {
        this, "xTo", "x To",
        MIN_ARGUMENT_FUNCTION
        {
            xTo = arg;
        }
    };

    argument<number> yFrom_arg
    {
        this, "yFrom", "y From",
        MIN_ARGUMENT_FUNCTION
        {
            yFrom = arg;
        }
    };

    argument<number> yTo_arg
    {
        this, "yTo", "y To",
        MIN_ARGUMENT_FUNCTION
        {
            yTo = arg;
        }
    };

    attribute<number> xFrom
    {
        this, "xFrom", 0.0, description{ "x from" },
        setter
        {
            MIN_FUNCTION
            {
//                scale.setXFrom(args[0]);
                return args;
            }
        }
    };

    attribute<number> xTo
    {
        this, "xTo", 1.0, description { "x to" },
        setter
        {
            MIN_FUNCTION
            {
//                scale.setXTo(args[0]);
                return args;
            }
        }
    };

    attribute<number> yFrom
    {
        this, "yFrom", 0.0, description { "y from" },
        setter
        {
            MIN_FUNCTION
            {
//                scale.setYFrom(args[0]);
                return args;
            }
        }
    };

    attribute<number> yTo
    {
        this, "yTo", 1.0, description { "y to" },
        setter
        {
            MIN_FUNCTION
            {
//                scale.setYTo(args[0]);
                return args;
            }
        }
    };

    sample operator()(sample in) {
//        return scale.scaleX2Y(in);
        return xtool::calc::scaleX2Y<sample>(in, xFrom, xTo, yFrom, yTo);
    }

private:
//    Scale<number> scale;
};

MIN_EXTERNAL(xin_joy_tilde);
