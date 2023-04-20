#include <iostream>
#include <sstream>
#include <exception>
#include <cmath>

#include <Graph_lib/Graph.h>
#include <Graph_lib/Window.h>

#include "logic.h"
#include "logic_shapes.h"


int main ()
try
{
  int win_w = 1200;
  int win_h = 800;
  Graph_lib::Point lt{ Graph_lib::x_max()/2 - win_w/2, Graph_lib::y_max()/2 - win_h/2 };
  Simple_window win{ lt, win_w, win_h, "Scheme of Logic Elements" };
  using namespace Logic;


  SchemeShape scheme{ Graph_lib::Point{5, 5}, win_w - 80, win_h - 10 };
  Logic::Decoder* decoder = new Logic::Decoder();
  Logic::DecoderShape ds{scheme, *decoder, "123", Graph_lib::Point{200, 200}};
  scheme.update_connections();
  win.attach(scheme);

  Logic::And* and1 = new Logic::And();
  *and1 >> *decoder;
  and1->set_opposite_out();
  Logic::AndShape* ands1 = new AndShape(scheme, *and1, "", Graph_lib::Point{20, 20});
  win.wait_for_button();

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


