#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>
#include <math.h>

#define REAL float 

template <class T, int n>
class Vector {
  public:
    Vector( const std::vector<T> & vec );
    ~Vector();

    const T& operator[](int i);                                     //Access element
    const Vector<T,n>& operator*(Vector<T,n> v);     //component-wise mult
    const Vector<T,n>& operator+(Vector<T,n> v);     //component-wise add
    const Vector<T,n>& operator/(Vector<T,n> v);     //compoment-wise divide
    const Vector<T,n>& operator-(Vector<T,n> v);     //component-wise subtract 
    const Vector<T,n>& operator-();       //unary negation
    const T& dot(Vector<T,n> v1, Vector<T,n> v2);       //dot product
    const Vector<REAL,n>& normalize();                  //normalize
    const T& mag();                                     //magnitude
    const Vector<T,n>& scale(Vector<T,n>, T alpha);     //Scalar multiplication
    void scale(T alpha);                  //mutating scalar multiplication
    void mult(Vector<T,n> v);             //mutating multiplication
    void add(Vector<T,n> v);              //mutating addition
    void div(Vector<T,n> v);              //mutating division
    void sub(Vector<T,n> v);              //mutating subtraction
    const REAL & angleBetween(Vector<T,n> v1, Vector<T,n> v2);  //angle between two vectors
    const REAL & angleWith(Vector<T,n> v2);                     //angle between this and another vector

  private:
    std::vector<T> _vec;
};

/* Constructor */
template <class T, int n>
Vector<T, n>::Vector( const std::vector<T> & vec ) {
  if(vec.size() != n) {
    std::cerr << "Improper size: got " << vec.size() << ", expected " << _vec.size() << std::endl;
    std::exit(EXIT_FAILURE);
  }

  _vec = vec;
} 

/* retrieval operator [] */
template <class T, int n>
T & Vector<T,n>::operator[](int i) {
  if(i < 0 || i >= n) {
    std::cerr << "Index out of bounds [" << i "]" << std::endl;
    std::exit(EXIT_FAILURE);
  } 
  return _vec[i];
}

/* vector-vector multiplication (component-wise) */
template <class T, int n>
Vector<T,n> & Vector<T,n>::operator*(Vector<T,n> v) {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = _vec[i] * v[i];
  }
  return new Vector<T,n>( dummy );
}

/* vector-vector addition (component-wise) */
template <class T, int n>
Vector<T,n> & Vector<T,n>::operator+(Vector<T,n> v) {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = _vec[i] + v[i];
  }
  return new Vector<T,n>( dummy );
}

/* vector-vector division (component-wise) */
template <class T, int n>
Vector<T,n> & Vector<T,n>::operator/(Vector<T,n> v) {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = _vec[i] / v[i];
  }
  return new Vector<T,n>( dummy );
}

/* vector-vector subtraction (component-wise) */
template <class T, int n>
Vector<T,n> & Vector<T,n>::operator-(Vector<T,n> v) {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = _vec[i] - v[i];
  }
  return new Vector<T,n>( dummy );
}

/* unary negation */
template <class T, int n>
Vector<T,n> & Vector<T,n>::operator-() {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = -vec[i];
  }
  return new Vector<T,n>( dummy );
}

/* dot product */
template <class T, int n>
T & Vector<T,n>::dot(Vector<T,n> v1, Vector<T,n> v2) {
  T acc = 0;
  for(int i = 0; i < n; ++i) {
    acc += (v1[i] * v2[i]);
  }
  return acc;
}

/* magnitude */
template <class T, int n>
T & Vector<T,n>::mag(Vector<T,n> v) {
  return sqrt(Vector<T,n>::dot(v, v));
}

/* normalize */
template <class T, int n>
Vector<REAL,n> & Vector<T,n>::normalize(Vector<T,n> v) {
  std::vector dummy = new std::vector;
  int magnitude = v.mag();
  for(int i = 0; i < n; ++i) {
    dummy[i] = v[i] / magnitude;
  }
  return new Vector<REAL,n>( dummy );
}

/* scalar multiplication */
Vector<T,n> & Vector<T,n>::scale(Vector<t,n> v, T alpha) {
  std::vector dummy = new std::vector;
  for(int i = 0; i < n; ++i) {
    dummy[i] = v[i] * alpha;
  }
  return new Vector<T,n>( dummy );
}

/* mutating scalar multiplication */
void Vector<T,n>::scale(T alpha) {
  for(int i = 0; i < n; ++i) {
    _vec[i] *= alpha;
  }
}

/* mutating multiplication */
void Vector<T,n>::mult(Vector<T,n> v) {
  for(int i = 0; i < n; ++i) {
    _vec[i] *= v[i];
  }
}

/* mutating addition */
void Vector<T,n>::add(Vector<T,n> v) {
  for(int i = 0; i < n; ++i) {
    _vec[i] += v[i];
  }
}

/* mutating division */
void Vector<T,n>::div(Vector<T,n> v) {
  for(int i = 0; i < n; ++i) {
    _vec[i] /= v[i];
  }
} 

/* mutating subtration */
void Vector<T,n>::sub(Vector<T,n> v) {
  for(int i = 0; i < n; ++i) {
    _vec[i] -= v[i];
  }
}

/* angle between two vectors */
REAL & Vector<T,n>::angleBetween(Vector<T,n> v1, Vector<T,n> v2) {
  return acos(Vector<T,n>::dot(v1, v2) / (v1.mag() * v2.mag()));
}

/* angle between this and another vector */
REAL & Vector<T,n>::angleTo(Vector<T,n> v) {
  return acos(Vector<T,n>::dot(this, v) / (this.mag() * v.mag()));
}

#endif
