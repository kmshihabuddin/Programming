# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 00:47:21 2019

@author: Shihab
"""
from sys import stdin

inputs=stdin.read().splitlines()
input_ind=0

testCases=int(inputs[input_ind])
input_ind+=1

for _ in range(testCases):
    k=int(inputs[input_ind])
    input_ind+=1
    
    Map={}
    for _ in range(k):
        ch,price=inputs[input_ind].split()
        input_ind+=1
        Map[ch]=int(price)
    
    m=int(inputs[input_ind])
    input_ind+=1
    
    res=0
    for _ in range(m):
        for ch in inputs[input_ind]:
            res+=Map.get(ch,0)
        input_ind+=1
    res/=100.0
    
    print("%0.2f$"%res)
        