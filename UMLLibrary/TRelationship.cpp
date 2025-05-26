#include "TRelationship.h"

TRelationship::TRelationship(const int first_, const int second_, const TRelationType type_)
{
  type = type_;
  first = first_;
  second = second_;
}

TRelationship::~TRelationship()
{

}

TRelationType TRelationship::GetType() const
{
  return type;
}

int TRelationship::GetFirst() const
{
  return first;
}

int TRelationship::GetSecond() const
{
  return second;
}

std::ostream &operator<<(std::ostream &o, const TRelationship &p)
{
  o << p.first << ' ' << p.second << ' ';
  switch (p.type)
  {
    case TRelationType::Association:
      o << "Association";
      break;
    case TRelationType::DirectedAssociation:
      o << "DirectedAssociation";
      break;
    case TRelationType::ReflexiveAssociation:
      o << "ReflexiveAssociation";
      break;
    case TRelationType::Multiplicity:
      o << "Multiplicity";
      break;
    case TRelationType::Aggregation:
      o << "Aggregation";
      break;
    case TRelationType::Composition:
      o << "Composition";
      break;
    case TRelationType::Inheritance:
      o << "Inheritance";
      break;
    case TRelationType::Realization:
      o << "Realization";
      break;
    case TRelationType::Arrow:
      o << "Arrow";
      break;
  }
  return o;
}



