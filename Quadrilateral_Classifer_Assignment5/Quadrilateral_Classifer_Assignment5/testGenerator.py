#!/usr/bin/env python3
import random
import string
import os
path = "/Users/quincycopeland/cs6015_assignment4/SofewareEngnieering/Quadrilateral_Classifer_Assignment5/Quadrilateral_Classifer_Assignment5/testFiles/"

def generate_square():
    x1 = 1
    y1 = 0
    x2 = 1
    y2 = 1
    x3 = 0
    y3 = 1

    file = open(path + "square.txt", "w")
    for i in range(100):
        line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(y3) + "\n"
        file.write(line)
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()



def square_answer_key():
    file = open(path + "squareExpected.txt", "w")

    for i in range(100):
        file.write("SQUARE\n")
    file.close()



def generate_rectangle():
    x1 = 2
    y1 = 0
    x2 = 2
    y2 = 3
    x3 = 0
    y3 = 3

    file = open(path + "rectangle.txt", "w")
    for i in range(97):
        line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(y3) + "\n"
        file.write(line)
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()


#OUTPUT KEY FILE GENERATION
def rectangle_answer_key():
    file = open(path + "rectangleExpected.txt", "w")

    for i in range(97):
        file.write("RECTANGLE\n")
    file.close()



def generate_trapezoid():
    x1 = 3
    y1 = 0
    x2 = 2
    y2 = 1
    x3 = 1
    y3 = 1

    file = open(path + "trapezoid.txt", "w")
    for i in range(98):
        line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(y3) + "\n"
        file.write(line)
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()


#OUTPUT KEY FILE GENERATION
def trapezoid_answer_key():
    file = open(path + "trapezoidExpected.txt", "w")

    for i in range(98):
        file.write("TRAPEZOID\n")
    file.close()


#OUTPUT FILES GENERATION
def generate_rhombus():
    x1 = 2
    y1 = 1
    x2 = 3
    y2 = 3
    x3 = 1
    y3 = 2

    file = open(path + "rhombus.txt", "w")
    for i in range(98):
        line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(y3) + "\n"
        file.write(line)
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()


#OUTPUT KEY FILE GENERATION
def rhombus_answer_key():
    file = open(path + "rhombusExpected.txt", "w")

    for i in range(98):
        file.write("RHOMBUS\n")
    file.close()



# def generate_kite():
#     file = open(path + "kite.txt", "w")
#     x1 = 2
#     y1 = 1
#     x2 = 2
#     y2 = 2
#     x3 = 1
#     y3 = 2
#
#     for i in range(98):
#         line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(x3) + "\n"
#         file.write(line)
#         x1 += 1
#         x2 += 1
#         x3 += 1
#         y1 += 1
#         y2 += 1
#         y3 += 1
#     file.close()


#1 0 2 1 1 1
def generate_parallelogram():
    file = open(path + "parallelogram.txt", "w")
    x1 = 3
    y1 = 0
    x2 = 4
    y2 = 2
    x3 = 1
    y3 = 2

    for i in range(97):
        line = str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " " + str(x3) + " " + str(y3) + "\n"
        file.write(line)
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()


def parallelogram_answer_key():
    file = open(path + "parallelogramExpected.txt", "w")

    for i in range(97):
        file.write("PARALELLELOGRAM\n")
    file.close()



def generate_rand_shape_0_to_300():
    num = 1
    for i in range(300):
        file = open(path + str(num) + ".txt", "w")
        file.write(str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100))
                   + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + " " + str(random.randint(0, 100)) + "\n")
        num += 1
    file.close()


def generate_rand_shape_to_600():
    num = 301
    for i in range(300):
        file = open(path + str(num) + ".txt", "w")
        file.write(str(random.randint(0, 10)) + " " + str(random.randint(0, 10)) + " " + str(random.randint(0, 10))
                   + " " + str(random.randint(0, 30)) + " " + str(random.randint(0, 30)) + " " + str(random.randint(0, 30)) + "\n")
        num += 1
    file.close()


def generate_rand_character_length():
    num = 601
    for i in range(400):
        file = open(path + str(num) + ".txt", "w")
        random_int = random.randint(0, 50)
        random_string = ''.join([random.choice(string.ascii_letters + string.digits) for n in range(random_int)])
        file.write(random_string + "\n")
        file.close()
        num += 1



generate_square()
generate_rectangle()
generate_trapezoid()
generate_rhombus()
#generate_kite()
generate_parallelogram()
square_answer_key()
rectangle_answer_key()
rhombus_answer_key()
trapezoid_answer_key()
parallelogram_answer_key()
generate_rand_shape_0_to_300()
generate_rand_shape_to_600()
generate_rand_character_length()

# os.system("sh fuzz.sh")
