class SetManip:
    def __init__(self):
        self.cricket = []
        self.badminton = []
        self.football = []
        self.c_b = []
        self.c_or_b = []
        self.not_c_not_b = []
        self.c_and_f_not_b = []

    def build_set(self):

        print('Building cricket list: ')
        n = int(input('Enter the number of entries for Cricket: '))
        while n != 0:
            name = input('Name of student: ')
            if name in self.cricket:
                print('Name is already in the list!!')
            else:
                self.cricket.append(name)
                n -= 1
        print('List completed!\n')

        print('Building football list: ')
        n = int(input('Enter the number of entries for Football: '))
        while n != 0:
            name = input('Name of student: ')
            if name in self.football:
                print('Name is already in the list!!')
            else:
                self.football.append(name)
                n -= 1
        print('List completed!\n')

        print('Building badminton list: ')
        n = int(input('Enter the number of entries for Badminton: '))
        while n != 0:
            name = input('Name of student: ')
            if name in self.badminton:
                print('Name is already in the list!!')
            else:
                self.badminton.append(name)
                n -= 1
        print('List completed!\n')

    def intersection(self, a, b, c):

        for i in a:
            if i in b:
                c.append(i)

    def union(self, a, b, c):

        for i in a:
            if i not in b:
                c.append(i)

        for i in b:
            if i not in a:
                c.append(i)

    def strictly_set(self, a, b, c, d):

        for i in a:
            if i not in b and i not in c:
                d.append(i)

    def a_and_b_not_c(self, a, b, c, d):

        for i in a:
            if i in b and i not in c:
                d.append(i)

    def main(self):

        self.build_set()
        print('Your inputs: \n')
        print('Cricket: ', self.cricket)
        print('Badminton: ', self.badminton)
        print('Football: ', self.football)
        self.intersection(self.cricket, self.badminton, self.c_b)
        self.union(self.cricket, self.badminton, self.c_or_b)
        self.strictly_set(self.football, self.cricket, self.badminton, self.not_c_not_b)
        self.a_and_b_not_c(self.cricket, self.football, self.badminton, self.c_and_f_not_b)
        print('\nFinal output lists: \n')
        print('Both Cricket and Badminton: ', self.c_b)
        print('Either Cricket or Badminton: ', self.c_or_b)
        print('Neither Cricket nor Badminton: ', len(self.not_c_not_b))
        print('Cricket and Football but not badminton: ', len(self.c_and_f_not_b))


s1 = SetManip()
if __name__ == "__main__":
    s1.main()
