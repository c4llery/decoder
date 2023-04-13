#ifndef DECODER_SHAPES_H
#define DECODER_SHAPES_H
#include "logic_shapes.h"
#include "logic.h"
#include "Graph_lib/Simple_window.h"
using namespace Logic;


class DecoderShape : public Graph_lib::Widget
{
public:
    DecoderShape(Graph_lib::Point);

    void add_input_shape(SchemeShape&, Element&, const std::string, const Graph_lib::Point&,
                          int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

    void add_and_shape(SchemeShape&, And&, const std::string, const Graph_lib::Point&,
                       int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);


    void move (int dx, int dy) override  { return; }
    void hide () override  { return; }
    void show () override  { return; }
    void attach (Graph_lib::Window&) override {return;};
private:

    Graph_lib::Vector_ref<ElementShape> src_shapes{};
    Graph_lib::Vector_ref<AndShape> and_shapes{};


};



#endif // DECODER_SHAPES_H
