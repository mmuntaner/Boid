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
#include "proie.h"







//############################################################################
//                                                                           #
//                              Class proie                                  #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const int proie::rayon=30;
const int proie::contact=5;
int proie::index =0;

// ===========================================================================
//                                  Constructors
// ===========================================================================
proie::proie(void)
{
	float a =640*((float)rand() / (float)RAND_MAX);	
	float b =480*((float)rand() / (float)RAND_MAX);	
  	vector p(a,b);
  	position=p;
  	index++;

  	
  
}

proie::proie(float a, float b)
{
	vector p(a,b);
	position=p;
	
}
// ===========================================================================
//                                  Destructor
// ===========================================================================
proie::~proie(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void proie::Set_vit(vector v)
{
	vitesse=v;
}

void proie::Set_pos(vector v)
{
	position=v;
}



// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
