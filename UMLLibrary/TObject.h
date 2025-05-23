#pragma once
#include "TString.h"
#include "TUML.h"
#include <iostream>

template<class T, int dim>
class TObject : public TUML
{
protected:
  T coords[dim];
  int color;
  TString name;
public:
  TObject();
  TObject(const T coords_[], const int color_ = 0,
          const TString& name_ = "Object", const TString& caption_ = "");
  TObject(const TObject& p);
  ~TObject();

  int GetDim() const;
  T* GetCoords() const;
  int GetColor() const;
  TString GetName();

  void SetCoords(const int coords_[]);
  void SetColor(const int color_);
  TString SetName(const TString& name_);

  // template<class I, int dim_>
  // friend std::istream& operator>>(std::istream& i, TObject<I, dim_>& p);

  template<class O, int dim_>
  friend std::ostream& operator<<(std::ostream& o, TObject<O, dim_>& p);
};

template<class O, int dim_>
std::ostream& operator<<(std::ostream &o, TObject<O, dim_>& p)
{
  o << p.name << '\n';
  for (int i = 0; i < dim_; ++i)
    o << p.coords[i] << ' ';
  o << '\n';
  return o;
}

template<class T, int dim>
TObject<T, dim>::TObject()
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = 0;
  }
  color = 0;
}

template<class T, int dim>
TObject<T, dim>::TObject(const T coords_[], const int color_,
        const TString& name_, const TString& caption_) : TUML(caption_) {
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = coords_[i];
  }
  color = color_;
}

template<class T, int dim>
TObject<T, dim>::TObject(const TObject& p) : TUML(p)
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = p.coords[i];
  }
  color = p.color;
  name = p.name;
}

template<class T, int dim>
TObject<T, dim>::~TObject()
{

}

template<class T, int dim>
int TObject<T, dim>::GetDim() const
{
  return dim;
}

template<class T, int dim>
T* TObject<T, dim>::GetCoords() const
{
  return coords;
}

template<class T, int dim>
int TObject<T, dim>::GetColor() const
{
  return color;
}

template<class T, int dim>
TString TObject<T, dim>::GetName()
{
  return name;
}

template<class T, int dim>
TString TObject<T, dim>::SetName(const TString& name_)
{
  name = name_;
}


template<class T, int dim>
void TObject<T, dim>::SetCoords(const int coords_[])
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = coords_[i];
  }
}

template<class T, int dim>
void TObject<T, dim>::SetColor(const int color_)
{
  color = color_;
}