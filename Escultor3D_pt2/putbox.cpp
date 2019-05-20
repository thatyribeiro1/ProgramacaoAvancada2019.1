#include "putbox.h"

/*!
      Este é o construtor da classe PutBox.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
    */
PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    this->x0 = _x0;
    this->x1 = _x1;
    this->y0 = _y0;
    this->y1 = _y1;
    this->z0 = _z0;
    this->z1 = _z1;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

PutBox::~PutBox()
{

}

/*!
      Este método desenha um cubo no intervalo definido pelo usuário.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
    */
void PutBox::draw(Sculptor &t)
{
    //draw a cube with
    t.setColor(r, g, b, a);
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                t.putVoxel(i,j,k);
            }
        }
    }
}
