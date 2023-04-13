#ifndef DECODER_WINDOW_H
#define DECODER_WINDOW_H
#include "Graph_lib/Simple_window.h"
#include "decoder_shapes.h"
#include "logic_shapes.h"

class DecoderWindow : public Graph_lib::Window
{
public:
    DecoderWindow(int i, Decoder*, SchemeShape*, DecoderShape*);
//    void add_scheme(SchemeShape* scheme);

private:
    static void callback_clicked(Graph_lib::Address, Graph_lib::Address object) {
        auto &btn = Graph_lib::reference_to<Graph_lib::Button>(object);
        dynamic_cast<DecoderWindow &>(btn.window()).clicked(btn);


    }
    Graph_lib::Vector_ref<Graph_lib::Button> buttons;
    Graph_lib::Button button;
    Decoder* current_decoder;
    DecoderShape* decoder_shape;
    SchemeShape* scheme;

    void clicked(Graph_lib::Button&);

};

#endif // DECODER_WINDOW_H
