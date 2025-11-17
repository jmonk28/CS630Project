import time

def main():
    sum_val = 0
    n = 984_600_000

    print("Program starting...")

    start = time.process_time()   # CPU time, like clock() in C
    print("Start time: {:.3f}".format(start))

    for i in range(1, n + 1):
        sum_val += i

    end = time.process_time()
    print("End time: {:.3f}".format(end))

    elapsed = end - start
    print("Time elapsed: {:.8f} seconds".format(elapsed))
    print("Sum: {}".format(sum_val))


if __name__ == "__main__":
    main()
