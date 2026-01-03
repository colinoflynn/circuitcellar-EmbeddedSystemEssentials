receive_and_process_password():
// Store current frame pointer (fp) and
// link register (lr)
push    {fp, lr}

// Store new frame pointer (fp)
add     fp, sp, #4

// Set auth_level to "PASSWORD_OK" (#1)
mov     r3, #1
// auth_level stored at fp-16
str     r3, [fp, #-16]

// correct_password stored at offset fp-36 
sub     r3, fp, #36
// load correct_password
mov     r0, r3        
bl      load_secret_password(char*)

// buffer stored at offset fp-100
sub     r3, fp, #100
... rest of code ...