/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>
#include <ostream>
using namespace std;

template<typename T> T& add(T&,T,T);

//{ endm manipulator
ostream& endm(ostream& os){
	return os<<"[eol]\n"<<std::flush;
}
//}

//{ squares manipulator
void squares(ostream& os){
	cout<<"["<<os<<"]";
}
//}
/*
//{ add manipulator
ostream& add(ostream& os,T a, T b){
	return os<<a+b<<std::flush;
}
//}
*/
#endif // __IOMANIP_HPP__
