#include "decoder_shapes.h"

DecoderShape::DecoderShape(Graph_lib::Point xy)
    :Graph_lib::Widget(xy, 1200, 600, "", nullptr)
{};

void DecoderShape::add_input_shape(SchemeShape& scheme, Element& src, const std::string name,
                                    const Graph_lib::Point&p, int width, int height){
    src_shapes.push_back(new SourceShape(scheme, dynamic_cast<Source&>(src), name, p, width, height));
}


void DecoderShape::add_and_shape(SchemeShape& scheme, And& and_piece, const std::string name,
                                    const Graph_lib::Point&p, int width, int height){
    and_shapes.push_back(new AndShape(scheme, and_piece, name, p, width, height));

}
