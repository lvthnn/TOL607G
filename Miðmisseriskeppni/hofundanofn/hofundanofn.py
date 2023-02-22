if __name__ == '__main__':
    name = input()

    a = name.split(' ')

    if (len(a) == 1):
        print(a[0])
    else:
        print(a[len(a) - 1], end=', ')
        for i in range(0, len(a) - 1):
            print(a[i][0] + '. ', end='')
