#! /usr/bin/env ruby

# str is array of chars
# pivot point is index in array to pivot on
# returns type like `str`
def quicksort(str, _begin, _end) 
	return str[_begin.._end] if _end - _begin <= 1

	pivot = _begin # choose beginning as pivot

	a = _begin
	b = _end

	while (b > a)
		if str[b-1] > str[pivot]
			str[b] = str[b-1]
			b-=1
		else
			str[b-1],str[a] = str[a],str[b-1]
			a+=1
		end
	end

	str[b] = str[pivot]

	str[ _begin..b ] = quicksort(str, _begin, b)
	str[ (b+1).._end] = quicksort(str, b+1, _end)

	return str[_begin.._end]

end

puts "give me a string"
str = gets.chomp.split('')

puts quicksort(str, 0, str.length - 1).join('')