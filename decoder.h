#ifndef DECODER_H
#define DECODER_H
#include "logic.h"
#include <Graph_lib/Graph.h>
//#include <Graph_lib/Window.h>
#include <Graph_lib/Simple_window.h>


class Decoder
{
public:
    void add_ands(int n);
    void add_ands() {ands.push_back(new Logic::And);}
    void add_inputs() {inputs.push_back(new Logic::Source);} ;
    void add_inputs(int n);
    void add_inputs(Logic::Element&);
    Graph_lib::Vector_ref<Logic::Element> inputs{};
    Graph_lib::Vector_ref<Logic::And> ands{};
    void connect();
    void connect(Logic::Element&, Logic::Operation&);
    void connect(Logic::Element&);


    void Clicked(Graph_lib::Button &b);

};

#endif // DECODER_H


