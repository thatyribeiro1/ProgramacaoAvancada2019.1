#include <iostream>
#include "sculptor.h"
#include "FiguraGeometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putvoxel.h"
#include "cutvoxel.h"

#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

//funcao criada para separar a string proveniente do arquivo de entrada a ser lido
//cada posicao de tokens é uma string

vector<string> split_string(string s)
{
    vector<string> tokens;
    size_t pos = 0;
    while (true)
    {
        pos = s.find(' ');
        if (pos == string::npos)
        {
            tokens.push_back(s.substr(0, s.size()));
            break;
        }
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + 1);

    }

    return tokens;
}


int main()
{
    vector<string> commands;

    Sculptor* sculpt = NULL;

    ifstream myfile;
    //myfile.open ("C:/Users/thaty/Documents/Escultor3D_pt2/Escultura_cubos.txt");
    //myfile.open ("C:/Users/thaty/Documents/Escultor3D_pt2/Escultura_esferas.txt");
    myfile.open ("C:/Users/thaty/Documents/Escultor3D_pt2/Escultura_ellipsoid.txt");

    if(myfile.is_open()){
        cout << "arquivo foi aberto\n";
      }
      else{
        cout << "arquivo nao foi aberto\n";
        exit(1);
      }

    string line;

    while (getline(myfile, line))
    {
        commands.push_back(line);
    }
    myfile.close();

   vector<FiguraGeometrica *> fgs;

    for (size_t i=0; i < commands.size(); i++)
    {
        vector<string>comm_args = split_string(commands[i]);

        // comandos
        if(comm_args[0].compare("dim") == 0)
        {
            //atoi - > Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.
            int largura = atoi( comm_args[1].c_str() );
            int altura = atoi( comm_args[2].c_str() );
            int profundidade = atoi( comm_args[3].c_str() );
            if (sculpt != NULL)
            {
                delete sculpt;
            }
            sculpt = new Sculptor(largura, altura, profundidade);
        }
        else if(comm_args[0].compare("putvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );

            float r = atof( comm_args[4].c_str() );
            float g = atof( comm_args[5].c_str() );
            float b = atof( comm_args[6].c_str() );
            float a = atof( comm_args[7].c_str() );
            fgs.push_back( new PutVoxel(x0, y0, z0, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutvoxel") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int y0 = atoi( comm_args[2].c_str() );
            int z0 = atoi( comm_args[3].c_str() );
            fgs.push_back( new CutVoxel(x0, y0, z0)  );
        }
        else if(comm_args[0].compare("putbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutbox") == 0)
        {
            int x0 = atoi( comm_args[1].c_str() );
            int x1 = atoi( comm_args[2].c_str() );
            int y0 = atoi( comm_args[3].c_str() );
            int y1 = atoi( comm_args[4].c_str() );
            int z0 = atoi( comm_args[5].c_str() );
            int z1 = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutBox(x0, x1, y0, y1, z0, z1)  );
        }
        else if(comm_args[0].compare("putsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );


            float r = atof( comm_args[5].c_str() );
            float g = atof( comm_args[6].c_str() );
            float b = atof( comm_args[7].c_str() );
            float a = atof( comm_args[8].c_str() );
            fgs.push_back( new PutSphere(xc, yc, zc, radius, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutsphere") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int radius = atoi( comm_args[4].c_str() );
            fgs.push_back( new CutSphere(xc, yc, zc, radius)  );
        }
        else if(comm_args[0].compare("putellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );


            float r = atof( comm_args[7].c_str() );
            float g = atof( comm_args[8].c_str() );
            float b = atof( comm_args[9].c_str() );
            float a = atof( comm_args[10].c_str() );
            fgs.push_back( new PutEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a)  );
        }
        else if(comm_args[0].compare("cutellipsoid") == 0)
        {
            int xc = atoi( comm_args[1].c_str() );
            int yc = atoi( comm_args[2].c_str() );
            int zc = atoi( comm_args[3].c_str() );
            int rx = atoi( comm_args[4].c_str() );
            int ry = atoi( comm_args[5].c_str() );
            int rz = atoi( comm_args[6].c_str() );
            fgs.push_back( new CutEllipsoid(xc, yc, zc, rx, ry, rz)  );

        }
        else
        {
            cout << "invalid command" << endl;
        }

    }

    if(sculpt != NULL)
    {
        for(size_t i=0; i < fgs.size(); i++)
        {
            fgs[i]->draw(*sculpt);
        }

        //sculpt->writeOFF("C:/Users/thaty/Documents/Escultor3D_pt2/OFF_files/Esculturas_cubos.off");
        //sculpt->writeOFF("C:/Users/thaty/Documents/Escultor3D_pt2/OFF_files/Esculturas_esferas.off");
        sculpt->writeOFF("C:/Users/thaty/Documents/Escultor3D_pt2/OFF_files/Esculturas_ellipsoid.off");
        delete sculpt;
    }

    return 0;
}
