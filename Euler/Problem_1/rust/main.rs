// Calculate the sum of every x digits up to n
fn sum(mut n: i32, x: i32) -> i32 {
    n = n - (n % x);
    (n*(n+x))/(2*x)
}

fn main() {
    let mut x = 0;
    
    x += sum(999, 3);
    x += sum(999, 5);
    x -= sum(999, 15);

    println!("The total sum is: {}", x);
}
