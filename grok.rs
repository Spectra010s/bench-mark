use std::time::Instant;

fn main() {
    println!("Hello from RUST");
    let start = Instant::now();

    let baseline: [&str; 30] = ["8"; 30];

    let to_change: [&[i32]; 14] = [
        &[1],
        &[],
        &[13, 14, 15, 16, 24, 25],
        &[9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24],
        &[7, 8, 9, 10, 11, 12, 20, 21, 22, 23],
        &[6, 7, 8, 9, 18, 19, 20, 21, 22, 23, 24],
        &[6, 7, 8, 16, 17, 18, 21, 22, 23],
        &[6, 7, 8, 14, 15, 16, 22, 23, 24],
        &[6, 7, 8, 9, 21, 22, 23],
        &[7, 8, 9, 18, 19, 20, 21, 22, 23],
        &[6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21],
        &[4, 5, 11, 12, 13, 14, 15, 16, 17, 18],
        &[],
        &[-1],
    ];


for _ in 0..1_000_000 {
    for i in 0..14 {

        let mut output = baseline;
        
        for &index in to_change[i] {
            if index >= 0 {
                output[index as usize] = if i == 0 { "0" } else { "1" };
            }
        }

    }
    }

    let duration = start.elapsed();
    let micros = duration.as_micros();
    let _millis = duration.as_millis();
    let secs = duration.as_secs_f64();

    println!("Time taken in microseconds: {}", micros);
    println!("Time taken in milliseconds: {}", micros as f32/1000.0);
    println!("Time taken in seconds: {:.6}", secs);
}
