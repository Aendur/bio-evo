"""
chaos.py
for Python 2.7 / 3.4

Usage: python chaos.py <X0> <A> <Iterations>

Runs Xt+1 = A*Xt*(1-Xt) for each t in 0 ... Iterations, with Xt0 = X0 
and prints the results to stdout.
 
0 <= X <= 1
0 <= A <= 4
"""
import sys

def x1 (x0, a): return a*x0*(1-x0)

if len(sys.argv) < 4:
	print(__doc__)
	sys.exit()

else:
	x0 = float(sys.argv[1])
	a = float(sys.argv[1])
	iters = int(sys.argv[3])
	
	history = [x0]
		
	for i in range(iters):
		xn = x1(history[i], a)
		history.append(x1(history[i], a))
		print("%3d %25.20f %35.20f x 10^10" % (i, history[i], history[i]*10000000000))
	
