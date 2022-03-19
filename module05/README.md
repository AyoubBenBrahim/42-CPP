The traditional C++ approach to error handling uses a function to return a specific value to indicate specific operations. Typically, a return value of 0 or 1 is used to indicate successful completion of the function’s task, whereas a negative value indicates an error condition. For example, with a function used to divide two numbers, a return value of -1 could indicate that the denominator is 0, and the division can’t be performed. When multiple error conditions can occur, different return values can be used to indicate specific errors.
Although this approach is still available and often used, a number of problems can occur. First, the programmer must check the return value to detect whether an error did occur. Next, the error-handling code that checks the return value frequently becomes intermixed with normal processing code, so sometimes it’s difficult to determine which part of the code is han- dling errors, as opposed to normal program processing. Finally, returning an error condition from a function means the condition must be the same data type as a valid returned value; hence, the error code must be a specially identified value that can be identified as an error alert. This means the error code is embedded as one of the possible nonerror values the func- tion might require and is available only at the point where the function returns a value. A function returning a Boolean value has no additional values for reporting an error condition, except true and false.
None of these problems is insurmountable, and many times this approach is simple and effective. However, another technique is available that’s designed for error detection and handling: exception handling. With this technique, when an error occurs while a function is executing, the function creates an exception. An exception is a value, a variable, or an object containing information about the error at the point the error occurs. This exception is imme- diately passed, at the point it’s generated, to code called the exception handler, which is designed to deal with the exception. The process of generating and passing an exception is referred to as throwing an exception. The exception is thrown from within the function while it’s still executing, which permits handling the error and then returning control back to the function so that it can complete its assigned task.

 To do this, the try block is included in a while statement, and then the catch block returns program con- trol to the while statement 


A first book of cpp

 ============

Exceptions are unexpected events that occur during the execution of a program. An exception can be the result of an error condition or simply an unanticipated input.

A thrown exception is “caught” by other code that “handles” the exception somehow, or the program is terminated unexpectedly.

Prior to having exceptions, errors were typically handled by having the program abort at the source of the error or by having the involved function return some special value. Exceptions provide a much cleaner mechanism for handling errors. Nevertheless, for historical reasons, many of the functions in the C++ standard library do not throw exceptions. Typically they return some sort of special error status, or set an error flag, which can be tested.


Exceptions are thrown when a piece of code finds some sort of problem dur- ing execution. Since there are many types of possible errors, when an exception is thrown, it is identified by a type. Typically this type is a class whose members pro- vide information as to the exact nature of the error, for example a string containing a descriptive error message.
Exception types often form hierarchies. For example, let’s imagine a hypothet- ical mathematics library, which may generate many different types of errors. The library might begin by defining one generic exception, MathException, represent- ing all types of mathematical errors, and then derive more specific exceptions for particular error conditions.

Exceptions are typically processed in the context of “try” and “catch” blocks. A try block is a block of statements proceeded by the keyword try. After a try block, there are one or more catch blocks. Each catch block specifies the type of exception that it catches. Execution begins with the statements of the try block. If all goes smoothly, then execution leaves the try block and skips over its associated catch blocks. If an exception is thrown, then the control immediately jumps into the appropriate catch block for this exception.


When an exception is thrown, it must be caught or the program will abort. In any particular function, an exception in that function can be passed through to the calling function or it can be caught in that function. When an exception is caught, it can be analyzed and dealt with. The general syntax for a try-catch block in C++ is as follows:

try
	try statements
catch ( exception type 1 identifier 1 )
	catch statements 1
...
catch ( exception type n identifier n ) 
	catch statements n

Execution begins in the “try statements.” If this execution generates no excep- tions, then the flow of control continues with the first statement after the last line of the entire try-catch block. If, on the other hand, an exception is generated, execu- tion in the try block terminates at that point and execution jumps to the first catch block matching the exception thrown.










 Data Structures and Algorithms in C++
