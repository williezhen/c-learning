#include "Picture.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

using namespace std;

#define N_TESTS 10

void add_shapes(Picture& pic, int i, int param1, int param2) {
	pic.add(new Circle(0, 0, "Circle_" + to_string(i), i * param1));
	pic.add(new Rectangle(0, 0, "Rectangle_" + to_string(i), i * param1, i * param2));
	pic.add(new Triangle(0, 0, "Rectangle_" + to_string(i), i * param1, i * param2));
	cout << pic.total_area() << endl;
	pic.draw_all();
	pic.print_all();
}

int main() {
	Picture pic;
	add_shapes(pic, 1, 10, 15);
}