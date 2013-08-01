//
//  thread.cpp
//  concurrency
//
//  Created by Wyg Jyw on 7/31/13.
//  Copyright (c) 2013 wygjyw. All rights reserved.
//

#include "thread.h"
#include <future>
#include <thread>

void foo1()
{
    std::cout<<"foo1\n";
}

class foo2
{
public:
    foo2() {}
    void operator ()() const
    {
        std::cout<<"foo2\n";
    }
};

class foo4
{
public:
    void test()
    {
        std::cout<<"foo4\n";
    }
};

void testthread()
{
    foo2 f;
    std::thread t1(foo1);
    t1.join();
    std::thread t2(f);
    t2.join();
    std::thread t3([]()
                   {
                       std::cout<<"foo3\n";
                   });
    t3.join();
    foo4 f4;
    std::thread t4(&foo4::test, &f4);
    t4.join();
}