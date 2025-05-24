#pragma once
#include <cmath>
#include "TObject.h"
#include "TException.h"

#define throw_exception(msg) throw TException(msg, __FILE__, __LINE__)

template<class T>
class TCircle : public TObject<T, 2>
{
protected:
  T radius;
public:
  TCircle(const int id_);
  TCircle(const int id_, const T* coords_, const int color_ = 0,
           const T radius_ = 0,
           const TString& name_ = "Circle", const TString& caption_ = "");
  TCircle(const int id_, const TCircle& p);
  ~TCircle();
  T GetRadius() const;
  T GetArea() const;
  void SetRadius(const T radius_) const;
};

template<class T>
T TCircle<T>::GetArea() const
{
  return M_PI * radius * radius;
}

template<class T>
TCircle<T>::TCircle(const int id_) : TObject<T, 2>::TObject(id_)
{
  radius = 0;
}

template<class T>
TCircle<T>::TCircle(const int id_, const T *coords_, const int color_,
                      const T radius_,
                      const TString& name_, const TString& caption_)
     : TObject<T, 2>::TObject(id_, coords_, color_, name_, caption_)
{
  radius = radius_;
}

template<class T>
TCircle<T>::TCircle(const int id_, const TCircle<T>& p) : TObject<T, 2>::TObject(id_, p)
{
  radius = p.radius;
}

template<class T>
TCircle<T>::~TCircle()
{

}

template<class T>
T TCircle<T>::GetRadius() const
{
  return radius;
}

template<class T>
void TCircle<T>::SetRadius(const T radius_) const
{
  if (radius_ < 0)
    throw_exception("Negative radius");
  radius = radius_;
}
