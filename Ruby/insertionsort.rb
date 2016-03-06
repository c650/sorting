#! /usr/bin/env ruby

puts "give me a string"
str = gets.chomp.split('')
strlen = str.length


for i in 1...strlen #exclusive range
	if str[i-1] > str[i]
		hold = str[i]

		pos = i

		while pos > 0
			str[pos] = str[pos - 1] # shift up
			pos -= 1

			break if str[pos + 1] <= hold
		end

		str[pos] = hold

	end
end

puts str.join('')