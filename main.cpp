#include <stdio.h>
#include "bwindow.h"
#include "environnement.h"
#include "vector.h"
#include "agent.h"
#include "proie.h"
#include "predateur.h"


int main()
{


  environnement test(5,8);
  printf("%d\n",test.Get_nbProie() );


	printf("Hello World !\n");

  //proie *tableau[5];
  //proie* tableau = new proie[5];
	proie* tableau =	test.Get_TabProie();

  /*tableau[0]= new proie();
  tableau[1]= new proie();
  tableau[2]= new proie(12, 18);
  tableau[3]= new proie(13,19);
  tableau[4]= new proie(11,17); */

  for (int i=0; i<5; i++)
  {
  	tableau[i].Get_pos().affichevector();
    printf("\n");
    tableau[i].Get_vit().affichevector();
  	
  }

   test.MouvProie();

  printf("\n");

  /*for (int i=0; i<5; i++)
  {
  	tableau[i].Get_speed(tableau,i);
    tableau[i].Get_rank(tableau,i, 1);
    tableau[i].Get_pos().affichevector();
  	tableau[i].Get_vit().affichevector();
   
  }
  /*
  

/*    bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
	int ev = win.parse_event();
	switch(ev)
	{
	    case BKPRESS :
		printf("keypressed\n"); 
		for (int i=0; i<5; i++)
 			 {  					
				win.draw_square(tableau[i]->Get_pos().Get_X()-2,tableau[i]->Get_pos().Get_Y()-2,tableau[i]->Get_pos().Get_X()+2,tableau[i]->Get_pos().Get_Y()+2,0xFF0000);
			}
		printf("key : %s\n",win.get_lastkey());
		break;
	    case BBPRESS:

		printf("buttonpressed\n"); break;
	    case BEXPOSE:
		printf("expose\n"); break;
	    case BCONFIGURE:
		printf("configure\n"); break;
	}
	//win.draw_point(300,300,0xFF00);
	//win.draw_line(400,400,640,480,0xFF0000); // Coordonnées du point de départ et d'arrivée.
	//win.draw_text(10,10,0x0,"Hello World",strlen("Hello World")); // Coordonées du point de départ / le texte / la taille du texte
	//win.draw_square(200,200,220,220,0xFF0000); //Rectangle FF0000 Rouge FF00 Vert FF0 Bleu
	//win.draw_fsquare(200,200,440,440,0xFF00);  // Rectangle rempli
    }

    
  */

    return 0;
}
