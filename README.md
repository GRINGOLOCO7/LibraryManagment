# LibraryManagment
C++ simple library manager



### Compile & Execute

PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2\src> g++ library_manager_system2.cpp -o library_manager_system2.o




PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2\src> ls

    Directory: C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2\src

Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a---          04/10/2024    16:10           4666 library_manager_system2.cpp
-a---          10/10/2024    02:04         142472 library_manager_system2.o





PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2\src> cd ..




PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2> make clean

rm -f src/library_manager_system2.o my_library_manager




PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2> make

g++ -Wall -std=c++17 -c src/library_manager_system2.cpp -o src/library_manager_system2.o
g++ -Wall -std=c++17 -o my_library_manager src/library_manager_system2.o




PS C:\Users\orlan\OneDrive\Desktop\1semestre\COMPUTER PROGRAMMING 2\My_Codes\Challenge2> .\my_library_manager.exe

User constructor
name: John
email: jon@gmail.com
Base constructor
type: Magazine
title: Vogue
User constructor
name: No name
email: No email
Magazine constructor
type: Magazine
title: Vogue
Base constructor
type: Book
title: Harry Potter
User constructor
name: No name
email: No email
Book constructor
type: Book
title: Harry Potter
Manager checkout
type: Magazine
title: Vogue
name: John
email: jon@gmail.com