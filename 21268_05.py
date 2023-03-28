class RollSort:
    def __init__(self):
        self.roll = []
        self.sort = []

    def random_input(self):
        a = int(input("Enter the number of students: "))
        for i in range(a):
            self.roll.append(float(input("Enter the percentage marks randomly: ")))
        print("List completed!\n")

    def in_sort(self):
        for i in range(1, len(self.roll)):
            self.sort = self.roll
            x = self.sort[i]
            j = i - 1
            while j >= 0 and x < self.sort[j]:
                self.sort[j+1] = self.sort[j]
                j -= 1
            self.sort[j+1] = x
        return self.sort

    def shell_sort(self):
        n = len(self.roll)
        interval = n//2
        while interval > 0:
            for i in range(interval, n-1):
                temp = self.roll[i]
                j = i
                while j >= interval and self.roll[j-interval] > temp:
                    self.roll[j] = self.roll[j-interval]
                    j -= interval
                self.roll[j] = temp
            interval //= 2
        return self.roll


obj = RollSort()
obj.random_input()
print('Insertion Sort: ', obj.in_sort())
print('Shell Sort:     ', obj.shell_sort())

print('Top five scores: ')
m = len(obj.roll)
o = min(5, m)
for y in range(o):
    print(obj.sort[m-1-y], end=', ')



