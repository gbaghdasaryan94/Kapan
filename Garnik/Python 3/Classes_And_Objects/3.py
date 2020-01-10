# 3. Create an Author class and a Book class.

class Author:

    def __init__ (self, name, email, gender):
        self.name = name
        self.email = email
        self.gender = gender
        

    @property
    def new_name():
        return self.name

    @new_name.setter
    def new_name(self, new_auth):
        self.name = new_auth

    def __str__(self):
        return f'Email the {self.name} author to {self.email} address'

class Book:
    def __init__ (self, author,  title, price,quantity):
        self.title = title
        self.price = price
        self.quantity = quantity
        self.author = author


    @property
    def new_title():
        return self.title

    @new_title.setter
    def new_title(self, updated_title):
        self.title = updated_title

    @new_title.deleter
    def new_title(self):
        del self.title               


    def profit(self):
        return self.quantity * self.price

    def __str__(self):
        return f'{self.title} book written by {self.author} was sold {self.quantity} item, each with {self.price} dollar ammount. The total amount is {self.profit()}'


if __name__ == "__main__":

    auth = Author("Paruyr Sevak", "psevak@gmail.com", "male")
    book1 = Book(auth.name, "Anlreli Zangakatun", 1300, 10)
    
    print(book1)