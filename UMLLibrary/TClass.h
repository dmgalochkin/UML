#pragma once
#include "TRectangle.h"
#include "TString.h"
#include <vector>
template<class T>
class TClass : public TRectangle<T>
{
private:
  std::vector<TString> variables;
  std::vector<TString> methods;
public:
  TClass(const int id_);
  TClass(const int id_, const std::vector<TString> variables_, const std::vector<TString> methods_,
         const T *coords_, const int color_,
         const T width_, const T height_,
         const TString& name_ = "Class", const TString& caption_ = "");
  ~TClass();
  TString GetType() const;

  std::vector<TString> GetVariables();
  void AddVariable(const TString variable);

  std::vector<TString> GetMethods();
  void AddMethod(const TString method);
};

template<class T>
TString TClass<T>::GetType() const
{
  return "Class";
}

template<class T>
TClass<T>::TClass(const int id_) : TRectangle<T>(id_)
{

}

template<class T>
TClass<T>::TClass(const int id_, const std::vector<TString> variables_, const std::vector<TString> methods_,
                  const T *coords_, const int color_,
                  const T width_, const T height_,
                  const TString& name_, const TString& caption_)
                  : TRectangle<T>(id_, coords_, color_, width_, height_, name_, caption_)
{
  variables = variables_;
  methods = methods_;
}

template<class T>
TClass<T>::~TClass()
{

}

template<class T>
std::vector<TString> TClass<T>::GetVariables()
{
  return variables;
}

template<class T>
void TClass<T>::AddVariable(const TString variable)
{
  variables.push_back(variable);
}

template<class T>
std::vector<TString> TClass<T>::GetMethods()
{
  return methods;
}

template<class T>
void TClass<T>::AddMethod(const TString method)
{
  methods.push_back(method);
}
