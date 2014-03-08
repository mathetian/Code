#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>
 
template<class A>
typename std::enable_if< std::rank<A>::value == 1 >::type
print_1d(const A& a)
{
	std::cout<<(std::extent<A>::value)<<std::endl;
    copy(a, a+std::extent<A>::value,
         std::ostream_iterator<typename std::remove_extent<A>::type>(std::cout, " "));
    std::cout << '\n';
}
 
int main()
{
    int a[][4] = {{1,2,3,1},{4,5,6, 7}};
//  print_1d(a); // compile-time error
    print_1d(a[1]);
}