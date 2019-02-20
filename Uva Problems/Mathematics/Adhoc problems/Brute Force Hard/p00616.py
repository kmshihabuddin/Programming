# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 22:08:34 2019

@author: Shihab
"""

def findDivisors(n,divisors):
    divisors.clear()
    var=2
    while var*var<=n:
        if n%var==0:
            divisors.insert(var)
        var+=1
    return 


total=int(input())

while total>=0:
    
    divisors=[]
    findDivisors(total,divisors)
    print(divisors)
    
    total=int(input())


