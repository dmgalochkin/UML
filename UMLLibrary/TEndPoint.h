#pragma once
#include "TCircle.h"
template<class T>
class TEndPoint : public TCircle<T>
{
private:
  TCircle<T> innerCircle;
public:
  TEndPoint(const int id_);
  TEndPoint(const int id_, const T *coords_, const int color_,
            const T radius_,
            const TString& name_ = "EndPoint", const TString& caption_ = "");
  ~TEndPoint();
  TString GetType() const;
  TCircle<T> GetInnerCircle();
};

template<class T>
TString TEndPoint<T>::GetType() const
{
  return "EndPoint";
}

template<class T>
TEndPoint<T>::TEndPoint(const int id_) : TCircle<T>(id_)
{

}

template<class T>
TEndPoint<T>::TEndPoint(const int id_, const T *coords_, const int color_,
                        const T radius_,
                        const TString& name_, const TString& caption_)
                        : TCircle<T>(id_, coords_, color_, radius_, name_, caption_)
{
  innerCircle = TCircle<T>(id_, coords_, radius_ / 2, name_);
}

template<class T>
TEndPoint<T>::~TEndPoint()
{

}

template<class T>
TCircle<T> TEndPoint<T>::GetInnerCircle()
{
  return innerCircle;
}

