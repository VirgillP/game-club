//Sample program demonstrating Abstraction, Inheritance, Encapsulation and Polymorphism.
//A game club sample program
#include <iostream>
#include <string>
using namespace std;

//Defining the SuperClass named Person
class Person{

    private:
        string FirstName;
        string LastName;
        int Age;
                  
    protected:
     string UserId;
     string EmailAddress;


    public:
            //The constructor Person. Constructors don't have return type like int, float etc.
        Person(){
            //Intentionally left blank
        }
        Person(string FName, string LName, int Ag){
            FirstName = FName;
            LastName = LName;  
            Age = Ag;
        }
        Person(string UI, string EA){
            UserId = UI;
            EmailAddress = EA;
        }

            void Greeting(void){
                cout << "Greetings Gamer! My name is " << FirstName << " " << LastName << "." << endl;
                cout << "I'm " << Age << " old and I love gaming." << endl;
                }
            
    
};

//Avatar class that inherits userid and emailaddress from SuperClass Person
class Avatar : public Person{

public:
string hobbies;


public://Being explicit here with public. Member functions, member data that follow after public, are public.
    Avatar(string hob){
    hobbies = hob;
    }

    Avatar() : Person(){
        //Intentionally left blank
    }

    Avatar(string UI, string EA) : Person(UI, EA){}

    void AvatarGreeting(void){
                cout << "Find me on game club with my Avatar handler " << UserId << endl;
                cout << "You can also find me with my emailaddress: " << EmailAddress << endl; 
            }
    
    //Polymorphism
    //Three functions with the same and return type but with different formal parameters
    void HighScore(void){
        cout << "You have no score yet. " << endl;
    }
      void HighScore(int iscore) const {
        cout << "My Highscore is " << iscore << endl;
    }
    void HighScore(float fscore){
        cout << "My Highscore is " << fscore << endl;
    }
};

//This class inherits the publicly available string hobbies from the class Avatar
class MyHobbies : public Avatar{

public:
    MyHobbies() : Avatar(){
        //Intentionally left blank
    }

    MyHobbies(string hob) : Avatar(hob){}

    void PromoteHobbies(void){
                cout << "My hobbies are: " << hobbies << endl; 
            }

};


int main(void){
cout << endl;

Person obj0("Virgil", "Pinas", 38);
obj0.Greeting();

cout << endl;

Avatar obj01, obj001("Codebuddie", "username@example.com");
obj001.AvatarGreeting();
cout << endl;
obj01.HighScore(678.9);
cout << endl;

MyHobbies obj3("Coding, Gaming, The great outdoors.");
obj3.PromoteHobbies();

return 0;
}
