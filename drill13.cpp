/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"




int main()
{
    //1
    Point tl{ 100,100 };
    Simple_window win{ tl,1000,800,"Canvas" };
    //2
    Lines negyzetracs;
    for (int i = 0; i < 9; i++) {
        negyzetracs.add(Point{ 0 + i * 100,0 }, Point{ 0 + i * 100,800 });
        negyzetracs.add(Point{ 0, 0 + i * 100 }, Point{ 800, 0 + i * 100 });
    }
    //3
    Vector_ref<Negyzet> negyzetek;
    for (int i = 0; i < 8; i++) {
        negyzetek.push_back(new Negyzet{ Point{ 0 + i * 100,0 + i * 100 }, 100, 100 });
        negyzetek[i].set_fill_color(Color::red);
    }
    //4
    Vector_ref<Image> kepek;
    kepek.push_back(new Image{ Point{0,200},"kep2.jpg" });
    kepek.push_back(new Image{ Point{0,600},"kep2.jpg" });
    kepek.push_back(new Image{ Point{400,600},"kep2.jpg" });
    //5
    Image mozgokep{ Point{ 0,0 },"kep3.jpg" };
    win.attach(mozgokep);
    win.attach(negyzetracs);
    for (int i = 0; i < negyzetek.size(); i++)
        win.attach(negyzetek[i]);
    for (int i = 0; i < kepek.size(); i++)
        win.attach(kepek[i]);
    win.attach(mozgokep);
    while (true) {
        win.wait_for_button();
        if (mozgokep.point(0).x == 700)
            mozgokep.move(-700, -700);
        else
            mozgokep.move(100, 100);
    }
}
