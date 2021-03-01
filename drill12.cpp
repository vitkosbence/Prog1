/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
    
    Point tl{ 100,100 };
    Simple_window win{ tl,640,464,"Canvas" };
    Image ii{ Point{0,0},"q5t061jjlkg31.jpg" };
    win.attach(ii);
    Axis xa{ Axis::x,Point{20,300},280,10,"x axis" };
    xa.set_color(Color::red);
    win.attach(xa);
    Axis ya{ Axis::y,Point{160,440},280,10,"y axis" };
    ya.set_color(Color::blue);
    win.attach(ya);
    Function tg{ tan, 0, 100, Point{20,150},1000,50,50 };
    tg.set_color(Color::black);
    win.attach(tg);
    Graph_lib::Polygon poly;
    poly.add(Point{ 300,200 });
    poly.add(Point{ 275,120 });
    poly.add(Point{ 350,70 });
    poly.add(Point{ 425,120 });
    poly.add(Point{ 400,200 });
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    poly.set_style(Line_style(Line_style::dash, 4)); 
    win.attach(poly);
    Negyzet r{ Point{200,200},100,50 };
    r.set_color(Color::black);
    r.set_fill_color(Color::yellow);
    win.attach(r);
    Closed_polyline poly_rect;
    poly_rect.add(Point{ 100,50 });
    poly_rect.add(Point{ 200,50 });
    poly_rect.add(Point{ 200,100 });
    poly_rect.add(Point{ 100,100 });
    poly_rect.add(Point{ 120,75 });
    poly_rect.set_color(Color::black);
    poly_rect.set_fill_color(Color::green);
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    Text t{ Point{150,150}, "My name Jeff" };
    t.set_font(Font::times_bold);
    t.set_font_size(50);
    t.set_color(Color::blue);
    win.attach(t);
    win.attach(poly_rect);
    win.wait_for_button();
    
}
