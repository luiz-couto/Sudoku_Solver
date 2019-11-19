import numpy as np
import random
import math
import sys

N = "9"
J = "3"
I = "3"

if (N == "4"):
    print(N + " " + I + " " + J)
    print("0 0 0 0")
    print("0 0 0 0")
    print("0 0 0 0")
    print("0 0 0 0")

if (N == "6"):
    print(N + " " + I + " " + J)
    print("3 0 0 1 0 5")
    print("0 0 5 0 0 6")
    print("0 0 0 5 0 0")
    print("0 0 2 0 0 0")
    print("2 0 0 6 0 0")
    print("5 0 4 0 2 2")

if (N == "8"):
    print(N + " " + I + " " + J)
    print("0 0 0 0 0 0 0 0")
    print("5 0 1 7 6 2 4 0")
    print("0 0 0 0 2 0 0 8")
    print("2 0 3 0 0 6 0 0")
    print("0 0 6 0 0 4 0 5")
    print("3 0 0 4 0 0 0 0")
    print("0 1 8 3 4 7 0 2")
    print("0 0 0 0 0 7 0 0")

if (N == "9"):
    print(N + " " + I + " " + J)
    print("0 0 0 0 0 0 0 0 0")
    print("4 9 0 2 0 5 0 0 8")
    print("0 0 0 3 8 7 0 1 0")
    print("0 1 3 0 0 0 4 8 0")
    print("0 0 9 0 2 0 1 0 0")
    print("0 5 6 0 0 0 7 2 0")
    print("0 3 0 6 5 1 0 0 0")
    print("1 0 0 7 0 4 0 9 0")
    print("0 0 0 0 0 0 0 4 0")