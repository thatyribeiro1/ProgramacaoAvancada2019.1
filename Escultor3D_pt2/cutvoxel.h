#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "sculptor.h"
#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica
{
public:
   CutVoxel(int _x, int _y, int _z);
   ~CutVoxel();

   void draw(Sculptor &t);

protected:
 int x,y,z;
 float r,g,b,a;
};

#endif // CUTVOXEL_H
