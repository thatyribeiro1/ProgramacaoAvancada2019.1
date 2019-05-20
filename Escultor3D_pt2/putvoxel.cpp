#include "putvoxel.h"


/*!
      Este é o construtor da classe PutVoxel.
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.
      \param isOn habilita o voxel (isOn=1).
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.

    */
PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
    this->r = _r;
    this->g = _g;
    this->b = _b;
    this->a = _a;
}

PutVoxel::~PutVoxel()
{

}
/*!
      Este método habilita os voxels desejados e atribui a coloração determinada pelo usuário.

    */
void PutVoxel::draw(Sculptor &t)
{
    t.setColor(this->r, this->g, this->b, this->a);
    t.putVoxel(x, y, z);
}
