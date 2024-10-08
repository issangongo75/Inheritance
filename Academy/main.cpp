#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::endl;


#define delimiter "\n-----------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name, age

using namespace std;

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//     Constructors
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructors:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//       Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		//os << strchr(typeid(*this).name(),' ')+ 1 << ":\t";
	    return os << last_name << " " << first_name << " " << age;
		
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(15);
		ofs << std::left;
		ofs <<std::string (strchr(typeid(*this).name(), ' ') + 1) + ":";
		ofs << last_name << " " << first_name << " " << age;
		return ofs;
		  
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}


#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality,group, rating, attendance
class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& Speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//  Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstrucotr:\t" << this << endl;
	}
	Student(const Human& human, STUDENT_TAKE_PARAMETERS) :Human(human)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << " Sconstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDesturctor: " << this << endl;
	}
	// Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}
};
#define TEACHER_TAKE_PARAMETERS const std::string& speciality,int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	//  Constructor
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	// Methods
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << " " << speciality << " " << experience << " years ";
	}
};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS const std::string& subject
class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	// Constructors:

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate(const Student& student, const std::string& subject) :Student(student)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	std::ostream& print(std::ostream& os)const override
	{
		return Student::print(os) << subject;
	}
};
void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for(int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] group[i];
	}
}


//#define INHERITANCE_1
//#define INHERITANCE_2

//#define Polymorphism
void main()
{
	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;
#ifdef INHERITANCE_1
	Human human("Richter", "Jeffrey", 40);
	human.print();
	cout << delimiter << endl;

	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITANCE_1
#ifdef INHERITANCE_2

	Human human("Vercetty", "Tommy", 30);
	human.print();
	cout << delimiter << endl;

	Student student(human, "Theft", "Vice", 95, 98);
	student.print();
	cout << delimiter << endl;

	Graduate graduate(student, "How to make money");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITANCE_2


	Human* group[] =
	{
		new Student("Pinkamn", "Jessie", 20,"Chemistry", "WW", 95,90),
		new Teacher("White", "Walter",50,"Chemistry",25),
		new Graduate("Schrader","Hank",40,"Criminalistic","OBW",50,70,"How to catch Heisenberg"),
		new Student("Vercetti","Tommy",30,"Theft","Vice",95,98),
		new Teacher("Diaz" ,"Ricardo",50,"Weapons distribution",20)
	};
	Print(group, sizeof(group) / sizeof(group[0]));
	Save(group, sizeof(group) / sizeof(group[0]),"group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
}