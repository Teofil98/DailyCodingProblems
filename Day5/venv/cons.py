def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(pair):
    def first(a,b):
        return a
    return pair(first)

def cdr(pair):
    def last(a,b):
        return b
    return pair(last)

def main():
    print("Test:")
    print("First of (3,4) is " + str(car(cons(3,4))))
    print("Last of (3,4) is " + str(cdr(cons(3,4))))

main()
