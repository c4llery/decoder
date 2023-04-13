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
    Graph_lib::Vector_ref<Logic::Source> inputs{}; //TODO: Добавить входы и выходы
    Graph_lib::Vector_ref<Logic::And> ands{};
    void connect(int, int);
    void connect();

    void Clicked(Graph_lib::Button &b);

};

#endif // DECODER_H


