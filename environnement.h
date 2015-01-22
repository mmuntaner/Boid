//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __ENVIRONNEMENT_H__
#define __ENVIRONNEMENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include "agent.h"
#include "proie.h"
#include "predateur.h"
#include "obstacle.h"



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class environnement
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    environnement(void);
    environnement(int n);
    environnement(int n, int o);
    environnement(int n, int o, int p);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~environnement(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline proie* Get_TabProie(void) const;
    inline int Get_nbProie(void) const;
    inline obstacle* Get_TabObstacle(void) const;
    inline int Get_nbObstacle(void) const;
    inline predateur* Get_TabPredateur(void) const;
    inline int Get_nbPredateur(void) const;
    

    void vitfinalProie(void);
    void posfinalProie(void);
    void vitfinalPred(void);
    void posfinalPred(void);


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
   
   
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void Mouve(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*environnement(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };

    environnement(const Template_class &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
      }; */


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
      const int W = 640;
      const int H = 480;
      const float dt=0.12;

      float G1 = 0.13;
      float G2 = 0.004;
      float G3 = 0.6;

      int nbProie;
      proie* TabProie;

      int nbObstacle;
      obstacle* TabObstacle;

      int nbPredateur;
      predateur* TabPredateur;
  
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline proie* environnement::Get_TabProie(void) const
{
  return TabProie;
}

 inline int environnement::Get_nbProie(void) const
 {
  return nbProie;
 }

 inline obstacle* environnement::Get_TabObstacle(void) const
{
  return TabObstacle;
}

 inline int environnement::Get_nbObstacle(void) const
 {
  return nbObstacle;
 }

 inline predateur* environnement::Get_TabPredateur(void) const
{
  return TabPredateur;
}

 inline int environnement::Get_nbPredateur(void) const
 {
  return nbPredateur;
 }


// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __ENVIRONNEMENT_H__

