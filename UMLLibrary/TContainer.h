#pragma once
#include "TObject.h"
#include "TRelation.h"
#include <vector>
template<class T>
class TContainer
{
private:
  std::vector<T> vector;
  void Show(const int ind);
  void Show(const char* name);

  void add(const T)
};