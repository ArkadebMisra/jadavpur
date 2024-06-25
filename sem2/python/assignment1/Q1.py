
#generator function fo generate primes
def prime_gen():
    # checking starts from number 2
    # i stores the current number that will 
    # checked to see if its a prime

    # primes is a list of all the prime
    # nombers found till now 

    # generator function saves the state
    i=2
    primes = []
    while True:
        if len(primes)==0:
            primes.append(2)
            yield primes[-1]
            i+=1
        else:
            flag = True
            for p in primes:
                if i%p==0:
                    flag=False
                    break

            if flag:
                primes.append(i)
                yield primes[-1]
            i+=1



gen = prime_gen()

n=20
print("generating ", n, " prime numbers")
for i in range(n):
    # next() executes the the generator
    # until it reaches yield statement

    # state of the funcion is saved in generator
    print(next(gen), end=" ")
print("")


                
                    
    