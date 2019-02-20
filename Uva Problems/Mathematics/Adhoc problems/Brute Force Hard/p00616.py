# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 22:08:34 2019

@author: Shihab
"""

def findDivisors(n,divisors):
    var=2
    while var*var<=n:
        if n%var==0:
            divisors.append(var)
        var+=1
    return 

def isValid(total,people):
    for _ in range(people):
        total-=1
        if total%people:
            return False
        total=(total*(people-1))//people
    return total%people==0


total=int(input())

while total>=0:
    
    divisors=[]
    findDivisors(total-1,divisors)
    
    res=-1
    for divisor in divisors[::-1]:
        if isValid(total,divisor):
            res=divisor
            break
    
    if res==-1:
        print(str(total)+' coconuts, no solution')
    else:
        print(str(total)+' coconuts, '+str(res)+' people and 1 monkey')
    
    total=int(input())


