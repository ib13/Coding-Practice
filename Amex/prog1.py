import datetime
test_cases = int(input())

data = []
for i in range(test_cases):
    val = input()
    data.append(val)

voucher = []
for i in range(test_cases):
    voucher.append('nnnnnnnnnn')

for i in range(test_cases):
    for j in range(len(data[i])-1):
        if data[i][j] == ',' and data[i][j+1] == ',':
            voucher[i] = 'N/A'

split_data = []
for i in range(test_cases):
    split_data.append(data[i].split(','))

# print(split_data)

# For enrollment date
for i in range(test_cases):
    if voucher[i] != 'N/A':
        temp = split_data[i][3]
        if (datetime.datetime(2019, 4, 12) - datetime.datetime(int(temp[0:4]), int(temp[5:7]), int(temp[8:10]))).days <= 89:
            voucher[i] = 'N/A'

# For Delinquent Flag
for i in range(test_cases):
    if int(split_data[i][4]) == 1:
        voucher[i] = 'N/A'

# For amount spend
for i in range(test_cases):
    if float(split_data[i][2]) < 25000.00:
        voucher[i] = 'N/A'

voucher_list = []
for i in range(test_cases):
    voucher_list.append(list(voucher[i]))

# print(voucher_list)

# Voucher code
for i in range(test_cases):
    if voucher[i] != 'N/A':
        # V1
        if float(split_data[i][2]) >= 100000.0:
            voucher_list[i][0] = 'F'
        elif float(split_data[i][2]) >= 50000.0 and float(split_data[i][2]) < 100000.0:
            voucher_list[i][0] = 'H'
        elif float(split_data[i][2]) >= 25000.0 and float(split_data[i][2]) < 50000.0:
            voucher_list[i][0] = 'S'

        # V2-V4-V6-V8-V10
        for j in range(0, 5):
            voucher_list[i][1+j*2] = str(9 - int(data[i][4-j]))

        # V3-V5
        name = split_data[i][1].strip()
        name = name.split()
        if len(name) == 2:
            voucher_list[i][2] = chr(
                ord('Z')-(ord(name[0][0].upper()) - ord('A')))
            voucher_list[i][4] = chr(
                ord('Z')-(ord(name[1][0].upper()) - ord('A')))
        elif len(name) == 1:
            voucher_list[i][2] = chr(
                ord('Z')-(ord(name[0][0].upper()) - ord('A')))
            voucher_list[i][4] = 'Z'
        elif len(name) == 0:
            voucher[i] = "".join(voucher_list[i])
            voucher[i] = 'N/A'
            voucher_list[i] = list(voucher[i])
            # voucher_list[i][2] = 'Z'
            # voucher_list[i][4] = 'Z'

        # V7
        num = 0
        for j in split_data[i][2]:
            if(j != '.'):
                num += int(j)
        while(num > 9):
            temp_num = 0
            for j in str(num):
                temp_num = temp_num + int(j)
            num = temp_num
        voucher_list[i][6] = str(num)

        # V9
        num = 0
        for j in split_data[i][3]:
            if(j != '-'):
                num += int(j)
        while(num > 9):
            temp_num = 0
            for j in str(num):
                temp_num = temp_num + int(j)
            num = temp_num
        voucher_list[i][8] = str(num)


for i in range(test_cases):
    voucher[i] = "".join(voucher_list[i])

final_answer = []
for i in range(test_cases):
    final_answer.append((split_data[i][0], voucher[i]))
final_answer = sorted(final_answer)

for i in range(test_cases):
    final_str = final_answer[i][0] + ","+final_answer[i][1]
    print(final_str)

# 4
# 6323246954,Chelsie Bryand,62472.07,2019-01-02,0
# 7021289247,Bryon Yonts,26245.30,2018-12-14,0
# 8311285536,Dominick Pena,42377.31,2018-12-23,1
# 8541521746,Aracelis Conway,107978,2018-12-19,0
