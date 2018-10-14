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
    dispositivo = CreateBuffer(640,480);

    view = (viewport *)malloc(sizeof(viewport));
    view->xmin = 0;
    view->xmax = 640;
    view->ymin = 0;
    view->ymax = 480;

    palheta = CreatePalette(6);  
    SetColor(0,0,0,palheta);
    SetColor(1,0,0,palheta);
    SetColor(0,1,0,palheta);
    SetColor(0,0,1,palheta);
    SetColor(1,1,1,palheta);
    
    poligono1 = HCreateObject(5);
    poligono2 = HCreateObject(4);
    poligono3 = HCreateObject(4);
    
    HSetObject(HSetPoint(-9.0,-8.0,1), poligono1);
    HSetObject(HSetPoint(-7.0,-3.0,1), poligono1);
    HSetObject(HSetPoint(-4.0,-4.0,1), poligono1);
    HSetObject(HSetPoint(-3.0,-6.0,1), poligono1);
    HSetObject(HSetPoint(-6.0,-9.0,1), poligono1);
    
    HSetObject(HSetPoint(-6.0,-2.0,3), poligono2);
    HSetObject(HSetPoint(-1.0,-2.0,3), poligono2);
    HSetObject(HSetPoint(-1.0,-6.0,3), poligono2);
    HSetObject(HSetPoint(-6.0,-6.0,3), poligono2);

    HSetObject(HSetPoint(0.0,4.0,2), poligono3);
    HSetObject(HSetPoint(3.0,4.0,2), poligono3);
    HSetObject(HSetPoint(3.0,0.0,2), poligono3);
    HSetObject(HSetPoint(0.0,0.0,2), poligono3);

    poligono4 = Skew(poligono3,-1,0);

    janela = CreateWindow(-10.0,5.0,-10.0,5.0);

    DrawObject(poligono1,janela,dispositivo,view);
    DrawObject(poligono2,janela,dispositivo,view);
    DrawObject(poligono4,janela,dispositivo,view);
    
    Dump2X(dispositivo,palheta);
    
    return 0;
}