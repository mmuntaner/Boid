//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "environnement.h"




//############################################################################
//                                                                           #
//                           Class environnement                             #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
 const int environnement::W = 640;
 const int  environnement::H = 480;
 const float  environnement::dt=0.179;
 int environnement::ProieMange=0;

 float  environnement::G1 = 0.293;
 float  environnement::G2 = 0.004;
 float  environnement::G3 = 0.589;
 float  environnement::G4 = 0.05;
// ===========================================================================
//                                  Constructors
// ===========================================================================
environnement::environnement(void)
{
	TabProie=NULL;
	nbProie=0;
}

environnement::environnement(int n)
{

	nbProie=n;
	TabProie= new proie [nbProie];
	nbObstacle=0;
	TabObstacle=NULL;
	nbPredateur=0;
	TabPredateur=NULL;

}

environnement::environnement(int p, int o)
{

	nbProie=p;
	TabProie= new proie [nbProie];

	nbObstacle=o;
	TabObstacle = new obstacle [nbObstacle];

	nbPredateur=0;
	TabPredateur=NULL;

}

environnement::environnement(int n, int o, int p)
{

	nbProie=n;
	TabProie= new proie [nbProie];

	nbObstacle=o;
	TabObstacle = new obstacle [nbObstacle];

	nbPredateur=p;
	TabPredateur = new predateur [nbPredateur];

}

// ===========================================================================
//                                  Destructor
// ===========================================================================
environnement::~environnement(void)
{

}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void environnement::Mouve(void)
{
	
	for(int i=0; i<nbProie;i++)
	{
		vitfinalProie();
		posfinalProie();

	}

	if (nbPredateur !=0)
	{
		for (int i = 0; i <nbPredateur; i++)
		{
			vitfinalPred();
			posfinalPred();
		}
	}
}

 void environnement::vitfinalProie(void)
{
	for (int i=0; i<nbProie; i++)
	{
		//printf("On étudie l'agent numéro %d\n",i );
		float K1=0;
		float K2=0;
		float O=0;
		vector newvit2(0,0);
		vector newvit1(0,0);
		vector newvit3(0,0);
		vector newvit3b(0,0);
		vector newvit4(0,0);

		for(int j=0; j<nbProie;j++)
		{
			vector dist=TabProie[i].Get_pos() -TabProie[j].Get_pos();
			float distance =dist.Get_Norm();
			//printf("Distance%d :%f \n", j, distance);
			if (distance<TabProie[i].Get_rayon() & j!= i)
			{
				K1++;		
				newvit2=newvit2 + TabProie[j].Get_pos() - TabProie[i].Get_pos(); 
				newvit1=newvit1 + TabProie[j].Get_vit() - TabProie[i].Get_vit(); 
				
			}
	
		}
		
		
		for (int k=0; k<nbProie;k++)
		{
			vector dist=TabProie[k].Get_pos() -TabProie[i].Get_pos();
			float distance =dist.Get_Norm();
			

			if (distance<TabProie[i].Get_contact() & k!= i)
			{
				K2++; 
				newvit3=newvit3 + TabProie[k].Get_pos() - TabProie[i].Get_pos(); 
			}

		}	


		for (int k=0; k<nbObstacle;k++)
		{

			vector espace=TabObstacle[k].Get_pos()-TabProie[i].Get_pos();
			float esp = espace.Get_Norm();

			if (esp<TabProie[i].Get_contact()) 
			{
				O++;
				newvit3b=newvit3b + TabObstacle[k].Get_pos() - TabProie[i].Get_pos();
			}

		}

		for (int k=0; k<nbPredateur;k++)
		{

			vector espace=TabPredateur[k].Get_pos()-TabProie[i].Get_pos();
			float esp = espace.Get_Norm();

			if (esp<TabProie[i].Get_rayon())
			{
				newvit4=espace/esp;
			
			}

			

		}


		if (K1!=0)
		{
		
			newvit2= newvit2/K1;
			newvit1= newvit1/K1;
		
		}

		if (K2!=0)
		{
			newvit3=newvit3/(K2);
		}

		if (O!=0)
		{
			newvit3b=newvit3b/O;
		}

		

		//printf("Valeur de newvit \n");
		//newvit1.affichevector();
		vector V1=newvit1*dt;
		//V1.affichevector();
		vector V2=newvit2*dt;
		vector V3=newvit3*dt;
		vector V3b=newvit3b*dt;
		vector V4=newvit4*dt;

		//printf("Valeur de V1 :");
  		//V1.affichevector();
  		//printf("Valeur de V1*gamma :");
  		V1=V1*G1;
  		//V1.affichevector();

  		//printf("Valeur de V2 : ");
  		//V2.affichevector();
  		V2=V2*G2;
  		//printf("Valeur de V2*gamma : ");
  		//V2.affichevector();

  		//printf("Valeur de V3 : ");
  		//V3.affichevector();
  		//printf("Valeur de V3*gamma : ");
  		V3=V3*G3;
  		//V3.affichevector();

  		//printf("\n");

  		V3b=V3b*G3;
  		V4=V4*G4;
  		vector V=V1+V2-V3-V3b-V4;

  		V=TabProie[i].Get_vit()+V;
  		//printf("Valeur de V : ");
  		//V.affichevector();

  		


		float a = TabProie[i].Get_pos().Get_X();
		float b = TabProie[i].Get_pos().Get_Y();

		if ( a<10 )
		{
		V.SetX(0.007);
		}
		else if ( a>630 )
		{
		V.SetX(-0.007);
		}
		if ( b<10 )
		{
		V.SetY(0.007);
		}
		else if ( b>470 )
		{
		V.SetY(-0.007);
		}

		TabProie[i].Set_vit(V);

		/*printf("Valeur de la nouvelle vitesse finale :");
		TabProie[i].Get_vit().affichevector();*/
	
	}

	

}

void environnement::posfinalProie(void)
{
	
	for (int i=0; i<nbProie;i++)
	{
		TabProie[i].Set_pos(TabProie[i].Get_pos()+TabProie[i].Get_vit()*dt);
			
	}		

}

void environnement::vitfinalPred(void)
{
	for (int i = 0; i <nbPredateur; ++i)
	{
		
		int position;
		float limite = 1000;
		vector direction(0,0);
		vector dist(0,0);
		float distance;
		vector vitcontp(0,0);
		vector vitconto(0,0);
		float Kp=0;
		float Ko=0;
	

		for (int j = 0; j <nbProie; ++j)
		{

			dist=TabPredateur[i].Get_pos() -TabProie[j].Get_pos();
		    distance =dist.Get_Norm();

			if ( distance < limite )
			{
				limite=distance;
				position=j;
			}

		}

	    if (limite>TabPredateur[i].Get_rayon() )
			{
				float c=60*((float)rand() / (float)RAND_MAX)-30;
  				float d=60*((float)rand() / (float)RAND_MAX)-30;
  				direction =vector(c,d);
			}

			
			
		else if (limite<TabPredateur[i].Get_rayon() )
		{
				
				//printf("Hello\n");
				

				vector espace=TabPredateur[i].Get_pos()-TabProie[position].Get_pos();
				float esp = espace.Get_Norm();
				
				direction=espace/esp;
			
				direction=direction*(-32);
		
				
		}
		

		for (int k=0; k<nbPredateur;k++)
		{
			vector dist=TabPredateur[k].Get_pos() -TabPredateur[i].Get_pos();
			float distance =dist.Get_Norm();
			

			if (distance<TabPredateur[i].Get_contact() & k!= i)
			{
				Kp++; 
				vitcontp=vitcontp + TabPredateur[k].Get_pos() - TabPredateur[i].Get_pos(); 
			}

		}

		if (Kp!=0)
		{
			vitcontp=vitcontp/Kp;
		}

		for (int k=0; k<nbObstacle;k++)
		{
			vector dist=TabObstacle[k].Get_pos() -TabPredateur[i].Get_pos();
			float distance =dist.Get_Norm();
			

			if (distance<TabPredateur[i].Get_contact() & k!= i)
			{
				Ko++; 
				vitconto=vitconto + TabObstacle[k].Get_pos() - TabPredateur[i].Get_pos(); 
			}

		}

		if (Ko!=0)
		{
			vitconto=vitconto/Ko;
		}

		direction=direction-vitcontp-vitconto;

		float a = TabPredateur[i].Get_pos().Get_X();
		float b = TabPredateur[i].Get_pos().Get_Y();

		if ( a<10 )
		{
		direction.SetX(-2);
		}
		else if ( a>630 )
		{
		direction.SetX(-2);
		}
		if ( b<10 )
		{
		direction.SetY(2);
		}
		else if ( b>470 )
		{
		direction.SetY(-2);
		}




		TabPredateur[i].Set_vit(direction);




		

	}
  			
}

void environnement::posfinalPred(void)
{


	for (int i = 0; i <nbPredateur; i++)
	{

		if (TabPredateur[i].Get_timer()>0)
		{
			vector null(0,0);
 	  	    TabPredateur[i].Set_vit(null);
 	   	    TabPredateur[i].Set_timer(TabPredateur[i].Get_timer()-1);
		}

		for (int j = 0; j < nbProie; j++)
		{
			if ((TabProie[j].Get_pos()-TabPredateur[i].Get_pos()).Get_Norm()<10)
			{
				/*proie* tableau = new proie [nbProie-1];

 				for(int k=0 ; k<i; k++)
    			{
      				tableau[k] = TabProie[k];
 			    }

 			    for (int k=i; k<nbProie-1; k++)
 			    {
 			    	tableau[k]=TabProie[k+1];
 			    }
 			    */
 			    vector null(0,0);
 			    TabPredateur[i].Set_vit(null);
 			    TabPredateur[i].Set_timer(20); 			    

 			    vector inf(-100000,-100000);
				TabProie[j].Set_pos(inf);
				ProieMange++;
			}
		} 

		vector test = TabPredateur[i].Get_pos()+TabPredateur[i].Get_vit()*dt;

		TabPredateur[i].Set_pos(TabPredateur[i].Get_pos()+TabPredateur[i].Get_vit()*dt);	

	}


	
		
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
