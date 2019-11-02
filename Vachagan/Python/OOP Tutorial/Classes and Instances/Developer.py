from Employee import Employee

class Developer(Employee):

    raise_amt = 1.10

    def __init__(self, firstName, lastName, pay, prog_lang):
        super().__init__(firstName, lastName, pay)
        self.prog_lang = prog_lang


if __name__ == "__main__":
    print(help(Developer)) 