if ARGV[0] == nil || ARGV[1] == nil
	puts "Wrong number of Arguments"
	puts "Usage: ruby test-runner.rb <test text location> <path to program to test>"
	exit(1)
end

NUM_RUNS = 25
runtimes = []

NUM_RUNS.times do |x|
	start = Time.now

	`cat #{ARGV[0]} | #{ARGV[1]}`

	finish = Time.now

	runtimes << (finish - start) * 1000
end

def average(arr)
	sum = 0.0

	arr.each do |x|
		sum += x
	end

	return sum / arr.length
end

puts "Average Runtime over #{NUM_RUNS} runs: #{average(runtimes)} milliseconds."
