# 2. Create an Employee class. Employee should have: id, first_name, last_name, position, salary, working_hours.


class Employee:

    def __init__ (self, id, first_name, last_name, position, salary, working_hours):
        self.id = id
        self.first_name = first_name
        self.last_name = last_name
        self.position = position
        self.salary = salary
        self.working_hours = working_hours

    def get_my_id(self):
        return self.id
    
    def update_my_id(self, new_id):
        self.id = new_id

    def delete_my_id(self):
        self.id = None 

    def annual_salary(self):
        return 12*self.salary

    def raise_salary(self, percent):
        return self.salary + 100 * percent/self.salary         

if __name__ == "__main__":
    
    emp = Employee(1, "Garnik", "Baghdasaryan", "QA Lead", 1000, 8)
    
    emp.update_my_id(2)

    print(emp.id)
    print(emp.annual_salary())
    print(emp.first_name)
    print(emp.last_name)
    print(emp.position)
    print(emp.working_hours)
    print(emp.raise_salary(25))