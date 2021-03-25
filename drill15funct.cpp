/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"


double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x / 2); }

int main()
{
    Point tl{ 100,100 };
    Simple_window win{ tl, 600,600,"drill15" };
    const int axis_lenght = 400;
    const int notch_spacing = 20;
    Axis x{ Axis::x,Point{(win.x_max()-axis_lenght)/2,win.y_max() / 2},axis_lenght,axis_lenght / notch_spacing,"1 == 20 pixels" };
    Axis y{ Axis::y,Point{win.x_max() / 2,win.y_max()- (win.y_max() - axis_lenght) / 2},axis_lenght,axis_lenght / notch_spacing,"1 == 20 pixels" };
    x.set_color(Color::red);
    y.set_color(Color::red);
    Point origin = { 300,300 };
    const int n = 400;
    const int x_scale = 20;
    const int y_scale = 20;
    Function one_f{ one,-10,11, origin,n,x_scale,y_scale };
    Function slope_f{ slope,-10,11, origin,n,x_scale,y_scale };
    Text slope_label{ Point{100,380},"x/2" };
    Function square_f{ square,-10,11, origin,n,x_scale,y_scale };
    Function cos_f{ cos,-10,11, origin,n,x_scale,y_scale };
    Function sloping_cos_f{ sloping_cos,-10,11, origin,n,x_scale,y_scale };
    cos_f.set_color(Color::blue);
    win.attach(one_f);
    win.attach(slope_f);
    win.attach(slope_label);
    win.attach(square_f);
    win.attach(cos_f);
    win.attach(sloping_cos_f);
    win.attach(x);
    win.attach(y);
    win.wait_for_button();
}