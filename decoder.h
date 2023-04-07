#ifndef DECODER_H
#define DECODER_H
#include "logic.h"
#include <Graph_lib/Graph.h>
#include <Graph_lib/Window.h>
#include <Graph_lib/Simple_window.h>

using namespace Logic;

class Decoder
{
public:
    void add_ands(int n);
    void add_ands() {ands.push_back(new And);}
    void add_inputs() {sources.push_back(new Source);} ;
    void add_inputs(int n);
    Graph_lib::Vector_ref<Logic::Source> sources{}; //TODO: Добавить входы и выходы
    Graph_lib::Vector_ref<Logic::And> ands{};
    void connect(int, int);
    void connect();

private:


};




#endif // DECODER_H
