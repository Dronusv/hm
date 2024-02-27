﻿#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <numeric>
#include <string>
#include <vector>


int test(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int sum=0;
    for (std::vector<int>::iterator ptr = begin; ptr < end; ptr++) {
        sum += *ptr;
    }
    return sum;
    
}

template<typename It,class F>
auto forEach(It begin, It end,F func) {
    size_t curr_size = std::distance(begin, end);
    if (curr_size <= 1) {
        return func(begin,end);
    }
    auto mid = begin;
    std::advance(mid, curr_size/2); 
    auto fl_res=std::async(forEach<It,F>, begin, mid,func);
    auto l_res= std::async(forEach<It, F>, mid, end, func);
    return fl_res.get() + l_res.get();
   
}



int main()
{
    std::vector<int> v (20, 1);
    int sum=forEach(v.begin(),v.end (),&test);
    std::cout << sum;
    
}
