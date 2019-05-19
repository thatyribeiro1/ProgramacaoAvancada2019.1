#include "cutbox.h"



CutBox::CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1)
{
    this->x0 = _x0;
    this->x1 = _x1;
    this->y0 = _y0;
    this->y1 = _y1;
    this->z0 = _z0;
    this->z1 = _z1;
}

CutBox::~CutBox()
{

}

void CutBox::draw(Sculptor &t)
{
    //draw a cube with
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                t.cutVoxel(i,j,k);
            }
        }
    }
}
