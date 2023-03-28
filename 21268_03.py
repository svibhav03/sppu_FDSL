class MatrixManip:
    def __init__(self):
        self.m1 = []
        self.m2 = []
        self.add = []
        self.sub = []
        self.mul = []
        self.trans = []
        self.rows1 = 0
        self.rows2 = 0
        self.columns1 = 0
        self.columns2 = 0

    def take_input_1(self):
        self.rows1 = int(input("Enter the number of rows: "))
        self.columns1 = int(input("Enter the number of columns: "))
        for i in range(self.rows1):
            l2 = []
            for j in range(self.columns1):
                l2.append(int(input("Enter the number: ")))
                print(l2)
            self.m1.append(l2)
        print("Matrix 1: ", self.m1)

    def take_input_2(self):
        self.rows2 = int(input("Enter the number of rows: "))
        self.columns2 = int(input("Enter the number of columns: "))
        for i in range(self.rows2):
            l2 = []
            for j in range(self.columns2):
                l2.append(int(input("Enter the number: ")))
                print(l2)
            self.m2.append(l2)
        print("Matrix 2: ", self.m2)

    def add_mat(self):
        if (self.rows1 != self.rows2) or (self.columns1 != self.columns2):
            print("Cannot add the matrices because their rows and columns arent equal!")
        else:
            for i in range(self.rows1):
                l2 = []
                for j in range(self.rows2):
                    l2.append(self.m1[i][j] + self.m2[i][j])
                self.add.append(l2)
            return self.add

    def sub_mat(self):
        if (self.rows1 != self.rows2) or (self.columns1 != self.columns2):
            print("Cannot subtract the matrices because their rows and columns arent equal!")
        else:
            for i in range(self.rows1):
                l2 = []
                for j in range(self.rows2):
                    l2.append(self.m1[i][j] - self.m2[i][j])
                self.sub.append(l2)
            return self.sub

    def mul_mat(self):
        if self.columns1 != self.rows2:
            print("Multiplication not possible because number of columns of first matrix "
                  "are not equal to number of rows of second matrix")
        else:
            for i in range(self.rows1):
                l2 = []
                for j in range(self.columns2):
                    s = 0
                    for k in range(self.rows2):
                        s += self.m1[i][k]*self.m2[k][j]
                    l2.append(s)
                self.mul.append(l2)
            return self.mul

    def transpose(self):
        for i in range(self.rows1):
            l2 = []
            for j in range(self.columns1):
                l2.append(self.m1[j][i])
            self.trans.append(l2)
        return self.trans


obj = MatrixManip()
print("Matrix 1: ")
obj.take_input_1()
print("\nMatrix 2: ")
obj.take_input_2()
print("\nThe addition of the two matrices is: \n", obj.add_mat())
print("\nThe subtraction of the two matrices is: \n", obj.sub_mat())
print("\nThe multiplication of the two matrices is: \n", obj.mul_mat())
print("\nTranspose of M1: ", obj.transpose())







