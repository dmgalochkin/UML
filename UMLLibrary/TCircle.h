#pragma once
#include "TObject.h"
#include "TException.h"

#define throw_exception(msg) throw TException(msg, __FILE__, __LINE__)

template<class T>
class TCircle : public TObject<T, 2>
{
protected:
  T radius;
public:
  TCircle();
  TCircle(const T* coords_, const int color_ = 0,
           const T radius_ = 0,
           const TString& name_ = "Circle", const TString& caption_ = "");
  TCircle(const TCircle& p);
  ~TCircle();
  T GetRadius() const;
  void SetRadius(const T radius_) const;
};

template<class T>
TCircle<T>::TCircle() : TObject<T, 2>::TObject()
{
  radius = 0;
}

template<class T>
TCircle<T>::TCircle(const T *coords_, const int color_,
                      const T radius_,
                      const TString& name_, const TString& caption_)
     : TObject<T, 2>::TObject(coords_, color_, name_, caption_)
{
  radius = radius_;
}

template<class T>
TCircle<T>::TCircle(const TCircle<T> &p) : TObject<T, 2>::TObject(p)
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
