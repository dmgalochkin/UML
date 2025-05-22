
template<class T, int dim>
class TObject
{
private:
  T coords[dim];
  int color;

  TObject();
  TObject(const T coords_[], int color_ = 0);
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
TObject<T, dim>::TObject(const T* coords_, int color_)
{
  for (int i = 0; i < dim; ++i)
  {
    coords[i] = coords_[i];
  }
  color = color_;
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