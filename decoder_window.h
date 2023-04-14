#ifndef DECODER_WINDOW_H
#define DECODER_WINDOW_H
#include "Graph_lib/Simple_window.h"
#include "decoder_shapes.h"
#include "logic_shapes.h"

class DecoderWindow : public Graph_lib::Window
{
public:
    DecoderWindow(Decoder*, SchemeShape*);

private:
    static void callback_clicked1(Graph_lib::Address, Graph_lib::Address object) {
        auto &btn = Graph_lib::reference_to<Graph_lib::Button>(object);
        dynamic_cast<DecoderWindow &>(btn.window()).clicked(btn, 0);
    }
    static void callback_clicked2(Graph_lib::Address, Graph_lib::Address object) {
        auto &btn = Graph_lib::reference_to<Graph_lib::Button>(object);
        dynamic_cast<DecoderWindow &>(btn.window()).clicked(btn, 1);
    }

    static void callback_clicked3(Graph_lib::Address, Graph_lib::Address object) {
        auto &btn = Graph_lib::reference_to<Graph_lib::Button>(object);
        dynamic_cast<DecoderWindow &>(btn.window()).clicked(btn, 2);
    }

    static void callback_clicked4(Graph_lib::Address, Graph_lib::Address object) {
        auto &btn = Graph_lib::reference_to<Graph_lib::Button>(object);
        dynamic_cast<DecoderWindow &>(btn.window()).clicked(btn, 3);
    }
    Decoder* current_decoder;
    SchemeShape* scheme;
    Graph_lib::Button button1;
    Graph_lib::Button button2;
    Graph_lib::Button button3;
    Graph_lib::Button button4;

    void clicked(Graph_lib::Button&, int number);
};

#endif // DECODER_WINDOW_H
