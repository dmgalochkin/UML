#include <iostream>
#include "TContainer.h"


int main()
{
  TContainer<double> container;

  double coords[2];
  coords[0] = 0;
  coords[0] = 0;
  container.Add(new TRectangle<double>(container.ReserveId(), coords, 1, 3, 7, "Rect1"));
  coords[0] = 1;
  coords[1] = 1;
  container.Add(new TRectangle<double>(container.ReserveId(), coords, 1, 4, 5, "Rect2"));
  container.Add(new TCircle<double>(container.ReserveId(), coords, 1, 5, "Circle1"));

  std::cout << "Objects in range (1, 1, 2, 2):\n";
  container.Show(container.Select(1, 1, 2, 2));
  container.Link(container[0]->GetId(), container[1]->GetId(), TRelationType::Aggregation);
  std::cout << "All objects:\n";
  container.ShowAll();
  std::cout << "All relationships:\n";
  container.ShowRelationships();
  std::cout << "Cout sample:\n";
  for (int i = 0; i < container.GetSize(); ++i)
  {
    std::cout << *container[i];
    std::cout << "Area: ";
    std::cout << container[i]->GetArea() << '\n';
    std::cout << '\n';
  }
}