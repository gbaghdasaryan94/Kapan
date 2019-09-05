function maxX(arr) {
    let sum = 0, x = 0;

    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
        if(sum < 1){
            x += Math.abs(sum);
            sum = 0;
        }
    }
    
    return x+1;
} 

console.log(maxX([-5,4,-2,3,1,-1,-6,-1,0,-5]));

console.log(maxX([-2,3,1,-5]));

console.log(maxX([-5,4,-2,3,1,-1,-6,-1, 5]));