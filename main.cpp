#include <iostream>

using namespace std;

class Person {
private:
    string first_name;
    string last_name;

    int age;

public:
    Person(string last_name_, string first_name_, int age_) {
        this->last_name = last_name_;
        this->first_name = first_name_;
        this->age = age_;
    }

    Person(string last_name_, string first_name_) {

        this->last_name = last_name_;
        this->first_name = first_name_;
        this->age = 18;
    }

    Person(){
        this->last_name = "Ivanov";
        this->first_name = "Ivan";
        this->age = 18;
    }

    ~Person() {
        cout << "Delete person " + last_name + " " + first_name + ", " << age << endl;
    }

    void print() {
        cout << "Last name: " << last_name << endl << "First name: " << first_name << endl << "Age: " << age << endl;
        cout << "-----------------------" << endl;
    }

    string getLastName() {
        return last_name;
    }

    int getAge() {
        return age;
    }

    bool operator>(Person& other) {
        return age > other.age;
    }


};

class Scoped_Ptr {
    Person* obj;
    Scoped_Ptr(const Scoped_Ptr& obj){}
public:
    Scoped_Ptr(Person* obj_) {
        this->obj = obj_;
    }

    Person* ptr() {
        return obj;
    }

    Person* operator->() {return obj;}
    Person& operator*() {return *obj;}

    ~Scoped_Ptr() {
        delete(obj);
    }

};

void print(Scoped_Ptr scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Scoped_Ptr" << endl;
    scoped->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}
void print(Scoped_Ptr* scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Scoped_Ptr*" << endl;
    (*scoped)->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}

template <class T>
class Auto_Ptr {
    T* obj;

public:

    Auto_Ptr(T* obj_) {
        this->obj = obj_;
    }
    Auto_Ptr(Auto_Ptr* autoPtr) {
        if(this == &autoPtr) {
            return;
        }
        delete obj;
        this->obj = autoPtr->obj_;
        autoPtr->obj = 0;
    }

    Person* ptr() {
        return obj;
    }

    T* operator->() {return obj;}
    T& operator*() {return *obj;}

    ~Auto_Ptr() {
        delete(obj);
    }

    Auto_Ptr(Auto_Ptr& other) {
        this->obj = other.obj;
        other.obj=0;
    }
    Auto_Ptr& operator=(Auto_Ptr& other) {
        if(this == &other) {
            return *this;
        }
        delete obj;
        this->obj = other.obj;
        other.obj = 0;
        return *this;
    }
};



void print(Auto_Ptr<Person> scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Auto_Ptr" << endl;
    scoped->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}
void print(Auto_Ptr<Person>* scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Auto_Ptr*" << endl;
    (*scoped)->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}


struct Storage{
    unsigned int count;
    Person* obj;
    Storage(Person* _obj = 0):obj(_obj),count(1){}
    ~Storage() {
        if(count==0) delete obj;
    }
};

class Shared_Ptr {
    Storage* storage;
public:
    Shared_Ptr(Person* obj = 0) {
        storage = new Storage(obj);
    }
    Shared_Ptr(const Shared_Ptr& other) {
        storage = other.storage;
        storage->count++;
    }
    Shared_Ptr& operator=(const Shared_Ptr& other) {
        if(this == &other) return *this;
        storage->count--;
        storage = other.storage;
        storage->count++;
        return *this;
    }
    bool operator>(const Shared_Ptr& other) {
//        if(this == &other) return false;
        return *(storage->obj) > *(other.storage->obj);
    }

    void svap(Shared_Ptr& other) {
        Storage* storage_tmp = this->storage;
        this->storage = other.storage;
        other.storage = storage_tmp;
    }

    ~Shared_Ptr(){
        if(this->storage->count<=1) {
            delete storage;
            return;
        }
        storage->count--;
    }
    Person* operator->() {return storage->obj;}
    Person& operator*() {return *storage->obj;}
};



void print(Shared_Ptr scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Shared_Ptr" << endl;
    scoped->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}
void print(Shared_Ptr* scoped) {
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
    cout << "Print Shared_Ptr*" << endl;
    (*scoped)->print();
    cout << "\\\\\\\\\\\\\\\\\\" << endl;
}


int main() {
    {
        cout << "Scoped Ptr:" << endl;
        Scoped_Ptr scoped(new Person("Ivan", "Ivanov"));
        scoped->print();
        (*scoped).print();

//        print(scoped);
        print(&scoped);
//  Не работает т.к содержимое будет удаляться дважды
//    Scoped_Ptr p2 = scoped;
    }
    {
        cout << endl << "Auto Ptr:" << endl;
        Auto_Ptr<Person> autoptr(new Person("Ivan", "Ivanov", 16));
        // Требуется ли это?
        //Auto_Ptr<Person> autoptr1 = (new Person("Ivan", "Ivanov", 16));
        cout << autoptr.ptr() << endl;
        Auto_Ptr<Person> autoPtr2 = autoptr;
        cout << autoptr.ptr() << endl;
        cout << autoPtr2.ptr() << endl;
        print(&autoPtr2);
        print(autoPtr2);
    }

    {
        cout << endl << "Shared Ptr:" << endl;
         Shared_Ptr sharedPtr = new Person("Ivan", "Ivanov", 17);
        sharedPtr->print();
        Shared_Ptr sharedPtr1 = sharedPtr;
        sharedPtr->print();
        sharedPtr->print();
        print(sharedPtr);
        print(&sharedPtr);
    }
    {
        cout << endl << "Shared_Ptr Array:" << endl;
        Shared_Ptr* sharedPtr = new Shared_Ptr[10];
        for(int i = 0; i < 10; i++) {
            int randInt = (rand()%('Z'-'A'));
            char* randChar = new char[2];
            randChar[0] = 'A'+randInt;
            randChar[1] = 0;
            string name = "Ivan" + string(randChar);
            sharedPtr[i] = new Person(name, "Sidorov", 18+(randInt));
            cout << "Add in array: ";
            sharedPtr[i]->print();
        }
        for(int i = 0; i < 10; i++) {
            cout << sharedPtr[i]->getLastName() << ", " << sharedPtr[i]->getAge() << "|";
        }
        cout << endl;

        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < 9; i++) {
                if(sharedPtr[i] > sharedPtr[i+1]) {
                    flag = true;
                    sharedPtr[i].svap(sharedPtr[i+1]);
                }
            }
        }
        for(int i = 0; i < 10; i++) {
            cout << sharedPtr[i]->getLastName() << ", " << sharedPtr[i]->getAge() << "|";
        }


    }
}`