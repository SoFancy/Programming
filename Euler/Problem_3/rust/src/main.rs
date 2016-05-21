extern crate primal;

fn factor(mut n: usize) -> usize {
    let max = (n as f32).sqrt().floor() as usize;
    let mut largest_so_far = 2;

    let sieve = primal::Sieve::new(max); 

    'outer: loop { 
        for p in sieve.primes_from(2) {
            if n % p == 0 {
                n = n / p;
            
                if p > largest_so_far {
                    largest_so_far = p;
                }

                if n <= p {
                    break 'outer;
                }
                continue 'outer;
            }
        }
    }

    largest_so_far
}

fn main() { 
    let x = 600851475143;
    let y = factor(x);
    println!("The largest prime factor of {0} is {1}", x, y);
}
