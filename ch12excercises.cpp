/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include <vector>


    

int main()
{
    
    Point tl{ 100,100 };
    Simple_window win{ tl,1920,1080,"Canvas" };
    //excercise 1
    Negyzet rectangle{ Point{100,100},100,200 };
    rectangle.set_color(Color::blue);
    Graph_lib::Polygon poly;
    poly.add(Point{ 300,100 });
    poly.add(Point{ 400,100 });
    poly.add(Point{ 400,300 });
    poly.add(Point{ 300,300 });
    poly.set_color(Color::red);
    //excercise 2
    Negyzet howdy{ Point{50,50},100,30 };
    Text szoveg{ Point{52,70},"Howdy!" };
    //excercise 3
    Text initial1{ Point{300,200},"V" };
    Text initial2{ Point{400,200},"B" };
    Text initial3{ Point{490,200},"D" };
    initial1.set_font_size(150);
    initial2.set_font_size(150);
    initial3.set_font_size(150);
    initial1.set_font( Font::times_bold );
    initial2.set_font(Font::times_bold);
    initial3.set_font(Font::times_bold);
    initial1.set_color(Color::red);
    initial2.set_color(Color::green);
    initial3.set_color(Color::yellow);
    //excercise 4
    Vector_ref<Negyzet> amoba;
    const Point table_corner = Point{ 400,300 };
    const int square_size = 50;
    const int col_num = 3;
    const int row_num = 3;
    for(int i = 0; i < row_num; i++)
        for (int j = 0; j < col_num; j++) {
            amoba.push_back(new Negyzet { Point{table_corner.x + square_size * i,table_corner.y + square_size * j},square_size,square_size });
            if ((i + j) % 2 == 0)
                amoba[i*col_num + j].set_fill_color(Color::red);
            else
                amoba[i*col_num + j].set_fill_color(Color::white);
        }
    //excercise 5
    Negyzet keret{ Point{600,50},x_max*2/3,y_max*3/4 };
    keret.set_style(Line_style{ Line_style::solid, 24 });
    keret.set_color(Color::red);
    //excercise 6
    Negyzet teszt{ Point{600,900},200,500 };
    teszt.set_color(Color::dark_blue);
    //Simple_window teszt_win{ tl,3000,4000,"teszt" };
    //excercise 7
    Negyzet alap{ Point{ 700,500 }, 200, 200 };
    Graph_lib::Polygon teto;
    teto.add(Point{ 680,500 });
    teto.add(Point{ 920,500 });
    teto.add(Point{ 800,400 });
    Negyzet ajto{ Point{770,610},60,90 };
    Point sarok1{ 720,520 };
    int meret = 30;
    Lines ablak1;
    for (int i = 0; i < 3; i++)
        ablak1.add(Point{ sarok1.x + meret * i,sarok1.y }, Point{ sarok1.x + meret * i,sarok1.y + meret * 2 });
    for (int i = 0; i < 3; i++)
        ablak1.add(Point{ sarok1.x,sarok1.y + meret * i }, Point{ sarok1.x + meret * 2,sarok1.y + meret * i });
    Point sarok2{ 820,520 };
    Lines ablak2;
    for (int i = 0; i < 3; i++)
        ablak2.add(Point{ sarok2.x + meret * i,sarok2.y }, Point{ sarok2.x + meret * i,sarok2.y + meret * 2 });
    for (int i = 0; i < 3; i++)
        ablak2.add(Point{ sarok2.x,sarok2.y + meret * i }, Point{ sarok2.x + meret * 2,sarok2.y + meret * i });
    Graph_lib::Polygon kemeny;
    cout << (teto.point(2).x + teto.point(1).x) << endl;
    kemeny.add(Point{ teto.point(2).x+ (teto.point(1).x-teto.point(2).x)/10*6, teto.point(2).y + (teto.point(1).y - teto.point(2).y) / 10 * 6 });
    kemeny.add(Point{ teto.point(2).x + (teto.point(1).x - teto.point(2).x)/10*4,teto.point(2).y + (teto.point(1).y - teto.point(2).y) / 10 * 4 });
    kemeny.add(Point{ teto.point(2).x + (teto.point(1).x - teto.point(2).x) /10*4, 400 });
    kemeny.add(Point{ teto.point(2).x + (teto.point(1).x - teto.point(2).x) / 10 * 6, 400 });
    //excercise 8
    int sugar = 100;
    Point kezdo_kozep{ 1100,500 };
    Circle kor1{ kezdo_kozep,sugar };
    Circle kor2{ Point{kezdo_kozep.x+sugar*2,kezdo_kozep.y},sugar };
    Circle kor3{ Point{kezdo_kozep.x + sugar*4,kezdo_kozep.y},sugar };
    Circle kor4{ Point{kezdo_kozep.x + sugar,kezdo_kozep.y+sugar},sugar };
    Circle kor5{ Point{kezdo_kozep.x + sugar*3,kezdo_kozep.y + sugar},sugar };
    kor1.set_color(Color::blue);
    kor2.set_color(Color::black);
    kor3.set_color(Color::red);
    kor4.set_color(Color::yellow);
    kor5.set_color(Color::green);
    //excercis 9
    Image kep{ Point{1000,200},"kep.jpg" };
    Text label{ Point{1050,360},"Így kéne am kinéznie" };
    label.set_color(Color::black);
    label.set_font_size(20);

    win.attach(label);
    win.attach(kep);
    win.attach(kor1);
    win.attach(kor2);
    win.attach(kor3);
    win.attach(kor4);
    win.attach(kor5);
    win.attach(kemeny);
    win.attach(ablak1);
    win.attach(ablak2);
    win.attach(ajto);
    win.attach(teto);
    win.attach(alap);
    win.attach(teszt);
    win.attach(keret);
    for (int i = 0; i < amoba.size(); i++)
        win.attach(amoba[i]);
    win.attach(initial1);
    win.attach(initial2);
    win.attach(initial3);
    win.attach(szoveg);
    win.attach(howdy);
    win.attach(poly);
    win.attach(rectangle);
    win.wait_for_button();
    
}
