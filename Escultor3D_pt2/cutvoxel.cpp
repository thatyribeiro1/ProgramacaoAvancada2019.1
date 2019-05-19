#include "cutvoxel.h"


CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

CutVoxel::~CutVoxel()
{

}

void CutVoxel::draw(Sculptor &t)
{
   t.cutVoxel(x, y, z);
}
