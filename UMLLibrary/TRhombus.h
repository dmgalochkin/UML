#pragma once
#include "TObject.h"
#include "TException.h"

#define throw_exception(msg) throw TException(msg, __FILE__, __LINE__)

template<class T>
class TRhombus : public TObject<T, 2>
{
protected:
  T horizontalDiagonal;
  T verticalDiagonal;
public:
  TRhombus(const int id_);
  TRhombus(const int id_, const T* coords_, const int color_ = 0,
             const T horizontalDiagonal_ = 0, const T verticalDiagonal_ = 0,
             const TString& name_ = "Rhombus", const TString& caption_ = "");
  TRhombus(const int id_, const TRhombus& p);
  ~TRhombus();
  T GetHorizontalDiagonal() const;
  T GetVerticalDiagonal() const;
  T GetArea() const;
  TString GetType() const;
  void SetHorizontalDiagonal(const T horizontalDiagonal_) const;
  void SetVerticalDiagonal(const T verticalDiagonal_) const;
};

template<class T>
TString TRhombus<T>::GetType() const
{
  return "Rhombus";
}

template<class T>
T TRhombus<T>::GetArea() const
{
  return horizontalDiagonal * verticalDiagonal / 2;
}

template<class T>
TRhombus<T>::TRhombus(const int id_) : TObject<T, 2>::TObject(id_)
{
  horizontalDiagonal = 0;
  verticalDiagonal = 0;
}

template<class T>
TRhombus<T>::TRhombus(const int id_, const T *coords_, const int color_,
                          const T horizontalDiagonal_, const T verticalDiagonal_,
                          const TString& name_, const TString& caption_)
                          : TObject<T, 2>::TObject(id_, coords_, color_, name_, caption_)
{
  horizontalDiagonal = horizontalDiagonal_;
  verticalDiagonal = verticalDiagonal_;
}

template<class T>
TRhombus<T>::TRhombus(const int id_, const TRhombus<T>& p) : TObject<T, 2>::TObject(id_, p)
{
  horizontalDiagonal = p.horizontalDiagonal;
  verticalDiagonal = p.verticalDiagonal;
}

template<class T>
TRhombus<T>::~TRhombus()
{

}

template<class T>
T TRhombus<T>::GetHorizontalDiagonal() const
{
  return horizontalDiagonal;
}

template<class T>
T TRhombus<T>::GetVerticalDiagonal() const
{
  return verticalDiagonal;
}

template<class T>
void TRhombus<T>::SetHorizontalDiagonal(const T horizontalDiagonal_) const
{
  if (horizontalDiagonal_ < 0)
    throw_exception("Negative horizontalDiagonal");
  horizontalDiagonal = horizontalDiagonal_;
}

template<class T>
void TRhombus<T>::SetVerticalDiagonal(const T verticalDiagonal_) const
{
  if (verticalDiagonal_ < 0)
    throw_exception("Negative verticalDiagonal");
  verticalDiagonal = verticalDiagonal_;
}
