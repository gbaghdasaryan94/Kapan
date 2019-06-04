def avoidObstacles(inputArray):
    step = 2
    while step:
        t = True
        for n in inputArray:
            t = t and n%step
        if t: return step
        step += 1