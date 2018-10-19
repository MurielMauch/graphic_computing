#include "cg2d.h"

/**
 * como compilar
 * gcc -c cg2d.c
 * gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11
 */

int main(int argc, char ** argv) {
    palette * palheta;
    bufferdevice * dispositivo;
    viewport * view;
    window * janela;
    hobject * poligono1, * poligono2, * poligono3, * poligono4;
    
    SetWorld(-20, 10, -20, 15); 
    dispositivo = CreateBuffer(1024,768);

    /**
     *  o tamanho da janela é independente do tamanho da viewport
     *  view = (viewport *)malloc(sizeof(viewport));
     *  view->xmin = 0;
     *  view->xmax = 1024;
     *  view->ymin = 0;
     *  view->ymax = 768; 
     **/

    view = (viewport *)malloc(sizeof(viewport));
    view->xmin = 0;
    view->xmax = 1024;
    view->ymin = 0;
    view->ymax = 768;

    palheta = CreatePalette(6);  
    SetColor(0,0,0,palheta);
    SetColor(1,0,0,palheta);
    SetColor(0,1,0,palheta);
    SetColor(0,0,1,palheta);
    SetColor(1,1,1,palheta);

    poligono1 = HCreateObject(7);
    poligono2 = HCreateObject(3);

    HSetObject(HSetPoint(-6.0,-1.0,2), poligono1);
    HSetObject(HSetPoint(-11.0,-11.0,2), poligono1);
    HSetObject(HSetPoint(-9.0,-11.0,2), poligono1);
    HSetObject(HSetPoint(-8.0,-9.0,2), poligono1);
    HSetObject(HSetPoint(-4.0,-9.0,2), poligono1);
    HSetObject(HSetPoint(-3.0,-11.0,2), poligono1);
    HSetObject(HSetPoint(-1.0,-11.0,2), poligono1);

    HSetObject(HSetPoint(-8.0,-8.0,2), poligono2);
    HSetObject(HSetPoint(-4.0,-8.0,2), poligono2);
    HSetObject(HSetPoint(-6.0,-5.0,2), poligono2);
    
    /*
    poligono3 = Skew(poligono1,-1,0);
    poligono4 = Skew(poligono2,-1,0);
    */

    // float xmin, float xmax, float ymin, float ymax
    // janela = CreateWindow(-15.0,2.0,-15.0,2.0);
    janela = CreateWindow(-20.0,12.0,-20.0,12.0);

    DrawObject(poligono1,janela,dispositivo,view);  // exterior
    DrawObject(poligono2,janela,dispositivo,view);  // interior
    
    Dump2X(dispositivo,palheta);
    
    return 0;
}