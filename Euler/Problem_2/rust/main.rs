fn main() {
    let mut x_1 = 0;
    let mut x_2 = 2;

    let mut sum = x_2; 

    loop {
        let temp = x_2;
        x_2 = x_2 * 4 + x_1;
        x_1 = temp; 

        if x_2 >= 4000000 { break; }

        sum += x_2; 
    }

    println!("The final sum is: {}", sum);
}
