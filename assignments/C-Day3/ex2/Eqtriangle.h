#ifndef _EQTRIANGLE
#define _EQTRIANGLE

#include <cmath>

#include "ColoredShape.h"

class Eqtriangle: public ColoredShape {
  public:
    Eqtriangle(double h, string color);
    ~Eqtriangle();
    double getArea(void);
    void printArea(std::ostream &s);

  protected:

  private:
    double h;
};

#endif // _EQTRIANGLE
