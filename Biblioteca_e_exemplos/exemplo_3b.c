// Para executar:
// gcc -c cg2d.c
// gcc exemplo_3b.c -o exemplo_3b cg2d.o -lm -lX11
// ./exemplo_3b

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta;
  object * poligono1, * poligono2, * poligono3;
  
  SetWorld(-20, -20, 10, 15); // Define o tamanho do mundo  
  monitor = CreateBuffer(640,480); // Cria um monitor virtual
  
  palheta = CreatePalette(5);  // Cria um colormap
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);
  poligono3 = CreateObject(4);
  
  SetObject(SetPoint(-9.0,-8.0,1,1), poligono1);
  SetObject(SetPoint(-7.0,-3.0,1,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1,1), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-1.0,-2.0,1,3), poligono2);
  SetObject(SetPoint(-1.0,-6.0,1,3), poligono2);
  SetObject(SetPoint(-6.0,-6.0,1,3), poligono2);

  SetObject(SetPoint(-6.0,-2.0,1,3), poligono3);
  SetObject(SetPoint(-1.0,-2.0,1,3), poligono3);
  SetObject(SetPoint(-1.0,-6.0,1,3), poligono3);
  SetObject(SetPoint(-6.0,-6.0,1,3), poligono3);
  
  // Translação para centralizar a figura 
  poligono1 = TranslateObj(poligono1, 5.0, 5.0);
  poligono2 = TranslateObj(poligono2, 5.0, 5.0);

  // Traslação do polinogo3 para a origem
  poligono3 = TranslateObj(poligono3, 6.0, 6.0);
  // Rotação do poligono3
  poligono3 = RotateObj(poligono3, 45);
  // Translação do poligono3 para as coordenadas iniciais
  poligono3 = TranslateObj(poligono3, -1.0, -1.0);

  // Escalonamento
  poligono1 = ScaleObj(poligono1, 0.2, 0.2);
  poligono2 = ScaleObj(poligono2, 0.2, 0.2);
  poligono3 = ScaleObj(poligono3, 0.2, 0.2);

  janela = CreateWindow(-2.0, -2.0, 2.0, 2.0);
  porta = CreateViewPort(215, 95, 470, 340); // 300x200
  
  DrawObject(poligono1,janela,porta,monitor,1);
  DrawObject(poligono2,janela,porta,monitor,3);
  DrawObject(poligono3,janela,porta,monitor,2);
 
  Dump2X(monitor,palheta);
 
  return 0;
  }

