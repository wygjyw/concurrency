//
//  main.cpp
//  concurrency
//
//  Created by Wyg Jyw on 7/31/13.
//  Copyright (c) 2013 wygjyw. All rights reserved.
//

#include <iostream>
#include <future>

int a, b, c;
int calculateA()
{
    return a+a*b;
}

int calculateB()
{
    return a*(a+a*(a+1));
}

int calculateC()
{
    return b*(b+1)-b;
}

extern void testthread();

int main(int argc, const char *argv[])
{
    testthread();
    a = 3;
    b = 5;
    c = calculateA() * (calculateB() + calculateC());
    std::cout<<c;
    std::future<int> f1 = std::async(calculateB);
    std::future<int> f2 = std::async(calculateC);
    c = calculateA() * (f1.get() + f2.get());
    std::cout<<c;
    return 0;
}
