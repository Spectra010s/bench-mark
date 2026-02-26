const start = Date.now()* 1_000;


const baseline = Array(30).fill("8");

const toChange = [
  [1],
  [],
  [13, 14, 15, 16, 24, 25],
  [9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24],
  [7, 8, 9, 10, 11, 12, 20, 21, 22, 23],
  [6, 7, 8, 9, 18, 19, 20, 21, 22, 23, 24],
  [6, 7, 8, 16, 17, 18, 21, 22, 23],
  [6, 7, 8, 14, 15, 16, 22, 23, 24],
  [6, 7, 8, 9, 21, 22, 23],
  [7, 8, 9, 18, 19, 20, 21, 22, 23],
  [6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
  [4, 5, 11, 12, 13, 14, 15, 16, 17, 18],
  [],
  [-1]
];

for (let t = 0; t < 1000000; t++) {
for (let i = 0; i < 14; i++) {
  const thisLine = [...baseline]; 
  for (const index of toChange[i]) {
    if (index >= 0) {
      thisLine[index] = i === 0 ? "0" : "1";
    }
  }
  
}}

const end = Date.now()* 1_000;
const timeTakenMicro = end - start;
const timeTakenMilli = timeTakenMicro/ 1_000;
const timeTakenSecs = timeTakenMicro/ 1_000_000;

console.log("Time taken in microseconds:", timeTakenMicro.toString());
console.log("Time taken in milliseconds:", timeTakenMilli.toString());
console.log("Time taken in seconds:", timeTakenSecs);
