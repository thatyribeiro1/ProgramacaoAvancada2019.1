#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "sculptor.h"
#include "FiguraGeometrica.h"

class CutSphere : public FiguraGeometrica
{
protected:
 int xc, yc, zc, radius;

public:
   CutSphere(int _xc, int _yc, int _zc, int _radius);
   ~CutSphere();

   void draw(Sculptor &t);

};

#endif // CUTSPHERE_H
