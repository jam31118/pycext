import cu
import numpy as np

N = 10
a = np.arange(N, dtype=float) * 2
b = a * 2

c = cu.add_array(a,b)

print("a: ", a)
print("b: ", b)
print("c: ", c)

