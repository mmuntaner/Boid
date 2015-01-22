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

	/*int k=(2*H+2*W)/4;
	Limite= new obstacle [k];
	for (int i=0; i<(W/4); i++)
	{
		Limite[i].Set_pos(vector(i*4,0));
	}
	for(int i=0;i<(W/4);i++)
	{
		Limite[i+(H/4)].Set_pos(vector(i*4,H));
	}
	for(int i=0;i<(H/4);i++)
	{
		Limite[i+(H+W)/4].Set_pos(vector(0,i*4));
	}
	for(int i=0;i<(H/4);i++)
	{
		Limite[i+(H+H+W)/4].Set_pos(vector(H,i*4));
	}
	nbLimite=k;*/
	
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
void environnement::MouvProie(void)
{
	for(int i=0; i<nbProie;i++)
	{
		
		vitfinal();
		posfinal();

	}
}

 void environnement::vitfinal(void)
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
		if (K1!=0)
		{
			//printf("Valeur de V2 ");
			//newvit2.affichevector();
			//printf(" pour K=%f \n",K1 );
			newvit2= newvit2/K1;
			//newvit2.affichevector();

			//printf("Valeur de V1 ");
			//newvit1.affichevector();
			//printf(" pour K=%f \n",K1 );
			newvit1= newvit1/K1;
			//newvit1.affichevector();
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

		for (int k=0; k<nbLimite;k++)
		{

			vector espace=Limite[k].Get_pos()-TabProie[i].Get_pos();
			float esp = espace.Get_Norm();

			if (esp<TabProie[i].Get_contact()) 
			{
				
				O++;
				newvit4=newvit4 + Limite[k].Get_pos() - TabProie[i].Get_pos();

			}

		}

		if (O!=0)
		{
			newvit4=newvit4/O;
		}
		if (K2!=0)
		{
			//printf("Valeur de V3 ");
			//newvit3.affichevector();
			//printf(" pour K=%d\n",K2 );
			newvit3=newvit3/(K2);
			//newvit3.affichevector();
		}

		//printf("Valeur de newvit \n");
		//newvit1.affichevector();
		vector V1=newvit1*dt;
		//V1.affichevector();
		vector V2=newvit2*dt;
		vector V3=newvit3*dt;
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

  		V4=V4*G3;
  		vector V=V1+V2-V3-V4;

  		V=TabProie[i].Get_vit()+V;
  		//printf("Valeur de V : ");
  		//V.affichevector();

  		


	float a = TabProie[i].Get_pos().Get_X();
	float b = TabProie[i].Get_pos().Get_Y();

	if ( a<20 )
	{
	V.SetX(0.02);
	}
	if ( a>620 )
	{
	V.SetX(-0.02);
	}
	if ( b<20 )
	{
	V.SetY(0.02);
	}
	if ( b>460 )
	{
	V.SetY(-0.02);
	}

	TabProie[i].Set_vit(V);
	/*printf("Valeur de la nouvelle vitesse finale :");
	TabProie[i].Get_vit().affichevector();*/
	
	}
}

void environnement::posfinal(void)
{
	
	for (int i=0; i<nbProie;i++)
	{
		/*printf("Valeur de la position :");
		TabProie[i].Get_pos().affichevector();
		printf("\n");

		printf("Valeur de la vitesse :");
		TabProie[i].Get_vit().affichevector();
		printf("\n");
	
		TabProie[i].Set_pos(TabProie[i].Get_pos()+TabProie[i].Get_vit()*dt);
		printf("Valeur de la position finale :");
		TabProie[i].Get_pos().affichevector();
		printf("\n");*/

		TabProie[i].Set_pos(TabProie[i].Get_pos()+TabProie[i].Get_vit()*dt);
	}
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
