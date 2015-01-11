//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __PREDATEUR_H__
#define __PREDATEUR_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "agent.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class predateur : public agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    predateur(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~predateur(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline const float Get_rayon(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Node(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };

    Node(const Template_class &model)
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
    static const float rayon = 10;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline const float predateur::Get_rayon(void) const 
{
  return rayon;
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


#endif // __NODE_H__
