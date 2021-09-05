#include <iostream>
#include <map>
using namespace std;

int main()
{
        map<char, char> m = {
            { 'a' , 'A'},
            { 'b' , 'B'},
            { 'c' , 'C'},
            { 'd' , 'D'},
            { 'e' , 'E'},        
        };

        auto last = *m.rbegin();
        auto i = m.begin();

        cout << "Map contains "
             << "following elements"
             <<  endl;

        do{
            cout << i->first << " = " << i->second << endl;
        }while (m.value_comp() (*i++, last) );

        return 0;

            
}



// https://www.geeksforgeeks.org/map-value_comp-in-c-stl/