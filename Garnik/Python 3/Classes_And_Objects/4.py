
class Account:
    
    '''4. Create an Account class. Account should have: id, name, balance'''

    def __init__ (self, id, name, balance):
        self.id = id
        self.name = name
        self.balance = balance

    @property
    def get_id(self):
        return self.id

    @get_id.setter
    def setter_id(self, new_id):
        if type(new_id) == int:
            self.id = new_id
        else:
            print("The new id should be integer")    

    @property
    def get_name(self):
        return self.name

    @get_name.setter
    def setter_name(self, new_name):
        if type(new_name) == str:
            self.name = new_name
        else:
            raise "The name should be alphabetical"

    @property
    def get_balance(self):
        return self.balance

    @get_balance.setter
    def setter_ballance(self, new_balance):
        if type(new_balance) == int:
            self.balance = new_balance
        else:
            raise "The balance should be only int"    
        
    def __str__(self):
        return f"The user id is {self.id}, name is {self.name} and the balance is {self.balance}"

    def credit(self, amount):

        '''Adds amount to balance and returns the updated balance.'''

        if type(amount) == int:
            self.balance += amount
            return f'The new balance is {self.balance}'
        else:
            raise "Amount should be a number"

    def debit(self, amount):

        '''Subtracts the amount from the balance,if amount is less than the balance, 
        otherwise outputs “Amount exceeded balance.”'''

        if type(amount) == int:
            if amount > self.balance:
                return "Amount exceeded balance" 
            else:
                return f'The remaingng balance is {self.balance - amount}'
        else:
            raise "The amount should be a number"             
    
    def trasfer_to(self,another_account, amount):

        '''subtracts the amount from the account balance and add it to the given another_account 
        and returns the updated balance, if amount is less than the balance, 
        otherwise output “Amount exceeded balance.”'''

        if type(amount) == int:
            if amount > self.balance:
                return "Amount exceeded balance."
            else:
                self.balance -= amount
                another_account.balance += amount              
                return f"{self.name} account balance is {self.balance}\n{another_account.name} account balance is {another_account.balance}"
        else:
            raise "The amount should be a number"    

    @staticmethod
    def identify_accounts(account_first, account_second):

        ''' identifies if they are the same or not comparing all fields.'''

        if account_first.balance == account_second.balance and account_first.name ==account_second.name:
            return "The accounts are identical"
        else:
            return "The accounts are different"    


if __name__ == "__main__":

    account = Account(1,"Garnik",1500)
    another_account = Account(2, "Garnik",15000)
    
    # print(account.credit(500))
    # account.setter_name = "5"
    # account.setter_id = "we"
    # print(account.debit(500))
    # print(account.trasfer_to(another_account, 2000))
    print(Account.identify_accounts(account, another_account))
    print(account)