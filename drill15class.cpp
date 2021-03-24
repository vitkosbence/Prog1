/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"
#include <regex>

struct Person {
    private:
        int a;
        string fn;
        string ln;
    public:
        Person(string first_name, string last_name, int age) : a(age), fn(first_name), ln(last_name) {
            regex name_regex = regex(R"(.*[; :"'\[\]*&^%$#@!.].*)");
            if (regex_match(fn,name_regex) || regex_match(ln, name_regex)) {
                error("Invalid name");
            }
            if (a > 150 || a < 0)
                error("Invalid age");

        }
        Person() : a(0), fn(""), ln("") {}
        int age() const { return a; }
        string first_name() const { return fn; }
        string last_name() const { return ln; }
        void set_age(int kor) { a = kor; }
        void set_fname(string nev) { fn = nev; }
        void set_lname(string nev) { ln = nev; }
        
};

ostream& operator<<(ostream& os, const Person& p) {
    os << p.first_name() << " " << p.last_name() << " is " << p.age() << " years old.";
    return os;
}

istream& operator>>(istream& is, Person& p) {
    int age;
    string fname;
    string lname;
    is >> fname >> lname >> age;
    p.set_fname(fname);
    p.set_lname(lname);
    p.set_age(age);
    return is;
}

int main()
{
    Person a;
    Person b("Nagy", "Sanyi", 10);
    cout << a << endl << b << endl;
    cin >> a;
    cout << a << endl;
    vector<Person> lista;
    for (int i = 0; i < 5; i++) {
    cin >> a;
    lista.push_back(a);
    }
    for (Person c : lista)
        cout << c << endl;
    string c;
    cin >> c;
}
