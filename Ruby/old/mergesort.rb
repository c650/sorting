#! /usr/bin/env ruby
class Array
	def mergesort

		return self if length <= 1

		if length == 2
			if (self[0] > self[1])
				self[0],self[1] = self[1],self[0]
			end

			return self
		end

		left = self[0...self.length/2].mergesort
		right = self[self.length/2...self.length].mergesort

		arr = []

		while(!left.empty? && !right.empty?)
			if left.first < right.first
				arr << left.first
				left.shift
			else
				arr << right.first
				right.shift
			end
		end

		if !left.empty?
			arr += left
		elsif !right.empty?
			arr += right
		end

		return arr
	end
end




puts "give me a string"
str = gets.chomp.split('')
strlen = str.length
puts str.mergesort.join('')
