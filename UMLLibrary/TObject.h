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
  int id;
public:
  TObject(const int id_);
  TObject(const int id_, const T coords_[], const int color_ = 0,
          const TString& name_ = "Object", const TString& caption_ = "");
  TObject(const int id_, const TObject& p);
  ~TObject();

  int GetId() const;
  int GetDim() const;
  T* GetCoords();
  int GetColor() const;
  TString GetName();
  virtual T GetArea() const;

  void SetCoords(const int coords_[]);
  void SetColor(const int color_);
  void SetName(const TString& name_);

  // template<class I, int dim_>
  // friend std::istream& operator>>(std::istream& i, TObject<I, dim_>& p);

  template<class O, int dim_>
  friend std::ostream& operator<<(std::ostream& o, TObject<O, dim_>& p);
};

template<class T, int dim>
T TObject<T, dim>::GetArea() const
{
  return 0;
}

template<class T, int dim>
int TObject<T, dim>::GetId() const
{
  return id;
}

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
TObject<T, dim>::TObject(int id_)
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = 0;
  }
  color = 0;
  id = id_;
}

template<class T, int dim>
TObject<T, dim>::TObject(const int id_, const T coords_[], const int color_,
        const TString& name_, const TString& caption_) : TUML(caption_) {
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = coords_[i];
  }
  name = name_;
  color = color_;
  id = id_;
}

template<class T, int dim>
TObject<T, dim>::TObject(int id_, const TObject& p) : TUML(p)
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = p.coords[i];
  }
  color = p.color;
  name = p.name;
  id = id_;
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
T* TObject<T, dim>::GetCoords()
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
void TObject<T, dim>::SetName(const TString& name_)
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