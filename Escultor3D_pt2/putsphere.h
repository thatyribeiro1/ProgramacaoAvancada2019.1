#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "sculptor.h"
#include "FiguraGeometrica.h"

class PutSphere : public FiguraGeometrica
{
public:
   PutSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b, float _a);
   ~PutSphere();

   void draw(Sculptor &t);

protected:
 int xc, yc, zc, radius;
 float r,g,b,a;
};

#endif // PUTSPHERE_H
