#include "container.h"

int main()
{
  Cube<char> Cube0(10, '*');
  std::cout << Cube0 << std::endl;

  Square<char> Square0(10, '/');
  std::cout << Square0 << std::endl;

  Rectangle<char> Rectangle0;
  std::cout << Rectangle0 << std::endl;

  Line<char> Line0(7, '*');
  std::cout << Line0 << std::endl;

  Point<char> Point0;
  std::cout << Point0 << std::endl;

  Triangle<char> Triangle0;
  std::cout << Triangle0 << std::endl;

  Simplex<char> Simplex0;
  std::cout << Simplex0 << std::endl;

  std::cout << "=======MEMORY======= " << std::endl;

  Container Container;

  Container.Add(Cube0);
  Container.Add(Square0);
  Container.Add(Rectangle0);
  Container.Add(Line0);
  Container.Add(Point0);
  Container.Add(Simplex0);
  Container.Add(Triangle0);

  Container.Visual(0);
  Container.Visual(3);
  Container.Visual(5);

  Container.Delete(Simplex0);

  Container.Visual(5);

  return 0;
}