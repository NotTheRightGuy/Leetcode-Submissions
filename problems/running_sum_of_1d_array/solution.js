var runningSum = function (names) {
  sum = 0;
  cumsum = [];
  for (let i = 0; i < names.length; i++) {
    sum += names[i];
    cumsum.push(sum);
  }
    return cumsum
};
