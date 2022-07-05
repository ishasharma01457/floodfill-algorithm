#include<iostream>
#include<conio.h>
#define M 8
#define N 8
using namespace std;
  void flood(int out[][N], int x, int z, int xColor, int nColor)
{

    if (x < 0 || x >= M || z < 0 || z >= N)
        return;
    if (out[x][z] != xColor)
        return;
    if (out[x][z] == nColor)
        return;


    out[x][z] = nColor;

    flood(out, x+1, z, xColor, nColor);
    flood(out, x-1, z, xColor, nColor);
    flood(out, x, z+1, xColor, nColor);
    flood(out, x, z-1, xColor, nColor);
}

void findColor(int out[][N], int x, int z, int nColor)
{
    int xColor = out[x][z];
    flood(out, x, z, xColor, nColor);
}


int main()
{
    int out[M][N] =
                    {
                      {2, 0, 1, 1, 2, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 3, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 0, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 4, z = 4, nColor = 3;
    findColor(out, x, z, nColor);

    cout << "Updated output : \n";


    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << out[i][j] << " ";
        cout << endl;
    }
    return 0;
}
