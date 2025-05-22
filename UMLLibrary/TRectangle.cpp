#include "TObject.h"
template<class T>
class TRectangle : public TObject<T, 2>
{
protected:
  T width;
  T height;
public:
  TRectangle();
  TRectangle(T* coords_,  T width_, T height_, int color = 0);
  TRectangle(const TRectangle& p);
  ~TRectangle();
public:
  T GetWidth() const;
  T GetHeight() const;
  void SetWidth(const T width_) const;
  void SetHeight(const T height_) const;
};