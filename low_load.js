// Node.js program
const n = 984_600_000;
let sum = 0;

console.log("Program starting...");
let start = process.hrtime.bigint(); // high-resolution time
console.log(`Start time: ${(Number(start) / 1e9).toFixed(3)}`);

for (let i = 1; i <= n; i++) {
    sum += i;
}

let end = process.hrtime.bigint();
console.log(`End time: ${(Number(end) / 1e9).toFixed(3)}`);

let elapsedSeconds = Number(end - start) / 1e9;
console.log(`Time elapsed: ${elapsedSeconds.toFixed(8)} seconds`);
console.log(`Sum: ${sum}`);
