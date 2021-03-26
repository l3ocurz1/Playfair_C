cmake_minimum_required(VERSION 3.14)
project(playfair)

set(CMAKE_C_STANDARD 99)

add_executable(playfair main.c make_message.c make_message.h file.c file.h playfair_procedure.c playfair_procedure.h encode_decode.c encode_decode.h matrix.c matrix.h controller.c controller.h check.c check.h)