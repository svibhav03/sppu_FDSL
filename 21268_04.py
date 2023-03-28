class RollSearch:
    def __init__(self):
        print('This program takes a list of roll numbers as input and enables searching a')
        print('particular number using 4 types of searching techniques.')
        self.roll = []
        self.sort = []

    def random_input(self):
        a = int(input("Enter the number of students: "))
        for i in range(a):
            self.roll.append(int(input("Enter the roll numbers randomly: ")))
        print("List completed!\n")

    def linear_search(self):
        a = int(input("Enter the roll number to be searched: "))
        for i in range(len(self.roll)):
            if self.roll[i] == a:
                print("Found in the list at position ", i)
                break
        else:
            print("NOT FOUND!")

    def sent_search(self):
        a = int(input("Enter the roll number to be searched: "))
        self.roll.append(a)
        count = 0
        while self.roll[count] != a:
            count += 1
        if count == len(self.roll) - 1:
            print("NOT FOUND!")
        else:
            print("Found in the list at position ", count)
        self.roll.pop(len(self.roll)-1)

    def in_sort(self):
        self.sort = self.roll
        for i in range(1, len(self.roll)):

            x = self.sort[i]
            j = i - 1
            while j >= 0 and x < self.sort[j]:
                self.sort[j+1] = self.sort[j]
                j -= 1
            self.sort[j+1] = x
        return self.sort

    def bin_search(self):
        a = int(input("Enter the roll number to be searched: "))
        high = len(self.sort) - 1
        low = 0
        while high - low > 1:
            m = (high + low) // 2
            if self.sort[m] < a:
                low = m + 1
            else:
                high = m

        if self.sort[low] == a:
            print("Found in the list at position ", low)
        elif self.sort[high] == a:
            print("Found in the list at position ", high)
        else:
            print("NOT FOUND!")

    def fib_search(self):
        a = int(input("Enter the roll number to be searched: "))
        n = len(self.sort)
        x = 0
        y = 1
        fib = x + y
        while fib < n:
            x = y
            y = fib
            fib = x + y
        off = -1
        while fib > 1:
            i = min(off + x, n-1)

            if self.sort[i] < a:
                fib = y
                y = x
                x = fib - y
                off = i

            elif self.sort[i] > a:
                fib = x
                y = y - fib
                x = fib - y

            else:
                return i

        if y and self.sort[n-1] == a:
            return n-1
        return -1


obj = RollSearch()
obj.random_input()
print("Your input list: ", obj.roll)
print("Linear search: ")
obj.linear_search()
print("Sentinel search: ")
obj.sent_search()
obj.in_sort()
print('\nList has been sorted')
print("Sorted list: ", obj.sort)
print("Binary search: ")
obj.bin_search()
print("Fibonacci search: ")
ans = obj.fib_search()
if ans == -1:
    print("NOT FOUND!")
else:
    print('Found at index ', ans)
