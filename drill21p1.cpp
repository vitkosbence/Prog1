/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"
//#include "GUI.h"
//#include "Lines_window.h"



using namespace std;

struct Item {
    string name;
    int iid;
    double value;
    Item(string n, int id, double val) : name(n), iid(id), value(val) {};

};

bool Id_case(const Item& x, const Item& y) {
    if (x.iid < y.iid) {
        return false;
    }
    return true;
};

bool Val_case(const Item& x, const Item& y) {
    if (x.value < y.value) {
        return false;
    }
    return true;
};

bool Name_case(const Item& x, const Item& y)  {
    if (x.name < y.name) {
        return false;
    }
    return true;
};


ostream& operator<<(ostream& os,const Item& it) {
    os << it.name << " " << it.iid << " " << it.value;
    return os;
}



int main()
{
    //1
    ifstream ist{ "input.txt" };
    string name;
    int id;
    double val;
    vector<Item> vi;
    while (ist >> name >> id >> val) {
        vi.push_back(Item{ name,id,val });
    }
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //2
    sort(vi.begin(), vi.end(), Name_case);
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //3
    sort(vi.begin(), vi.end(), Id_case);
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //4
    sort(vi.begin(), vi.end(), Val_case);
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //5
    vi.push_back(Item{ "horse shoe",99,12.34 });
    vi.push_back(Item{ "Canon S400",9988,499.95 });
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //6
    auto iter = find_if(vi.begin(), vi.end(), [](Item a) {string b{ "Ferenc" };  return a.name == b; });
    if(iter != vi.end())
        vi.erase(iter);
    iter = find_if(vi.begin(), vi.end(), [](Item a) {string b{ "Anna" };  return a.name == b; });
    if (iter != vi.end())
        vi.erase(iter);
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //7
    iter = find_if(vi.begin(), vi.end(), [](Item a) {  return a.iid == 2; });
    if (iter != vi.end())
        vi.erase(iter);
    iter = find_if(vi.begin(), vi.end(), [](Item a) {  return a.iid == 8; });
    if (iter != vi.end())
        vi.erase(iter);
    for (Item x : vi) {
        cout << x << " ";
    }
    cout << endl;
    //8.1
    ifstream ist2{ "input.txt" };
    string name2;
    int id2;
    double val2;
    list<Item> li;
    while (ist2 >> name2 >> id2 >> val2) {
        li.push_back(Item{ name2,id2,val2 });
    }
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.2
    li.sort(Name_case);
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.3
    li.sort( Id_case);
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.4
    li.sort(Val_case);
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.5
    li.push_back(Item{ "horse shoe",99,12.34 });
    li.push_back(Item{ "Canon S400",9988,499.95 });
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.6
    auto iter1 = find_if(li.begin(), li.end(), [](Item a) {string b{ "Ferenc" };  return a.name == b; });
    if (iter1 != li.end())
        li.erase(iter1); 
    iter1 = find_if(li.begin(), li.end(), [](Item a) {string b{ "Anna" };  return a.name == b; });
    if (iter1 != li.end())
        li.erase(iter1);
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    //8.7
    iter1 = find_if(li.begin(), li.end(), [](Item a) {  return a.iid == 2; });
    if (iter1 != li.end())
        li.erase(iter1);
    iter1 = find_if(li.begin(), li.end(), [](Item a) {  return a.iid == 8; });
    if (iter1 != li.end())
        li.erase(iter1);
    for (Item x : li) {
        cout << x << " ";
    }
    cout << endl;
    
    
    
    string asd;
    cin >> asd;
    

}

