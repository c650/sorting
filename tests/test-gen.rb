unless ARGV[0].to_i.respond_to?(:**)
	puts "Wrong number of args: specify test length"
	exit(1)
end

ARGV[0].to_i.times do |x|
	print rand(32..127).chr
end

print "\n"