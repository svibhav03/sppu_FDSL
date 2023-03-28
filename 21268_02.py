class StringManip:
    def __init__(self):
        self.s1 = ''

    def take_input(self):
        self.s1 = input("Enter a string: ")

    def msplit(self, a):
        a += ' '
        l1 = []
        s = ''
        for i in a:
            s += i
            if i == ' ':
                l1.append(s)
                s = ''
        return l1

    def largest_word(self):
        a = self.msplit(self.s1)
        out = ''
        for i in a:
            if len(i) >= len(out):
                out = i
        return out

    def frequency(self, a):
        count = 0
        for i in self.s1:
            if i == a:
                count += 1
        return count

    def is_palindrome(self):
        n = len(self.s1)
        for i in range(n):
            if self.s1[i] != self.s1[n - 1 - i]:
                return False
        return True

    def check_sub(self, x):
        for i in range(len(self.s1)):
            if self.s1[i] != x[0]:
                continue
            a = i
            for j in range(len(x)):
                if self.s1[a] != x[j]:
                    break
                a += 1
            if a - i == len(x):
                return i

    def word_frequency(self):
        a = self.msplit(self.s1)
        count = 0
        la = []
        for i in a:
            count = 0
            for j in a:
                if i == j:
                    count += 1
            s = i + ' --> ' + str(count)
            if s not in la:
                la.append(s)
        return la


obj = StringManip()
obj.take_input()

print("The largest word in the string is: ", obj.largest_word())

f = input("\nEnter a character to check its frequency: ")
print(f, " occurs ", obj.frequency(f), " times in the string\n")

if obj.is_palindrome():
    print("The given string is a palindrome\n")
else:
    print("The given string is not a palindrome\n")


g = input("Enter any substring: ")
if obj.check_sub(g) is None:
    print("Substring is not present in the string.\n")
else:
    print(g, " occurs in the string at ", obj.check_sub(g), " index\n")

print("Frequency of words: ", obj.word_frequency())
