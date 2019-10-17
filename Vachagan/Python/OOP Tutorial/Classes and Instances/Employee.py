
class Employee:
    
    num_of_emps = 0
    raise_amount = 1.04

    def __init__(self, firstName, lastName, pay):
        self.firstName = firstName
        self.lastName = lastName
        self.pay = pay
        self.email = firstName + '.' + lastName + '@hayit.am'

        Employee.num_of_emps += 1

    def fullName(self):
        return '{} {}'.format(self.firstName, self.lastName)

    def applyRaise(self):
        self.pay = int(self.pay * self.raise_amount)

A = Employee("Hayk", "Nahapet", 1500)
B = Employee("Anahit", "Voskanyan", 2000)

print(Employee.fullName(A))
print(Employee.fullName(B))
print(A.fullName())
print(B.fullName())

A.raise_amount = 2

print(A.raise_amount)
print(Employee.__dict__)
print(A.__dict__)