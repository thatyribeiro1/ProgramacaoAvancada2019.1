#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "sculptor.h"
#include "FiguraGeometrica.h"

class CutEllipsoid : public FiguraGeometrica
{
public:
   CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz);
   ~CutEllipsoid();

   void draw(Sculptor &t);

protected:
 int xc, yc, zc, rx, ry, rz;
};

#endif // CUTELLIPSOID_H
