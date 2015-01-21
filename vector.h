//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __VECTOR_H__
#define __VECTOR_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <math.h>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================



class vector
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    vector(void);
    vector (float new_x, float new_y);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~vector(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline float Get_X(void) const;
    inline float Get_Y(void) const;
    inline float Get_Norm(void) const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
     void SetX(float new_x);
     void SetY(float new_y);
     void updateNorm(void);
    // =======================================================================
    //                                Operators
    // =======================================================================
     friend inline vector operator+ (vector v1, vector v2);
     friend inline vector operator- (vector v1, vector v2);
     inline vector operator/ (float v);
     inline vector operator* (float v);
    
   // =======================================================================
    //                              Public Methods
    // =======================================================================
     inline void affichevector(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*vector(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };

    vector(const point &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
      }; */


    // =======================================================================
    //                              Protected Methods
    // =======================================================================
    // void updateNorm(void); 
    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    float x;
    float y;
    float norm;
};


// ===========================================================================
//                              Getters' definitions
// ==========================================================================
inline float vector::Get_X(void) const
{
  return x;
}

inline float vector::Get_Y(void) const
{
  return y;
}

inline float vector::Get_Norm(void) const
{
  float norme=sqrt(x*x + y*y);
  return norme;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================


// ===========================================================================
//                             Operators' definitions
// ===========================================================================
inline vector operator+(vector v1, vector v2)
{
  float a = v1.Get_X() + v2.Get_X();
  float b = v1.Get_Y() + v2.Get_Y();
  vector p(a,b);
  return p;
  
}

inline vector operator-(vector v1, vector v2)
{
  float a = v1.Get_X() - v2.Get_X();
  float b = v1.Get_Y() - v2.Get_Y();
  vector p(a,b);
  return p;
  
}

inline vector vector::operator/ (float v)
{
  float a = x/v;
  float b = y/v;
  vector p(a,b);
  return p;
  
}

inline vector vector::operator* (float v)
{
  float a = x*v;
  float b = y*v;
  vector p(a,b);
  return p;
  
}




// ===========================================================================
//                          Inline functions' definition
// ===========================================================================
inline void vector::affichevector(void)
{
    printf("%f %f \n", this->Get_X(), this->Get_Y());
}

#endif // __VECTOR_H__

