#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "TObject.h"
#include "TRelationship.h"
#include "TException.h"

#include "TCircle.h"
#include "TRectangle.h"
#include "TRhombus.h"

#define throw_exception(msg) throw TException(msg, __FILE__, __LINE__)

template<class T>
class TContainer
{
private:
  int idCounter;
  std::vector<TObject<T, 2>*> objects;
  std::vector<TRelationship> relationships;
public:
  TContainer();
  ~TContainer();
  TObject<T, 2>*& operator[](int index);
  int GetSize();
  int ReserveId();
  void Add(TObject<T, 2>* obj);
  void Delete(const int id);
  void ShowRelationships();
  void Show(const int id);
  void Show(const std::vector<int> ids);
  void ShowAll();
  std::vector<int> Select(T x1, T y1, T x2, T y2);
  void Link(const int first, const int second, const TRelationType type);
  void Unlink(const int first, const int second, const TRelationType type);
};

template<class T>
int TContainer<T>::GetSize()
{
  return objects.size();
}

template<class T>
TContainer<T>::TContainer()
{
  idCounter = 0;
}

template<class T>
TContainer<T>::~TContainer()
{
  for (int i = 0; i < objects.size(); ++i)
  {
    if (objects[i] != nullptr)
      delete objects[i];
  }
}

template<class T>
int TContainer<T>::ReserveId()
{
  int v = idCounter;
  ++idCounter;
  return v;
}

template<class T>
void TContainer<T>::Add(TObject<T, 2> *obj)
{
  objects.push_back(obj);
}

template<class T>
void TContainer<T>::Delete(const int id)
{
  bool find = false;
  for (int i = 0; i < objects.size(); ++i)
  {
    if (objects[i]->GetId() == id)
      find = true;
  }


  if (!find)
    throw_exception("Can't find object with this id");

  for (int i = 0; i < objects.size(); ++i)
  {
    if (objects[i]->GetId() == id)
    {
      std::swap(objects[i], objects.back());
    }
  }
  delete objects.back();
  objects.pop_back();
}

template<class T>
TObject<T, 2>*& TContainer<T>::operator[](int index)
{

  if (index < 0 || index >= objects.size())
    throw_exception("Out of bounds");
  return objects[index];
}

template<class T>
void TContainer<T>::ShowRelationships()
{
  std::cout << '\n';
  for (int i = 0; i < relationships.size(); ++i) {
    std::cout << relationships[i] << ' ';
  }
  std::cout << '\n';
}

template<class T>
void TContainer<T>::Show(const int id)
{
  std::cout << '\n';
  for (int i = 0; i < objects.size(); ++i) {
    if (objects[i]->GetId() == id)
      std::cout << *(objects[i]) << '\n';
  }
  std::cout << '\n';
}

template<class T>
void TContainer<T>::Show(const std::vector<int> ids)
{
  std::cout << '\n';
  for (int i = 0; i < objects.size(); ++i) {
    if (std::find(ids.begin(), ids.end(), objects[i]->GetId()) != ids.end())
      std::cout << *(objects[i]) << '\n';
  }
  std::cout << '\n';
}

template<class T>
void TContainer<T>::ShowAll()
{
  for (int i = 0; i < objects.size(); ++i) {
    std::cout << *(objects[i]) << '\n';
  }
  std::cout << '\n';
}

template<class T>
std::vector<int> TContainer<T>::Select(T x1, T y1, T x2, T y2)
{
  if (x1 > x2)
    std::swap(x1, x2);
  if (y1 > y2)
    std::swap(y1, y2);
  std::vector<int> indices;
  for (int i = 0; i < objects.size(); ++i)
  {
    T* coords = objects[i]->GetCoords();
    if (x1 <= coords[0] && coords[0] <= x2 && y1 <= coords[1] && coords[1] <= y2)
      indices.push_back(objects[i]->GetId());
  }
  return indices;
}

template<class T>
void TContainer<T>::Link(const int first, const int second, const TRelationType type)
{
  bool findFirst = false;
  bool findSecond = false;
  for (int i = 0; i < objects.size(); ++i)
  {
    if (objects[i]->GetId() == first)
      findFirst = true;
    if (objects[i]->GetId() == second)
      findSecond = true;
  }
  if (!findFirst || !findSecond)
    throw_exception("Can't find objects with this ids");

  bool findRelationship = false;
  for (int i = 0; i < relationships.size(); ++i)
    if (relationships[i].GetFirst() == first &&
        relationships[i].GetSecond() == second && relationships[i].GetType() == type)
          findRelationship = true;

  if (findRelationship)
    throw_exception("Relationship already exists");
  relationships.push_back(TRelationship(first, second, type));
}

template<class T>
void TContainer<T>::Unlink(const int first, const int second, const TRelationType type)
{
  int index = -1;
  for (int i = 0; i < relationships.size(); ++i)
    if (relationships[i].GetFirst() == first &&
        relationships[i].GetSecond() == second && relationships[i].GetType() == type)
      index = i;

  if (index == -1)
    throw_exception("Relationship doesn't exist");
  relationships.erase(relationships.begin() + index);
}