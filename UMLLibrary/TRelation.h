#pragma once

#include "TUML.h"
#include "TObject.h"

enum class TRelationType
{
  Association, DirectedAssociation, ReflexiveAssociation,
  Multiplicity, Aggregation, Composition, Inheritance, Realization
};

template<class T>
class TRelation : public TUML
{
protected:
  TRelationType type;
  TObject<T, 2>* first;
  TObject<T, 2>* second;

  TRelation(const TRelationType& type_, const TObject<T, 2>* first_, const TObject<T, 2>* second_);
  ~TRelation();
};

template<class T>
TRelation<T>::TRelation(const TRelationType& type_, const TObject<T, 2>* first_, const TObject<T, 2>* second_)
{
  type = type_;
  first = first_;
  second = second_;
}

template<class T>
TRelation<T>::~TRelation()
{

}