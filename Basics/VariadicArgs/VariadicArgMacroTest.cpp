#include <iostream>
#include <cstdio>

/*
// way to check the size of a templated variadic argument
template<typename... T>
void f(const T&... t)
{
    // this is first way to get the number of arguments
    constexpr auto size = sizeof...(t);
    std::cout<<size <<std::endl;
}

int main()
{
    f("Raje", 2, 4, "ASH");
    return 0;
}
*/

// Way to check size of variadic arg
#define IS_EMPTY(...) (sizeof(#__VA_ARGS__) == 1)

#define PROVIDE_EMPTY_IF_NEEDED(...) \
  (sizeof(#__VA_ARGS__) == 1) ? "" : (__VA_ARGS__))

    
/* working approach taking variadic argument into a string */
/*
       if ((condition)) { \
           char testStr[] = {__VA_ARGS__};\
          if (sizof(testStr)) { \
            printf(testStr,"\n");\
          } else { \
            printf("Default string. Condition is true.\n"); \
          } \
*/

// Below approach doesn't works bcoz after MACRO expansion;
// the printf statement for null __VA_ARGS__ looks like below and hence there is no "true "condition available in ternary operator hence
// it fails:
// Missing false condition for ternary operator.
//
// printf("%s\n", ( (sizeof("") == 1) ? "" : ));

#define CONDITIONAL_MACRO(condition, ...) \
  do { \
       if ((condition)) { \
        if(IS_EMPTY(__VA_ARGS__)) {\
            printf(""); \
        } else \
        printf("%s\n", ( (sizeof(#__VA_ARGS__) == 1) ? "" : __VA_ARGS__ ));\
      } \
     else { \
      printf("Condition is false.\n"); \
    } \
  } while(0)

int main() {
  int x = 5;

  // Usage of the macro with a condition
  CONDITIONAL_MACRO(x > 0);   // Output: Condition is true.
  CONDITIONAL_MACRO(x > 0, "Hello success");  // Output: Hello success
  CONDITIONAL_MACRO(true, "Hello failure");  // Output: Hello failure
  return 0;
}
