#include "Picture.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"

#define N_TESTS 10


using namespace std;


void add_shapes(Picture& pic, int i, int param1, int param2) {
	pic.add(new Circle(0, 0, "Circle_" + to_string(i), i * param1));
	pic.add(new Rectangle(0, 0, "Rectangle_" + to_string(i), i * param1, i * param2));
	pic.draw_all();
	//pic.print_all();
}

int main() {
	Picture pic;
	add_shapes(pic, 1, 10, 15);

}