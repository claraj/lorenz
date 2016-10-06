#include <stdio.h>

//this is not how you do string?? freeing memory? arguments helpful here :)!
//todo chart plot library

double P = 10;
double R = 28;
double B = 8.0/3.0;
double dt = 0.01;
int its = 100000;

void writeFile(double x, double y , double z) {

  FILE *fp;

  char filename [150];
  int len = sprintf(filename, "points-%f-%f-%f.csv", x, y, z);

  fp = fopen(filename, "w+");

  fputs("x,y,z\n", fp);

  for ( int t = 1 ; t < its ; t++) {

    //printf("%f", t);
    //dt is 1 so
    double dx = P * (y - x);
    double dy = (x * (R - z) ) - y;
    double dz = (x*y) - (B*z);

    x = x + ( dx * dt);
    y = y + ( dy * dt);
    z = z + ( dz * dt);

    char points [150];
    int len = sprintf(points, "%f,%f,%f\n", x, y, z);
    //printf(points);
    fputs(points, fp);
    //fputs("bloop", fp);

  }

  fclose(fp);

}


int main() {

  /*

  Lorenz attractor

  dx/dt = P(y-x)
  dy/dt = Rx - y - xz
  dz/dt = xy - Bz

  */

  // double x=0.1;
  // double y = 0;
  // double z = 0;

  writeFile(0.1, 0, 0);
  writeFile(0.10001, 0, 0);

  return 0;

}
