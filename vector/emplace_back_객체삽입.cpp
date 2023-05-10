#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct President
{
  string name;
  string country;
  int year;
   
  President(string p_name, string p_country, int p_year)
    : name(move(p_name)), country(move(p_country)), year(p_year)
  {
    cout << "I am being constructed.\n";
  }
  
};
 
int main()
{
  vector<President> elections;
  elections.emplace_back("Nelson Mandela", "South Africa", 1994);
  elections.emplace_back("Nelson Mandela2", "South Africa2", 1995);

  cout << "\nContents:\n";
  for (President const& president: elections)
    cout << president.name << " " << president.country << " " << president.year << ".\n";
}
