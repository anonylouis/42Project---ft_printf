# 42Project---ft_printf

In this project we have to recode the printf function from the C librairy !  
The function has the following declaration :  
```int printf(const char *format, ...)```  

## Subject

The original subject from 42 Paris is [en.subject.pdf](https://github.com/anonylouis/42Project---ft_printf/blob/main/en.subject.pdf)

Only these Specifiers work :
- `%c` to print a character  
- `%s` to print a string  
- `%d` or `%i` to print an int  
- `%u` to print an unsigned int  
- `%p` to print a pointer  
- `%x` or `%X` to print an unsigned hexadecimal integer  
- `%%` to print a %  

And you can add the followings flags on the adapted specifiers :
- flag `-`  
- flag `0`  
- flag `.` (precision)
- flag `#`
- flag ` ` (space)
- flag `+`
- the field minimum width

## Commands

Use :
- `make` to compile the *libftprintf.a library*
- `make test` to compile the tests from ```test.c```
