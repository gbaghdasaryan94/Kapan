def reverseInParentheses(txtS):
    for i in range(len(txtS)):
        if txtS[i] == "(":
            start = i
        if txtS[i] == ")":
            end = i
            return reverseInParentheses(txtS[:start] + txtS[start+1:end][::-1] + txtS[end+1:])
    return txtS

print(reverseInParentheses(input("Enter text for Revers : ")))