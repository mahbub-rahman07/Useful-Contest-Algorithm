#!/usr/bin/python

def exp( x, n):
	if ( n == 1 ):
		return x
	if ( n%2 == 0 ):
		return exp( x*x, n//2 )
	return x * exp( x*x, n//2 )
x = 2
n = 1000000
print(exp(x,n))