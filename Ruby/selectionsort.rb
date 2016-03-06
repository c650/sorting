#! /usr/bin/env ruby

puts "give me a string"
str = gets.chomp.split('')
strlen = str.length

for i in 0...strlen
	min_pos = i

	for j in i+1...strlen
		min_pos = j if (str[j] < str[min_pos])
	end

	str[i], str[min_pos] = str[min_pos],str[i] if min_pos != i
end

puts str.join('')