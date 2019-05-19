#ifndef PUTBOX_H
#define PUTBOX_H

#include "sculptor.h"
#include "FiguraGeometrica.h"

class PutBox : public FiguraGeometrica
{
public:
   PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a);
   ~PutBox();

   void draw(Sculptor &t);

protected:
 int x0,x1, y0, y1, z0, z1;
 float r,g,b,a;
};

#endif // PUTBOX_H
