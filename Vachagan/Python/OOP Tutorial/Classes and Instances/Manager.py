from Employee import Employee
from Developer import Developer

class Manager(Employee):

    def __init__(self, firstName, lastName, pay, employees=None):
        super().__init__(firstName, lastName, pay)
        self.employees = employees or []
        # if employees is None:
        #     self.employees = []
        # else:
        #     self.employees = employees

    def add_emp(self, emp):
        if emp not in self.employees:
            self.employees.append(emp)
        
    def remove_emp(self, emp):
        if emp in self.employees:
            self.employees.remove(emp)
    
    def print_emps(self):
        for emp in self.employees:
            print('-->', emp.fullName)


if __name__ == "__main__":

    A = Developer("Hayk", "Nahapet", 1500, "Python")
    B = Developer("Anahit", "Voskanyan", 2000, "C++")
    C = Developer("Axun", "Arshakyan", 1500, "Java")

    mgr = Manager("Nver", "Karapetyan", 2000, [A, B, C])

    print(mgr.fullName)

    mgr.add_emp(A)
    mgr.remove_emp(B)
    mgr.add_emp(B)
    mgr.print_emps()

    for dev in mgr.employees:
        print(dev.email)

    print(isinstance(mgr, Developer))
    print(isinstance(mgr, Employee))

    print(issubclass(Manager, Employee))
    print(issubclass(Manager, Developer))