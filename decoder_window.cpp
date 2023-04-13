#include "decoder_window.h"

#include <iostream>

DecoderWindow::DecoderWindow(int k, Decoder* dec, SchemeShape* scheme, DecoderShape* dec_shape)
    :Graph_lib::Window(Graph_lib::Point(0,0), 1200, 1200, "FALT Decoder"),
    button(Graph_lib::Point{x_max()-70, 200}, 70, 20, "Next", callback_clicked)

{
attach(button);
current_decoder = dec;
decoder_shape = dec_shape;
for (int i = 0; i < k; ++i){
        buttons.push_back(new Graph_lib::Button( Graph_lib::Point{x_max()-70, 30 * i}, 70, 20, "Next", callback_clicked));
        attach(buttons[i]);

  }
scheme = scheme;
}

void DecoderWindow::clicked(Graph_lib::Button& btn)
{
    current_decoder->sources[0].set_opposite_out();
    this->redraw();
   //scheme->update_connections();
//    current_decoder->sources.push_back(new Logic::Source);
//    decoder_shape->add_source_shape(new SourceShape(scheme_shape, current_decoder->sources[4], "", Graph_lib::Point(0, 0), 100, 100));

}
