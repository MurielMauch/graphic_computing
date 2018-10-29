
// Para executar:
// gcc -c cg2d.c
// gcc exemplo_2d.c -o exemplo_2d cg2d.o -lm -lX11
// ./exemplo_2d

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * monitor;
  window * janela;
  viewport * porta;
  object * poligono1, * poligono2, * poligono3;
  
  SetWorld(-20, -20, 10, 15); // Define o tamanho do mundo  
  monitor = CreateBuffer(640,480); // Cria um monitor virtual
  // monitor = CreateBuffer(1024,768); // conforme solicitado
  
  palheta = CreatePalette(5);  // Cria um colormap
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  poligono1 = CreateObject(9);
  poligono2 = CreateObject(4);
  poligono3 = CreateObject(4);
  
  SetObject(SetPoint(-6.0,-1.0,1,3), poligono1);
  SetObject(SetPoint(-6.0,7.0,1,3), poligono1);
  SetObject(SetPoint(-3.0,7.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,6.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,4.0,1,3), poligono1);
  SetObject(SetPoint(-3.0,3.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,2.0,1,3), poligono1);
  SetObject(SetPoint(-2.0,0.0,1,3), poligono1);
  SetObject(SetPoint(-3.0,-1.0,1,3), poligono1);
  
  SetObject(SetPoint(-5.0,0.0,1,3), poligono2);
  SetObject(SetPoint(-5.0,2.0,1,3), poligono2);
  SetObject(SetPoint(-3.25,2.0,1,3), poligono2);
  SetObject(SetPoint(-3.25,0.0,1,3), poligono2);

  SetObject(SetPoint(-5.0,4.0,1,3), poligono3);
  SetObject(SetPoint(-5.0,6.0,1,3), poligono3);
  SetObject(SetPoint(-3.25,6.0,1,3), poligono3);
  SetObject(SetPoint(-3.25,4.0,1,3), poligono3);
  
  janela = CreateWindow(-20.0, -20.0, 10.0, 15.0);
  porta = CreateViewPort(0, 0, 639, 479);
  
  DrawObject(poligono1,janela,porta,monitor,3);
  DrawObject(poligono2,janela,porta,monitor,3);
  DrawObject(poligono3,janela,porta,monitor,3);
 
  Dump2X(monitor,palheta);
 
  return 0;
  }

