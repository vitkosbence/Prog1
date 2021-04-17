/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"
//#include "GUI.h"
//#include "Lines_window.h"


template<typename T> struct S {
public:
    S(T a) : val(a) {};
    T& get();
    T& get() const;
    void operator=(const T& b) { val = b.get() };
    //void set(T b) { val = b.get() };

private:
    T val;
};

template<typename T> T& S<T>::get() { return val; };
template<typename T> T& S<T>::get() const { return val; };

template<typename T> void read_val(T& v) {
    T temp;
    cin >> temp;
    v = temp;
}

int main()
{
    S<int> i(4);
    S<char> c('a');
    S<double> d(2.7);
    S<string> s ("default");
    S<vector<int>> v ({ 1,2,3 });
    S<char> g('g');
    c = g;
    cout << i.get() << endl;
    cout << c.get() << endl;
    cout << d.get() << endl;
    cout << s.get() << endl;
    cout << v.get()[0] << endl;
    
    read_val<int>(i.get());
    read_val<char>(c.get());
    read_val<double>(d.get());
    read_val<string>(s.get());
}

