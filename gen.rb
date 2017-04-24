def main
if ARGV.length != 3
	puts "Usage: ruby num_gen.rb min max nb"
	return;
end
min = ARGV[0].to_i;
max = ARGV[1].to_i + 1;
nb = ARGV[2].to_i;
if (max - min < nb || max < min)
	puts "wrong params, it does not make any sense"
	puts "Usage: ruby num_gen.rb min max nb"
	return;
end
tab = Array.new();
nb.times do |x|
	w = Random.rand(min...max);
	while tab.include? w
		w = Random.rand(min...max);
	end
	tab.push w;
	print  "#{w} ";
end
end
main();
