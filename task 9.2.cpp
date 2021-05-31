#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Human{
  protected:
   string PIB;
   bool gender;
   unsigned age;
  public:
  Human(){}
  Human(string s1,bool s2,unsigned a):PIB(s1),gender(s2),age(a){}

  void output(){
         const char* gen = gender?"Male":"Female";
          cout << PIB << ", " << age <<"," << gen<<endl;

  }



  friend ostream& operator<<(ostream & ost, const Human & h){
          const char* gen = h.gender?"Male":"Female";
          ost << h.PIB << ", " << h.age <<"," << gen<<endl;
  }

  int input(){

     cout<<"PIB:";
     cin>> PIB;
     cout<<"age:";
     cin>> age;
     cout<<"Male or Female? M/F?";
     string sex;
     cin>>sex;
     if (tolower(sex[0])=='f'){
       gender =false;
      }
     else{
       gender =true;
     }

    return 0;
  }

  virtual void getVUZ(){}

};

class Student : virtual public Human{


  protected:
   string VUZ;
    int kurs;
    string grupa;

   public:
    Student(){}

    Student(string s1,bool s2,unsigned a, int kurs, string s3, string s4):Human(s1,s2,a){
         this->kurs = kurs;
         grupa = s3;
         VUZ = s4;
    }

   int input(){
      Human::input();
      cout<<"Kurs, grupa, VUZ";
      cin>>kurs;
      cin>>grupa;
      cin>>VUZ;
   }

     friend ostream& operator<<(ostream & ost, Student & h){
          h.output();
          //const char* gen = h.gender?"Male":"Female";
          //ost << h.PIB << ", " << h.age <<"," << gen<<endl;
          ost << h.VUZ<<":"<<h.kurs<<", "<< h.grupa<<endl;

  }

   void getVUZ(){
     cout<<VUZ;
  }

};


class Lecturer: virtual public Human{
     string VUZ;
  protected:
   string posada;
   float salary;
  public:
   Lecturer(){}
   Lecturer(string s1,bool s2,unsigned a, string s3, string s4, float sal):Human(s1,s2,a){
         this->VUZ = s3;
         posada = s4;
         salary = sal;
    }

   int input(){
      Human::input();
      cout<<"VUZ, posada, salary";
      cin>>VUZ;
      cin>>posada;
      cin>>salary;
   }

   friend ostream& operator<<(ostream & ost, Lecturer & h){
      h.output();
      ost << h.VUZ<<":"<<h.posada<<", "<< h.salary<<endl;

   }



};


class PGStudent : public Student, public Lecturer{

  public:
 PGStudent(){}
   PGStudent(string s1,bool s2,unsigned a, int kurs, string s3, string s4,
                              string s6, float sal):Student(s1,s2,a, kurs,s3,s4){

         posada = s6;
         salary = sal;
    }

     int input(){
      Student::input();
      cout<<"Posada, salary: ";
      cin>>posada;
      cin>>salary;
   }


   friend ostream& operator<<(ostream & ost, PGStudent & h){
      h.output();
      ost <<":"<<h.posada<<", "<< h.salary<<endl;
      ost << h.kurs<<", "<< h.grupa<<endl;
      h.getVUZ();
   }

};


int main(){

   int N=3;
   Human* m1[10];

   //int N=2;
   for(int i=0;i<N;++i){
    cout<<"Lecturer or student or aspirant l/s/a?";
    string str;
    cin>>str;

    if (tolower(str[0])=='l'){
      Lecturer* l = new Lecturer();
      l->input();

      m1[i] =l;
    }
   else if(tolower(str[0])=='a'){
      PGStudent* l = new PGStudent();
      l->input();

      m1[i] =l;
   }
   else{
      Student* l = new Student;
      l->input();

      m1[i] = l;
    }

  }


   for(int i=0;i<N;++i){
	cout<<(*m1[i]);
        Lecturer* l1 = dynamic_cast<Lecturer*> (m1[i]);
        if(l1!=nullptr) cout<< l1;
        m1[i]->getVUZ();
  }


}

