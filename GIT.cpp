#include <iostream>
#include <string>
using namespace std;


class AbstractClass { // clasa abstracta
public:
    virtual void doSomething() = 0;
};


class ExceptionNegativ : public std::exception {
public:
    const char* what() const noexcept override {
        return "Salariul nu poate fi negativ";
    }
};

class ExceptionZero : public std::exception {
public:
    const char* what() const noexcept override {
        return "Salariul nu poate fi 0";
    }
};



class Person : public AbstractClass { // clasa concreta implementeaza clasa abstracta
private:
    std::string name;
    std::string CNP;
    std::string birthDate;
    std::string gender;
    std::string home;
    std::string height;
    int age;

    bool validName(string name) {
        // Verifica daca numele este valid
        if (name.empty()) {
            cout << "Numele este invalid! " << endl;
            return false;
        }}


public:
    // Constructor
    Person(const std::string& name, const std::string& CNP, const std::string& birthDate, const std::string& gender, const std::string& home, 
    const std::string& height, int age)  : name(name), CNP(CNP), birthDate(birthDate), gender(gender), home(home), height(height), age(age) {}

    // Getter si Setter
    std::string getName() const { return name; }
    bool setName(string _name) { 
        if(validName(name)){
            name = _name;
            return true;
        }
        return false;
        }


    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }

    std::string getCNP() const { return CNP; }
    void setCNP(const std::string& newCNP) { CNP = newCNP; }

    std::string getBirthDate() const { return birthDate; }
    void setBirthDate(const std::string& newBirthDate) { birthDate = newBirthDate; }

    std::string getGender() const { return gender; }
    void setGender(const std::string& newGender) { gender = newGender; }

    std::string getHome() const { return home; }
    void setHome(const std::string& newHome) { home = newHome; }

    std::string getHeight() const { return height; }
    void setHeight(const std::string& newHeight) { height = newHeight; }



    // Metodele clasei
     virtual void display() const {
        std::cout << "Person - Name: " << name << ", Age: " << age << ", CNP: " << CNP << ", Birth date: " << birthDate << ", Gender: " <<
        gender << ", Home: " << home << ", Height: " << height  << std::endl;

     }


     void doSomething() override { // suprascrierea metodei abstracte
        std::cout << "Clasa Person implementeaza metoda abstracta!!!" << std::endl;
    }

     bool isMale() {
        // Verifica daca perosana este barbat
        return gender == "M";
    }

    bool older(Person other) {
        return birthDate > other.birthDate;
        // returneaza "true" daca persoana este mai in varsta, altfel returneaza "false"
    }
    


    friend void displayPerson(const Person& person); // functia friend

    // Destructor
    ~Person() {
        std::cout << "Destructor called for " << name << std::endl;
    }


}; // class Person end




class Student : public Person {
private:
    int studentId;
 
public:
    // Constructor
    Student(const std::string& name, const std::string& CNP, const std::string& birthDate, const std::string& gender, const std::string& home,
    const std::string& height, int age, int studentId)
    : Person(name, CNP, birthDate, gender, home, height, age), studentId(studentId) {}


    // Getter si Setter
    int getStudentId() const { return studentId; }
    void setStudentId(int newStudentId) { studentId = newStudentId; }


    // Metodele clasei
    void display() const override {
        std::cout << "Student - Name: " << getName() << ", CNP: " << getCNP() << ", Age: " << getAge() << ", Student ID: " << getStudentId() << 
        ", Birth date: " << getBirthDate() << ", Gender: " << getGender() << ", Home: " << getHome() << ", Height: " << getHeight() << std::endl;
    }

    friend void displayStudent(const Student& student); // functia friend


    // Destructor
    ~Student() {
        std::cout << "Destructor called for " << getName() << std::endl;
    }

}; // class Student end



class SalariedStudent : public Student {
private:
    double salary;

public:
    // Constructor
    SalariedStudent(const std::string& name, const std::string& CNP, const std::string& birthDate, const std::string& gender, const std::string& home,
    const std::string& height, int age, int studentId, double salary)
    : Student(name, CNP, birthDate, gender, home, height, age, studentId), salary(salary) {}

    // Getter si Setter
    double getSalary() const { return salary; }
    void setSalary(double newSalary) { salary = newSalary; }


    // Metodele clasei SalariedStudent
      void display() const override {
        std::cout << "Salaried Student - Name: " << getName() << ", CNP: " << getCNP() << ", Birth date: " << getBirthDate() <<
        ", Gender: " << getGender() << ", Home: " << getHome() << ", Height: " << getHeight() <<  ", Age: " << getAge()  << 
        ", Student ID: " << getStudentId() << ", Salary: $" << getSalary() << std::endl;
      }


     // Functia friend
     friend void displaySalariedStudent(const SalariedStudent& salariedStudent);

     // Destructor
    ~SalariedStudent() {
        std::cout << "Destructor called for " << getName() << std::endl;
    }



}; // class SalariedStudent end



// Metodele functiei friend
void displayPerson(const Person& person) {
    std::cout << "Friend Function a fost apelata pentru clasa Person: ";
    person.display();
}

void displayStudent(const Student& student) {
    std::cout << "Friend Function a fost apelata pentru clasa Student: ";
    student.display();
}

void displaySalariedStudent(const SalariedStudent& salariedStudent) {
    std::cout << "Friend Function a fost apelata pentru clasa Salaried Student: ";
    salariedStudent.display();
}


// Metoda process, verifica daca salariul este negativ sau 0 si arunca o exceptie
void process(double salary) {
    if (salary == 0) {
        throw ExceptionZero();
    } else if (salary < 0) {
        throw ExceptionNegativ();
    }
    std::cout << "Salariul  este valid: " << salary << std::endl;
    }




int main() {


    Person Popescu("Popescu Pavel", "1950214294302", "14/02/1998", "M", "Bucuresti", "1.65", 24);
    Popescu.display();

    Student Popa("Popa Marius", "1990912043892", "12/09/2002", "M", "Craiova", "1.72", 20, 943943);
    Popa.display();

    SalariedStudent Oprea("Oprea Daniela", "1950227234344", "22/05/1995", "F", "Brasov", "1.66", 29, 43242, 5000);
    Oprea.display();

    std::cout << "********************************************" << std::endl;

    //metoda clasa abstracta
    Popescu.doSomething();

    std::cout << "********************************************" << std::endl;

      //Firend function
     displayPerson(Popescu);
     displayStudent(Popa);
     displaySalariedStudent(Oprea);

    std::cout << "********************************************" << std::endl;

    //Accesare metode folosind getter si setter
    std::cout << "Accesare metode folosind getter si setter: " << std::endl;
    std::cout << "Name: " << Popescu.getName() << std::endl;
    std::cout << "Age: " << Popa.getAge() << std::endl;
    std::cout << "Student ID: " << Oprea.getStudentId() << std::endl;
    std::cout << "Salary: " << Oprea.getSalary() << std::endl;

    std::cout << "********************************************" << std::endl;

    // Modificare variabile folosind setter
    std::cout << "Modificare variabile folosind setter si apelarea lor folosind getter: " << std::endl;
    Popa.setAge(55);
    Popa.setStudentId(1);
    Oprea.setSalary(2000);

    // Accesare date modificate
    std::cout << "Modified Age: " << Popa.getAge() << std::endl;
    std::cout << "Modified Student ID: " << Popa.getStudentId() << std::endl;
    std::cout << "Modified Salary: " << Oprea.getSalary() << std::endl;

    std::cout << "********************************************" << std::endl;

    // Creating a copy using the copy constructor
    std::cout << "Crearea unei copii a obiectului Oprea folosind un constructor de copiere: " << std::endl;
    SalariedStudent opreaCopy(Oprea); 
    std::cout << "Copied Name: " << opreaCopy.getName() << std::endl;
    std::cout << "Copied Age: " << opreaCopy.getAge() << std::endl;
    std::cout << "Copied Student ID: " << opreaCopy.getStudentId() << std::endl;
    std::cout << "Copied Salary: " << opreaCopy.getSalary() << std::endl;

    std::cout << "********************************************" << std::endl;

    if (Popescu.isMale()) {
        cout << Popescu.getName()  << " este barbat" << endl;
    } else {
        cout << Popescu.getName()  << " este femeie" << endl;
    }


    if (Oprea.isMale()) {
        cout << Oprea.getName()  << " este barbat" << endl;
    } else {
        cout << Oprea.getName()  << " este femeie" << endl;
    }

      std::cout << "********************************************" << std::endl;

 
    Person Stanciu("Stanciu Cristi", "1982123948354", "12/12/1998", "M", "Bacau", "1.78", 28);
    if(Stanciu.setName("")) {
        cout << "Numele este: " << Stanciu.getName() << endl;
    } else {
        cout << "Numele invalid: "<< Stanciu.getName() << endl;
    }

    std::cout << "********************************************" << std::endl;


    if (Stanciu.older(Oprea)) {
        cout << Stanciu.getName() << " este mai in varsta decat " << Oprea.getName() << endl;
    } else {
        cout << Oprea.getName() << " este mai in varsta decat " << Stanciu.getName() << endl;
    }

    std::cout << "********************************************" << std::endl;   

   try {
       process(0);     // ExceptionZero
    } catch (const ExceptionZero& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const ExceptionNegativ& e) {
       std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught generic exception: " << e.what() << std::endl;
    }



    try {
       process(-5);    // ExceptionNegativ 
    } catch (const ExceptionZero& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const ExceptionNegativ& e) {
       std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught generic exception: " << e.what() << std::endl;
    }





    std::cout << "********************************************" << std::endl;
    std::cout << "Apel destructori: " << std::endl;

    return 0;

};