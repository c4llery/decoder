#include "decoder.h"
#include <stdexcept>
#include <iostream>


Decoder::Decoder(int n){
    add_inputs(n);
    add_ands(int(pow(2, inputs.size())));
}

Decoder::Decoder(Graph_lib::Vector_ref<Logic::Element> sources):
    inputs{sources}
    {
    add_inputs(inputs.size());
    add_ands(int(pow(2, inputs.size())));
}


void Decoder::add_ands(int n){
    for (int i = 0; i < n; ++i)
        ands.push_back(new Logic::And);
}

void Decoder::add_inputs(int n){
    for (int i = 0; i < n; ++i)
        inputs.push_back(new Logic::Source);
}


void Decoder::add_inputs(Logic::Element& elem)
{
    inputs.push_back(elem);
}

void Decoder::connect()
{
    for (int i = 0; i < std::min(int(pow(2, inputs.size())), ands.size()); ++i){
        int tmp = i;
        for (int j = 0; j < inputs.size(); ++j){
            if (tmp % 2 == 0)
                inputs[j] >> ~ands[i];
            else
                inputs[j] >> ands[i];
         tmp /= 2;
        }
    }
}



void Decoder::connect(Logic::Element& source, Logic::Operation& output)
{
        source >> output;
}


