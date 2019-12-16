from employee import Employee

class Developer(Employee):

    raise_amount = 1.1

    def __init__(self, first, last, pay, prog_lang=None):
        # Employee.__init__(self, first, last, pay)
        # self._first_name = first
        # self._last_name = last
        # self._pay = pay
        super().__init__(first, last, pay)
        self._prog_lang=prog_lang or []

    @property
    def prog_lang(self):
        return self._prog_lang
    
    @prog_lang.setter
    def prog_lang(self, lang):
        if lang not in self._prog_lang:
            self._prog_lang.append(lang)
    
    @prog_lang.deleter
    def prog_lang(self):
        self._prog_lang = []
    
    
    def remove_lang(self, lang):
        if lang in self._prog_lang:
            self._prog_lang.remove(lang)
    


if __name__ == "__main__":
    
    dev1 = Developer("Barac", "Obama", 300, ['Python', 'C', 'Pascal'])
    dev1.prog_lang = "HTML"
    dev1.remove_lang("Python")
    print(dev1.__dict__)