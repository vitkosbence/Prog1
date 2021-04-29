/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include <map>
#include <numeric>
//#include "Graph.h"
//#include "GUI.h"
//#include "Lines_window.h"



using namespace std;




int main()
{
    //1
    vector<double> vd;
    ifstream ist{ "number.txt" };
    //2
    double num;
    while (ist >> num) {
        vd.push_back(num);
    }
    for (double x : vd) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> vi(vd.size());
    for (int i = 0; i < vd.size(); i++)
        vi[i] = vd[i];
    for (int i = 0; i < vd.size(); i++)
        cout << vd[i] << "   " << vi[i] << endl;
    cout << accumulate(vd.begin(), vd.end(), 0.0) << endl;
    cout << accumulate(vd.begin(), vd.end(), 0.0) - accumulate(vi.begin(), vi.end(), 0) << endl;
    reverse(vd.begin(), vd.end());
    for (double x : vd) {
        cout << x << " ";
    }
    cout << endl;
    cout << accumulate(vd.begin(), vd.end(), 0.0)/vd.size() << endl;
    while (true);
    

}

