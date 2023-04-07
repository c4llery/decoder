#include "decoder.h"
#include <stdexcept>
#include <iostream>
void Decoder::add_ands(int n){
    for (int i = 0; i < n; ++i)
        ands.push_back(new And);
}

void Decoder::add_inputs(int n){
    for (int i = 0; i < n; ++i)
        sources.push_back(new Source);
}

void Decoder::connect(int begin, int end)
{
    try{
    if ((begin < 1) || (end > ands.size()) || (begin > end))
        throw "You are out of bounds!";
    for (int i = begin - 1; i < end; ++i){
        int tmp = i;
        for (int j = 0; j < sources.size(); ++j){
            if (tmp % 2 == 0)
                sources[j] >> ~ands[i];
            else
                sources[j] >> ands[i];
         tmp /= 2;
        }
    }
}
catch (std::out_of_range)
{
    std::cout << "You are out of bounds!";
}
}

void Decoder::connect()
{
    for (int i = 0; i < std::min(int(pow(2, sources.size())), ands.size()); ++i){
        int tmp = i;
        for (int j = 0; j < sources.size(); ++j){
            if (tmp % 2 == 0)
                sources[j] >> ~ands[i];
            else
                sources[j] >> ands[i];
         tmp /= 2;
        }
    }
}
