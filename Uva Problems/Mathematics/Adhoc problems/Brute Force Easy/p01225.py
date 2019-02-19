# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 20:59:20 2019

@author: Shihab
"""
def countDig(num,count):
        while num:
            count[int(num%10)]+=1
            num//=10
            
t=int(input())


for case in range(1,t+1):
    count=[0]*10
    n=int(input())
    for i in range(1,n+1):
        countDig(i,count)
        
    print(' '.join(map(str,count)))
    
    
    