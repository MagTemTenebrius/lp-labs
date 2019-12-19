//
// Created by magte on 19.12.2019.
//

#include "InfInt.h"
#include "BigDecimal.h"


#include <iostream>
#include <time.h>
//#include "wide_integer.cpp"


using namespace std;

int main() {

    clock_t start, end;
    {
        start = clock();
        main_InfInt();
        InfInt num1 = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
        InfInt num2 = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
//        InfInt num3 = "1000";
//        cout << num3 << "! = " << fact(num3) << endl;

        end = clock();
        cout << "The above code block was executed in " << ((double) end - start) / ((double) CLOCKS_PER_SEC)
             << " second(s)" << endl << endl << endl;
    }
//    _test::tests();
    {
        start = clock();
        BigDecimal C;
        BigDecimal A("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
        BigDecimal B("11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
        cout << A.toString() << " * " << B.toString() << " = " << (A*B).toString() << endl;

        end = clock();


        cout << "The above code block was executed in " << ((double) end - start) / ((double) CLOCKS_PER_SEC)
             << " second(s)";
    }

}
