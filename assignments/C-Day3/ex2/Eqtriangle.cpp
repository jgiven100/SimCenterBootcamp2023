#include "Eqtriangle.h"

Eqtriangle::~Eqtriangle() {
  std::cout << "Eqtriangle Destructor\n";
}

Eqtriangle::Eqtriangle(double height, string color)
  :ColoredShape(color)
{
  h = height;
}

double
Eqtriangle::getArea(void) {
  return (h * h) / std::sqrt(3);
}

void
Eqtriangle::printArea(std::ostream & s) {
  s << "Eqtriangle: color: " << this->getColor() << ", area: " << this->getArea() << "\n";
}
