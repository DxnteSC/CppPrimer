#include <iostream>
#include <string>

class Employee
{
public:
    Employee() = default;
    Employee(const std::string& s): name(s) { ID = ++IDCount; }
    void GetDetails();
    Employee(const Employee& a): name(a.name), ID(++IDCount) {}
    Employee& operator= (const Employee&);
private:
    std::string name;
    int ID;
    static int IDCount;
};

int Employee::IDCount = 0;

Employee& Employee::operator= (const Employee& a)
{
    name = a.name;
    ID = a.ID;
    return *this;
}
void Employee::GetDetails()
{
    std::cout << "Name: " << name << ", ID: " << ID << std::endl;
}
int main()
{
    Employee a("Dante"), b("Lufu"), c(a);
    Employee d("Cray");
    c = b;
    a.GetDetails();
    b.GetDetails();
    c.GetDetails();
    d.GetDetails();
    c.GetDetails();
}
