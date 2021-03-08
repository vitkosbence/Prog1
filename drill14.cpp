/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
//#include "Graph.h"


class B1 {
    public:
        virtual void vf() { cout << "B1 :: vf" << endl; };
        void f() { cout << "B1 :: f" << endl; };
        virtual void pvf() = 0;
};

class D1 : public B1 {
    public:
        void vf() override { cout << "D1 :: vf" << endl; };
        //void f() { cout << "D1 :: f" << endl; };
};

class D2 : public D1 {
    public:
        void pvf() override{ cout << "D2 :: pvf" << endl; }
};

class B2 {
    public:
        virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    string s = "default";
    void pvf() override { cout << s << endl; };

};

class D22 : public B2 {
public:
    int i = 1;
    void pvf() override { cout << i << endl; };

};

void f(B2& b) {
    b.pvf();
}

int main()
{
    /*//1
    B1 b;
    b.f();
    b.vf();
    //2
    D1 d;
    d.f();
    d.vf();
    //3
    B1& b2 = d;
    b2.f();
    b2.vf();*/
    //4
    /*Ha a D1-nek nincs f met�dusa akkor az �se f met�dus�t haszn�lja akkor is ha D1 t�pus� referenci�r�l h�vjuk meg
    viszont ha van, akkor D1 t�pusu ref eset�n saj�tj�t B1 t�pus� ref eset�n �s�j�t h�vja meg*/
    //5
    /*error t�rt�nik mivel se B1 se D1 nem overrideolja a pvf-et annak ellen�re hogy l�teznek p�ld�nyaik*/
    //6
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    //7
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
    String a;
    cin >> a;
}
