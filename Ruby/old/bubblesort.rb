#! /usr/bin/env ruby

puts "give me a string"
str = gets.chomp.split('')
strlen = str.length

changes_made = false

for i in 0..(strlen - 2) # 0 thru two less than the length of str
	for j in 0..(strlen - 2)
		if str[j] > str[j+1]
			str[j],str[j+1] = str[j+1],str[j]
			changes_made = true
		end
	end

	break if !changes_made

	changes_made = false
end

puts str.join('')
