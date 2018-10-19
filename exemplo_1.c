#include "cg2d.h"

/**
 * como compilar
 * gcc -c cg2d.c
 * gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11
 */

/**
 * 
 * Respostas da Atividade 2
 * 
 * a) Sim, ocorre uma distorção do objeto.
 * O tamanho da janela é independente do tamanho da viewport, 
 * então quando o conteúdo da janela é mapeado nas dimenões da viewport 
 * (considerando que as da janela e viewport são diferentes)
 * ocorre uma distorção natural do objedo do SRU para o SRD.
 * 
 * b) Após determinar uma janela com dimensões mais adequadas 
 * para a visualização do SRD, o objeto não ocorre mais distorções. 
 * 
*/

int main(int argc, char ** argv) {
    palette * palheta;
    bufferdevice * dispositivo;
    viewport * view, * view1, * view2, * view3;
    window * janela, * janela1, * janela2, * janela3;
    hobject * poligono1, * poligono2;
    hobject * poligono3, * poligono4, * poligono5, * poligono6;
    hobject * poligono7, * poligono8, * poligono9, * poligono10;
    hobject * poligono11, * poligono12, * poligono13, * poligono14;
    
    SetWorld(-20, 20, -20, 20); 
    dispositivo = CreateBuffer(1024,768);

    palheta = CreatePalette(6);  
    SetColor(0,0,0,palheta);
    SetColor(1,0,0,palheta);
    SetColor(0,1,0,palheta);
    SetColor(0,0,1,palheta);
    SetColor(1,1,1,palheta);

    /**
     *  o tamanho da janela é independente do tamanho da viewport
     *  view = (viewport *)malloc(sizeof(viewport));
     *  view->xmin = 0;
     *  view->xmax = 1024;
     *  view->ymin = 0;
     *  view->ymax = 768; 
     **/

    /**
     * this first block draws the original object
    */
    view = (viewport *)malloc(sizeof(viewport));
    view->xmin = 0;
    view->xmax = 250;
    view->ymin = 0;
    view->ymax = 250;

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

    // float xmin, float xmax, float ymin, float ymax
    // janela = CreateWindow(-15.0,2.0,-15.0,2.0);
    janela = CreateWindow(-15.0,2.0,-15.0,2.0);

    DrawObject(poligono1, janela, dispositivo, view);  // exterior
    DrawObject(poligono2, janela, dispositivo, view);  // interior

    /**
     * second
    */
    view1 = (viewport *)malloc(sizeof(viewport));
    view1->xmin = 0;
    view1->xmax = 250;
    view1->ymin = 300;
    view1->ymax = 550;

    poligono3 = HCreateObject(7);
    poligono4 = HCreateObject(3);

    HSetObject(HSetPoint(-6.0,-1.0,3), poligono3);
    HSetObject(HSetPoint(-11.0,-11.0,3), poligono3);
    HSetObject(HSetPoint(-9.0,-11.0,3), poligono3);
    HSetObject(HSetPoint(-8.0,-9.0,3), poligono3);
    HSetObject(HSetPoint(-4.0,-9.0,3), poligono3);
    HSetObject(HSetPoint(-3.0,-11.0,3), poligono3);
    HSetObject(HSetPoint(-1.0,-11.0,3), poligono3);

    HSetObject(HSetPoint(-8.0,-8.0,3), poligono4);
    HSetObject(HSetPoint(-4.0,-8.0,3), poligono4);
    HSetObject(HSetPoint(-6.0,-5.0,3), poligono4);

    poligono5 = Skew(poligono3, -0.3, 0);
    poligono6 = Skew(poligono4, -0.3, 0);

    janela1 = CreateWindow(-15.0,2.0,-15.0,2.0);

    DrawObject(poligono5, janela1, dispositivo, view1);  // exterior
    DrawObject(poligono6, janela1, dispositivo, view1);  // interior

    /**
     * third
    */
    view2 = (viewport *)malloc(sizeof(viewport));
    view2->xmin = 350;
    view2->xmax = 600;
    view2->ymin = 300;
    view2->ymax = 550;

    poligono7 = HCreateObject(7);
    poligono8 = HCreateObject(3);

    HSetObject(HSetPoint(-6.0,-1.0,4), poligono7);
    HSetObject(HSetPoint(-11.0,-11.0,4), poligono7);
    HSetObject(HSetPoint(-9.0,-11.0,4), poligono7);
    HSetObject(HSetPoint(-8.0,-9.0,4), poligono7);
    HSetObject(HSetPoint(-4.0,-9.0,4), poligono7);
    HSetObject(HSetPoint(-3.0,-11.0,4), poligono7);
    HSetObject(HSetPoint(-1.0,-11.0,4), poligono7);

    HSetObject(HSetPoint(-8.0,-8.0,4), poligono8);
    HSetObject(HSetPoint(-4.0,-8.0,4), poligono8);
    HSetObject(HSetPoint(-6.0,-5.0,4), poligono8);

    poligono9 = Skew(poligono7, 0.3, 0);
    poligono10 = Skew(poligono8, 0.3, 0);

    janela2 = CreateWindow(-15.0,2.0,-15.0,2.0);

    DrawObject(poligono9, janela2, dispositivo, view2);  // exterior
    DrawObject(poligono10, janela2, dispositivo, view2);  // interior

    /**
     * forth
    */
    view3 = (viewport *)malloc(sizeof(viewport));
    view3->xmin = 350;
    view3->xmax = 600;
    view3->ymin = 0;
    view3->ymax = 250;

    poligono11 = HCreateObject(7);
    poligono12 = HCreateObject(3);

    HSetObject(HSetPoint(-6.0,1.0,1), poligono11);
    HSetObject(HSetPoint(-11.0,-9.0,1), poligono11);
    HSetObject(HSetPoint(-9.0,-9.0,1), poligono11);
    HSetObject(HSetPoint(-8.0,-7.0,1), poligono11);
    HSetObject(HSetPoint(-4.0,-7.0,1), poligono11);
    HSetObject(HSetPoint(-3.0,-9.0,1), poligono11);
    HSetObject(HSetPoint(-1.0,-9.0,1), poligono11);

    HSetObject(HSetPoint(-8.0,-6.0,1), poligono12);
    HSetObject(HSetPoint(-4.0,-6.0,1), poligono12);
    HSetObject(HSetPoint(-6.0,-3.0,1), poligono12);

    poligono13 = Skew(poligono11, 0.2, 0.2);
    poligono14 = Skew(poligono12, 0.2, 0.2);

    janela3 = CreateWindow(-15.0,2.0,-15.0,2.0);

    DrawObject(poligono13, janela3, dispositivo, view3);  // exterior
    DrawObject(poligono14, janela3, dispositivo, view3);  // interior


    Dump2X(dispositivo,palheta);
    
    return 0;
}