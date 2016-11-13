#! /usr/bin/env ruby
def sorted?(arr)
	for i in 1...arr.length
		return false if arr[i] < arr[i-1]
	end

	return true
end
# ignore, just input
puts "give me a string"
str = gets.chomp.split('')
strlen = str.length
# stop ignoring

# PAY ATTENTION HERE
# if the element to the left bigger than the element we are looking at, str[i]
# we need to put str[i] where it belongs.
# and we do this by temporarily storing the value of str[i] and then shifting
# all the elements of the array/str that are bigger than str[i] to the right
# until we arrive at str[i]'s new, rightful place
while !sorted?(str)

	for i in 1...strlen #exclusive range

		if str[i-1] > str[i]
			hold = str[i] # store value to INSERT

			pos = i

			while pos > 0 && str[pos - 1] > hold
				str[pos] = str[pos - 1] # shift up
				pos -= 1

				# stop if we have shifted all the elements that are BOTH greater than str[i] AND
            	# to the left of str[i]
			end

			# put str[i] in its rightful spot, just left of the last element we shifted, or the original spot of
        	# the last element we shifted
			str[pos] = hold
		end

	end

end
puts str.join('')
