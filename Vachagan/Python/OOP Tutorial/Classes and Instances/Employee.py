
class Employee:
    
    num_of_emps = 0
    raise_amount = 1.04

    def __init__(self, firstName, lastName, pay):
        self.firstName = firstName
        self.lastName = lastName
        self.pay = pay
        # self.email = firstName + '.' + lastName + '@hayit.am'

        Employee.num_of_emps += 1
    @property
    def email(self):
        return f'{self.firstName}.{self.lastName}@hayit.am'
    
    @property
    def fullName(self):
        return f'{self.firstName} {self.lastName}'

    @fullName.setter
    def fullName(self, name):
        first, last = name.split(' ')
        self.firstName = first
        self.lastName = last

    @fullName.deleter
    def fullName(self):
        print("Delete Name!")
        self.firstName = None
        self.lastName = None

    def applyRaise(self):
        self.pay = int(self.pay * self.raise_amount)

    @classmethod
    def set_raise_amt(cls, amount):
        cls.raise_amount = amount
    
    @classmethod
    def from_string(cls, emp_str):
        first, last, pay = emp_str.split('-')
        return cls(first, last, pay)
    
    @staticmethod
    def is_workday(day):
        return day.weekday() not in [5, 6]
        # if day.weekday() == 5 or day.weekday() == 6:
        #     return False
        # return True

    def __repr__(self):
        return f"Employee('{self.firstName}', '{self.lastName}', '{self.pay}')"
    
    def __str__(self):
        return f'{self.fullName} - {self.email}'
    
    def __add__(self, other):
        return self.pay + other.pay

    def __len__(self):
        return len(self.fullName)

   
if __name__ == "__main__":
    A = Employee("Hayk", "Nahapet", 1500)
    B = Employee("Anahit", "Voskanyan", 2000)

    A.firstName = "Valod"
    A.fullName = "Posos Pogosyan"
    print(A.fullName)
    print(A.email)

    del A.fullName

    print(A)

    # print(len(A))

    # emp_str_1 = 'John-Doe-10000'

    # D = Employee.from_string(emp_str_1)

    # print(repr(D))
    # print(str(D))

    # print(D.__repr__())
    # print(D.__str__())

    # print(1+3)
    # print(int.__add__(1,5))
    # print(D.__dict__)

    # import datetime

    # now = datetime.datetime.now()
    # print(Employee.is_workday(datetime.date(2019,10,27)))

    # print(Employee.fullName(A))
    # print(Employee.fullName(B))
    # print(A.fullName())
    # print(B.fullName())

    # A.raise_amount = 2

    # print(A.raise_amount)
    # print(Employee.__dict__)
    # print(A.__dict__)