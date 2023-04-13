#include <iostream>
#include <sstream>
#include <exception>
#include <cmath>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Window.h>
#include <Graph_lib/Simple_window.h>

#include "logic.h"
#include "logic_shapes.h"
#include "decoder.h"
#include "decoder_shapes.h"
#include "decoder_window.h"

int main ()
try
{
  int win_w = 1200;
  int win_h = 1200;
  Graph_lib::Point lt{ Graph_lib::x_max()/2 - win_w/2, Graph_lib::y_max()/2 - win_h/2 };
//  Simple_window win{ lt, win_w, win_h, "Scheme of Logic Elements" };
  using namespace Logic;


  Decoder decoder;
  DecoderShape decoder_shape(Graph_lib::Point(50, 50));

  decoder.add_ands(16);
  decoder.add_inputs(4);
  decoder.connect();

  SchemeShape scheme{ Graph_lib::Point{5, 5}, win_w - 80, win_h - 10 };
  DecoderWindow decoder_window(4, &decoder, &scheme, &decoder_shape);
  decoder_window.attach(scheme);

  auto column_x = [] (double c) -> int
  { return int(30 + 100 * c);};

  auto line_y = [] (double l) -> int
  { return int(40 + 75 * l); };
  int sdv1 = 44;

  for (int k = 0; k < decoder.sources.size(); ++k){
      decoder_shape.add_source_shape(scheme, decoder.sources[k], "", Graph_lib::Point{ column_x(0.5 * k), line_y(0) - 20});
  }

  for (int k = 0; k < decoder.ands.size(); ++k){
    decoder_shape.add_and_shape(scheme, decoder.ands[k], "", Graph_lib::Point{ column_x(4), line_y(0.5 * k) + sdv1});
}
  scheme.update_connections();
  decoder.sources[0] = true;
  return Graph_lib::gui_main();
}

catch (std::exception& e)
{
  std::cerr << e.what() << std::endl;
  return 1;
}
catch (...)
{
  std::cerr <<"Oops, something went wrong..."<< std::endl;
  return 2;
}


