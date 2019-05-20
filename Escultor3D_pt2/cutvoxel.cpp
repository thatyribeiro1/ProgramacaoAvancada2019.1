#include "cutvoxel.h"

/*!
      Este é o construtor da classe CutVoxel.
      \param isOn desabilita o voxel (isOn=0).
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.

    */

CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

CutVoxel::~CutVoxel()
{

}

/*!
      Este método desabilita os voxels desejados e atribui a coloração determinada pelo usuário.
      \param isOn desabilita o voxel (isOn=0).
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.

    */
void CutVoxel::draw(Sculptor &t)
{
   t.cutVoxel(x, y, z);
}
