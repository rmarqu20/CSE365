from Student import Student
from Chef import Chef
from ChineseChef import ChineseChef

# import main

# # Dictionary
# monthConversions = {
#     "Jan": "January",
#     "Feb": "February",
#     "Mar": "March",
#     "Apr": "April",
#     "May": "May",
#     "Jun": "June",
#     "Jul": "July",
#     "Aug": "August",
#     "Sep": "September",
#     "Oct": "October",
#     "Nov": "November",
#     "Dec": "December",
# }
# #2D Array
# number_grid = [
#     [1,2,3],
#     [4,5,6],
#     [7,8,9],
#     [0]
# ]
# for i in number_grid:
#     for j in i:
#         print(j)
# #Translate Function
# def translate(phrase):
#     translation = ""
#     for letter in phrase:
#         if letter.lower() in "aeiou":
#             if letter.isupper():
#                 translation = translation + "G"
#             else:
#                 translation = translation + "g"
#         else:
#             translation = translation + letter
#     return translation
# print(translate("Hi My Name Is Richard"))
# #Try/Except
# try:
#     value = 10 / 0
#     number = int(input("Enter a number"))
#     print(number)
# except ZeroDivisionError as err:
#     print(err)
# except ValueError:
#     print("Invalid input")
# Read/Write to Files
# employee_file = open("test.txt", "r+")
# for i in employee_file.readlines():
#     print(i)
# #employee_file.write("\nKelly - Customer Service")
# # print(employee_file.read())
# employee_file.close()
# print(main.roll_dice(100))
#
# student1 = Student("Oscar", "Business", 3.6)
# student2 = Student("Phyllis", "Accounting", 2.5)
# print(student1.gpa)
# print(student1.on_honor_roll())

myChef = Chef()
myChef.make_special_dish()

myChineseChef = ChineseChef()
myChineseChef.make_chicken()
myChineseChef.make_special_dish()