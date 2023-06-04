// Need to re write



/*
 * New String Literals
 */

// C++ 03
char* a= "string";

// C++ 11

char* a1= u8"string"; // To define an UTF-8 string 
char16_t* a2= u"string";   // To define an UTF-16 string
char32_t* a3= U"string";   // To define an UTF-32 string
char* a4= R"string \\";   // To define raw string (consider 2 \\ )
