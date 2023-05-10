#include<iostream>
#include<string>

enum ItemType
{
  ITEMTYPE_SWORD, // 0
  ITEMTYPE_TORCH, // 1
  ITEMTYPE_POTION // 2
};

std::string getItemName(ItemType i)
{
  if(i == ITEMTYPE_SWORD)
    return std::string("Sword");
  else
    return std::string("몰ㄹ?루");
}

int main(){
  enum ItemType i = ITEMTYPE_TORCH; // 열거형 변수 선언 방법 1
  ItemType j = ITEMTYPE_SWORD;      // 열거형 변수 선언 방법 2

  std::cout << getItemName(i) << "\n";
  std::cout << getItemName(j) << "\n";

  return 0;
}
