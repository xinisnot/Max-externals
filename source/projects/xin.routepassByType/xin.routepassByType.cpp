/// @file
///    @ingroup     minexamples
///    @copyright    Copyright 2018 The Min-DevKit Authors. All rights reserved.
///    @license    Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"

using namespace c74::min;


class xin_routepassByType : public object<xin_routepassByType> {
public:
    MIN_DESCRIPTION     {"Routepass by the type of the 0th element in any message."};
    MIN_TAGS            {"utilities"};
    MIN_AUTHOR          {"xin"};
    MIN_RELATED         {"route, routepass, typeroute~"};

    inlet<>  in1    { this, "Message to be routed." };
    outlet<> out1   { this, "0th element is int." };
    outlet<> out2   { this, "0th element is float." };
    outlet<> out3   { this, "0th element is symbol." };


    c74::min::function process = MIN_FUNCTION {
        switch(args[0].type()) {
            case message_type::int_argument:    out1.send(args);    break;
            case message_type::float_argument:  out2.send(args);    break;
            case message_type::symbol_argument: out3.send(args);    break;
            default: break;
        }
        return {};
    };
    
    message<threadsafe::yes> list      { this, "list",     "List to be routed.", process };
    message<threadsafe::yes> anything  { this, "anything", "Anything to be routed.", process };
    message<threadsafe::yes> number    { this, "number",   "Number to be routed.", process };
};


MIN_EXTERNAL(xin_routepassByType);
