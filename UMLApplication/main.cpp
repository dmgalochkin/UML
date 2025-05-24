#include <iostream>
#include "TContainer.h"


int main()
{
  TContainer<double> container;
  //TRectangle(const int id_, const T* coords_, const int color_ = 0,
  //             const T width_ = 0, const T height_ = 0,
  //             const TString& name_ = "Rectangle", const TString& caption_ = "");
  double coords[2];
  coords[0] = 0;
  coords[0] = 0;
  container.Add(new TRectangle<double>(container.ReserveId(), coords, 1, 3, 7, "Rect1"));
  coords[0] = 1;
  coords[1] = 1;
  container.Add(new TRectangle<double>(container.ReserveId(), coords, 1, 3, 7, "Rect2"));
  container.Show(container.Select(1, 1, 2, 2));
  container.Link(container[0]->GetId(), container[1]->GetId(), TRelationType::Aggregation);
  container.ShowAll();
  container.ShowRelationships();
  for (int i = 0; i < container.GetSize(); ++i)
  {
    std::cout << *container[i];
    std::cout << container[i]->GetArea() << '\n';
    std::cout << '\n';
  }
}