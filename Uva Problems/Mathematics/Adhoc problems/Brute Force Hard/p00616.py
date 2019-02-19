# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 22:08:34 2019

@author: Shihab
"""

"""
total=int(input())

while total>=0:
    
    pass
    
    total=int(input())
"""

def f(n,k):
    return ((k+1)*n-1)*(n/(n-1))**n-n+1

print(f(5,4))