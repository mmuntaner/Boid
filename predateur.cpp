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
#include "predateur.h"




//############################################################################
//                                                                           #
//                              Class predateur                              #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const int predateur::rayon=80;
const int predateur::contact=20;

// ===========================================================================
//                                  Constructors
// ===========================================================================
predateur::predateur(void)
{
	
	float a =400*((float)rand() / (float)RAND_MAX)+10;
	float b =300*((float)rand() / (float)RAND_MAX)+10;
  	vector p(a,b);
	position=p;
  	float c=2*((float)rand() / (float)RAND_MAX)-1;
  	float d=2*((float)rand() / (float)RAND_MAX)-1;
  	vector v(c,d);
  	vitesse=v;
  	timer=0;


}

// ===========================================================================
//                                  Destructor
// ===========================================================================
predateur::~predateur(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================
void predateur::Set_vit(vector v)
{
	vitesse=v;
}

void predateur::Set_pos(vector v)
{
	position=v;
}

void predateur::Set_timer( int new_timer)
{
	timer=new_timer;
}

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
