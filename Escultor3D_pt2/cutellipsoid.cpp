#include "cutellipsoid.h"


CutEllipsoid::CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->rx = _rx;
    this->ry = _ry;
    this->rz = _rz;
}

CutEllipsoid::~CutEllipsoid()
{

}

void CutEllipsoid::draw(Sculptor &t)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz;
    float aux,rx_f,ry_f,rz_f;
    rx_f = rx;
    ry_f = ry;
    rz_f = rz;
    x0 = xc - rx;
    x1 = xc + rx;
    y0 = yc - ry;
    y1 = yc + ry;
    z0 = zc - rz;
    z1 = zc + rz;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                aux = ( (diffx*diffx)/(rx_f*rx_f))  + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f)) ;
                if (aux <= 1){
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }

}
