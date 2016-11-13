#! /usr/bin/env ruby

# str is array of chars
# pivot point is index in array to pivot on
# returns type like `str`
#! /usr/bin/env ruby
def sorted?(arr)
	for i in 1...arr.length
		return false if arr[i] < arr[i-1]
	end

	return true
end

def insertionsort(str)
	strlen = str.length
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

	return str
end

def quicksort(str, _begin, _end)
	return str[_begin..._end] if _end - _begin <= 1

	if _end - _begin <= 10
		return insertionsort(str[_begin..._end])
	end


	pivot = str[_end - 1] # choose last as pivot

	a = _begin
	b = _end - 1

	while (b > a)
		if str[b-1] > pivot
			str[b] = str[b-1]
			b-=1
		else
			str[b-1],str[a] = str[a],str[b-1]
			a+=1
		end
	end

	str[b] = pivot

	str[ _begin...b ] = quicksort(str, _begin, b) if b - _begin > 1
	str[ (b+1)..._end] = quicksort(str, b+1, _end) if _end - b > 1

	return str[_begin..._end]

end

puts "give me a string"
str = gets.chomp.split('')

puts quicksort(str, 0, str.length).join('')
