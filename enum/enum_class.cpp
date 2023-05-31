#include<iostream>

int main()
{
  enum class Color {
    RED,
    BLUE
  };

  Color color = Color::RED;

  if (color == Color::RED)
    std::cout << "The color is red\n";
  else if (color == Color::BLUE)
    std::cout << "The color is blue\n";

  return 0;
}
// 열거형 클래스는 일반 열거형과 달리 강한 형식과 범위를 가진다.
