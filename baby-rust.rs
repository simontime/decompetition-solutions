use std::env;

fn main()
{
	if let Some(num) = env::args().nth(1)
	{
		print!("Thanks");
		
		match num.parse::<i32>() {
			Ok(n)   => print!(", {} could be a number", n),
			Err(..) => print!(". This was unexpected")
		}
		
		print!("\n");
	}
	else
	{
		print!("Please provide an argument\n");
	}
}