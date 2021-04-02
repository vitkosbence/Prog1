/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
//#include "Simple_window.h"
//#include "Graph.h"
#include "GUI.h"
#include "Lines_window.h"



int main(){
try {
    Lines_window win{ Point{100,100},600,400,"lines" };
    return gui_main();
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
}
