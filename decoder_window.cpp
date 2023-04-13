#include "decoder_window.h"

#include <iostream>

DecoderWindow::DecoderWindow(int k, Decoder* dec, SchemeShape* scheme, DecoderShape* dec_shape)
    :Graph_lib::Window(Graph_lib::Point(0,0), 1200, 1200, "FALT Decoder"),
     button1 (Graph_lib::Button(Graph_lib::Point{x_max()-70, 30 * 1}, 70, 20, "1st input", callback_clicked1)),
     button2 (Graph_lib::Button(Graph_lib::Point{x_max()-70, 30 * 2}, 70, 20, "2nd input", callback_clicked2)),
     button3 (Graph_lib::Button(Graph_lib::Point{x_max()-70, 30 * 3}, 70, 20, "3rd input", callback_clicked3)),
    button4 (Graph_lib::Button(Graph_lib::Point{x_max()-70, 30 * 4}, 70, 20, "4th input", callback_clicked4))

{
current_decoder = dec;
decoder_shape = dec_shape;
attach(button1);
attach(button2);
attach(button3);
attach(button4);

}

void DecoderWindow::clicked(Graph_lib::Button& btn, int number)
{
    current_decoder->inputs[number].set_opposite_out();
    this->redraw();
}
