#pragma once
#include "TObject.h"
#include "TException.h"

#define throw_exception(msg) throw TException(msg, __FILE__, __LINE__)

template<class T>
class TRectangle : public TObject<T, 2>
{
protected:
  T width;
  T height;
public:
  TRectangle(const int id_);
  TRectangle(const int id_, const T* coords_, const int color_ = 0,
             const T width_ = 0, const T height_ = 0,
             const TString& name_ = "Rectangle", const TString& caption_ = "");
  TRectangle(const int id_, const TRectangle& p);
  ~TRectangle();
  T GetWidth() const;
  T GetHeight() const;
  T GetArea() const;
  TString GetType() const;

  void SetWidth(const T width_) const;
  void SetHeight(const T height_) const;
};

template<class T>
TString TRectangle<T>::GetType() const
{
  return "Rectangle";
}

template<class T>
T TRectangle<T>::GetArea() const
{
  return width * height;
}

template<class T>
TRectangle<T>::TRectangle(const int id_) : TObject<T, 2>::TObject(id_)
{
  width = 0;
  height = 0;
}

template<class T>
TRectangle<T>::TRectangle(const int id_, const T *coords_, const int color_,
                          const T width_, const T height_,
                          const TString& name_, const TString& caption_)
                          : TObject<T, 2>::TObject(id_, coords_, color_, name_, caption_)
{
  width = width_;
  height = height_;
}

template<class T>
TRectangle<T>::TRectangle(const int id_, const TRectangle<T>& p) : TObject<T, 2>::TObject(id_, p)
{
  width = p.width;
  height = p.height;
}

template<class T>
TRectangle<T>::~TRectangle()
{

}

template<class T>
T TRectangle<T>::GetWidth() const
{
  return width;
}

template<class T>
T TRectangle<T>::GetHeight() const
{
  return height;
}

template<class T>
void TRectangle<T>::SetWidth(const T width_) const
{
  if (width_ < 0)
    throw_exception("Negative width");
  width = width_;
}

template<class T>
void TRectangle<T>::SetHeight(const T height_) const
{
  if (height_ < 0)
    throw_exception("Negative height");
  height = height_;
}

