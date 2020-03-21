/*
Concept: OOP, class, bubble sort by object
Date: 2020/02/26
*/

#include <iostream>
#include <string>
using namespace std;

//define class
class Student
{
  private:
    string id;
    string name;
    double midscore;
    double finalscore;
    double normscore;
    double termscore;
  public:
    void set_value(string, string, double, double, double);
    void show();
    void calculate();
    string get_id();
    string get_name();
};

void Student::set_value(string iid, string nname, double mid, double final, double norm)
{
  id = iid;
  name = nname;
  midscore = mid;
  finalscore = final;
  normscore = norm;
  termscore = 0;
}

void Student::show()
{
    cout << id  << "\t";
    cout << name << "\t";
    cout << midscore << "\t";
    cout << finalscore << "\t";
    cout << normscore << "\t";
    cout << termscore << endl;
}

void Student::calculate()
{
  termscore = midscore * 0.3 + finalscore* 0.3 + normscore * 0.4;
}

string Student::get_id()
{
  return id;
}

string Student::get_name()
{
  return name;
}

Student stu[100];   //object declaratin

int main()
{
  int total; 
  cin >> total;
  string id, name;
  double mid, final, norm;

  //input data;
  for(int i = 1; i <= total; i++)
  {
    cin >> id >> name >> mid >> final >> norm;
    stu[i].set_value(id, name, mid, final, norm);
    stu[i].calculate();
  }
  
  //show original dta
  cout << "--------------------------------------" << endl; 

  cout << "Original:" << endl;
  for (int i = 1; i <= total; i++) stu[i].show();

  cout << "--------------------------------------" << endl; 

  //bubble sort by name
  for (int pass = 1; pass <= total; pass++)
  {
    for (int i = 1; i < total; i++)
    {
      if (stu[i].get_name() > stu[i+1].get_name())
      {
        Student temp;
        temp = stu[i];
        stu[i] = stu[i+1];
        stu[i+1] = temp;
      }
    }
  }

  // show data sorted by name
  cout << "Sorted by name:" << endl;
  for (int i=1; i<=total; i++) 
  {
    stu[i].show();
  }
  cout << "--------------------------------------" << endl; 

  return 0;  
}

/*
10
10630101 Amy 90 80 60
10630102 Anny 100 100 100
10630103 Mary 98 80 98
10630104 Betty 100 98 60
10630105 Kerry 99 99 99
10630106 Beauty 100 100 98
10630107 David 90 60 80
10630108 Jason 99 96 98
10630109 Anita 99 97 95
10630110 Kiki 95 100 100
--------------------------------------
Original:
10630101  Amy 90  80  60  75
10630102  Anny  100 100 100 100
10630103  Mary  98  80  98  92.6
10630104  Betty 100 98  60  83.4
10630105  Kerry 99  99  99  99
10630106  Beauty  100 100 98  99.2
10630107  David 90  60  80  77
10630108  Jason 99  96  98  97.7
10630109  Anita 99  97  95  96.8
10630110  Kiki  95  100 100 98.5
--------------------------------------
Sorted by name:
10630101  Amy 90  80  60  75
10630109  Anita 99  97  95  96.8
10630102  Anny  100 100 100 100
10630106  Beauty  100 100 98  99.2
10630104  Betty 100 98  60  83.4
10630107  David 90  60  80  77
10630108  Jason 99  96  98  97.7
10630105  Kerry 99  99  99  99
10630110  Kiki  95  100 100 98.5
10630103  Mary  98  80  98  92.6
--------------------------------------

*/
