#include "TUML.h"

template<class T, int dim>
class TObject : public TUML
{
protected:
  T coords[dim];
  int color;
public:
  TObject();
  TObject(const T coords_[], const int color_ = 0,
          const TString& name_ = "Object", const TString& caption_ = "");
  TObject(const TObject& p);
  ~TObject();

  int GetDim() const;
  T* GetCoords() const;
  int GetColor() const;

  void SetCoords(const int coords_[]);
  void SetColor(const int color_);
};

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
        const TString& name_, const TString& caption_) : TUML(name_, caption_) {
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