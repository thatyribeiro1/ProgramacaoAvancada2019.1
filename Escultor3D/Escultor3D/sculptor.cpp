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
    delete []v;
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
      Este método desenha um cubo no intervalo definido pelo usuário.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
    */

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    //draw a cube with
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                putVoxel(i,j,k);
            }
        }
    }
}

/*!
      Este método recorta um cubo no intervalo definido pelo usuário.
      \param x0 posição inicial na dimensao x.
      \param x1 posição final na dimensao x.
      \param y0 posição inicial na dimensao y.
      \param y1 posição final na dimensao y.
      \param z0 posição inicial na dimensao z.
      \param z1 posição final na dimensao z.
    */

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                cutVoxel(i,j,k);
            }
        }
    }
}

/*!
      Este método desenha uma esfera de raio determinado pelo usuário e centrada nas coordenadas x y z determinadas pelo usuário.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param radius raio da esfera
    */

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz, radius2, aux;
    x0 = xcenter - radius;
    x1 = xcenter + radius;
    y0 = ycenter - radius;
    y1 = ycenter + radius;
    z0 = zcenter - radius;
    z1 = zcenter + radius;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xcenter;
                diffy = j - ycenter;
                diffz = k - zcenter;
                radius2 = radius*radius;
                aux = (diffx*diffx) + (diffy*diffy) + (diffz*diffz);
                if (aux <= radius2){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

/*!
      Este método recorta uma esfera de raio determinado pelo usuário e centrada nas coordenadas x y z determinadas pelo usuário.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param radius raio da esfera
    */

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz, radius2, aux;
    x0 = xcenter - radius;
    x1 = xcenter + radius;
    y0 = ycenter - radius;
    y1 = ycenter + radius;
    z0 = zcenter - radius;
    z1 = zcenter + radius;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xcenter;
                diffy = j - ycenter;
                diffz = k - zcenter;
                radius2 = radius*radius;
                aux = (diffx*diffx) + (diffy*diffy) + (diffz*diffz);
                if (aux <= radius2){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
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


void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz;
    float aux,rx_f,ry_f,rz_f;
    rx_f = rx;
    ry_f = ry;
    rz_f = rz;
    x0 = xcenter - rx;
    x1 = xcenter + rx;
    y0 = ycenter - ry;
    y1 = ycenter + ry;
    z0 = zcenter - rz;
    z1 = zcenter + rz;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xcenter;
                diffy = j - ycenter;
                diffz = k - zcenter;
                aux = ( (diffx*diffx)/(rx_f*rx_f))  + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f)) ;
                if (aux <= 1){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

/*!
      Este método recorta um elipsóide de raio determinado pelo usuário e centrado nas coordenadas x y z determinadas pelo usuário.
      \param xcenter centróide na dimensão x.
      \param ycenter centróide na dimensão y.
      \param zcenter centróide na dimensão z.
      \param rx raio do elipsóide na dimensão x.
      \param ry raio do elipsóide na dimensão y.
      \param rz raio do elipsóide na dimensão z.
    */

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    int x1,x0,y1,y0,z1,z0, diffx, diffy, diffz;
    float aux,rx_f,ry_f,rz_f;
    rx_f = rx;
    ry_f = ry;
    rz_f = rz;
    x0 = xcenter - rx;
    x1 = xcenter + rx;
    y0 = ycenter - ry;
    y1 = ycenter + ry;
    z0 = zcenter - rz;
    z1 = zcenter + rz;

    for (int i = x0; i <= x1 ; i++){
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                diffx = i - xcenter;
                diffy = j - ycenter;
                diffz = k - zcenter;
                aux = ( (diffx*diffx)/(rx_f*rx_f) ) + ( (diffy*diffy)/(ry_f*ry_f) ) + ( (diffz*diffz)/(rz_f*rz_f) );
                if (aux <= 1){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

/*!
      Este método desenha na tela os atributos da classe. Utilizado no projeto só para teste intermediário da implementação.

    */
void Sculptor::printFigure()
{
    cout << "red channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].r << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "green channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].g << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "blue channel" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].b << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "alpha" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].a << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }

    cout << "ison" << endl;
    for (int i = 0; i < this->nx ; i++){
        cout << i << endl;
        for (int j = 0; j < this->ny; j++) {
            for (int k = 0; k < this->nz; k++) {
                cout << v[i][j][k].isOn << " " ;
            }
            cout << endl;
        }
        cout << "\n\n";
    }
}

/*!
      Este método escreve o arquivo .OFF.
      \param filename é o destino do arquivo criado.
    */

void Sculptor::writeOFF(string filename)
{
    const char* name = filename.c_str();
    int n_voxels = nx * ny * nz;
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

    float **mat_x = new float*[n_voxelsOn];
    float **mat_y = new float*[n_voxelsOn];
    float **mat_z = new float*[n_voxelsOn];

    for (int i = 0; i < n_voxelsOn; i++) {
        mat_x[i] = new float[8];
    }
    for (int i = 0; i < n_voxelsOn; i++) {
        mat_y[i] = new float[8];
    }
    for (int i = 0; i < n_voxelsOn; i++) {
        mat_z[i] = new float[8];
    }

    int current_voxel = 0;




    for (int i=0; i < nx; i++) {
        for (int j=0; j < ny; j++) {
            for (int k=0; k < nz; k++) {
                if (v[i][j][k].isOn == true){
                    mat_x[current_voxel][0] = i - 0.5;
                    mat_y[current_voxel][0] = j + 0.5;
                    mat_z[current_voxel][0] = k - 0.5;

                    mat_x[current_voxel][1] = i - 0.5;
                    mat_y[current_voxel][1] = j - 0.5;
                    mat_z[current_voxel][1] = k - 0.5;

                    mat_x[current_voxel][2] = i + 0.5;
                    mat_y[current_voxel][2] = j - 0.5;
                    mat_z[current_voxel][2] = k - 0.5;

                    mat_x[current_voxel][3] = i + 0.5;
                    mat_y[current_voxel][3] = j + 0.5;
                    mat_z[current_voxel][3] = k - 0.5;

                    mat_x[current_voxel][4] = i - 0.5;
                    mat_y[current_voxel][4] = j + 0.5;
                    mat_z[current_voxel][4] = k + 0.5;

                    mat_x[current_voxel][5] = i - 0.5;
                    mat_y[current_voxel][5] = j - 0.5;
                    mat_z[current_voxel][5] = k + 0.5;

                    mat_x[current_voxel][6] = i + 0.5;
                    mat_y[current_voxel][6] = j - 0.5;
                    mat_z[current_voxel][6] = k + 0.5;

                    mat_x[current_voxel][7] = i + 0.5;
                    mat_y[current_voxel][7] = j + 0.5;
                    mat_z[current_voxel][7] = k + 0.5;

                    for (int aux = 0; aux < 8; aux++) {
                        outfile <<mat_x[current_voxel][aux] <<" " << mat_y[current_voxel][aux] << " " << mat_z[current_voxel][aux] << "\n";

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

    for (int i = 0; i < n_voxelsOn; i++) {
        delete [] mat_x[i];
        delete [] mat_y[i];
        delete [] mat_z[i];

    }
    delete [] mat_x;
    delete [] mat_y;
    delete [] mat_z;
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
