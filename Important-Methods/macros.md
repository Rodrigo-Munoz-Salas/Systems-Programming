**THIS FILE INCLUDES A LIST OF IMPORTANT MACROS FOR SOFTWARE DEVELOPMENT**
* #define error(code, message) do{ fprintf(stderr, "%s\n", message); return code;} while (0);
    call: error(code, message) where
    code is an int
    message is a string explaining the error
* #define square(a) ((a) * (a))
    call: square(value) where
    value is a type to be squared