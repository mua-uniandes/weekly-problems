# -*- coding: utf-8 -*-
"""
Created on Tue Apr  6 17:56:24 2021

@author: Angelo Marcetty
"""

inp = input()
inp = inp.split(" ")

n1 = inp[0]
k1 = int(inp[1])
k2 = k1

    
def Kaprekar(n,k):

    g1 = list(map(int,n))
    g1 = sorted(g1,reverse=True)
    g1 = [str(i) for i in g1]
    g1 = "".join(g1)
    g1 = int(g1)
    #print("g1:",g1)
    
    g2 = list(map(int,n))
    g2 = sorted(g2)
    g2 = [str(j) for j in g2]
    g2 = "".join(g2)
    g2 = int(g2)
    #print("g2:",g2)
    
    fx = g1 - g2
    #print(fx)
    
    if k == 1 or k == 0:
        print(fx)
    else:
        global n1
        n1 = str(fx)
        global k1 
        k1 = k1-1
         #Kaprekar(str(fx),k-1)


if k1 == 0:
    print(n1)
for i in range(0,k2):
    Kaprekar(n1,k1)