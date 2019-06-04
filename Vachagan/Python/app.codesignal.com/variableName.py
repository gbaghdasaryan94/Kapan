import re
def variableName(name):
    return re.findall("^[a-zA-Z_][0-9a-zA-Z_]*$", name) != []

print(variableName("s_scs_"))