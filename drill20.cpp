/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"
//#include "GUI.h"
//#include "Lines_window.h"

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 drillcopy(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) {
        *f2 = *f1;
        f1++;
        f2++;
    }
    return f2;
}
;

using namespace std;

int main()
{
    array<int, 10> a { 0,1,2,3,4,5,6,7,8,9 };
    vector<int> b{ 0,1,2,3,4,5,6,7,8,9 };
    list<int> c{ 0,1,2,3,4,5,6,7,8,9 };
    array<int, 10> d = a;
    vector<int> e = b;
    list<int> f = c;
    for (int x : a)
        x += 2;
    for (int x : b)
        x += 3;
    for (int x : c)
        x += 5;
    drillcopy(a.begin(), a.end(), b.begin());
    drillcopy(c.begin(), c.end(), a.begin());

    auto g = find(b.begin(),b.end(), 3);
    auto h = find(c.begin(), c.end(), 27);

    if (g != b.end())
        cout << distance(b.begin(),g) << endl;
    if (h != c.end())
        cout << distance(c.begin(),h) << endl;
    
    string asd;
        cin >> asd;
}

