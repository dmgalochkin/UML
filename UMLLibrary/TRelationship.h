#pragma once
#include <iostream>
#include "TUML.h"

enum class TRelationType
{
  Association, DirectedAssociation, ReflexiveAssociation,
  Multiplicity, Aggregation, Composition, Inheritance, Realization,
  Arrow
};

class TRelationship : public TUML
{
protected:
  TRelationType type;
  int first;
  int second;
public:
  TRelationship(const int first_, const int second_, const TRelationType type_);
  ~TRelationship();

  TRelationType GetType() const;
  int GetFirst() const;
  int GetSecond() const;

  friend std::ostream& operator<<(std::ostream& o, const TRelationship& p);
};