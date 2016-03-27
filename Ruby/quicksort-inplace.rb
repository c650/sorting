#! /usr/bin/env ruby

# str is array of chars
# pivot point is index in array to pivot on
# returns type like `str`
def quicksort(str, _begin, _end) 
	return str[_begin..._end] if _end - _begin <= 1

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