#ifndef DECODER_SHAPES_H
#define DECODER_SHAPES_H
#include "logic_shapes.h"
#include "logic.h"
using namespace Logic;


class DecoderShape
{
public:
    void add_source_shape(SchemeShape&, Source&, const std::string, const Graph_lib::Point&,
                          int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
    void add_and_shape(SchemeShape&, And&, const std::string, const Graph_lib::Point&,
                       int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);

private:

    Graph_lib::Vector_ref<SourceShape> src_shapes{};
    Graph_lib::Vector_ref<AndShape> and_shapes{};


};



#endif // DECODER_SHAPES_H
