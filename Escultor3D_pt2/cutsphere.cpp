#include "cutsphere.h"


CutSphere::CutSphere(int _xc, int _yc, int _zc, int _radius)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->radius = _radius;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz, radius2, aux;
    x0 = xc - radius;
    x1 = xc + radius;
    y0 = yc - radius;
    y1 = yc + radius;
    z0 = zc - radius;
    z1 = zc + radius;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                radius2 = radius*radius;
                aux = (diffx*diffx) + (diffy*diffy) + (diffz*diffz);
                if (aux <= radius2){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
