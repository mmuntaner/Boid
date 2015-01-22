#include <stdio.h>
#include "bwindow.h"
#include "environnement.h"
#include "vector.h"
#include "agent.h"
#include "proie.h"
#include "predateur.h"


int main()
{
  printf("Hello World !\n");

  environnement test(50,2);

  proie* tableau = test.Get_TabProie();
  obstacle* tabO = test.Get_TabObstacle();

/*

  for (int i=0; i<test.Get_nbProie(); i++)
  {
  	tableau[i].Get_pos().affichevector();
    tableau[i].Get_vit().affichevector();
  	
  }


  test.MouvProie();

  printf("\n");


  for (int i=0; i<test.Get_nbProie(); i++)
  {
    tableau[i].Get_pos().affichevector();
    tableau[i].Get_vit().affichevector();
    
  }

  */

  
 bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
	int ev = win.parse_event();
	switch(ev)
	{
	    case BKPRESS :
		printf("keypressed\n"); 
    /*win.draw_fsquare(0,0,640,480,0xFFFFFF);
		for (int i=0; i<test.Get_nbProie();i++)
 			 {  					
				win.draw_fsquare(tableau[i].Get_pos().Get_X()-2,tableau[i].Get_pos().Get_Y()-2,tableau[i].Get_pos().Get_X()+2,tableau[i].Get_pos().Get_Y()+2,0xFF0000);
			}
    test.MouvProie();  */
		printf("key : %s\n",win.get_lastkey());
		break;
	    case BBPRESS:

		printf("buttonpressed\n"); break;
	    case BEXPOSE:
		printf("expose\n"); break;
	    case BCONFIGURE:
		printf("configure\n"); break;
	}
  win.draw_fsquare(0,0,640,480,0xFFFFFF);
  for (int i=0; i<test.Get_nbObstacle();i++)
       {            
        win.draw_fsquare(tabO[i].Get_pos().Get_X()-4,tabO[i].Get_pos().Get_Y()-4,tabO[i].Get_pos().Get_X()+4,tabO[i].Get_pos().Get_Y()+4,0xFF0);
      }

  for (int i=0; i<test.Get_nbProie();i++)
       {            
        win.draw_fsquare(tableau[i].Get_pos().Get_X()-2,tableau[i].Get_pos().Get_Y()-2,tableau[i].Get_pos().Get_X()+2,tableau[i].Get_pos().Get_Y()+2,0xFF0000);
      }
    test.MouvProie();  
	//win.draw_point(300,300,0xFF00);
	//win.draw_line(400,400,640,480,0xFF0000); // Coordonnées du point de départ et d'arrivée.
	//win.draw_text(10,10,0x0,"Hello World",strlen("Hello World")); // Coordonées du point de départ / le texte / la taille du texte
	//win.draw_square(200,200,220,220,0xFF0000); //Rectangle FF0000 Rouge FF00 Vert FF0 Bleu
	//win.draw_fsquare(10,200,440,440,0xFF00);  // Rectangle rempli
    }

    
  
    return 0;
}
