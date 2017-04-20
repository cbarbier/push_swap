def main
if ARGV.length != 3
	puts "Usage: ruby num_gen.rb min max nb"
	return;
end
min = ARGV[0].to_i;
max = ARGV[1].to_i;
nb = ARGV[2].to_i;
nb.times do |x|
	print  "#{Random.rand(min...max)} ";
end
end
main();
