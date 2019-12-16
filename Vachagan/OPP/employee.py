
class Employee:

    count_of_emp = 0
    raise_amount = 1.06

    def __init__(self, first, last, pay):
        self._first_name = first
        self._last_name = last
        self._pay = pay
        Employee.count_of_emp+=1
        
    
    @property
    def first_name(self):
        return self._first_name

    @first_name.setter
    def first_name(self, name):
        self._first_name = name

    @first_name.deleter
    def first_name(self):
        self._first_name = None
    
    @property
    def last_name(self):
        return self._last_name

    @last_name.setter
    def last_name(self, name):
        self._last_name = name

    @last_name.deleter
    def last_name(self):
        self._last_name = None
    
 
    @property
    def pay(self):
        return self._pay


    @property
    def email(self):
        return f'{self._first_name}.{self._last_name}@email.com'.lower()


    @property
    def full_name(self):
         return f'{self._first_name} {self._last_name}'

    @full_name.setter
    def full_name(self, name):
        first, last = name.split(' ')
        self._first_name = first
        self._last_name = last
    
    @full_name.deleter
    def full_name(self):
        self._first_name = None
        self._last_name = None
    
    def apply_raise(self):
        self._pay = int(self._pay*self.raise_amount)

    @classmethod
    def set_raise_amount(cls, amount):
        cls.raise_amount = amount

    @staticmethod
    def is_work_day(day):
        return day.weekday() not in [5, 6]



if __name__ == "__main__":
        
    emp1 = Employee("Arus", "Tigranyan", 300000)
    emp2 = Employee("Tatev", "Vardanyan", 200000)


    import datetime

    print(Employee.is_work_day(datetime.date(2019, 12, 14)))
