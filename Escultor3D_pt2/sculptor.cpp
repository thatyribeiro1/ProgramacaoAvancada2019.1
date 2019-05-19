#include "sculptor.h"
#include <iostream>
#include <fstream>


/*!
      Este é o construtor da classe Escultor.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param _nz é a quantidade de elementos na dimensao z.
      \param v é o voxel criado.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
      \param isOn habilita o voxel (isOn=1) ou desabilita (isOn=0).
    */


Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 0;
    v = new Voxel**[nx];
    int i,j,k;

    for (i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];
        for (j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
            for (k = 0; k <nz; k++) {
                v[i][j][k].r = 0;
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].isOn = false;
            }
        }
    }
}

/*!
      Este é o destrutor da classe Escultor.
      \param _nx é a quantidade de elementos na dimensao x.
      \param _ny é a quantidade de elementos na dimensao y.
      \param v é o voxel criado.
      \param i, j são contadores.
    */
Sculptor::~Sculptor()
{
    int i,j;
    for (i = 0; i < nx; i++){
        for (j = 0; j < ny; j++) {
            delete [] v[i][j];
        }
        delete [] v[i];
    }
    if (v != NULL)
    {
        delete []v;
        v = NULL;
    }
}

/*!
      Este método seleciona as cores desejadas para os voxels.
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.
      \param isOn habilita o voxel (isOn=1) ou desabilita (isOn=0).
    */

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

/*!
      Este método habilita os voxels desejados e atribui a coloração determinada pelo usuário.
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.
      \param isOn habilita o voxel (isOn=1).
      \param r se refere a cor vermelha.
      \param g se refere a cor verde.
      \param b se refere a cor azul.
      \param a se refere a transparencia do voxel.

    */

void Sculptor::putVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
        v[x][y][z].isOn = true;
        v[x][y][z].r = this->r;
        v[x][y][z].g = this->g;
        v[x][y][z].b = this->b;
        v[x][y][z].a = this->a;
    }

}

/*!
      Este método desabilita os voxels desejados e atribui a coloração determinada pelo usuário.
      \param isOn desabilita o voxel (isOn=0).
      \param x posição na dimensao x.
      \param y posição na dimensao y.
      \param z posição na dimensao z.

    */

void Sculptor::cutVoxel(int x, int y, int z)
{
    if (x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
    v[x][y][z].isOn = false;
    }
}

/*!
      Este método escreve o arquivo .OFF.
      \param filename é o destino do arquivo criado.
    */

void Sculptor::writeOFF(string filename)
{
    const char* name = filename.c_str();
    // int n_voxels = nx * ny * nz;
    char corA[10], corR[10], corG[10], corB[10];
    int n_voxelsOn = 0;
    ofstream outfile (name);
    outfile << "OFF" << "\n";
    //cada voxel é o centro de um cubo (1 voxel = 8 vertices = 6 faces)

    for (int i=0; i < nx; i++) {
        for (int j=0; j < ny; j++) {
            for (int k=0; k < nz; k++) {
                if (v[i][j][k].isOn == true){
                    n_voxelsOn = n_voxelsOn +1;
                }
            }
        }

    }

    int n_vertices = n_voxelsOn*8;

    outfile <<n_vertices  <<" " << n_voxelsOn*6 << " " << 0 << "\n";

    float matcoord[8][3];

    matcoord[0][0] = - 0.5;
    matcoord[0][1] =  0.5;
    matcoord[0][2] = - 0.5;

    matcoord[1][0] = - 0.5;
    matcoord[1][1] = - 0.5;
    matcoord[1][2] = - 0.5;

    matcoord[2][0] = + 0.5;
    matcoord[2][1] = - 0.5;
    matcoord[2][2] = - 0.5;

    matcoord[3][0] = + 0.5;
    matcoord[3][1] = + 0.5;
    matcoord[3][2] = - 0.5;

    matcoord[4][0] = - 0.5;
    matcoord[4][1] = + 0.5;
    matcoord[4][2] = + 0.5;


    matcoord[5][0] = - 0.5;
    matcoord[5][1] = - 0.5;
    matcoord[5][2] = + 0.5;


    matcoord[6][0] = + 0.5;
    matcoord[6][1] = - 0.5;
    matcoord[6][2] = + 0.5;

    matcoord[7][0] = + 0.5;
    matcoord[7][1] = + 0.5;
    matcoord[7][2] = + 0.5;

    int current_voxel = 0;

    for (int i=0; i < nx; i++) {
        for (int j=0; j < ny; j++) {
            for (int k=0; k < nz; k++) {
                if (v[i][j][k].isOn == true){

                    for (int aux = 0; aux < 8; aux++) {
                        outfile << i + matcoord[aux][0] <<" " << j + matcoord[aux][1] << " " << k + matcoord[aux][2] << "\n";

                    }
                    current_voxel = current_voxel + 1;

                }

            }

        }

    }

    int mat_faces [6][4];

    mat_faces[0][0] = 0;
    mat_faces[0][1] = 3;
    mat_faces[0][2] = 2;
    mat_faces[0][3] = 1;

    mat_faces[1][0] = 4;
    mat_faces[1][1] = 5;
    mat_faces[1][2] = 6;
    mat_faces[1][3] = 7;


    mat_faces[2][0] = 0;
    mat_faces[2][1] = 1;
    mat_faces[2][2] = 5;
    mat_faces[2][3] = 4;

    mat_faces[3][0] = 0;
    mat_faces[3][1] = 4;
    mat_faces[3][2] = 7;
    mat_faces[3][3] = 3;

    mat_faces[4][0] = 3;
    mat_faces[4][1] = 7;
    mat_faces[4][2] = 6;
    mat_faces[4][3] = 2;

    mat_faces[5][0] = 1;
    mat_faces[5][1] = 2;
    mat_faces[5][2] = 6;
    mat_faces[5][3] = 5;

    current_voxel = 0;

    for (int i=0; i < nx; i++) {
        for (int j=0; j < ny; j++) {
            for (int k=0; k < nz; k++) {
                int shift = current_voxel*8;
                if (v[i][j][k].isOn == true){
                    for (int aux = 0 ; aux < 6; aux++) {

                        sprintf(corR, "%.2f", v[i][j][k].r);
                        sprintf(corG, "%.2f", v[i][j][k].g);
                        sprintf(corB, "%.2f", v[i][j][k].b);
                        sprintf(corA, "%.2f", v[i][j][k].a);


                        outfile << 4 << " " << (mat_faces[aux][0] + shift) << " " << (mat_faces[aux][1] + shift) << " " << (mat_faces[aux][2] + shift) << " " << (mat_faces[aux][3] + shift) << " " << corR << " " << corG << " " << corB << " " << corA << "\n";

                    }

                    current_voxel = current_voxel +1;

                }

            }
        }
    }

}

/*!
      Este método escreve o arquivo .VECT.
      \param filename é o destino do arquivo criado.
    */

void Sculptor::writeVECT(string filename)
{
    const char* name = filename.c_str();
    char corA[10], corR[10], corG[10], corB[10];
    int n_voxels = nx * ny * nz;
    ofstream outfile (name);
    outfile << "VECT" << "\n";

    //conta os numeros de voxels validos
    int n_voxelsOn = 0;
    for (int i = 0 ; i <= (nx-1); i++) {
        for (int j = 0; j <=  (ny-1); j++) {
            for (int k = 0; k <= (nz-1); k++) {
                if (v[i][j][k].isOn == true)
                    n_voxelsOn = n_voxelsOn + 1;
            }
        }
    }

    outfile << n_voxelsOn <<" " << n_voxelsOn << " " << n_voxelsOn << "\n";
    for (int var = 0; var < n_voxelsOn; ++var) {
        if (var< n_voxels-1){
            outfile << 1 <<" ";
        }else{
            outfile << 1;
        }
    }
    outfile << "\n" ;
    for (int var = 0; var < n_voxelsOn; ++var) {
        if (var< n_voxels-1){
            outfile << 1 <<" ";
        }else{
            outfile << 1;
        }
    }
    outfile << "\n" ;
    for (int i = 0 ; i <= (nx-1); i++) {
        for (int j = 0; j <=  (ny-1); j++) {
            for (int k = 0; k <= (nz-1); k++) {
                if (v[i][j][k].isOn == true){
                    outfile << i <<" " << j << " " << k << "\n" ;
                }
            }
        }
    }

    for (int i = 0 ; i <= (nx-1); i++) {
        for (int j = 0; j <=  (ny-1); j++) {
            for (int k = 0; k <= (nz-1); k++) {
                if (v[i][j][k].isOn == true){
                    sprintf(corR, "%.2f", v[i][j][k].r);
                    sprintf(corG, "%.2f", v[i][j][k].g);
                    sprintf(corB, "%.2f", v[i][j][k].b);
                    sprintf(corA, "%.2f", v[i][j][k].a);
                    outfile << corR <<" " << corG << " " << corB << " " << corA << "\n";
                }

            }
        }
    }

}
