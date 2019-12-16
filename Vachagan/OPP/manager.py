from employee import Employee
from developer import Developer

class Manager(Employee):
    
    def __init__(self, first, last, pay, emloyees=None):
        super().__init__(first, last, pay)
        self._emloyees = emloyees or []
    

    @property
    def employees(self):
        return self._emloyees

    def add_emp(self, emp):
        if emp not in self._emloyees:
            self._emloyees.append(emp)

    def remove_emp(self, emp):
        if emp in self._emloyees:
            self._emloyees.remove(emp)
    

    def print_emps(self):
        for emp in self._emloyees:
            print(emp.full_name)


if __name__ == "__main__":
    
    dev1 = Developer("Barac", "Obama", 300, ['Python', 'C'])
    dev2 = Developer("Hmayak", "Nazaryan", 300, ['CSS', 'JS', 'HTML'])
    dev3 = Developer("Axoxa", "Saxs", 300, ['R', 'C'])

    mgr = Manager("Mher", "Sargsyan", 3000)

    mgr.add_emp(dev1)
    mgr.add_emp(dev2)

    print(mgr.employees[1].prog_lang)

    mgr.print_emps()