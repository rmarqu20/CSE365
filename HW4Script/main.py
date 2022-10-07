import os

stringToMatch = '/var/challenge/'
outputFolder = r'C:\Users\Home\PycharmProjects\HW4Script\Flags'
flag = ''
challenge_id = ''

with open('hw4.txt', 'r') as file:
    os.chdir(outputFolder)
    for line in file:
        if stringToMatch in line:
            challenge_id = line[15:-1]
            text_file = open('%s_flag_commands.txt' % challenge_id, 'w')
            text_file.write("-p flag")
        if stringToMatch not in line:
            flag = line
            text_file = open('%s_flag.txt' % challenge_id, 'w')
            text_file.write(flag)

