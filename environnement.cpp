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
		if (K1!=0)
		{
		
			newvit2= newvit2/K1;
			newvit1= newvit1/K1;
		
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

		if (O!=0)
		{
			newvit3b=newvit3b/O;
		}

		if (K2!=0)
		{
			newvit3=newvit3/(K2);
		}

		//printf("Valeur de newvit \n");
		//newvit1.affichevector();
		vector V1=newvit1*dt;
		//V1.affichevector();
		vector V2=newvit2*dt;
		vector V3=newvit3*dt;
		vector V3b=newvit3b*dt;

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
  		vector V=V1+V2-V3-V3b;

  		V=TabProie[i].Get_vit()+V;
  		//printf("Valeur de V : ");
  		//V.affichevector();

  		


		float a = TabProie[i].Get_pos().Get_X();
		float b = TabProie[i].Get_pos().Get_Y();

		if ( a<10 )
		{
		V.SetX(0.007);
		}
		if ( a>630 )
		{
		V.SetX(-0.007);
		}
		if ( b<10 )
		{
		V.SetY(0.007);
		}
		if ( b>470 )
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
		float c=60*((float)rand() / (float)RAND_MAX)-30;
  		float d=60*((float)rand() / (float)RAND_MAX)-30;
  		vector v(c,d);
  		printf("Valeur de la vitesse\n");
  		v.affichevector();
 		TabPredateur[i].Set_vit(v);


  		float a = TabPredateur[i].Get_pos().Get_X();
		float b = TabPredateur[i].Get_pos().Get_Y();

		if ( a<10 )
		{
		v.SetX(-0.01);
		}
		if ( a>630 )
		{
		v.SetX(-0.01);
		}
		if ( b<10 )
		{
		v.SetY(0.01);
		}
		if ( b>470 )
		{
		v.SetY(-0.01);
		}

		TabPredateur[i].Set_vit(v);
	}
  			
}

void environnement::posfinalPred(void)
{

	for (int i = 0; i <nbPredateur; i++)
	{
		
		vector test = TabPredateur[i].Get_pos()+TabPredateur[i].Get_vit()*dt;
		printf("La nouvelle valeur de la position : \n");
		test.affichevector();
		TabPredateur[i].Set_pos(TabPredateur[i].Get_pos()+TabPredateur[i].Get_vit()*dt);
	}
		
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
