#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Eqtriangle.h"

#include <list>
#include <vector>

typedef std::list<ColoredShape*> Container;
//typedef std::vector<ColoredShape*> Container;

typedef Container::iterator Iter;

int main(int argc, char **argv) {
  Container theShapes;

  ColoredShape *s1 = new Circle(2.0, "red");
  ColoredShape *s2 = new Rectangle(1.0, 2.0, "blue");
  ColoredShape *s3 = new Rectangle(3.0,2.0, "green");
  ColoredShape *s4 = new Ellipse(3.0,2.0, "purple");
  ColoredShape *s5 = new Eqtriangle(1.0, "magenta");
  
  theShapes.push_front(s1);
  theShapes.push_front(s2);
  theShapes.push_front(s3);
  theShapes.push_front(s4);
  theShapes.push_front(s5);

  Iter it;  
  for (it = theShapes.begin(); it != theShapes.end(); it++) {
    (*it)->printArea(std::cout);
    delete *it;
  }

  return 0;
}


