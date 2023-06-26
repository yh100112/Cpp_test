#include<iostream>
#include<string>
using namespace std;

enum ItemType
{
  ITEMTYPE_SWORD, // 0
  ITEMTYPE_TORCH, // 1
  ITEMTYPE_POTION // 2
};

string getItemName(ItemType i)
{
  if(i == ITEMTYPE_SWORD) return "Sword";
  else                    return "몰ㄹ?루";
}

int main(){
  enum ItemType i = ITEMTYPE_TORCH; // 열거형 변수 선언 방법 1
  ItemType j = ITEMTYPE_SWORD;      // 열거형 변수 선언 방법 2
  cout << getItemName(i) << "\n";
  cout << getItemName(j) << "\n";
}
