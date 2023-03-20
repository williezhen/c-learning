#include <iostream>
#include <crtdbg.h>
#include <windows.h>
using namespace std;

#include "Picture.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

#define _CRTDBG_MAP_ALLOC
#define N_TESTS 10

void add_shapes(Picture& pic, int i, int param1, int param2)
{
    pic.add(new Circle(0, 0, "Circle_" + to_string(i), double(i) * double(param1)));
    //pic.add(new Rectangle(0, 0, "Rectangle_" + to_string(i), i * param1, i * param2));
    /*pic.print_all();
    pic.draw_all();*/
    //pic.add(new Rectangle(0,0,"Rectangle_" + to_string(i), i * param1, i * param2));
    //pic.add(new Triangle(0,0,"Triangle_" + to_string(i), i * param1, i * param2));
    //pic.add(new Square(0,0,"Square_" + to_string(i), i * param1));

}

int main()
{
    cout << "helloworld" << endl;
    //cin >> s;
    Picture * collage = new Picture();
    for (int i = 1; i <= N_TESTS; ++i)
        add_shapes(*collage, 1, 2, 3);

    /*collage.print_all();*/
    delete collage;
    _CrtDumpMemoryLeaks();
    //Sleep(2000);
    cout << "hello" << endl;

    return 0;
}

