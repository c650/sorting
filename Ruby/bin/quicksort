#! /usr/bin/env ruby
require 'pry'
# str is array of chars
# pivot point is index in array to pivot on
# returns type like `str`
def quicksort(str, pivot_point) 
	strlen = str.length
	return str if strlen <= 1

	pivot_char = str[pivot_point]

	left = []
	right = []

	for i in 0...strlen
		next if i == pivot_point

		if str[i] < pivot_char
			left << str[i]
		else
			right << str[i]
		end
	end

	left = quicksort(left, rand(left.length))
	right = quicksort(right, rand(right.length))

	str = []
	str << left << pivot_char << right

	return str.flatten

end













puts "give me a string"
str = gets.chomp.split('')

puts quicksort(str, rand(str.length)).join('')