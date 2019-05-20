#include "putellipsoid.h"


/*!
      Este é o construtor da classe PutEllipsoid.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
      \param r é o canal de cor vermelho.
      \param g é o canal de cor verde.
      \param b é o canal de cor azul.
      \param a é a transparência da figura.
    */

PutEllipsoid::PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    this->xc = _xc;
    this->yc = _yc;
    this->zc = _zc;
    this->rx = _rx;
    this->ry = _ry;
    this->rz = _rz;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

PutEllipsoid::~PutEllipsoid()
{

}

/*!
      Este método desenha um elipsóide de raio determinado pelo usuário e centrado nas coordenadas x y z determinadas pelo usuário.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
    */
void PutEllipsoid::draw(Sculptor &t)
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

    t.setColor(r, g, b, a);
    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xc;
                diffy = j - yc;
                diffz = k - zc;
                aux = ( (diffx*diffx)/(rx_f*rx_f))  + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f)) ;
                if (aux <= 1){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }

}
