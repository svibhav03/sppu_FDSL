class SortQuick:
    def __init__(self):
        self.scores = []

    def take_input(self):
        x = int(input('Enter the number of elements: '))
        for i in range(x):
            self.scores.append(int(input('Enter the number: ')))

    def partition(self, array, low, high):
        pivot = array[high]
        i = low-1

        for j in range(low, high):
            if array[j] <= pivot:
                i += 1
                (array[i], array[j]) = (array[j], array[i])
        (array[i+1], array[high]) = (array[high], array[i+1])

        return i+1

    def quick_sort(self, array, low, high):
        if low < high:
            pi = self.partition(array, low, high)
            self.quick_sort(array, low, pi-1)
            self.quick_sort(array, pi+1, high)


obj = SortQuick()
obj.take_input()
obj.quick_sort(obj.scores, 0, len(obj.scores)-1)

print(obj.scores)

