values = [36, 37, 38, 37, 117, 118, 112, 34, 57, 38, 36, 119, 36, 57, 32, 114, 37, 113, 57, 118, 44, 36, 32, 57, 114, 44, 113, 112, 35, 45, 35, 36, 37, 117, 35, 32]
xor_result = []

for value in values:
    xor_result.append(chr(value ^ 0x14))

print(xor_result)

result_string = ''.join(xor_result)

print(result_string)


# user_input = [ord(x) for x in user_input]
# validation = [36, 37, 38, 37, 117, 118, 112, 34, 57, 38, 36, 119, 36, 57, 32, 114, 37, 113, 57, 118, 44, 36, 32, 57, 114, 44, 113, 112, 35, 45, 35, 36, 37, 117, 35, 32]

# if len(user_input) != len(validation):
#     print("your password is wrong")
#     exit(0)

# for x in range(len(user_input)):
#     if user_input[x] != validation[x] ^ 0x14:
#         print("your password is wrong")

# print("good, the input is your password")