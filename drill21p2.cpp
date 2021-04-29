/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include <map>
//#include "Graph.h"
//#include "GUI.h"
//#include "Lines_window.h"



using namespace std;

//5
void mapread(map<string, int>& a) {
    string name;
    int id;
    while (std::cin >> name >> id) {
        a[name] = id;
    }
        
}


int main()
{
    //1
    map<string, int> msi;
    ifstream ist{ "mapin.txt" };
    //2
    string name;
    int id;
    while (ist >> name >> id) {
        msi[name] = id;
    }
    //3
    for (const auto& p : msi)
        cout << p.first << ": " << p.second << endl;
    //4
    msi.clear();
    //6
    mapread(msi);
    //7
    for (const auto& p : msi)
        cout << p.first << ": " << p.second << endl;
    //8
    int sum = accumulate(msi.begin(), msi.end(), 0, [](int value, const std::map<string, int>::value_type& p) { return value + p.second; });
    //9
    map<int, string> mis;
    //10
    for (const auto& p : msi)
        mis[p.second] = p.first;
    //11
    for (const auto& p : mis)
        cout << p.first << ": " << p.second << endl;

    while (true);
    

}

