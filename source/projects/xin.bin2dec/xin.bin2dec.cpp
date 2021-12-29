/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"

using namespace c74::min;


class xin_bin2dec : public object<xin_bin2dec> {
public:
    MIN_DESCRIPTION {"Convert binary to decimal."};
    MIN_TAGS        {"utilities"};
    MIN_AUTHOR      {"xin"};
    MIN_RELATED     {"number"};
    
    inlet<>  in1  { this, "(list) Binary" };
    outlet<> out1 { this, "(int) Decimal" };
    
    c74::min::function process = MIN_FUNCTION {
        lock lock {m_mutex};
        int n = 0;
        
        for(auto i = args.begin(); i != args.end(); ++i) {
            n += (int(*i) != 0) * pow(2, std::distance(i, args.end()-1));
        }
        dec = n;
        
        lock.unlock();
        
        out1.send(n);
        return {};
    };
    
    message<threadsafe::yes> list   { this, "list",   "Convert binary to decimal. Any value is treated as a Boolean value.", process };
    message<threadsafe::yes> number { this, "number", "Convert binary to decimal. Any value is treated as a Boolean value.", process };
    message<threadsafe::yes> bang   { this, "bang",   "Send out decimal value.",
        MIN_FUNCTION {
            out1.send(dec);
            return {};
        }
    };
    
private:
    mutex m_mutex;
    int dec = 0;
};

MIN_EXTERNAL(xin_bin2dec);
