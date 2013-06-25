#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstdlib>
#include <vector>
#include <math.h>

#define REAL float 

/* T MUST BE A NON-INTEGER TYPE */
template <typename T, int n>
class Vector {
  public:
    // constructor
    Vector( const std::vector<T> & vec );

    // copy constructor
    Vector( const Vector<T,n> & vec );

    // element access
    T operator[](int i) const;

    // component-wise operations
    Vector<T,n> operator*( const Vector<T,n> & v ) const;
    Vector<T,n> operator+( const Vector<T,n> & v ) const;
    Vector<T,n> operator/( const Vector<T,n> & v ) const;
    Vector<T,n> operator-( const Vector<T,n> & v ) const;
    Vector<T,n> operator-() const;

    // in-place component-wise operations
    void mult( const Vector<T,n> & v );
    void add(  const Vector<T,n> & v );
    void div(  const Vector<T,n> & v );
    void sub(  const Vector<T,n> & v );

    // vector operations
    T mag() const;
    T dot( const Vector<T,n> & v ) const;
    Vector<T,n> & normalize() const;
    Vector<T,n> & scale( const T & alpha ) const;

    // in-place vector operations
    void inormalize();
    void iscale( const T & alpha );

    // convenience methods
    T angleTo( const Vector<T,n> & v ) const;

  private:
    std::vector<T> _vec;
};

/* Constructor */
template <typename T, int n>
Vector<T,n>::Vector( const std::vector<T> & vec ) {
  if( vec.size() != n ) {
    std::cerr << "Improper size: got " << vec.size() << ", expected " << _vec.size() << std::endl;
    std::exit( EXIT_FAILURE );
  }

  _vec = vec;
} 

/* Copy constructor */
template <typename T, int n>
Vector<T,n>::Vector( const Vector<T,n> & copy ) {
  _vec = std::vector<T>( copy._vec );
}

/* retrieval operator [] */
template <typename T, int n>
T Vector<T,n>::operator[]( int i ) const {
  if( i < 0 || i >= n ) {
    std::cerr << "Index out of bounds [" << i << "]" << std::endl;
    std::exit( EXIT_FAILURE );
  }

  return _vec[i];
}

/* vector-vector multiplication (component-wise) */
template <typename T, int n>
Vector<T,n> Vector<T,n>::operator*( const Vector<T,n> & v ) const {
  std::vector<T> copy = std::vector<T>( _vec );

  for( int i = 0; i < n; ++i )
    copy[i] *= v[i];

  return Vector<T,n>( copy );
}

/* vector-vector division (component-wise) */
template <typename T, int n>
Vector<T,n> Vector<T,n>::operator/( const Vector<T,n> & v ) const {
  std::vector<T> copy = std::vector<T>( _vec );

  for( int i = 0; i < n; ++i )
    copy[i] /= v[i];

  return Vector<T,n>( copy );
}

/* vector-vector addition (component-wise) */
template <typename T, int n>
Vector<T,n> Vector<T,n>::operator+( const Vector<T,n> & v ) const {
  std::vector<T> copy = std::vector<T>( _vec );

  for( int i = 0; i < n; ++i )
    copy[i] += v[i];

  return Vector<T,n>( copy );
}

/* vector-vector subtraction (component-wise) */
template <typename T, int n>
Vector<T,n> Vector<T,n>::operator-( const Vector<T,n> & v ) const {
  std::vector<T> copy = std::vector<T>( _vec );

  for( int i = 0; i < n; ++i )
    copy[i] -= v[i];

  return Vector<T,n>( copy );
}

/* unary negation (component-wise) */
template <typename T, int n>
Vector<T,n> Vector<T,n>::operator-() const {
  std::vector<T> copy = std::vector<T>( _vec );

  for( int i = 0; i < n; ++i )
    copy[i] = -copy[i];

  return Vector<T,n>( copy );
}

/* dot product */
template <typename T, int n>
T Vector<T,n>::dot( const Vector<T,n> & v ) const {
  T acc = 0.f;

  for( int i = 0; i < n; ++i )
    acc += ( _vec[i] * v[i] );

  return acc;
}

/* magnitude */
template <typename T, int n>
T Vector<T,n>::mag() const {
  return sqrt( _vec.dot( _vec ) );
}

/* normalize */
template <typename T, int n>
Vector<T,n> & Vector<T,n>::normalize() const {
  std::vector<T> copy = std::vector<T>( _vec );
  T magnitude = mag();

  for(int i = 0; i < n; ++i)
    copy[i] = copy[i] / magnitude;

  return Vector<T,n>( copy );
}

/* in-place normalize */
template <typename T, int n>
void Vector<T,n>::inormalize() {
  T magnitude = mag();

  for(int i = 0; i < n; ++i)
    _vec[i] = _vec[i] / magnitude;
}

/* scalar multiplication */
template <typename T, int n>
Vector<T,n> & Vector<T,n>::scale( const T & alpha ) const {
  std::vector<T> copy = std::vector<T>( _vec );

  for ( int i = 0; i < n; ++i )
    copy[i] = copy[i] * alpha;

  return Vector<T,n>( copy );
}

/* mutating scalar multiplication */
template <typename T, int n>
void Vector<T,n>::iscale( const T & alpha ) {
  for ( int i = 0; i < n; ++i )
    _vec[i] *= alpha;
}

/* mutating multiplication */
template <typename T, int n>
void Vector<T,n>::mult( const Vector<T,n> & v ) {
  for ( int i = 0; i < n; ++i )
    _vec[i] *= v[i];
}

/* mutating addition */
template <typename T, int n>
void Vector<T,n>::add( const Vector<T,n> & v ) {
  for ( int i = 0; i < n; ++i )
    _vec[i] += v[i];
}

/* mutating division */
template <typename T, int n>
void Vector<T,n>::div( const Vector<T,n> & v ) {
  for ( int i = 0; i < n; ++i )
    _vec[i] /= v[i];
} 

/* mutating subtration */
template <typename T, int n>
void Vector<T,n>::sub( const Vector<T,n> & v ) {
  for ( int i = 0; i < n; ++i )
    _vec[i] -= v[i];
}

/* angle between this and another vector */
template <typename T, int n>
T Vector<T,n>::angleTo( const Vector<T,n> & v ) const {
  return acos( dot(v) / ( mag() * v.mag() ) );
}

#endif
