# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 01:04:52 2019

@author: Shihab
"""

from sys import stdin

n=int(stdin.readline())
case=1

while n>=0:
    
    cumsum=n
    
    created=list(map(int,stdin.readline().split()))
    required=list(map(int,stdin.readline().split()))
    
    
    print("Case "+str(case)+":")
    for i in range(len(created)):
        
        if cumsum<required[i]:
            print("No problem. :(")
        else:
            print("No problem! :D")
            cumsum-=required[i]
            
        cumsum+=created[i]
    
    n=int(stdin.readline())
    case+=1
    