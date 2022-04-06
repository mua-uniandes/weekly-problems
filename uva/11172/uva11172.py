'''import itertools'''
import time

answers = []

def main():
    start_time = time.time()           
    def loadFile():
        f = open('./../11172.in', 'r')
        num_problems = int(f.readline())
        for i in range(num_problems):
            line = f.readline()
            left = int(line.split()[0])
            right = int(line.split()[1])
            if(left < right):
                answers.append("<")
            elif(left > right):
                answers.append(">")
            else:
                answers.append("=")
        f.close()
        writeAnswer()
        print(time.time() - start_time)
    def writeAnswer():
        f = open('./res.out', 'w')
        for answer in answers:
            f.write(str(answer) + "\n")
        f.close()
    loadFile()

    
main()



    