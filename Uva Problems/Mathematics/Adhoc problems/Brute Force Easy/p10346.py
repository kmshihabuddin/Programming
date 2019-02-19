# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 21:52:21 2019

@author: Shihab
"""

from sys import stdin

for line in stdin:
    n,k=map(int,line.split())
    
    res=n
    extra=n
    
    while extra>=k:
        res+=extra//k
        extra=extra//k+extra%k;
      
    print(res)
        