// Uma possível solução para a atividade exemplo disponibilizada
// no Moodle utizando as funções da biblioteca implementada
// (item f da primeira atividade avaliativa)

// Para executar:
// gcc -c cg2d.c
// gcc exemplo_3c.c -o exemplo_3c cg2d.o -lm -lX11
// ./exemplo_3c

#include "cg2d.h"

int main(int argc, char **argv)
{

  palette *palheta;
  bufferdevice *monitor;
  window *janela;
  viewport *porta;
  object *poligono1, *poligono2;

  SetWorld(-20, -20, 10, 15);       // Define o tamanho do mundo
  monitor = CreateBuffer(640, 480); // Cria um monitor virtual

  palheta = CreatePalette(6); // Cria um colormap
  SetColor(0, 0, 0, palheta);
  SetColor(1, 0, 0, palheta);
  SetColor(0, 1, 0, palheta);
  SetColor(0, 0, 1, palheta);
  SetColor(1, 1, 1, palheta);
  SetColor(1, 0, 1, palheta);

  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);

  SetObject(SetPoint(-9.0, -8.0, 1, 4), poligono1);
  SetObject(SetPoint(-7.0, -3.0, 1, 4), poligono1);
  SetObject(SetPoint(-4.0, -4.0, 1, 4), poligono1);
  SetObject(SetPoint(-3.0, -6.0, 1, 4), poligono1);
  SetObject(SetPoint(-6.0, -9.0, 1, 4), poligono1);

  SetObject(SetPoint(-6.0, -2.0, 1, 3), poligono2);
  SetObject(SetPoint(-1.0, -2.0, 1, 3), poligono2);
  SetObject(SetPoint(-1.0, -6.0, 1, 3), poligono2);
  SetObject(SetPoint(-6.0, -6.0, 1, 3), poligono2);

  janela = CreateWindow(-10.0, -10.0, 0.0, 0.0);
  porta = CreateViewPort(0, 0, 639, 479);

  FillIntersection(poligono1, poligono2, janela, porta, monitor, 1, 3, 2);

  Dump2X(monitor, palheta);

  return 0;
}
