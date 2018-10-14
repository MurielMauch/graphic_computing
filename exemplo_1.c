
// gcc -c cg2d.c
// gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11 

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  viewport * vp;
  hobject *hpoligono1, *hpoligono2, *hpoligono3, *hpoligono4;
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo

  vp = (viewport *)malloc(sizeof(viewport));
  vp->xmin = 0;
  vp->xmax = 640;
  vp->ymin = 0;
  vp->ymax = 480;
  
  palheta = CreatePalette(6);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);

  hpoligono1 = HCreateObject(5);
  hpoligono2 = HCreateObject(4);
  hpoligono3 = HCreateObject(4);

  HSetObject(HSetPoint(-9.0, -8.0, 1), hpoligono1);
  HSetObject(HSetPoint(-7.0, -3.0, 1), hpoligono1);
  HSetObject(HSetPoint(-4.0, -4.0, 1), hpoligono1);
  HSetObject(HSetPoint(-3.0, -6.0, 1), hpoligono1);
  HSetObject(HSetPoint(-6.0, -9.0, 1), hpoligono1);

  HSetObject(HSetPoint(-6.0, -2.0, 3), hpoligono2);
  HSetObject(HSetPoint(-1.0, -2.0, 3), hpoligono2);
  HSetObject(HSetPoint(-1.0, -6.0, 3), hpoligono2);
  HSetObject(HSetPoint(-6.0, -6.0, 3), hpoligono2);

  HSetObject(HSetPoint(0.0, 4.0, 2), hpoligono3);
  HSetObject(HSetPoint(3.0, 4.0, 2), hpoligono3);
  HSetObject(HSetPoint(3.0, 0.0, 2), hpoligono3);
  HSetObject(HSetPoint(0.0, 0.0, 2), hpoligono3);

  hpoligono4 = Skew(hpoligono3,-1,0);
  
  janela = CreateWindow(-10.0,5.0,-10.0,5.0);  

  HDrawObject(hpoligono1, janela, vp, dispositivo); 
  HDrawObject(hpoligono2, janela, vp, dispositivo); 
  // HDrawObject(hpoligono3, janela, vp, dispositivo); 
  HDrawObject(hpoligono4, janela, vp, dispositivo); 
  
  /* 
   * Dispositivo gráfico matricial.
   * A janela de visualização considerada não está adequada para visualizar completamente os dois objetos.
   * Poderiamos considerar a janela definida pelos pontos (-10,-10) e (0,0)
   */
  
  Dump2X(dispositivo,palheta);
 
  return 0;
  }
