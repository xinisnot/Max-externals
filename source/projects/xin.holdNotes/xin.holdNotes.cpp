/// @file
///	@ingroup 	minexamples
///	@copyright	Copyright 2018 The Min-DevKit Authors. All rights reserved.
///	@license	Use of this source code is governed by the MIT License found in the License.md file.

#include "c74_min.h"

using namespace c74::min;


class xin_holdNotes : public object<xin_holdNotes> {
public:
    MIN_DESCRIPTION	{"Hold MIDI notes."};
    MIN_TAGS		{"midi"};
    MIN_AUTHOR		{"xin"};
    MIN_RELATED		{"kslider, nslider"};

    inlet<>  in1    { this, "pitch" };
    inlet<>  in2    { this, "velocity" };
    outlet<> out1   { this, "(list) pitches" };
    outlet<> out2   { this, "(list) velocities" };
    outlet<> out3   { this, "bang when nothing is being held."};
    

    
    c74::min::function process = MIN_FUNCTION {
        switch(inlet)
        {
            //===============================================================
            // right inlet
            case 1:
            {
                lock lock {m_mutex};
                tmp_vel = args[0];
                lock.unlock();
                break;
            }
                
            //===============================================================
            // left inlet
            case 0:
            {
                lock lock {m_mutex};
                
                if(tmp_vel == 0)
                {
                    std::vector<atom>::iterator itr = std::find(pitches.begin(), pitches.end(), args[0]);
    
                    if(itr != pitches.end())
                    {
                        const int i = std::distance(pitches.begin(), itr);
                        pitches.erase(pitches.begin() + i);
                        velocities.erase(velocities.begin() + i);
                    }
                }
                else
                {
                    pitches.reserve     (pitches.size() + 1);
                    pitches.insert      (pitches.end(), args[0]);
                    velocities.reserve  (velocities.size() + 1);
                    velocities.insert   (velocities.end(), tmp_vel);
                }
                
                lock.unlock();
    
                if(pitches.size() != 0)
                {
                    out2.send(velocities);
                    out1.send(pitches);
                }
                else
                {
                    out3.send(k_sym_bang);
                }
                
                break;
            }

            //===============================================================
            // default
            default:
                assert(false);
        }
        
        return {};
    };
    
    message<threadsafe::yes> ints   { this, "int",   "MIDI note", process };
    message<threadsafe::yes> floats { this, "float", "MIDI note", process };
    
private:
    atom  tmp_vel;
    atoms pitches;
    atoms velocities;
    mutex m_mutex;

};


MIN_EXTERNAL(xin_holdNotes);
